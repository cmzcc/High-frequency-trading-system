#pragma once
#include "Event.h"
#include "Mutex.h"
#include "maBpuTradeDefine.h"

using maclicpp::CEvent;
using maclicpp::CMutex;

extern CEvent g_event;
extern CMutex g_mutex;
/********��ѯ�ֲ�����Ŀ*********/
extern int  g_iQryCntPer;       //ÿ�β�ѯ��Ŀ��   
extern LONGLONG g_ExpShsCnt;   //�ֲܳ���Ŀ
extern bool g_bFinish;       //�ֲ��Ƿ��ѯ��
extern char g_szPos[32+1];  //�ֲֶ�λ��
/********��ѯ�ֲ�����Ŀ*********/

extern ST_BPU_CONTEXT g_stBpuCtx;  //ȫ���˻���Ϣ
extern LONGLONG g_llRequestId ;  //����ID
