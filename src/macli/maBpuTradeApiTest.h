#ifndef _MACLI_TEST_H
#define _MACLI_TEST_H

//----------------------------------------------------------------------------
//文件名称：maBpuTradeApiTest.cpp
//模块名称：股票交易API简单例子程序
//----------------------------------------------------------------------------

#include "iniFileRW.h"
#include "maBpuTradeDefine.h"
#include "maBpuTradeGlobal.h"
#include "maBpuStkReq.h"


#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>


#include <sys/types.h>
#include <sys/ioctl.h>
#include <string.h>



using std::string;
using std::cout;
using std::cin;

USE_NAMESPACE_MACLI


static void InitCliTrdApi(CCliTradeApi *pClTrdApi)
{
	set_section("Common");
	//注册连接信息信息
	CReqSysField stSysField = {0};

	stSysField.nSvrPort =read_profile_int("STK_SERVER_PORT", 41000);
    read_profile_string("STK_SERVER_IP", stSysField.szSvrAddress, sizeof(stSysField.szSvrAddress), "10.10.10.1");

	stSysField.uiTimeout = read_profile_int("TIMEOUT", 5);
	stSysField.iSsl = read_profile_int("SSL", 0);
	read_profile_string("PKT_VER", stSysField.szPktVer, sizeof(stSysField.szPktVer), "01");
  //0:不订阅；'0':按连接订阅；'1':按账户订阅（4个限制）
  char chTemp = read_profile_char("DATA_SET", 0);

  if('0'!=chTemp && '1'!=chTemp)
  {
	  stSysField.chDataSet = 0;
  }
  else
  {
	  stSysField.chDataSet = chTemp;
  }

  //软加速推送模式 '0':按账户普通  '1':按账户精简  '2':按连接普通 '3':按连接精简
  chTemp = read_profile_char("FLASH_PUB", 0);

  if('0'!=chTemp && '1'!=chTemp && '2'!=chTemp && '3'!=chTemp)
  {
    stSysField.chFlashPub = 0;
  }
  else
  {
    stSysField.chFlashPub = chTemp;
  }

	set_section("Cpp");
	stSysField.iFlashModule = read_profile_int("FLASH_MODULE", 1);
	read_profile_string("LOCAL_IP", stSysField.szLocalAddress, sizeof(stSysField.szLocalAddress), "0.0.0.0");
	cout << "Connecting Server IP: " << stSysField.szSvrAddress << ", Port: " << stSysField.nSvrPort << std::endl;
	int res = pClTrdApi->RegisterServer(&stSysField);
	cout << "RegisterServer res: " << res << std::endl;

	set_section("Common");

  //固定参数设置
  CReqFixField stFixField;
  memset(&stFixField, 0x00, sizeof(stFixField));
  stFixField.chChannel = read_profile_char("CHANNEL", 'K');
  stFixField.chOpRole = '1';
  pClTrdApi->RegisterAcct(&stFixField);

  //设置需要传入的留痕信息
  char szIip[64 + 1] = {'\0'};
  char szAppName[64 + 1] = {'\0'};
  char szAppVer[32 + 1] = {'\0'};
  read_profile_string("IIP", szIip, sizeof(szIip), "");
  read_profile_string("APP_NAME", szAppName, sizeof(szAppName), "");
  read_profile_string("APP_VER", szAppVer, sizeof(szAppVer), "");
  CReqClientField cliField = {'\0'};
  strncpy(cliField.szIip, szIip, strlen(szIip));
  sprintf(cliField.szExt, "CSC1;%s;V%s", szAppName, szAppVer);
  pClTrdApi->RegisterClient(&cliField);
}


#endif