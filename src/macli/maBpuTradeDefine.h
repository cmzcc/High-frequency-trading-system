#pragma once

#include "maCliStkTradeApiStruct.h"
#include <string>
#include <map>
#include <string.h>

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#include <Windows.h>
#define atoll _atoi64
#else
#include <sys/types.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#endif

using std::string;
using std::map;

USE_NAMESPACE_MACLI

enum EN_SUB_SYS
{
  StkSys,
  OptSys,
  FutSyS, 
  FislSys,
  MaxSys
};


//�����ļ�
#define CONF_FILE "../config/api_config.ini"

//deleter
#define SAFEDEL_PTR(ptr) \
	if(NULL != ptr) \
{ \
	delete ptr; \
	ptr = NULL; \
}

//struct
struct ST_TRADE_CONTEXT 
{
  ST_TRADE_CONTEXT() 
    : iIntOrg(0) 
    , llCustCode(0L)
    , llCuacctCode(0L)
  {
    memset(szCliRemark, 0, sizeof(szCliRemark));
    memset(szSess, 0, sizeof(szSess));
  }

  void Reset()
  {
    iIntOrg = 0;
    llCustCode = 0;
    llCuacctCode = 0;
    mapBdTrdAcct.clear();
    memset(szCliRemark, 0, sizeof(szCliRemark));
    memset(szSess, 0, sizeof(szSess));
  }


  LONGLONG             llCustCode;
  LONGLONG             llCuacctCode;
  map<string, string>  mapBdTrdAcct;                  // bd-trdacct
  int                  iIntOrg;                       // �ڲ�����
  char                 szSess[128 + 1];       //session
  char                 szCliRemark[256+1];            // ������Ϣ   CLI_REMARK   VARCHAR(256) X 8914
};

struct ST_BPU_CONTEXT 
{
  ST_BPU_CONTEXT() 
    : chChannel('\0')
  {
    memset(szPktVer, 0, sizeof(szPktVer));
    trdCtxMap[StkSys] = ST_TRADE_CONTEXT();
    trdCtxMap[OptSys] = ST_TRADE_CONTEXT();
    trdCtxMap[FutSyS] = ST_TRADE_CONTEXT();
    trdCtxMap[FislSys] = ST_TRADE_CONTEXT();
  }

  char     chChannel;       //����
  char     szPktVer[2 + 1]; //Э��
  map<EN_SUB_SYS, ST_TRADE_CONTEXT>  trdCtxMap;
};

