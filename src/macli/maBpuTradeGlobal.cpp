#include "maBpuTradeGlobal.h"

CEvent g_event;
CMutex g_mutex;

/********��ѯ�ֲ�����Ŀ*********/
int  g_iQryCntPer = 0;        //ÿ�β�ѯ��Ŀ��   
LONGLONG g_ExpShsCnt = 0LL;   //�ֲܳ���Ŀ
bool g_bFinish = false;       //�ֲ��Ƿ��ѯ��
char g_szPos[32+1] = {'\0'};  //�ֲֶ�λ��
/********��ѯ�ֲ�����Ŀ*********/

ST_BPU_CONTEXT g_stBpuCtx;  //ȫ��������
LONGLONG g_llRequestId = 0L;  //����ID