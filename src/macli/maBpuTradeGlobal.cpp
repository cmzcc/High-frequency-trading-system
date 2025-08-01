#include "maBpuTradeGlobal.h"

CEvent g_event;
CMutex g_mutex;

/********查询持仓总条目*********/
int  g_iQryCntPer = 0;        //每次查询条目数   
LONGLONG g_ExpShsCnt = 0LL;   //总持仓条目
bool g_bFinish = false;       //持仓是否查询完
char g_szPos[32+1] = {'\0'};  //持仓定位串
/********查询持仓总条目*********/

ST_BPU_CONTEXT g_stBpuCtx;  //全局上下文
LONGLONG g_llRequestId = 0L;  //请求ID