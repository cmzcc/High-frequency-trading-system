
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "iniFileRW.h"
#include <iostream>
char* g_szini_file_buffer=NULL;
int   g_ifile_size=0;
char* g_szsection=NULL;  
#define INVALIDE_CHAR(pChar) ('\r'==(pChar)||'\n'==(pChar))
int load_ini_file(const char *file)
{
	
	FILE *in = NULL;
	int i=0;
	
  if (file == NULL )
  {
    return -2;
  }
  
	in = fopen(file,"r");
	if( NULL == in) {
		printf("load_ini_file error：%s,filename:%s\n",strerror(errno),file);
		return -1;
	}
	free_ini_file();
	g_szini_file_buffer=(char*)malloc(MAX_FILE_SIZE);
	g_szini_file_buffer[i]=fgetc(in);
	
	//load initialization file
	while( g_szini_file_buffer[i]!= (char)EOF) {
		i++;
	//	assert( i < MAX_FILE_SIZE ); //file too big, you can redefine MAX_FILE_SIZE to fit the big file 
    if(i < MAX_FILE_SIZE)
    {
		  g_szini_file_buffer[i]=fgetc(in);
    }
	}
	
	g_szini_file_buffer[i]='\0';
	g_ifile_size = i;
	
	fclose(in);
	return i;
}
int save_ini_file(const char *file)
{
	FILE* out;
	out = fopen(file,"w");
	if(NULL == out|| NULL==g_szini_file_buffer || 0>=g_ifile_size)
	{
		return 0;
	}

	if(-1 == fputs(g_szini_file_buffer,out) )
	{
		fclose(out);
		return 0;
	}

	fclose(out);
	return 1;	
}
void free_ini_file()
{
	if(g_szini_file_buffer){
		free(g_szini_file_buffer);
		g_ifile_size=0;
		g_szini_file_buffer=NULL;
	}
	if(g_szsection)
	{
		free(g_szsection);
		g_szsection=NULL;
	}
}
void set_section(const char *section)
{
	if(NULL==g_szsection)
		g_szsection=(char*)calloc(MAX_SECTION_SIZE,1);
	if(NULL!=section)
		strncpy(g_szsection,section,MAX_SECTION_SIZE);	
}
static int newline(char c)
{
	return ('\n' == c ||  '\r' == c )? 1 : 0;
}
static int end_of_string(char c)
{
	return '\0'==c? 1 : 0;
}
static int left_barce(char c)
{
	return LEFT_BRACE == c? 1 : 0;
}
static int isright_brace(char c )
{
	return RIGHT_BRACE == c? 1 : 0;
}
static int parse_file( const char *key,int *sec_s,int *sec_e, int *key_s,int *key_e, int *value_s, int *value_e)
{
	const char *p = g_szini_file_buffer;
	int i=0;
  if (g_szini_file_buffer == NULL || g_szsection ==NULL || key == NULL)
  {
    return -1;
  }

	*sec_e = *sec_s = *key_e = *key_s = *value_s = *value_e = -1;

	while( !end_of_string(p[i]) ) {
		//find the section
		if( ( 0==i ||  newline(p[i-1]) ) && left_barce(p[i]) )
		{
			int section_start=i+1;

			//find the ']'
			do {
				i++;
			} while( !isright_brace(p[i]) && !end_of_string(p[i]));

			if( 0 == strncmp(p+section_start,g_szsection, i-section_start)&&
				strlen(g_szsection)==i-section_start) {
				int newline_start=0;

				i++;

				//Skip over space char after ']'
				while(isspace(p[i])) {
					i++;
				}

				//find the section
				*sec_s = section_start;
				*sec_e = i;

				while( ! (newline(p[i-1]) && left_barce(p[i])) 
				&& !end_of_string(p[i]) ) {
					int j=0;
					//get a new line
					newline_start = i;

					while( !newline(p[i]) &&  !end_of_string(p[i]) ) {
						i++;
					}
					
					//now i  is equal to end of the line
					j = newline_start;

					if(';' != p[j]) //skip over comment
					{
						while(j < i && p[j]!='=') {
							j++;
							if('=' == p[j]) {
							//	if(strncmp(key,p+newline_start,j-newline_start)==0)
								{
									int iLength = j-newline_start;
									if((int)strlen(key) > iLength)
									{
										iLength = strlen(key);
									}
									if(strncmp(key,p+newline_start,iLength)==0)
									{
										//find the key ok
										*key_s = newline_start;
										*key_e = j-1;
	
										*value_s = j+1;
										*value_e = i;
										if(INVALIDE_CHAR(*value_s))
											return 0;
										return 1;
									}									
								}
							}
						}
					}

					i++;
				}
			}
		}
		else
		{
			i++;
		}
	}
	return 0;
}
char read_profile_char( const char *key,const char default_value)
{
	char buf[MAX_FILE_SIZE]={0};
	//int file_size;
	int sec_s,sec_e,key_s,key_e, value_s, value_e;
	if (g_szsection == NULL || key ==NULL)
	{
		return default_value;
	}
	if(0>=g_ifile_size)
	{
		return default_value;
	}
	if(0>=parse_file(key,&sec_s,&sec_e,&key_s,&key_e,&value_s,&value_e))
	{
		return default_value; //not find the key
	}	
	return *(g_szini_file_buffer+value_s);
}
/*! \fn read_profile_string(  const char *key,char *value, 
		 							int size, const char *default_value, const char *file)
 * \brief read string in initialization file

 * \param[in] 	section					name of the section containing the key name
 * \param[in] 	key						name of the key pairs to value 
 * \param[in] 	value						size of result's buffer
 * \param[in] 	size						path of the initialization file
 * \param[in] 	default_value				default value of result
 * \param[in] 	file						path of the initialization file
 * \return 		return 1 : read success; \n 0 : read fail
 * \author 		郭玉臻
 * \date 			2009-6-19
*/



int read_profile_string(  const char *key,char *value, int size, const char *default_value)
{
//	int file_size;
	int sec_s,sec_e,key_s,key_e, value_s, value_e;
  if (g_szsection == NULL || key ==NULL || value == NULL)
  {
    return -1;
  }
	if(0>=g_ifile_size)
	{
		if(default_value!=NULL)
		{
			strncpy(value,default_value, size);
		}
		return 0;
	}

	if(!parse_file(key,&sec_s,&sec_e,&key_s,&key_e,&value_s,&value_e))
	{
		if(default_value!=NULL)
		{
			strncpy(value,default_value, size);
		}
		return 0; //not find the key
	}
	else
	{
		int cpcount = value_e -value_s;

		if( size-1 < cpcount)
		{
			cpcount =  size-1;
		}
		
		memset(value, 0, size);		
		memcpy(value,g_szini_file_buffer+value_s, cpcount );
		value[cpcount] = '\0';

		return 1;
	}
}

/*! \fn read_profile_int(  const char *key,int default_value, 
								const char *file)
 * \brief read int value in initialization file

 * \param[in] 	section					name of the section containing the key name
 * \param[in] 	key						name of the key pairs to value
 * \param[in] 	default_value				default value of result
 * \param[in] 	file						path of the initialization file
 * \return 		profile int value,if read fail, return default value
 * \author 		郭玉臻
 * \date 		2009-6-19
*/
int read_profile_int(  const char *key,int default_value)
{
	char value[32] = {0};
	if(0>=read_profile_string(key,value, sizeof(value),NULL))
	{
		return default_value;
	}
	else
	{
		return atoi(value);
	}
}
__int64 read_profile_int64(  const char *key,__int64 default_value)
{
	char value[32] = {0};
	if(0>=read_profile_string(key,value, sizeof(value),NULL))
	{
		return default_value;
	}
	else
	{
		return atoll(value);
	}
}
int write_profile_char( const char *key, char chValue)
{
	int sec_s,sec_e,key_s,key_e, value_s, value_e;	
	char tmp_buf[MAX_SECTION_SIZE+MAX_KEY_SIZE+6]={0};
	int new_content_len=0;
	char *left,*right;
	if (NULL==g_szini_file_buffer||g_szsection == NULL || key ==NULL)
	{
		return -1;
	}
	if(0>=g_ifile_size)
	{
		sec_s = -1;
	}
	else
	{
		parse_file(key,&sec_s,&sec_e,&key_s,&key_e,&value_s,&value_e);
	}

	if( -1 == sec_s)
	{
		if(0==g_ifile_size)
		{
			sprintf(g_szini_file_buffer,"%c%s%c\n%s=%c\n",LEFT_BRACE,g_szsection,RIGHT_BRACE,key,chValue);
			g_ifile_size=strlen(g_szini_file_buffer);
		}
		else
		{
			//not find the section, then add the new section at end of the file			
			sprintf(tmp_buf,"%c%s%c\n%s=%c\n",LEFT_BRACE,g_szsection,RIGHT_BRACE,key,chValue);
			new_content_len=strlen(tmp_buf);
			if(new_content_len+g_ifile_size>=MAX_FILE_SIZE)
				return -1;
			memcpy(g_szini_file_buffer+g_ifile_size,tmp_buf,new_content_len);
			g_ifile_size+=new_content_len;
			g_szini_file_buffer[g_ifile_size]='\0';
		}
	}
	else if(-1 == key_s)
	{
		//not find the key, then add the new key=value at end of the section
		//	memcpy(tmp_buf,buf,sec_e);
		//	sprintf(tmp_buf+sec_e,"%s=%s\n",key,value);
		//	sprintf(tmp_buf+sec_e+strlen(key)+strlen(value)+2,buf+sec_e, file_size - sec_e);
		sprintf(tmp_buf,"%s=%c\n",key,chValue);
		new_content_len=strlen(tmp_buf);
		if(new_content_len+g_ifile_size>=MAX_FILE_SIZE)
			return -1;		
		left =g_szini_file_buffer+g_ifile_size;
		right=left+new_content_len;
		while(left>=g_szini_file_buffer+sec_e)
			*right--=*left--;		
		memcpy(g_szini_file_buffer+sec_e,tmp_buf,new_content_len);
		g_ifile_size+=new_content_len;
		g_szini_file_buffer[g_ifile_size]='\0';
	}
	else
	{
		//update value with new value
		//2009-06-22
		g_szini_file_buffer[value_s]=chValue;
	}	
	return 1;
}
/*! \fn write_profile_string( const char *key,
					const char *value, const char *file)
 * \brief rite a profile string to a ini file

 * \param[in] 	section					name of the section,can't be NULL and empty string
 * \param[in] 	key						name of the key pairs to value, can't be NULL and empty string
 * \param[in] 	value						profile string value
 * \param[in] 	file						path of ini file
 * \return 		1 : success\n 0 : failure
 * \author 		郭玉臻
 * \date 		2009-6-19
*/
int write_profile_string( const char *key, const char *value)
{			
	int sec_s,sec_e,key_s,key_e, value_s, value_e;
	int value_len = (int)strlen(value);
	char tmp_buf[MAX_SECTION_SIZE+MAX_KEY_SIZE+MAX_VALUE_SIZE+5]={0};
	int new_content_len=0;
	char *left,*right;
  if (NULL==g_szini_file_buffer||g_szsection == NULL || key ==NULL || value == NULL)
  {
    return -1;
  }
	if(0>=g_ifile_size)
	{
		sec_s = -1;
	}
	else
	{
		parse_file(key,&sec_s,&sec_e,&key_s,&key_e,&value_s,&value_e);
	}
	
	if( -1 == sec_s)
	{
		if(0==g_ifile_size)
		{
			sprintf(g_szini_file_buffer,"%c%s%c\n%s=%s\n",LEFT_BRACE,g_szsection,RIGHT_BRACE,key,value);
			g_ifile_size=strlen(g_szini_file_buffer);
		}
		else
		{
			//not find the section, then add the new section at end of the file			
			sprintf(tmp_buf,"%c%s%c\n%s=%s\n",LEFT_BRACE,g_szsection,RIGHT_BRACE,key,value);
			new_content_len=strlen(tmp_buf);
			if(new_content_len+g_ifile_size>=MAX_FILE_SIZE)
				return -1;
			memcpy(g_szini_file_buffer+g_ifile_size,tmp_buf,new_content_len);
			g_ifile_size+=new_content_len;
			g_szini_file_buffer[g_ifile_size]='\0';
		}
	}
	else if(-1 == key_s)
	{
		//not find the key, then add the new key=value at end of the section
	//	memcpy(tmp_buf,buf,sec_e);
	//	sprintf(tmp_buf+sec_e,"%s=%s\n",key,value);
	//	sprintf(tmp_buf+sec_e+strlen(key)+strlen(value)+2,buf+sec_e, file_size - sec_e);
		sprintf(tmp_buf,"%s=%s\n",key,value);
		new_content_len=strlen(tmp_buf);
		if(new_content_len+g_ifile_size>=MAX_FILE_SIZE)
			return -1;		
		left =g_szini_file_buffer+g_ifile_size;
		right=left+new_content_len;
		while(left>=g_szini_file_buffer+sec_e)
			*right--=*left--;		
		memcpy(g_szini_file_buffer+sec_e,tmp_buf,new_content_len);
		g_ifile_size+=new_content_len;
		g_szini_file_buffer[g_ifile_size]='\0';
	}
	else
	{
		//update value with new value
		//2009-06-22
		if(value_len-(value_e-value_s)+g_ifile_size>MAX_FILE_SIZE)
			return -1;		
		if(value_len>value_e-value_s)
		{
			left =g_szini_file_buffer+g_ifile_size;
			right=left+value_len-value_e+value_s;
			while(left>=g_szini_file_buffer+value_e)
				*right--=*left--;
			memcpy(g_szini_file_buffer+value_s,value,value_len);
			g_ifile_size+=value_len-value_e+value_s;
			g_szini_file_buffer[g_ifile_size]='\0';
		}
		else if(value_len<value_e-value_s)
		{
			left =g_szini_file_buffer+value_s+value_len;
			right=g_szini_file_buffer+value_e;
			while(right<g_szini_file_buffer+g_ifile_size)
				*left++=*right++;
			memcpy(g_szini_file_buffer+value_s,value,value_len);
			g_ifile_size+=value_len-value_e+value_s;
			g_szini_file_buffer[g_ifile_size]='\0';
		}
		else
		{
			memcpy(g_szini_file_buffer+value_s,value,value_len);
		}		
	}	
	return 1;
}

int write_profile_int( const char *key, int iValue)
{
	char szBuf[16] = {0};
	sprintf(szBuf, "%d", iValue); 
	write_profile_string(key, szBuf);

  return 0;
}
int write_profile_int64( const char *key, __int64 iValue)
{
	char szBuf[32] = {0};
	sprintf(szBuf, "%lld", iValue); 
	write_profile_string(key, szBuf);

	return 0;
}

void ShowErrorInfo(int iRetCode)
{
	printf("错误码:%d;  错误信息:",iRetCode);
	switch(iRetCode)
	{
	case -3:
		printf("invalid parameter\n");
		break;
	case -2:
		printf("invalid handle\n");
		break;
	case 100:
		printf("no data\n");
		break;
	case 101:
		printf("timeout\n");
		break;
	case 102:
		printf("exists\n");
		break;
	case 103:
		printf("more data\n");
		break;
	case 500:
		printf("call object function failed\n");
		break;
	case 501:
		printf("create object failed\n");
		break;
	case 502:
		printf("initialize object failed \n");
		break;
	case 503:
		printf("object uninitiated\n");
		break;
	case 504:
		printf("create resource failed\n");
		break;
	case 505:
		printf("dispatch event failed\n");
		break;
	case 506:
		printf("event  undefined \n");
		break;
	case 507:
		printf("register event {@1} from {@2} failed\n");
		break;
	case 508:
		printf("startup service {@1} failed\n");
		break;
	case 509:
		printf("init service env {@1} failed\n");
		break;
	case 510:
		printf("kernel/service env {@1} invalid\n");
		break;
	case 511:
		printf("service {@1} status not expect\n");
		break;
	case 512:
		printf("open internal queue {@1} failed\n");
		break;
	case 513:
		printf("open internal queue {@1} failed\n");
		break;
	case 514:
		printf("invalid message queue\n");
		break;
	case 515:
		printf("xml file {@1} format invalid\n");
		break;
	case 516:
		printf("open runtimedb {@1} failed\n");
		break;
	case 517:
		printf("create or initialize service function {@1}:{@2} fail \n");
		break;
	case 518:
		printf("option {@2} read only\n");
		break;
	case 519:
		printf("option {@2} unsupported \n");
		break;
	case 520:
		printf("purpose access {@2},but not granted\n");
		break;
	case 521:
		printf("queue {@1} fulled, max depth\n");
		break;
	case 522:
		printf("xa {@1} undefined\n");
		break;
	case 523:
		printf("call biz function {@1} exception\n");
		break;
	case 524:
		printf("timer {@1} callback failed, return\n");
		break;
	case 525:
		printf("filter expression {@1} invalid\n");
		break;
	case 526:
		printf("oem {@1} illegal\n");
		break;	
	case 1000:
		printf("API基本错误\n");
		break;
	case 1001:
		printf("DLL缺失\n");
		break;
	case 1002:
		printf("DLL初始化失败(版本不对)\n");
		break;
	case 1003:
		printf("API实例已存在\n");
		break;
	case 1101:
		printf("insufficient space expect\n");
		break;
	case 1102:
		printf("receive packet from {@1} failed\n");
		break;
	case 1103:
		printf("send packet to {@1} failed\n");
		break;
	case 1104:
		printf("connect to {@1} failed\n");
		break;
	case 1105:
		printf("reconnect failed in function\n");
		break;
	case 1106:
		printf("reconnect {@1} success\n");
		break;
	case 1107:
		printf("disconnect\n");
		break;
	case 1100:
		printf("call zmq api {@2} failed\n");
		break;
	case 1200:
		printf("MA_ERROR_DB_EXCEPTION\n");
		break;
	case 1201:
		printf("data {@1} unload\n");
		break;
	case 1202:
		printf("table {@1} cursor {@2} has already opened\n");
		break;
	case 1203:
		printf("table {@1} cursor {@2} not opened\n");
		break;
	case 1204:
		printf("database {@1} not opened\n");
		break;
	case 1205:
		printf("invalid database connect string\n");
		break;
	case 1250:
		printf("MA_ERROR_DAO_EXCEPTION\n");
		break;
	case 1500:
		printf("call fix api {@2} failed\n");
		break;
	case 1501:
		printf("fix parse from {@1} failed\n");
		break;
	case 1502:
		printf("call kcbp api {@2} failed\n");
		break;
	case 1503:
		printf("invalid packet {@2} failed\n");
		break;
	case 1504:
		printf("call json api {@2} failed\n");
		break;
	case 1600:
		printf("call kcxp api {@2} failed\n");
		break;
	case 2000:
		printf("API套接字错误\n");
		break;
	case 2001:
		printf("客户端连接失败(请检查连接参数与服务器是否开启)\n");
		break;
	case 2002:
		printf("服务器创建失败\n");
		break;
	case 3000:
		printf("API配置错误\n");
		break;
	case 3001:
		printf("GTU节点配置文件错误\n");
		break;
	default:
		printf("尚无详细信息\n");
		break;

	}		
}

