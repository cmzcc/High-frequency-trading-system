#pragma once
#include <string>
#include <unordered_set>
#include <queue>
#include <random>
#include <algorithm>
#include <unordered_map>
#include "OpenXLSX.hpp"
#ifndef INI_FILE_RW_H
#define INI_FILE_RW_H

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#define atoll _atoi64
#else 
#define __int64 long
#define errno 0
#endif

#define MAX_FILE_SIZE    1024*64
#define MAX_SECTION_SIZE 32
#define MAX_KEY_SIZE     32
#define MAX_VALUE_SIZE   512

#define LEFT_BRACE       '['
#define RIGHT_BRACE      ']'
//行情订阅分隔代码
#define SYMBOL_SEPARATOR       ','
int  load_ini_file(const char *file);
int  save_ini_file(const char *file);
void free_ini_file();
void set_section(const char *section);
//读INI文件
char    read_profile_char( const char *key,const char default_value);
int     read_profile_string( const char *key,char *value, int size,const char *default_value);
//读INI文件
int     read_profile_int( const char *key,int default_value);
__int64 read_profile_int64( const char *key,__int64 default_value);
//写INI文件
int  write_profile_char( const char *key, char chValue);
int  write_profile_string( const char *key,const char *value);

int  write_profile_int( const char *key, int iValue);
int  write_profile_int64( const char *key, __int64 llValue);

void ShowErrorInfo(int iRetCode);

	

#define CHECK_RETCODE(iRetCode,p_pclTradeApi)													\
	do{																							\
		if(iRetCode)																			\
			std::cout<<__FUNCTION__<<" Error::"<<p_pclTradeApi->GetLastErrorText()<<std::endl;	\
	}while(0)

#define READ_FROM_INI_OR_DEFAULT_CHAR(KEY,chParam,g_chDefault,BUFFER)   \
	do{	\
	read_profile_string(KEY,BUFFER,sizeof(BUFFER),"0");		\
	if(0==strcmp(KEY,BUFFER))		\
	chParam=g_chDefault;			\
	else                            \
	chParam=BUFFER[0];			 \
	}while(0)

#define READ_FROM_INI_OR_DEFAULT_INT(KEY,iParam,g_iDefault,BUFFER)   \
	do{	\
	read_profile_string(KEY,BUFFER,sizeof(BUFFER),"0");		\
	if(0==strcmp(KEY,BUFFER))		\
	iParam=g_iDefault;			\
	else                            \
	iParam=atoi(BUFFER);        \
	}while(0)

#define READ_FROM_INI_OR_DEFAULT_INT64(KEY,llParam,g_llDefault,BUFFER)   \
	do{	\
	read_profile_string(KEY,BUFFER,sizeof(BUFFER),"0");		\
	if(0==strcmp(KEY,BUFFER))		\
	llParam=g_llDefault;			\
	else                            \
	llParam=atoll(BUFFER);     \
	}while(0)

#define READ_FROM_INI_OR_DEFAULT_STRING(KEY,szParam,g_szDefault,BUFFER)   \
	do{	\
	read_profile_string(KEY,BUFFER,sizeof(BUFFER),"0");		\
	if(0==strcmp(KEY,BUFFER))								\
	strncpy(szParam,g_szDefault,sizeof(szParam));		\
	else													\
	strncpy(szParam,BUFFER,sizeof(szParam));			\
	}while(0)

#endif //INI_FILE_RW_H