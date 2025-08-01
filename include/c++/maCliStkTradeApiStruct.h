#if !defined(__MA_CLI_STK_TRADE_API_STRUCT_H__)
#define __MA_CLI_STK_TRADE_API_STRUCT_H__

#include "maCliTradeApi.h"

BGN_NAMESPACE_MACLI

#if defined(OS_IS_LINUX)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

//-------------------------------10301036:֤ȯ��Ϣ��ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryInfoExField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQueryFlag;                // ��ѯ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  char            szCuacctCode[16 + 1];       // �ʲ��˻� COSϵͳʹ��
};

struct MATRADEAPI CRspStkQryInfoExField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chStkCls;                   // ֤ȯ���
  char            chStkStatus;                // ֤ȯ״̬
  char            chCurrency;                 // ���Ҵ���
  char            szStkUplmtRatio[21 + 1];    // ��ͣ����
  char            szStkLwlmtRatio[21 + 1];    // ��ͣ����
  char            szStkUplmtPrice[21 + 1];    // ��ͣ�۸�
  char            szStkLwlmtPrice[21 + 1];    // ��ͣ�۸�
  LONGLONG        llStkUplmtQty;              // �޼���������
  LONGLONG        llStkLwlmtQty;              // �޼���������
  LONGLONG        llStkUplmtQtyMp;            // �м���������
  LONGLONG        llStkLwlmtQtyMp;            // �м���������
  LONGLONG        llStkLotSize;               // ÿ������
  char            chStkLotFlag;               // ��λ��־
  char            szStkSpread[21 + 1];        // ��λ�۲�
  char            chStkCalMktval;             // ��ֵ��־
  char            chStkSuspended;             // ͣ�Ʊ�־
  char            szBondInt[21 + 1];          // ծȯ��Ϣ
  int             iBuyUnit;                   // ������С��λ
  int             iSaleUnit;                  // ������С��λ
  char            chStkLevel;                 // ֤ȯ����
  int             iStkDeadline;               // ���׽�ֹ����
  char            szRemindMessage[128 + 1];   // ������ʾ��Ϣ
  char            szStkBizs[512 + 1];         // ֤ȯҵ�� DD[STK_BIZ]
  LONGLONG        llStkCirculation;           // ��ͨ��
  char            chIsReg;                    // �Ƿ�ע����
  char            chIsVie;                    // �Ƿ����Э����Ƽܹ�
  char            chNoprofit;                 // �Ƿ���δӯ��
  char            chVoterights;               // �Ƿ����ͶƱȨ����
};

//-------------------------------10301001:֤ȯ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryStkInfoField
{
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chStkLevel;                 // ֤ȯ���� �ֵ�[STK_LEVEL] ���С�Z����ʾΪ��������ʾ����֤ȯ���;�������ȫ��
  char            chStkex;                    // �����г� �����װ�����벻�Ϸ�ʱ���ֶ���Ч
  char            szCuacctCode[16 + 1];       // �ʲ��˻� COSϵͳʹ��
};

struct MATRADEAPI CRspStkQryStkInfoField
{
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chStkCls;                   // ֤ȯ���
  char            chStkStatus;                // ֤ȯ״̬
  char            chCurrency;                 // ���Ҵ���
  char            szStkUplmtRatio[21 + 1];    // ��ͣ����
  char            szStkLwlmtRatio[21 + 1];    // ��ͣ����
  char            szStkUplmtPrice[21 + 1];    // ��ͣ�۸�
  char            szStkLwlmtPrice[21 + 1];    // ��ͣ�۸�
  LONGLONG        llStkUplmtQty;              // �޼���������
  LONGLONG        llStkLwlmtQty;              // �޼���������
  LONGLONG        llStkUplmtQtyMp;            // �м���������
  LONGLONG        llStkLwlmtQtyMp;            // �м���������
  LONGLONG        llStkLotSize;               // ÿ������
  char            chStkLotFlag;               // ��λ��־
  char            szStkSpread[21 + 1];        // ��λ�۲�
  char            chStkCalMktval;             // ��ֵ��־
  char            chStkSuspended;             // ͣ�Ʊ�־
  char            szStkIsin[16 + 1];          // ���ʱ���
  char            chStkSubCls;                // ֤ȯ����� �ֵ�[STK_SUB_CLS]
  char            szStkBizes[512 + 1];        // ֤ȯҵ�� �ֵ�[STK_BIZ]
  char            chStkCustodyMode;           // �й�ģʽ �ֵ�[STK_CUSTODY_MODE]
  char            szStkUndlCode[8 + 1];       // ���ɴ���
  char            szStkFaceVal[21 + 1];       // ֤ȯ��ֵ
  char            szBondInt[21 + 1];          // ծȯ��Ϣ
  int             iBuyUnit;                   // ������С��λ
  int             iSaleUnit;                  // ������С��λ
  char            chStkLevel;                 // ֤ȯ����
  int             iStkDeadline;               // ���׽�ֹ����
  char            szRemindMessage[128 + 1];   // ������ʾ��Ϣ
  LONGLONG        llStkCirculation;           // ��ͨ��
  int             iStkCtrlExpDate;            // ��ؽ�������
  LONGLONG        llStkPublishCount;          // �ܷ�����
  int             iDlvyCycle;                 // ��������
  char            szStkFullName[128 + 1];     // ����֤ȯ���ƣ�����
  char            chIsReg;                    // �Ƿ�ע����
  char            chIsVie;                    // �Ƿ����Э����Ƽܹ�
  char            chNoprofit;                 // �Ƿ���δӯ��
  char            chVoterights;               // �Ƿ����ͶƱȨ����
  char            chSwapFlag;                 // ת���ڱ�־
  char            chPutbackFlag;              // �����ڱ�־
  char            chPutbackCancelFlag;        // ���۳����ڱ�־
  char            szStkLayerInfo[16 + 1];     // ֤ȯ�ֲ���Ϣ
  char            chStkLayerFlag;             // �ֲ���Ϣ��־
};

//-------------------------------10303132:�̺������ѯ(�Ϻ��ƴ���)--------------------------
struct MATRADEAPI CReqStkQryClosingMktField
{
  char            chStkex;                    // �г�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
};

struct MATRADEAPI CRspStkQryClosingMktField
{
  int             iTrdDate;                   // ��������
  char            chStkex;                    // �г�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chStkCls;                   // ֤ȯ���
  char            szClosingPrice[21 + 1];     // �������̼�
  LONGLONG        llStkMatchedQty;            // �ɽ�����
  char            szStkMatchedAmt[21 + 1];    // �ɽ����
  LONGLONG        llStkBuyLeftQty;            // ����ʣ������
  LONGLONG        llStkSaleLeftQty;           // ����ʣ������
  char            chStkSuspended;             // ͣ�Ʊ�ʶ
  char            szUpdTime[32 + 1];          // ����ʱ��
  char            szRemark[56 + 1];           // ��ע
};

//-------------------------------10301022:LOF��Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryLofInfoField
{
  char szStkbd[2 + 1];                        // ���װ��
  char szLofCode[8 + 1];                      // LOF����
};

struct MATRADEAPI CRspStkQryLofInfoField
{
  char chStkex;                               // ֤ȯ������
  char szStkbd[2 + 1];                        // ���װ��
  char szLofCode[8 + 1];                      // LOF����
  char chLofCrFlag;                           // �깺��ر�־
  LONGLONG llLofCrtnUplmt;                    // �깺����
  LONGLONG llLofCrtnLwlmt;                    // �깺����
  LONGLONG llLofCrtnUnit;                     // �깺��λ
  LONGLONG llLofRdtnUplmt;                    // �������
  LONGLONG llLofRdtnlwlmt;                    // �������
  LONGLONG llLofRdtnUnit;                     // ��ص�λ
  int iLofRdtnDlvyDays;                       // ����ʽ��ת����
  char chLofType;                             // ��������
  char chLofRtdnPreFlag;                      // LOF�ʽ���ǰ���ñ�־
};

//-------------------------------10302001:����ί��------------------------------------
struct MATRADEAPI CReqStkOrderField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderPrice[21 + 1];       // ί�м۸� �ƴ����м�ί�������
  LONGLONG        llOrderQty;                 // ί������
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  int             iOrderBsn;                  // ί������
  char            szClientInfo[256 + 1];      // �ն���Ϣ ����Ӳ�̺�\CPU\�������� ��ʽ�� "PC;IIP=����IP��ַ;IPORT=����IP�˿ں�;LIP=����IP;MAC=MAC��ַ;HD=Ӳ�����к�;PCN=PC�ն��豸��;CPU=CPU���к�;PI=Ӳ�̷�����Ϣ;VOL=ϵͳ�̾����@��չ��Ϣ1;��չ��Ϣ2;��չ��Ϣ3"
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char			  szTrdacctCommon[20 + 1];	  // ��֤ͨȯ�˻�
  int             iCuacctSn;                  // �˻���� �ͻ��˱�ʶ�����ڶ���ͻ��˹���ͬһ���ʲ��˺��µ�ʱ�����ֲ�ͬ�ͻ��˵�ί����ɽ���Ϣ�����ṩ����صĽӿڲ�ѯ���ܡ�
  LONGLONG        llCustCode;                 // �ͻ�����
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szOrderText[1024 + 1];       // ί����չ ��ʽ:�ؼ���1=ֵ1,�ؼ���2=ֵ2 ��ʽ:�ؼ���1=ֵ1,�ؼ���2=ֵ2 ҵ���ʵ��Լ�飬�ؼ���ΪPROP_RISK_NO��ƥ����ˮ�ţ����磺PROP_RISK_NO=ƥ����ˮ�� �����Ҫȷ�ϱ�ʶ���ؼ���ΪOF_CTR_FLAGS ���磺OF_CTR_FLAGS=1��1����ȷ�ϣ�����ֵ��δȷ��
  char            chSecurityLevel;            // ��ȫ�ֶ� 1:У��Ựƾ֤
  char            szSecurityInfo[256 + 1];    // ��ȫ��Ϣ �Զ���д
  char            szComponetStkCode[8 + 1];   // �ɷݹɴ��� ETF���¹�Ʊ�Ϲ�����
  char            szComponetStkbd[2 + 1];     // �ɷݹɰ�� ETF���¹�Ʊ�Ϲ���ETFʵ����������
  char            szStkbdLink[2 + 1];         // ������� ETF���¹�Ʊ�Ϲ���ETFʵ����������
  char            chPublishCtrlFlag;          // ��Ʊ��ر�־ 0�������� 1�����ƹ�Ʊ����ֲֲ������ܹɱ�һ������ �������޲����󣬲�����Ϻ�̨��������ò���������Ч
  char            szRepayOrderId[10 + 1];     // ������ͬ��� ����������ȯ����
  int             iRepayOpeningDate;          // ������Լ���� ����������ȯ����
  char            szRepayStkCode[8 + 1];      // ����֤ȯ���� ����������ȯ����
  char            szTrdacctLink[20 + 1];      // �����ɶ� ���ڿ��г�ETF����
  char            szInitTrdAmt[21 + 1];       // ��ʼ���׽�� ���ڹ�Ʊ��Ѻ����
  int             iRepchDay;                  // �������� ���ڹ�Ʊ��Ѻ����
  char            szLoanerTrdacct[20 + 1];    // ������֤ȯ�˻� ���ڹ�Ʊ��Ѻ����
  char            szRepaySno[32 + 1];         // ��Լ��� ���ڹ�Ʊ��Ѻ����
  char            szContactInfo[32 + 1];      // ���ڽ���ʱ����ϵ��ʽ
  int             iItemno;                    // ��Լ��� ���ڹ�Ʊ��Ѻ����
  char            chOutputDelayFlag;          // ���ʱ�ӱ�־ 0:�����������������ʱ 1:���������������ʱ Ĭ��Ϊ0
  char            chCloseOutMode;             // ƽ�ַ�ʽ ���ڹ�Ʊ��Ѻ����
  char            chEtfMode;                  // ETFģʽ ������ETF�깺���� �ֵ�[ETF_MODE]
  char            szMeetingSeq[10 + 1];       // �ɶ������� ��������ͶƱ����
  char            szVoteId[10 + 1];           // �鰸��� ��������ͶƱ����
  char            szOppLofCode[3 + 1];        // ת�뷽������� ������֤LOF����ת������
  LONGLONG        llMatchNo;                  // �ɽ�Լ����
  char            szOpptStkpbu[8 + 1];        // ���ַ����׵�Ԫ
  char            szOpptTrdacct[20 + 1];      // ���ַ��ɶ��˻�
  char            szStkprop[2 + 1];           // �ɷ�����
  char            szLoanerName[40 + 1];       // ��ϵ������
};

struct MATRADEAPI CRspStkOrderField
{
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ������
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  int           iCuacctSn;                    // �˻����
  int           iOrderSn;                     // ί�����
  char          chOrderStatus;                // ί��״̬
  char          szStkName[64 + 1];            // ֤ȯ����
};

//-------------------------------10302003:���ί��------------------------------------
struct MATRADEAPI CReqStkCombOrderField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  int           iOrderBsn;                    // ί������
  int           iCuacctSn;                    // �˻����
  char          chErrorFlag;                  // �������ױ�־
  char          szStrategyText[32768 + 1];    // ������Ϣ
  LONGLONG      llCustCode;                   // �ͻ�����
  char          szClientInfo[256 + 1];        // �ն���Ϣ
  char          szTrdTermcode[20 + 1];        // �ն�������
  char          chSecurityLevel;              // ��ȫ�ֶ�
  char          szSecurityInfo[256 + 1];      // ��ȫ��Ϣ
  char          chPublishCtrlFlag;            // ��Ʊ��ر�־
  int           iTgwIndex;                    // ָ�����̵��±�
};

struct MATRADEAPI CRspStkCombOrderField
{
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  int           iCuacctSn;                    // �˻����
  int           iOrderRet;                    // ί�н��
  char          szRetInfo[256 + 1];           // ������Ϣ
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ������
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkName[64 + 1];            // ֤ȯ����
  int           iStkBizAction;                // ҵ����Ϊ
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
};

//-------------------------------10302004:ί�г���------------------------------------
struct MATRADEAPI CReqStkCancelOrderField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iStkBiz;                      // ֤ȯҵ��
  int           iOrderBsn;                    // ί������
  char          szClientInfo[256 + 1];        // �ն���Ϣ
  LONGLONG      llCustCode;                   // �ͻ�����(δ����)
  LONGLONG      llFortuneCode;                // �Ƹ��˻�(δ����)
};

struct MATRADEAPI CRspStkCancelOrderField
{
  char          szOrderId[10 + 1];            // ��ͬ��� ԭί�к�ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  int           iStkBiz;                      // ֤ȯҵ��
  char          szWtOrderId[10 + 1];          // ί�к�ͬ�� ����ί�к�ͬ���
  int           iOrderBsn;                    // ί������
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ������
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  int           iStkBizAction;                // ҵ����Ϊ
  char          chCancelStatus;               // �ڲ�������־
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szMsgOk[32 + 1];              // �ڳ���Ϣ ������ڲ��������޸ķ�����ϢΪ "����������"
  char          szCancelList[256 + 1];        // �����б� ��ʽ: ԭί�����#����ί�����#�ڲ�������־#������Ϣ|......|  ����ί�����=-1 ��ʾ����ʧ��
  long long     llFortuneCode;                // �Ƹ��˻�(δ����)
};

//-------------------------------10302010:���ɽ���������----------------------------
struct MATRADEAPI CReqStkMaxTradeQtyField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderPrice[21 + 1];       // ί�м۸�
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            chHiqtyFlag;                // ������ޱ�־ ���ӿ�Ԥ�����ݲ�ʵ�֣�
  char            szStkbdLink[2 + 1];         // ������� ETFʵ������ʱ�ͣ��ӿ�Ԥ�����ݲ�ʵ�֣�
  char            szTrdacctLink[20 + 1];      // �����ɶ� ETFʵ������ʱ�ͣ��ӿ�Ԥ�����ݲ�ʵ�֣�
  char            szMeetingSeq[10 + 1];       // �ɶ�������
  char            szVoteId[10 + 1];           // �鰸���
  char            chEtfMode;                  // ETFģʽ �ֵ�ETF_MODE
  char            chStkBizCtvFlag;            // ҵ��ת����־
  int             iTrdDate;                   // ��������
  char            szOrderId[10 + 1];          // ��ͬ���
  char            szStkpbu[8 + 1];            // ����ϯλ
  char            szStkprop[2 + 1];           // �ɷ�����
  char            szSdStkType[2 + 1];         // �ϵ�֤ȯ���
  char            szEquitType[2 + 1];         // Ȩ������
  char            chCirculType;               // ��ͨ����
  char            szProdcode[12 + 1];         // ��Ʒ����
  char            szOrderText[256 + 1];       // ί����չ ��ʽ:�ؼ���1=ֵ1,�ؼ���2=ֵ2 �ʵ���ҵ����򣬹ؼ���ΪPROP_RISK_NO������ƥ����ˮ�ţ����磺 PROP_RISK_NO=��ˮ��
};

struct MATRADEAPI CRspStkMaxTradeQtyField
{
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  LONGLONG        llOrderQty;                 // ί������ ��ί���������
  LONGLONG        llStkQty;                   // �ɷֹ�����
};

//-------------------------------10302011:����ί��------------------------------------
struct MATRADEAPI CReqStkQuantityOrderField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  int           iTrdacctCnt;                  // ֤ȯ�˻�����
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  LONGLONG      llTrdacctSaleLimit;           // ���˻������ɷ��޶�
  int           iTrdacctStartNo;              // ֤ȯ�˻���ʼ���
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  int           iOrderBsn;                    // ί������
  char          szClientInfo[256 + 1];        // �ն���Ϣ
  char          chSecurityLevel;              // ��ȫ�ֶ�
  char          szSecurityInfo[256 + 1];      // ��ȫ��Ϣ
  int           iCuacctSn;                    // �˻����
  char          chPublishCtrlFlag;            // ��Ʊ��ر�־
};

struct MATRADEAPI CRspStkQuantityOrderField
{
  int           iOrderBsn;                    // ί������
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  int           iTrdacctSuccCnt;              // ֤ȯ�˻�ί�гɹ��ۼ�
  LONGLONG      llOrderQtySum;                // ί�������ɹ��ۼ�
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  int           iCuacctSn;                    // �˻����
};

//-------------------------------10302012:��������------------------------------------
struct MATRADEAPI CReqStkQuantityCancelOrderField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  int           iStkBiz;                      // ֤ȯҵ��
  int           iOrderBsn;                    // ί������
  char          szClientInfo[256 + 1];        // �ն���Ϣ
};

struct MATRADEAPI CRspStkQuantityCancelOrderField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iCancelRet;                   // �������
  char          szRetInfo[256 + 1];           // ������Ϣ
};

//-------------------------------10302019:ETF ����ί��--------------------------------
struct MATRADEAPI CReqStkEtfOrderField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szEtfCode[8 + 1];             // ETF����
  LONGLONG      llOrderQty;                   // ί������
  char          szPriceInfo[10240 + 1];       // �۸���Ϣ
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          chBizType;                    // ��������
  char          szClientInfo[256 + 1];        // �ն���Ϣ
  char          chSecurityLevel;              // ��ȫ�ֶ�
  char          szSecurityInfo[256 + 1];      // ��ȫ��Ϣ
  char          szTrdacctLink[20 + 1];        // �����ɶ�
  char          chPublishCtrlFlag;            // �ֱֲ�������
  int           iCuacctSn;                    // �˻����
};

struct MATRADEAPI CRspStkEtfOrderField
{
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ������
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  int           iCuacctSn;                    // �˻����
};

//-------------------------------10302020:����ί�����ɽ���������--------------------
struct MATRADEAPI CReqStkEtfMaxTradeQtyField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szEtfCode[8 + 1];             // ETF����
  char          szPriceInfo[10240 + 1];       // �۸���Ϣ
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          chBizType;                    // ��������
  char          szTrdacctLink[20 + 1];        // �����ɶ�
};

struct MATRADEAPI CRspStkEtfMaxTradeQtyField
{
  char          chStkex;                      // �����г�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szStkCode[8 + 1];             // ֤ȯ����
  LONGLONG      llOrderQty;                   // ί������
};

//-------------------------------10303001:�����ʽ��ѯ--------------------------------
struct MATRADEAPI CReqStkQryExpendableFundField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iValueFlag;                   // ȡֵ��־
};

struct MATRADEAPI CRspStkQryExpendableFundField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iIntOrg;                      // �ڲ�����
  char          szMarketValue[21 + 1];        // �ʲ���ֵ
  char          szFundValue[21 + 1];          // �ʽ��ʲ�
  char          szStkValue[21 + 1];           // ��ֵ
  char          szFundLoan[21 + 1];           // �����ܽ��
  char          szFundLend[21 + 1];           // ��ȯ�ܽ��
  char          szFundPrebln[21 + 1];         // �ʽ��������
  char          szFundBln[21 + 1];            // �ʽ����
  char          szFundAvl[21 + 1];            // �ʽ���ý��
  char          szFundFrz[21 + 1];            // �ʽ𶳽���
  char          szFundUfz[21 + 1];            // �ʽ�ⶳ���
  char          szFundTrdFrz[21 + 1];         // �ʽ��׶�����
  char          szFundTrdUfz[21 + 1];         // �ʽ��׽ⶳ���
  char          szFundTrdOtd[21 + 1];         // �ʽ�����;���
  char          szFundTrdBln[21 + 1];         // �ʽ���������
  char          chFundStatus;                 // �ʽ�״̬
  char          chCuacctAttr;                 // �ʲ��˻�����
  char          szFundBorrowBln[21 + 1];      // �ʽ��ڲ������
  char          szHFundAvl[21 + 1];           // ��ͨ�ʽ����
  char          szHFundTrdFrz[21 + 1];        // ��ͨ�ʽ��׶���
  char          szHFundTrdUfz[21 + 1];        // ��ͨ�ʽ��׽ⶳ
  char          szHFundTrdOtd[21 + 1];        // ��ͨ�ʽ�����;
  char          szHFundTrdBln[21 + 1];        // ��ͨ�ʽ�������
  char          szCreditFundBln[21 + 1];      // ��ȯ�������
  char          szCreditFundFrz[21 + 1];      // ��ȯ��������
  char          szQryPos[32 + 1];             // ��λ��
  char          chHgtFlag;                    // �۹�ͨ�ʽ�ͨ�ñ�־
  int           iExtOrg;                      // �ⲿ����
  char          szCashproval[21 + 1];         // �ֽ��ʲ�
  char          szTranAvl[21 + 1];            // ����ȡ���
  char          szLwlmtFund[21 + 1];          // Ԥ����� �ʽ�����
};

//-------------------------------10301653:��Ƶ�������Ʋ�����ѯ--------------------------------
struct MATRADEAPI CReqStkQryFreqTradeLmtParamField
{
  LONGLONG      llCustCode;                      // �ͻ�����
  LONGLONG      llCuacctCode;                    // �ʲ��ʺ�
  char          szStkbd[2 + 1];                  // ���װ��
  char          szTrdacct[20 + 1];               // �����˺�
};

struct MATRADEAPI CRspStkQryFreqTradeLmtParamField
{
  LONGLONG      llCustCode;                      // �ͻ�����
  LONGLONG      llCuacctCode;                    // �ʲ��ʺ�
  char          szStkbd[2 + 1];                  // ���װ��
  char          szTrdacct[20 + 1];               // �ɶ��˻�
  int           iTimeslice;                      // ����ʱ��Ƭ
  int           iTimesliceUplmtNum;              // ������ֵ
  int           iDayUplmtNum;                    // ����������ֵ
};

//-------------------------------10349043:�����ʽ��ѯ(��ϯ����)----------------------------
struct MATRADEAPI CReqStkQryExpendableFundCiXiField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  int             iValueFlag;                 // ȡֵ��־
};

struct MATRADEAPI CRspStkQryExpendableFundCiXiField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iIntOrg;                      // �ڲ�����
  char          szMarketValue[21 + 1];        // �ʲ���ֵ
  char          szFundValue[21 + 1];          // �ʽ��ʲ�
  char          szStkValue[21 + 1];           // ��ֵ
  char          szFundLoan[21 + 1];           // �����ܽ��
  char          szFundLend[21 + 1];           // ��ȯ�ܽ��
  char          szFundPrebln[21 + 1];         // �ʽ��������
  char          szFundBln[21 + 1];            // �ʽ����
  char          szFundAvl[21 + 1];            // �ʽ���ý��
  char          szFundFrz[21 + 1];            // �ʽ𶳽���
  char          szFundUfz[21 + 1];            // �ʽ�ⶳ���
  char          szFundTrdFrz[21 + 1];         // �ʽ��׶�����
  char          szFundTrdUfz[21 + 1];         // �ʽ��׽ⶳ���
  char          szFundTrdOtd[21 + 1];         // �ʽ�����;���
  char          szFundTrdBln[21 + 1];         // �ʽ���������
  char          chFundStatus;                 // �ʽ�״̬
  char          chCuacctAttr;                 // �ʲ��˻�����
  char          szFundBorrowBln[21 + 1];      // �ʽ��ڲ������
  char          szHFundAvl[21 + 1];           // ��ͨ�ʽ����
  char          szHFundTrdFrz[21 + 1];        // ��ͨ�ʽ��׶���
  char          szHFundTrdUfz[21 + 1];        // ��ͨ�ʽ��׽ⶳ
  char          szHFundTrdOtd[21 + 1];        // ��ͨ�ʽ�����;
  char          szHFundTrdBln[21 + 1];        // ��ͨ�ʽ�������
  char          szCreditFundBln[21 + 1];      // ��ȯ�������
  char          szCreditFundFrz[21 + 1];      // ��ȯ��������
  char          szQryPos[32 + 1];             // ��λ��
  char          chHgtFlag;                    // �۹�ͨ�ʽ�ͨ�ñ�־
  int           iExtOrg;                      // �ⲿ����
  char          szTranAvl[21 + 1];            // ����ȡ���
  char          szCashproval[21 + 1];         // �ֽ��ʲ�
  char          szLwlmtFund[21 + 1];          // Ԥ����� �ʽ�����
};

//-------------------------------10303002:���ùɷݲ�ѯ--------------------------------
struct MATRADEAPI CReqStkQryExpendableSharesField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          chQueryFlag;                  // ��ѯ����
  char          szTrdacct[20 + 1];            // �����˻�
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  char          chContractFlag;               // ���ú�Լ����
  char          chBizFlag;                    // ҵ���־
  char          iIntOrg;                      // �ڲ�����
};

struct MATRADEAPI CRspStkQryExpendableSharesField
{
  char          szQryPos[32 + 1];             // ��λ��
  int           iIntOrg;                      // �ڲ�����
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szTrdacct[20 + 1];            // �����˻�
  char          chCurrency;                   // ���Ҵ���
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  char          chStkCls;                     // ֤ȯ���
  LONGLONG      llStkPrebln;                  // ֤ȯ�������
  LONGLONG      llStkBln;                     // ֤ȯ���
  LONGLONG      llStkAvl;                     // ֤ȯ��������
  LONGLONG      llStkFrz;                     // ֤ȯ��������
  LONGLONG      llStkUfz;                     // ֤ȯ�ⶳ����
  LONGLONG      llStkTrdFrz;                  // ֤ȯ���׶�������
  LONGLONG      llStkTrdUfz;                  // ֤ȯ���׽ⶳ����
  LONGLONG      llStkTrdOtd;                  // ֤ȯ������;����
  LONGLONG      llStkTrdBln;                  // ֤ȯ������������
  char          szStkBcost[21 + 1];           // ֤ȯ����ɱ�
  char          szStkBcostRlt[21 + 1];        // ֤ȯ����ɱ���ʵʱ��
  char          szStkPlamt[21 + 1];           // ֤ȯӯ�����
  char          szStkPlamtRlt[21 + 1];        // ֤ȯӯ����ʵʱ��
  char          szMktVal[21 + 1];             // ��ֵ
  char          szCostPrice[21 + 1];          // �ɱ��۸�
  char          szProIncome[21 + 1];          // �ο�ӯ��
  char          chStkCalMktval;               // ��ֵ�����ʶ
  LONGLONG      llStkQty;                     // ��ǰӵ����
  char          szCurrentPrice[21 + 1];       // ���¼۸�
  char          szProfitPrice[21 + 1];        // �ο��ɱ���
  LONGLONG      llStkDiff;                    // ����������
  LONGLONG      llStkTrdUnfrz;                // ����������
  char          szIncome[21 + 1];             // ӯ��
  LONGLONG      llStkRemain;                  // ��ȯ��������
  LONGLONG      llStkSale;                    // ������������
  char          chIsCollat;                   // �Ƿ��ǵ���Ʒ
  char          szCollatRatio[21 + 1];        // ����Ʒ������
  char          szMarketValue[21 + 1];        // ��ֵ���˻���
  LONGLONG      llMktQty;                     // ��ǰӵ�������˻���
  char          szLastPrice[21 + 1];          // ���¼۸��˻���
  char          szProfitRate[21 + 1];         // ӯ������
  char          szAveragePrice[21 + 1];       // �������
  LONGLONG      llStkTrdEtfctn;               // ETF�깺����
  LONGLONG      llStkTrdEtfrmn;               // ETF�������
  LONGLONG      llStkIntradayQty;             // ������ͨ����ɷ�
  LONGLONG      llFislIntradayQty;            // ������������ɷ�
};

//-------------------------------10303003:����ί�в�ѯ--------------------------------
struct MATRADEAPI CReqStkQryCurrDayOrderField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iOrderBsn;                    // ί������
  char          szTrdacct[20 + 1];            // �����˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
  char          chFlag;                       // ��ѯ��־
};

struct MATRADEAPI CRspStkQryCurrDayOrderField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  int           iIntOrg;                      // �ڲ�����
  int           iTrdDate;                     // ��������
  int           iOrderDate;                   // ί������
  char          szOrderTime[32 + 1];          // ί��ʱ��
  char          szOrderId[10 + 1];            // ��ͬ���
  char          chOrderStatus;                // ί��״̬
  char          chOrderValidFlag;             // ί����Ч��־
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  char          chCurrency;                   // ���Ҵ���
  char          szBondInt[21 + 1];            // ծȯ��Ϣ
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ί�ж�����
  char          szOrderUfzAmt[21 + 1];        // ί�нⶳ���
  LONGLONG      llOfferQty;                   // �걨����
  int           iOfferStime;                  // �걨ʱ��
  LONGLONG      llWithdrawnQty;               // �ѳ�������
  LONGLONG      llMatchedQty;                 // �ѳɽ�����
  char          chIsWithdraw;                 // ������־
  char          chIsWithdrawn;                // �ѳ�����־
  int           iOrderBsn;                    // ί������
  char          szMatchedAmt[21 + 1];         // �ɽ����
  char          szTrdacct[20 + 1];            // �����˻�
  int           iCuacctSn;                    // �˻����
  char          szRawOrderId[10 + 1];         // ԭ��ͬ���
  char          szOfferRetMsg[64 + 1];        // �걨��Ϣ
  char          szOpSite[256 + 1];            // ����վ��
  char          chChannel;                    // ��������
  char          szRltSettAmt[21 + 1];         // ʵʱ������
  char          szStkCls[2 + 1];              // ֤ȯ���
};

//-------------------------------10303004:���ճɽ���ѯ--------------------------------
struct MATRADEAPI CReqStkQryCurrDayFillField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iOrderBsn;                    // ί������
  char          szTrdacct[20 + 1];            // �����˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
  char          chFlag;                       // ��ѯ��־
};

struct MATRADEAPI CRspStkQryCurrDayFillField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  char          szMatchedTime[8 + 1];         // �ɽ�ʱ��
  int           iOrderDate;                   // ί������
  int           iOrderSn;                     // ί�����
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iIntOrg;                      // �ڲ�����
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szStkTrdacct[20 + 1];         // ֤ȯ�˻�
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ֤ȯҵ����Ϊ
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  char          chCurrency;                   // ���Ҵ���
  char          szBondInt[21 + 1];            // ծȯ��Ϣ
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ί�ж�����
  char          szMatchedSn[32 + 1];          // �ɽ����
  char          szMatchedPrice[21 + 1];       // �ɽ��۸�
  char          szMatchedQty[21 + 1];         // �ѳɽ�����
  char          szMatchedAmt[21 + 1];         // �ѳɽ����
  char          chMatchedType;                // �ɽ�����
  int           iCuacctSn;                    // �˻����
  char          chIsWithdraw;                 // ������־
  char          chOrderStatus;                // ί��״̬
  char          szRltSettAmt[21 + 1];         // ʵʱ������
  char          szStkCls[2 + 1];              // ֤ȯ���
};

//-------------------------------10303005:�ɶ��˻���ѯ--------------------------------
struct MATRADEAPI CReqStkQryStkholderAcctField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // �����˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  char          szIntOrg[256 + 1];            // �ڲ�����
  char          chTregStatus;                 // ָ��״̬
};

struct MATRADEAPI CRspStkQryStkholderAcctField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chStkex;                      // �����г�
  char          szStkbd[2 + 1];               // ���װ��
  int           iIntOrg;                      // �ڲ�����
  int           iTrdacctSn;                   // �˻����
  char          szTrdacctExid[20 + 1];        // �����˻�
  char          chTrdacctStatus;              // �˻�״̬
  char          chTregStatus;                 // ָ��״̬
  char          chBregStatus;                 // �ع�״̬
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  char          szIdType[2 + 1];              // ֤������
  char          szIdCode[48 + 1];             // ֤������
  char          szCustName[8 + 1];            // �ͻ�����
  char          chTrdacctExcls;               // �����˻����
  char          chTrdacctMainFlag;            // �������˻���־
  char          chLimitFlag;                  // ���޹ɶ���־
};

//-------------------------------10303006:�ɳ���ί�в�ѯ------------------------------
struct MATRADEAPI CReqStkQryCanWithdrawOrderField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iOrderBsn;                    // ί������
  char          szTrdacct[20 + 1];            // �����˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
};

struct MATRADEAPI CRspStkQryCanWithdrawOrderField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  int           iIntOrg;                      // �ڲ�����
  int           iTrdDate;                     // ��������
  int           iOrderDate;                   // ί������
  char          szOrderTime[32 + 1];          // ί��ʱ��
  char          szOrderId[10 + 1];            // ��ͬ���
  char          chOrderStatus;                // ί��״̬
  char          chOrderValidFlag;             // ί����Ч��־
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  char          chCurrency;                   // ���Ҵ���
  char          szOrderPrice[21 + 1];         // ί�м۸�
  LONGLONG      llOrderQty;                   // ί������
  char          szOrderAmt[21 + 1];           // ί�н��
  char          szOrderFrzAmt[21 + 1];        // ί�ж�����
  char          szOrderUfzAmt[21 + 1];        // ί�нⶳ���
  LONGLONG      llOfferQty;                   // �걨����
  int           iOfferStime;                  // �걨ʱ��
  LONGLONG      llWithdrawnQty;               // �ѳ�������
  LONGLONG      llMatchedQty;                 // �ѳɽ�����
  char          chIsWithdraw;                 // ������־
  char          chIsWithdrawn;                // �ѳ�����־
  int           iOrderBsn;                    // ί������
  char          szMatchedAmt[21 + 1];         // �ɽ����
  char          szTrdacct[20 + 1];            // �����˻�
  int           iCuacctSn;                    // �˻����
};

//-------------------------------10303011:�����ʽ��ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryExpendableFundExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
};

struct MATRADEAPI CRspStkQryExpendableFundExField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iIntOrg;                      // �ڲ�����
  char          chCuacctAttr;                 // �ʲ��˻�����
  char          szFundPrebln[21 + 1];         // �ʽ��������
  char          szFundBln[21 + 1];            // �ʽ����
  char          szFundAvl[21 + 1];            // �ʽ���ý��
  char          szFundTrdFrz[21 + 1];         // �ʽ��׶�����
  char          szFundTrdUfz[21 + 1];         // �ʽ��׽ⶳ���
  char          szFundTrdOtd[21 + 1];         // �ʽ�����;���
  char          szFundTrdBln[21 + 1];         // �ʽ���������
  char          chFundStatus;                 // �ʽ�״̬
  char          szCreditFundBln[21 + 1];      // �����ʽ����
  char          szCreditFundFrz[21 + 1];      // ���ö�����
};

//-------------------------------10303012:���ùɷݲ�ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryExpendableSharesExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
};

struct MATRADEAPI CRspStkQryExpendableSharesExField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  int           iIntOrg;                      // �ڲ�����
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szTrdacct[20 + 1];            // �����˻�
  char          chCurrency;                   // ���Ҵ���
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          chStkCls;                     // ֤ȯ���
  LONGLONG      llStkAvl;                     // ֤ȯ��������
  LONGLONG      llStkBln;                     // ֤ȯ���
  LONGLONG      llStkTrdFrz;                  // ֤ȯ���׶�������
  LONGLONG      llStkTrdUfz;                  // ֤ȯ���׽ⶳ����
  LONGLONG      llStkTrdOtd;                  // ֤ȯ������;����
  LONGLONG      llStkTrdBln;                  // ֤ȯ������������
  LONGLONG      llStkQty;                     // ��ǰӵ����
  LONGLONG      llStkDiff;                    // ����������
  LONGLONG      llStkTrdUnfrz;                // ����������
  LONGLONG      llStkIntradayQty;             // ������ͨ����ɷ�
  LONGLONG      llFislIntradayQty;            // ������������ɷ�
};

//-------------------------------10303013:����ί�в�ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryCurrDayOrderExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu [8 + 1];             // ���׵�Ԫ
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iCuacctSn;                    // �˻����
  char          chFlag;                       // ��ѯ��־
};

struct MATRADEAPI CRspStkQryCurrDayOrderExField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  int           iIntOrg;                      // �ڲ�����
  char          szOrderId[10 + 1];            // ��ͬ���
  char          chOrderStatus;                // ί��״̬
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  LONGLONG      llOrderQty;                   // ί������
  LONGLONG      llWithdrawnQty;               // �ѳ�������
  LONGLONG      llMatchedQty;                 // �ѳɽ�����
  char          chIsWithdraw;                 // ������־
  char          chIsWithdrawn;                // �ѳ�����־
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ֤ȯҵ����Ϊ
  int           iCuacctSn;                    // �˻����
  int           iOrderBsn;                    // ί������
  char          szRawOrderId[10 + 1];         // ԭ��ͬ���
};

//-------------------------------10303014:���ճɽ���ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryCurrDayFillExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
  char          szOrderId[10 + 1];            // ��ͬ���
};

struct MATRADEAPI CRspStkQryCurrDayFillExField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iIntOrg;                      // �ڲ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkTrdacct[20 + 1];         // ֤ȯ�˻�
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ֤ȯҵ����Ϊ
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  LONGLONG      llOrderQty;                   // ί������
  char          szMatchedSn[32 + 1];          // �ɽ����
  char          szMatchedPrice[21 + 1];       // �ɽ��۸�
  char          szMatchedQty[21 + 1];         // �ɽ�����
  char          szMatchedAmt[21 + 1];         // �ɽ����
  int           iCuacctSn;                    // �˻����
  char          chOrderStatus;                // ί��״̬
};

//-------------------------------10303015:�ɶ��˻���ѯ[����]--------------------------
struct MATRADEAPI CReqStkQryStkholderAcctExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
};

struct MATRADEAPI CRspStkQryStkholderAcctExField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chStkex;                      // �����г�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
  int           iIntOrg;                      // �ڲ�����
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          chTrdacctExcls;               // �����˻����
};

//-------------------------------10303016:�ɳ���ί�в�ѯ[����]------------------------
struct MATRADEAPI CReqStkQryCanWithdrawOrderExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��
  int           iQueryNum;                    // ��ѯ����
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iCuacctSn;                    // �˻����
};

struct MATRADEAPI CRspStkQryCanWithdrawOrderExField
{
  char          szQryPos[32 + 1];             // ��λ����ѯ
  int           iIntOrg;                      // �ڲ�����
  char          szOrderId[10 + 1];            // ��ͬ���
  char          chOrderStatus;                // ί��״̬
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szStkName[64 + 1];            // ֤ȯ����
  LONGLONG      llOrderQty;                   // ί������
  LONGLONG      llWithdrawnQty;               // �ѳ�������
  LONGLONG      llMatchedQty;                 // �ѳɽ�����
  char          chIsWithdraw;                 // ������־
  char          chIsWithdrawn;                // �ѳ�����־
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ֤ȯҵ����Ϊ
  int           iCuacctSn;                    // �˻����
};

//-------------------------------10303018:ETF �ɷֹɳֲֲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryEtfCotPositionField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szEtfCode[8 + 1];             // ETF����
  char          szStkbd[2 + 1];               // ���װ��
};

struct MATRADEAPI CRspStkQryEtfCotPositionField
{
  char          szEtfCode[8 + 1];                // ETF����
  char          szStkCode[8 + 1];                // �ɷֹɴ���
  char          szStkName[64 + 1];               // �ɷֹɼ��
  char          chStkMarket;                     // �ɷֹɽ����г�
  LONGLONG      llStkQty;                        // �ɷֹ�����
  LONGLONG      llStkAvl;                        // �ͻ��ֲ�����
  char          chEtfInsteadFlag;                // �����־
  char          szEtfOverflowRate[21 + 1];       // ��۱���
  char          szCreationInsteadAmt[21 + 1];    // �깺������
  char          szRedemptionInsteadAmt[21 + 1];  // ���������
  char          szStkbd[2 + 1];                  // ���װ��
};

//-------------------------------10301034:֤ȯ��ֵ��Ȳ�ѯ------------------------------------
struct MATRADEAPI CReqStkMktQuotaField
{
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
};

struct MATRADEAPI CRspStkMktQuotaField
{
  char            chStkex;                    // ������ �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  LONGLONG        llMktQuota;                 // ��ֵ���(����)
  LONGLONG        llKcbMktquota;              // ��ֵ���(�ƴ���)
};

//-------------------------------10301016:ETF��Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryEtfInfoField
{
  char          szStkbd[2 + 1];             // ���װ��
  char          szEtfCode[8 + 1];           // ETF����
  char          chEtfMode;                  // ETFģʽ �ֵ�ETF_MODE
  char          chEtfType;                  // ETF����
};

struct MATRADEAPI CRspStkQryEtfInfoField
{
  char          chStkex;                    // ֤ȯ������
  char          szStkbd[2 + 1];             // ���װ��
  int           iTrdDate;                   // ��������
  int           iTrdPredate;                // ǰ������
  char          szEtfCode[8 + 1];           // ETF����
  char          szEtfName[64 + 1];          // ETF����
  char          chEtfPublish;               // ETF������־
  char          chEtfCrFlag;                // �깺��ر�־
  LONGLONG      llEtfCrUnit;                // �깺��ص�λ
  char          szEtfCashRatio[21 + 1];     // �ֽ��������
  int           iEtfStkNum;                 // ETF��Ʊ����Ʊ��
  char          szEtfEstmCash[21 + 1];      // ETF��Ʊ���ֽ��
  char          szEtfCashComp[21 + 1];      // ��׼��λ�ֽ�
  char          szEtfNavPercu[21 + 1];      // ��׼��λ��ֵ
  char          szEtfNav[21 + 1];           // ETF��λ��ֵ
  char          chEtfType;                  // ETF����
  LONGLONG      llCreationLimit;            // �깺����
  LONGLONG      llRedemptionLimit;          // �������
  LONGLONG      llClimitPerUser;            // ���˻��깺����
  LONGLONG      llRlimitPerUser;            // ���˻��������
  char          chEtfMode;                  // ETFģʽ �ֵ�ETF_MODE
  char          chRiskLevel;                // ���ռ���
  char          chQsEtfCrFlag;              // ȯ���깺��ر�־
  char          szEtfUndlCode[8 + 1];       // ETF�����г�����
};

//-------------------------------10301018:ETF����Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryEtfBasketField
{
  char          szStkbd[2 + 1];                   // ���װ��
  char          szEtfCode[8 + 1];                 // ETF����
  char          chEtfMode;                        // ETFģʽ �ֵ�ETF_MODE
};

struct MATRADEAPI CRspStkQryEtfBasketField
{
  char          chStkex;                          // ֤ȯ������
  char          szStkbd[2 + 1];                   // ���װ��
  char          szEtfCode[8 + 1];                 // ETF����
  char          szStkCode[8 + 1];                 // ֤ȯ����
  char          szStkName[64 + 1];                // ֤ȯ����
  LONGLONG      llStkQty;                         // ֤ȯ����
  char          chEtfInsteadFlag;                 // �ֽ������־
  char          szEtfOverflowRate[21 + 1];        // ��۱���
  char          szRedemptionInsteadAmt[21 + 1];   // ����ֽ�������
  char          chComponetStkex;                  // �ɷݹ��г�����
  char          szCreationInsteadAmt[21 + 1];     // �깺�ֽ�������
  char          chEtfMode;                        // ETFģʽ �ֵ�ETF_MODE
  int           iUpdDate;                         // ��������
  char          szEtfDiscountRate[21 + 1];        // �ۼ۱���
};

//-------------------------------10301053:�۹�ͨ������Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryRateInfoField
{
  char          szStkbd[2 + 1];              // ���װ��
  char          chCurrency;                  // ���Ҵ���
};

struct MATRADEAPI CRspStkQryRateInfoField
{
  char          chStkex;                     // �����г�
  char          szStkbd[2 + 1];              // ���װ��
  char          chCurrency;                  // ���Ҵ���
  char          szBuyRate[21 + 1];           // ����ο�����
  char          szDayBuyRiseRate[21 + 1];    // �ռ�����ο����ʸ�������
  char          szNightBuyRiseRate[21 + 1];  // ҹ������ο����ʸ�������
  char          szSaleRate[21 + 1];          // �����ο�����
  char          szDaySaleRiseRate[21 + 1];   // �ռ������ο����ʸ�������
  char          szNightSaleRiseRate[21 + 1]; // ҹ�������ο����ʸ�������
  char          szMidRate[21 + 1];           // �м�ο�����
  char          szBuySettRate[21 + 1];       // ����������
  int           iUpdDate;                    // ��������
  char          szRemark[256 + 1];           // ��ע
};

//-------------------------------10301057:�۹�ͨ�г�״̬��Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryMktStatusInfoField
{
  char          szStkbd[2 + 1];              // ���װ��
};

struct MATRADEAPI CRspStkQryMktStatusInfoField
{
  char          chStkex;                     // �����г�
  char          szStkbd[2 + 1];              // ���װ��
  char          szThresholdQuota[21 + 1];    // ÿ�ճ�ʼ���
  char          szPosQuota[21 + 1];          // ����ʣ����
  char          chQuotaStatus;               // ���״̬
  char          chMktTrdStatus;              // �г�����״̬
  int           iUpdDate;                    // ��������
  char          szRemark[128 + 1];           // ��ע
};

//-------------------------------10301059:�۹�ͨ���֤ȯ״̬��ѯ------------------------------------
struct MATRADEAPI CReqStkQryUndlStkStatusField
{
  char          szStkbd[2 + 1];              // ���װ��
  char          szStkCode[8 + 1];            // ֤ȯ����
  char          chObjectFlag;                // ��ı�־
};

struct MATRADEAPI CRspStkQryUndlStkStatusField
{
  char          chStkex;                     // ֤ȯ������
  char          szStkbd[2 + 1];              // ���װ��
  char          szStkCode[8 + 1];            // ֤ȯ����
  char          chLotTrdStatus;              // ���ֽ���״̬
  char          chOddTrdStatus;              // ��ɽ���״̬
  char          chObjectFlag;                // ��ı�־
  int           iUpdDate;                    // ��������
  char          szRemark[256 + 1];           // ��ע
};

//-------------------------------10303027:�۹�ͨ�����ʽ�̨�˲�ѯ------------------------------------
struct MATRADEAPI CReqStkQryFundAcctLvlTwoField
{
  LONGLONG      llCuacctCode;                // �ʲ��˻�
  char          chCurrency;                  // ���Ҵ���
};

struct MATRADEAPI CRspStkQryFundAcctLvlTwoField
{
  LONGLONG      llCuacctCode;                // �ʲ��˻�
  char          chCurrency;                  // ���Ҵ���
  char          szFundDetailCls[2 + 1];      // �ʽ���ϸ����
  int           iDlvyCycle;                  // ��������
  char          szFundBln[21 + 1];           // �ʽ����
  char          szFundAvl[21 + 1];           // �ʽ���ý��
  char          szFundFrz[21 + 1];           // �ʽ𶳽���
  char          szFundUfz[21 + 1];           // �ʽ�ⶳ���
  char          szFundTrdFrz[21 + 1];        // �ʽ��׶�����
  char          szFundTrdUfz[21 + 1];        // �ʽ��׽ⶳ���
  char          szFundTrdOtd[21 + 1];        // �ʽ�����;���
  char          szFundTrdBln[21 + 1];        // �ʽ���������
  char          szFundBorrowBln[21 + 1];     // �ڲ��������
};

//-------------------------------10301055:�۹�ͨ������С�۲��ѯ------------------------------------
struct MATRADEAPI CReqStkQryTradeMinSpreadField
{
  char          szStkbd[2 + 1];              // ���װ��
  char          chStkCls;                    // ֤ȯ���
  char          szPrice[21 + 1];             // �۸�
};

struct MATRADEAPI CRspStkQryTradeMinSpreadField
{
  char          chStkex;                     // �����г�
  char          szStkbd[2 + 1];              // ���װ��
  char          chStkCls;                    // ֤ȯ���
  char          szBgnPrice[21 + 1];          // �۸�����
  char          szEndPrice[21 + 1];          // �۸�����
  char          szStkSpread[21 + 1];         // �۲��λ��
  char          szMinBgnPrice[21 + 1];       // ��ͼ۸�����
  char          szMaxEndPrice[21 + 1];       // ��߼۸�����
  int           iPriceUnitNum;               // �۲�����
};

//-------------------------------10303024:�ع���Լ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryRepchContractField
{
  LONGLONG      llCuacctCode;                // �ʲ��˻�
  LONGLONG      llCustCode;                  // �ͻ�����
  char          chFlag;                      // ��ѯ��־
  char          szOrderId[10 + 1];           // ��ͬ���
  int           iRepchDate;                  // �ع�����
  int           iIntOrg;                     // �ڲ�����
  char          szStkbd[2 + 1];              // ���װ��
  char          szTrdacct[20 + 1];           // �����˻�
  char          szStkCode[8 + 1];            // ֤ȯ����
  char          chDateType;                  // ��������
  int           iBgnDate;                    // ��ʼ����
  int           iEndDate;                    // ��������
  char          szQueryPos[32 + 1];          // ��λ��
  int           iQueryNum;                   // ��ѯ����
  char          chQueryFlag;                 // ��ѯ����
};

struct MATRADEAPI CRspStkQryRepchContractField
{
  int           iRepchDate;                  // ��������
  int           iTrdDate;                    // ��������
  LONGLONG      llCuacctCode;                // �ʲ��˻�
  char          chStkex;                     // �����г�
  char          szStkbd[2 + 1];              // ���װ��
  char          szOrderId[10 + 1];           // ��ͬ���
  LONGLONG      llCustCode;                  // �ͻ�����
  char          chCurrency;                  // ���Ҵ���
  char          szTrdacct[20 + 1];           // �����˻�
  char          szStkCode[8 + 1];            // ֤ȯ����
  char          szStkName[64 + 1];           // ֤ȯ����
  int           iStkBiz;                     // ֤ȯҵ��
  int           iStkBizAction;               // ҵ����Ϊ
  char          szOrderPrice[21 + 1];        // ί�м۸�
  char          szMatchedPrice[21 + 1];      // �ɽ��۸�
  LONGLONG      llRepchQty;                  // �ع�����
  char          szRepchAmt[21 + 1];          // ���ڽ��
  char          szQryPos[32 + 1];            // ��λ��
  int           iIntOrg;                     // �ڲ�����
  char          szCustName[32 + 1];          // �ͻ�����
  char          chStkCls;                    // ֤ȯ���
  LONGLONG      llOrderQty;                  // ί������
  LONGLONG      llMatchQty;                  // �ɽ�����
  char          szMatchAmt[21 + 1];          // �ɽ����
  char          szStkpbu[8 + 1];             // ���׵�Ԫ
  char          szMatchId[32 + 1];           // �ɽ����
  char          chStkTrdExtcls;              // ���׷�ʽ����
  char          chMpOrdertype;               // �м�ί������
  char          chRepchStatus;               // �ع�״̬
  char          chChannel;                   // ��������
  int           iActualUsedDays;             // ʵ��ռ������
};

//-------------------------------10304112:�ͻ��ʵ��Բ�ѯ------------------------------------
struct MATRADEAPI CReqStkQryCustAppropriateField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
};

struct MATRADEAPI CRspStkQryCustAppropriateField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  char          chProfInvestorType;           // רҵͶ���߷���
  int           iProfExpDate;                 // רҵͶ���ߵ�������
  char          chInvestLmt;                  // Ͷ������
  char          szInvestPro[32 + 1];          // Ͷ��Ʒ��
  char          chExpectIncome;               // Ԥ������
  char          chCustLastriskFlag;           // ��Ϳͻ���������ʾ
  char          chCustRiskLevel;              // �ͻ����յȼ�
  int           iCustRiskLevelDate;           // ���յȼ���Ч��
};

//-------------------------------10301147:��Ʒ�ʵ��Բ�ѯ------------------------------------
struct MATRADEAPI CReqStkQryProdAppropriateField
{
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          chStkex;                      // �����г�
  int           iStkBiz;                      // ֤ȯҵ��
  char          chQueryFlag;				  // ��ѯ����
  char          szQueryPos[32 + 1];		      // ��λ��
  int           iQueryNum;					  // ��ѯ����
};

struct MATRADEAPI CRspStkQryProdAppropriateField
{
  char			szQueryPos[32 + 1];			  // ��λ��
  char          chStkex;                      // ֤ȯ������
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          chStkRiskLevel;               // ��Ʒ���յȼ�
  char          chInvestPeriod ;              // Ͷ������
  char          szInvestType[2 + 1];          // Ͷ��Ʒ��
  char          chExincomeType;               // Ԥ������
  int           iStkBiz;                      // ֤ȯҵ��
  char          chElectContFlag;              // �Ƿ���ҪETF���Ӻ�ͬ 0-�� 1-��
};

//-------------------------------10301467:�ʵ���ƥ����------------------------------------
struct MATRADEAPI CReqStkAppropriateCheckField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  char          chRiskNoFlag;                 // ���ռ�¼��־
};

struct MATRADEAPI CRspStkAppropriateCheckField
{
  LONGLONG      llPropRiskNo;                 // �ʵ�����ˮ��
  LONGLONG      llCustCode;                   // �ͻ�����
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  char          chCheckResult;                // �ʵ���ƥ����
  char          chCustRiskLevel;              // �ͻ����յȼ�
  char          chCustInvestLmt;              // �ͻ�Ͷ������
  char          szCustInvestPro[128 + 1];     // �ͻ�Ͷ��Ʒ��
  char          chCustExpectIncome;           // �ͻ�Ԥ������
  char          chStkRiskLevel;               // ��Ʒ���յȼ�
  char          chStkInvestPeriod;            // ��ƷͶ������
  char          szStkInvestType[2 + 1];       // ��ƷͶ��Ʒ��
  char          chStkExincomeType;            // ��ƷԤ������
  char          chRiskLevelFitFlag;           // ���յȼ�ƥ����
  char          chInvestPeriodFitFlag;        // Ͷ������ƥ����
  char          chInvestTypeFitFlag;          // Ͷ��Ʒ��ƥ����
  char          chExincomeTypeFitFlag;        // Ԥ������ƥ����
  char          szCheckDesc[512 + 1];         // У��������
  char          chCustLastriskFlag;           // ��Ϳͻ���������ʾ
  int           iCustRiskLevelDate;           // ���յȼ���Ч��
};

//-------------------------------10301468:�ʵ���ƥ������¼------------------------------------
struct MATRADEAPI CReqStkAppropriateResultField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  char          szConfirmType[64 + 1];        // ȷ�����
  LONGLONG      llPropRiskNo;                 // �ʵ�����ˮ��
};

struct MATRADEAPI CRspStkAppropriateResultField
{
  LONGLONG      llPropRiskNo;                 // �ʵ�����ˮ��
};

//-------------------------------10303095:�ع��ʽ�ռ��������ѯ------------------------------------
struct MATRADEAPI CReqStkQryRepchFundField
{
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iTrdDate;                     // ��������
};

struct MATRADEAPI CRspStkQryRepchFundField
{
  int           iBeginUsedDate;               // ��ʼռ������
  int           iUsedDate;                    // ռ������
  int           iRepchDate;                   // ��������
};

//-------------------------------10301079:��֤LOF��Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqStkQryScLofInfoField
{
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkLofCode[8 + 1];          // ��֤LOF����
};

struct MATRADEAPI CRspStkQryScLofInfoField
{
  char          chStkex;                      // ֤ȯ������
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkLofCode[8 + 1];          // ��֤LOF����
  char          szStkLofName[10 + 1];         // ��֤LOF����
  char          szStkLofStatusSh[8 + 1];      // ��֤LOF״̬
  int           iStkLofRatio;                 // ����ת��ϵ��
  char          chStkLofType;                 // ��������
  char          chStkLofSubType;              // ����������
  LONGLONG      llStkLofPmUnit;               // ��ֺϲ���λ
  LONGLONG      llStkLofMergeFloor;           // ��С�ϲ���
  LONGLONG      llStkLofPartitionFloor;       // ��С�����
  char          szStkLofMainCode[8 + 1];      // ĸ�������
  char          szStkLofMainName[10 + 1];     // ĸ��������
  int           iStkLofMainRatio;             // ĸ�ݶ�ת��ϵ��
  char          szStkLofMainStatus[8 + 1];    // ĸ����״̬
};

//-------------------------------10303028:��ʷί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryHisOrderField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  int             iIntOrg;                    // �ڲ�����
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������ (��ǰ֧��0������ֵ������չ��)
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  int             iBgnDate;                   // ��ʼ����
  int             iEndDate;                   // ��������
};

struct MATRADEAPI CRspStkQryHisOrderField
{
  int             iIntOrg;                    // �ڲ�����
  int             iTrdDate;                   // ��������
  int             iOrderDate;                 // ί������
  char            szOrderId[10 + 1];          // ��ͬ���
  char            chOrderStatus;              // ί��״̬ �ֵ�[ORDER_STATUS]
  char            chOrderValidFlag;           // ί����Ч��־ �ֵ�[ORDER_VALID_FLAG]
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ί�ж�����
  char            szOrderUfzAmt[21 + 1];      // ί�нⶳ���
  LONGLONG        llOfferQty;                 // �걨����
  char            szOfferStime[32 + 1];       // �걨ʱ��
  LONGLONG        llWithdrawnQty;             // �ѳ�������
  LONGLONG        llMatchedQty;               // �ѳɽ�����
  char            chIsWithdraw;               // ������־ �ֵ�[IS_WITHDRAW]
  char            chIsWithdrawn;              // �ѳ�����־ �ֵ�[IS_WITHDRAWN]
  int             iOrderBsn;                  // ί������
  char            szQryPos[32 + 1];           // ��λ����ѯ
  char            szOrderTime[32 + 1];        // ί��ʱ��
  char            szMatchedAmt[21 + 1];       // �ѳɽ����
};

//-------------------------------10303029:��ʷ�ɽ���ѯ--------------------------
struct MATRADEAPI CReqStkQryHisFillField
{
  LONGLONG        llCustCode;                 // �ͻ����� ����ͬʱΪ�� ������Ϊ��ʱ���ͻ�������Ϊ��Ч����
  int             iIntOrg;                    // �ڲ�����
  char            chQueryFlag;                // ��ѯ���� ��0��:���ȡ���� ��1��:��ǰȡ���� ����ȫ������ (��ǰ֧��0������ֵ������չ��)
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  int             iBgnDate;                   // ��ʼ����
  int             iEndDate;                   // ��������
};

struct MATRADEAPI CRspStkQryHisFillField
{
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ��
  int             iOrderDate;                 // ί������
  int             iOrderSn;                   // ί�����
  int             iOrderBsn;                  // ί������
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iIntOrg;                    // �ڲ�����
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ֤ȯҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ί�ж�����
  char            szMatchedSn[32 + 1];        // �ɽ����
  char            szMatchedPrice[21 + 1];     // �ɽ��۸�
  LONGLONG        llMatchedQty;               // �ѳɽ�����
  char            szMatchedAmt[21 + 1];       // �ѳɽ����
  char            szQryPos[32 + 1];           // ��λ����ѯ
};

//-------------------------------10303019:����/��ʷί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryCurrDayHisOrderField
{
  int             iBgnDate;                   // ��ʼ����
  int             iEndDate;                   // ��������
  LONGLONG        llCustCode;                 // �ͻ����� �����ͬʱΪ��
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iOrderBsn;                  // ί������
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ�� ��ӦΪί�б��С�QUERY_POS��
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
  int             iCuacctSn;                  // �˻����
  char            chOrderMode;                // ί��ģʽ 0-����ί�У�1-�ɳ�ί�У�2-�Ƿ�ί�У�3-�Ϸ�ί��
};

struct MATRADEAPI CRspStkQryCurrDayHisOrderField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  int             iIntOrg;                    // �ڲ�����
  int             iTrdDate;                   // ��������
  int             iOrderDate;                 // ί������
  char            szOrderTime[32 + 1];        // ί��ʱ��
  char            szOrderId[10 + 1];          // ��ͬ���
  char            chOrderStatus;              // ί��״̬ �ֵ�[ORDER_STATUS]
  char            chOrderValidFlag;           // ί����Ч��־ �ֵ�[ORDER_VALID_FLAG]
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szBondInt[21 + 1];          // ծȯ��Ϣ
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ί�ж�����
  char            szOrderUfzAmt[21 + 1];      // ί�нⶳ���
  LONGLONG        llOfferQty;                 // �걨����
  int             iOfferStime;                // �걨ʱ��
  LONGLONG        llWithdrawnQty;             // �ѳ�������
  LONGLONG        llMatchedQty;               // �ѳɽ�����
  char            chIsWithdraw;               // ������־ �ֵ�[IS_WITHDRAW]
  char            chIsWithdrawn;              // �ѳ�����־ �ֵ�[IS_WITHDRAWN]
  int             iOrderBsn;                  // ί������
  char            szMatchedAmt[21 + 1];       // �ɽ����
  int             iCuacctSn;                  // �˻����
  char            szRawOrderId[10 + 1];       // ԭ��ͬ��� ����ί��ʱ��Ч��ָ��������ί��
  char            szOfferRetMsg[64 + 1];      // �걨������Ϣ
};

//-------------------------------10303020:����/��ʷ�ɽ���ѯ--------------------------
struct MATRADEAPI CReqStkQryCurrDayHisFillField
{
  int             iBgnDate;                   // ��ʼ����
  int             iEndDate;                   // ��������
  LONGLONG        llCustCode;                 // �ͻ����� �ͻ��������ʲ��˻������ͬʱΪ��
  LONGLONG        llCuacctCode;               // �ʲ��˻� �ͻ��������ʲ��˻������ͬʱΪ��
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iOrderBsn;                  // ί������
  char            chQueryFlag;                // ��ѯ���� ��0��:���ȡ���� ��1��:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ�� ��ӦΪ�ɽ����С�QUERY_POS��
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
  int             iCuacctSn;                  // �˻����
};

struct MATRADEAPI CRspStkQryCurrDayHisFillField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ��
  int             iOrderDate;                 // ί������
  int             iOrderSn;                   // ί�����
  int             iOrderBsn;                  // ί������
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iIntOrg;                    // �ڲ�����
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ֤ȯҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szBondInt[21 + 1];          // ծȯ��Ϣ
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ί�ж�����
  char            szMatchedSn[32 + 1];        // �ɽ����
  char            szMatchedPrice[21 + 1];     // �ɽ��۸�
  char            szMatchedQty[21 + 1];       // �ѳɽ�����
  char            szMatchedAmt[21 + 1];       // �ѳɽ����
  char            chIsWithdraw;               // ������־ �ֵ�[IS_WITHDRAW]
  char            chMatchedType;              // �ɽ����� ��0��:δ�걨�����ɽ� ��1��:�Ƿ�ί�г����ɽ� ��2��:�������ɽ�
  char            szStkTrdacct[20 + 1];       // ֤ȯ�˻�
  int             iCuacctSn;                  // �˻����
};

//-------------------------------10303008:��Ѻ�ɷ���ϸ��ѯ(���ͻ�)--------------------------
struct MATRADEAPI CReqStkQryPledgeSharesField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            chQueryFlag;                // ��ѯ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
};

struct MATRADEAPI CRspStkQryPledgeSharesField
{
  int             iIntOrg;                    // �ڲ�����
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szQryPos[32 + 1];           // ��λ��
  char            chStkCls;                   // ֤ȯ��� �ֵ�[STK_CLS]
  LONGLONG        llStkPrebln;                // ֤ȯ�������
  LONGLONG        llStkBln;                   // ֤ȯ���
  LONGLONG        llStkAvl;                   // ֤ȯ��������
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szBondCvtrate[21 + 1];      // ծȯ������
  LONGLONG        llStkStdAvl;                // ��׼ȯ����
};

//-------------------------------10309005:�ʽ���ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryFundFlowField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻� �ʽ��˻���ͻ����벻��ͬʱΪ��
  LONGLONG        llCustCode;                 // �ͻ����� �ʽ��˻���ͻ����벻��ͬʱΪ��
  char            szIntOrg[256 + 1];          // �ڲ�����
  int             iBizCodes;                  // ҵ����� 1:�������� 2:�������� 3:��Ϣ�������� 4:�ʽ����� 5:�ʽ𶳽�
  char            chQueryFlag;                // ��ѯ���� '0':���ȡ���� '1':��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  int             iTrdDate;                   // ��������
  char            chReverseStatus;            // ����״̬
  LONGLONG        llSerialNo;                 // ��ˮ���
  char            szTransStatuses[8 + 1];     // ת��״̬ '0':�Ѿ����� '1':ת�ʳɹ� '2':��֤ת��ʧ�� '3':��ʱ ��������
};

struct MATRADEAPI CRspStkQryFundFlowField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  LONGLONG        llSerialNo;                 // ��ˮ���
  int             iTrdDate;                   // ��������
  char            szSyncTime[32 + 1];         // ����ʱ��
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  int             iIntOrg;                    // �ڲ�����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  int             iBizCodes;                  // ҵ����� 1:�������� 2:�������� 3:��Ϣ�������� 4:�ʽ����� 5:�ʽ𶳽�
  char            szBizContext[128 + 1];      // ҵ������
  LONGLONG        llBizSn;                    // ������ˮ��
  char            szFundAvl[21 + 1];          // �ʽ���ý��
  char            szFundBlnEffect[21 + 1];    // �ʽ����仯
  char            szFundAvlEffect[21 + 1];    // �ʽ���ñ仯
  char            szFundFrzEffect[21 + 1];    // �ʽ𶳽�仯
  char            szFundUfzEffect[21 + 1];    // �ʽ�ⶳ�仯
  char            chReverseStatus;            // ����״̬ '1':�ѳ���
  char            chTransStatus;              // ת��״̬ '0':�Ѿ����� ��ʼ״̬����ʾ�����Ѿ��ɹ����ü��н��׵���֤ת��ӿڡ� '1':ת�ʳɹ� ת�˹��̽����� '2':��֤ת��ʧ�� ������֤ת��ӿ�ʧ�ܡ� '3':��ʱ ��ȡת�˽����ʱ
};

//-------------------------------10301105:�û���¼------------------------------------
struct MATRADEAPI CReqStkUserLoginField
{
  char          szAcctType[2 + 1];            // �˻�����
  char          szAcctId[32 + 1];             // �˻���ʶ
  char          chUseScope;                   // ʹ�÷�Χ
  char          szEncryptKey[32 + 1];         // ��������
  char          chAuthType;                   // ��֤����
  char          szAuthData[256 + 1];          // ��֤����
  char          szThirdParty[1024 + 1];       // ������
  char          chEncryptType;                // ���ܷ�ʽ ��0��:��֤KBSSϵͳ���� ��1��:��֤Win�漯�н��׼��� ��2��:��֤Unix�漯�н��׼���
  char          chChannel;                    // ��������
  char          szSerChannel[8 + 1];          // ��������
  char          chPasswordType;               // �������ͣ�'0'-���ģ�'1'-���ģ����û������ֵĬ�ϱ�ʾ����
};

struct MATRADEAPI CRspStkUserLoginField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chStkex;                      // �����г�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkTrdacct[20 + 1];         // ֤ȯ�˻�
  int           iTrdacctSn;                   // �˻����
  char          szTrdacctExid[20 + 1];        // �����˻�
  char          chTrdacctStatus;              // �˻�״̬
  char          chTregStatus;                 // ָ��״̬
  char          chBregStatus;                 // �ع�״̬
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szAcctType[2 + 1];            // �˻�����
  char          szAcctId[32 + 1];             // �˻���ʶ
  char          szTrdacctName[128 + 1];        // �����˻�����
  char          szSessionId[256 + 1];         // �Ựƾ֤
  int           iIntOrg;                      // �ڲ�����
  char          chCuacctAttr;                 // �ʲ��˻�����
  int           iFlashPort;                   // �����ٶ˿ں�
  char          szFlashStkBizes[64 + 1];      // ������ҵ��
  char          chSzFlashMode;                // �����������г�����ģʽ ��0��-������ ��1��-�������� ��2��-FPGA����
  char          chShFlashMode;                // �������Ϻ��г�����ģʽ ��0��-������ ��1��-�������� ��2��-FPGA����
  char          chFlashEnableFlag;            // �������ñ�־ ��0��-δ���� ��1��-������
  char          chTrdacctExcls;               // �����˻���� '0' -- �����˻���'1' -- �����˻���'2' -- ���������˻���'3' -- ���������˻�
  char          szThirdParty[1024 + 1];       // ������
  char          chTrdacctMainFlag;            // ���ɶ��˻���־ ��0��- ���ɶ��˻�  ��1��- ���ɶ��˻�
  char          chCuacctSyncFlag;             // ���˻���ڵ��־ ��0��-�ǵ��˻���ڵ㣬��1��-���˻���ڵ�
  char          szFlashIp[64 + 1];            // �����ٵ�ַ
};

//-------------------------------10360500:ת������ҵ����Ϣ------------------------------------
struct MATRADEAPI CReqStkBankTransBasicInfoField
{
  char chCurrency;    //���Ҵ���  9080
  char szBankCode[4+1]; //���д���  15
};
struct MATRADEAPI CRspStkBankTransBasicInfoField
{
  char szBankCode[4+1];        // ���д���  BANK_CODE VARCHAR(4)  9080
  char chSourceType;           // ����    SOURCE_TYPE CHAR(1) 9108
  char chBankTranType;         // ת�ʷ�ʽ  BANK_TRAN_TYPE  CHAR(1) 9109
  char chFundPwdFlag;          // �ʽ�����У��  FUND_PWD_FLAG CHAR(1) 9081
  char chBankPwdFlag;          // ��������У��  BANK_PWD_FLAG CHAR(1) 9082
  char chCheckBankId;          // �����ʺ�У��  CHECK_BANK_ID CHAR(1) 9083
  char chCheckIdNo;          // ֤��У���־  CHECK_ID_NO CHAR(1) 9084
  int  iIntOrg;            // ��������  INT_ORG SMALLINT  8821
  char chCurrency;           // ���Ҵ���  CURRENCY  CHAR(1) 9085
  char chStatus;             // ����״̬  STATUS  CHAR(1) 9086
};

//-------------------------------10305036:��֤ת��------------------------------------
struct MATRADEAPI CReqStkBankStkTransField
{
  LONGLONG llCuacctCode;      //�ʽ��˺�  CUACCT_CODE     SMALLINT  ��  8920
  char  chCurrency;       //���Ҵ���  CURRENCY      CHAR(1)   ��  15
  char  szFundPwd[32+1];      //�ʽ�����  FUND_PWD      VARCHAR(32) X 9100
  char  szBankCode[4+1];      //���д���  BANK_CODE     VARCHAR(4)  ��  9101
  char  szBankPwd[32+1];      //��������  BANK_PWD      CHAR(32)  X 9102
  char  chBankTranType;     //ת������  BANK_TRAN_TYPE    CHAR(1)   ��  9103
  char  szTransAmt[21+1];     //ת�ʽ��  TRANS_AMT     CMONEY    ��  9104
  char  chPwdFlag;          //�ʽ�����У���־  PWD_FLAG  CHAR(1)   X 9105
  //char szExtsNo[32+1];      //�ⲿ��ˮ��  EXTS_NO       VARCHAR(32) X 9106
  //char          szTrdPwd[32 + 1];             // ��������2015-11-26���� 2016-1-15 ȥ��

};
struct MATRADEAPI CRspStkBankStkTransField
{
  int  iSNo;        //ί�����  S_NO      SMALLINT  9107
  int  iSysErrorId;   //�������  SYS_ERROR_ID  SMALLINT  9108
  char szErrorMsg[64+1];  //������Ϣ  ERROR_MSG VAARCHAR(64)  9109
};

//-------------------------------10101502:��ѯ�˻����--------------------------------
struct MATRADEAPI CReqStkFundBalaField
{
  LONGLONG      llCuacctCode;                 // �ʽ��˺�     8920
  char          chCurrency;         // ���Ҵ���     15
  char          szFundPwd[32 + 1];            // �ʽ�����     9100
  char          szBankCode[4 + 1];            // ���д���     9101
  char          szBankPwd[32 + 1];            // ��������     9102
  //char          szTrdPwd[32 + 1];             // ��������2015-11-26���� 2016-1-15 ȥ��
};
struct MATRADEAPI CRspStkFundBalaField
{
  int           iSNo;                        // ί�����      9107
  char          szErrorMsg[64 + 1];           // ������Ϣ     9108
  int           iSysErrId;                   // �������      9109
  LONGLONG      llFundEffect;                 // �������     9110
};

//-------------------------------10101503:��֤ת�˲�ѯ------------------------------------
struct MATRADEAPI CReqStkBankStkTransInfoField
{
  LONGLONG      llCuacctCode;          // �ʽ��˺�     8920
  char          chCurrency;            // ���Ҵ���   15
  char          szSNo[32 + 1];         // ת�����   9100
};
struct MATRADEAPI CRspStkBankStkTransInfoField
{
  int           iOperDate;                    // ת������      9100
  int           iOperTime;                    // ת��ʱ��      9101
  LONGLONG      llCuacctCode;                 // �ʽ��˺�      8920
  char          chCurrency;                   // ���Ҵ���      15
  LONGLONG      llCustCode;                   // �ͻ�����      8902
  char          szBankCode[4 + 1];            // ���д���      9102
  char          chBankTranId;                 // ҵ������      9103
  int           iSNo;                         // ��ͬ���      9104
  LONGLONG      llFundEffect;                 // ί�н��      9105
  LONGLONG      llFundBal;                    // ���        9106
  char          szRemark[32 + 1];             // ��ע��Ϣ      9107
  char          chStatus;                     // �������      9108
  char          chSourceType;                 // ������      9109
  char          szBankMsgId[16 + 1];          // �ⲿ��Ϣ����    9110
  char          szBankMsg[64 + 1];            // �ⲿ��Ϣ����    9111
  char          szErrorMsg[64 + 1];           // ϵͳ������Ϣ    9112
  int           iSysErrId;                    // ϵͳ�������    9113
  char          szFundEffect[23 + 1];         // ί�н��       9105
  char          szFundBal[23 + 1];            // ���           9106
};

//-------------------------------10101504:�޸Ľ�������------------------------------------
struct MATRADEAPI CReqStkChgTrdPwdField
{
  char          szNewPwd[32 + 1];             // ������ 9100
};
struct MATRADEAPI CRspStkChgTrdPwdField
{
  char          szMsgOk[32 + 1];              // �ɹ���Ϣ 9101
  char          szCustCert[128 + 1];          // �ͻ�֤�� 9102
};

//-------------------------------10101505:�޸��ʽ�����------------------------------------
struct MATRADEAPI CReqStkChgFundPwdField
{
  LONGLONG      llCuacctCode;                 // �ʽ��ʻ�     8920
  char          szOldFundPwd[32 + 1];         // ���ʽ�����  9100
  char          szNewFundPwd[32 + 1];         // ���ʽ�����  9101
};
struct MATRADEAPI CRspStkChgFundPwdField
{
  char          szMsgOk[32 + 1];              // �ɹ���Ϣ   9101
};

//-------------------------------10101506:���ʵ���ѯ------------------------------------
struct MATRADEAPI CReqStkStatementField
{
  int          iStrDate;                     // ��ʼ����      9100
  int          iEndDate;                     // ��ֹ����      9101
  LONGLONG     llCuacctCode;                 // �ʽ��ʻ�      8920
  char         chCurrency;                   // ���Ҵ���      15
  char         chPrintFlag;                  // �ش��ʶ      9102
  char         chQryFlag;                    // ��ѯ����      9080
  int          iQryNum;                      // ��������      8992
  char         szQryPos[32 + 1];             // ��λ��        8991
};
struct MATRADEAPI CRspStkStatementField
{
  char         szQryPos[32 + 1];             // ��λ��         8991
  int          iClearDate;                   // ��������       8992
  int          iBizDate;                     // ��������       9103
  int          iOrderDate;                   // ��������       9104
  int          iOrderTime;                   // ����ʱ��       9105
  int          iDigestId;                    // ҵ�����       9106
  char         szDigestName[16 + 1];         // ҵ��˵��       9107
  LONGLONG     llCustId;                     // �ͻ�����       8902
  char         szCustName[16 + 1];           // �ͻ�����       8910
  char         szIntOrg[4 + 1];              // ��������       8911
  LONGLONG     llCuacctCode;                 // �ʽ��ʺ�       8920
  char         chCurrency;                   // ���Ҵ���       15
  char         chStkex;                      // �г�����       207
  char         szTrdacct[20 + 1];            // �ɶ�����       8927
  int          iStkBal;                      // �ɷݱ������   9110
  char         szOrderId[10 + 1];            // ��ͬ���       11
  char         szStkCode[16 + 1];            // ֤ȯ����       48
  char         szStkName[64 + 1];            // ֤ȯ����       55
  char         szBsFlag[2 + 1];              // �������       9111
  int          iMatchedQty;                  // �ɽ�����       387
  char         szFundEffect[21 + 1];         // �ʽ�����     9108
  char         szFundBal[21 + 1];            // �ʽ𱾴����   9109
  char         szMatchedPrice[21 + 1];       // �ɽ��۸�       8841
  char         szMatchedAmt[21 + 1];         // �ɽ����       8504
};

//-------------------------------10101507:�ʽ𻮲�--------------------------
struct MATRADEAPI CReqStkFundTransferField
{
  char         szOrgId[4 + 1];               // ��������
  LONGLONG     llCuacctCode;                 // �ʽ��˺�
  char         chCurrency;                   // ���Ҵ���
  char         szFundAvl[21 + 1];            // �ʽ����
  char         chDirect;                     // ��������
};
struct MATRADEAPI CRspStkFundTransferField
{
  int          iSNo;                         // ������ˮ��
  int          iVipSno;                      // VIP������ˮ��
};
//-------------------------------10101509:��ʷί����ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHistoryOrderDetailField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iOrdergroup;       // ί������
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
    char          chQryoperway;      // ί������
};
struct MATRADEAPI CRspStkQryRpcHistoryOrderDetailField
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iOrderdate;            // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMoneytype;           // ����
    char          szOrgid[4 + 1];        // ��������
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[10 + 1];     // �걨��ͬ���
    int           iOrdergroup;           // ί������
    int           iReporttime;           // ����ʱ��
    int           iOpertime;             // ί��ʱ��
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szProdcode[12 + 1];    // ��Ʒ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    char          szOrderfrzamt[21 + 1]; // ������
    int           iMatchqty;             // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iCancelqty;            // ��������
    char          chCancelflag;          // ������־
    char          chOrderstatus;         // ί��״̬
    char          szSeat[6 + 1];         // ����ϯλ
    char          szMatchprice[21 + 1];  // �ɽ��۸�
    int           iOperdate;             // ��������
    char          szBondintr[21 + 1];    // ծȯӦ����Ϣ
    char          chOperway;             // ί������
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
//-------------------------------10101510:��ʷ�ɽ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHistoryMatchDetailField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHistoryMatchDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iBizdate;             // ��������
    int           iCleardate;           // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    char          szOrderid[10 + 1];    // �걨��ͬ���
    int           iOrdersno;            // ί�����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];   // ��Ʒ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iStkbal;              // �ɷݱ������
    char          szFeeJsxf[21 + 1];    // ��������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFeeQtf[21 + 1];     // ������
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFundeffect[21 + 1]; // �ʽ�����
    char          szFundbal[21 + 1];    // ʹ�ý��
    char          szBondintr[21 + 1];   // ծȯӦ����Ϣ
};
//-------------------------------10101511:�����¹��嵥��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcIPOField
{
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // �깺����
    int           iIssuedate;       // �깺����
};
struct MATRADEAPI CRspStkQryRpcIPOField
{
    char          chMarket;           // �����г�
    char          szStkcode[8 + 1];   // �깺����
    char          szStkname[64 + 1];  // �깺��������
    char          szLinkstk[8 + 1];   // ���ɴ���
    char          chIssuetype;        // ���з�ʽ
    int           iIssuedate;         // �깺����
    char          szFixprice[21 + 1]; // �깺�۸�
    int           iBuyunit;           // �깺��λ
    int           iMinqty;            // �깺��С����
    int           iMaxqty;            // �깺�������
};
//-------------------------------10101512:��Χ�¹��깺��ֵ��ȱ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcIPOSubscriptionLimitField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szOrgid[4 + 1];   // ��������
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcIPOSubscriptionLimitField
{
    char          szPosstr[64 + 1]; // ��λ��
    int           iServerid;        // �ڵ���
    int           iDbfrec;          // ���
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // ��������
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llCustquota;      // �ͻ���ֵ���
    LONGLONG      llKcCustquota;    // �ƴ����깺���
    int           iReceivedate;     // ��������
    char          szRemark[32 + 1]; // ��ע
};
//-------------------------------10101513:��Ų�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcDistributionField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSecuid[10 + 1];  // �ɶ�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcDistributionField
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iBizdate;              // �������
    char          chMarket;              // �����г�
    char          szSecuid[32 + 1];      // �ɶ�����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[16 + 1];     // ֤ȯ����
    int           iMatchqty;             // �������
    char          szMateno[32 + 1];      // �깺���
    char          szOrderid[10 + 1];     // ί�к�
    int           iOrderdate;            // ί������
    char          szMateerrmsg[128 + 1]; // ��ע
};
//-------------------------------10101514:��ֵ������ǩ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcMktCapPlacingField
{
    char          szSecuid[10 + 1]; // �ɶ�����
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chIssuetype;      // ���з�ʽ
};
struct MATRADEAPI CRspStkQryRpcMktCapPlacingField
{
    LONGLONG      llCustid;             // �ͻ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    int           iOrderdate;           // ί������
    int           iMatchdate;           // ��ǩ����
    int           iHitqty;              // ��ǩ����
    int           iGiveupqty;           // ��������
    char          szMatchprice[21 + 1]; // �۸�
    char          szHitamt[21 + 1];     // ��ǩ���
    int           iPayqty;              // �ѽɿ�����
    char          szPayamt[21 + 1];     // �ѽɿ���
    char          szFrzamt[21 + 1];     // Ԥ������
    int           iClearsno;            // ����˳��
    char          chIssuetype;          // ���з�ʽ
    char          chStatus;             // ����״̬
};
//-------------------------------10101515:��ǩ��ʷ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcWinningHistoryField
{
    char          szSecuid[10 + 1];  // �ɶ�����
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chIssuetype;       // ���з�ʽ
    int           iBegindate;        // ��ǩ��ʼ����
    int           iEnddate;          // ��ǩ��������
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcWinningHistoryField
{
    char          szPoststr[32 + 1];    // ��λ��
    LONGLONG      llCustid;             // �ͻ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    int           iOrderdate;           // ί������
    int           iOrdersno;            // ί�����
    int           iMatchdate;           // ��ǩ����
    int           iHitqty;              // ��ǩ����
    int           iGiveupqty;           // ��������
    char          szMatchprice[21 + 1]; // �۸�
    char          szHitamt[21 + 1];     // ��ǩ���
    int           iPayqty;              // �ѽɿ�����
    char          szPayamt[21 + 1];     // �ѽɿ���
    int           iClearsno;            // ����˳��
    char          chIssuetype;          // ���з�ʽ
    char          chStatus;             // ����״̬
};
//-------------------------------10101516:��ֵ���۽���˳���޸�--------------------------
struct MATRADEAPI CReqStkRpcChgMktCapDistDeliOrderField
{
    int           iMatchdate;       // ��ǩ����
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iClearsno;        // ����˳��
};
struct MATRADEAPI CRspStkRpcChgMktCapDistDeliOrderField
{
    int           iSerialno; // ������ˮ��
};
//-------------------------------10101517:�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcDeliOrderField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcDeliOrderField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ί������
    int           iOrdertime;           // ί��ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ�����˵��
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // ����������
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ�����
    int           iMatchtimes;          // �ɽ�����
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szFundeffect[21 + 1]; // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeJsxf[21 + 1];    // ��׼������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          chSourcetype;         // ����
    char          szBankcode[4 + 1];    // �ⲿ����
    char          szBankid[32 + 1];     // �ⲿ�˻�
    char          szFeeOneYhs[21 + 1];  // һ��ӡ��˰
    char          szFeeOneGhf[21 + 1];  // һ��������
    char          szFeeOneQsf[21 + 1];  // һ�������
    char          szFeeOneJygf[21 + 1]; // һ�����׹��
    char          szFeeOneJsf[21 + 1];  // һ�����ַ�
    char          szFeeOneZgf[21 + 1];  // һ��֤�ܷ�
    char          szFeeOneQtf[21 + 1];  // һ��������
    char          szFeeOneFxj[21 + 1];  // һ�����ս�
};
//-------------------------------10101518:���ʲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcChkAcctField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcChkAcctField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ��������
    int           iOrdertime;           // ����ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ��˵��
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // �г�����
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szFundeffect[21 + 1]; // �ʽ�����
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szFeeJsxf[21 + 1];    // ��Ӷ��
    char          szFeeSxf[21 + 1];     // Ӷ��
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFeeQtf[21 + 1];     // ������
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szBankcode[16 + 1];   // ���д���
    LONGLONG      llStkeffect;          // �ɷݷ�����
    char          szMatchcode[32 + 1];  // �ɽ����
};
//-------------------------------10101519:��ȡ��ͨת��(����)�˺Ų�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBankAcctField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chMoneytype;       // ���Ҵ���
    LONGLONG      llFundid;          // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcBankAcctField
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szOrgid[4 + 1];     // ��������
    char          szBankcode[4 + 1];  // ���д���
    char          szBankname[32 + 1]; // ��������
    char          chMoneytype;        // ���Ҵ���
    char          szBankid[32 + 1];   // �����ʻ�
    LONGLONG      llFundid;           // �ʽ��ʺ�
    char          chLinkflag;         // ת�ʱ�ʶ
    char          chSourcetype;       // ������
};
//-------------------------------10101520:��ȡ��ͨ�ⲿ(����)�˺Ų�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOtherBankAcctField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chMoneytype;       // ���Ҵ���
    LONGLONG      llFundid;          // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcOtherBankAcctField
{
    LONGLONG      llCustid;            // �ͻ�����
    char          szOrgid[4 + 1];      // ��������
    char          szBankcode[4 + 1];   // ���д���
    char          szBankid[32 + 1];    // �����ʻ�
    char          szSubbankid[32 + 1]; // �������ʻ�
    LONGLONG      llFundid;            // �ʽ��ʺ�
};
//-------------------------------10101521:�ʽ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFundField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcFundField
{
    LONGLONG      llCustid;              // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szOrgid[4 + 1];        // ��������
    char          chMoneytype;           // ����
    char          szFundbal[21 + 1];     // �ʽ����
    char          szFundavl[21 + 1];     // �ʽ���ý��
    char          szMarketvalue[21 + 1]; // �ʲ���ֵ
    char          szFund[21 + 1];        // �ʽ��ʲ�
    char          szStkvalue[21 + 1];    // ��ֵ
    int           iFundseq;              // ���ʽ��־
    char          szFundloan[21 + 1];    // �����ܽ��
    char          szFundbuy[21 + 1];     // ���붳��
    char          szFundsale[21 + 1];    // �����ⶳ
    char          szFundfrz[21 + 1];     // �����ܽ��
    char          szFundlastbal[21 + 1]; // �������
};
//-------------------------------10101522:�����ʽ���ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFundDetailField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFundDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ��������
    int           iOrdertime;           // ����ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ��˵��
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // �г�����
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szFundeffect[21 + 1]; // �ʽ�����
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
};
//-------------------------------10101523:����ί�л���(410514)--------------------------
struct MATRADEAPI CReqStkQryRpcOrderSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspStkQryRpcOrderSummaryField
{
    int           iOrderdate;            // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    char          szOrgid[4 + 1];        // ��������
    char          szBsflag[2 + 1];       // �������
    char          chMarket;              // �����г�
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    LONGLONG      llOrderqty;            // ί������
    char          szOrderfrzamt[21 + 1]; // ί�н��
    LONGLONG      llMatchqty;            // �ɽ�����
    LONGLONG      llCancelqty;           // ��������
    char          szMatchamt[21 + 1];    // �ɽ����
};
//-------------------------------10101524:���ճɽ�����(410516)--------------------------
struct MATRADEAPI CReqStkQryRpcMatchSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspStkQryRpcMatchSummaryField
{
    int           iOperdate;            // ��������
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��������
    char          szBsflag[2 + 1];      // �������
    char          chMarket;             // �����г�
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    LONGLONG      llMatchqty;           // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    char          szBankcode[4 + 1];    // �ⲿ����
    char          szBankid[32 + 1];     // �ⲿ�˻�
};

//-------------------------------10101525:��ѯ��ǰϵͳ״̬--------------------------
struct MATRADEAPI CReqStkQryRpcCurSysStatField
{
};
struct MATRADEAPI CRspStkQryRpcCurSysStatField
{
    int           iSysdate;              // ϵͳ����
    int           iOrderdate;            // ί������
    char          chStatus;              // ϵͳ����״̬
    char          szNightremark[32 + 1]; // ҹ��״̬ע��
    int           iSystime;              // ����ʱ��
};
//-------------------------------10101526:ȡ�ֵ���Ϣ--------------------------
struct MATRADEAPI CReqStkRpcDictInfoField
{
    char          szDictitem[8 + 1]; // �ֵ���Ŀ
    char          szSubitem[4 + 1];  // �ֵ�����
};
struct MATRADEAPI CRspStkRpcDictInfoField
{
    char          szOrgid[4 + 1];        // ��������
    char          szDictitem[8 + 1];     // �ֵ���Ŀ
    char          szSubitem[4 + 1];      // �ֵ�����
    char          szSubitemname[32 + 1]; // ��������
    char          chDispflag;            // ��ʾ��ʶ
    char          chAddenable;           // �ֵ�ɷ���������
    char          szItemname[32 + 1];    // �ֵ���Ŀ����
};
//-------------------------------10101527:֤ȯ��Ϣ--------------------------
struct MATRADEAPI CReqStkRpcStkInfoField
{
    char          chMarket;          // �����г�
    char          chStklevel;        // ֤ȯ����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szPoststr[32 + 1]; // ��λ��
    int           iRowcount;         // ��ѯ����
    char          chStktype;         // ֤ȯ���
};
struct MATRADEAPI CRspStkRpcStkInfoField
{
    char          szPoststr[32 + 1];      // ��λ��
    char          chMarket;               // �����г�
    char          chMoneytype;            // ����
    char          szStkname[64 + 1];      // ֤ȯ����
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          chStktype;              // ֤ȯ���
    int           iPriceunit;             // ��λ
    char          szMaxrisevalue[21 + 1]; // ��ͣ�۸�
    char          szMaxdownvalue[21 + 1]; // ��ͣ�۸�
    char          chStopflag;             // ͣ�Ʊ�־
    char          chMtkcalflag;           // ��ֵ�����ʶ
    char          szBondintr[21 + 1];     // ծȯӦ����Ϣ
    int           iMaxqty;                // �������
    int           iMinqty;                // �������
    int           iBuyunit;               // ������С��λ
    int           iSaleunit;              // ������С��λ
    char          chStkstatus;            // ֤ȯ״̬
    char          chStklevel;             // ֤ȯ����
    char          chTrdid;                // ��������
    int           iQuitdate;              // ����֤ȯ���׽�ֹ����
    char          szFixprice[21 + 1];     // ϵͳ����
    char          chPriceflag;            // ί�м۸��־
    char          szMemotext[128 + 1];    // ����֤ȯ��ʾ��Ϣ
};
//-------------------------------10101528:��ѯ������Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcOrgInfoField
{
    char          szQryorgid[4 + 1]; // ��������
};
struct MATRADEAPI CRspStkQryRpcOrgInfoField
{
    char          szOrgid[4 + 1];    // ��������
    char          szOrgname[32 + 1]; // �������
};
//-------------------------------10101529:��֤ͨת������ҵ����Ϣ--------------------------
struct MATRADEAPI CReqStkRpcBankStkTransferBankBizInfoField
{
    char          szBankcode[4 + 1]; // ���д���
};
struct MATRADEAPI CRspStkRpcBankStkTransferBankBizInfoField
{
    char          szBankcode[4 + 1]; // ���д���
    int           iBanktrdid;        // ���н�������
    char          chTrdpwdflag;      // ��������У��
    char          chCtrlflag;        // ֤��У���־
    char          chStatus;          // ����״̬
};
//-------------------------------10101530:�û���½--------------------------
struct MATRADEAPI CReqStkRpcLoginField
{
    char          chInputtype;                // ��½����
    char          szInputid[64 + 1];          // ��½��ʶ
    char          szProcName[128 + 1];        // ��������������
    char          szCert[4096 + 1];           // ֤��
    char          chCerttype;                 // ֤������
    char          chUserrole;                 // �û���ɫ
    char          szRandcode[32 + 1];         // �����
    char          szSignedrandcode[4096 + 1]; // ǩ��������
    char          szEtokenpin[33 + 1];        // ��̬����pin��
    char          szDynpwd[33 + 1];           // ��̬����
    char          szLoginsite[64 + 1];        // ί��վ��
    char          szLoginip[64 + 1];          // ��¼����IP
    char          szMac[32 + 1];              // ��¼����MAC��ַ
    char          szCpusn[32 + 1];            // ��¼����cpu���к�
    char          szHddsn[32 + 1];            // ��¼����Ӳ�����к�
    char          chCheckauthflag;            // ��ȫ��֤����־
};
struct MATRADEAPI CRspStkRpcLoginField
{
    char          chCustprop;             // �ͻ�����
    char          chMarket;               // �����г�
    char          szSecuid[10 + 1];       // �ɶ�����
    char          szName[16 + 1];         // �ɶ�����
    LONGLONG      llFundid;               // ȱʡ�ʽ��ʻ�
    LONGLONG      llCustid;               // �ͻ�����
    char          szCustname[16 + 1];     // �ͻ�����
    char          szOrgid[4 + 1];         // ��������
    char          szBankcode[4 + 1];      // ���д���
    char          szIdentitysign[64 + 1]; // ����ǩ��
    char          chTimeoutflag;          // ��ʱ����
    char          chAuthlevel;            // ��֤��ʽ/����
    int           iPwderrtimes;           // ��½�������
    char          chSingleflag;           // �ͻ���־
    char          chCheckpwdflag;         // ������Ч��־
    char          szCustcert[128 + 1];    // �ͻ�֤��
    char          szTokenlen[8 + 1];      // ��¼ʱ����Ķ�̬���Ƴ���
    char          szLastlogindate[8 + 1]; // �����¼����
    char          szLastlogintime[8 + 1]; // �����¼ʱ��
    char          szLastloginip[64 + 1];  // �����¼IP
    char          szLastloginmac[32 + 1]; // �����¼MAC
    char          chInputtype;            // ��½����
    char          szInputid[64 + 1];      // ��½��ʶ
    char          szTokenenddate[8 + 1];  // �ͻ���̬���ƽ�������
    char          chBindflag;             // Ӳ������Ϣ��ʶ
};
//-------------------------------10101531:�ͻ����ʲ���ѯ(��)--------------------------
struct MATRADEAPI CReqStkQryRpcTotalAssetsField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ��ʺ�
    char          chMoneytype;      // ���Ҵ���
    char          chAssetcategory;  // �ʲ����
};
struct MATRADEAPI CRspStkQryRpcTotalAssetsField
{
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          chMoneytype;            // ���Ҵ���
    char          szSpecies[4 + 1];       // �ʲ���Ŀ����
    char          szSpeciesname[32 + 1];  // �ʲ���Ŀ����
    char          chAssetcategory;        // �ʲ����
    char          szCategoryname[32 + 1]; // �ʲ��������
    char          szAsset[21 + 1];        // �� ��
};
//-------------------------------10101532:�޸���ϵ��ʽ�����Ͻ���ʹ�ã�--------------------------
struct MATRADEAPI CReqStkRpcChgContactField
{
    char          chIdtype;           // ֤������
    char          szIdno[32 + 1];     // ֤������
    char          szAddr[64 + 1];     // ��ַ
    char          szPostid[16 + 1];   // �ʱ�
    char          szTelno[32 + 1];    // �绰
    char          szMobileno[32 + 1]; // �ƶ��绰
    char          szEmail[32 + 1];    // EMAIL
    char          chContact;          // ���緽ʽ
    char          chContactfrep;      // ����Ƶ��
    char          chEdu;              // ѧ��
    char          chOcctype;          // ְҵ
};
struct MATRADEAPI CRspStkRpcChgContactField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101533:�ͻ����ϲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCustInfoField
{
};
struct MATRADEAPI CRspStkQryRpcCustInfoField
{
    LONGLONG      llCustid;                // �ͻ�����
    char          szCustname[16 + 1];      // �ͻ�����
    char          szOrgid[4 + 1];          // ��������
    char          chSex;                   // �Ա�
    char          szAddr[64 + 1];          // ��ַ
    char          szPostid[16 + 1];        // �ʱ�
    char          szTelno[32 + 1];         // �绰
    char          szMobileno[32 + 1];      // �ƶ��绰
    char          szEmail[32 + 1];         // EMAIL
    int           iOpendate;               // ��������
    char          chContact;               // ���緽ʽ
    char          chContactfrep;           // ����Ƶ��
    char          szRemark[32 + 1];        // ��ע��Ϣ
    char          chIdtype;                // ֤������
    char          szIdno[32 + 1];          // ֤������
    int           iIdbegindate;            // ֤����Ч��ʼ����
    int           iIdenddate;              // ֤����Ч��������
    int           iYearchkdate;            // �������
    int           iClosedate;              // ��������
    char          szPoliceorg[64 + 1];     // ��֤��λ
    char          chEdu;                   // ѧ��
    char          chOcctype;               // ְҵ
    char          szContractverno[32 + 1]; // ������ͬ�汾��
    char          szExtprop[32 + 1];       // ��չ����
    int           iPwderrtimes;            // �ͻ�����У��������
    int           iTimeout;                // ��½������ʱ
    char          chLockflag;              // �����������
};
//-------------------------------10101534:�޸Ĳ�����ʽ--------------------------
struct MATRADEAPI CReqStkRpcChgOperModeField
{
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szNewoperway[128 + 1]; // ������ʽ
};
struct MATRADEAPI CRspStkRpcChgOperModeField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101535:��ѯ�ͻ���ͨ�Ĳ�����ʽ--------------------------
struct MATRADEAPI CReqStkQryRpcCustOperModeField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcCustOperModeField
{
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          szName[16 + 1];     // �ʽ�����
    char          szOperway[128 + 1]; // ������ʽ
};
//-------------------------------10101536:�޸Ŀͻ���ϵ����Ϣ--------------------------
struct MATRADEAPI CReqStkRpcChgCustInfoField
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szLinkman[16 + 1];  // ��ϵ������
    char          chSex;              // �Ա�
    char          chOcctype;          // ְҵ
    char          chIdtype;           // ֤������
    char          szIdno[32 + 1];     // ֤������
    char          szTelno[32 + 1];    // ��ͥ�绰
    char          szTelnoCo[32 + 1];  // ��λ�绰
    char          szMobileno[32 + 1]; // �ƶ��绰
    char          szFax[32 + 1];      // �������
    char          szEmail[32 + 1];    // EMAIL
    char          szAddr[64 + 1];     // ��ַ
    char          szPostid[16 + 1];   // �ʱ�
    char          szRemark[32 + 1];   // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcChgCustInfoField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101537:���ÿͻ�����չ����--------------------------
struct MATRADEAPI CReqStkRpcSetCustAttrExField
{
    char          szExtprop[32 + 1]; // �ͻ���չ����
};
struct MATRADEAPI CRspStkRpcSetCustAttrExField
{
};
//-------------------------------10101538:��������ǩ��--------------------------
struct MATRADEAPI CReqStkRpcSetDigitalSignField
{
    char          szIdentitysign[64 + 1]; // ����ǩ��
};
struct MATRADEAPI CRspStkRpcSetDigitalSignField
{
};
//-------------------------------10101539:��Χ�޸��ʽ��ʺ�Ȩ��--------------------------
struct MATRADEAPI CReqStkRpcChgCuacctPermissionField
{
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szRightid[2 + 1];  // Ȩ��
    char          chMarket;          // �г�
    char          szSecuid[10 + 1];  // ֤ȯ�˺�
    char          szRemark[128 + 1]; // ��ע
    char          chAction;          // ��������
};
struct MATRADEAPI CRspStkRpcChgCuacctPermissionField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101540:�ʽ��ʺſ�ͨ�ʽ�Ȩ�޲�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctPermissionField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcCuacctPermissionField
{
    char          szOrgid[4 + 1];       // Ӫҵ������
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szFundname[16 + 1];   // �ʽ�����
    char          szFundright[512 + 1]; // �ʽ�Ȩ��
};
//-------------------------------10101541:֤ȯ�ʺſ�ͨȨ�޲�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcTrdacctPermissionField
{
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    char          chMarket;         // �г�
};
struct MATRADEAPI CRspStkQryRpcTrdacctPermissionField
{
    char          chMarket;             // �г�
    char          szSecuid[10 + 1];     // ֤ȯ�˺�
    char          szSecuright[512 + 1]; // ֤ȯȨ��
};
//-------------------------------10101542:�ͻ�Ȩ����Ч����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCustPermissionValidPeriodField
{
    LONGLONG      llFundid;           // �ʽ��˻�
    char          chMarket;           // �г�
    char          szSecuid[10 + 1];   // ֤ȯ�˺�
    char          szRightid[512 + 1]; // Ȩ��
};
struct MATRADEAPI CRspStkQryRpcCustPermissionValidPeriodField
{
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // Ӫҵ������
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    char          szRightid[2 + 1]; // Ȩ��
    int           iEffectdate;      // ��Ч����
    int           iExpiredate;      // ʧЧ����
    char          szRemark[64 + 1]; // ��ע
};
//-------------------------------10101543:��Χ����ͻ�Ȩ��--------------------------
struct MATRADEAPI CReqStkRpcActivateCustPermissionField
{
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szRightid[2 + 1];  // Ȩ��
    char          chMarket;          // �г�
    char          szSecuid[10 + 1];  // ֤ȯ�˺�
    int           iExpiredate;       // ʧЧ����
    char          szRemark[128 + 1]; // ��ע
};
struct MATRADEAPI CRspStkRpcActivateCustPermissionField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101544:�ͻ����������Ѳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCustSpecialFeeField
{
    LONGLONG      llFundid;             // �ʲ��˻�
    char          szMarket[32 + 1];     // �г�����
    char          szStktype[128 + 1];   // ֤ȯ���
    char          szTrdid[128 + 1];     // ��������
    char          szMoneytype[128 + 1]; // ��������
    char          szBsflag[128 + 1];    // �������
};
struct MATRADEAPI CRspStkQryRpcCustSpecialFeeField
{
    int           iServerid;                // ��������
    char          szOrgid[4 + 1];           // ��������
    LONGLONG      llFundid;                 // �ʽ��˺�
    LONGLONG      llCustid;                 // �ͻ�����
    char          szCustname[32 + 1];       // �ͻ�����
    char          chMarket;                 // �г�����
    char          szBsflag[2 + 1];          // ��������
    char          chPtOperway;              // ������ʽ
    char          chMoneytype;              // ���Ҵ���
    char          chStktype;                // ֤ȯ���
    char          szTrdid[2 + 1];           // ��������
    char          szMinfee[21 + 1];         // ����շ�
    char          szMaxfee[21 + 1];         // ����ն�
    char          szCommissionrate[21 + 1]; // ����
};
//-------------------------------10101545:һ���Է���Ӷ����ȡ--------------------------
struct MATRADEAPI CReqStkRpcOneTimeServiceCommissionField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˻�
    char          chMoneytype;      // ����
    int           iFeeno;           // ����Ӷ����
};
struct MATRADEAPI CRspStkRpcOneTimeServiceCommissionField
{
    char          szFee[21 + 1]; // ������
    int           iSno;          // ������ˮ��
};
//-------------------------------10101546:һ���Է���Ӷ�𳷵�--------------------------
struct MATRADEAPI CReqStkRpcCancelOneTimeServiceCommissionField
{
    LONGLONG      llFundid;         // �ʽ��˻�
    char          chMoneytype;      // ����
    int           iFeeno;           // ����Ӷ����
};
struct MATRADEAPI CRspStkRpcCancelOneTimeServiceCommissionField
{
    char          szReturnamt[21 + 1]; // �˿���
    int           iSno;                // ������ˮ��
};
//-------------------------------10101547:�̶����޷���Ӷ�����--------------------------
struct MATRADEAPI CReqStkRpcFixedTermServiceCommissionField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˻�
    int           iFeeno;           // ����Ӷ����
    char          chEffectmode;     // ��Ч��ʽ
    char          chContinueflag;   // �Զ�����ģʽ
    int           iContinuetime;    // �Զ����Ѵ���
};
struct MATRADEAPI CRspStkRpcFixedTermServiceCommissionField
{
    char          szFreezefund[21 + 1]; // ������
    int           iEffectdate;          // ��Ч����
    int           iSno;                 // ������ˮ��
};
//-------------------------------10101548:�̶����޷���Ӷ���˿�--------------------------
struct MATRADEAPI CReqStkRpcFixedTermServiceCommissionRefundField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˻�
    int           iFeeno;           // ����Ӷ����
    char          chReturnmode;     // �˿ʽ
};
struct MATRADEAPI CRspStkRpcFixedTermServiceCommissionRefundField
{
    char          szReturnamt[21 + 1]; // �˿���
    int           iSno;                // ������ˮ��
};
//-------------------------------10101549:һ���Է���Ӷ�����ò�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOneTimeServiceCommissionSettingField
{
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcOneTimeServiceCommissionSettingField
{
    char          szOrgid[4 + 1]; // ��������
    int           iFeeno;         // ����Ӷ����
    char          chMoneytype;    // ����
    char          chFeetype;      // ����Ӷ������
    char          szFee[21 + 1];  // ����
};
//-------------------------------10101550:һ���Է���Ӷ����ȡ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOneTimeServiceCommissionsField
{
    LONGLONG      llFundid;         // �ʽ��˻�
};
struct MATRADEAPI CRspStkQryRpcOneTimeServiceCommissionsField
{
    int           iFeeno;        // ����Ӷ����
    char          chFeetype;     // ����Ӷ������
    char          chMoneytype;   // ����
    char          szFee[21 + 1]; // ��ȡ���
    int           iTrddate;      // ��������
};
//-------------------------------10101551:��ѯ��ѯ�������--------------------------
struct MATRADEAPI CReqStkQryRpcConsultationPaymentCategoryField
{
    char          szProccode[4 + 1]; // ��Ʒ���
};
struct MATRADEAPI CRspStkQryRpcConsultationPaymentCategoryField
{
    char          szProccode[4 + 1];  // ��Ʒ���
    char          szProcname[32 + 1]; // ��Ʒ����
    char          chProducttype;      // ��Ʒ����
    char          szFdOrgid[255 + 1]; // ��ֹӪҵ��
};
//-------------------------------10101552:������ѯ�������--------------------------
struct MATRADEAPI CReqStkRpcAddConsultationPaymentCategoryField
{
    char          szProccode[4 + 1];  // ��Ʒ���
    char          szProcname[32 + 1]; // ��Ʒ����
    char          chProducttype;      // ��Ʒ����
    char          szFdOrgid[4 + 1];   // ��ֹӪҵ��
    char          szRemark[64 + 1];   // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcAddConsultationPaymentCategoryField
{
};
//-------------------------------10101553:ά���ͻ�����״̬--------------------------
struct MATRADEAPI CReqStkRpcMaintainCustSubStatusField
{
    int           iOperdate;        // ��������
    int           iStrsno;          // ��ʼ��ˮ��
    int           iEndsno;          // ������ˮ��
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          chBusitype;       // ҵ������
    char          chCheckflag;      // ������־
};
struct MATRADEAPI CRspStkRpcMaintainCustSubStatusField
{
};
//-------------------------------10101554:��ѯ�ͻ�������ˮ--------------------------
struct MATRADEAPI CReqStkQryRpcCustSubStatementField
{
    int           iStrdate;           // ��ʼ����
    int           iEnddate;           // ��������
    char          szProductid[4 + 1]; // ��Ʒ���
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          chCheckflag;        // ������־
    char          chQryflag;          // ��ѯ����
    int           iCount;             // ��������
    char          szPoststr[32 + 1];  // ��λ��
};
struct MATRADEAPI CRspStkQryRpcCustSubStatementField
{
    char          szPoststr[32 + 1];      // ��λ��
    int           iOperdate;              // ��������
    int           iSno;                   // ϵͳ��ˮ��
    char          szProductid[4 + 1];     // ��Ʒ���
    char          szProcductname[32 + 1]; // ��Ʒ����
    char          szOrgid[4 + 1];         // �������
    char          szBrhid[4 + 1];         // ������֧
    int           iOpertime;              // ����ʱ��
    LONGLONG      llCustid;               // �ͻ�����
    char          szName[16 + 1];         // ��������
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          chMoneytype;            // ���Ҵ���
    char          chBusitype;             // ҵ������
    char          chCheckflag;            // ������־
    char          szNetaddr[12 + 1];      // ����վ��
    char          szOperorg[4 + 1];       // ����Ӫҵ��
    char          szRemark[64 + 1];       // ��ע��Ϣ
};
//-------------------------------10101555:�ͻ���������--------------------------
struct MATRADEAPI CReqStkRpcCustSubSettingField
{
    char          szProductid[4 + 1];     // ��Ʒ���
    char          szProcductname[32 + 1]; // ��Ʒ����
    char          szBrhid[4 + 1];         // ������֧
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          chMoneytype;            // ���Ҵ���
    char          chBusitype;             // ҵ������
};
struct MATRADEAPI CRspStkRpcCustSubSettingField
{
};
//-------------------------------10101556:�������շѽṹ--------------------------
struct MATRADEAPI CReqStkRpcThirdPartyChargingStructureField
{
    LONGLONG      llFundid;           // �ʽ��˻�
    char          chMoneytype;        // ���Ҵ���
    char          chFeetype;          // ���ñ�ʶ
    char          szOtherfee[21 + 1]; // ��������
};
struct MATRADEAPI CRspStkRpcThirdPartyChargingStructureField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101557:Ͷ����ѯ��Ʒ���ñ�֤��֧��--------------------------
struct MATRADEAPI CReqStkRpcInvestmentAdvisoryProductFeeField
{
    LONGLONG      llFundid;                // �ʽ��˻�
    char          szFundpwd[32 + 1];       // �ʽ�����
    char          chMoneytype;             // ���Ҵ���
    char          szDepositpayfee[21 + 1]; // ֧�����
    char          szOrderid[10 + 1];       // �������
    char          szRemark[64 + 1];        // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcInvestmentAdvisoryProductFeeField
{
    int           iSno;              // ������ˮ��
    char          szFundavl[21 + 1]; // �ʽ����
};
//-------------------------------10101558:����У��--------------------------
struct MATRADEAPI CReqStkRpcCuacctPwdCheckField
{
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szFundpwd[64 + 1]; // �ʽ�����
};
struct MATRADEAPI CRspStkRpcCuacctPwdCheckField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101559:�ʽ����ϲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctInfoField
{
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szFundpwd[64 + 1]; // �ʽ�����
    char          chMoneytype;       // ���Ҵ���
};
struct MATRADEAPI CRspStkQryRpcCuacctInfoField
{
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          szOrgid[4 + 1];     // ��������
    char          szFundname[16 + 1]; // �ʽ�����
    char          chIdtype;           // ֤������
    char          szIdno[32 + 1];     // ֤������
    int           iOpendate;          // ��������
    char          chStatus;           // �ʽ�״̬
    char          chMoneytype;        // ���Ҵ���
    char          szFundbal[21 + 1];  // �ʽ����
    char          szFundavl[21 + 1];  // �ʽ����
};
//-------------------------------10101560:��ȡ�ͻ����Ϻ˲�״̬--------------------------
struct MATRADEAPI CReqStkRpcCustInfoCheckField
{
    LONGLONG      llCustid;         // �ͻ�����
};
struct MATRADEAPI CRspStkRpcCustInfoCheckField
{
    char          chVerifiedflag; // �ͻ����Ϻ˲��ʶ
    int           iVerifieddate;  // �ͻ����Ϻ˲�����
};
//-------------------------------10101561:���ÿͻ���¼У����Ϣ--------------------------
struct MATRADEAPI CReqStkRpcSetLoginCheckModeField
{
    char          chLockflag;       // ��������
    int           iPwderrtimes;     // �ͻ�����У��������
    int           iTimeout;         // ��½������ʱ
};
struct MATRADEAPI CRspStkRpcSetLoginCheckModeField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101562:���ÿͻ����Ϻ˲��ʶ--------------------------
struct MATRADEAPI CReqStkRpcSetCustInfoCheckModeField
{
    LONGLONG      llCustid;         // �ͻ�����
    char          chVerifiedflag;   // �ͻ��˲��ʶ
};
struct MATRADEAPI CRspStkRpcSetCustInfoCheckModeField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101563:���ÿͻ���Ϣ״̬--------------------------
struct MATRADEAPI CReqStkRpcSetCustMsgStatusField
{
    LONGLONG      llCustid;         // �ͻ�����
    int           iNewsid;          // ��Ϣ��
    char          chSendflag;       // ���ͱ�־
};
struct MATRADEAPI CRspStkRpcSetCustMsgStatusField
{
};
//-------------------------------10101564:��ѯ�ͻ���Ϣ����--------------------------
struct MATRADEAPI CReqStkQryRpcCustMsgServiceField
{
    LONGLONG      llCustid;         // �ͻ�����
    int           iNewsid;          // ��Ϣ��
};
struct MATRADEAPI CRspStkQryRpcCustMsgServiceField
{
    char          szOrgid[4 + 1];       // ��������
    char          szBrhid[4 + 1];       // ��֧����
    LONGLONG      llCustid;             // �ͻ�����
    int           iNewsid;              // ��Ϣ��
    char          szNewsname[32 + 1];   // ��Ϣ����
    char          szNewstext[1024 + 1]; // ��Ϣ����
    char          szRemark[255 + 1];    // ��ע
};
//-------------------------------10101565:�޸���������--------------------------
struct MATRADEAPI CReqStkRpcChgBankPwdField
{
    LONGLONG      llFundid;             // �ʽ��˺�
    char          chMoneytype;          // ���Ҵ���
    char          szFundpwd[32 + 1];    // �ʽ�����
    char          szBankcode[4 + 1];    // ���д���
    char          szBankpwd[32 + 1];    // ��������
    char          szNewbankpwd[32 + 1]; // ����������
};
struct MATRADEAPI CRspStkRpcChgBankPwdField
{
    int           iSno;             // ί�����
    char          chStatus;         // �������
    char          szErrmsg[64 + 1]; // ������Ϣ
};
//-------------------------------10101566:�ʽ�̨�ʼ�ת��--------------------------
struct MATRADEAPI CReqStkRpcTransferBetweenCuacctField
{
    char          szOrgid[4 + 1];        // ��������
    LONGLONG      llOutfundid;           // ת���ʽ��ʺ�
    char          chCheckpwdflag;        // ��������־
    char          szOutpassword[32 + 1]; // ת���ʽ�����
    LONGLONG      llInfundid;            // ת���ʽ��ʺ�
    char          chMoneytype;           // ���Ҵ���
    char          szFundeffect[21 + 1];  // ת�ʽ��
    char          chCashcheck;           // �ֽ�֧Ʊ����
};
struct MATRADEAPI CRspStkRpcTransferBetweenCuacctField
{
    int           iOutsno; // ת����ˮ��
    int           iInsno;  // ת����ˮ��
};
//-------------------------------10101567:��Χ�ͻ������ʻ��ʽ�鼯--------------------------
struct MATRADEAPI CReqStkRpcCuacctCashConcentrationField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMoneytype;      // ���Ҵ���
    char          chCashcheck;      // �ֽ�֧Ʊ����
};
struct MATRADEAPI CRspStkRpcCuacctCashConcentrationField
{
    char          szFundeffect[21 + 1]; // �鼯���          ��
    int           iRenum;               // ���ر���
};
//-------------------------------10101568:ȡͬһ�ͻ�����̨�ʡ�ת��̨��--------------------------
struct MATRADEAPI CReqStkRpcCuacctInfo2Field
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ�����
};
struct MATRADEAPI CRspStkRpcCuacctInfo2Field
{
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��ʺ�
    char          chFundtype;          // �ʻ����
    char          chMoneytype;         // ���Ҵ���
    char          szFundbal[21 + 1];   // ���
    char          szFundavl[21 + 1];   // ����
    char          szSfbankcode[4 + 1]; // ����������д���
};
//-------------------------------10101569:�ʽ��ȡ����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctMaxDrawField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcCuacctMaxDrawField
{
    LONGLONG      llCustid;          // �ͻ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szOrgid[4 + 1];    // ��������
    char          chMoneytype;       // ����
    char          szMaxdraw[21 + 1]; // ��ȡ���
};
//-------------------------------10101570:�ͻ���ȡ�ʽ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctMaxDrawForTencentPayField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ���Ҵ���
};
struct MATRADEAPI CRspStkQryRpcCuacctMaxDrawForTencentPayField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ����
    char          chMoneytype;       // ���Ҵ���
    char          szMaxdraw[21 + 1]; // ����ȡ���
};
//-------------------------------10101571:ȡ֤ȯ����ǰ���¼۵�,֧����������--------------------------
struct MATRADEAPI CReqStkRpcStkAvlAndLatestPriceField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��˻�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szPrice[21 + 1];  // �۸�
    int           iQty;             // ����
};
struct MATRADEAPI CRspStkRpcStkAvlAndLatestPriceField
{
    char          chMarket;            // �����г�
    char          szStkcode[6 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];   // ֤ȯ����
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��ʻ�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          chMoneytype;         // ���Ҵ���
    char          szFundavl[21 + 1];   // �ʽ����
    char          szFundbal[21 + 1];   // �ʽ����
    int           iStkavl;             // ֤ȯ����
    int           iStkmaxqty;          // ֤ȯ��������
    char          szLastprice[21 + 1]; // ����۸�
    char          szUpprice[21 + 1];   // ��ͣ�۸�
    char          szDownprice[21 + 1]; // ��ͣ�۸�
    char          chHandflag;          // ���ֱ�־
    char          szBondintr[21 + 1];  // ��ծ��Ϣ
};
//-------------------------------10101572:ȡ���������,֧����������--------------------------
struct MATRADEAPI CReqStkRpcMaxStkQtyField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    char          szPrice[21 + 1];      // �۸�
    char          szBankcode[4 + 1];    // �ⲿ����
    char          chHiqtyflag;          // ������ޱ�־
    char          chCreditid;           // ���ò�Ʒ��ʶ
    char          chCreditflag;         // ����ί������
    char          chLinkmarket;         // �����г�
    char          szLinksecuid[20 + 1]; // �����ɶ�
    char          szSorttype[4 + 1];    // Ʒ�����
    char          chDzsaletype;         // ��������
    char          szProdcode[12 + 1];   // ��Ʒ����
};
struct MATRADEAPI CRspStkRpcMaxStkQtyField
{
    int           iMaxstkqty; // �ɷ�����
};
//-------------------------------10101573:����ί��ҵ��,֧����������--------------------------
struct MATRADEAPI CReqStkRpcOrderField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    char          szPrice[21 + 1];      // �۸�
    int           iQty;                 // ����
    int           iOrdergroup;          // ί������
    char          szBankcode[4 + 1];    // �ⲿ����
    char          chCreditid;           // ���ò�Ʒ��ʶ
    char          chCreditflag;         // ����ί������
    char          szRemark[64 + 1];     // ��ע��Ϣ
    char          szTargetseat[6 + 1];  // �Է�ϯλ
    int           iPromiseno;           // Լ����
    int           iRisksno;             // ���յ�����ˮ��
    char          chAutoflag;           // �Զ�չ�ڱ�־
    int           iEnddate;             // չ����ֹ����
    char          szLinkman[12 + 1];    // ��ϵ��
    char          szLinkway[30 + 1];    // ��ϵ��ʽ
    char          chLinkmarket;         // �����г�
    char          szLinksecuid[20 + 1]; // �����ɶ�
    char          szSorttype[3 + 1];    // Ʒ�����
    int           iMergematchcode;      // �ϲ������ĳ�ʼ���׵ĳɽ����
    int           iMergematchdate;      // �ϲ������ĳ�ʼ���׵ĳɽ�����
    char          szOldorderid[24 + 1]; // ԭ��ͬ���
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          chPricetype;          // ��������
    char          chBlackflag;          // �Ƿ��������������֤ȯ
    char          chDzsaletype;         // ��������
    LONGLONG      llRisksignsno;        // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
};
//-------------------------------10101574:ί�г���--------------------------
struct MATRADEAPI CReqStkRpcOrderCancelField
{
    int           iOrderdate;       // ί������
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iOrdersno;        // ί�����
    char          szBsflag[2 + 1];  // �������
};
struct MATRADEAPI CRspStkRpcOrderCancelField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
    char          chCancelStatus;  // �ڲ�������־
    int           iOrdersno;       // ����ί�����
};
//-------------------------------10101575:ί�г�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOrderCancelField
{
    int           iOrderdate;        // ί������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcOrderCancelField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iOrdersno;            // ί�����
    int           iOrdergroup;          // ί������
    char          szOrcderid[10 + 1];   // ��ͬ���
    int           iOrderdate;           // ί������
    int           iOpertime;            // ί��ʱ��
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMarket;             // �ͻ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iOrderqty;            // ί������
    int           iMatchqty;            // �ɽ�����
    char          chOrderstatus;        // ί��״̬
};
//-------------------------------10101576:���óɱ�--------------------------
struct MATRADEAPI CReqStkRpcResetCostField
{
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    LONGLONG      llFundid;            // �ʽ��ʻ�
    char          szCostprice[21 + 1]; // �ɱ��۸�
    char          chReqtype;           // ��������
};
struct MATRADEAPI CRspStkRpcResetCostField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101577:ӯ�����ü���--------------------------
struct MATRADEAPI CReqStkRpcCalcFeeField
{
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          szPrice[21 + 1];  // �ɽ��۸�
    int           iQty;             // �ɽ�����
};
struct MATRADEAPI CRspStkRpcCalcFeeField
{
    char          szTradefee[21 + 1]; // �ܷ���
};
//-------------------------------10101578:ί������ҵ��,֧���������ף�������Χ���ã�--------------------------
struct MATRADEAPI CReqStkRpcOrderForTencentPayField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    char          szPrice[21 + 1];      // �۸�
    int           iQty;                 // ����
    char          szOrdergroup[32 + 1]; // ί������
    char          szBankcode[4 + 1];    // �ⲿ����
    char          chCreditid;           // ���ò�Ʒ��ʶ
    char          chCreditflag;         // ����ί������
    char          szRemark[64 + 1];     // ��ע��Ϣ
    char          szTargetseat[6 + 1];  // �Է�ϯλ
    int           iPromiseno;           // Լ����
    int           iRisksno;             // ���յ�����ˮ��
    char          chAutoflag;           // �Զ�չ�ڱ�־
    int           iEnddate;             // չ����ֹ����
    char          szLinkman[12 + 1];    // ��ϵ��
    char          szLinkway[30 + 1];    // ��ϵ��ʽ
    char          chLinkmarket;         // �����г�
    char          szLinksecuid[20 + 1]; // �����ɶ�
    char          szSorttype[3 + 1];    // Ʒ�����
    int           iMergematchcode;      // �ϲ������ĳ�ʼ���׵ĳɽ����
    int           iMergematchdate;      // �ϲ������ĳ�ʼ���׵ĳɽ�����
    char          szOldorderid[24 + 1]; // ԭ��ͬ���
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          chPricetype;          // ��������
    char          szExtsno[32 + 1];     // �ⲿ��ˮ��
};
struct MATRADEAPI CRspStkRpcOrderForTencentPayField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
};
//-------------------------------10101579:�ʹܷݶ�ת��T+0ί��--------------------------
struct MATRADEAPI CReqStkRpcTransferCapitalManagementShareField
{
    char          chMarket;             // �����г�
    LONGLONG      llFundid;             // �ʽ��ʻ�
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szTaacc[12 + 1];      // �����˺�
    char          szOfcode[8 + 1];      // �������
};
struct MATRADEAPI CRspStkRpcTransferCapitalManagementShareField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101580:�������۽ɿ�, ֧����������--------------------------
struct MATRADEAPI CReqStkRpcCancelRationField
{
    int           iSno;              // ��ˮ��
    int           iMatchdate;        // ��������
    char          chMarket;          // �����г�
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szSecuid[10 + 1];  // �ɶ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    int           iGiveupqty;        // ��������
    char          szBankcode[4 + 1]; // �ⲿ����
    char          szRemark[64 + 1];  // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcCancelRationField
{
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101581:�������۽ɿ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCancelRationField
{
    int           iSno;              // ��ˮ��
    int           iMatchdate;        // ��ǩ����
    char          chMarket;          // �����г�
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szSecuid[10 + 1];  // �ɶ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    int           iGiveupqty;        // ��������
    char          szBankcode[4 + 1]; // �ⲿ����
    char          szRemark[64 + 1];  // ��ע��Ϣ
};
struct MATRADEAPI CRspStkQryRpcCancelRationField
{
    int           iMatchdate;           // ��ǩ����
    int           iSno;                 // ���
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʺ�
    LONGLONG      llCustid;             // �ͻ�����
    int           iOrderdate;           // ί������
    int           iSettlefundays;       // �ɿ�����
    char          szBpsecuid[10 + 1];   // ���̹ɶ�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          chMarket;             // �����г�
    char          szSeat[6 + 1];        // ����ϯλ
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrderid[10 + 1];    // ��ͬ���
    int           iHitqty;              // ��ǩ����
    char          szMatchprice[21 + 1]; // �۸�
    int           iPayqty;              // �ɿ�����
    char          chSourcetype;         // ����
    char          szBankcode[4 + 1];    // �ⲿ����
    int           iGiveupqty;           // �����ɿ�����
    char          chGiveupflag;         // ����ί�з��ͱ�־
    int           iMktconfirmqty;       // ��������������
};
//-------------------------------10101582:�ͻ�ҡ�Ų�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCustLotteryField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iLotteryno;       // ��ŵ��ں�
};
struct MATRADEAPI CRspStkQryRpcCustLotteryField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ�����
    LONGLONG      llFundid;         // �ʽ��ʺ�
    int           iIssue;           // ��ŵ��ں�
    int           iLotteryno;       // ���
    char          chHitflag;        // �����ǩ��־
    char          chProcessflag;    // �ͻ��ҽ���־
    char          szRemark[32 + 1]; // ��ע
};
//-------------------------------10101583:�ͻ�����Χ�ⶳ��ǩԤ�����ʽ�--------------------------
struct MATRADEAPI CReqStkRpcUnfreezePreFrozenFundsField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iMatchdate;       // ��ǩ����
};
struct MATRADEAPI CRspStkRpcUnfreezePreFrozenFundsField
{
    int           iSno;               // ������ˮ��
    char          szUnfrzamt[21 + 1]; // �ⶳԤ������
};
//-------------------------------10101584:��Ʒ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeProductInfoField
{
    char          chProducttype;    // ��Ʒ����
    int           iGhdays;          // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeProductInfoField
{
    char          chProducttype;         // ��Ʒ����
    char          szProductname[64 + 1]; // ��Ʒ����
    int           iGhdays;               // ��Ʒ����
    char          chTermtype;            // ��������
    char          szDuerate[21 + 1];     // ������
    char          szPrerate[21 + 1];     // ��ǰ��������
    char          szContrate[21 + 1];    // ��������
    char          szPunishrate[21 + 1];  // ��Ϣ����
    int           iMinintdays;           // ��С��Ϣ����
    int           iMaxtimes;             // ������ڴ���
    int           iMaxghdays;            // �����
    char          szWarningrate[21 + 1]; // Ԥ����
    char          szLowestrate[21 + 1];  // �����
    char          szEndingrate[21 + 1];  // ��ֹ��
};
//-------------------------------10101585:����Ѻ���֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeNegotiableSecurityField
{
    char          chMarket;         // �����г�
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          chTargetstktype;  // ���ȯ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeNegotiableSecurityField
{
    char          chMarket;             // �����г�
    char          szStkcode[6 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szCloseprice[21 + 1]; // �����̼�
    char          szExchrate[21 + 1];   // Ĭ����Ѻ������
};
//-------------------------------10101586:�ͻ���Ѻ��������ʲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgePledgeConversionRateField
{
    char          chMarket;         // �����г�
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          chProducttype;    // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgePledgeConversionRateField
{
    char          chMarket;           // �����г�
    char          szStkcode[6 + 1];   // ֤ȯ����
    char          szStkname[64 + 1];  // ֤ȯ����
    char          chProducttype;      // ��Ʒ����
    char          szExchrate[21 + 1]; // ��Ѻ������
};
//-------------------------------10101587:�ͻ���������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeLoanQuotaField
{
};
struct MATRADEAPI CRspStkQryRpcStkPledgeLoanQuotaField
{
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llCustid;           // �ͻ�����
    char          szTotalamt[21 + 1]; // �ܶ��
    char          szAvlamt[21 + 1];   // ʣ����ö��
};
//-------------------------------10101588:����Ѻ֤ȯ�ֲֲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeNegotiableSecurityPosiField
{
    char          chProducttype;    // ��Ʒ����
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeNegotiableSecurityPosiField
{
    char          chMarket;              // �г�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkcode[6 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    LONGLONG      llStkavl;              // ����Ѻ����
    char          szLastprice[21 + 1];   // �������¼�
    char          szMktvalue[21 + 1];    // ��ֵ
    char          szPledgeprice[21 + 1]; // ��ѺƷ�۸�
    char          szExchrate[21 + 1];    // ������
    char          szMaxamt[21 + 1];      // �ɴ����
};
//-------------------------------10101589:���ɴ������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeMaxLoanAmtField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szSecuid[10 + 1]; // �ɶ�����
    int           iOrderqty;        // ��Ѻ����
    char          chProducttype;    // Ʒ��
    int           iGhdays;          // ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeMaxLoanAmtField
{
    char          szMaxamt[21 + 1]; // ���ɴ����
};
//-------------------------------10101590:��������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeLoanApplicationField
{
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��˺�
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szSecuid[10 + 1];     // �ɶ�����
    int           iOrderqty;            // ��Ѻ����
    char          szOrderamt[21 + 1];   // ������
    char          chProducttype;        // Ʒ��
    int           iGhdays;              // ����
    char          szFundusetype[2 + 1]; // �ʽ���;����
    char          szFunduse[100 + 1];   // �ʽ���;����
    LONGLONG      llRisksignsno;        // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcStkPledgeLoanApplicationField
{
    char          szReqsno[32 + 1]; // ���뵥��
};
//-------------------------------10101591:��������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeRepaymentApplicationField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szGpzysno[32 + 1]; // ��Լ���
};
struct MATRADEAPI CRspStkRpcStkPledgeRepaymentApplicationField
{
    int           iReqsno; // ���뵥��
};
//-------------------------------10101592:����֤ȯ��Ѻ������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeSupplementaryPledgeSecurityApplicationField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szGpzysno[32 + 1]; // ��Լ���
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSecuid[10 + 1];  // �ɶ�����
    int           iOrderqty;         // ��Ѻ����
};
struct MATRADEAPI CRspStkRpcStkPledgeSupplementaryPledgeSecurityApplicationField
{
    LONGLONG      llReqsno; // ���뵥��
};
//-------------------------------10101593:��Լ��������������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeDeferredContractRepaymentApplicationField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szGpzysno[32 + 1]; // ��Լ���
    int           iEnddate;          // ����Ŀ����
};
struct MATRADEAPI CRspStkRpcStkPledgeDeferredContractRepaymentApplicationField
{
    int           iReqsno; // ���뵥��
};
//-------------------------------10101594:��Լ�貹����Ѻ������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeInsufficientPledgeField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szGpzysno[32 + 1]; // ��Լ���
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeInsufficientPledgeField
{
    LONGLONG      llQty;             // �貹����Ѻ����
    char          szNeedamt[21 + 1]; // �貹����
};
//-------------------------------10101595:ҵ�����������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeBizApplicationStatusField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˺�
    char          szReqbiz[8 + 1];  // ����ҵ������
    int           iBegindate;       // ����(��)
    int           iEnddate;         // ����(ֹ)
};
struct MATRADEAPI CRspStkQryRpcStkPledgeBizApplicationStatusField
{
    char          szReqsno[32 + 1];     // ���뵥��
    int           iReqdate;             // ��������
    char          szReqbiz[8 + 1];      // ����ҵ������
    char          chMarket;             // �г�
    char          szStkcode[6 + 1];     // ֤ȯ����
    char          szSecuid[10 + 1];     // �ɶ�����
    LONGLONG      llOrderqty;           // ����
    char          szOrderamt[21 + 1];   // ���
    char          szDuerate[21 + 1];    // ����
    char          chProducttype;        // ��Ʒ����
    int           iGhdays;              // ����
    int           iTargetdate;          // ������
    char          szFundusetype[2 + 1]; // �ʽ���;����
    char          szFunduse[100 + 1];   // �ʽ���;����
    char          chDealstatus;         // ����״̬
    char          szDealmsg[128 + 1];   // �������
    char          szGpzysno[32 + 1];    // ��Լ���
    char          szOrderid[10 + 1];    // ��������ͬ���
    char          szRemark[256 + 1];    // ��ע
};
//-------------------------------10101596:�����Լ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeLoanContractField
{
    char          szGpzysno[32 + 1]; // ��Լ���
    char          chMarket;          // �г�����
    int           iOrderbegindate;   // ��������(��)
    int           iOrderenddate;     // ��������(ֹ)
    char          chEndflag;         // �˽����
    char          chBusikind;        // ҵ������
    char          szPosstr[64 + 1];  // ��λ��
};
struct MATRADEAPI CRspStkQryRpcStkPledgeLoanContractField
{
    int           iSysdate;                  // ��Լ����
    char          szGpzysno[32 + 1];         // ��Լ���
    char          chMarket;                  // �г�����
    char          chProducttype;             // ��Ʒ����
    int           iGhdays;                   // ����
    char          szDuerate[21 + 1];         // ������
    char          szPrerate[21 + 1];         // ��ǰ��������
    char          szContrate[21 + 1];        // ��������
    char          szPunishrate[21 + 1];      // ��Ϣ����
    int           iOldenddate;               // ��ʼ��������
    int           iEnddate;                  // ��Լ������
    char          szMatchamt[21 + 1];        // ������
    char          szBackamt[21 + 1];         // �ѻ����
    char          szBackamtReal[21 + 1];     // �ռ�ʵʱ�����ܶ�
    char          szCalbackamt[21 + 1];      // Ԥ�ƹ��ؽ��
    char          szDueintr[21 + 1];         // ��ǰ����Ϣ
    char          szAwardamt[21 + 1];        // ��Ϣ����
    char          szAwardintr[21 + 1];       // �Ѽ���Ϣ
    char          szUncalintr[21 + 1];       // ��ǰδ����Ϣ
    char          szPayinterest[21 + 1];     // �ѻ���Ϣ
    char          szCallbackintr[21 + 1];    // ��ǰ������Ϣ
    char          szSaferate[21 + 1];        // ���շ��ձ���
    char          szRiskrate[21 + 1];        // ʵʱ���ձ���
    char          chTermtype;                // ��������
    char          szFundusetype[2 + 1];      // �ʽ���;����
    char          szFundusedo[100 + 1];      // �ʽ���;����
    char          chStatus;                  // ��Լ״̬
    char          szOrderid[10 + 1];         // ��ͬ���
    char          chRiskstatus;              // ΥԼ״̬
    char          szWarningrate[21 + 1];     // Ԥ����
    char          szLowestrate[21 + 1];      // �����
    char          szEndingrate[21 + 1];      // ��ֹ��
    char          szFundpay[21 + 1];         // Ӧ���ʽ�
    char          szPursueamt[21 + 1];       // ׷�����
    char          szPursueamtReal[21 + 1];   // ��׷�����
    char          szRemainpursueamt[21 + 1]; // ʣ��׷�����
    int           iTimes;                    // �����ڴ���
    int           iPursuedays;               // ׷������
    char          szPosstr[64 + 1];          // ��λ��
};
//-------------------------------10101597:�����Լ��Ѻ��ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeLoanContractPledgeDetailField
{
    char          szGpzysno[32 + 1]; // ��Լ���
    char          chBusikind;        // ҵ������
    char          chMarket;          // �г�����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeLoanContractPledgeDetailField
{
    char          szGpzysno[32 + 1];          // ��Լ���
    int           iItemno;                    // ���
    char          chMarket;                   // �г�����
    char          szSecuid[10 + 1];           // �ɶ�����
    char          szStkcode[8 + 1];           // ֤ȯ����
    LONGLONG      llMatchqty;                 // ��Ѻ����
    LONGLONG      llBonusqty;                 // �������
    LONGLONG      llBackqty;                  // ������������
    LONGLONG      llBackqtyReal;              // �ռ�ʵʱ��������
    char          szBonusamt[21 + 1];         // �������
    char          szBackbonusamt[21 + 1];     // �����������ܽ��
    char          szBackbonusamtReal[21 + 1]; // �ռ�ʵʱ�������
    char          chStatus;                   // ��Լ״̬
};
//-------------------------------10101598:��Ʊ��Ѻ����޸�--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeChgStkPledgeQuotaField
{
    char          szTotalamt[21 + 1]; // �ܶ��
};
struct MATRADEAPI CRspStkRpcStkPledgeChgStkPledgeQuotaField
{
    char          szTotalamt[21 + 1]; // �ܶ��
    char          szExchrate[21 + 1]; // ����ϵ��
};
//-------------------------------10101599:���ֻ�������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgePartialRepaymentApplicationField
{
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llFundid;           // �ʽ��˺�
    char          szGpzysno[32 + 1];  // ��Լ���
    int           iItemno;            // ��Լ���
    int           iOrderqty;          // ��������
    char          szOrderamt[21 + 1]; // ���ؽ��
};
struct MATRADEAPI CRspStkRpcStkPledgePartialRepaymentApplicationField
{
    int           iReqsno; // ���뵥��
};
//-------------------------------10101600:�����˶�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeLenderQuotaField
{
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // ֤ȯ�ʺ�
};
struct MATRADEAPI CRspStkQryRpcStkPledgeLenderQuotaField
{
    char          szOrgid[4 + 1];   // ��������
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szAvlamt[21 + 1]; // ʣ����ö��
    char          chStatus;         // ״̬
    char          chLoanermodel;    // ������ģʽ
};
//-------------------------------10101601:��ѯ��ԼΥԼ״̬Ϊ׷���ĺ�Լ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeAdditionalMarginContractField
{
    LONGLONG      llFundid;               // �ʽ��˺�
    char          szGpzysno[32 + 1];      // ��Լ���
    char          szBusikind[128 + 1];    // ҵ������
    char          szProducttype[128 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeAdditionalMarginContractField
{
    int           iSysdate;                  // ��Լ����
    char          szGpzysno[32 + 1];         // ��Լ���
    LONGLONG      llFundid;                  // �ʽ��ʺ�
    char          chMarket;                  // �г�����
    char          szSecuid[10 + 1];          // �ɶ�����
    char          chProducttype;             // ��Ʒ����
    int           iGhdays;                   // ����
    char          szDuerate[21 + 1];         // ������
    char          szPrerate[21 + 1];         // ��ǰ��������
    char          szContrate[21 + 1];        // ��������
    char          szPunishrate[21 + 1];      // ��Ϣ����
    int           iOldenddate;               // ��ʼ��������
    int           iEnddate;                  // ��Լ������
    char          szMatchamt[21 + 1];        // ������
    char          szBackamt[21 + 1];         // �ѻ����
    char          szBackamtReal[21 + 1];     // �ռ�ʵʱ�����ܶ�
    char          szCalbackamt[21 + 1];      // Ԥ�ƹ��ؽ��
    char          szDueintr[21 + 1];         // ��ǰ����Ϣ
    char          szPayinterest[21 + 1];     // �ѻ���Ϣ
    char          szSaferate[21 + 1];        // ���շ��ձ���
    char          chTermtype;                // ��������
    char          chStatus;                  // ��Լ״̬
    char          chRiskstatus;              // ΥԼ״̬
    char          szWarningrate[21 + 1];     // Ԥ����
    char          szLowestrate[21 + 1];      // �����
    char          szEndingrate[21 + 1];      // ��ֹ��
    char          szPursueamt[21 + 1];       // ׷�����
    char          szPursueamtReal[21 + 1];   // ��׷�����
    char          szRemainpursueamt[21 + 1]; // ʣ��׷�����
};
//-------------------------------10101602:��ѯ׷����Լ��Ҫ׷��������--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeAdditionalMarginQtyField
{
    char          szGpzysno[32 + 1]; // ��Լ���
    char          chMarket;          // �г�
    char          szStkcode[10 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcStkPledgeAdditionalMarginQtyField
{
    LONGLONG      llPursueqty; // ׷������
};
//-------------------------------10101603:����𳥻�--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeLoanPrincipalRepaymentField
{
    char          szGpzysno[32 + 1]; // ��Լ���
    char          szBackamt[21 + 1]; // �������
};
struct MATRADEAPI CRspStkRpcStkPledgeLoanPrincipalRepaymentField
{
    char          szReqsno[16 + 1]; // ���뵥��
};
//-------------------------------10101604:�����ڻ����ʽ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgeAvailableQtyForRepaymentField
{
    char          szGpzysno[32 + 1]; // ��Լ���
};
struct MATRADEAPI CRspStkQryRpcStkPledgeAvailableQtyForRepaymentField
{
    char          szCanuseamt[21 + 1];     // ��ʹ�ý��
    char          szRemainbackamt[21 + 1]; // �����ؽ��
};
//-------------------------------10101605:�ɷݲ��ֽ����Ѻ����--------------------------
struct MATRADEAPI CReqStkRpcStkPledgePartialCancellationPledgeApplicationField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szGpzysno[32 + 1]; // ��Լ���
    int           iItemno;           // ��Լ���
    int           iOrderqty;         // ��Ѻ����
};
struct MATRADEAPI CRspStkRpcStkPledgePartialCancellationPledgeApplicationField
{
    LONGLONG      llReqsno; // ���뵥��
};
//-------------------------------10101606:�ͻ����Ի��������ʲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkPledgePersonalizedInterestRateField
{
};
struct MATRADEAPI CRspStkQryRpcStkPledgePersonalizedInterestRateField
{
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llCustid;             // �ͻ�����
    char          chProducttype;        // ��Ʒ���
    int           iGhdays;              // ��Ʒ����
    char          chTermtype;           // ��������
    char          szDuerate[21 + 1];    // ������
    char          szPrerate[21 + 1];    // ��ǰ��������
    char          szContrate[21 + 1];   // ��������
    char          szPunishrate[21 + 1]; // ��Ϣ����
    int           iStartdate;           // ��ʼ����
    int           iEnddate;             // ��������
    char          szRemark[32 + 1];     // ��ע
};
//-------------------------------10101607:��Լ��Ϣ��������--------------------------
struct MATRADEAPI CReqStkRpcStkPledgeRepaymentContractInterestApplicationField
{
    char          szGpzysno[32 + 1]; // ��Լ���
    char          szBackamt[21 + 1]; // �������
};
struct MATRADEAPI CRspStkRpcStkPledgeRepaymentContractInterestApplicationField
{
    LONGLONG      llReqsno;          // ���뵥��
    char          szBackamt[21 + 1]; // ʵ�ʳ������
};
//-------------------------------10101608:Լ�����ؿͻ���Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcAgreementRepurchaseDebtContractField
{
    char          szYdghsno[32 + 1]; // ��Լ���
    char          chMarket;          // �г�����
    int           iOrderbegindate;   // ��������(��)
    int           iOrderenddate;     // ��������(ֹ)
    char          chEndflag;         // �˽����
    char          szPosstr[64 + 1];  // ��λ��
    int           iQryrec;           // ��ѯ����
};
struct MATRADEAPI CRspStkQryRpcAgreementRepurchaseDebtContractField
{
    int           iSysdate;               // ��Լ����
    char          szYdghsno[32 + 1];      // ��Լ���
    char          chMarket;               // �г�����
    char          szOrderid[10 + 1];      // ��ͬ���
    char          szMatchcode[20 + 1];    // �ɽ�����
    char          szDuerate[21 + 1];      // ������
    int           iEnddate;               // ��Լ������
    char          szMatchamt[21 + 1];     // �ɽ����
    char          szBackamt[21 + 1];      // �ѷ������
    char          szBackamtUnfrz[21 + 1]; // ��;���ؽ��
    char          szBackamtReal[21 + 1];  // �ռ乺�ؽ��
    LONGLONG      llMatchqty;             // �ɽ�����
    LONGLONG      llBonusqty;             // �������
    LONGLONG      llBackqty;              // �ѷ�������
    LONGLONG      llBackqtyUnfrz;         // ��;��������
    LONGLONG      llBackqtyReal;          // �ռ乺������
    char          szDueintr[21 + 1];      // ��ǰ����Ϣ
    char          szPayinterest[21 + 1];  // �ѻ���Ϣ
    char          szSaferate[21 + 1];     // ���ձ���
    char          szFundusedo[100 + 1];   // �ʽ���;
    char          chStatus;               // ��Լ״̬
    char          chRiskstatus;           // ΥԼ״̬
    char          szPosstr[64 + 1];       // ��λ��
};
//-------------------------------10101609:Լ�����ؿͻ���Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcAgreementRepurchaseQuotaField
{
};
struct MATRADEAPI CRspStkQryRpcAgreementRepurchaseQuotaField
{
    int           iServerid;          // ��������
    LONGLONG      llCustid;           // �ͻ�����
    char          szTotalamt[21 + 1]; // �ܶ��
    char          szAvlamt[21 + 1];   // ��ȿ���
};
//-------------------------------10101610:Լ�����س�ʼ����--------------------------
struct MATRADEAPI CReqStkRpcAgreementRepurchaseInitialTransactionField
{
    LONGLONG      iFundid;               // �ʽ��˺�
    char          szMarket[128 + 1];     // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szSecuid[10 + 1];      // �ɶ�����
    int           iOrderqty;             // ί������
    char          szOrderamt[21 + 1];    // ί�н��
    int           iGhdays;               // ��������
    char          szDuerate[21 + 1];     // �����
    char          szLinkydghsno[32 + 1]; // ������Լ���
    char          chCycleflag;           // ��Ϣ�۳���ʽ
    int           iCyclevalue;           // ��Ϣ������
    char          szFundusedo[32 + 1];   // �ʽ���;
    LONGLONG      llRisksignsno;         // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcAgreementRepurchaseInitialTransactionField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ί�ж�����
};
//-------------------------------10101611:Լ�����ع��ؽ���--------------------------
struct MATRADEAPI CReqStkRpcAgreementRepurchaseRepurchaseTransactionField
{
    LONGLONG      llFundid;          // �ʽ��˺�
    char          szYdghsno[32 + 1]; // ��Լ���
};
struct MATRADEAPI CRspStkRpcAgreementRepurchaseRepurchaseTransactionField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ί�ж�����
};
//-------------------------------10101612:Լ���������ڹ�������--------------------------
struct MATRADEAPI CReqStkRpcAgreementRepurchaseDelayedRepurchaseApplicationField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szYdghsno[32 + 1]; // ��Լ���
    int           iDelaydays;        // �ӳ�����
};
struct MATRADEAPI CRspStkRpcAgreementRepurchaseDelayedRepurchaseApplicationField
{
    int           iSno; // ������ˮ��
};
//-------------------------------10101613:ȡȨ֤��Ϣ--------------------------
struct MATRADEAPI CReqStkRpcWarrantInfoField
{
    char          chMarket;         // �����г�
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkRpcWarrantInfoField
{
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ��Ȩ����
    char          szWarrantcode[8 + 1];  // Ȩ֤����
    char          szTargetstk[8 + 1];    // ���֤ȯ����
    char          chExertype;            // ��Ȩ��ʽ
    char          chWarrantkind;         // ��Ȩ����
    char          chCleartype;           // ���㷽ʽ
    char          szExerprice[21 + 1];   // ��Ȩ�۸�
    char          szExerratio[21 + 1];   // ��Ȩ����
    char          szTotquantity[32 + 1]; // Ȩ֤��ͨ�����
    char          szClearprice[21 + 1];  // ����۸�
    int           iExpdate;              // ��������
    int           iExerbegindate;        // ��Ȩ��ʼ����
    int           iExerenddate;          // ��Ȩ��������
};
//-------------------------------10101614:�ͻ�������Ȩί��Ԥ������˰��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcExpectedIncomeTaxField
{
    LONGLONG      llCustid;           // �ͻ�����
    char          chMarket;           // �����г�
    char          chStkcode;          // ֤ȯ����
    char          szOrderqty[10 + 1]; // ί������
};
struct MATRADEAPI CRspStkQryRpcExpectedIncomeTaxField
{
    char          szIncometaxamt[21 + 1]; // Ӧ��˰���ö�
    char          szIncometax[21 + 1];    // Ӧ��˰��
};
//-------------------------------10101615:��Լ��ѯ(410983)--------------------------
struct MATRADEAPI CReqStkQryRpcContractField
{
    int           iSysdate;         // ��������
    char          szRzsno[64 + 1];  // ��Լ���
    char          szMarket[32 + 1]; // �г�
    LONGLONG      llFundid;         // �ʽ��˻�
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          chStatus;         // ��Լ״̬
    int           iEnddate;         // ��������
    int           iClosedate;       // �˽�����
};
struct MATRADEAPI CRspStkQryRpcContractField
{
    int           iSysdate;                  // ��������
    char          szRzsno[64 + 1];           // ��Լ���
    char          szOrgid[4 + 1];            // ��������
    LONGLONG      llCustid;                  // �ͻ�����
    char          szCustname[32 + 1];        // �ͻ�����
    LONGLONG      llFundid;                  // �ʽ��˻�
    char          chMoneytype;               // ����
    char          chMarket;                  // �г�
    char          szSeat[6 + 1];             // ϯλ
    char          szSecuid[10 + 1];          // �ɶ��˻�
    char          szOrderid[10 + 1];         // ί�����
    char          szStkcode[8 + 1];          // ֤ȯ����
    char          szStkname[64 + 1];         // ֤ȯ����
    char          szTargetstk[8 + 1];        // ���֤ȯ
    char          szOrderprice[21 + 1];      // ί�м۸�
    LONGLONG      llConqty;                  // ��Ȩ����
    char          szConamt[21 + 1];          // ��Ȩ���
    char          szPayconamt[21 + 1];       // �ѹ黹����
    char          szPayconamtReal[21 + 1];   // ʵʱ�黹����
    char          szTaxamt[21 + 1];          // ��˰���
    char          szPaytaxamt[21 + 1];       // �ѻ���˰���
    char          szPaytaxamtReal[21 + 1];   // ʵʱ�黹��˰���
    int           iIntcaldate;               // �ϴμ�Ϣ����
    char          szDuerate[21 + 1];         // ��Ϣ������
    char          szDueintr[21 + 1];         // Ӧ����Ϣ
    char          szPaydueintr[21 + 1];      // �ѻ���Ϣ
    char          szPaydueintrReal[21 + 1];  // ʵʱ�黹��Ϣ
    char          szPunirate[21 + 1];        // ΥԼ������
    char          szPuniintr[21 + 1];        // Ӧ��ΥԼ��
    char          szPaypuniintr[21 + 1];     // �ѻ�ΥԼ��
    char          szPaypuniintrReal[21 + 1]; // ʵʱ�黹ΥԼ��
    int           iEnddate;                  // ��������
    int           iClosedate;                // �˽�����
    char          chStatus;                  // ��Լ״̬
    char          szRzdebt[21 + 1];          // �ͻ��賥����ծ
    char          szRemark[64 + 1];          // ��ע
};
//-------------------------------10101616:������Ȩί�в�ѯ(410989)--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingRightCommissionField
{
    int           iBegindate;         // ��ʼ����
    int           iEnddate;           // ��������
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llFundid;           // �ʽ��˻�
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    char          szStkcode[6 + 1];   // ֤ȯ����
    char          szBsflag[2 + 1];    // �������
    char          szBsflagSub[2 + 1]; // ��Ȩ����
    char          chCancelflag;       // ������ʶ
    char          chOrderstatus;      // ί��״̬
    char          szPosstr[64 + 1];   // ��λ��
    int           iQryrec;            // ��������
};
struct MATRADEAPI CRspStkQryRpcFinancingRightCommissionField
{
    int           iOrdersno;              // ί�����
    int           iOrdergroup;            // ����ί������
    int           iOrdertime;             // ����ί��ʱ��
    LONGLONG      llCustid;               // �ͻ�����
    char          szCustname[16 + 1];     // �ͻ�����
    char          szOrgid[4 + 1];         // ��֧����
    char          szBrhid[4 + 1];         // ������֧
    LONGLONG      llFundid;               // �ʲ��ʻ�
    char          chMoneytype;            // ���Ҵ���
    char          chFundkind;             // �ʽ����
    char          chFundlevel;            // �ʽ𼶱�
    char          chFundgroup;            // �ʽ����
    char          szSeat[6 + 1];          // ����ϯλ
    char          chMarket;               // �����г�
    char          szTargetstk[6 + 1];     // ���֤ȯ
    char          chChannel;              // ͨ����
    char          szStkname[64 + 1];      // ֤ȯ����
    char          chStktype;              // ֤ȯ���
    int           iCancelqty;             // ��������
    char          szOrderfrzamt[21 + 1];  // ί�ж�����
    char          szTaxamt[21 + 1];       // ����ί�ж�������˰
    char          szBsflag[2 + 1];        // ��������
    char          szBsflagSub[2 + 1];     // ��Ȩ����
    char          chCancelflag;           // ������־'F'
    char          chOrderstatus;          // ί��״̬
    char          szOldorderid[10 + 1];   // �������
    int           iOperid;                // ������Ա����
    char          szNetaddr[64 + 1];      // ����վ��
    char          chOperway;              // ������ʽ
    char          szRemark[128 + 1];      // ������ע
    char          szClearmainseat[6 + 1]; // �ǽ����걨������ϯλ,fjybs.bszjjs
    char          szBsywlb[2 + 1];        // �걨ҵ�����,fjybs.bsywlb
    char          chBswtlx;               // ����ί������,fjybs.bswtlx,'S'�걨,'C'����
    char          szOrderid[10 + 1];      // ���ͺ�ͬ���,fjybs.bswtxh
    char          szStkcode[6 + 1];       // ֤ȯ����
    char          szSecuid[10 + 1];       // �ɶ�����
    char          szBsxwdm[6 + 1];        // ����ϯλ����
    char          szBsywsj[32 + 1];       // ����ҵ������
    char          szBsgfxz[2 + 1];        // ���͹ɷ�����
    int           iOrderqty;              // ί������
    char          szOrderamt[21 + 1];     // ί�н��
    char          szOrderprice[21 + 1];   // ί�м۸�
    char          chBsbz1;                // ���ͱ�ʶ1
    char          chBsbz2;                // ���ͱ�ʶ2
    char          szBsdfxw[6 + 1];        // ���ͶԷ�ϯλ
    char          szBsdfgd[10 + 1];       // ���ͶԷ��ɶ�
    char          szBsdfxz[2 + 1];        // ���ͶԷ�����
    char          szBsnr1[64 + 1];        // ��������1
    char          szBsnr2[128 + 1];       // ��������2
    int           iOrderdate;             // ί�н�������
    int           iReporttime;            // ����ʱ��
    char          chBsclbz;               // ���ʹ�����ʶ
    char          chBsbyzd;               // ���ͱ����ֶ�
};
//-------------------------------10101617:��Ȩ������Ա��Ϣ��ѯ��410990��--------------------------
struct MATRADEAPI CReqStkQryRpcEquityIncentivePersonnelInfoField
{
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    char          szStkcode[6 + 1];   // ��Ȩ����
    char          szTargetstk[6 + 1]; // ���ȯ����
};
struct MATRADEAPI CRspStkQryRpcEquityIncentivePersonnelInfoField
{
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szTargetstk[6 + 1];  // ���ȯ����
    char          szStkcode[6 + 1];    // ��Ȩ����
    LONGLONG      llCustid;            // �ͻ�����
    char          szCuatname[16 + 1];  // �ͻ�����
    char          chCusttype;          // �ͻ����
    int           iProratetime;        // ��������
    int           iWarBegindate;       // �����ڿ�ʼ
    int           iWarEnddate;         // �����ڽ���
    char          chProctax;           // �Ƿ�������˰
    char          szBegcaitax[21 + 1]; // ����˰�������
    char          chFrzstatus;         // �Ƿ񶳽���ȯ
    char          chStatus;            // ״̬
};
//-------------------------------10101618:������Ȩ������Ϣ��ѯ��410991��--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingExerciseParamsField
{
    char          chCusttype;       // �ͻ����
};
struct MATRADEAPI CRspStkQryRpcFinancingExerciseParamsField
{
    char          chCusttype;             // �ͻ�����
    int           iContractdate;          // ��������
    char          szStdrate[21 + 1];      // ��׼��������(��)
    char          szFinerate[21 + 1];     // ΥԼ����(��)
    char          szMaxlimit[21 + 1];     // ���ʶ������(Ԫ)
    char          szTranrate[21 + 1];     // ��Լ����������ȡ��
    char          szWarnrate[21 + 1];     // ��Լ��������������
    char          szCloserate[21 + 1];    // ��Լ��������ƽ����
    char          szWarnrateSub[21 + 1];  // ������Լ��������������
    char          szCloserateSub[21 + 1]; // ������Լ��������ƽ����
    char          szSaferate[21 + 1];     // ��Լ����������ȫ��
    char          szRemark[64 + 1];       // ��ע
};
//-------------------------------10101619:������Ȩ�ʲ���ծ��ѯ��410992��--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingExerciseAssetsLiabilityField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��˺�
};
struct MATRADEAPI CRspStkQryRpcFinancingExerciseAssetsLiabilityField
{
    char          szAsset[21 + 1];           // �����ʲ�
    char          szDebt[21 + 1];            // �ܸ�ծ
    char          szMktval[21 + 1];          // ����֤ȯ��ֵ
    char          szKeeprate[21 + 1];        // ��Լ��������
    char          szKeeprateSub[21 + 1];     // ������Լ��������
    char          szTranrate[21 + 1];        // ��Լ����������ȡ��
    char          szWarnrate[21 + 1];        // ��Լ��������������
    char          szCloserate[21 + 1];       // ��Լ��������ƽ����
    char          szDueintr[21 + 1];         // ��Ϣ
    char          szPuniintr[21 + 1];        // ΥԼ��
    char          szTaxamt[21 + 1];          // ��˰
    char          szStdrate[21 + 1];         // ��������
    char          szConamt[21 + 1];          // ���ʱ���
    char          szCustbondamt[21 + 1];     // �������Ŷ��
    char          szCustlimitremain[21 + 1]; // ���ʿ��ö��
    char          szCanrepaydebt[21 + 1];    // �ͻ��ɻ���ծ
    char          szRepayamt[21 + 1];        // ʵʱ������
};
//-------------------------------10101620:������Ȩ�ͻ������Ϣ��ѯ��410993��--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingExerciseCustQuotaInfoField
{
};
struct MATRADEAPI CRspStkQryRpcFinancingExerciseCustQuotaInfoField
{
    LONGLONG      llCustid;                  // �ͻ�����
    char          szCustname[16 + 1];        // �ͻ�����
    char          szCustbondamt[21 + 1];     // �ͻ����Ŷ��
    char          szCustusedamt[21 + 1];     // �ͻ����ö��
    char          szCustusedamtReal[21 + 1]; // �ͻ�ʵʱ���ö��
    char          szCustfinrate[21 + 1];     // ���õȼ�����ϵ��
    char          szCanrepaydebt[21 + 1];    // �ͻ��ɻ���ծ
    char          szRepayamt[21 + 1];        // ʵʱ������
};
//-------------------------------10101621:ֱ�ӻ���(410984)--------------------------
struct MATRADEAPI CReqStkRpcDirectRepaymentField
{
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��˻�
    char          chMoneytype;         // ����
    char          szReturnamt[21 + 1]; // ������
};
struct MATRADEAPI CRspStkRpcDirectRepaymentField
{
    char          szFundeffect[21 + 1]; // ���������
};
//-------------------------------10101622:������Ȩҵ��(410985)--------------------------
struct MATRADEAPI CReqStkRpcFinancingExerciseBizField
{
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    LONGLONG      llFundid;           // �ʽ��˻�
    char          szOrgid[4 + 1];     // ��������
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szBsflag[2 + 1];    // �������
    char          szBsflagSub[2 + 1]; // ��Ȩ����
    LONGLONG      llOrderqty;         // ����
    LONGLONG      llRisksignsno;      // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcFinancingExerciseBizField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
};
//-------------------------------10101623:ȡ������Ȩ��ί������(410986)--------------------------
struct MATRADEAPI CReqStkRpcFinancingExerciseMaxOrderQtyField
{
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    LONGLONG      llFundid;           // �ʽ��˻�
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szBsflag[2 + 1];    // �������
    char          szBsflagSub[2 + 1]; // ��Ȩ����
};
struct MATRADEAPI CRspStkRpcFinancingExerciseMaxOrderQtyField
{
    LONGLONG      llOrderqty; // �ɷ�����
};
//-------------------------------10101624:������Ȩί�г���(410987)--------------------------
struct MATRADEAPI CReqStkRpcFinancingExerciseCancelField
{
    int           iOrderdate;       // ί������
    int           iOrdersno;        // ί�����
    int           iOrdergroup;      // ί������
};
struct MATRADEAPI CRspStkRpcFinancingExerciseCancelField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
};
//-------------------------------10101625:������Ȩ����֤ȯ��ѯ(410988)--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingExerciseGuaranteedSecurityInfoField
{
};
struct MATRADEAPI CRspStkQryRpcFinancingExerciseGuaranteedSecurityInfoField
{
    char          chMarket;             // �����г�
    char          szStkcode[10 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szPledgerate[21 + 1]; // ������
};
//-------------------------------10101626:ETF�ɷݹ��嵥��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcETFStkListField
{
    char          chMarket;         // �����г�
    char          szOfcode[8 + 1];  // ETF�������
    char          szStkcode[8 + 1]; // �ɷݹɴ���
    char          chStkmarket;      // �ɷݹɽ����г�
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcETFStkListField
{
    char          szPosstr[64 + 1];        // ��λ��
    int           iServerid;               // �ڵ���
    char          chMarket;                // �����г�
    char          szOfcode[8 + 1];         // ETF�������
    char          szOfname[16 + 1];        // ETF��������
    char          szStkcode[8 + 1];        // �ɷݹɴ���
    char          szStkname[64 + 1];       // �ɷݹɼ��
    char          chStkmarket;             // �ɷݹɽ����г�
    char          szStkmic[4 + 1];         // �ɷݹ��г���ʶ��
    int           iAmount;                 // ��Ʊ����
    char          chReplaceflag;           // �����־
    char          szOverpricerate[21 + 1]; // ��۱���
    char          szReplaceamtSg[21 + 1];  // �깺������
    char          szReplaceamtSh[21 + 1];  // ���������
    int           iIBy;                    // ����
    char          szCBy[8 + 1];            // ����
    char          szRemark[32 + 1];        // ��ע
};
//-------------------------------10101627:ETF�����Ϲ����루�ֽ��Ϲ�����Ʊ�Ϲ���--------------------------
struct MATRADEAPI CReqStkRpcETFOfflineApplicationField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szOfcode[8 + 1];      // �����Ϲ�����
    char          szBsflag[2 + 1];      // �Ϲ�����
    char          szStkcode[8 + 1];     // ��Ʊ����
    int           iOrderqty;            // ί������
    char          chSecumarket;         // �ɷݹ��г�
    char          chLinkmarket;         // �����г�
    char          szLinksecuid[20 + 1]; // �����ɶ�
    LONGLONG      llRisksignsno;        // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcETFOfflineApplicationField
{
    int           iSno;                 // �������
    char          szFundeffect[21 + 1]; // �������
};
//-------------------------------10101628:ETF�����Ϲ����볷��--------------------------
struct MATRADEAPI CReqStkRpcETFOfflineApplicationCancelField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iSysdate;         // ����ʱϵͳ����
    int           iSno;             // �������
};
struct MATRADEAPI CRspStkRpcETFOfflineApplicationCancelField
{
    int           iSno;                // �������
    char          szErrormsg[128 + 1]; // ������Ϣ
};
//-------------------------------10101629:ETF�����Ϲ������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcETFOfflineApplicationField
{
    int           iSysdate;             // ϵͳ����
    int           iSno;                 // �������
    char          szMarket[32 + 1];     // �����г�
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szOfcode[8 + 1];      // �����Ϲ�����
    char          szBsflag[32 + 1];     // �Ϲ�����
    char          szCancelflag[32 + 1]; // ������ʶ
    char          szStatus[32 + 1];     // ״̬
};
struct MATRADEAPI CRspStkQryRpcETFOfflineApplicationField
{
    int           iSysdate;                 // ϵͳ����
    int           iSno;                     // �������
    int           iOperdate;                // ������������
    int           iOpertime;                // ��������ʱ��
    char          szOfcode[8 + 1];          // ��׼�������
    char          szOfname[20 + 1];         // ��׼��������
    char          chMoneytype;              // ����
    char          chSecumarket;             // �ɶ��г�
    char          szSecuid[10 + 1];         // �ɶ�
    char          chMarket;                 // �����г�
    char          szStkcode[8 + 1];         // �����Ϲ�����
    char          szStkname[64 + 1];        // �����Ϲ���������
    char          chInputbsflag;            // �Ϲ�����
    int           iOrderqty;                // ί������
    char          szOrderfrzamt[21 + 1];    // ί�ж�����
    char          szCommissionrate[21 + 1]; // ���ñ���
    char          szBillfee[21 + 1];        // ����
    char          chCancelflag;             // ������ʶ
    char          chStatus;                 // ����״̬
    char          szFrzcode[10 + 1];        // �ɷ��Ϲ��������
    char          szFrzname[8 + 1];         // �ɷ��Ϲ������������
    int           iOrderdate;               // �깺ί������
    int           iOrdersno;                // �깺ί��ί�����
};
//-------------------------------10101630:����LOF����ֲ�ϲ���Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzLOFFundSplitMergeField
{
    char          chMarket;                 // �г�
    char          szStkcode[6 + 1];         // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcSzLOFFundSplitMergeField
{
    char          chMarket;                 // �г�
    char          szStkcode[6 + 1];         // ֤ȯ����
    char          szStkname[64 + 1];        // ֤ȯ����
    char          szMststkcode[6 + 1];      // ĸ����֤ȯ����
    char          szMststkname[64 + 1];     // ĸ����֤ȯ����
    char          chStatus;                 // �ֲ�ϲ�״̬
    char          szComrate[21 + 1];        // ��ϱ���
    int           iUnitcomqty;              // ��С�ϲ���λ
    int           iUnitsegqty;              // ��С�ֲ�λ
    int           iMincomqty;               // ��ͺϲ�����
    int           iMinsegqty;               // ��ͷֲ�����
    LONGLONG      llMaxcomqty;              // ��ߺϲ�����
    LONGLONG      llMaxsegqty;              // ��߷ֲ�����
};
//-------------------------------10101631:�Ϻ�LOF����ֲ�ϲ���Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcShLOFFundSplitMergeField
{
    char          chMarket;                 // �г�
    char          szStkcode[6 + 1];         // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcShLOFFundSplitMergeField
{
    char          chMarket;                 // �г�
    char          szStkcode[6 + 1];         // ֤ȯ����
    char          szStkname[64 + 1];        // ֤ȯ����
    char          szMststkcode[6 + 1];      // ĸ����֤ȯ����
    char          szMststkname[64 + 1];     // ĸ����֤ȯ����
    char          szBusistatus[8 + 1];      // �ֲ�ϲ�״̬
    int           iCoefficient;             // ת��ϵ��
    int           iUnitqty;                 // �ֲ�ϲ�������
    int           iMincomqty;               // ��ͺϲ�����
    int           iMinsegqty;               // ��ͷֲ�����
};
//-------------------------------10101632:�̺����ֲ�/�ϲ����������깺��õ��Ľ���ֵ--------------------------
struct MATRADEAPI CReqStkRpcAfterCloseFundSplitMergeRecommendedValueField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          szBsflag[2 + 1];  // �������
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkRpcAfterCloseFundSplitMergeRecommendedValueField
{
    LONGLONG      llAdviceqty; // �ɷ�����
    char          chIsmccust;  // ä��ͻ�
};
//-------------------------------10101633:��ѯ�ͻ���ծԤ���гֲ���ϸ--------------------------
struct MATRADEAPI CReqStkQryRpcTreasuryBondsPreIssuePosiField
{
    char          chMarket;         // �г�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iTrddate;         // ��������
    char          szPosstr[32 + 1]; // ��λ��
    int           iCount;           // ��������
};
struct MATRADEAPI CRspStkQryRpcTreasuryBondsPreIssuePosiField
{
    char          szPosstr[32 + 1];        // ��λ��
    int           iServerid;               // ��������
    int           iTrddate;                // ��������
    char          szOrderid[10 + 1];       // ��ͬ���
    LONGLONG      llCustid;                // �ͻ�����
    char          chMoneytype;             // ���Ҵ���
    LONGLONG      llFundid;                // �ʽ��˺�
    char          szSecuid[10 + 1];        // �ɶ�����
    int           iMatchtime;              // �ɽ�ʱ��
    char          szMatchcode[32 + 1];     // �ɽ����
    char          chMarket;                // �г�����
    char          szStkcode[8 + 1];        // ֤ȯ����
    LONGLONG      llPosiqty;               // ԭʼ�ֲ�����
    LONGLONG      llLastcloseqty;          // ǰƽ���ۼ�����
    LONGLONG      llRealcloseqty;          // ʵʱƽ���ۼ�����
    LONGLONG      llDaycloseqty;           // ����ƽ���ۼ�����
    LONGLONG      llRemianposiqty;         // ʣ��ֲ�����
    char          szPosiprice[21 + 1];     // �ֲּ۸�
    char          szDeposit[21 + 1];       // ��Լ��֤��
    char          szRemaindeposit[21 + 1]; // ʣ����Լ��֤��
    char          szMarginamt[21 + 1];     // �۲֤���ۼ�
    char          szCustrate[21 + 1];      // ԭʼ��Լ�����
};
//-------------------------------10101634:��ѯ�ͻ���ծԤ����ƽ����ϸ--------------------------
struct MATRADEAPI CReqStkQryRpcTreasuryBondsPreIssueClosePosiField
{
    char          chMarket;         // �г�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iClosedate;       // ƽ������
    char          szPosstr[64 + 1]; // ��λ��
    int           iCount;           // ��������
};
struct MATRADEAPI CRspStkQryRpcTreasuryBondsPreIssueClosePosiField
{
    char          szPosstr[32 + 1];       // ��λ��
    int           iServerid;              // ��������
    char          szOrgid[4 + 1];         // ��������
    int           iOpendate;              // ��������
    char          szOrderid[10 + 1];      // ���ֺ�ͬ���
    LONGLONG      llCustid;               // �ͻ���
    char          chMoneytype;            // ��������
    LONGLONG      llFundid;               // �ʽ��˺�
    char          szSecuid[10 + 1];       // �ɶ�����
    char          szMatchcode[32 + 1];    // ���ֳɽ����
    char          chMarket;               // �г�����
    char          szStkcode[8 + 1];       // ֤ȯ����
    int           iClosedate;             // ƽ������
    char          szCloseorderid[16 + 1]; // ƽ�ֺ�ͬ���
    char          szClosecode[32 + 1];    // ƽ�ֳɽ����
    LONGLONG      llCloseqty;             // ƽ������
    char          szCloseprice[21 + 1];   // ƽ�ּ۸�
    char          szBackdeposit[21 + 1];  // ������Լ��֤��
    char          szMarginamt[21 + 1];    // �۲֤��
    char          szProfitamt[21 + 1];    // ������
};
//-------------------------------10101635:��ѯ�ͻ���ծԤ����Ӧ����Լ����ϸ--------------------------
struct MATRADEAPI CReqStkQryRpcTreasuryBondsPreIssuePerformanceBondField
{
    LONGLONG      llFundid;         // �ʲ��˻�
    char          chMarket;         // �г�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szPosstr[64 + 1]; // ��λ��
    int           iCount;           // ��������
};
struct MATRADEAPI CRspStkQryRpcTreasuryBondsPreIssuePerformanceBondField
{
    char          szPosstr[32 + 1];     // ��λ��
    int           iServerid;            // ��������
    char          szOrgid[4 + 1];       // ��������
    char          chMarket;             // �г�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    int           iFundid;              // �ʲ��˻�
    char          szOrderid[10 + 1];    // ��Լ��
    char          chInvitebids;         // �б귽ʽ
    int           iRemainposiqty;       // �ֲ�����
    char          szPaymentamt[21 + 1]; // Ӧ֧����Լ��
};
//-------------------------------10101636:����ͶƱ�ɶ������Ϣ��ѯ(440001)--------------------------
struct MATRADEAPI CReqStkQryRpcNetworkVotingTrdacctsConferenceInfoField
{
    char          chMarket;             // �г�
    char          szCompanycode[8 + 1]; // ��˾����
    char          szVotecode[8 + 1];    // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcNetworkVotingTrdacctsConferenceInfoField
{
    char          szCompanycode[8 + 1];      // ��˾����
    char          szCompanyinfo[64 + 1];     // ��˾���
    char          szMeetingdatebegin[8 + 1]; // �ɶ���Ὺʼ��
    char          szMeetingdateend[8 + 1];   // �ɶ���������
    char          szMeetingtype[4 + 1];      // �ɶ��������
    char          szMeetingdesc[500 + 1];    // �ɶ��������
    char          chTpmarket;                // ͶƱ�г�
    char          szMeetingseq[10 + 1];      // �ɶ�������
    char          chMarket;                  // �����г�
    char          szVotecode[8 + 1];         // ��Ʒ����
    char          szSabbr[64 + 1];           // ��Ʊ���
    char          szStype[24 + 1];           // �ɷ����
    char          szRegdate[8 + 1];          // ��Ȩ�Ǽ���
    char          szLasttradedate[8 + 1];    // �������
};
//-------------------------------10101637:����ͶƱ�鰸��Ϣ��ѯ(440002)--------------------------
struct MATRADEAPI CReqStkQryRpcNetworkVotingMotionInfoField
{
    char          chTpmarket;        // ͶƱ�г�
    char          chMeetingseq;      // �ɶ�������
    char          szVid[10 + 1];     // �鰸���
    char          szVotecode[8 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcNetworkVotingMotionInfoField
{
    char          chTpmarket;           // ͶƱ�г�
    char          szMeetingseq[10 + 1]; // �ɶ�������
    char          szVid[10 + 1];        // �鰸���
    char          szVinfo[1024 + 1];    // �鰸����
    char          szVtype[4 + 1];       // �鰸����
    char          szVleijino[4 + 1];    // �ۻ�ͶƱӦѡ��
    char          szVrole[50 + 1];      // �ɶ�����
    char          szVrelation[100 + 1]; // �鰸��ϵ
    char          szRefcode[255 + 1];   // ͶƱ��Ʒ����ָ��
};
//-------------------------------10101638:����ͶƱ�����ѯ(440003)--------------------------
struct MATRADEAPI CReqStkQryRpcNetworkVotingResultField
{
    char          chQueryflag;       // ��ѯ��ʶ
    int           iBegindate;        // �鵵��ʼ����
    int           iEnddate;          // �鵵��������
    char          chTpmarket;        // ͶƱ�г�
    char          chMeetingseq;      // �ɶ�������
    char          szVid[10 + 1];     // �鰸���
    char          chMarket;          // �г�
    char          szVotecode[8 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcNetworkVotingResultField
{
    char          chTpmarket;        // ͶƱ�г�
    char          chMeetingseq;      // �ɶ�������
    LONGLONG      llCustid;          // �ͻ�����
    char          chMarket;          // �г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szVotecode[8 + 1]; // ��Ʒ����
    LONGLONG      llVoteagree;       // �޳�
    LONGLONG      llVoteagainst;     // ����
    LONGLONG      llVotecancel;      // ��Ȩ
    char          szVid[10 + 1];     // �鰸���
    char          szVinfo[100 + 1];  // �鰸����
    char          szVtype[4 + 1];    // �鰸����
};
//-------------------------------10101639:����ͶƱ(440101)--------------------------
struct MATRADEAPI CReqStkRpcNetworkVotingField
{
    LONGLONG      llFundid;         // �ʽ��˻�
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chTpmarket;       // ͶƱ�г�
    char          chMeetingseq;     // �ɶ�������
    char          chVid;            // �鰸���
    LONGLONG      llQty;            // ͶƱ����
    char          chResult;         // ͶƱ���
    int           iOrdergroup;      // ί������
};
struct MATRADEAPI CRspStkRpcNetworkVotingField
{
};
//-------------------------------10101640:����ͶƱί�в�ѯ(440103)--------------------------
struct MATRADEAPI CReqStkQryRpcNetworkVotingField
{
    int           iBegindate;       // ��ʼ����
    int           iEnddate;         // ��������
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chTpmarket;       // ͶƱ�г�
    char          chMeetingseq;     // �ɶ�������
    char          szVid[10 + 1];    // �鰸���
};
struct MATRADEAPI CRspStkQryRpcNetworkVotingField
{
    int           iOrdersno;            // ί�����
    int           iOrdergroup;          // ����ί������
    char          szOrderid[10 + 1];    // �걨��ͬ���
    int           iOrderdate;           // ί�н�������
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��֧����
    char          szBrhid[4 + 1];       // ������֧
    LONGLONG      llFundid;             // �ʲ��ʻ�
    char          chMoneytype;          // ���Ҵ���
    char          szSecuid[10 + 1];     // �ɶ�����
    char          chMarket;             // �����г�
    char          szSeat[6 + 1];        // ����ϯλ
    char          chChannel;            // ͨ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          chStktype;            // ֤ȯ���
    char          szBsflag[2 + 1];      // ��������
    char          chTpmarket;           // ͶƱ�г�
    char          szMeetingseq[12 + 1]; // �ɶ�������
    char          szVid[12 + 1];        // ͶƱ�鰸���
    char          chVoteresult;         // ͶƱ���
    LONGLONG      llVoteqty;            // ͶƱ����
    char          szSegment[4 + 1];     // �ֶ�ͳ�ƶκ�
    LONGLONG      llLongqty;            // �ܹɷ�������
    int           iReporttime;          // �걨ʱ��
    char          chOrderstatus;        // ί��״̬
    char          chSendstatus;         // ����״̬
    char          szRemark[128 + 1];    // ������ע
};
//-------------------------------10101641:��׼ȯ���ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStdBondSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcStdBondSummaryField
{
    char          szPoststr[32 + 1];  // ��λ��
    int           iServerid;          // �ڵ���
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llCustid;           // �ͻ�����
    LONGLONG      llFundid;           // �ʽ��˻�
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          chStktype;          // ֤ȯ���
    char          chMoneytype;        // ���Ҵ���
    char          szExchrate[21 + 1]; // ������
    LONGLONG      llBondassetavl;     // ��Ѻȯ����
    LONGLONG      llBondunfrz;        // ��׼ȯ�ⶳ
    LONGLONG      llBondfrz;          // ��׼ȯ����
    LONGLONG      llRemainqty;        // ��׼ȯ����
};
//-------------------------------10101642:��Ѻ���׼ȯ��ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcPledgeBankStdBondDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcPledgeBankStdBondDetailField
{
    char          szPoststr[32 + 1]; // ��λ��
    char          szOrgid[4 + 1];    // ��������
};
//-------------------------------10101643:�ع��ʽ�ռ��������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcRepurchaseFundOccupancyDaysField
{
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chMarket;         // �г�����
};
struct MATRADEAPI CRspStkQryRpcRepurchaseFundOccupancyDaysField
{
    int           iJxdays;      // ��Ϣ����
    int           iJxbegindate; // ��ʼ��������
};
//-------------------------------10101644:δ���ڻع���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcUndueRepurchaseField
{
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chDatetype;        // ��������
    int           iBegindate;        // ��ʼ����
    int           iEnddate;          // ��������
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcUndueRepurchaseField
{
    char          szPoststr[32 + 1];    // ��λ��
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��˺�
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          chMoneytype;          // ����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szSeat[6 + 1];        // ����ϯλ
    char          szSecuid[10 + 1];     // �ɶ�����
    int           iOrderdate;           // ί������
    int           iMatchdate;           // ��������
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szMatchcode[20 + 1];  // �ɽ�����
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iOrderqty;            // ί������
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szClearedamt[21 + 1]; // ���ؽ��
    char          szBrhid[4 + 1];       // ������֧
    char          chStktype;            // ֤ȯ���
    char          szBsflag[2 + 1];      // �������
    char          chTrdid;              // ��������
    char          szBusitype[4 + 1];    // ҵ�����
    char          chOperway;            // ������ʽ
    char          chStatus;             // ״̬
    char          szFeeSxf[21 + 1];     // ���ؽ���Ӷ��
    char          chBreakflag;          // ΥԼ��־
    char          szDiscratio[21 + 1];  // �ۿ۱���
    int           iBbMatchdate;         // �ʽ�ռ������
};
//-------------------------------10101645:�ͻ����ʻع����ղ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFinancingRepurchaseRiskField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          chMoneytype;      // ���Ҵ���
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkQryRpcFinancingRepurchaseRiskField
{
    char          szOrgid[4 + 1];           // ��������
    char          szBrhid[4 + 1];           // ��֧����
    LONGLONG      llFundid;                 // �ʽ��˺�
    LONGLONG      llCustid;                 // �ͻ�����
    char          chMarket;                 // �����г�
    char          chMoneytype;              // ���Ҵ���
    char          szSecuid[10 + 1];         // ֤ȯ�˺�
    char          szRate[21 + 1];           // ��׼ȯʹ�ñ���
    char          szScale[21 + 1];          // ���ʷŴ���
    char          szBondbal[21 + 1];        // ������Ѻ����
    char          szRemainqty[21 + 1];      // ��׼ȯ���
    char          szClearmat[21 + 1];       // δ���ڻع��ʽ�
    char          szFundassettotal[21 + 1]; // �ͻ����ʲ�(���ʲ����ͻ�����ͳ�ƣ������ʽ��ʺ�ͳ��)
    char          szMaxamtRz[21 + 1];       // ���������ʽ��
    LONGLONG      llMaxamtCk;               // �����ٳ�������
    char          szMaxamtZc[21 + 1];       // ������ת�����
};
//-------------------------------10101646:��ѯ�ͻ����ۻع�Ʒ����Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcShQuoteRepurchaseProductInfoField
{
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          chMarket;           // �����г�
    char          szProdcode[12 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcShQuoteRepurchaseProductInfoField
{
    char          chMarket;                   // �����г�
    char          szStkcode[8 + 1];           // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    char          szProdcode[12 + 1];         // ��Ʒ����
    char          szProdname[64 + 1];         // ��Ʒ����
    int           iGhDays;                    // ����(��)
    int           iBuyunit;                   // ���׵�λ(��)
    int           iMinqty;                    // �����������
    char          szLastrate[21 + 1];         // ���µ���������
    char          szCallrate[21 + 1];         // ������ǰ��ֹ������
    char          szMaxbondamt[21 + 1];       // �ܶ��
    char          szBondbalamt[21 + 1];       // ������
    char          szBondavlamt[21 + 1];       // ���ö��
    LONGLONG      llLastcontract;             // ����δ����
    LONGLONG      llBondbackbal;              // ������ȯ��ת������
    LONGLONG      llBondbrk;                  // �����ۼ���ֹ
    LONGLONG      llBondbrkunfrz;             // �����ۼ���ֹ�ɽ�
    char          chAutobuyflag;              // �Զ�չ�ڱ�־
    char          chBuyflag;                  // ���ױ�־
    int           iContmaxdays;               // ���չ������
    char          szMinprebookbrkamt[21 + 1]; // ԤԼ���ض�����
    char          szRemark[128 + 1];          // ��ע��Ϣ
};
//-------------------------------10101647:��ǰ����--------------------------
struct MATRADEAPI CReqStkRpcShQuoteRepurchaseAdvanceRepurchaseField
{
    char          chMarket;            // �����г�
    LONGLONG      llFundid;            // �ʽ��ʻ�
    int           iBrkqty;             // ��ǰ��ֹ����
    int           iMatchdate;          // �ɽ�����
    char          szMatchcode[32 + 1]; // �ɽ����
    char          chAction;            // ������־
};
struct MATRADEAPI CRspStkRpcShQuoteRepurchaseAdvanceRepurchaseField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101648:���ۻع�ԤԼ--------------------------
struct MATRADEAPI CReqStkRpcShQuoteRepurchaseReservationField
{
    LONGLONG      llFundid;            // �ʽ��ʻ�
    char          chMarket;            // �����г�
    int           iMatchdate;          // �ɽ�����
    char          szMatchcode[32 + 1]; // �ɽ����
    int           iExecdate;           // ִ������
    char          chAction;            // ��������
    LONGLONG      llMatchqty;          // ί������
};
struct MATRADEAPI CRspStkRpcShQuoteRepurchaseReservationField
{
    int           iSno; // ������ˮ��
};
//-------------------------------10101649:���ۻع�ԤԼ��ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcShQuoteRepurchaseReservationStatementField
{
    LONGLONG      llFundid;            // �ʽ��˺�
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];  // ��Ʒ����
    char          chMoneytype;         // ���Ҵ���
    char          szMatchcode[32 + 1]; // �ɽ����
    char          chDatetype;          // ��������
    int           iBegindate;          // ��ʼ����
    int           iEnddate;            // ��������
    int           iCount;              // ��������
    char          szPosstr[64 + 1];    // ��λ��
};
struct MATRADEAPI CRspStkQryRpcShQuoteRepurchaseReservationStatementField
{
    char          szPosstr[64 + 1];     // ��λ��
    int           iServerid;            // �ڵ���
    int           iSysdate;             // ϵͳ����
    int           iSno;                 // ��ˮ��
    int           iOperdate;            // ����ԤԼ����
    int           iOpertime;            // ����ԤԼʱ��
    int           iExecdate;            // ��ǰ��ִֹ������
    char          szOrgid[4 + 1];       // ��������
    char          szBrhid[4 + 1];       // ��֧����
    LONGLONG      llFundid;             // �ʽ��˺�
    LONGLONG      llCustid;             // �ͻ�����
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // ֤ȯ�˺�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          chMoneytype;          // ���Ҵ���
    LONGLONG      llMatchqty;           // ��ǰ��ֹ����
    char          szMatchamt[21 + 1];   // ��ǰ��ֹ���
    char          szPrebookamt[21 + 1]; // ԤԼ��ȱ������
    int           iMatchdate;           // �ع���Ч����
    char          szMatchcode[32 + 1];  // �ع��ɽ����
    char          szRemark[32 + 1];     // ����
    char          chStatus;             // ״̬
    int           iOrderdate;           // ί������
    int           iOrdersno;            // ί�����
    char          szProdcode[12 + 1];   // ��Ʒ����
};
//-------------------------------10101650:��ѯ�ͻ�δ���ڵı��ۻع���Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcShQuoteRepurchaseUndueRepurchaseField
{
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    char          chDatetype;         // ��������
    int           iBegindate;         // ��ʼ����
    int           iEnddate;           // ��������
    char          chQrytype;          // ��ѯ����
    char          szProdcode[12 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcShQuoteRepurchaseUndueRepurchaseField
{
    char          chMarket;             // �����г�
    char          szOrgid[4 + 1];       // ��������
    char          szBrhid[4 + 1];       // ��֧����
    LONGLONG      llCustid;             // �ͻ�����
    LONGLONG      llFundid;             // �ʽ��˺�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          szProdname[64 + 1];   // ��Ʒ����
    char          szLastrate[21 + 1];   // ����������
    char          szCallrate[21 + 1];   // ��ǰ��ֹ������
    char          szMaxbondamt[21 + 1]; // �ܶ��
    char          szBondbalamt[21 + 1]; // ������
    char          szBondavlamt[21 + 1]; // ��ȿ���
    char          chBreakautoflag;      // �Զ�չ�ڱ�־(ԤԼ)
    int           iBreakautodate;       // չ����ֹ����(ԤԼ)
    int           iSno;                 // ԤԼ��ˮ��
    int           iSysdate;             // ԤԼ����
    char          szLastraten[21 + 1];  // ���µ���������
    char          szCallraten[21 + 1];  // ������ǰ��ֹ������
    LONGLONG      llMatchqty;           // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    int           iOrderdate;           // ί������
    int           iMatchdate;           // ��������
    char          szMatchcode[32 + 1];  // �ɽ����
    char          chAutoflag;           // �Զ�չ�ڱ�־
    LONGLONG      llRemainqty;          // δ��ǰ��ֹ����
    LONGLONG      llContqty;            // �Զ�չ������
    LONGLONG      llCancontqty;         // ��չ������
    char          chBrkcontflag;        // ��ֹչ�ڱ�־
    char          chBreakflag;          // ΥԼ��־
    char          szDiscratio[21 + 1];  // �ۿ۱���
};
//-------------------------------10101651:���ۻع���Ӧ��Ѻ����ϸ--------------------------
struct MATRADEAPI CReqStkRpcShQuoteRepurchasePledgeDetailField
{
    LONGLONG      llFundid;            // �ʽ��˺�
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    int           iMatchdate;          // �ɽ�����
    char          szMatchcode[32 + 1]; // �ɽ����
    char          szProdcode[12 + 1];  // ��Ʒ����
    int           iCount;              // ��������
    char          szPosstr[64 + 1];    // ��λ��
};
struct MATRADEAPI CRspStkRpcShQuoteRepurchasePledgeDetailField
{
    char          szPosstr[64 + 1];    // ��λ��
    int           iServerid;           // �ڵ���
    char          szOrgid[4 + 1];      // ��������
    char          szBrhid[4 + 1];      // ��֧����
    LONGLONG      llFundid;            // �ʽ��˺�
    LONGLONG      llCustid;            // �ͻ�����
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // ֤ȯ�˺�
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];  // ��Ʒ����
    char          szSeat[6 + 1];       // ϯλ����
    char          szZywdm[8 + 1];      // ��Ѻ�����
    char          chZywlx;             // ��Ѻ������
    LONGLONG      llStkbal;            // �ɷ����
    int           iMatchdate;          // �ɽ�����
    char          szMatchcode[32 + 1]; // �ɽ����
    char          szTargetseat[6 + 1]; // ������
    char          szSjlx[3 + 1];       // ��������
    char          chLtlx;              // ��ͨ����
    char          szQylb[2 + 1];       // Ȩ�����
    char          szGpnf[4 + 1];       // �������
    char          szFzdm[3 + 1];       // ��������
    char          szText[64 + 1];      // ����˵��
    char          szRemark[32 + 1];    // ����
};
//-------------------------------10101652:�Ϻ����ۻع���Ȩ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcShQuoteRepurchasePledgeInfoField
{
};
struct MATRADEAPI CRspStkQryRpcShQuoteRepurchasePledgeInfoField
{
    LONGLONG      llStdbond;          // ��׼ȯ�ܶ�
    char          szUndueamt[21 + 1]; // δ���ڻع��ܶ�
};
//-------------------------------10101653:���ۻع�����ί�б�����Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcShQuoteRepurchaseBatchOrderRetentionLimitField
{
    char          chMarket;         // �����г�
};
struct MATRADEAPI CRspStkQryRpcShQuoteRepurchaseBatchOrderRetentionLimitField
{
    int           iServerid;           // �ڵ���
    char          szOrgid[4 + 1];      // ��������
    char          chMarket;            // �����г�
    LONGLONG      llCustid;            // �ͻ�����
    char          szSecuid[10 + 1];    // ֤ȯ�˺�
    char          szReservamt[21 + 1]; // �������
    int           iBegindate;          // ��Ч����
    int           iEnddate;            // ʧЧ����
};
//-------------------------------10101654:���ۻع�����ί�б����������--------------------------
struct MATRADEAPI CReqStkRpcShQuoteRepurchaseSetBatchOrderRetentionLimitField
{
    char          szReservamt[21 + 1]; // �������
    char          szSecuid[10 + 1];    // ֤ȯ�˺�
    char          chMarket;            // �����г�
    char          chAction;            // ��������
    int           iBegindate;          // ��Ч����
    int           iEnddate;            // ʧЧ����
};
struct MATRADEAPI CRspStkRpcShQuoteRepurchaseSetBatchOrderRetentionLimitField
{
};
//-------------------------------10101655:���ڱ��ۻع���Ʒ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseAdvanceRepurchaseField
{
    char          szProdcode[12 + 1]; // ��Ʒ����
    char          chIsvalid;          // ��Ʒ״̬
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseAdvanceRepurchaseField
{
    char          chMarket;                   // �����г�
    char          szStkcode[8 + 1];           // ֤ȯ����
    char          szProdcode[12 + 1];         // ��Ʒ����
    char          szProdname[64 + 1];         // ��Ʒ����
    char          chProdmode;                 // ��Ʒģʽ
    char          chProdtype;                 // ��Ʒ����
    int           iGhDays;                    // ��������
    int           iBuyunit;                   // ���뵥λ
    int           iMinqty;                    // �����������
    char          szLastrate[21 + 1];         // ������������
    char          szCallrate[21 + 1];         // ��ǰ��ֹ������
    char          szMaxbondamt[21 + 1];       // ��Ʒ�ܷ��ж��ܶ��
    char          szBondbalamt[21 + 1];       // ������
    char          szBondavlamt[21 + 1];       // ���ö��
    char          szNextLastrate[21 + 1];     // ���ֵ�����������
    char          szNextCallrate[21 + 1];     // ������ǰ��ֹ������
    LONGLONG      llLastcontract;             // ��ռ�ö��
    LONGLONG      llBondbackbal;              // ���յ��ڲ�չ�������ۼ�
    LONGLONG      llBondbrkunfrz;             // �ռ乺�������ۼ�
    char          chAutobuyflag;              // �Զ�չ�ڱ�־
    char          chBuyflag;                  // ���ױ�־
    char          szMinprebookbrkamt[21 + 1]; // ԤԼ���ض�����
    char          chLxzqFlag;                 // ��Ϣչ�ڱ�־
    LONGLONG      llRemainedminqty;           // ����ʣ����С����
    int           iBegindate;                 // ��������
    int           iEnddate;                   // ��������
    int           iRemaindays;                // ʣ������
    char          chIsbuy;                    // �Ƿ����������
    char          chIsprebook;                // �Ƿ��ԤԼ
    char          szRemark[128 + 1];          // ��ע��Ϣ
};
//-------------------------------10101656:���ڱ��ۻع�ԤԼ--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseReservationField
{
    LONGLONG      llFundid;            // �ʽ��ʻ�
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // ֤ȯ�˺�
    char          szStkcode[6 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];  // ��Ʒ����
    char          chPrebooktype;       // ԤԼ����
    LONGLONG      llMatchqty;          // ԤԼ����
    int           iMatchdate;          // ԭ��Լ�ɽ�����
    char          szMatchcode[32 + 1]; // ԭ��Լ�ɽ����
    int           iExecdate;           // ִ������
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseReservationField
{
    int           iSno; // ԤԼ��ˮ��
};
//-------------------------------10101657:���ڱ��ۻع�ԤԼȡ��--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseReservationCancelField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    int           iSysdate;         // ԤԼ����
    int           iSno;             // ԤԼ��ˮ��
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseReservationCancelField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101658:���ڱ��ۻع�ԤԼִ��--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseReservationExecutionField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    int           iSysdate;         // ԤԼ����
    int           iSno;             // ԤԼ��ˮ��
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseReservationExecutionField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101659:���ڱ��ۻع���ǰ����--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseAdvanceRepurchaseField
{
    char          chMarket;            // �����г�
    LONGLONG      llFundid;            // �ʽ��ʻ�
    int           iBrkqty;             // ��ǰ��ֹ����
    int           iMatchdate;          // �ɽ�����
    char          szMatchcode[32 + 1]; // �ɽ����
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseAdvanceRepurchaseField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101660:���ۻع�ԤԼ��ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseReservationStatementField
{
    LONGLONG      llFundid;           // �ʽ��˺�
    char          szProdcode[12 + 1]; // ��Ʒ����
    char          chPrebooktype;      // ԤԼ����
    char          szStatus[8 + 1];    // ԤԼ״̬
    int           iBegindate;         // ԤԼ��ʼ����
    int           iEnddate;           // ԤԼ��������
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseReservationStatementField
{
    int           iSysdate;           // ԤԼ����
    int           iSno;               // ԤԼ��ˮ��
    int           iExecdate;          // ԤԼִ������
    char          szOrgid[4 + 1];     // ��������
    char          szBrhid[4 + 1];     // ��֧����
    LONGLONG      llFundid;           // �ʽ��˺�
    LONGLONG      llCustid;           // �ͻ�����
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // ֤ȯ�˺�
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szProdcode[12 + 1]; // ��Ʒ����
    char          chPrebooktype;      // ԤԼ����
    LONGLONG      llMatchqty;         // ԤԼ����
    char          szMatchamt[21 + 1]; // ԤԼ���
    char          chStatus;           // ״̬
};
//-------------------------------10101661:���ۻع���Լ��������--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseChgContractQtyField
{
    char          chMarket;            // �����г�
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��˺�
    char          szMatchcode[32 + 1]; // �ɽ����
    int           iMatchdate;          // �ɽ�����
    LONGLONG      llAdjustqty;         // ��������
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseChgContractQtyField
{
};
//-------------------------------10101662:���ڱ��ۻع�չ��ȡ��--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseExtensionCancelField
{
    char          chMarket;            // �����г�
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��˺�
    int           iMatchdate;          // ��Լ�ɽ�����
    char          szMatchcode[32 + 1]; // ��Լ�ɽ����
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseExtensionCancelField
{
};
//-------------------------------10101663:��ѯ���ڿͻ�δ���ڵı��ۻع���Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseUndueRepurchaseField
{
    LONGLONG      llFundid;           // �ʽ��˺�
    int           iBegindate;         // ��Լ��������
    int           iEnddate;           // ��Լ��������
    char          szContflag[16 + 1]; // ��Լչ�ڱ�־
    char          szProdcode[12 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseUndueRepurchaseField
{
    char          chMarket;              // �����г�
    char          szOrgid[4 + 1];        // ��������
    LONGLONG      llCustid;              // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˺�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szProdcode[12 + 1];    // ��Ʒ����
    char          szProdname[64 + 1];    // ��Ʒ����
    char          szLastrate[21 + 1];    // ����������
    char          szCallrate[21 + 1];    // ��ǰ��ֹ������
    int           iOrderdate;            // ί������
    int           iMatchdate;            // �ɽ�����
    char          szMatchcode[32 + 1];   // �ɽ����
    int           iEnddate;              // ��������
    LONGLONG      llMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    LONGLONG      llBackqty;             // �ѹ�������
    LONGLONG      llBackqtyReal;         // ʵʱ��������
    LONGLONG      llRemainqty;           // δ��������
    char          szRemainamt[21 + 1];   // δ���ؽ��
    char          szFundintCalc[21 + 1]; // Ԥ����Ϣ
    char          chContflag;            // չ�ڱ�־
    LONGLONG      llContqty;             // ��չ������
};
//-------------------------------10101664:��ѯ���ڱ��ۻع���Ѻ������--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchasePledgeConversionRateField
{
    char          chMarket;         // �г�
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchasePledgeConversionRateField
{
    char          chMarket;           // �г�
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szExchrate[21 + 1]; // ��Ѻ������
    char          szNav[21 + 1];      // ����ֵ
};
//-------------------------------10101665:���ۻع��ֽ���Ѻ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseCashPledgeField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ�����
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseCashPledgeField
{
    int           iServerid;                // ��������
    char          szOrgid[4 + 1];           // ��������
    LONGLONG      llFundid;                 // �ʽ��˺�
    LONGLONG      llCustid;                 // �ͻ�����
    char          chMarket;                 // �����г�
    char          szSecuid[10 + 1];         // ֤ȯ�˺�
    char          szBondamtlastbal[21 + 1]; // �ϴ����
    char          szBondamtbal[21 + 1];     // ���������
    char          szBondamtavl[21 + 1];     // ���������
    char          szPosstr[64 + 1];         // ��λ��
};
//-------------------------------10101666:���ڱ��ۻع���Ȩ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseMortgageField
{
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseMortgageField
{
    char          szStkvalue[21 + 1]; // ��Ѻȯ����ֵ
    char          szFundavl[21 + 1];  // ����ʽ����
    LONGLONG      llStdbond;          // ��׼ȯ�ܶ�
    LONGLONG      llStdbondavl;       // ʵʱ��׼ȯ���
    char          szUndueamt[21 + 1]; // δ���ڻع��ܶ�
};
//-------------------------------10101667:��ѯ���ڱ��ۻع��ͻ��ض�����--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchaseSpecificOfferField
{
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llFundid;           // �ʽ��˺�
    char          szProdcode[12 + 1]; // ��Ʒ����
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchaseSpecificOfferField
{
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llFundid;           // �ʽ��˺�
    char          szProdcode[12 + 1]; // ��Ʒ����
    char          szLastrate[21 + 1]; // ����������
    char          szCallrate[21 + 1]; // ��ǰ��ֹ������
};
//-------------------------------10101668:�ͻ�����Ͷ���ʵ�����Ϣά��--------------------------
struct MATRADEAPI CReqStkRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriatenessField
{
    char          szOrgid[4 + 1];           // ��������
    LONGLONG      llCustid;                 // �ͻ�����
    char          chInvestmentperiod;       // Ͷ������
    char          szInvestmenttype[32 + 1]; // Ͷ��Ʒ��
    char          szRemark[128 + 1];        // ��ע
};
struct MATRADEAPI CRspStkRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriatenessField
{
};
//-------------------------------10101669:���ۻع���Ѻ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzQuoteRepurchasePledgeField
{
    char          chMarket;          // �����г�
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcSzQuoteRepurchasePledgeField
{
    char          szPoststr[64 + 1];    // ��λ��
    int           iServerid;            // �ڵ���
    LONGLONG      llCustid;             // �ͻ�����
    char          szOrgid[5 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szSeat[6 + 1];        // ϯλ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          chStktype;            // ֤ȯ���
    LONGLONG      llBondlastbal;        // �ϴ����
    LONGLONG      llBondbal;            // ��Ѻ���
    LONGLONG      llBondavl;            // ��Ѻ����
    char          szExchrate[21 + 1];   // ������
    char          szStdbondavl[21 + 1]; // ����ɱ�׼ȯ����
};
//-------------------------------10101670:ծȯЭ��ع�ί���걨--------------------------
struct MATRADEAPI CReqStkRpcBondAgreementRepurchaseOrderField
{
    char          chMarket;            // �����г�
    LONGLONG      llFundid;            // �ʲ��ʻ�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];     // �������
    LONGLONG      llOrderqty;          // ί������
    char          szOrderamt[21 + 1];  // ���ʽ��
    int           iGhdays;             // ��Ʒ����
    char          szDuerate[21 + 1];   // ������
    char          szTargetseat[6 + 1]; // �Է����׵�Ԫ
    char          szConfernum[8 + 1];  // Լ����
    char          szZqzysno[32 + 1];   // ��ʼ��Լ��
    LONGLONG      llRisksignsno;       // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcBondAgreementRepurchaseOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101671:ծȯЭ��ع�ί�г����걨--------------------------
struct MATRADEAPI CReqStkRpcBondAgreementRepurchaseCancelField
{
    char          chMarket;         // �����г�
    int           iOrderdate;       // ί������
    int           iOrdersno;        // ί�����
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkRpcBondAgreementRepurchaseCancelField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101672:ծȯЭ��ع�ί����ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondAgreementRepurchaseStatementField
{
    char          chMarket;         // �����г�
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iBegindate;       // ί������(��)
    int           iEnddate;         // ί������(ֹ)
    int           iOrdersno;        // ί�����
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcBondAgreementRepurchaseStatementField
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iOrderdate;            // ί������
    int           iOrdersno;             // ί�����
    char          szOrderid[10 + 1];     // ��ͬ���
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szSeat[6 + 1];         // ����ϯλ
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          chMoneytype;           // ���Ҵ���
    char          szBsflag[2 + 1];       // �������
    char          chOrderstatus;         // ί��״̬
    char          chCancelstatus;        // ����״̬
    char          chCancelflag;          // ������ʶ
    char          szOldorderid[10 + 1];  // ԭ��ͬ���
    int           iOrderqty;             // ί������
    int           iMatchqty;             // �ɽ�����
    int           iCancelqty;            // ��������
    char          szOrderamt[21 + 1];    // ί�н��
    char          szOrderfrzamt[21 + 1]; // ������
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iGhdays;               // ��������
    char          szDuerate[21 + 1];     // ������
    char          szTargetseat[6 + 1];   // �Է�ϯλ
    char          szConfernum[8 + 1];    // Լ����
    char          szZqzysno[32 + 1];     // ��ʼ��Լ��
    int           iReporttime;           // ����ʱ��
    char          chOperway;             // ί������
    int           iOpertime;             // ί��ʱ��
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
//-------------------------------10101673:ծȯЭ��ع��ɽ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondAgreementRepurchaseMatchField
{
    char          chMarket;         // �����г�
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iBegindate;       // �ɽ�����(��)
    int           iEnddate;         // �ɽ�����(ֹ)
    int           iOrdersno;        // ί�����
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcBondAgreementRepurchaseMatchField
{
    char          szPoststr[32 + 1];   // ��λ��
    int           iSysdate;            // �ɽ�����
    char          szSecuid[10 + 1];    // �ɶ�����
    char          chMarket;            // �����г�
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];   // ֤ȯ����
    char          szBsflag[2 + 1];     // �������
    int           iOrdersno;           // ί�����
    char          szOrderid[10 + 1];   // ��ͬ���
    int           iOrderqty;           // ί������
    char          szMatchcode[20 + 1]; // �ɽ����
    char          chMatchtype;         // �ɽ�����
    int           iMatchqty;           // �ɽ�����
    char          szMatchamt[21 + 1];  // �ɽ����
    int           iMatchtime;          // �ɽ�ʱ��
};
//-------------------------------10101674:ծȯЭ��ع���Լ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondAgreementRepurchaseContractField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szZqzysno[32 + 1]; // ��ʼ��Լ��
    char          chQueryflag;       // ��ѯ��־
    int           iCount;            // ��������
    char          szPosstr[64 + 1];  // ��λ��
};
struct MATRADEAPI CRspStkQryRpcBondAgreementRepurchaseContractField
{
    char          szPoststr[32 + 1];   // ��λ��
    char          szZqzysno[32 + 1];   // ��ʼ��Լ��
    int           iSysdate;            // ϵͳ����
    LONGLONG      llFundid;            // �ʽ��˺�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szSeat[6 + 1];       // ϯλ����
    char          chMarket;            // �г�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];   // ֤ȯ����
    char          chMoneytype;         // ���Ҵ���
    char          szOrderid[10 + 1];   // ��ͬ���
    char          szConfernum[8 + 1];  // Լ����
    char          szTargetseat[6 + 1]; // �Է�ϯλ
    int           iGhdays;             // ��Ʒ����
    int           iEnddate;            // Ԥ�ƹ�������
    char          szDuerate[21 + 1];   // ������
    LONGLONG      llMatchqty;          // ��ʼ��Ѻ����
    char          szMatchamt[21 + 1];  // ��ʼ���
    char          szMatchcode[32 + 1]; // �ɽ����
    char          chStatus;            // ��Լ״̬
    LONGLONG      llDebtqty;           // ��Լ����
    char          szDebtamt[21 + 1];   // ��Լ���
    char          chPledgorkind;       // �ʽ�����/�ڳ���־
    char          szRemark[128 + 1];   // ��ע��Ϣ
};
//-------------------------------10101675:�������ί���걨--------------------------
struct MATRADEAPI CReqStkRpcPwdServiceOrderField
{
    char          chMarket;         // �����г�
    LONGLONG      llFundid;         // �ʲ��ʻ�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chValidationtype; // ���뼤������
    int           iValidationcode;  // ���뼤��У���
};
struct MATRADEAPI CRspStkRpcPwdServiceOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101676:�ɶ���ѯ����ѯ�ͻ���Ӧ�Ĺɶ�����--------------------------
struct MATRADEAPI CReqStkQryRpcTrdacctField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcTrdacctField
{
    char          szPoststr[32 + 1]; // ��λ��
    LONGLONG      llCustid;          // �ͻ�����
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szName[16 + 1];    // �ɶ�����
    int           iSecuseq;          // �ɶ����
    char          chRegflag;         // ָ������״̬
};
//-------------------------------10101677:�ʽ��ѯ(������ҵ��)--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
    char          szRemark[6 + 1];  // ��ע
};
struct MATRADEAPI CRspStkQryRpcCuacctField
{
    LONGLONG      llCustid;              // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szOrgid[4 + 1];        // ��������
    char          chMoneytype;           // ����
    char          szFundbal[21 + 1];     // �ʽ����
    char          szMarketvalue[21 + 1]; // �ʲ���ֵ
    char          szFundavl[21 + 1];     // �ʽ���ý��
    char          szFund[21 + 1];        // �ʽ��ʲ�
    char          szStkvalue[21 + 1];    // ��ֵ
    int           iFundseq;              // ���ʽ��־
    char          szFundloan[21 + 1];    // �����ܽ��
    char          szFundbuy[21 + 1];     // ���붳��
    char          szFundsale[21 + 1];    // �����ⶳ
    char          szFundfrz[21 + 1];     // �����ܽ��
    char          szFundlastbal[21 + 1]; // �������
    char          szFundpartavl[21 + 1]; // ����ͨ���������ʽ�
};
//-------------------------------10101678:�ʲ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcAssetDetailField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcAssetDetailField
{
    LONGLONG      llCustid;                  // �ͻ�����
    LONGLONG      llFundid;                  // �ʽ��˻�
    char          szOrgid[4 + 1];            // ��������
    char          chMoneytype;               // ����
    char          szFundassettotoal[21 + 1]; // �ʲ���ֵ
    char          szFundassetpure[21 + 1];   // �ʲ���ֵ
    char          szFundasset[21 + 1];       // �ʽ��ʲ�
    char          szSktasset[21 + 1];        // ֤ȯ�ʲ���ֵ
    char          szStkassetabg[21 + 1];     // AB��֤ȯ�ʲ�
    char          szStkassetgz[21 + 1];      // ��ת֤ȯ�ʲ�
    char          szStkassethk[21 + 1];      // �۹�֤ȯ�ʲ�
    char          szFundassetof[21 + 1];     // ����ʽ�����ʲ�
    char          szFundassetrzjr[21 + 1];   // ���ʽ����ʽ�
    char          szFundassetrqjc[21 + 1];   // ��ȯ����ʽ�
    char          szStkassetzy[21 + 1];      // ��Ѻ֤ȯ�ʲ�
    char          szFundassetofzj[21 + 1];   // �Խ�TA�����ʲ�
    char          szFundassetofjs[21 + 1];   // �е�TA�����ʲ�
};
//-------------------------------10101679:�ɷ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcStkDetailField
{
    char          szPoststr[32 + 1];     // ��λ��
    LONGLONG      llCustid;              // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMarket;              // �����г�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szOrgid[4 + 1];        // ��������
    char          chMoneytype;           // ����
    int           iStkbal;               // �ɷ����
    int           iStkavl;               // �ɷݿ���
    char          szBuycost[21 + 1];     // ��ǰ�ɱ�
    char          szCostprice[21 + 1];   // �ɱ��۸�
    char          szMktval[21 + 1];      // ��ֵ
    char          szIncome[21 + 1];      // ӯ��
    char          szProincome[21 + 1];   // �ο�ӯ��
    char          chMtkcalflag;          // ��ֵ�����ʶ
    int           iStkqty;               // ��ǰӵ����
    char          szLastprice[21 + 1];   // ���¼۸�
    char          chStktype;             // ֤ȯ����
    char          szProfitcost[21 + 1];  // �ο��ɱ�
    char          szProfitprice[21 + 1]; // �ο��ɱ���
    LONGLONG      llStkbuy;              // �ɷ�����ⶳ
    LONGLONG      llStksale;             // �ɷ���������
    LONGLONG      llStkdiff;             // ����������
    LONGLONG      llStkfrz;              // �ɷݶ���
    LONGLONG      llStktrdfrz;           // ���������
    LONGLONG      llStktrdunfrz;         // ��������
    LONGLONG      llStkbuysale;          // �ɷ�ʵʱ�������
    LONGLONG      llStkuncomebuy;        // ��;����
    LONGLONG      llStkuncomesale;       // ��;����
    char          szCostpriceEx[21 + 1]; // �ɱ��۸�
};
//-------------------------------10101680:�ɷݻ��ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkSummaryField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcStkSummaryField
{
    LONGLONG      llCustid;              // �ͻ�����
    char          chMarket;              // �����г�
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          chMoneytype;           // ����
    int           iStkbal;               // �ɷ����
    int           iStkavl;               // �ɷݿ���
    int           iCreditstkbal;         // ��������ɷ����
    int           iCreditstkavl;         // ��������ɷݿ���
    char          szBuycost[21 + 1];     // ��ǰ�ɱ�
    char          szCostprice[21 + 1];   // �ɱ��۸�
    char          szMktval[21 + 1];      // ��ֵ
    char          szIncome[21 + 1];      // ӯ��
    char          chMtkcalflag;          // ��ֵ�����ʶ
    int           iStkqty;               // ��ǰӵ����
    char          szLastprice[21 + 1];   // ���¼۸�
    char          chStktype;             // ֤ȯ����
    char          szProincome[21 + 1];   // �ο�ӯ��
    char          szProfitcost[21 + 1];  // �ο��ɱ�
    char          szProfitprice[21 + 1]; // �ο��ɱ���
};
//-------------------------------10101681:��Χ�ʽ��ʻ��ʽ������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacct2Field
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcCuacct2Field
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    LONGLONG      llFundid;           // �ʽ��˻�
    char          szOrgid[4 + 1];     // ��������
    char          chMoneytype;        // ����
    char          szFundavl[21 + 1];  // �ʽ����
    char          szFundbal[21 + 1];  // �ʽ����
};
//-------------------------------10101682:�ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�����--------------------------
struct MATRADEAPI CReqStkQryRpcTrdacct2Field
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkQryRpcTrdacct2Field
{
    LONGLONG      llCustid;         // �ͻ�����
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
//-------------------------------10101683:�ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�����--------------------------
struct MATRADEAPI CReqStkQryRpcTrdacct3Field
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspStkQryRpcTrdacct3Field
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    char          szOrgid[4 + 1];     // ��������
    char          szBankcode[4 + 1];  // ���д���
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
};
//-------------------------------10101684:����ί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOrderDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iOrdergroup;       // ί������
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
    char          chQryoperway;      // ί������
};
struct MATRADEAPI CRspStkQryRpcOrderDetailField
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iOrderdate;            // ί������
    int           iOrdersno;             // ί�����
    int           iOrdergroup;           // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMoneytype;           // ����
    char          szOrgid[4 + 1];        // ��������
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[10 + 1];     // �걨��ͬ���
    int           iReporttime;           // ����ʱ��
    int           iOpertime;             // ί��ʱ��
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szProdcode[12 + 1];    // ��Ʒ����
    char          szProdname[64 + 1];    // ��Ʒ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    char          szOrderfrzamt[21 + 1]; // ������
    int           iMatchqty;             // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iCancelqty;            // ��������
    char          chOrderstatus;         // ί��״̬
    char          szSeat[6 + 1];         // ����ϯλ
    char          chCancelflag;          // ������ʶ
    int           iOperdate;             // ��������
    char          szBondintr[21 + 1];    // ծȯӦ����Ϣ
    char          chOperway;             // ί������
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
//-------------------------------10101685:����ί�в�ѯ(������ҵ��)--------------------------
struct MATRADEAPI CReqStkQryRpcOrder2Field
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iOrdergroup;       // ί������
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
    char          chQryoperway;      // ί������
};
struct MATRADEAPI CRspStkQryRpcOrder2Field
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iOrderdate;            // ί������
    int           iOrdersno;             // ί�����
    int           iOrdergroup;           // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMoneytype;           // ����
    char          szOrgid[4 + 1];        // ��������
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[10 + 1];     // �걨��ͬ���
    int           iReporttime;           // ����ʱ��
    int           iOpertime;             // ί��ʱ��
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szProdcode[12 + 1];    // ��Ʒ����
    char          szProdname[64 + 1];    // ��Ʒ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    char          szOrderfrzamt[21 + 1]; // ������
    int           iMatchqty;             // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iCancelqty;            // ��������
    char          chOrderstatus;         // ί��״̬
    char          szSeat[6 + 1];         // ����ϯλ
    char          chCancelflag;          // ������ʶ
    int           iOperdate;             // ��������
    char          szBondintr[21 + 1];    // ծȯӦ����Ϣ
    char          chOperway;             // ί������
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
//-------------------------------10101686:���ճɽ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcMatchDetailField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          chQryoperway;      // ί������
};
struct MATRADEAPI CRspStkQryRpcMatchDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iTrddate;             // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // �걨��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          szProdname[64 + 1];   // ��Ʒ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szBondintr[21 + 1];   // ծȯӦ����Ϣ
};
//-------------------------------10101687:���ճɽ���ѯ(������ҵ��)--------------------------
struct MATRADEAPI CReqStkQryRpcMatchField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          chQryoperway;      // ί������
};
struct MATRADEAPI CRspStkQryRpcMatchField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iTrddate;             // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // �걨��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          szProdname[64 + 1];   // ��Ʒ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szBondintr[21 + 1];   // ծȯӦ����Ϣ
};
//-------------------------------10101688:���ճɽ���ѯ��΢֤ȯר�ã�--------------------------
struct MATRADEAPI CReqStkQryRpcMatchForTencentPayField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          chQryoperway;      // ί������
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
};
struct MATRADEAPI CRspStkQryRpcMatchForTencentPayField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iTrddate;             // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // �걨��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProdcode[12 + 1];   // ��Ʒ����
    char          szProdname[64 + 1];   // ��Ʒ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szBondintr[21 + 1];   // ծȯӦ����Ϣ
    char          szOrdergroup[32 + 1]; // �ⲿ��ˮ��
};
//-------------------------------10101689:��ʷί�л��ܲ�ѯ, ��֤ȯ�������������--------------------------
struct MATRADEAPI CReqStkQryRpcHisOrderSummaryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspStkQryRpcHisOrderSummaryField
{
    int           iOrderdate;            // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    char          szOrgid[4 + 1];        // ��������
    char          szBsflag[2 + 1];       // �������
    char          chMarket;              // �����г�
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    LONGLONG      llOrderqty;            // ί������
    char          szOrderfrzamt[21 + 1]; // ί�н��
    LONGLONG      llMatchqty;            // �ɽ�����
    LONGLONG      llCancelqty;           // ��������
    char          szMatchamt[21 + 1];    // �ɽ����
};
//-------------------------------10101690:�ɽ����ܲ�ѯ, ��֤ȯ�������������--------------------------
struct MATRADEAPI CReqStkQryRpcHisMatchSummaryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryoperway;      // ��������
};
struct MATRADEAPI CRspStkQryRpcHisMatchSummaryField
{
    int           iBizdate;             // ��������
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��������
    char          szBsflag[2 + 1];      // �������
    char          chMarket;             // �����г�
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    LONGLONG      llMatchqty;           // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szBankcode[4 + 1];    // �ⲿ����
    char          szBankid[32 + 1];     // �ⲿ�˻�
    char          szFeeJsxf[21 + 1];    // ��Ӷ��
    char          szFeeSxf[21 + 1];     // Ӷ��
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFeeQtf[21 + 1];     // ������
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFundeffect[21 + 1]; // �ʽ�����
};
//-------------------------------10101691:�����ѯ�����ݹ�̨��ͨ���ʵ�ժҪ���ô�ӡ��Ϣ��ӡ���ݡ�΢֤ȯר��--------------------------
struct MATRADEAPI CReqStkQryRpcDeliveryForTencentPayField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          szExtsno[32 + 1];  // �ⲿ��ˮ��
};
struct MATRADEAPI CRspStkQryRpcDeliveryForTencentPayField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ί������
    int           iOrdertime;           // ί��ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ�����˵��
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // ����������
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ�����
    int           iMatchtimes;          // �ɽ�����
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szFundeffect[21 + 1]; // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeJsxf[21 + 1];    // ��׼������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          chSourcetype;         // ����
    char          szBankcode[4 + 1];    // �ⲿ����
    char          szBankid[32 + 1];     // �ⲿ�˻�
    char          szFeeOneYhs[21 + 1];  // һ��ӡ��˰
    char          szFeeOneGhf[21 + 1];  // һ��������
    char          szFeeOneQsf[21 + 1];  // һ�������
    char          szFeeOneJygf[21 + 1]; // һ�����׹��
    char          szFeeOneJsf[21 + 1];  // һ�����ַ�
    char          szFeeOneZgf[21 + 1];  // һ��֤�ܷ�
    char          szFeeOneQtf[21 + 1];  // һ��������
    char          szFeeOneFxj[21 + 1];  // һ�����ս�
    char          szOrdergroup[32 + 1]; // �ⲿ��ˮ��
};
//-------------------------------10101692:����ί�л��ܲ�ѯ,ordergroup+stkcode+bsflag--------------------------
struct MATRADEAPI CReqStkQryRpcOrderSummary2Field
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspStkQryRpcOrderSummary2Field
{
    int           iOrderdate;            // ί������
    int           iOrdergroup;           // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    char          szOrgid[4 + 1];        // ��������
    char          szBsflag[2 + 1];       // �������
    char          chMarket;              // �����г�
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    LONGLONG      llOrderqty;            // ί������
    char          szOrderfrzamt[21 + 1]; // ί�н��
    LONGLONG      llMatchqty;            // �ɽ�����
    LONGLONG      llCancelqty;           // ��������
    char          szMatchamt[21 + 1];    // �ɽ����
    LONGLONG      llQty;                 // �ɳ�����
};
//-------------------------------10101693:�ͻ�������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcOrgField
{
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkQryRpcOrgField
{
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // ��������
    char          chMarket;         // ������ֵ
    char          szSecuid[10 + 1]; // �ɶ�����
};
//-------------------------------10101694:��ѯ�ͻ����Ժ��ʽ��ʺ�����--------------------------
struct MATRADEAPI CReqStkQryRpcAcctInfoField
{
    LONGLONG      llFundid;         // �ʽ��˻�
};
struct MATRADEAPI CRspStkQryRpcAcctInfoField
{
    LONGLONG      llCustid;              // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˺�
    char          chCustprop;            // �ͻ�����
    char          chCustkind;            // �ͻ����
    char          chCustgroup;           // �ͻ�����
    char          chFundkind;            // �ʽ����
    char          chFundlevel;           // �ʽ��Һ�
    char          chFundgroup;           // �ʽ����
    char          szRiskfactor[129 + 1]; // ����Ҫ��
    char          szCriterion[129 + 1];  // �����淶
};
//-------------------------------10101695:���������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcMktIntentionField
{
    char          chMarket;          // �г�
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szBsflag[128 + 1]; // ҵ�����
    int           iPromiseno;        // Լ����
    int           iQryrec;           // ��ѯ��¼��
    int           iPosstr;           // ��λ��
};
struct MATRADEAPI CRspStkQryRpcMktIntentionField
{
    char          chMarket;              // ����������
    int           iJysorderid;           // �����걨���к�
    char          szStkcode[6 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szOrderqty[21 + 1];    // �����걨����
    char          szOrderprice[21 + 1];  // �����걨�۸�
    char          szBsflag[2 + 1];       // �������
    char          szSeat[6 + 1];         // ϯλ
    char          szSecuid[10 + 1];      // �û�����
    char          szSecuname[16 + 1];    // �û�����
    char          szContactinfo[32 + 1]; // ��ϵ��ʽ
    int           iReporttime;           // �걨ʱ��
    int           iPromiseno;            // Լ����
    int           iUpdtime;              // ����ˢ��ʱ��
    int           iPosstr;               // ��λ��
};
//-------------------------------10101696:��ѯӪҵ��ĳһҵ�������걨ϯλ--------------------------
struct MATRADEAPI CReqStkQryRpcSeatField
{
    char          chMarket;         // ����������
    char          szOrgid[4 + 1];   // Ӫҵ��
    char          szBsflag[2 + 1];  // ҵ�����
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkQryRpcSeatField
{
    char          szSeat[6 + 1]; // �걨ϯλ
};
//-------------------------------10101697:��ѯ�ʽ��˻���Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcCuacctAcctInfoField
{
    LONGLONG      llFundid;         // �ʽ��˻�
};
struct MATRADEAPI CRspStkQryRpcCuacctAcctInfoField
{
    char          szFundname[16 + 1];        // �ʽ�����
    char          chIdtype;                  // ֤������
    char          szIdno[32 + 1];            // ֤������
    char          szOperway[128 + 1];        // ������ʽ
    char          szFundagentright[128 + 1]; // �ʽ����Ȩ��
    char          szFundright[128 + 1];      // �ʽ�Ȩ��
    char          chStatus;                  // �ʽ�״̬
};
//-------------------------------10101698:����ͨ�ɷ�����ѯ�����У�--------------------------
struct MATRADEAPI CReqStkQryRpcShNonCirculatingShareBalanceField
{
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iCount;            // ��������
    char          szPoststr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcShNonCirculatingShareBalanceField
{
    LONGLONG      llCustid;          // �ͻ�����
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    LONGLONG      llStkbal;          // ί������
    char          szMktval[21 + 1];  // ��ֵ
    char          szPathid[16 + 1];  // ����·������
    char          szPoststr[64 + 1]; // ��λ��
};
//-------------------------------10101699:���ڷ���ͨ�ɷ�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzNonCirculatingShareBalanceField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iCount;            // ��������
    char          szPoststr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcSzNonCirculatingShareBalanceField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSeat[6 + 1];     // ϯλ
    char          szStkprop[2 + 1];  // �ɷ�����
    LONGLONG      llStkbal;          // �ɷ����
    LONGLONG      llStkavl;          // �ɷݿ���
    char          szMktval[21 + 1];  // ��ֵ
    char          szPoststr[64 + 1]; // ��λ��
};
//-------------------------------10101700:��Ϣ������˰��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcDividendWithholdingTaxField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iBegindate;       // ��ʼ����
    int           iEnddate;         // ��������
    char          chQryhis;         // ��ѯ��ʽ
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcDividendWithholdingTaxField
{
    char          chMarket;               // �����г�
    char          szSecuid[10 + 1];       // ֤ȯ�˺�
    char          szStkcode[8 + 1];       // ֤ȯ����
    LONGLONG      llTaxcount;             // �����ֹ���
    int           iReducedate;            // ���ֽ�������
    char          chMoneytype;            // ���Ҵ���
    char          szTaxamt[21 + 1];       // Ӧ��˰��
    char          szPaidtaxamt[21 + 1];   // �ѿ�˰��
    char          szUnpaidtaxamt[21 + 1]; // δ��˰��
    char          chStatus;               // ��˰״̬
    int           iTaxdate;               // ��˰����
};
//-------------------------------10101701:��ѯ�ͻ���������--------------------------
struct MATRADEAPI CReqStkQryRpcCustOrgField
{
    char          chInputtype;       // ��½����
    char          szInputid[64 + 1]; // ��½��ʶ
};
struct MATRADEAPI CRspStkQryRpcCustOrgField
{
    int           iServerid;      // �������
    char          szOrgid[5 + 1]; // ��������
    char          szBrhid[5 + 1]; // ��֧����
    LONGLONG      llCustid;       // �ͻ�����
};
//-------------------------------10101702:��ѯ����ʽ��˺�--------------------------
struct MATRADEAPI CReqStkQryRpcDepositoryCuacctField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chMoneytype;       // ���Ҵ���
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chIdtype;          // ֤������
    char          szIdno[32 + 1];    // ֤���˺�
};
struct MATRADEAPI CRspStkQryRpcDepositoryCuacctField
{
    int           iServerid;         // ��������
    LONGLONG      llCustid;          // �ͻ�����
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          chIdtype;          // ֤������
    char          szIdno[32 + 1];    // ֤������
    char          chStatus;          // ״̬
    char          chMoneytype;       // ����
    char          szBankid[32 + 1];  // �����ʺ�
    char          szBankcode[4 + 1]; // ���д���
};
//-------------------------------10101703:���ڻ�������ʧ�ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFloorFundRedemptionFailureField
{
    char          chMarket;         // �г�
    char          szStkcode[6 + 1]; // ֤ȯ����
    int           iBegindate;       // ��ʼ����
    int           iEnddate;         // ��������
};
struct MATRADEAPI CRspStkQryRpcFloorFundRedemptionFailureField
{
    char          szOrgid[4 + 1];    // ��������
    char          chMarket;          // �г�
    LONGLONG      llCustid;          // �ͻ�����
    char          szSecuid[10 + 1];  // �ɶ�����
    char          chMoneytype;       // ����
    int           iOrderdate;        // ί������
    char          szOrderid[10 + 1]; // ί�к�ͬ��
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szStkname[64 + 1]; // ֤ȯ����
    char          chStktype;         // ֤ȯ���
    char          szRemark[32 + 1];  // ��ע
};
//-------------------------------10101704:������֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBlacklistStkField
{
    char          chMarket;         // �г�
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcBlacklistStkField
{
    char          chMarket;             // �г�
    char          szStkcode[6 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[1024 + 1];   // ���������������
    char          szOperway[128 + 1];   // �������Ĳ�����ʽ
    char          szPromptmsg[128 + 1]; // ������ʾ��Ϣ
};
//-------------------------------10101705:���ڴ��ڽ��������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzBlockTradingMktField
{
    char          szStkcode[6 + 1];    // ֤ȯ����
    char          szConfermnum[8 + 1]; // Լ����
    char          szBsflag[2 + 1];     // ҵ�����
    char          chStatus;            // ��¼״̬
};
struct MATRADEAPI CRspStkQryRpcSzBlockTradingMktField
{
    int           iHqjlh;            // ��¼��
    char          szHqzqdm[6 + 1];   // ֤ȯ����
    LONGLONG      llHqsbsl;          // �걨�������ţ�
    char          szHqsbjg[21 + 1];  // �걨�۸�
    char          szHqywlb[2 + 1];   // ҵ�����
    char          szHqzllb[10 + 1];  // ָ�����
    char          szHqhtxh[22 + 1];  // ��ͬ���
    char          szHqlxr[12 + 1];   // ��ϵ��
    char          szHqlxfs[30 + 1];  // ��ϵ��ʽ
    char          szHqjsjg[2 + 1];   // �����������
    char          szHqsbsj[8 + 1];   // �걨ʱ��
    char          szHqydh[8 + 1];    // Լ����
    char          szHqsyl[21 + 1];   // �ο�������
    LONGLONG      llHqsbsl2;         // �걨����2
    char          szHqsbjg2[21 + 1]; // �걨�۸�2
    char          szHqsyl2[21 + 1];  // �ο�������2
    char          chHqjlzt;          // ��¼״̬
    char          szHqbybz[2 + 1];   // ���ñ�־
    char          chHqqxlx;          // ��������
    int           iHqghqx;           // �ع�����
    char          szHqbywb[80 + 1];  // �����ı�
};
//-------------------------------10101706:�Ϻ����ڽ��������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcShBlockTradingMktField
{
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          szBsflag[2 + 1];  // ҵ�����
};
struct MATRADEAPI CRspStkQryRpcShBlockTradingMktField
{
    int           iHqjlh;           // ��¼��
    char          szHqzqdm[6 + 1];  // ֤ȯ����
    char          szHqhybh[10 + 1]; // ��Ա���
    char          chHqbdlx;         // ��������
    char          chHqmmbz;         // ������־
    char          szHqsbjg[21 + 1]; // �걨�۸�
    LONGLONG      llHqsbsl;         // �걨�������ţ�
    char          szHqcdbh[10 + 1]; // �������
    char          szHqfqf[6 + 1];   // ����ϯλ
    char          szHqlxfs[50 + 1]; // ��ϵ��ʽ
};
//-------------------------------10101707:���ڳ��ڻ���ֺ췽ʽ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSzFloorFundDividendsField
{
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcSzFloorFundDividendsField
{
    char          chMarket;          // �г�
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szStkname[64 + 1]; // ֤ȯ����
    char          chDividpolicy;     // �ֺ췽ʽ
};
//-------------------------------10101708:���޹ɶ����ֶ�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcLimitedTrdacctReductionLimitField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcLimitedTrdacctReductionLimitField
{
    int           iImportdate;      // ��������
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szSeat[6 + 1];    // ϯλ
    LONGLONG      llStkbal;         // �ɷ����
    LONGLONG      llStkavl1;        // ���ۿ���
    LONGLONG      llStkavl2;        // ���ڷ��ض����ֿ���
    LONGLONG      llStkavl3;        // �����ض����ֿ���
    LONGLONG      llStkavl4;        // ETF�깺����
};
//-------------------------------10101709:�۹�ͨ�ʽ��ʲ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkCuacctField
{
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          szOrgid[4 + 1];    // ��������
    char          chMoneytype;       // ���Ҵ���
    char          szFundcode[8 + 1]; // �ʽ��Ŀ
};
struct MATRADEAPI CRspStkQryRpcHkCuacctField
{
    char          szOrgid[4 + 1];          // ��������
    LONGLONG      llFundid;                // �ʽ��ʺ�
    char          szFundcode[8 + 1];       // �ʽ��Ŀ
    char          chMoneytype;             // ���Ҵ���
    char          szLasttotalamt[21 + 1];  // ��������
    char          szTotalamt[21 + 1];      // ��ǰ����
    char          szAvlamt[21 + 1];        // ������
    char          szFunduncomein[21 + 1];  // ��;����
    char          szFunduncomeout[21 + 1]; // ��;����
    char          szFundrealin[21 + 1];    // ʵʱ����
    char          szFundrealout[21 + 1];   // ʵʱ����
    char          szFundnightout[21 + 1];  // ҹ�г����ʽ�
    char          szFundtranin[21 + 1];    // ������
    char          szFundtranout[21 + 1];   // �������
    char          szOtheramt[21 + 1];      // �������
    char          szRemark[128 + 1];       // ��ע��Ϣ
};
//-------------------------------10101710:�۹�ͨ�ͻ���ծ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkLiabilityField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ���Ҵ���
    char          chDebtsid;        // ��ծ����
    char          szOrgid[4 + 1];   // ��������
};
struct MATRADEAPI CRspStkQryRpcHkLiabilityField
{
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llCustid;             // �ͻ�����
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chDebtsid;            // ��ծ����
    char          chMoneytype;          // ���Ҵ���
    char          szUnpayamt[21 + 1];   // δ֧�����
    char          szSumpaidamt[21 + 1]; // ��֧���ܽ��
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szSumdebtamt[21 + 1]; // Ӧ���ܽ��
};
//-------------------------------10101711:Ȩ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkEquityField
{
    char          szSecuid[11 + 1]; // �ɶ�����
    char          chMarket;         // �����г�
    char          szStkcode[9 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcHkEquityField
{
    char          chMarket;           // �г�����
    char          szSecuid[11 + 1];   // ֤ȯ�ʺ�
    char          szSeat[7 + 1];      // ϯλ����
    char          szStkcode[9 + 1];   // ֤ȯ����
    char          szStkprop[2 + 1];   // �ɷ�����
    char          szEquittype[2 + 1]; // Ȩ������
    char          szRightno[10 + 1];  // Ȩ����
    char          chListstatus;       // ����״̬
    LONGLONG      llStkbal;           // �������
    LONGLONG      llStkuncome;        // δ��������
    LONGLONG      llStkfrz;           // ��������
    LONGLONG      llStkother;         // ��������
};
//-------------------------------10101712:�۹�ͨ����׼��--------------------------
struct MATRADEAPI CReqStkRpcHkPreparationForOpeningAccountField
{
    char          chMarket;         // �г�����
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspStkRpcHkPreparationForOpeningAccountField
{
    int           iSno;            // ��ˮ��
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101713:�۹�ͨδ������ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkUndeliveryDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkUndeliveryDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iOrderdate;           // ί������
    int           iOrdersno;            // �ɽ�����
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          chMoneytype;          // ����
    char          szOrgid[4 + 1];       // ��������
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBusitype[4 + 1];    // ҵ�����
    char          szOrderid[10 + 1];    // ��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szOrderprice[21 + 1]; // ί�м۸�(�۱�)
    int           iOrderqty;            // ί������
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�(�����)
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szClearedamt[21 + 1]; // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeJsxf[21 + 1];    // ��׼������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �ɷݽ��շ�
    char          szFeeJygf[21 + 1];    // ���׷�
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFeeJsf[21 + 1];     // ����ϵͳʹ�÷ѷ�
    char          szFeeZgf[21 + 1];     // ��������
    char          szFeeOneYhs[21 + 1];  // һ��ӡ��˰
    char          szFeeOneGhf[21 + 1];  // һ��������
    char          szFeeOneQsf[21 + 1];  // һ���ɷݽ��շ�
    char          szFeeOneJygf[21 + 1]; // һ�����׷�
    char          szFeeOneJsf[21 + 1];  // һ������ϵͳʹ�÷�
    char          szFeeOneZgf[21 + 1];  // һ����������
    char          szFeeOneQtf[21 + 1];  // һ��������
    char          szFeeOneFxj[21 + 1];  // һ�����ս�
    char          szSettrate[21 + 1];   // �������
    char          szRemark[128 + 1];    // ��ע
};
//-------------------------------10101714:�۹�֤ͨȯ��Ϸѽ�����ϸ--------------------------
struct MATRADEAPI CReqStkRpcHkStkCombinationFeeDeliveryDetailField
{
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          chMoneytype;       // ���Ҵ���
    char          szOrgid[4 + 1];    // ��������
    int           iStrdate;          // ���㿪ʼʱ��
    int           iEnddate;          // �������ʱ��
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          chMarket;          // �����г�
};
struct MATRADEAPI CRspStkRpcHkStkCombinationFeeDeliveryDetailField
{
    char          szPoststr[32 + 1];      // ��λ��
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          szOrgid[4 + 1];         // ��������
    char          chMoneytype;            // ���Ҵ���
    char          chMarket;               // �����г�
    char          szSecuid[10 + 1];       // ֤ȯ�˺�
    char          chDebtsid;              // ��ծ����
    char          szSno[16 + 1];          // ������ˮ��
    int           iQsdate;                // ��������
    int           iJsdate;                // ��������
    char          szLastmktvalue[21 + 1]; // T-1�ճ�����ֵ
    char          szSettrate[21 + 1];     // �������
    char          szCombinfeeHk[21 + 1];  // �۱�Ӧ�ո����
    char          szCombinfeeRmb[21 + 1]; // �����Ӧ�ո����
    char          szRemark[128 + 1];      // ��ע
};
//-------------------------------10101715:�۹�ͨ�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkDeliveryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkDeliveryField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ί������
    int           iOrdertime;           // ί��ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ�����˵��
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // ����������
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ�����
    int           iMatchtimes;          // �ɽ�����
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szFundeffect[21 + 1]; // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeJsxf[21 + 1];    // ��׼������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �ɷݽ��շ�
    char          szFeeJygf[21 + 1];    // ���׷�
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFeeJsf[21 + 1];     // ����ϵͳʹ�÷ѷ�
    char          szFeeZgf[21 + 1];     // ��������
    char          szFeeQtf[21 + 1];     // ������
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�(�۱�)
    char          szFeeOneYhs[21 + 1];  // һ��ӡ��˰
    char          szFeeOneGhf[21 + 1];  // һ��������
    char          szFeeOneQsf[21 + 1];  // һ���ɷݽ��շ�
    char          szFeeOneJygf[21 + 1]; // һ�����׷�
    char          szFeeOneJsf[21 + 1];  // һ������ϵͳʹ�÷�
    char          szFeeOneZgf[21 + 1];  // һ����������
    char          szFeeOneQtf[21 + 1];  // һ��������
    char          szFeeOneFxj[21 + 1];  // һ�����ս�
    char          szSettrate[21 + 1];   // �������
};
//-------------------------------10101716:�۹�ͨ���ʵ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkStatementField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkStatementField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iOrderdate;           // ��������
    int           iOrdertime;           // ����ʱ��
    int           iDigestid;            // ҵ�����
    char          szDigestname[16 + 1]; // ҵ��˵��
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          chMarket;             // �г�����
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szFundeffect[21 + 1]; // �ʽ�����
    char          szFundbal[21 + 1];    // �ʽ𱾴����
    int           iStkbal;              // �ɷݱ������
    char          szOrderid[10 + 1];    // ��ͬ���
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    int           iMatchqty;            // �ɽ�����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szSettrate[21 + 1];   // �������
};
//-------------------------------10101717:�۹�ͨ��С�۲��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkMinSpreadField
{
    char          chMarket;         // �����г�
    char          chStktype;        // ֤ȯ���
    char          szPrice[21 + 1];  // ί�м۸�
};
struct MATRADEAPI CRspStkQryRpcHkMinSpreadField
{
    char          chMarket;             // �����г�
    char          chStktype;            // ֤ȯ���
    char          szBeginprice[21 + 1]; // �۸�����
    char          szEndprice[21 + 1];   // �۸�����
    char          szPriceunit[21 + 1];  // ��λ
};
//-------------------------------10101718:�۹�ͨ�ο����ʲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkExchangeRateField
{
    char          chMarket;         // �����г�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspStkQryRpcHkExchangeRateField
{
    char          chMarket;                    // �����г�
    char          chMoneytype;                 // ����
    char          szBuyrate[21 + 1];           // ����ο�����
    char          szDaybuyriserate[21 + 1];    // �ռ�����ο����ʸ�������
    char          szNightbuyriserate[21 + 1];  // ҹ������ο����ʸ�������
    char          szSalerate[21 + 1];          // �����ο�����
    char          szDaysaleriserate[21 + 1];   // �ռ������ο����ʸ�������
    char          szNightsaleriserate[21 + 1]; // ҹ�������ο����ʸ�������
    char          szMidrate[21 + 1];           // �м�ο�����
    int           iSysdate;                    // ʹ������
    char          szSettrate[21 + 1];          // �������
    char          szRemark[128 + 1];           // ��ע
};
//-------------------------------10101719:�۹�ͨ�г�����״̬��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkMarketStatusField
{
    char          chMarket;         // �����г�
};
struct MATRADEAPI CRspStkQryRpcHkMarketStatusField
{
    char          chMarket;          // �����г�
    LONGLONG      llQuotabal;        // ÿ�ճ�ʼ���
    LONGLONG      llQuotaavl;        // ����ʣ����
    char          chQuotastatus;     // ���״̬
    char          chMkttrdstatus;    // �г�����״̬
    int           iUpddate;          // ��������
    char          szRemark[128 + 1]; // ��ע
};
//-------------------------------10101720:�۹�ͨ���֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkUnderlyingSecurityField
{
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcHkUnderlyingSecurityField
{
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szStkname[64 + 1]; // ֤ȯ����
    char          chZstrdstatus;     // ���ֽ���״̬
    char          chLgtrdstatus;     // ��ɽ���״̬
    int           iUpddate;          // ��������
    char          szRemark[128 + 1]; // ��ע
};
//-------------------------------10101721:�۹�ͨ����������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkCalendarField
{
    int           iPhydate;          // ��������
    int           iEnddate;          // ��������
    char          chMarket;          // �����г�
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkCalendarField
{
    char          szPoststr[32 + 1]; // ��λ��
    char          chMarket;          // �����г�
    char          chMoneytype;       // ����
    int           iPhydate;          // ��������
    char          chBusinessflag;    // �����ձ�ʶ
    char          chCommitflag;      // �����ձ�ʶ
};
//-------------------------------10101722:�۹�ͨί����������--------------------------
struct MATRADEAPI CReqStkRpcHkOrderField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��˻�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szBsflag[2 + 1];  // �������
    char          szPrice[21 + 1];  // �۸�(�۸�)
    int           iQty;             // ����
    int           iOrdergroup;      // ί������
    char          chTimeinforce;    // ������Чʱ������
    LONGLONG      llRisksignsno;    // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcHkOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
};
//-------------------------------10101723:�۹�ͨ����ί��--------------------------
struct MATRADEAPI CReqStkRpcHkCancelField
{
    int           iOrderdate;       // ί������
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iOrdersno;        // ί�����
    char          szBsflag[2 + 1];  // �������
};
struct MATRADEAPI CRspStkRpcHkCancelField
{
    int           iOrdersno; // ����ί�����
};
//-------------------------------10101724:ί�г�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkCancelField
{
    int           iOrderdate;        // ί������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkCancelField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iOrdersno;            // ί�����
    int           iOrdergroup;          // ί������
    char          szOrderid[10 + 1];    // ��ͬ���
    int           iOrderdate;           // ί������
    int           iOpertime;            // ί��ʱ��
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMarket;             // �г�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];      // �������
    char          szOrderprice[21 + 1]; // ί�м۸�(�۱�)
    int           iOrderqty;            // ί������
    int           iMatchqty;            // �ɽ�����
    char          chOrderstatus;        // ί��״̬
    char          chCancelstatus;       // ����״̬
};
//-------------------------------10101725:�۹�ͨ���ɽ���������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkMaxTradeQtyField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szBsflag[2 + 1];  // ��������
    char          szPrice[21 + 1];  // �۸�(�۱�)
};
struct MATRADEAPI CRspStkQryRpcHkMaxTradeQtyField
{
    int           iMaxstkqty; // ���������
};
//-------------------------------10101726:�۹�ͨ����ί����ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkOrderDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iOrdergroup;       // ί������
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkOrderDetailField
{
    char          szPoststr[32 + 1];        // ��λ��
    int           iOrderdate;               // ί������
    int           iOrdersno;                // ί�����
    int           iOrdergroup;              // ί������
    LONGLONG      llCustid;                 // �ͻ�����
    char          szCustname[16 + 1];       // �ͻ�����
    LONGLONG      llFundid;                 // �ʽ��˻�
    char          chMoneytype;              // ����
    char          szOrgid[4 + 1];           // ��������
    char          szSecuid[10 + 1];         // �ɶ�����
    char          szBsflag[2 + 1];          // �������
    char          szOrderid[10 + 1];        // �걨��ͬ���
    int           iReporttime;              // ����ʱ��
    int           iOpertime;                // ί��ʱ��
    char          chMarket;                 // �����г�
    char          szStkcode[8 + 1];         // ֤ȯ����
    char          szStkname[64 + 1];        // ֤ȯ����
    char          szOrderprice[21 + 1];     // ί�м۸�(�۱�)
    int           iOrderqty;                // ί������
    char          szOrderfrzamtRmb[21 + 1]; // ������(�����)
    int           iMatchqty;                // �ɽ�����
    char          szMatchamt[21 + 1];       // �ɽ����(�۱�)
    int           iCancelqty;               // ��������
    char          chOrderstatus;            // ί��״̬
    char          chCancelstatus;           // ����״̬
    char          szSeat[6 + 1];            // ����ϯλ
    char          chCancelflag;             // ������ʶ
    int           iOperdate;                // ��������
    char          szReferrate[21 + 1];      // �ο�����
    char          szRemark[128 + 1];        // ��ע
    char          szAfundamt[21 + 1];       // A���ʽ�䶯���
    char          szHfundamt[21 + 1];       // �۹��ʽ�䶯���
};
//-------------------------------10101727:�۹�ͨ���׳ɽ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkMatchField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkMatchField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iTrddate;             // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // �걨��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�(�۱�)
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����(�۱�)
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�(�۱�)
};
//-------------------------------10101728:�۹�ͨ������ʷί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkHisOrderField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    int           iOrdergroup;       // ί������
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkHisOrderField
{
    char          szPoststr[32 + 1];        // ��λ��
    int           iOrderdate;               // ί������
    LONGLONG      llCustid;                 // �ͻ�����
    char          szCustname[16 + 1];       // �ͻ�����
    LONGLONG      llFundid;                 // �ʽ��˻�
    char          chMoneytype;              // ����
    char          szOrgid[4 + 1];           // ��������
    char          szSecuid[10 + 1];         // �ɶ�����
    char          szBsflag[2 + 1];          // �������
    char          szOrderid[10 + 1];        // �걨��ͬ���
    int           iOrdergroup;              // ί������
    int           iReporttime;              // ����ʱ��
    int           iOpertime;                // ί��ʱ��
    char          chMarket;                 // �����г�
    char          szStkcode[8 + 1];         // ֤ȯ����
    char          szStkname[64 + 1];        // ֤ȯ����
    char          szOrderprice[21 + 1];     // ί�м۸�(�۱�)
    int           iOrderqty;                // ί������
    char          szOrderfrzamtRmb[21 + 1]; // ���������ң�
    int           iMatchqty;                // �ɽ�����
    char          szMatchamt[21 + 1];       // �ɽ����(�۱�)
    int           iCancelqty;               // ��������
    char          chCancelflag;             // ������־
    char          chOrderstatus;            // ί��״̬
    char          chCancelstatus;           // ����״̬
    char          szSeat[6 + 1];            // ����ϯλ
    char          chOperway;                // ������ʽ
    int           iOperdate;                // ��������
    char          szReferrate[21 + 1];      // �ο�����
    char          szAfundamt[21 + 1];       // A���ʽ�䶯���
    char          szHfundamt[21 + 1];       // �۹��ʽ�䶯���
};
//-------------------------------10101729:�۹�ͨ���׳ɽ���ʷ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcHkHisMatchField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcHkHisMatchField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iBizdate;             // ��������
    int           iCleardate;           // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    char          szOrderid[10 + 1];    // �걨��ͬ���
    int           iOrdersno;            // ί�����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�(�۱�)
    int           iStkbal;              // �ɷݱ������
    char          szFeeJsxf[21 + 1];    // ��������
    char          szFeeSxf[21 + 1];     // ������
    char          szFeeYhs[21 + 1];     // ӡ��˰
    char          szFeeGhf[21 + 1];     // ������
    char          szFeeQsf[21 + 1];     // �����
    char          szFeeJygf[21 + 1];    // ���׹��
    char          szFeeJsf[21 + 1];     // ���ַ�
    char          szFeeZgf[21 + 1];     // ֤�ܷ�
    char          szFeeQtf[21 + 1];     // ������
    char          szFeefront[21 + 1];   // ǰ̨����
    char          szFundeffect[21 + 1]; // �ʽ�����
    char          szFundbal[21 + 1];    // ʹ�ý��
    char          szSettrate[21 + 1];   // �������
};
//-------------------------------10101730:��תϵͳ֤ȯί���걨--------------------------
struct MATRADEAPI CReqStkRpcStkTranSysStkOrderField
{
    char          chMarket;               // �����г�
    LONGLONG      llFundid;               // �ʽ��˻�
    char          szSecuid[10 + 1];       // �ɶ�����
    char          szBsflag[2 + 1];        // �������
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          szPrice[21 + 1];        // ί�м۸�
    int           iQty;                   // ί������
    int           iOrdergroup;            // ί������
    char          szLinkman[12 + 1];      // ��ϵ��
    char          szLinkway[30 + 1];      // ��ϵ��ʽ
    char          szTargetseat[6 + 1];    // �Է�ϯλ
    char          szTargetsecuid[10 + 1]; // �Է��ɶ��˻�
    char          szConfernum[21 + 1];    // �ɽ�Լ����
    LONGLONG      llRisksignsno;          // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcStkTranSysStkOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
    int           iOrdergroup;       // ί������
};
//-------------------------------10101731:��תϵͳЭ��ת�������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkTranSysAgreementTransferMktField
{
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];     // ί�����
    char          szConfernum[21 + 1]; // �ɽ�Լ����
    char          szOrdertime[6 + 1];  // ί��ʱ��
};
struct MATRADEAPI CRspStkQryRpcStkTranSysAgreementTransferMktField
{
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szSeat[6 + 1];        // ϯλ����
    char          szBsflag[2 + 1];      // ί�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szConfernum[21 + 1];  // �ɽ�Լ����
    char          szOrdertime[6 + 1];   // ί��ʱ��
    int           iStatus;              // ��¼״̬
    char          chRemark;             // ���ñ�־
};
//-------------------------------10101732:��תϵͳȡ���������,֧����������--------------------------
struct MATRADEAPI CReqStkRpcStkTranSysMaxTradeQtyField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBsflag[2 + 1];   // �������
    char          szPrice[21 + 1];   // �۸�
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chHiqtyflag;       // ������ޱ�־
    char          chCreditid;        // ���ò�Ʒ��ʶ
    char          chCreditflag;      // ����ί������
};
struct MATRADEAPI CRspStkRpcStkTranSysMaxTradeQtyField
{
    int           iMaxstkqty; // �ɷ�����
};
//-------------------------------10101733:��תϵͳ����Ͷ���߲�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkTranSysRestrictedInvestorField
{
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szPosstr[64 + 1]; // ��λ��
    int           iCount;           // ��������
};
struct MATRADEAPI CRspStkQryRpcStkTranSysRestrictedInvestorField
{
    int           iServerid;        // �ڵ���
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ�����
    char          chMarket;         // �г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szPosstr[64 + 1]; // ��λ��
};
//-------------------------------10101734:��ת�г�����ͨ�ɷ�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcStkTranSysNonCirculatingSharesBalanceField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iCount;            // ��������
    char          szPoststr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcStkTranSysNonCirculatingSharesBalanceField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSeat[6 + 1];     // ϯλ
    char          szStkprop[2 + 1];  // �ɷ�����
    LONGLONG      llStkbal;          // �ɷ����
    LONGLONG      llStkavl;          // �ɷݿ���
    char          szPoststr[64 + 1]; // ��λ��
};
//-------------------------------10101735:����ƽ̨����ί����ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFixedIncomeSysOrderDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFixedIncomeSysOrderDetailField
{
    int           iOrderdate;            // ί������
    int           iOrdersno;             // ί�����
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMoneytype;           // ����
    char          szOrgid[4 + 1];        // ��������
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[10 + 1];     // �걨��ͬ���
    int           iReporttime;           // ����ʱ��
    int           iOpertime;             // ί��ʱ��
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    char          szOrderfrzamt[21 + 1]; // ������
    int           iMatchqty;             // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iCancelqty;            // ��������
    char          chOrderstatus;         // ί��״̬
    char          szSeat[6 + 1];         // ����ϯλ
    char          chCancelflag;          // ������ʶ
    int           iOperdate;             // ��������
    int           iConfernum;            // Լ����
    char          szTargettrader[6 + 1]; // �Է�����Ա
    char          szRemark[128 + 1];     // ��ע
    char          szPoststr[32 + 1];     // ��λ��
};
//-------------------------------10101736:����ƽ̨������ʷί����ϸ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFixedIncomeSysHisOrderDetailField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʺ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFixedIncomeSysHisOrderDetailField
{
    int           iOrderdate;            // ί������
    LONGLONG      llCustid;              // �ͻ�����
    char          szCustname[16 + 1];    // �ͻ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMoneytype;           // ����
    char          szOrgid[4 + 1];        // ��������
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[10 + 1];     // �걨��ͬ���
    int           iReporttime;           // ����ʱ��
    int           iOpertime;             // ί��ʱ��
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    char          szOrderfrzamt[21 + 1]; // ������
    int           iMatchqty;             // �ɽ�����
    char          szMatchamt[21 + 1];    // �ɽ����
    int           iCancelqty;            // ��������
    char          chCancelflag;          // ������־
    char          chOrderstatus;         // ί��״̬
    char          szSeat[6 + 1];         // ����ϯλ
    char          chOperway;             // ������ʽ
    int           iOperdate;             // ��������
    int           iConfernum;            // Լ����
    char          szTargettrader[6 + 1]; // �Է�����Ա
    char          szPoststr[32 + 1];     // ��λ��
};
//-------------------------------10101737:����ƽ̨���׳ɽ���ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFixedIncomeSysMatchField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFixedIncomeSysMatchField
{
    int           iTrddate;             // �ɽ�����
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szBsflag[2 + 1];      // �������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // �걨��ͬ���
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    int           iMatchtime;           // �ɽ�ʱ��
    char          szMatchcode[20 + 1];  // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          szPoststr[32 + 1];    // ��λ��
};
//-------------------------------10101738:����ƽ̨���ɽ���������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFixedIncomeSysMaxTradeQtyField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szBsflag[2 + 1];  // ��������
    char          szPrice[21 + 1];  // �۸�
};
struct MATRADEAPI CRspStkQryRpcFixedIncomeSysMaxTradeQtyField
{
    int           iMaxstkqty; // ���������
};
//-------------------------------10101739:����ƽ̨ί����������--------------------------
struct MATRADEAPI CReqStkRpcFixedIncomeSysOrderField
{
    char          chMarket;              // �����г�
    char          szSecuid[10 + 1];      // �ɶ�����
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szBsflag[2 + 1];       // �������
    char          szPrice[21 + 1];       // �۸�
    int           iQty;                  // ����
    int           iConfernum;            // Լ����
    char          szTargettrader[6 + 1]; // �Է�����Ա���
    LONGLONG      llRisksignsno;         // ���ս�ʾǩ����ˮ��
};
struct MATRADEAPI CRspStkRpcFixedIncomeSysOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10101740:����ƽ̨����ί��--------------------------
struct MATRADEAPI CReqStkRpcFixedIncomeSysCancelField
{
    int           iOrderdate;       // ί������
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iOrdersno;        // ί�����
    char          szBsflag[2 + 1];  // �������
};
struct MATRADEAPI CRspStkRpcFixedIncomeSysCancelField
{
    int           iOrdersno; // ����ί�����
};
//-------------------------------10101741:ί�г�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFixedIncomeSysCancelField
{
    int           iOrderdate;        // ί������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFixedIncomeSysCancelField
{
    int           iOrdersno;             // ί�����
    char          szOrderid[10 + 1];     // ��ͬ���
    int           iOrderdate;            // ί������
    int           iOpertime;             // ί��ʱ��
    LONGLONG      llFundid;              // �ʽ��ʻ�
    char          chMarket;              // �ͻ�����
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szBsflag[2 + 1];       // �������
    char          szOrderprice[21 + 1];  // ί�м۸�
    int           iOrderqty;             // ί������
    int           iMatchqty;             // �ɽ�����
    int           iConfernum;            // Լ����
    char          szTargettrader[6 + 1]; // �Է�����Ա
    char          chOrderstatus;         // ί��״̬
    char          szPoststr[32 + 1];     // ��λ��
};
//-------------------------------10101742:ծȯ������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondBasicInfoField
{
    char          chMarket;         // �г�
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcBondBasicInfoField
{
    int           iServerid;                // ��������
    char          chMarket;                 // �г�
    char          szStkcode[6 + 1];         // ֤ȯ����
    char          szBondname[8 + 1];        // ծȯ���
    char          szBondfullname[64 + 1];   // ծȯȫ��
    char          chStktype;                // ֤ȯ����
    char          szIssueqty[21 + 1];       // ������
    char          szTicketprice[21 + 1];    // ծȯ��ֵ
    char          chOffertype;              // ���۷�ʽ
    char          szIssueprice[21 + 1];     // ���м۸�
    char          chBaseintrtype;           // ��׼��������
    char          chIntrtype;               // ��Ϣ����
    char          szExchrate[21 + 1];       // ��׼ծȯ�ۺϱ���
    int           iIssuedate;               // ��������
    int           iListingdate;             // ��������
    int           iIntrcaldate;             // ��Ϣ����
    int           iIntrpaydate;             // ��Ϣ����
    char          szIntrpayrate[21 + 1];    // ��Ϣ˰��
    int           iPayvaluedate;            // �޸�����
    int           iExerdate;                // ��Ȩ����
    char          szBondintr[21 + 1];       // Ӧ����Ϣ
    char          szTaxrate[21 + 1];        // ������Ϣ����
    char          szIntrrate[21 + 1];       // ծȯ������
    int           iPaytimes;                // ��ϢƵ��
    int           iIntrenddate;             // ծȯ������
    char          szBondterm[21 + 1];       // ծȯ����
    char          szMaincreditlevel[6 + 1]; // �������õȼ�
    char          szBondcreditlevel[6 + 1]; // ծ�����õȼ�
    char          szTicketpriceadj[21 + 1]; // ���ڳ���������ֵ
    int           iRepaydate;               // ���ڳ�������
    char          chRisklevel;              // ���ռ���
    char          chProprietyflag;          // ծȯͶ�����ʵ���Ҫ����
};
//-------------------------------10101743:��̨ծȯ�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondMktField
{
    char          chMarket;            // �г�
    char          szStkcode[6 + 1];    // ֤ȯ����
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szOrderid[24 + 1];   // ��ͬ���
    char          szBsflag[128 + 1];   // �������
    char          szConfernum[21 + 1]; // Լ����
    char          szRecordid[21 + 1];  // ��¼��
    char          szRemark[2 + 1];     // ���ñ�־
};
struct MATRADEAPI CRspStkQryRpcBondMktField
{
    char          szRecordid[21 + 1];    // ��¼��
    char          chMarket;              // �г�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkcode[6 + 1];      // ֤ȯ����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szOrderqty[21 + 1];    // �걨����
    char          szOrderprice[21 + 1];  // �걨����
    char          szAllprice[21 + 1];    // �걨ȫ��
    char          szTicketprice[21 + 1]; // �ҵ���ֵ
    char          szBusitype[2 + 1];     // ҵ�����
    char          chCmdtype;             // ָ�����
    char          szBsflag[2 + 1];       // �������
    char          szOrderid[24 + 1];     // ��ͬ���
    char          szLinkman[12 + 1];     // ��ϵ��
    char          szLinkway[30 + 1];     // ��ϵ��ʽ
    char          szBranchid[5 + 1];     // ��������
    char          szSettleorg[2 + 1];    // �������
    int           iReporttime;           // �걨ʱ��
    int           iDeaddate;             // ʧЧ����
    char          szConfernum[21 + 1];   // Լ����
    char          szIncomerate[21 + 1];  // ����������
    char          szOrderqty2[21 + 1];   // �걨����2
    char          szOrderprice2[21 + 1]; // �걨�۸�2
    char          szIncomerate2[21 + 1]; // ����������2
    int           iStatus;               // ��¼״̬
    char          szBondlevel[6 + 1];    // ծȯ����
    char          szBondterm[21 + 1];    // ʣ������
    char          szIntrrate[21 + 1];    // Ʊ������
    char          szIntrendrate[21 + 1]; // ����������
    char          szExerrate[21 + 1];    // ��Ȩ������
    char          szBondintr[21 + 1];    // Ӧ����Ϣ
    char          szRemark[2 + 1];       // ���ñ�־
    char          szText[80 + 1];        // �����ı�
};
//-------------------------------10101744:��̨���Ʋ�Ʒ�ݶ�ת�ó���--------------------------
struct MATRADEAPI CReqStkRpcFinancialProductShareTransferCancelField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szOrderid[24 + 1]; // ��ͬ���
};
struct MATRADEAPI CRspStkRpcFinancialProductShareTransferCancelField
{
    int           iSno; // ί�����
};
//-------------------------------10101745:��̨���Ʋ�Ʒ�ݶ�ת��ҵ��--------------------------
struct MATRADEAPI CReqStkRpcFinancialProductShareTransferField
{
    char          chMarket;             // �����г�
    LONGLONG      llFundid;             // �ʽ��ʻ�
    int           iTacode;              // ����˾
    char          szTaacc[12 + 1];      // �����ʺ�
    char          szTransacc[17 + 1];   // �����ʺ�
    char          szOfcode[6 + 1];      // ��Ʒ����
    char          szBsflag[2 + 1];      // ��������
    char          szOrderid[24 + 1];    // ��ͬ���
    char          szOrderprice[21 + 1]; // �ɽ��۸�
    char          szOrderqty[21 + 1];   // ί�зݶ�
    char          szConfernum[32 + 1];  // Լ����
    int           iDeaddate;            // ʧЧ����
    char          szOldorderid[24 + 1]; // ԭ��ͬ���
    char          szLinkname[17 + 1];   // ��ϵ������
    char          szLinktelno[32 + 1];  // ��ϵ�˵绰
    LONGLONG      llRisksignsno;        // ���ս�ʾǩ����ˮ��
    char          szRemark[64 + 1];     // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcFinancialProductShareTransferField
{
    int           iSno;              // ί�����
    char          szOrderid[24 + 1]; // ��ͬ���
};
//-------------------------------10101746:��̨���Ʋ�Ʒת����ϵ����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFinancialProductShareTransferContactInfoField
{
    char          szOrgid[4 + 1];   // ��������
    char          szName[16 + 1];   // ��ϵ������
    char          szTelno[32 + 1];  // ��ϵ�绰
    char          chDefaultflag;    // Ĭ�ϱ�ʶ
};
struct MATRADEAPI CRspStkQryRpcFinancialProductShareTransferContactInfoField
{
    char          szOrgid[4 + 1];  // ��������
    char          szName[16 + 1];  // ��ϵ������
    char          szTelno[32 + 1]; // ��ϵ�绰
    char          chDefaultflag;   // Ĭ�ϱ�ʶ
};
//-------------------------------10101747:��̨���Ʋ�Ʒ�ݶ�ת�÷��ü���--------------------------
struct MATRADEAPI CReqStkRpcFinancialProductShareTransferFeeField
{
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szOfcode[6 + 1];      // ��Ʒ����
    char          szBsflag[2 + 1];      // ��������
    char          szOrderprice[21 + 1]; // �ɽ��۸�
    char          szOrderqty[21 + 1];   // ί�зݶ�
};
struct MATRADEAPI CRspStkRpcFinancialProductShareTransferFeeField
{
    char          szOrderfee[21 + 1]; // ί��Ӷ��
};
//-------------------------------10101748:��̨ծȯ������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondParamInfoField
{
    char          chMarket;         // �г�
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          chOffermode;      // ���۷�ʽ
};
struct MATRADEAPI CRspStkQryRpcBondParamInfoField
{
    int           iServerid;        // �ڵ���
    char          chMarket;         // �г�
    char          szStkcode[6 + 1]; // ֤ȯ����
    char          chOffermode;      // ���۷�ʽ
    char          szBsflag[2 + 1];  // �������
    char          chCancelflag;     // ������־
    int           iBuyunit;         // ���뵥λ
    int           iSaleunit;        // ������λ
    int           iMaxqty;          // �����������
    int           iMinqty;          // �����������
};
//-------------------------------10101749:����ί����ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcBondIntentionOrderStatementField
{
    char          szOrgid[4 + 1];   // ��������
    char          szBsflag[2 + 1];  // �������
    LONGLONG      llCustid;         // �ͻ�����
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chStatus;         // ״̬
    char          chDatetype;       // ��������
    int           iBegindate;       // ��ʼ����
    int           iEnddate;         // ��������
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcBondIntentionOrderStatementField
{
    char          szPosstr[64 + 1];     // ��λ��
    int           iServerid;            // �ڵ���
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // ��ͬ���
    int           iOrderdate;           // ί������
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llFundid;             // �ʽ��˺�
    LONGLONG      llCustid;             // �ͻ�����
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // ֤ȯ�˺�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iOrderqty;            // ί������
    char          szLinkname[16 + 1];   // ��ϵ��
    char          szLinktelno[32 + 1];  // ��ϵ�˵绰
    char          szBsflag[2 + 1];      // �������
    int           iDeaddate;            // ʧЧ����
    char          chStatus;             // ״̬
};
//-------------------------------10101750:��̨���Ʋ�Ʒ�����ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFinancialProductMarketField
{
    char          chMarket;            // �г�
    char          szOfcode[6 + 1];     // ��Ʒ����
    char          szTaacc[12 + 1];     // �����ʺ�
    char          szOrderid[24 + 1];   // ��ͬ���
    char          szBsflag[128 + 1];   // �������
    char          szConfernum[21 + 1]; // Լ����
    char          szRecordid[21 + 1];  // ��¼��
    char          szRemark[2 + 1];     // ���ñ�־
};
struct MATRADEAPI CRspStkQryRpcFinancialProductMarketField
{
    char          szRecordid[21 + 1];   // ��¼��
    char          chMarket;             // �г�
    char          szTaacc[12 + 1];      // �����ʺ�
    char          szOfcode[6 + 1];      // ��Ʒ����
    char          szOfname[20 + 1];     // ��Ʒ����
    char          szOrderqty[21 + 1];   // �걨����
    char          szOrderprice[21 + 1]; // �걨����
    char          szBusitype[2 + 1];    // ҵ�����
    char          chCmdtype;            // ָ�����
    char          szOrderid[24 + 1];    // ��ͬ���
    char          szLinkman[12 + 1];    // ��ϵ��
    char          szLinkway[30 + 1];    // ��ϵ��ʽ
    char          szBranchid[5 + 1];    // ��������
    int           iReporttime;          // �걨ʱ��
    int           iDeaddate;            // ʧЧ����
    char          szConfernum[21 + 1];  // Լ����
    int           iStatus;              // ��¼״̬
    char          szRemark[2 + 1];      // ���ñ�־
    char          szText[80 + 1];       // �����ı�
};
//-------------------------------10101751:��̨���Ʋ�Ʒί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFinancialProductOrderField
{
    char          chOrgid;           // ��������
    LONGLONG      llFundid;          // �ʽ��ʻ�
    int           iTacode;           // ����˾
    char          szOfcode[6 + 1];   // ��Ʒ����
    char          szBsflag[2 + 1];   // ��������
    char          szOrderid[24 + 1]; // ��ͬ���
    int           iOrderdate;        // ί������
    char          szPoststr[21 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcFinancialProductOrderField
{
    int           iSno;                 // ί�����
    char          szOrderid[24 + 1];    // ��ͬ���
    char          chMarket;             // �г�
    char          szTaacc[12 + 1];      // �����ʺ�
    char          szOfcode[6 + 1];      // ��Ʒ����
    char          szOfname[20 + 1];     // ��Ʒ����
    char          szOrderqty[21 + 1];   // �걨����
    char          szOrderprice[21 + 1]; // �걨����
    char          szBsflag[2 + 1];      // �������
    char          szLinkman[12 + 1];    // ��ϵ��
    char          szLinkway[30 + 1];    // ��ϵ��ʽ
    char          szBranchid[5 + 1];    // ��������
    int           iReporttime;          // �걨ʱ��
    int           iDeaddate;            // ʧЧ����
    char          szConfernum[21 + 1];  // Լ����
    int           iOrderstatus;         // ί��״̬
    char          chStatus;             // ״̬
    char          szPoststr[21 + 1];    // ��λ��
};
//-------------------------------10101752:֤ȯ����ί����Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkRpcRefinancingStkLendingOrderField
{
    char          chDataOri;            // ������Դ
    int           iOrgCode;             // ��֧����
    LONGLONG      llCustCode;           // �ͻ�����
    char          chMarket;             // �г�����
    char          szSecuAcc[10 + 1];    // ֤ȯ�˻�
    char          szSecuCode[8 + 1];    // ֤ȯ����
    LONGLONG      llLendQty;            // ��������
    int           iCreditDays;          // ת��ͨ����
    char          chReqSrc;             // ������Դ
    char          chReportType;         // �걨����
    char          szOpSecuAcc[10 + 1];  // ���ַ�֤ȯ�˺�
    char          szOpTradeUnit[6 + 1]; // ���ַ����׵�Ԫ
    int           iAgreementId;         // Լ����
    char          szTradeUnit[6 + 1];   // ���׵�Ԫ
    char          chChannel;            // ����
    char          chStockChkFlag;       // �ɷݼ���־
    char          chStockFrozenFlag;    // �ɷݶ����־
    LONGLONG      llAccount;            // �ʲ��˻�
    char          chSendFlag;           // ����ʽ
};
struct MATRADEAPI CRspStkRpcRefinancingStkLendingOrderField
{
    char          szOrderId[10 + 1]; // ί�б��
    LONGLONG      llReqId;           // �������
};
//-------------------------------10101753:֤ȯ����ί�г�����Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkRpcRefinancingStkLendingCancelField
{
    char          chDataOri;           // ������Դ
    int           iOrgCode;            // ��֧����
    LONGLONG      llCustCode;          // �ͻ�����
    char          chMarket;            // �г�����
    char          szSecuAcc[10 + 1];   // ֤ȯ�˻�
    LONGLONG      llReqId;             // �������
    LONGLONG      llOrderSno;          // ί�����
    char          chStockUnfrozenFlag; // �ɷݽⶳ��־
    LONGLONG      llAccount;           // �ʲ��˻�
};
struct MATRADEAPI CRspStkRpcRefinancingStkLendingCancelField
{
};
//-------------------------------10101754:ί�в�ѯ��Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingOrderField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    char          szSecuCode[8 + 1]; // ֤ȯ����
    int           iCreditDays;       // ת��ͨ����
    char          szOrderId[10 + 1]; // ί�б��
    LONGLONG      llOrderSno;        // ί�����
    char          szPosstr[256 + 1]; // ��λ��
    int           iCount;            // ÿҳ����
};
struct MATRADEAPI CRspStkQryRpcRefinancingOrderField
{
    char          szOrderId[10 + 1];   // ί�б��
    int           iTrdDate;            // ��������
    char          chMarket;            // �г�����
    char          szSecuAcc[10 + 1];   // ֤ȯ�ʺ�
    char          szSecuCode[8 + 1];   // ֤ȯ����
    char          szSecuName[64 + 1];  // ֤ȯ����
    char          szPub[6 + 1];        // ���׵�Ԫ
    LONGLONG      llLendQty;           // ��������
    int           iCreditDays;         // ת��ͨ����
    char          szBusiCode[4 + 1];   // ��������
    char          szOpSecuAcc[10 + 1]; // ���ַ�֤ȯ�ʺ�
    char          szOpPub[6 + 1];      // ���ַ����׵�Ԫ
    char          szOpOrderId[10 + 1]; // ���ַ�ί�б��
    char          chOrderStatus;       // ί��״̬
    char          chValidFlag;         // �Ϸ���ʶ
    LONGLONG      llReqId;             // ������
    char          szPosstr[256 + 1];   // ��λ��
    int           iOrgCode;            // ��������
    LONGLONG      llCustCode;          // �ͻ�����
    LONGLONG      llAccount;           // �ʽ��˺�
    char          szAfrReason[2 + 1];  // ��ǰ����ԭ��
};
//-------------------------------10101755:��ǰ������Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkRpcRefinancingAdvanceRevertField
{
    char          chMarket;           // �г�����
    char          szSecuAcc[10 + 1];  // ֤ȯ�ʺ�
    int           iOpeningDate;       // ��������
    LONGLONG      llContractNo;       // ��Լ���
    LONGLONG      llAfrQty;           // ��������
    char          szAfrReason[2 + 1]; // ��ǰ����ԭ��
};
struct MATRADEAPI CRspStkRpcRefinancingAdvanceRevertField
{
    char          szOrderId[10 + 1]; // ί�б��
};
//-------------------------------10101756:ͬ��չ����Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkRpcRefinancingExtentionApproveField
{
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    int           iOpeningDate;      // ��������
    LONGLONG      llContractNo;      // ��Լ���
    LONGLONG      llOpContractNo;    // ���ַ���Լ���
    char          chOpFlag;          // ͬ��չ��������־
    LONGLONG      llExQty;           // չ������
};
struct MATRADEAPI CRspStkRpcRefinancingExtentionApproveField
{
    char          szOrderId[10 + 1]; // ί�б��
};
//-------------------------------10101757:֤ȯ����ɳ���¼��ѯ��Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingStkLendingCanWithdrawField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    char          szSecuCode[6 + 1]; // ֤ȯ����
    char          szOrderId[10 + 1]; // ί�б��
    char          szPosstr[64 + 1];  // ��λ��
    int           iCount;            // ÿҳ����
};
struct MATRADEAPI CRspStkQryRpcRefinancingStkLendingCanWithdrawField
{
    char          szPosstr[64 + 1];     // ��λ��
    LONGLONG      llReqId;              // ������
    char          szOrderId[10 + 1];    // ί�б��
    LONGLONG      llOrderSno;           // ί�����
    int           iTrdDate;             // ��������
    char          chMarket;             // �г�����
    char          szSecuAcc[10 + 1];    // ֤ȯ�˺�
    char          szSecuCode[6 + 1];    // ֤ȯ����
    char          szSecuName[64 + 1];   // ֤ȯ����
    char          szTradeUnit[6 + 1];   // ���׵�Ԫ
    LONGLONG      llLendQty;            // ��������
    int           iCreditDays;          // ת��ͨ����
    char          szBusiCode[4 + 1];    // ��������
    char          szOpSecuAcc[10 + 1];  // ���ַ�֤ȯ�˺�
    char          szOpTradeUnit[6 + 1]; // ���ַ����׵�Ԫ
    char          szOpOrderId[10 + 1];  // ���ַ�ί�б��
    int           iAgreementId;         // Լ����
};
//-------------------------------10101758:ת��ȯδ�˽��Լ��ѯ��Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingOpenContractField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    char          szSecuCode[6 + 1]; // ֤ȯ����
    char          chRfsClsdtFlag;    // ת��ȯҵ������
    int           iCreditDays;       // ת��ͨ����
    int           iBgnDate;          // ��ʼ����
    int           iEndDate;          // ��������
    char          szPosstr[64 + 1];  // ��λ��
    int           iCount;            // ÿҳ����
};
struct MATRADEAPI CRspStkQryRpcRefinancingOpenContractField
{
    char          szPosstr[64 + 1];       // ��λ��
    LONGLONG      llContractNo;           // ��Լ���
    int           iOpeningDate;           // ��������
    char          chMarket;               // �����г�
    char          szSecuAcc[10 + 1];      // ֤ȯ�ʺ�
    char          szSecuCode[8 + 1];      // ֤ȯ����
    char          szPub[6 + 1];           // ���׵�Ԫ
    char          chRfsClsdtFlag;         // ת��ȯҵ������
    int           iCreditDays;            // ת��ͨ����
    LONGLONG      llContractQty;          // ��Լ����
    char          szIntendingFee[21 + 1]; // ��ԼԤ����Ϣ
    int           iCloseDate;             // ��Լ������
    char          szContractAmt[21 + 1];  // ��Լ���
    char          chExAfrFlag;            // ͬ��չ��������־
    char          szSecuName[64 + 1];     // ֤ȯ����
    char          szCreditRate[21 + 1];   // ת��ͨϢ����
};
//-------------------------------10101759:�ɳ�����ȯ��ѯ��Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingUnderlyingStkForLendingField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuCode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcRefinancingUnderlyingStkForLendingField
{
    char          chMarket;             // �г�����
    char          chRfsCls;             // ת��ȯҵ������
    int           iCreditDays;          // ת��ͨ����
    char          szSecuCode[8 + 1];    // ֤ȯ����
    char          szStdFeeRate[21 + 1]; // ��׼����
    char          szFeeRate[21 + 1];    // ����
    char          chExFlag;             // չ�ڱ�־
    char          chAfrFlag;            // ������־
    char          chRfFlag;             // ת��ͨ��־
};
//-------------------------------10101760:��������Ϣ��ѯ��Χ�ӿ�--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingLenderInfoField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
};
struct MATRADEAPI CRspStkQryRpcRefinancingLenderInfoField
{
    char          chDataOri;          // ������Դ
    int           iOrgCode;           // ��������
    LONGLONG      llCustCode;         // �ͻ�����
    char          szCustName[32 + 1]; // �ͻ�����
    char          chCustCls;          // �ͻ����
    char          chCustStatus;       // �ͻ�״̬
    char          chCurrency;         // ���Ҵ���
    char          chMarket;           // �����г�
    char          szSecuAcc[10 + 1];  // ֤ȯ�˻�
    char          chSecuStatus;       // �ɶ�״̬
    char          chSecuCls;          // �ɶ�����
    char          chLendFlag;         // �����־
    char          chRfsFlag;          // ��ȯԤԼ��־
    char          szTradeUnit[6 + 1]; // ���׵�Ԫ
    int           iContrBgnDate;      // ��ͬ��ʼ����
    int           iContrEndDate;      // ��ͬ��������
    char          chContrStatus;      // ��ͬ״̬
};
//-------------------------------10101761:��ʷ����ί�в�ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingHisLendingOrderField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    int           iBgnDate;          // ��ʼ����
    int           iEndDate;          // ��������
    char          szSecuCode[8 + 1]; // ֤ȯ����
    int           iCreditDays;       // ת��ͨ����
    char          szOrderId[10 + 1]; // ί�б��
    LONGLONG      llOrderSno;        // ί�����
    char          szPosstr[256 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcRefinancingHisLendingOrderField
{
    char          szOrderId[10 + 1];   // ί�б��
    int           iOrderDate;          // ί������
    char          chMarket;            // �г�����
    char          szSecuAcc[10 + 1];   // ֤ȯ�ʺ�
    char          szSecuCode[8 + 1];   // ֤ȯ����
    char          szSecuName[64 + 1];  // ֤ȯ����
    char          szPub[6 + 1];        // ���׵�Ԫ
    LONGLONG      llOrderQty;          // ��������
    int           iCreditDays;         // ת��ͨ����
    char          szBusiCode[4 + 1];   // ��������
    char          szOpSecuAcc[10 + 1]; // ���ַ�֤ȯ�ʺ�
    char          szOpPub[6 + 1];      // ���ַ����׵�Ԫ
    char          szOpOrderId[10 + 1]; // ���ַ�ί�б��
    char          chOrderStatus;       // ί��״̬
    char          chValidFlag;         // �Ϸ���ʶ
    LONGLONG      llOrderSno;          // ί�����
};
//-------------------------------10101762:֤ȯ�������˽��Լ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcRefinancingStkLendingClosedContractField
{
    int           iOrgCode;          // ��������
    LONGLONG      llCustCode;        // �ͻ�����
    char          chMarket;          // �г�����
    char          szSecuAcc[10 + 1]; // ֤ȯ�ʺ�
    int           iBgnDate;          // ��ʼ����
    int           iEndDate;          // ��������
    char          szSecuCode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspStkQryRpcRefinancingStkLendingClosedContractField
{
    char          szSettDate[10 + 1]; // ��������
    int           iTrdDate;           // �ɽ�����
    LONGLONG      llContractNo;       // ��Լ���
    int           iOpeningDate;       // ��������
    char          chBusiType;         // ת��ͨ���
    char          chMarket;           // �����г�
    char          szSecuAcc[10 + 1];  // ֤ȯ�ʺ�
    char          szPub[6 + 1];       // ���׵�Ԫ
    int           iCreditDays;        // ת��ͨ����
    LONGLONG      llContractQty;      // ��Լ����
    char          szSecuCode[8 + 1];  // ֤ȯ����
    LONGLONG      llSettQty;          // ��������
    LONGLONG      llSettAmt;          // ���ս��
    LONGLONG      llSettPrincipal;    // ���ձ���
    LONGLONG      llSettInterest;     // ������Ϣ
    LONGLONG      llSettPenalty;      // ���շ�Ϣ
    LONGLONG      llSettPenalSum;     // ����ΥԼ��
    LONGLONG      llSettOtherFee;     // ����������
    LONGLONG      llClosePrice;       // ���̼�
    char          szRemark[64 + 1];   // ��ע
    int           iClosedDate;        // ��������
};
//-------------------------------10101763:��ѯ�ͻ���Ԥ����Ϣ--------------------------
struct MATRADEAPI CReqStkQryRpcSysSecurityCustReservedInfoField
{
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // ��������
    char          szBrhid[4 + 1];   // ������֧
};
struct MATRADEAPI CRspStkQryRpcSysSecurityCustReservedInfoField
{
    char          szPresetinfo[255 + 1]; // �ͻ�Ԥ����Ϣ
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
//-------------------------------10101764:���ÿͻ�Ԥ����Ϣ--------------------------
struct MATRADEAPI CReqStkRpcSysSecuritySetCustReservedInfoField
{
    char          szOrgid[4 + 1];        // ��������
    char          szBrhid[4 + 1];        // ������֧
    LONGLONG      llCustid;              // �ͻ�����
    char          szPresetinfo[255 + 1]; // �ͻ�Ԥ����Ϣ
    char          szRemark[64 + 1];      // ��ע��Ϣ
};
struct MATRADEAPI CRspStkRpcSysSecuritySetCustReservedInfoField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101765:ͬ���ͻ���̬����--------------------------
struct MATRADEAPI CReqStkRpcSysSecuritySyncDynamicTokenField
{
    char          szFuncid[16 + 1];   // ���ܺ�
    char          szCustorgid[8 + 1]; // �ͻ�������֧
    char          szNetaddr[16 + 1];  // ��¼������IP
    char          szOrgid[8 + 1];     // ��¼���ڷ�֧
    char          chOperway;          // ��������
    char          chExt;              // ��չ��ʶ
    char          chInputtype;        // �û��˻�����
    char          szInputid[32 + 1];  // �û��˻�
    char          chCustprop;         // �û���ɫ
    char          szDynpwd1[16 + 1];  // ��һ����̬����
    char          szDynpwd2[16 + 1];  // �ڶ�����̬����
};
struct MATRADEAPI CRspStkRpcSysSecuritySyncDynamicTokenField
{
    char          szEtokensn[32 + 1]; // �������к�
    char          szUsercn[128 + 1];  // �û�CN
    char          szDynpwd1[16 + 1];  // ��һ����̬����
    char          szDynpwd2[16 + 1];  // �ڶ�����̬����
    char          szUnlocked[8 + 1];  // �ͻ��ʻ�������ʶ
};
//-------------------------------10101766:�ͻ�֤���ȡ�����--------------------------
struct MATRADEAPI CReqStkRpcSysSecurityCertificateRandomCodeField
{
    char          chInputtype;       // �û��˻�����
    char          szInputid[32 + 1]; // �û��˻�
    char          chUserrole;        // �û���ɫ
    char          chCertType;        // ֤������
};
struct MATRADEAPI CRspStkRpcSysSecurityCertificateRandomCodeField
{
    LONGLONG      llUserCode;        // �û�����
    char          chUserRole;        // �û���ɫ
    char          chCaType;          // ֤������
    char          szRndcode[16 + 1]; // �����
};
//-------------------------------10101767:�ͻ���̬����״̬����--------------------------
struct MATRADEAPI CReqStkRpcSysSecuritySetDynamicTokenStatusField
{
    char          szOrgid[4 + 1];       // ��������
    char          chInputtype;          // �ʺ�����
    char          szInputid[64 + 1];    // �ʺ�
    char          chCustprop;           // �û���ɫ
    char          chOperway;            // ������ʽ
    char          szTokenstatus[8 + 1]; // ����״̬
    char          szDynpwd[33 + 1];     // ��̬����
    char          szEtokenpin[33 + 1];  // ��̬����pin��
};
struct MATRADEAPI CRspStkRpcSysSecuritySetDynamicTokenStatusField
{
    LONGLONG      llUserCode; // �û�����
    char          chUserRole; // �û���ɫ
    char          chStatus;   // ����״̬
};
//-------------------------------10101768:�ͻ���ȡһ���Զ�̬����--------------------------
struct MATRADEAPI CReqStkRpcSysSecurityOneTimeDynamicPwdField
{
    char          szOrgid[4 + 1];    // ��������
    char          chInputtype;       // �ʺ�����
    char          szInputid[64 + 1]; // �ʺ�
    char          chCustprop;        // �û���ɫ
    char          chOperway;         // ������ʽ
};
struct MATRADEAPI CRspStkRpcSysSecurityOneTimeDynamicPwdField
{
    LONGLONG      llUserCode;          // �û�����
    char          chUserRole;          // �û���ɫ
    char          szTmpdynpwd[16 + 1]; // һ���Զ�̬����
    char          szMobileno[32 + 1];  // ��������ʱԤ���ֻ���
};
//-------------------------------10101769:�ͻ���½����Ϣ����--------------------------
struct MATRADEAPI CReqStkRpcSysSecuritySetLoginBindingInfoField
{
    char          szOrgid[4 + 1];         // ��������
    LONGLONG      llCustid;               // �ͻ�����
    char          szComputername[32 + 1]; // ������ǳ�
    char          chBindtype;             // ������
    char          szBindcontext[128 + 1]; // ������
    char          chBindstatus;           // ��״̬
    char          szOtpcode[32 + 1];      // �ֻ�����
    char          szRemark[64 + 1];       // ��ע��Ϣ
    char          chAction;               // ������ʽ
};
struct MATRADEAPI CRspStkRpcSysSecuritySetLoginBindingInfoField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10101770:�ͻ���½����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcSysSecurityLoginBindingInfoField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ͻ�����
    char          chBindtype;       // ������
    char          chBindstatus;     // ��״̬
};
struct MATRADEAPI CRspStkQryRpcSysSecurityLoginBindingInfoField
{
    int           iServerid;              // ��������
    LONGLONG      llCustid;               // �ͻ�����
    char          szOrgid[4 + 1];         // ��������
    char          chBindtype;             // ������
    char          szBindcontext[128 + 1]; // ������
    int           iBinddate;              // ������
    int           iBindtime;              // ��ʱ��
    char          szComputername[32 + 1]; // ������ǳ�
    char          chBindstatus;           // ��״̬
    char          szRemark[64 + 1];       // ��ע��Ϣ
};
//-------------------------------10101771:У��ͻ���������--------------------------
struct MATRADEAPI CReqStkRpcSysSecurityVerifyTrdPwdField
{
    char          chInputtype;       // �û��˻�����
    char          szInputid[32 + 1]; // �û��˻�
};
struct MATRADEAPI CRspStkRpcSysSecurityVerifyTrdPwdField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
    char          chStatus;        // �ͻ�״̬
    char          szOrgid[4 + 1];  // ��������
    char          chTokenuser;     // ���ƿͻ�
    LONGLONG      llCustid;        // �ͻ�����
};
//-------------------------------10101772:�ͻ���ȡ�ֻ�һ���Զ�̬����--------------------------
struct MATRADEAPI CReqStkRpcSysSecurityMobileOneTimeDynamicPwdField
{
    char          szOrgid[4 + 1];   // ��������
    LONGLONG      llCustid;         // �ʺ�����
};
struct MATRADEAPI CRspStkRpcSysSecurityMobileOneTimeDynamicPwdField
{
    LONGLONG      llUserCode;        // �û�����
    char          szRndcode[32 + 1]; // �û���ɫ
};
//-------------------------------10101773:��ѯ�ͻ�ETF�����ɷֹɵĳֲ�����--------------------------
struct MATRADEAPI CReqStkQryRpcETFConstituentStkPosiField
{
    char          chMarket;         // �����г�
    LONGLONG      llFundid;         // �ʽ��˻�
    char          szEtfcode[8 + 1]; // ETF����
};
struct MATRADEAPI CRspStkQryRpcETFConstituentStkPosiField
{
    char          chMarket;                // �����г�
    char          szEtfcode[8 + 1];        // ETF����
    char          szStkcode[8 + 1];        // �ɷݹɴ���
    char          szStkname[64 + 1];       // �ɷݹɼ��
    char          chStkmarket;             // �ɷݹɽ����г�
    int           iAmount;                 // �ɷֹ�����
    int           iStkavl;                 // �ͻ��ֲ�����
    char          chReplaceflag;           // �����־
    char          szOverpricerate[21 + 1]; // ��۱���
    char          szReplaceamtSg[21 + 1];  // �깺������
    char          szReplaceamtSh[21 + 1];  // ���������
};
//-------------------------------10101774:��ͨ�ڵ��VIPϵͳ��֤ȯ����--------------------------
struct MATRADEAPI CReqStkRpcCommVIPStkTransferField
{
    char          szOrgid[4 + 1];   // ��������
    char          chMarket;         // �����г�
    LONGLONG      llFundid;         // �ʽ��˺�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llStkavl;         // ��������
    char          chDirect;         // ��������
};
struct MATRADEAPI CRspStkRpcCommVIPStkTransferField
{
    int           iSno;    // ������ˮ��
    int           iVipsno; // VIP������ˮ��
};
//-------------------------------10101775:�ֽ��ʲ�ת����--------------------------
struct MATRADEAPI CReqStkRpcCashAssetBankTransferField
{
    LONGLONG      iFundid;           // �ʽ��˺�
    char          chMoneytype;       // ���Ҵ���
    char          szFundpwd[32 + 1]; // �ʽ�����
    char          szBankcode[4 + 1]; // ���д���
    char          szBankpwd[32 + 1]; // ��������
    char          chBanktrantype;    // ת������
    char          szTranamt[21 + 1]; // ת�ʽ��
    char          chPwdflag;         // �ʽ�����У���־
    int           nEncodeType;       // ���ܷ�ʽ 1:W�漯�н��� 2:U�漯�н���
};
struct MATRADEAPI CRspStkRpcCashAssetBankTransferField
{
    int           iSno;             // ί�����
    int           iSyserrid;        // �������
    char          szErrmsg[64 + 1]; // ������Ϣ
};
//-------------------------------10101776:�ʽ𻮲���ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcCapitalTransferStatementField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char		  szExtsno[32 + 1];  // �ⲿ��ˮ��
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspStkQryRpcCapitalTransferStatementField
{
    char          szPoststr[32 + 1]; // ��λ��
    int           iOperdate;         // ��������
    int           iSysdate;          // �����Ľ�������
    int           iSno;              // ϵͳ��ˮ��
    char          szOrgid[4 + 1];    // ��������
    char          szBrhid[4 + 1];    // ������֧
    int           iOpertime;         // ����ʱ��
    int           iDigestid;         // ժҪ����
    LONGLONG      llCustid;          // �ͻ�����
    char          szName[16 + 1];    // �ͻ���������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          chMoneytype;       // ���Ҵ���
    char          szRemark[64 + 1];  // ��ע��Ϣ
    char		  szExtsno[256 + 1]; // �ⲿ��ˮ��
};
//-------------------------------10101777:Vip�ͻ��ʽ��ʲ�ͬ������ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcVIPCuacctSyncTableField
{
    LONGLONG      llFundid;             // �ʲ��˻�
    char          szMoneytype[128 + 1]; // ��������
};
struct MATRADEAPI CRspStkQryRpcVIPCuacctSyncTableField
{
    int           iServerid;              // ��������
    char          szOrgid[4 + 1];         // ��������
    LONGLONG      llCustid;               // �ͻ�����
    char          chMoneytype;            // ���Ҵ���
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          szFundlastbal[21 + 1];  // �������
    char          szFundbal[21 + 1];      // �������
    char          szFundavl[21 + 1];      // �����ʽ�
    char          szFundbuy[21 + 1];      // ���붳��
    char          szFundsale[21 + 1];     // �����ⶳ
    char          szOverdraw[21 + 1];     // ͸֧�޶�
    char          szFundfrz[21 + 1];      // �����ܽ��
    char          szFundunfrz[21 + 1];    // �ⶳ�ܽ��
    char          szFundtrdfrz[21 + 1];   // ���׽ⶳ���
    char          szFundnightfrz[21 + 1]; // ҹ�ж����ʽ�
    char          szFundloan[21 + 1];     // �����ܽ��
    char          szMarketvalue[21 + 1];  // ֤ȯ��ֵ
};
//-------------------------------10101778:���ڲ�Ʒ�ʵ�����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcFloorTradingProductAppropriatenessInfoField
{
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBsflag[128 + 1]; // �������
};
struct MATRADEAPI CRspStkQryRpcFloorTradingProductAppropriatenessInfoField
{
    char          chMarket;                // �����г�
    char          szStkcode[8 + 1];        // ֤ȯ����
    char          szStkname[64 + 1];       // ֤ȯ����
    char          chStktype;               // ֤ȯ���
    char          szBsflag[2 + 1];         // �������
    char          chRisklevel;             // ���յȼ�
    char          chInvestmentperiod;      // Ͷ������
    char          szInvestmenttype[2 + 1]; // Ͷ��Ʒ��
    char          chExincometype;          // Ԥ������
};
//-------------------------------10101779:�ͻ��ʵ�����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryRpcAppropriatenessInfoField
{
};
struct MATRADEAPI CRspStkQryRpcAppropriatenessInfoField
{
    char          chInvestortype;            // Ͷ��������
    int           iTrdprofvaliddate;         // רҵͶ������Ч��
    char          chRisklevel;               // ���յȼ�
    int           iRisklevelvaliddate;       // ���յȼ���Ч��
    char          chLowriskflag;             // ��ͷ��ճ���������ʶ
    char          chInvestmentperiod;        // Ͷ������
    char          szInvestmenttype[128 + 1]; // Ͷ��Ʒ��
    char          chExincometype;            // Ԥ������
    char          szRiskpropright[32 + 1];   // ��Ӧ���յȼ�����Э��
};
//-------------------------------10101780:�ͻ��볡�ڲ�Ʒ�ʵ���ƥ��У��--------------------------
struct MATRADEAPI CReqStkRpcAppropriatenessMatchingCheckField
{
    int           iMarket;          // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          szBsflag[2 + 1];  // �������
};
struct MATRADEAPI CRspStkRpcAppropriatenessMatchingCheckField
{
    char          chResultcode;            // ƥ����
    char          szResultmsg[128 + 1];    // ƥ��������
    char          chRisklevelinvalid;      // �ͻ����յȼ����ڱ�ʶ
    int           iRisklevelvaliddate;     // �ͻ����յȼ���Ч��
    char          chInvestortype;          // Ͷ��������
    int           iTrdprofvaliddate;       // רҵͶ������Ч��
    char          chLowriskflag;           // ��ͷ��ճ���������ʶ
    char          szRiskpropright[32 + 1]; // ��Ӧ���յȼ�����Э��
    char          chOrderctrlflag;         // �Ƿ�����ǿ���µ���־
};
//-------------------------------10101781:��¼����ҵ����ս�ʾ��ǩ����ˮ--------------------------
struct MATRADEAPI CReqStkRpcFloorTradingRiskDisclosureStatementSignedRecordFlowField
{
    char          szSigntype[64 + 1]; // ���ս�ʾ������
    char          szVersion[64 + 1];  // ���ս�ʾ��汾
    char          chMarket;           // �����г�
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szBsflag[2 + 1];    // �������
    char          chConfirmflag;      // ȷ�ϱ�ʶ
};
struct MATRADEAPI CRspStkRpcFloorTradingRiskDisclosureStatementSignedRecordFlowField
{
    LONGLONG      llRisksignsno; // ���ս�ʾ��ǩ����ˮ���
};

//-------------------------------10349001:ϵͳ̽��--------------------------
struct MATRADEAPI CReqStkBizStatusField
{
  char            szStkbd[2 + 1];             // ���װ�� ����ʱΪϵͳ̽�⣬���ص�һ������� �;�����ʱ�����ظð���Ƿ�����µ��Լ��������ڵ���Ϣ; ��*����@ʱ�������а���Ƿ���µ���Ϣ
};

struct MATRADEAPI CRspStkBizStatusField
{
  char            szStkbd[2 + 1];             // ���װ��
  int             iTrdDate;                   // ��ǰ������
  int             iPhysicalDate;              // ��������
  char            chTrdStatus;                // ����״̬ 0:��ֹ����  1����������
  char            szRemark[128 + 1];          // ��ע �����µ�������
};

//-------------------------------10302002:����ί��(����)--------------------------
struct MATRADEAPI CReqStkOrderExField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szClientInfo[256 + 1];      // �ն���Ϣ
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  int             iTgwIndex;                  // ָ�����̵��±�
};

struct MATRADEAPI CRspStkOrderExField
{
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
};

//-------------------------------10309007:�ɷ���ˮ��ѯ--------------------------
struct MATRADEAPI CReqStkQryStockFlowField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  char            szIntOrg[1024 + 1];         // �ڲ�����
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  int             iTrdDate;                   // ��������
  char            szStkbd[32 + 1];            // ���װ��
  char            chReverseStatus;            // ����״̬
  int             iBizCode;                   // ҵ�����
};

struct MATRADEAPI CRspStkQryStockFlowField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  LONGLONG        llSerialNo;                 // ��ˮ���
  int             iTrdDate;                   // ��������
  char            szSyncTime[32 + 1];         // ͬ��ʱ��
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  int             iIntOrg;                    // �ڲ�����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  int             iBizCode;                   // ҵ�����
  char            szBizContext[128 + 1];      // ҵ������
  LONGLONG        llBizSn;                    // ������ˮ��
  LONGLONG        llStkAvl;                   // �ɷݿ��ý��
  LONGLONG        llStkBlnEffect;             // �ɷ����仯
  LONGLONG        llStkAvlEffect;             // �ɷݿ��ñ仯
  LONGLONG        llStkFrzEffect;             // �ɷݶ���仯
  LONGLONG        llStkUfzEffect;             // �ɷݽⶳ�仯
  char            chReverseStatus;            // ����״̬ '1' - �ѳ���
  char            szSubsysSn[32 + 1];         // KCBP�ڵ�
};

//-------------------------------10306028:���н����ղ�ѯ--------------------------
struct MATRADEAPI CReqStkQrySettDateField
{
};

struct MATRADEAPI CRspStkQrySettDateField
{
  int             iTrdDate;                   // ��������
  int             iSettDate;                  // ��һ������
  int             iSubsysSn;                  // ��ϵͳ���
};

//-------------------------------10301030:�̺���������ѯ--------------------------
struct MATRADEAPI CReqStkQryLofMktInfoField
{
  char            szStkbd[32 + 1];            // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
};

struct MATRADEAPI CRspStkQryLofMktInfoField
{
  char            chStkex;                    // ֤ȯ������
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chStkLofStatus;             // ����״̬
  int             iNavDate;                   // ��ֵ����
  char            szStkLofNav[21 + 1];        // ����ֵ
  char            szStkLofNavTotal[21 + 1];   // �ۼƾ�ֵ
  char            chStkMsStatus;              // �ϲ�/�ֲ�״̬
  char            szStkLofMainCode[8 + 1];    // ���������
  int             iStkMsRatio;                // �ϲ�/�ֲ����
  LONGLONG        llStkMergeFloor;            // ��ͺϲ�����
  LONGLONG        llStkSplitFloor;            // ��ͷֲ�����
  char            chStkChangeStatus;          // ת��״̬
  char            szRsvField[32 + 1];         // �����ֶ�
  char            szAdminCode[8 + 1];         // �����˴���
  char            szTaCode[8 + 1];            // TA����
};

//-------------------------------10305015:�ʽ𻮲�(���н���)--------------------------
struct MATRADEAPI CReqStkFundTransferJzjyField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  char            chDirect;                   // �������� ��1�����н��׻���������ϵͳ���� ��2�����н��׻��롢����ϵͳ����
  char            szBizAmt[21 + 1];           // �������
  LONGLONG        llOpCode;                   // ������Ա��� ��ѯ���н��׹ɷ���Ҫ��ԱȨ��
  char            chIsEffectBln;              // �Ƿ񻮲���� ��0��:��������� ��1��:������� ��Ĭ��ֵ��1����
};

struct MATRADEAPI CRspStkFundTransferJzjyField
{
  LONGLONG        llSerialNo;                 // ��ˮ���
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  int             iIntOrg;                    // �ڲ�����
  char            chCurrency;                 // ���Ҵ���
  LONGLONG        llBizCode;                  // ժҪ����
  LONGLONG        llBizSn;                    // ������ˮ��
  char            chDirect;                   // ��������
  char            szBizAmt[21 + 1];           // �������
};

//-------------------------------10303131:�����ʽ��ѯ(���н���)--------------------------
struct MATRADEAPI CReqStkQryExpendableFundJzjyField
{
  LONGLONG        llCustCode;                 // �ͻ����� �����ͬʱΪ��
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY] ��ͻ��������ʹ�� ���ʲ��˻����ʹ��
  char            chBlnFlag;                  // ����ȡ��־ 0��������ȡ��� 1����������ȡ��� Ĭ����0
  char            chCuacctAttr;               // �˻����� �ֵ�[CUACCT_ATTR]
};

struct MATRADEAPI CRspStkQryExpendableFundJzjyField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szFundBln[21 + 1];          // �ʽ����
  char            szFundAvl[21 + 1];          // �ʽ���ý��
  char            szTranAvl[21 + 1];          // ����ȡ���
};

//-------------------------------10304013:��֤��Ϣ����(����¼��/�޸�)--------------------------
struct MATRADEAPI CReqStkAuthDataSetJzjyField
{
  LONGLONG        llUserCode;                 // �û�����
  char            szAuthData[256 + 1];        // ��֤���� ����
  char            szSrcAuthData[256 + 1];     // ԭ��֤���� ����
  char            chUseScope;                 // ʹ�÷�Χ 0: ��Ʊ�������� 2�����ý�������
};

struct MATRADEAPI CRspStkAuthDataSetJzjyField
{
  char            szMsgOk[32 + 1];            // �ɹ���Ϣ
};

//-------------------------------10305019:�ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮��--------------------------
struct MATRADEAPI CReqStkFundTransferNodeField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  char            chDirect;                   // �������� ��0������ ��1������
  char            szTransFund[21 + 1];        // �������
  char            chTranType;                 // ��������  '0'-�������� '1'-������ȡ
};

struct MATRADEAPI CRspStkFundTransferNodeField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  char            szTransFund[21 + 1];        // �������
  LONGLONG        llSerialNo;                 // ��ˮ���
  char            chTransStatus;              // ����״̬ 0-�ѵ��� 1-�ɹ� 2-ʧ�� 3-��ʱ
  char            szRemark[256 + 1];          // ��ע ����״̬Ϊ2/3ʱ���ش���ԭ��
};

//-------------------------------10349044:�ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮��[��ϯ����]------------------
struct MATRADEAPI CReqStkFundTransferNodeCiXiField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  char            szTransFund[21 + 1];        // �������
  char            chDirect;                   // ��������  '0'-���� '1'-����
  char            szStkbd[2 + 1];             // ���װ��
  int             iSyncSubsysSn;              // ����Ŀ��ڵ�
  char            chTranType;                 // ��������  '0'-�������� '1'-������ȡ
};

struct MATRADEAPI CRspStkFundTransferNodeCiXiField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ���
  char            szTransFund[21 + 1];        // �������
  LONGLONG        llSerialNo;                 // ��ˮ���
  char            chTransStatus;              // ����״̬ 0-�ѵ��� 1-�ɹ� 2-ʧ�� 3-��ʱ
  char            szRemark[256 + 1];          // ��ע ����״̬Ϊ2/3ʱ���ش���ԭ��
};

//-------------------------------10305036:��֤ת��--------------------------
struct MATRADEAPI CReqStkBankStkTransferField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chCurrency;                 // ���Ҵ��� DD[CURRENCY]
  char            chTranType;                 // ת������ ��1��: ����ת����2��: ֤ȯת����
  char            szTranAmt[21 + 1];          // ת�ʽ��
  char            szFundPwd[32 + 1];          // �ʽ����� ������Ҫ����, ���ܲ���kbss_encrypt1���� �ӿ��Զ�����
  char            szBankCode[4 + 1];          // ���д���
  char            szBankPwd[32 + 1];          // �������� ����
  char            chPwdFlag;                  // �ʽ�����У���־ ����֤ȯת����,0��ʾ��У���ʽ�����,1��ʾУ���ʽ�����,����Ĭ��Ϊ1
  char            szTrdPwd[32 + 1];           // �������� ��������룬���ܲ���kbss_encrypt1����  �ӿ��Զ�����
  char            chInitiator;                // ���� I-ȯ�� O-���� (Ŀǰֻ֧����I)
  int             iExtOrg;                    // �ⲿ���� U����Ҫ��
  char            szTrdTermcode[20 + 1];      // �����ն������� ��̨��¼��ʽ��MAC_ADDR+HD_ID+TRD_TERMCODE
};

struct MATRADEAPI CRspStkBankStkTransferField
{
  LONGLONG        llSerialNo;                 // ��ˮ���
  char            szErrorMess[128 + 1];       // ������Ϣ
};

//-------------------------------10301506:ҪԼ�չ��չ�����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryTenderSgrInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ҪԼ���� ֤ȯ����
  char            szSgrCode[8 + 1];           // �չ��˱���
};

struct MATRADEAPI CRspStkQryTenderSgrInfoField
{
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ҪԼ����
  char            szSgrCode[8 + 1];           // �չ��˱���
  char            szSgPrice[21 + 1];          // �չ��۸�
  char            szPurchaserNane[32 + 1];    // �չ�������
  int             iTenderBegDate;             // ҪԼ��ʼ����
  int             iTenderEndDate;             // ҪԼ��������
};

//-------------------------------10302017:ETF�����Ϲ����볷��--------------------------
struct MATRADEAPI CReqStkEtfOfflineCancelOrderField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  int             iTrdDate;                   // ��������
  int             iOrderSn;                   // ί�����
  int             iOrderBsn;                  // ί������
  LONGLONG        llFortuneCode;              // �Ƹ��˻�
};

struct MATRADEAPI CRspStkEtfOfflineCancelOrderField
{
  int             iOrderBsn;                  // ί������
  char            szOrderId[10 + 1];          // ��ͬ���
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ������
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szStkbd[2 + 1];             // ���װ��
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkSubCode[8 + 1];        // �Ϲ�����
  char            szStkSubName[64 + 1];       // �Ϲ���������
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  int             iOrderSn;                   // ί�����
  LONGLONG        llFortuneCode;              // �Ƹ��˻�
};

//-------------------------------10303007:ETF�����Ϲ������ѯ--------------------------
struct MATRADEAPI CReqStkQryEtfOfflineOrderField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  LONGLONG        llTrdDate;                  // ��������
  char            szStkbd[32 + 1];            // ���װ�� �ֵ�[STKBD]
  char            szStkSubCode[8 + 1];        // �Ϲ�����
  int             iOrderSn;                   // ί�����
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkBiz[1024 + 1];         // ֤ȯҵ�� �ֵ�[STK_BIZ]
  char            chStkSubStatus;             // ����״̬
  char            szOrderId[10 + 1];          // ��ͬ���
  char            szIntOrg[1024 + 1];         // �ڲ�����
  LONGLONG        llFortuneCode;              // �Ƹ��˻�
};

struct MATRADEAPI CRspStkQryEtfOfflineOrderField
{
  int             iTrdDate;                   // ��������
  int             iOrderDate;                 // ί������
  char            szOrderTime[32 + 1];        // ί��ʱ��
  int             iOrderSn;                   // ί�����
  int             iOrderBsn;                  // ί������
  char            szOrderId[10 + 1];          // ��ͬ���
  char            szOrderType[32 + 1];        // ί������
  int             iIntOrg;                    // �ڲ�����
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // �����˻�
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  int             iSubsysSn;                  // ��ϵͳ����
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ί�ж�����
  char            szOrderUfzAmt[21 + 1];      // ί�нⶳ���
  LONGLONG        llWithdrawnQty;             // �ѳ�������
  char            chIsWithdraw;               // ������־ �ֵ�[IS_WITHDRAW]
  char            chIsWithdrawn;              // �ѳ�����־ �ֵ�[IS_WITHDRAWN]
  char            szEtfCode[8 + 1];           // ETF����
  char            szEtfName[16 + 1];          // ETF����
  char            szStkSubCode[8 + 1];        // �Ϲ�����
  char            szStkSubName[16 + 1];       // �Ϲ���������
  char            szBillFee[21 + 1];          // ����
  char            szCommissionRate[21 + 1];   // �Ϲ����ñ���
  char            chStkSubStatus;             // ����״̬ '0'δ�Ϲ� '1'���Ϲ� '2'�ѳ��� '3'������ '4'�Ѵ���
  char            szTrdacctLink[20 + 1];      // ���������˻�
  char            szStkbdLink[2 + 1];         // �������װ�� �ֵ�[STKBD]
  char            szStkpbuLink[8 + 1];        // �������׵�Ԫ
  LONGLONG        llStkAvlFrz;                // ֤ȯ��������
  int             iUpdDate;                   // ��������
  char            szCustName[32 + 1];         // �ͻ�����
  char            szIdCode[48 + 1];           // ֤������
  char            chCuacctAttr;               // �ʲ��˻�����
  LONGLONG        llFortuneCode;              // �Ƹ��˻�
};

//-------------------------------10303206:�¹�������ѯ--------------------------
struct MATRADEAPI CReqStkQryNewStkCalField
{
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkCls[2 + 1];            // ֤ȯ���
  int             iBgnDate;                   // ��ʼ����
  int             iEndDate;                   // ��������
  char            szFxMode[6 + 1];            // ���з�ʽ
};

struct MATRADEAPI CRspStkQryNewStkCalField
{
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ����֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            szGbType[2 + 1];            // �㲥���
  char            szStkCls[2 + 1];            // ֤ȯ���
  char            szFxMode[6 + 1];            // ���з�ʽ
  LONGLONG        llStkUplimitQty;            // �깺��������
  LONGLONG        llStkLwlimitQty;            // �깺��������
  LONGLONG        llBuyUnit;                  // �깺����
  int             iBgnDate;                   // �깺��ʼ����
  int             iEndDate;                   // �깺��������
  char            szDataRate[21 + 1];         // �Ϲ�����
  char            szStkUplimitPrice[21 + 1];  // ���м۸�����
  char            szStkLwlimitPrice[21 + 1];  // ���м۸�����
  char            szByzd[50 + 1];             // �����ֶ�
  int             iAcceptDate;                // ���ݽ�������
  char            szRemark[128 + 1];          // ��ע��Ϣ
};

//-------------------------------10307313:�����ڴ�Ʒ����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryStkInfoShmField
{
  char            szStkbd[2 + 1];             // ֤ȯ���
  char            szStkCls[2 + 1];            // ֤ȯ���
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ����(Ĭ��)
  char            szQueryPos[32 + 1];         // ��λ�� ����ֵΪ��¼�� ���ѯ�������ʹ��
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
};

struct MATRADEAPI CRspStkQryStkInfoShmField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkCls[2 + 1];            // ֤ȯ���
  char            chStkSubCls;                // ֤ȯ����� �ֵ�[STK_SUB_CLS]
  char            chStkStatus;                // ֤ȯ״̬
  char            chStkLotFlag;               // ��λ��־
  LONGLONG        llStkLotSize;               // ÿ������
  char            chStkLevel;                 // ֤ȯ����
  char            chIsReg;                    // �Ƿ�ע����
  int             iDlvyCycle;                 // ��������
  char            chLofSubFlag;               // �ӻ����־
  char            chBondSuitable;             // ծȯ�ʵ���
  char            szStkUplmtPrice[21 + 1];    // ��ͣ�۸�
  char            szStkLwlmtPrice[21 + 1];    // ��ͣ�۸�
  LONGLONG        llStkUplmtQty;              // �޼���������
  LONGLONG        llStkLwlmtQty;              // �޼���������
  LONGLONG        llStkUplmtQtyMp;            // �м���������
  LONGLONG        llStkLwlmtQtyMp;            // �м���������
  char            szStkSpread[21 + 1];        // ��λ�۲�
  int             iBuyUnit;                   // ������С��λ
  int             iSaleUnit;                  // ������С��λ
  char            szBondInt[21 + 1];          // ծȯ��Ϣ
  char            szQryPos[32 + 1];           // ��λ��
};

//-------------------------------10302122:ծȯ����ҵ��ԤԼί�г���--------------------------
struct MATRADEAPI CReqStkReserveOrderCancelField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // �����˻�
  char            szOrderId[10 + 1];          // ��ͬ��� ��ί�����Ų���ͬʱΪ�� ��ͬ��Ų�Ϊ�գ��Ͱ���ͬ��ų����� ����ί�����Ų�Ϊ�գ���ί�����ų�����
  int             iOrderBsn;                  // ί������ �����ί�����ų����������λ��������¼���ڣ�������ʹ������������ʵ�֡�
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llFortuneCode;              // �Ƹ��˻�
  int             iStkBiz;                    // ֤ȯҵ��
  int             iTrdDate;                   // ��������  ����Ϊ��
};

struct MATRADEAPI CRspStkReserveOrderCancelField
{
  int             iOrderBsn;                  // ί������
  char            szOrderId[10 + 1];          // ��ͬ��� ԭί�еĺ�ͬ���
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szOrderAmt[21 + 1];         // ί�н��
  char            szOrderFrzAmt[21 + 1];      // ������
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szStkbd[2 + 1];             // ���װ��
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  int             iStkBiz;                    // ֤ȯҵ��
  int             iStkBizAction;              // ҵ����Ϊ
  char            chCancelStatus;             // �ڲ�������־ 1:�ڲ����� ��1:��ͨ����
  char            szMsgOk[32 + 1];            // �ɹ���Ϣ ������ڲ��������޸ķ�����ϢΪ�������ɹ���
  char            szCancelList[256 + 1];      // �����б� ��ʽ: ԭί�����#����ί�����#�ڲ�������־#������Ϣ|��...| ����ί�����=-1 ��ʾ����ʧ��
  char            szWtOrderId[10 + 1];        // ί�к�ͬ�� ί�еĺ�ͬ���
};

//-------------------------------10301579:����ծȯ���������ѯ--------------------------
struct MATRADEAPI CReqStkQryBondQuoteField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQuoteType;                // �������� 0������ɽ����� 1��ѯ���걨 2��ѯ�۳ɽ�����
  char            chSide;                     // �������� 1������ 2������
  char            chQuoteStatus;              // ״̬
};

struct MATRADEAPI CRspStkQryBondQuoteField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  int             iOfferStime;                // �걨ʱ��
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  int             iIntOrg;                    // �ڲ�����
  char            chSide;                     // ��������
  char            chQuoteType;                // ��������
  char            szOfferMsgId[10 + 1];       // ��Ϣ���
  char            szOfferPrice[21 + 1];       // ���ۼ۸�
  LONGLONG        llOfferQty;                 // ��������
  char            szMemberId[6 + 1];          // �����̴���
  char            szInvestorType[2 + 1];      // ������������
  char            szInvestorName[256 + 1];    // ������������
  char            szTraderCode[8 + 1];        // ����Ա����
  char            chQuoteStatus;              // ״̬
  char            chIsAnonymity;              // �Ƿ�����
  int             iOwnerType;                 // ����������
  char            szOrderId[10 + 1];          // ��ͬ���
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szInvestorId[10 + 1];       // �����������
  char            szQuoteReqId[10 + 1];       // ѯ��������
  char            szRemark[256 + 1];          // ��ע��Ϣ
  int             iSettlType;                 // ���㷽ʽ
  int             iSettlPeriod;               // ��������
  char            chCashMargin;               // ������ȯ��Ϣ��ʶ
  char            szCtpMemberId[8 + 1];       // ���ַ������̴���
  char            szCtpInvestorType[2 + 1];   // ���ַ�������������
  char            szCtpInvestorId[10 + 1];    // ���ַ������������
  char            szCtpInvestorName[30 + 1];  // ���ַ�������������
  char            szCtpTraderCode[8 + 1];     // ���ַ�����Ա����
  char            szExecId[32 + 1];           // ִ�б��
  char            szTrdMatchId[32 + 1];       // ���ױ��
  char            szOfferCustName[128 + 1];   // �걨�ͻ�����
  char            szOpptStkpbu[8 + 1];        // ���׵�Ԫ(����)
  char            szExpireTime[32 + 1];       // ʧЧʱ��
};

//-------------------------------10301583:Э�̳ɽ��ر�������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryReportMktInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szMemberId[8 + 1];          // �����̴���
  char            szCtpMemberId[8 + 1];       // ���ַ������̴���
  char            chReportType;               // �ɽ��걨���� 0=�ύ�ɽ��걨 2=���ܳɽ��걨 3=�ܾ��ɽ��걨
  char            chSide;                     // ��������
  char            chStatus;                   // ״̬
  char            szCtpTraderCode[8 + 1];     // ���ַ�����Ա����
  char			  szConfirmId[8 + 1];		  // Լ����
  char			  szApplID[8 + 1];			  // Ӧ�ñ�ʶ
  char			  szTrdacct[20 + 1];		  // ֤ȯ�˻�
};

struct MATRADEAPI CRspStkQryReportMktInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  int             iTransactStime;             // �ر�ʱ��
  int             iOwnerType;                 // ����������
  char            szReportId[10 + 1];         // �ͻ��ɽ��걨���
  char            chReportType;               // �ɽ��걨���� 0=�ύ�ɽ��걨 2=���ܳɽ��걨 3=�ܾ��ɽ��걨
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            szConfirmId[8 + 1];         // Լ����
  char            chSide;                     // ��������
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  int             iIntOrg;                    // Ӫҵ������
  char            szMemberId[6 + 1];          // �����̴���
  char            szInvestorType[2 + 1];      // ������������
  char            szInvestorName[256 + 1];    // ������������
  char            szInvestorId[10 + 1];       // �����������
  char            szTraderCode[8 + 1];        // ����Ա����
  char            szCtpMemberId[8 + 1];       // ���ַ������̴���
  char            szCtpInvestorType[2 + 1];   // ���ַ�������������
  char            szCtpInvestorName[256 + 1]; // ���ַ�������������
  char            szCtpInvestorId[10 + 1];    // ���ַ������������
  char            szCtpTraderCode[8 + 1];     // ���ַ�����Ա����
  char            szOrderId[10 + 1];          // ��ͬ���
  char            chStatus;                   // ״̬
  char            szRemark[256 + 1];          // ��ע��Ϣ
  int             iSettlType;                 // ���㷽ʽ
  char            chSettlPeriod;              // ��������
  char            szOpptStkpbu[8 + 1];        // ���׵�Ԫ(����)
  int             iTrdSubtype;                // �ɽ��걨��ҵ�����
  LONGLONG        llOrderAmt;                 // ί�н��
  LONGLONG        llSettAmt;                  // ������
  int             iExpDates;                  // ����
  char            szExecId[32 + 1];           // ִ�б��
  char            szTrdMatchId[32 + 1];       // ���ױ��
  char            chCashMargin;               // ������ȯ��Ϣ��ʶ
  char            szOfferCustName[128 + 1];   // �걨�ͻ�����
  char			  szApplID[8 + 1];			  // Ӧ�ñ�ʶ
  char			  szOrigTradeDate[32 + 1];	  // ԭ�ɽ��걨����
  char			  szSecondaryExecId[32 + 1];  // �ڶ�ִ�б��
};

//-------------------------------10303352:ծȯ��ȯ���׾���ԤԼί����Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryCashBondReserveOrderInfoField
{
  int             iTrdDate;                   // ��������
  char            chStkex;                    // ֤ȯ������
  char            szStkbd[2 + 1];             // ���װ��
  char            szOrderId[10 + 1];          // ��ͬ���
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szTrdacct[20 + 1];          // �����˻�
  int             iBidTrdDate;                // ����������
  char            szStkCode[8 + 1];           // ֤ȯ����
  int             iBidExecInstType;           // ����ɽ���ʽ
  char            chIsWithdraw;               // ������־
  char            chIsWithdrawn;              // �ѳ�����־
};

struct MATRADEAPI CRspStkQryCashBondReserveOrderInfoField
{
  int             iTrdDate;                   // ��������
  char            chStkex;                    // ֤ȯ������
  char            szStkbd[2 + 1];             // ���װ��
  char            szOrderId[10 + 1];          // ��ͬ���
  char            szStkOrderId[14 + 1];       // ��������ͬ���
  char            szBidId[16 + 1];            // ���򳡴α��
  int             iIntOrg;                    // �ڲ�����
  char            szMemberId[6 + 1];          // ���������̴���
  char            szInvestorType[2 + 1];      // ����������������
  char            szInvestorId[10 + 1];       // ���������������
  char            szTraderCode[8 + 1];        // ��������Ա����
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szTrdacct[20 + 1];          // �����˻�
  int             iBidTrdDate;                // ����������
  LONGLONG        llOrderQty;                 // ί������
  char            szStkCode[8 + 1];           // ֤ȯ����
  LONGLONG        llMinQty;                   // ��ͳɽ�����
  int             iBidExecInstType;           // ����ɽ���ʽ
  char            szPriceCelling[21 + 1];     // �۸�����
  char            szPriceFloor[21 + 1];       // �۸�����
  char            chAnonymity;                // �Ƿ�����
  char            chIsWithdraw;               // ������־
  char            chIsWithdrawn;              // �ѳ�����־
  char            szRemark[320 + 1];          // ��ע��Ϣ
  char            chStkSubStatus;             // ����״̬
};

//-------------------------------10309038:ί�л��ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryOrderSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  LONGLONG        llOpUser;                   // �����û�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  int             iStkBiz;                    // ������Ϊ
  int             iStkBizAction;              // ҵ��
  char            chCurrency;                 // ����
  int             iBeginDate;                 // ��ʼ����
  int             iEndDate;                   // ��������
};

struct MATRADEAPI CRspStkQryOrderSummaryField
{
  char            szCustName[32 + 1];         // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  LONGLONG        llOpUser;                   // �����û�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  int             iStkBiz;                    // ������Ϊ
  int             iStkBizAction;              // ҵ��
  char            szStkbd[2 + 1];             // ���װ��
  char            chStkex;                    // �����г�
  LONGLONG        llOrderQty;                 // ί������
  LONGLONG        llMatchedQty;               // �ɽ�����
  char            szMatchedAmt[21 + 1];       // �ɽ����
  char            szMatchPrice[21 + 1];       // �ɽ�����
  LONGLONG        llWithdrawnQty;             // ��������
  char            szTrdsDate[32 + 1];         // ��������
  char            chCurrency;                 // ����
};

//-------------------------------10309039:�ɽ����ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryMatchSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  LONGLONG        llOpUser;                   // �����û�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  int             iStkBiz;                    // ������Ϊ
  int             iStkBizAction;              // ҵ��
  char            chCurrency;                 // ����
  int             iBeginDate;                 // ��ʼ����
  int             iEndDate;                   // ��������
};

struct MATRADEAPI CRspStkQryMatchSummaryField
{
  char            szCustName[32 + 1];         // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  LONGLONG        llOpUser;                   // �����û�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  int             iStkBiz;                    // ������Ϊ
  int             iStkBizAction;              // ҵ��
  char            szStkbd[2 + 1];             // ���װ��
  char            chStkex;                    // �����г�
  LONGLONG        llMatchedQty;               // �ɽ�����
  char            szMatchedAmt[21 + 1];       // �ɽ����
  char            szMatchPrice[21 + 1];       // �ɽ�����
  char            szTrdsDate[32 + 1];         // ��������
  char            chCurrency;                 // ����
};

//-------------------------------10309041:�ʽ�䶯���ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryFundEffectSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  char			  szIntOrg[4096 + 1];		  // �ڲ�����
  int             iBizCode;                   // ҵ�����
};
struct MATRADEAPI CRspStkQryFundEffectSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  int			  iIntOrg;					  // �ڲ�����
  char			  chCurrency;				  // ���Ҵ���
  int		      iBizCode;			          // ҵ�����
  char			  szBizContext[128 + 1];	  // ҵ������
  char			  szFundBlnEffect[21 + 1];	  // �ʽ����仯
  char			  szFundAvlEffect[21 + 1];	  // �ʽ���ñ仯
  char			  chReverseStatus;			  // ����״̬
  char			  chTransStatus;			  // ת��״̬
};
//-------------------------------10309042:�ɷݱ䶯���ܲ�ѯ--------------------------
struct MATRADEAPI CReqStkQryStockEffectSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  char			  szIntOrg[4096 + 1];		  // �ڲ�����
  char			  szStkbd[32 + 1];			  // ���װ��
  int             iBizCode;                   // ҵ�����
};
struct MATRADEAPI CRspStkQryStockEffectSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  int			  iIntOrg;					  // �ڲ�����
  char			  szTrdacct[20 + 1];          // �����˻�
  char			  szStkbd[32 + 1];	          // ���װ��
  char			  szStkCode[32 + 1];          // ֤ȯ����
  int			  iBizCode;					  // ҵ�����
  char			  szBizContext[128 + 1];	  // ҵ������
  LONGLONG	      szStkBlnEffect;		      // �ɷ����仯
  LONGLONG		  szStkAvlEffect;		      // �ɷݿ��ñ仯
  char			  chReverseStatus;			  // ����״̬
};

//-------------------------------10303353:ծȯ��ȯ���׾���ԤԼ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryCashBondTradeReservationInfoField
{
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szBidId[16 + 1];            // ���򳡴α��
  int             iBidTrdDate;                // ����������
  int             iBidExecInstType;           // ����ɽ���ʽ
  char            chAnonymity;                // �Ƿ�����
  char            szMemberId[6 + 1];          // �����̴���
  char            szInvestorType[2 + 1];      // ������������
  int             iSettType;                  // ���㷽ʽ
};

struct MATRADEAPI CRspStkQryCashBondTradeReservationInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szBidId[16 + 1];            // ���򳡴α��
  char            szStkCode[8 + 1];           // ֤ȯ����
  int             iBidTrdDate;                // ԤԼ��������
  LONGLONG        llBidQty;                   // ����ԤԼ����
  LONGLONG        llBidMinQty;                // ��ͳɽ�����
  int             iBidExecInstType;           // ����ɽ���ʽ
  char            chAnonymity;                // �Ƿ�����
  char            szMemberId[6 + 1];          // �����̴���
  char            szInvestorType[2 + 1];      // ������������
  char            szPriceCelling[21 + 1];     // �۸�����
  char            szPriceFloor[21 + 1];       // �۸�����
  int             iSettType;                  // ���㷽ʽ
  int             iSettPeriod;                // ��������
  char            szRemark[320 + 1];          // ��ע��Ϣ
};

//-------------------------------10301389:ծȯ��ȯ����ҵ��ο���Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryCashBondTradeProfitInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ�� ����ֵΪ��¼�� ���ѯ�������ʹ��
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
};

struct MATRADEAPI CRspStkQryCashBondTradeProfitInfoField
{
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chTraType;                  // ���׷�ʽ
  char            szPriceTick[21 + 1];        // �۸�λ
  char            szPriceUpperLimit[21 + 1];  // ��ͣ��
  char            szPriceLowerLimit[21 + 1];  // ��ͣ��
  LONGLONG        llBuyQtyUpperLimit;         // ����������
  LONGLONG        llSellQtyUpperLimit;        // ����������
  LONGLONG        llBuyQtyLowerLimit;         // ����������
  LONGLONG        llSellQtyLowerLimit;        // ����������
  LONGLONG        llBuyQtyUnit;               // ��������λ
  LONGLONG        llSellQtyUnit;              // ��������λ
  char            szQryPos[32 + 1];           // ��λ��
};

//-------------------------------10301391:ծȯͨ����Ѻʽ�ع�ҵ��ο���Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryBondPledgeRepchProfitInfoField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ�� ����ֵΪ��¼�� ���ѯ�������ʹ��
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
};
struct MATRADEAPI CRspStkQryBondPledgeRepchProfitInfoField
{
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chTraType;                  // ���׷�ʽ
  char            szPriceTick[21 + 1];        // �۸�λ
  char            szPriceUpperLimit[21 + 1];  // ��ͣ��
  char            szPriceLowerLimit[21 + 1];  // ��ͣ��
  LONGLONG        llBuyQtyUpperLimit;         // ����������
  LONGLONG        llSellQtyUpperLimit;        // ����������
  LONGLONG        llBuyQtyLowerLimit;         // ����������
  LONGLONG        llSellQtyLowerLimit;        // ����������
  LONGLONG        llBuyQtyUnit;               // ��������λ
  LONGLONG        llSellQtyUnit;              // ��������λ
  char            szQryPos[32 + 1];           // ��λ��
};

//-------------------------------10303368:REITs�����ǵ���״̬��ѯ--------------------------
struct MATRADEAPI CReqStkQryPriceStatusField
{
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkCode[32 + 1];          // ֤ȯ����
};

struct MATRADEAPI CRspStkQryPriceStatusField
{
  char            chTdStatus;                 // �����ǵ���״̬ ��ʾ�����Ƿ��ǵ�������5%�� 0��ʾδ������ 1��ʾ������
  char            chHisStatus;                // �����ǵ���״̬ ��ʾǰ20���ǵ����Ƿ񳬹�20%�� 0��ʾδ������ 1��ʾ������
  char            szRemark[128 + 1];          // ��ע ��״̬����һ��������Ϊ����ʱ���������ʾ��Ϣ
};

//-------------------------------10301108:ģ��ͻ���¼--------------------------
struct MATRADEAPI CReqStkUserLoginImpersonateField
{
  LONGLONG        llCustCode;                 // �ͻ����� �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻� �ʲ��˻�
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  char            chChannel;                  // ��������
  char            szSerChannel[8 + 1];        // ��������
};

struct MATRADEAPI CRspStkUserLoginImpersonateField
{
  char            szQryPos[32 + 1];           // ��λ����ѯ
  LONGLONG        llCustCode;                 // �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  char            szStkTrdacct[20 + 1];       // ֤ȯ�˻�
  int             iTrdacctSn;                 // �˻����
  char            szTrdacctExid[20 + 1];      // �����˻�
  char            chTrdacctStatus;            // �˻�״̬
  char            chTregStatus;               // ָ��״̬
  char            chBregStatus;               // �ع�״̬
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szTrdacctName[32 + 1];      // �����˻�����
  char            szChannelId[2 + 1];         // ͨ����
  char            szSessionId[256 + 1];       // �Ựƾ֤
  int             iIntOrg;                    // �ڲ�����
  char            chCuacctAttr;               // �ʲ��˻�����
  int             iSubsysSn;                  // Զ����ϵͳ��� ָ�ʲ�������Ӧ��ϵͳ���� �ԽӼ��н���ϵͳʱ�Ǽ��н���ϵͳ�Ľڵ���� �Խ��ʲ��й�ϵͳʱ,ָ���ǲ����й�ϵͳ
  char            chTrdacctExcls;             // ֤ȯ�˻����
};

//-------------------------------10305107:�ɷݻ���--------------------------
struct MATRADEAPI CReqStkStockTransferField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ��
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  LONGLONG        llOpCode;                   // ������Ա���� ��ѯ���н��׹ɷ���Ҫ��ԱȨ��
  char            chOrderType;                // ָ������ 1:���뼯�н���  0:�������н���
  LONGLONG        llStkEffect;                // �ɷݷ����� ����
  LONGLONG        llSerialNo;                 // ��ˮ��
  char            chIsEffectBln;              // �Ƿ񻮲���� ��0��:��������� ��1��:������� ��Ĭ��ֵ��1����
};

struct MATRADEAPI CRspStkStockTransferField
{
  LONGLONG        llSerialNo;                 // ��ˮ��
  LONGLONG        llStkQty;                   // �����ɷ�����
};

//-------------------------------10301082:���ڽ���������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryBlockTradingMktInfoField
{
  char            chStkex;                    // ֤ȯ������
  char            szStkbd[32 + 1];            // ���װ��
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chQueryFlag;                // ��ѯ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
  char            chMkCls;                    // ������� 1���������� 2����������
  char            chSide;                     // ��������
};

struct MATRADEAPI CRspStkQryBlockTradingMktInfoField
{
  char            chStkex;                    // ֤ȯ������
  char            szStkbd[2 + 1];             // ���װ��
  LONGLONG        llApplseqNum;               // ��¼���
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            chMkCls;                    // �������
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  char            chSide;                     // ��������
  char            szConfirmId[8 + 1];         // Լ����
  char            szOrderTime[32 + 1];        // ί��ʱ��
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ��
  char            szMatchedPrice[21 + 1];     // �ɽ��۸�
  LONGLONG        llMatchedQty;               // �ɽ�����
  char            szContactInfo[50 + 1];      // ��ϵ��Ϣ
  char            chExecType;                 // ִ������ 0���걨  1���ɽ� 2������ί��
};

//-------------------------------10303094:�̺����������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryClosingBlockTradingMktInfoField
{
  char            chStkex;                    // �г�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chStkPhQuoteType;           // �̺󱨼����� ��1�������̼� ��2����ƽ����
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
};

struct MATRADEAPI CRspStkQryClosingBlockTradingMktInfoField
{
  int             iTrdDate;                   // ��������
  char            chStkex;                    // �г�
  char            szStkPhhqlb[5 + 1];         // �������
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            chStkPhQuoteType;           // ��������
  char            szStkPhQuotePrice[21 + 1];  // �۸�
  LONGLONG        llStkMatchedQty;            // �ɽ�����
  char            szStkMatchedAmt[21 + 1];    // �ɽ����
  LONGLONG        llStkMatchedCount;          // �ɽ�����
  LONGLONG        llStkBuyLeftQty;            // ����ʣ������
  LONGLONG        llStkSaleLeftQty;           // ����ʣ������
  char            szUpdTime[32 + 1];          // ����ʱ��
  char            szRemark[56 + 1];           // ��ע
};

//-------------------------------10303224:��ҵ���̺󶨼������ѯ--------------------------
struct MATRADEAPI CReqStkQryClosingMktSecondboardField
{
  char            chStkex;                    // �г�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ��
  int             iQueryNum;                  // ��ѯ����
};

struct MATRADEAPI CRspStkQryClosingMktSecondboardField
{
  char            szQryPos[32 + 1];           // ��λ��
  int             iTrdDate;                   // ��������
  char            chStkex;                    // �г�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkName[64 + 1];          // ֤ȯ����
  char            szStkCls[2 + 1];            // ֤ȯ���
  char            szClosingPrice[21 + 1];     // �������̼�
  LONGLONG        llStkMatchedQty;            // �ɽ�����
  char            szStkMatchedAmt[21 + 1];    // �ɽ����
  LONGLONG        llStkBuyLeftQty;            // ����ʣ������
  LONGLONG        llStkSaleLeftQty;           // ����ʣ������
  char            chStkSuspended;             // ͣ�Ʊ�ʶ
  char            szUpdTime[32 + 1];          // ����ʱ��
  char            szRemark[56 + 1];           // ��ע
};

//-------------------------------10301641:ETF�ͻ����Ӻ�ͬ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqStkQryEtfContractInfoField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
};

struct MATRADEAPI CRspStkQryEtfContractInfoField
{
  LONGLONG        llCustCode;                 // �ͻ�����
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            chStkex;                    // �����г�
  char            szStkbd[2 + 1];             // ���װ��
  int             iIntOrg;                    // �ڲ�����
  char            szStkName[64 + 1];          // ֤ȯ����
  int             iExpDate;                   // ��Ч����
  int             iSignDate;                  // ǩ������
  char            szContractSn[32 + 1];       // ��ͬ���
  char            szSignTime[6 + 1];          // ǩԼʱ��
  char            chSignChannel;              // ǩԼ����
  char            szSignMacid[32 + 1];        // ǩԼMAC��ַ
  char            chStatus;                   // ״̬ 0-���� 1-��Լ
  char            chSignRiskNotic;            // �Ƿ���ǩ����ս�ʾ�� 0-��ǩ�� 1-δǩ���ݲ�ʹ�ã�
  char            szRemark[64 + 1];           // ��ע
};

//-------------------------------10303097:�Ϻ����ֹɷݶ�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryReductLimitShField
{
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[32 + 1];          // ֤ȯ����
};

struct MATRADEAPI CRspStkQryReductLimitShField
{
  int             iTrdDate;                   // ��������
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[32 + 1];          // ֤ȯ����
  LONGLONG        llMaxReductQty;             // ��������������
  LONGLONG        llDzjyMaxReductQty;         // ��������������
  LONGLONG        llTotalReductQty;           // �����ۼƼ�������
  LONGLONG        llDzjyTotalReductQty;       // ���ڽ����ۼƼ�������
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  LONGLONG        llStkConfirmQty;            // ֤ȯ�϶�����1
  LONGLONG        llStkConfirmQty2;           // ֤ȯ�϶�����2
  LONGLONG        llStkBln;                   // ֤ȯ���
  LONGLONG        llDzjyLimitQty;             // ���ڼ������÷���������
  LONGLONG        llStkFrz;                   // ֤ȯ��������
  char            szRemark[128 + 1];          // ��ע��Ϣ
  int             iUpdDate;                   // ��������
  LONGLONG        llLimitAvlQty;              // ���ۼ���ʣ����
  LONGLONG        llDzjyNoLimitAvlQty;        // ���ڼ��ַ�����ʣ����
  LONGLONG        llDzjyLimitAvlQty;          // ���ڼ�������ʣ����
};

//-------------------------------10303098:���ڼ��ֹɷݶ�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqStkQryReductLimitSzField
{
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkPbu[8 + 1];            // ���׵�Ԫ
};

struct MATRADEAPI CRspStkQryReductLimitSzField
{
  char            szTrdacct[20 + 1];          // �����˻�
  char            szStkCode[32 + 1];          // ֤ȯ����
  char            szStkpbu[8 + 1];            // ���׵�Ԫ
  LONGLONG        llStkBln;                   // ֤ȯ���
  LONGLONG        llStkFrz;                   // ֤ȯ��������
  LONGLONG        llDzjyLimitQty;             // ���÷���������
  LONGLONG        llDzjyReductQty;            // ����ͨ�����ڼ���
  LONGLONG        llReductQty;                // �ɾ��ۺʹ��ڼ���
  LONGLONG        llStkBuyQty;                // �����г�����
  LONGLONG        llReductLimit;              // ���ۼ��ֶ��
  LONGLONG        llDzjyReductLimit;          // ���ڼ��ֶ��
  LONGLONG        llInitDzjyLimitQty;         // ��ʼ���÷���������
  LONGLONG        llInitDzjyReductQty;        // ��ʼ����ͨ�����ڼ���
  LONGLONG        llInitReductQty;            // ��ʼ�ɾ��ۺʹ��ڼ���
  LONGLONG        llInitStkBuyQty;            // ��ʼ�����г�����
  LONGLONG        llInitReductLimit;          // ��ʼ���ۼ��ֶ��
  LONGLONG        llInitDzjyReductLimit;      // ��ʼ���ڼ��ֶ��
  LONGLONG        llDzjyLimitQtyInclfrz;      // ���÷����������������ᣩ
  LONGLONG        llDzjyReductQtyInclfrz;     // ����ͨ�����ڼ��֣������ᣩ
  LONGLONG        llReductQtyInclfrz;         // �ɾ��ۺʹ��ڼ��֣������ᣩ
  LONGLONG        llStkBuyQtyInclfrz;         // �����г����루�����ᣩ
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  int             iUpdDate;                   // ��������
  LONGLONG        llLimitAvlQty;              // ���ۼ���ʣ����
  LONGLONG        llDzjyNoLimitAvlQty;        // ���ڼ��ַ�����ʣ����
  LONGLONG        llDzjyLimitAvlQty;          // ���ڼ�������ʣ����
};

//////////////////////////////////////////////////////////////////////////
//-------------------------------10302102:����ί��(����)-------------------------
struct MATRADEAPI CReqStkOrderFlashField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻�
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻�
  char            szStkCode[8 + 1];           // ֤ȯ����
  char            szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG        llOrderQty;                 // ί������
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  int             iTgwIndex;                  // ָ�����̵��±�
  char            szStkpbu[8 + 1];            // ���׵�Ԫ(δ����)
  char            szClientInfo[256 + 1];      // �ն���Ϣ(δ����)
};

struct MATRADEAPI CRspStkOrderFlashField
{
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
};

//-------------------------------10302104:ί�г���(����)------------------------------------
struct MATRADEAPI CReqStkCancelOrderFlashField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iStkBiz;                      // ֤ȯҵ��
  int           iOrderBsn;                    // ί������(δ����)
  char          szClientInfo[256 + 1];        // �ն���Ϣ(δ����)
  LONGLONG      llCustCode;                   // �ͻ�����(δ����)
  LONGLONG      llFortuneCode;                // �Ƹ��˻�(δ����)
};

struct MATRADEAPI CRspStkCancelOrderFlashField
{
  char          szOrderId[10 + 1];            // ��ͬ��� ԭί�к�ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  int           iStkBiz;                      // ֤ȯҵ��
  char          szWtOrderId[10 + 1];          // ί�к�ͬ�� ����ί�к�ͬ���
  int           iOrderBsn;                    // ί������(δ����)
  char          szOrderPrice[21 + 1];         // ί�м۸�(δ����)
  LONGLONG      llOrderQty;                   // ί������(δ����)
  char          szOrderAmt[21 + 1];           // ί�н��(δ����)
  char          szOrderFrzAmt[21 + 1];        // ������(δ����)
  char          szStkpbu[8 + 1];              // ���׵�Ԫ(δ����)
  char          szStkCode[8 + 1];             // ֤ȯ����(δ����)
  char          szStkName[64 + 1];            // ֤ȯ����(δ����)
  int           iStkBizAction;                // ҵ����Ϊ(δ����)
  char          chCancelStatus;               // �ڲ�������־(δ����)
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�(δ����)
  char          szMsgOk[32 + 1];              // �ڳ���Ϣ(δ����)
  char          szCancelList[256 + 1];        // �����б�(δ����)
  LONGLONG      llFortuneCode;                // �Ƹ��˻�(δ����)
};

//-------------------------------10302103:���ί��(����)------------------------------------
struct MATRADEAPI CReqStkCombOrderFlashField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  int           iStkBiz;                      // ֤ȯҵ��
  int           iStkBizAction;                // ҵ����Ϊ
  int           iOrderBsn;                    // ί������
  int           iCuacctSn;                    // �˻����
  char          chErrorFlag;                  // �������ױ�־
  char          szStrategyText[32768 + 1];    // ������Ϣ
  int           iTgwIndex;                    // ָ�����̵��±�
  LONGLONG      llCustCode;                   // �ͻ�����(δ����)
  char          szClientInfo[256 + 1];        // �ն���Ϣ(δ����)
  char          szTrdTermcode[20 + 1];        // �ն�������(δ����)
  char          chSecurityLevel;              // ��ȫ�ֶ�(δ����)
  char          szSecurityInfo[256 + 1];      // ��ȫ��Ϣ(δ����)
  char          chPublishCtrlFlag;            // ��Ʊ��ر�־(δ����)
};

struct MATRADEAPI CRspStkCombOrderFlashField
{
  int           iOrderBsn;                    // ί������
  char          szOrderId[10 + 1];            // ��ͬ���
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iStkBiz;                      // ֤ȯҵ��
  int           iCuacctSn;                    // �˻����
  int           iOrderRet;                    // ί�н��
  char          szRetInfo[256 + 1];           // ������Ϣ
  char          szOrderPrice[21 + 1];         // ί�м۸�(δ����)
  LONGLONG      llOrderQty;                   // ί������(δ����)
  char          szOrderAmt[21 + 1];           // ί�н��(δ����)
  char          szOrderFrzAmt[21 + 1];        // ������(δ����)
  char          szStkpbu[8 + 1];              // ���׵�Ԫ(δ����)
  char          szStkName[64 + 1];            // ֤ȯ����(δ����)
  int           iStkBizAction;                // ҵ����Ϊ(δ����)
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�(δ����)
};

//-------------------------------00102023:�ɽ��ر�����------------------------------------
struct MATRADEAPI CRtnStkOrderFillField
{
   char szMatchedSn[32 + 1];        // 成交编号，唯一标识一笔成交
   char chStkex;                    // 交易市场（如 'S' 表示上交所，'Z' 表示深交所）
   char szStkCode[8 + 1];           // 证券代码，标识股票或证券
   char szOrderId[10 + 1];          // 订单编号，唯一标识订单
   char szTrdacct[20 + 1];          // 交易账户，记录发起交易的账户
   LONGLONG llMatchedQty;           // 成交数量，表示本次成交的证券数量
   char szMatchedPrice[11 + 1];     // 成交价格，字符串格式的价格
   char szOrderFrzAmt[21 + 1];      // 订单冻结金额，订单执行时的冻结资金
   char szRltSettAmt[21 + 1];       // 实时结算金额，实际结算的资金
   char szFundAvl[21 + 1];          // 可用资金，账户当前可用于交易的资金
   LONGLONG llStkAvl;               // 可用证券数量，可用于交易的证券数量
   char szOpptStkpbu[8 + 1];        // 对手方席位，记录交易对手的席位编号
   char szOpptTrdacct[20 + 1];      // 对手方交易账户，记录对手方的账户
   int iMatchedDate;                // 成交日期，通常为 YYYYMMDD 格式
   char szMatchedTime[8 + 1];       // 成交时间，格式通常为 HHMMSS
   char chIsWithdraw;               // 撤单标志，'T' 表示撤单
   LONGLONG llCustCode;             // 客户代码，标识客户身份
   LONGLONG llCuacctCode;           // 资产账户代码，标识资产账户
   int iOrderBsn;                   // 订单业务编号，标识订单的业务类型
   int iCuacctSn;                   // 账户序列号，标识账户的唯一序列
   char szStkbd[2 + 1];             // 交易板块，标识交易的子市场
   char chMatchedType;              // 成交类型，标识成交的具体类别
   char chOrderStatus;              // 订单状态，如已成交、已取消等
   int iStkBiz;                     // 证券业务类型（如 100 表示买入）
   int iStkBizAction;               // 证券业务行为，具体业务操作的子类型
   char szOfferRetMsg[64 + 1];      // 报单返回信息，记录报单失败原因或状态
   LONGLONG llOrderQty;             // 订单数量，订单的总委托数量
   LONGLONG llWithdrawnQty;         // 已撤单数量，订单中已撤销的部分
   LONGLONG llTotalMatchedQty;      // 累计成交数量，订单的总成交量
   char chCuacctAttr;               // 账户属性，标识账户的类型或特性
   char szTotalMatchedAmt[21 + 1];  // 累计成交金额，订单的总成交金额
   LONGLONG llStkQty;               // 持有证券数量，账户当前的持仓量
   char szMatchedAmt[21 + 1];       // 本次成交金额，本次成交的资金金额
   char szHFundAvl[21 + 1];         // 港股可用资金，港股交易的可用资金
   char szRemark1[32 + 1];          // 预留字段1，用于扩展功能
   char szRemark2[32 + 1];          // 预留字段2，用于扩展功能
   char szRemark3[32 + 1];          // 预留字段3，用于扩展功能
   char szRemark4[32 + 1];          // 预留字段4，用于扩展功能
   char szRemark5[32 + 1];          // 预留字段5，用于扩展功能
   char szRemark6[32 + 1];          // 预留字段6，用于扩展功能
   char szRemark7[32 + 1];          // 预留字段7，用于扩展功能
   char szRemark8[32 + 1];          // 预留字段8，用于扩展功能
   char szRemark9[32 + 1];          // 预留字段9，用于扩展功能
   char szRemarkA[32 + 1];          // 预留字段A，用于扩展功能
   char szOrderNo[10 + 1];          // 委托编号，订单的委托标识
   LONGLONG llStkTrdEtfctn;         // ETF 认购数量，ETF 相关交易数据
   LONGLONG llStkTrdEtfrmn;         // ETF 赎回数量，ETF 相关交易数据
};

//-------------------------------00102023:����ɽ�����------------------------------------
struct MATRADEAPI CRtnStkPefEtfFillField
{
  int             iTrdDate;                   // ��������
  LONGLONG        llSerialNo;                 // ��ˮ��� ��ˮ��ţ�Ψһ
  char            szOccurTime[32 + 1];        // ����ʱ��
  char            szMatchedSn[16 + 1];        // �ɽ���� �Ͻ�����cjbh,������Ψһ ���:��
  char            szMatchedSno[32 + 1];       // �ɽ����� �Ͻ�����gdxm+bcye ���: ִ�б��EXECID
  char            chStkex;                    // �����г� �����ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �����ֵ�[STKBD]
  char            szEtfCode[8 + 1];           // ETF����
  char            chEtfCr;                    // ���귽�� 1.�깺2.���
  char            chBizType;                  // ҵ������ 1.�ǿ������֤ȯ2.�������֤ȯ2.�ǿ����ֽ����3.�����ֽ����4.ȫ�ֽ����5.�ֽ���
  char            chSettlementMode;           // ���շ�ʽ 1.���������2.T+0���ȫ��ǵ���3.T+1���ȫ��ǵ���4.RTGS��T+0���ȫ��ǵ���5.���մ���
  char            szCustCode[16 + 1];         // �ͻ����� �ͻ�����
  char            szCuacctCode[16 + 1];       // �ʲ��˻� ���ͻ����ʲ��˻�
  char            szTrdacct[20 + 1];          // �����˻� �����˻����ɶ��˻���
  char            szBizAmt[21 + 1];           // ҵ���� ��ǰ�������
  char            szFundBln[21 + 1];          // �ʽ�ǰ��� ���ͻ����ʲ��˻���ǰ���
  char            szFundAvl[21 + 1];          // �ʽ���ý�� ���ͻ����ʲ��˻����ý��
  char            szFundFrz[21 + 1];          // �ʽ𶳽��� ���ͻ����ʲ��˻�������
  char            szFundUfz[21 + 1];          // �ʽ�ⶳ��� ���ͻ����ʲ��˻��ⶳ���
  char            szFundTrdFrz[21 + 1];       // �ʽ��׶����� ���ͻ����ʲ��˻����׶�����
  char            szFundTrdUfz[21 + 1];       // �ʽ��׽ⶳ��� ���ͻ����ʲ��˻����׽ⶳ���
  char            szFundTrdOtd[21 + 1];       // �ʽ�����;��� ���ͻ����ʲ��˻�������;���
  char            szFundTrdBln[21 + 1];       // �ʽ��������� ���ͻ����ʲ��˻�����������
  char            szStkpbu[8 + 1];            // ���׵�Ԫ ���׵�Ԫ��ϯλ��
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szStkCode[8 + 1];           // ֤ȯ���� �ɷֹ�֤ȯ���������г�����
  char            chStkCls;                   // ֤ȯ��� ֤ȯ���DD[STK_CLS]
  LONGLONG        llBizQty;                   // ҵ������ ������ɷݽ������� �Ͻ�����cjsl
  LONGLONG        llStkBln;                   // ֤ȯ���
  LONGLONG        llStkAvl;                   // ֤ȯ��������
  LONGLONG        llStkTrdFrz;                // ֤ȯ���׶�������
  LONGLONG        llStkTrdUfz;                // ֤ȯ���׽ⶳ����
  LONGLONG        llStkTrdOtd;                // ֤ȯ������;����
  LONGLONG        llStkTrdBln;                // ֤ȯ������������
  LONGLONG        llStkTrdEtfctn;             // ETF�깺����
  LONGLONG        llStkTrdEtfrmn;             // ETF�������
  char            szUncollectedAmt[21 + 1];   // ��ش������ʽ�
  char            szCollectedAmt[21 + 1];     // ����Ѵ����ʽ�
  char            szQryPos[32 + 1];           // ��λ�� ��ѯ��λ��
  int             iMatchedDate;               // �ɽ�����
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ��
  char            szMatchedPrice[21 + 1];     // �ɽ��۸� �Ͻ���cjjg
  char            szApplyId[10 + 1];          // ������ �Ͻ���Sqbh
  char            szInvTrdacct[20 + 1];       // Ͷ����֤ȯ�˻�
  char            szInvPbu[8 + 1];            // Ͷ���߽��׵�Ԫ
  char            chExecType;                 // ����ִ��״̬
  char            szRltSettAmt[21 + 1];       // ʵʱ������
};

//-------------------------------00102024:ȷ�ϻر�����------------------------------------
struct MATRADEAPI CRtnStkOrderConfirmField
{
  char          chStkex;                    // �����г�
  char          szStkCode[8 + 1];           // ֤ȯ����
  char          szOrderId[10 + 1];          // ��ͬ���
  char          szTrdacct[20 + 1];          // �����˻�
  char          chIsWithdraw;               // ������־
  LONGLONG      llCustCode;                 // �ͻ�����
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  int           iOrderBsn;                  // ί������
  int           iCuacctSn;                  // �˻����
  char          szStkbd[2 + 1];             // ���װ��
  char          chOrderStatus;              // ί��״̬
  int           iStkBiz;                    // ֤ȯҵ��
  int           iStkBizAction;              // ҵ����Ϊ
  char          chCuacctAttr;               // �˻�����
  int           iOrderDate;                 // ί������
  int           iOrderSn;                   // ί�����
  int           iIntOrg;                    // �ڲ�����
  char          szStkpbu[8 + 1];            // ���׵�Ԫ
  char          szOrderPrice[21 + 1];       // ί�м۸�
  LONGLONG      llOrderQty;                 // ί������
  char          szRemark1[32 + 1];          // Ԥ���ֶ�1
  char          szRemark2[32 + 1];          // Ԥ���ֶ�2
  char          szRemark3[32 + 1];          // Ԥ���ֶ�3
  char          szRemark4[32 + 1];          // Ԥ���ֶ�4
  char          szRemark5[32 + 1];          // Ԥ���ֶ�5
  char          szRemark6[32 + 1];          // Ԥ���ֶ�6
  char          szRemark7[32 + 1];          // Ԥ���ֶ�7
  char          szRemark8[32 + 1];          // Ԥ���ֶ�8
  char          szRemark9[32 + 1];          // Ԥ���ֶ�9
  char          szRemarkA[32 + 1];          // Ԥ���ֶ�A
};

//-------------------------------00102030:�ɽ��ر�����(����)------------------------------------
struct MATRADEAPI CRtnStkOrderFillFlashField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  LONGLONG      llMatchedQty;               // ���γɽ�����
  int           iOrderBsn;                  // ί������
  char          szMatchedSn[16 + 1];        // �ɽ����
  char          szMatchedPrice[11 + 1];     // ���γɽ��۸�
  char          szOrderId[10 + 1];          // ��ͬ���
  char          szStkCode[8 + 1];           // ֤ȯ����
  char          szStkbd[2 + 1];             // ���װ��
  char          chIsWithdraw;               // ������־
  char          chMatchedType;              // �ɽ�����
  char          chOrderStatus;              // ί��״̬
};

//-------------------------------00102031:ȷ�ϻر�����(����)------------------------------------
struct MATRADEAPI CRtnStkOrderConfirmFlashField
{
  char          szStkCode[8 + 1];           // ֤ȯ����
  char          szOrderId[10 + 1];          // ��ͬ���
  char          chIsWithdraw;               // ������־
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  int           iOrderBsn;                  // ί������
  char          szStkbd[2 + 1];             // ���װ��
};

#if defined(OS_IS_LINUX)
#pragma pack()
#else
#pragma pack(pop)
#endif

END_NAMESPACE_MACLI

#endif  //__MA_CLI_STK_TRADE_API_STRUCT_H__