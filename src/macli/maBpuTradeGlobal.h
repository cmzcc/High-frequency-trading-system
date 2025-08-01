#pragma once
#include "Event.h"
#include "Mutex.h"
#include "maBpuTradeDefine.h"

using maclicpp::CEvent;
using maclicpp::CMutex;

extern CEvent g_event;
extern CMutex g_mutex;
/********查询持仓总条目*********/
extern int  g_iQryCntPer;       //每次查询条目数   
extern LONGLONG g_ExpShsCnt;   //总持仓条目
extern bool g_bFinish;       //持仓是否查询完
extern char g_szPos[32+1];  //持仓定位串
/********查询持仓总条目*********/

extern ST_BPU_CONTEXT g_stBpuCtx;  //全局账户信息
extern LONGLONG g_llRequestId ;  //请求ID
