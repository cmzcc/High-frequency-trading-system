#if !defined(__MA_CLI_FISL_TRADE_API_STRUCT_H__)
#define __MA_CLI_FISL_TRADE_API_STRUCT_H__
#include "maCliTradeApi.h"
BGN_NAMESPACE_MACLI

#if defined(OS_IS_LINUX)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

//-------------------------------10321001:���ȯ��Ϣ��ѯ------------------------------
struct MATRADEAPI CReqFislQryUndlStkInfoField
{
  char          chStkex;                    // ֤ȯ������ �ֵ�[STKEX]
  char          szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char          szStkCode[8 + 1];           // ֤ȯ���� 
  char          chCurrEnableFi;             // �������� �ֵ�[CURR_ENABLE_FI]
  char          chCurrEnableSl;             // ������ȯ �ֵ�[CURR_ENABLE_SL]
  char          chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char          szQueryPos[32 + 1];         // ��λ�� ��1�β�ѯ�Ϳգ�������ѯ���� ���ѯ�������ʹ��
  int           iQueryNum;                  // ��ѯ���� ���2000
  LONGLONG      llCuacctCode;               // �ʲ��˻� 
};

struct MATRADEAPI CRspFislQryUndlStkInfoField
{
  char          szQryPos[32 + 1];           // ��λ�� 
  char          chStkex;                    // ֤ȯ������ �ֵ�[STKEX]
  char          szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char          szStkCode[8 + 1];           // ֤ȯ���� 
  char          szStkName[64 + 1];          // ֤ȯ���� 
  char          szFiMarginRatio[21 + 1];    // ���ʱ�֤����� 
  char          szSlMarginRatio[21 + 1];    // ��ȯ��֤����� 
  char          chCurrEnableFi;             // �������ʱ�־ �ֵ�[CURR_ENABLE_FI]
  char          chCurrEnableSl;             // ������ȯ��־ �ֵ�[CURR_ENABLE_SL]
  char          szCollatRatio[21 + 1];      // ����Ʒ������ 
  char          chCreditFundCtl;            // ���ʽ��׿��� 
  char          chCreditStkCtl;             // ��ȯ���׿��� 
};

//-------------------------------10321010:����֤ȯ��Ϣ��ѯ----------------------------
struct MATRADEAPI CReqFislQryColStkInfoField
{
  char          chStkex;                      // ֤ȯ������
  char          szStkbd[2 + 1];               // ���װ��  
  char          szStkCode[8 + 1];             // ֤ȯ����  
  char          chQueryFlag;                  // ��ѯ����  
  char          szQueryPos[32 + 1];           // ��λ��    
  int           iQueryNum;                    // ��ѯ����  
};

struct MATRADEAPI CRspFislQryColStkInfoField
{
  char          szQryPos[32 + 1];             // ��λ��      
  char          chStkex;                      // ֤ȯ������  
  char          szStkbd[2 + 1];               // ���װ��    
  char          szStkCode[8 + 1];             // ֤ȯ����    
  char          szStkName[64 + 1];            // ֤ȯ����    
  char          szCollatRatio[21 + 1];        // ����Ʒ������
  char          chCreditFundUseFlag;          // �����ʽ�ʹ�ñ�־
  char          szCollatCls[2 + 1];           // ������� �ֵ�[COLLAT_CLS]
};

//-------------------------------10301022:LOF��Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqFislQryLofInfoField
{
  char szStkbd[2 + 1];                        // ���װ��
  char szLofCode[8 + 1];                      // LOF���� 
};

struct MATRADEAPI CRspFislQryLofInfoField
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
struct MATRADEAPI CReqFislOrderField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�    
  char          szStkbd[2 + 1];               // ���װ��    
  char          szStkCode[8 + 1];             // ֤ȯ����    
  char          szOrderPrice[21 + 1];         // ί�м۸�    
  LONGLONG      llOrderQty;                   // ί������    
  int           iStkBiz;                      // ֤ȯҵ��    
  int           iStkBizAction;                // ҵ����Ϊ    
  int           iOrderBsn;                    // ί������    
  char          szClientInfo[256 + 1];        // �ն���Ϣ    
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�    
  char			szTrdacctCommon[20 + 1];	  // ��֤ͨȯ�˻�
  int           iCuacctSn;                    // �˻����    
  LONGLONG      llCustCode;                   // �ͻ�����    
  char          szStkpbu[8 + 1];              // ���׵�Ԫ    
  char          szOrderText[1024 + 1];         // ί����չ    
  char          chSecurityLevel;              // ��ȫ�ֶ�    
  char          szSecurityInfo[256 + 1];      // ��ȫ��Ϣ    
  char          szComponetStkCode[8 + 1];     // �ɷݹɴ���  
  char          szComponetStkbd[2 + 1];       // �ɷݹɰ��  
  char          szStkbdLink[2 + 1];           // �������    
  char          chPublishCtrlFlag;            // ��Ʊ��ر�־
  char          szRepayOrderId[10 + 1];       // ������ͬ���
  int           iRepayOpeningDate;            // ������Լ����
  char          szRepayStkCode[8 + 1];        // ����֤ȯ����
  char          szTrdacctLink[20 + 1];        // �����ɶ�
  char          szInitTrdAmt[21 + 1];         // ��ʼ���׽��
  int           iRepchDay;                    // ��������
  char          szLoanerTrdacct[20 + 1];      // ������֤ȯ�˻�
  char          szRepaySno[32 + 1];           // ��Լ���
  char          szContactInfo[32 + 1];        // ���ڽ���ʱ����ϵ��ʽ
  int           iItemno;                      // ��Լ���
  char          chAutoBuyFlag;                // �Զ�չ�ڱ�־
  char          chCloseOutMode;               // ƽ�ַ�ʽ
  char          chEtfMode;                    // ETFģʽ �ֵ�ETF_MODE
  char          szMeetingSeq[10 + 1];         // �ɶ�������
  char          szVoteId[10 + 1];             // �鰸���
  char          szOppLofCode[3 + 1];          // ת�뷽�������
  LONGLONG      llMatchNo;                    // �ɽ�Լ���� 
  char          szOpptStkpbu[8 + 1];          // ���ַ����׵�Ԫ 
  char          szOpptTrdacct[20 + 1];        // ���ַ��ɶ��˻� 
  char          szStkprop[2 + 1];             // �ɷ����� 
  char          szLoanerName[40 + 1];         // ��ϵ������
};

struct MATRADEAPI CRspFislOrderField
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

//-------------------------------10302004:ί�г���------------------------------------
struct MATRADEAPI CReqFislCancelOrderField
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

struct MATRADEAPI CRspFislCancelOrderField
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
struct MATRADEAPI CReqFislMaxTradeQtyField
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

struct MATRADEAPI CRspFislMaxTradeQtyField
{
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻� 
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  LONGLONG        llOrderQty;                 // ί������ ��ί���������
  LONGLONG        llStkQty;                   // �ɷֹ����� 
};

//-------------------------------10322001:������ȯֱ�ӻ���----------------------------
struct MATRADEAPI CReqFislMarginRepayField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            chRepayType;                // �������� 0:ȫ������ 1:������ȯ����
  char            szRepayOrderId[10 + 1];     // ������ͬ��� 
  int             iRepayOpeningDate;          // ������Լ���� 
  char            szRepayStkCode[8 + 1];      // ����֤ȯ���� 
  char            szRepayContractAmt[21 + 1]; // ������� 
  char            chRepayAmtCls;              // ���������� 0:ȫ���黹 1:���黹���� 2:���黹��Ϣ
  char            szRemark[128 + 1];          // ��ע 
  char            chCashType;                 // ͷ������
  char            szOrderText[1024 + 1];      // ί����չ ֱ�ӻ���ָ����Լ��ʽ:�ؼ���1=ֵ1,�ؼ���2=ֵ2������?ORDER_TEXT:DEBTLIST=��Լ����1|��ͬ���1;��Լ����2|��ͬ���
};

struct MATRADEAPI CRspFislMarginRepayField
{
  char            szRealRepayAmt[21 + 1];     // ʵ�ʻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            szRepayContractAmt[21 + 1]; // ������� 
};

//-------------------------------10303001:�����ʽ��ѯ--------------------------------
struct MATRADEAPI CReqFislQryExpendableFundField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iValueFlag;                   // ȡֵ��־
};

struct MATRADEAPI CRspFislQryExpendableFundField
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
struct MATRADEAPI CReqFislQryFreqTradeLmtParamField
{
  LONGLONG      llCustCode;                      // �ͻ�����
  LONGLONG      llCuacctCode;                    // �ʲ��ʺ�
  char          szStkbd[2 + 1];                  // ���װ��
  char          szTrdacct[20 + 1];               // �����˺�
};

struct MATRADEAPI CRspFislQryFreqTradeLmtParamField
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
struct MATRADEAPI CReqFislQryExpendableFundCiXiField
{
  LONGLONG        llCustCode;                 // �ͻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ���
  int             iValueFlag;                 // ȡֵ��־
};

struct MATRADEAPI CRspFislQryExpendableFundCiXiField
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
struct MATRADEAPI CReqFislQryExpendableSharesField
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

struct MATRADEAPI CRspFislQryExpendableSharesField
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
struct MATRADEAPI CReqFislQryCurrDayOrderField
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

struct MATRADEAPI CRspFislQryCurrDayOrderField
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
  char          szOpSite[32 + 1];             // ����վ��    
  char          chChannel;                    // ��������    
  char          szStkCls[2 + 1];              // ֤ȯ���
};

//-------------------------------10303004:���ճɽ���ѯ--------------------------------
struct MATRADEAPI CReqFislQryCurrDayFillField
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

struct MATRADEAPI CRspFislQryCurrDayFillField
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
  char          szStkTrdacct[10 + 1];         // ֤ȯ�˻�    
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
  char          szStkCls[2 + 1];              // ֤ȯ���
};

//-------------------------------10303005:�ɶ��˻���ѯ--------------------------------
struct MATRADEAPI CReqFislQryStkholderAcctField
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
  char          chQueryMode;                  // ��ѯģʽ 
};

struct MATRADEAPI CRspFislQryStkholderAcctField
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
struct MATRADEAPI CReqFislQryCanWithdrawOrderField
{
  LONGLONG      llCustCode;                   // �ͻ�����
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkCode[8 + 1];             // ֤ȯ����
  char          szOrderId[10 + 1];            // ��ͬ���
  char          iOrderBsn;                    // ί������
  char          szTrdacct[20 + 1];            // �����˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��  
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
};

struct MATRADEAPI CRspFislQryCanWithdrawOrderField
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
struct MATRADEAPI CReqFislQryExpendableFundExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
};

struct MATRADEAPI CRspFislQryExpendableFundExField
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
};

//-------------------------------10303012:���ùɷݲ�ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryExpendableSharesExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��  
  int           iQueryNum;                    // ��ѯ����
};

struct MATRADEAPI CRspFislQryExpendableSharesExField
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
  LONGLONG      llStkIntradayQty;             // ������ͨ����ɷ�
  LONGLONG      llFislIntradayQty;            // ������������ɷ�
};

//-------------------------------10303013:����ί�в�ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryCurrDayOrderExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��  
  int           iQueryNum;                    // ��ѯ����
  char          szStkbd[2 + 1];               // ���װ��
  char          szStkpbu[8 + 1];              // ���׵�Ԫ
  char          szOrderId[10 + 1];            // ��ͬ���
  int           iCuacctSn;                    // �˻����
  char          chFlag;                       // ��ѯ��־
};

struct MATRADEAPI CRspFislQryCurrDayOrderExField
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
struct MATRADEAPI CReqFislQryCurrDayFillExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chQueryFlag;                  // ��ѯ����
  char          szQueryPos[32 + 1];           // ��λ��  
  int           iQueryNum;                    // ��ѯ����
  int           iCuacctSn;                    // �˻����
  char          szOrderId[10 + 1];            // ��ͬ��� 
};

struct MATRADEAPI CRspFislQryCurrDayFillExField
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
struct MATRADEAPI CReqFislQryStkholderAcctExField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
};

struct MATRADEAPI CRspFislQryStkholderAcctExField
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
struct MATRADEAPI CReqFislQryCanWithdrawOrderExField
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

struct MATRADEAPI CRspFislQryCanWithdrawOrderExField
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

//-------------------------------10321004:������ȯЭ���ѯ----------------------------
struct MATRADEAPI CReqFislQryMarginProtocolField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  int           iIntOrg;                      // �ڲ�����
  LONGLONG      llCashFiNo;                   // ����ͷ����
  LONGLONG      llCashSlNo;                   // ��ȯͷ����
};

struct MATRADEAPI CRspFislQryMarginProtocolField
{
  LONGLONG      llCashFiNo;                   // ����ͷ����    
  LONGLONG      llCashSlNo;                   // ��ȯͷ����    
  LONGLONG      llCustCode;                   // �ͻ�����        
  LONGLONG      llCuacctCode;                 // �ʲ��˻�        
  char          chCurrency;                   // ���Ҵ���        
  int           iIntOrg;                      // �ڲ�����        
  int           iCreditIntGrp;                // ��������      
  char          szCreditLine[21 + 1];         // ���ö��        
  char          chCreditType;                 // ���ö������    
  char          szMaxCredit[21 + 1];          // ������ö������
  char          szMinCredit[21 + 1];          // ��С���ö������
  int           iContractTerm;                // ��Լ����        
  int           iAgtBgnDate;                  // Э�鿪ʼ����    
  int           iAgtEndDate;                  // Э���������    
  char          chCalIntMode;                 // ��Ϣ����ģʽ    
  char          chDebtRepayMode;              // ��ծ����ģʽ    
  char          chAgmtStatus;                 // Э��״̬        
  char          szFiCredit[21 + 1];           // �������ö��    
  char          szSlCredit[21 + 1];           // ��ȯ���ö��    
  char          szFundRightundRight[128 + 1]; // �ʽ�Ȩ��
  char          szRemark[256 + 1];            // ��ע
  char          chDebtsStatus;                // ��ծ״̬
  char          szFiMarginrateInit[21 + 1];   // �ͻ���ʼ���ʱ�֤�����
  char          szSlMarginrateInit[21 + 1];   // �ͻ���ʼ��ȯ��֤�����
  char          szFiMarginrateAgio[21 + 1];   // ���ʱ�֤������ۿ�
  char          szSlMarginrateAgio[21 + 1];   // ��ȯ��֤������ۿ�
  char          szFiMarginrateLow[21 + 1];    // ���ʱ�֤���������
  char          szSlMarginrateLow[21 + 1];    // ��ȯ��֤���������
  LONGLONG      llFiShareQuoteNo;             // ���ʹ����ȱ��
  LONGLONG      llSlShareQuoteNo;             // ��ȯ�����ȱ��
  char          szCreditFundUsed[21 + 1];     // �����ʽ�ռ��
};

//-------------------------------10323001:������ȯ��Լ��ѯ----------------------------
struct MATRADEAPI CReqFislQryMarginContractField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  int           iBgnDate;                     // ��ʼ����
  int           iEndDate;                     // ��������
  char          szOrderId[10 + 1];            // ��ͬ���
  char          chContractType;               // ��Լ����
  char          szQueryPos[32 + 1];           // ��λ��  
  LONGLONG      llQueryNum;                   // ��ѯ����
  LONGLONG      llCustCode;                   // �ͻ�����
  char          chStkex;                      // �����г�
  char          szStkbd[2 + 1];               // ���װ��
  char          szTrdacct[20 + 1];            // �����˻�
  char          szStkCode[8 + 1];             // ֤ȯ����
  int           iIntOrg;                      // �ڲ�����
  int           iOpOrg;                       // ��������
  char          chContractStatus;             // ��Լ״̬
  char          chRepayFlag;                  // ƽ��״̬
  char          chQueryFlag;                  // ��ѯ����
};

struct MATRADEAPI CRspFislQryMarginContractField
{
  char          szQryPos[32 + 1];             // ��λ��              
  LONGLONG      llCashNo;                     // ͷ����            
  int           iTrdDate;                     // ��������            
  char          chContractType;               // ��Լ����            
  char          szTrdacct[20 + 1];            // �����˻�            
  char          chStkex;                      // �����г�            
  char          szStkbd[2 + 1];               // ���װ��            
  int           iOpeningDate;                 // ��������            
  char          szStkCode[8 + 1];             // ֤ȯ����            
  char          szOrderId[10 + 1];            // ��ͬ���            
  char          szFiDebtsAmt[21 + 1];         // ���ʸ�ծ���        
  LONGLONG      llSlDebtsQty;                 // ��ȯ��ծ����        
  LONGLONG      llRepaidQty;                  // ��ȯ�ѻ�����        
  char          szRepaidAmt[21 + 1];          // �����ѻ����        
  char          chContractStatus;             // ��Լ״̬            
  int           iContractExpireDate;          // ��Լ������          
  char          szMarginRatio[21 + 1];        // ��֤�����          
  char          szMarginAmt[21 + 1];          // ռ�ñ�֤��          
  char          szRights[21 + 1];             // δ����Ȩ����      
  LONGLONG      llRightsQty;                  // δ����Ȩ������      
  char          szOverdueFee[21 + 1];         // ����δ����Ϣ��      
  int           iLastRepayDate;               // ��󳥻�����        
  LONGLONG      llCustCode;                   // �ͻ�����            
  LONGLONG      llCuacctCode;                 // �ʲ��˻�            
  char          chCurrency;                   // ���Ҵ���            
  int           iIntOrg;                      // �ڲ�����            
  char          szOrderPrice[21 + 1];         // ί�м۸�            
  LONGLONG      llOrderQty;                   // ί������            
  char          szOrderAmt[21 + 1];           // ί�н��            
  char          szOrderFrzAmt[21 + 1];        // ί�ж�����        
  LONGLONG      llWithdrawnQty;               // �ѳ�������          
  LONGLONG      llMatchedQty;                 // �ɽ�����            
  char          szMatchedAmt[21 + 1];         // �ɽ����            
  char          szRltSettAmt[21 + 1];         // ʵʱ������        
  char          szSlDebtsMktvalue[21 + 1];    // ��ȯ��ծ��ֵ        
  LONGLONG      llRltRepaidQty;               // ��ȯʵʱ�黹����    
  char          szRltRepaidAmt[21 + 1];       // ����ʵʱ�黹���    
  char          szMatchedAmtRepay[21 + 1];    // ���ɽ����          
  int           iCalIntDate;                  // ��ʼ��Ϣ����        
  char          szContractInt[21 + 1];        // ��Լ��Ϣ            
  char          szContractIntAccrual[21 + 1]; // ��Ϣ����            
  char          szOverRights[21 + 1];         // ����δ����Ȩ��      
  char          szRightsRepay[21 + 1];        // ������Ȩ��          
  char          szRightsRlt[21 + 1];          // ʵʱ����Ȩ��        
  char          szOverRightsRlt[21 + 1];      // ʵʱ����Ԥ��Ȩ��    
  LONGLONG      llOverRightsQty;              // ����δ����Ȩ������  
  LONGLONG      llRightsQtyRepay;             // �ѳ���Ȩ������      
  LONGLONG      llRightsQtyRlt;               // ʵʱ����Ȩ������    
  LONGLONG      llOverRightsQtyRlt;           // ʵʱ��������Ȩ������
  char          szContractFee[21 + 1];        // ������ȯϢ��        
  char          szFeeRepay[21 + 1];           // ������Ϣ��          
  char          szFeeRlt[21 + 1];             // ʵʱ����Ϣ��        
  char          szOverDuefeeRlt[21 + 1];      // ʵʱ��������Ϣ��    
  char          szPuniDebts[21 + 1];          // ���ڱ���Ϣ        
  char          szPuniDebtsRepay[21 + 1];     // ����Ϣ����        
  char          szPuniDebtsRlt[21 + 1];       // ʵʱ���ڱ���Ϣ    
  char          szPuniFee[21 + 1];            // ��Ϣ�����ķ�Ϣ      
  char          szPuniFeeRepay[21 + 1];       // ��������Ϣ          
  char          szPuniFeeRlt[21 + 1];         // ʵʱ����Ϣ�ѷ�Ϣ    
  char          szPuniRights[21 + 1];         // ����Ȩ�淣Ϣ        
  char          szPuniRightsRepay[21 + 1];    // Ȩ�淣Ϣ����        
  char          szPuniRightsRlt[21 + 1];      // ʵʱ����Ȩ�淣Ϣ    
  int           iClosingDate;                 // ��Լ�˽�����        
  char          szClosingPrice[21 + 1];       // ��Լ�˽�۸�        
  int           iOpOrg;                       // ��������            
  char          chContractCls;                // ��Լ���            
  char          szProIncome[21 + 1];          // �ο�ӯ��            
  char          szPledgeCuacct[21 + 1];       // ��Ѻ�ʲ�            
  char          szFiRepayAmt[21 + 1];         // ���ʳ���            
  LONGLONG      llSlRepayQty;                 // ��ȯ����     
  char          szStkName[64 + 1];            // ֤ȯ���� 
  int           iRelasNo;                     // ������ծ��ˮ�� 
  char          szDebtProfit[21 + 1];         // ��ծӯ�� 
  char          szRefProfit[21 + 1];          // ����ӯ�� 
  char          szContractRate[21 + 1];       // ��Լ���� 
  char          szUnreplayFund[21 + 1];       // δ����� 
  LONGLONG      llUnreplayQty;                // δ������ 
  char          chOverdueFlag;                // ���ڱ�־       
  char          szCmpdInt[21 + 1];            // �������
  char          szCmpdPrin[21 + 1];           // ��������
};

//-------------------------------10323002:������ȯ��֤���������ѯ------------------
struct MATRADEAPI CReqFislQryMarginDepositAvlField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  LONGLONG      llCustCode;                   // �ͻ�����
};

struct MATRADEAPI CRspFislQryMarginDepositAvlField
{
  LONGLONG      llCustCode;                   // �ͻ�����      
  LONGLONG      llCuacctCode;                 // �ʲ��˻�      
  char          chCurrency;                   // ���Ҵ���      
  int           iIntOrg;                      // �ڲ�����      
  char          szMarginValue[21 + 1];        // ��֤��������
};

//-------------------------------10323003:������ȯ���ÿ��ö�Ȳ�ѯ--------------------
struct MATRADEAPI CReqFislQryMarginCreditAvlField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
  char          chContractType;               // ��Լ����
};

struct MATRADEAPI CRspFislQryMarginCreditAvlField
{
  LONGLONG      llCustCode;                   // �ͻ�����    
  LONGLONG      llCuacctCode;                 // �ʲ��˻�    
  char          chCurrency;                   // ���Ҵ���    
  int           iIntOrg;                      // �ڲ�����    
  char          chContractType;               // ��Լ����    
  char          szCreditValue[21 + 1];        // ���ÿ��ö��
};

//-------------------------------10323006:���ÿͻ��ʲ���ծ��ѯ------------------------
struct MATRADEAPI CReqFislQryCreditCustDebtsField
{
  LONGLONG      llCuacctCode;                 // �ʲ��˻�
  char          chCurrency;                   // ���Ҵ���
};

struct MATRADEAPI CRspFislQryCreditCustDebtsField
{
  LONGLONG        llCustCode;                 // �ͻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  char            szFiRate[21 + 1];           // �������� 
  char            szSlRate[21 + 1];           // ��ȯ���� 
  char            szFreeIntRate[21 + 1];      // ��Ϣ���� 
  char            chCreditStatus;             // ����״̬ 0:���� 1:δ���� 2:������ 3:���� 9:����
  char            szMarginRate[21 + 1];       // ά�ֵ������� 
  char            szRealRate[21 + 1];         // ʵʱ�������� 
  char            szTotalAssert[21 + 1];      // ���ʲ� 
  char            szTotalDebts[21 + 1];       // �ܸ�ծ 
  char            szMarginValue[21 + 1];      // ��֤�������� 
  char            szFundAvl[21 + 1];          // �ʽ���ý�� 
  char            szFundBln[21 + 1];          // �ʽ���� 
  char            szSlAmt[21 + 1];            // ��ȯ���������ʽ� 
  char            szGuaranteOut[21 + 1];      // ��ת�������ʲ� 
  char            szColMktVal[21 + 1];        // ����֤ȯ��ֵ 
  char            szFiAmt[21 + 1];            // ���ʱ��� 
  char            szTotalFiFee[21 + 1];       // ����Ϣ�� 
  char            szFiTotalDebts[21 + 1];     // ���ʸ�ծ�ϼ� 
  char            szSlMktVal[21 + 1];         // Ӧ����ȯ��ֵ 
  char            szTotalSlFee[21 + 1];       // ��ȯϢ�� 
  char            szSlTotalDebts[21 + 1];     // ��ȯ��ծ�ϼ� 
  char            szFiCredit[21 + 1];         // �������Ŷ�� 
  char            szFiCreditAvl[21 + 1];      // ���ʿ��ö�� 
  char            szFiCreditFrz[21 + 1];      // ���ʶ�ȶ��� 
  char            szSlCredit[21 + 1];         // ��ȯ���Ŷ�� 
  char            szSlCreditAvl[21 + 1];      // ��ȯ���ö�� 
  char            szSlCreditFrz[21 + 1];      // ��ȯ��ȶ��� 
  char            szRights[21 + 1];           // ����Ȩ�� 
  char            szRightsUncomer[21 + 1];    // ����Ȩ�棨��;�� 
  LONGLONG        llRightsQty;                // ���Ȩ�� 
  LONGLONG        llRightsQtyUncomer;         // ���Ȩ�棨��;�� 
  char            szTotalCredit[21 + 1];      // �ܶ�� 
  char            szTotalCteditAvl[21 + 1];   // �ܿ��ö�� 
  char            szAddMarginAmt[21 + 1];     // ��׷�ӱ�֤��� 
  char            szStkValue[21 + 1];         // ֤ȯ��ֵ 
  char            szTotalSlAmt[21 + 1];       // ����ȯ�����ʽ� 
  char            szTotalSlInt[21 + 1];       // ��ȯԤ����Ϣ
  char            szTotalAssertGy[21 + 1];    // �����ʲ�
  char            szStkValueGy[21 + 1];       // ������ֵ
};

//-------------------------------10323008:������ȯ�ʽ�ͷ���ѯ------------------------
struct MATRADEAPI CReqFislQryMarginFundCashField
{
  LONGLONG      llCashNo;                     // ͷ����
};

struct MATRADEAPI CRspFislQryMarginFundCashField
{
  LONGLONG      llCashNo;                     // ͷ����    
  char          chCashType;                   // ͷ������    
  char          szCashBln[21 + 1];            // ͷ���ܶ��  
  char          szCashAvl[21 + 1];            // ͷ����ö��
  char          chCurrency;                   // ���Ҵ���    
};

//-------------------------------10323009:������ȯ�ɷ�ͷ���ѯ------------------------
struct MATRADEAPI CReqFislQryMarginSharesCashField
{
  LONGLONG        llCashNo;                   // ͷ���� 
  char            chStkex;                    // ֤ȯ������ 
  char            szStkbd[32 + 1];            // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  char            chMeshFlag;                 // �ϲ���־ 0Ϊ���ϲ���1Ϊ�ϲ�
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ���� ����ȫ������
  char            szQueryPos[32 + 1];         // ��λ�� ��ֵΪ��¼�� ���ѯ�������ʹ��
  int             iQueryNum;                  // ��ѯ���� 
};

struct MATRADEAPI CRspFislQryMarginSharesCashField
{
  LONGLONG        llCashNo;                   // ͷ���� 
  char            szTrdacct[20 + 1];          // �����˻� 
  char            chStkex;                    // �����г� 
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  LONGLONG        llAssetBln;                 // ͷ���ܶ�� 
  LONGLONG        llAssetAvl;                 // ͷ����ö�� 
  char            chCashType;                 // ͷ������ 
  char            szSrkName[64 + 1];          // ֤ȯ���� 
  LONGLONG        llRepayQty;                 // ���ջ�ȯ 
  LONGLONG        llSlUnlockQty;              // ��ȯ���� 
  LONGLONG        llSlRemainQty;              // ʣ����ȯ���� 
  LONGLONG        llRemainQty;                // ���軹ȯ���� 
  char            szQryPos[32 + 1];           // ��λ�� 
};

//-------------------------------10323011:�ɳ�������ѯ------------------------
struct MATRADEAPI CReqFislQryCanRepayField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCashType;                 // ͷ������ 
};

struct MATRADEAPI CRspFislQryCanRepayField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            szFiTotalDebts[21 + 1];     // ���ʸ�ծ�ϼ� 
  char            szTotalSlFee[21 + 1];       // ��ȯϢ�� 
  char            szCanRepayAmt[21 + 1];      // �ɳ������ 
  char            szMayrepay[21 + 1];         // �������ý�� 
};

//-------------------------------10301034:֤ȯ��ֵ��Ȳ�ѯ------------------------------------
struct MATRADEAPI CReqFislMktQuotaField
{
  char          szTrdacct[20 + 1];            // ֤ȯ�˻�
};

struct MATRADEAPI CRspFislMktQuotaField
{
  char            chStkex;                    // ������ �ֵ�[STKEX]
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻� 
  char            szStkpbu[8 + 1];            // ���׵�Ԫ 
  LONGLONG        llMktQuota;                 // ��ֵ���(����) 
  LONGLONG        llKcbMktquota;              // ��ֵ���(�ƴ���) 
};

//-------------------------------10323030:���ʺ�Լ���ܲ�ѯ------------------------------------
struct MATRADEAPI CReqFislQryFiContractSumField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  char          szStkbd[2 + 1];             // ���װ��
  char          szStkCode[8 + 1];           // ֤ȯ����
};

struct MATRADEAPI CRspFislQryFiContractSumField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�      
  char          szStkbd[2 + 1];             // ���װ��      
  char          szStkCode[8 + 1];           // ֤ȯ����      
  char          szSettAmt[21 + 1];          // ������      
  LONGLONG      llOpenQty;                  // ��������      
  char          szRepayAmt[21 + 1];         // �黹���      
  char          szOrderAmt[21 + 1];         // ί�н��      
  LONGLONG      llOrderQty;                 // ί������      
  LONGLONG      llMatchedQty;               // �ѳɽ�����    
  char          szRltSettAmt[21 + 1];       // ʵʱ������  
  char          szMarginAmt[21 + 1];        // ռ�ñ�֤��    
  char          szCollatRatio[21 + 1];      // ����Ʒ������  
  char          szFiMarginRatio[21 + 1];    // ���ʱ�֤�����
  LONGLONG      llRltSettQty;               // ʵʱ��������  
};

//-------------------------------10323031:��ȯ��Լ���ܲ�ѯ------------------------------------
struct MATRADEAPI CReqFislQrySlContractSumField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  char          szStkbd[2 + 1];             // ���װ��
  char          szStkCode[8 + 1];           // ֤ȯ����
};

struct MATRADEAPI CRspFislQrySlContractSumField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�      
  char          szStkbd[2 + 1];             // ���װ��      
  char          szStkCode[8 + 1];           // ֤ȯ����      
  LONGLONG      llOpenQty;                  // ��������          
  LONGLONG      llRepayQty;                 // �黹����          
  char          szSettAmt[21 + 1];          // ������          
  char          szRepayAmt[21 + 1];         // �黹���          
  LONGLONG      llOrderQty;                 // ί������          
  LONGLONG      llRightsQty;                // δ����Ȩ������    
  LONGLONG      llOverRightsQty;            // ����δ����Ȩ������
  char          szCollatRatio[21 + 1];      // ����Ʒ������      
  char          szSlMarginRatio[21 + 1];    // ��ȯ��֤�����    
  LONGLONG      llRltOpenQty;               // ʵʱ��������      
  char          szRltSettAmt[21 + 1];       // ʵʱ������      
};

//-------------------------------10323080:��Լչ�������ѯ------------------------------------
struct MATRADEAPI CReqFislContractExtField
{
  int           iBgnDate;                   // ��ʼ����
  int           iEndDate;                   // ��������
  LONGLONG      llCustCode;                 // �ͻ�����
  char          szStkbd[2 + 1];             // �г����
  char          szOrderId[10 + 1];          // ��ͬ���
  char          chApplyStatus;              // ����״̬
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  int           iIntOrg;                    // �ڲ�����
  char          szQueryPos[32 + 1];         // ��λ��
  int           iQueryNum;                  // ��ѯ����
  int           iKOpeningDate;              // ���һ����¼��������
  LONGLONG      llKCustCode;                // ���һ����¼�ͻ���
  char          szKStkbd[2 + 1];            // ���һ����¼���װ��
  char          szKOrderId[10 + 1];         // ���һ����¼��Լ���
  char          szKOccureDate[40 + 1];      // ���һ����¼��������
};

struct MATRADEAPI CRspFislContractExtField
{
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  LONGLONG      llCustCode;                 // �ͻ�����
  int           iIntOrg;                    // �ڲ�����
  int           iOpeningDate;               // ��������
  char          szStkbd[2 + 1];             // ���װ��
  char          szOrderId[10 + 1];          // ��ͬ���
  char          chApplyStatus;              // ����״̬
  char          szRemark[128 + 1];          // ��ע��Ϣ
  int           iApplyDate;                 // ��������
  char          chStkex;                    // �����г�
  char          szQueryPos[32 + 1];         // ��λ��
  LONGLONG      llTotalNum;                 // �ܼ�¼��    
  char          szOccurTime[32 + 1];        // ����ʱ�� yyyy-mm-dd hh24miss.nnn
};

//�ʽ𻮲�
struct MATRADEAPI CReqFislFundTransferField
{
  char         szOrgId[4 + 1];               // ��������
  LONGLONG     llCuacctCode;                 // �ʽ��˺�
  char         chCurrency;                   // ���Ҵ���
  char         szFundAvl[21 + 1];            // �ʽ����
  char         chDirect;                     // ��������
};
struct MATRADEAPI CRspFislFundTransferField
{
  int          iSNo;                         // ������ˮ��
  int          iVipSno;                      // VIP������ˮ��
};

//-------------------------------10301105:�û���¼------------------------------------
struct MATRADEAPI CReqFislUserLoginField
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

struct MATRADEAPI CRspFislUserLoginField
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
  char          szTrdacctName[128 + 1];       // �����˻�����
  char          szSessionId[256 + 1];         // �Ựƾ֤    
  int           iIntOrg;                      // �ڲ�����    
  char          chCuacctAttr;                 // �ʲ��˻�����
  int           iFlashPort;                   // ����ٶ˿ں�
  char          szFlashStkBizes[64 + 1];      // �����ҵ��
  char          chSzFlashMode;                // ����������г�����ģʽ
  char          chShFlashMode;                // ������Ϻ��г�����ģʽ
  char          chFlashEnableFlag;            // �������ñ�־ ��0��-δ���� ��1��-������
  char          chTrdacctExcls;               // �����˻���� '0' -- �����˻���'1' -- �����˻���'2' -- ���������˻���'3' -- ���������˻�
  char          szThirdParty[1024 + 1];       // ������ 
  char          chTrdacctMainFlag;            // ���ɶ��˻���־ ��0��- ���ɶ��˻�  ��1��- ���ɶ��˻�
  char          chCuacctSyncFlag;             // ���˻���ڵ��־ ��0��-�ǵ��˻���ڵ㣬��1��-���˻���ڵ�
  char          szFlashIp[64 + 1];            // ����ٵ�ַ
};

//-------------------------------00102023:�ɽ��ر�����------------------------------------
struct MATRADEAPI CRtnFislOrderFillField
{
  char          szMatchedSn[32 + 1];        // �ɽ����
  char          chStkex;                    // �����г�
  char          szStkCode[8 + 1];           // ֤ȯ����
  char          szOrderId[10 + 1];          // ��ͬ���
  char          szTrdacct[20 + 1];          // �����˻�
  LONGLONG      llMatchedQty;               // ���γɽ�����
  char          szMatchedPrice[11 + 1];     // ���γɽ��۸�
  char          szOrderFrzAmt[21 + 1];      // ί�ж�����
  char          szRltSettAmt[21 + 1];       // ʵʱ������
  char          szFundAvl[21 + 1];          // �ʽ���ý��ɽ���
  LONGLONG      llStkAvl;                   // ֤ȯ�����������ɽ���
  char          szOpptStkpbu[8 + 1];        // �Է�ϯλ
  char          szOpptTrdacct[20 + 1];      // �Է������˺�
  int           iMatchedDate;               // �ɽ�����
  char          szMatchedTime[8 + 1];       // �ɽ�ʱ��
  char          chIsWithdraw;               // ������־
  LONGLONG      llCustCode;                 // �ͻ�����
  LONGLONG      llCuacctCode;               // �ʲ��˻�
  int           iOrderBsn;                  // ί������
  int           iCuacctSn;                  // �˻����
  char          szStkbd[2 + 1];             // ���װ��
  char          chMatchedType;              // �ɽ�����
  char          chOrderStatus;              // ί��״̬
  int           iStkBiz;                    // ֤ȯҵ��
  int           iStkBizAction;              // ֤ȯҵ����Ϊ
  char          szOfferRetMsg[64 + 1];      // �걨��Ϣ �������ϵ�ʱ���طϵ�ԭ��
  LONGLONG      llOrderQty;                 // ί������
  LONGLONG      llWithdrawnQty;             // �ѳ�������
  LONGLONG      llTotalMatchedQty;          // �ۼƳɽ�����
  char          chCuacctAttr;               // �˻�����
  char          szTotalMatchedAmt[21 + 1];  // �ۼƳɽ����
  LONGLONG      llStkQty;                   // ӵ����
  char          szMatchedAmt[21 + 1];       // �ѳɽ����
  char          szHFundAvl[21 + 1];         // �۹��ʽ����
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
  char          szOrderNo[10 + 1];          // ί�б��
  LONGLONG      llStkTrdEtfctn;             // ETF�깺����
  LONGLONG      llStkTrdEtfrmn;             // ETF�������
};

//-------------------------------00102023:����ɽ�����------------------------------------
struct MATRADEAPI CRtnFislPefEtfFillField
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
struct MATRADEAPI CRtnFislOrderConfirmField
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


//-------------------------------10103500:������ȯ��ծ������ˮ��ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryRpcRepaymentDetailField
{
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          szPaykind[128 + 1];   // ������ʽ
    char          szDebtstype[128 + 1]; // ��ծ����
    char          szMarket[128 + 1];    // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szBegindate[8 + 1];   // ��ʼ����
    char          szEnddate[8 + 1];     // ��������
    int           iReladate;            // ��ծ����
    int           iRelasno;             // ��ծ��ˮ��
    LONGLONG      llPositionid;         // ͷ����
    int           iRelaLogbizdate;      // �����ʽ���ˮ����
    int           iRelaLogsno;          // �����ʽ���ˮ���
    char          szPosstr[32 + 1];     // ��λ��
    int           iQrynum;              // ��������
};
struct MATRADEAPI CRspFislQryRpcRepaymentDetailField
{
    int           iSysdate;                   // ��������
    int           iSno;                       // ��ˮ��
    LONGLONG      llCustid;                   // �ͻ�����
    char          szCustname[32 + 1];         // �ͻ�����
    LONGLONG      llFundid;                   // �ʽ��ʺ�
    char          chMoneytype;                // ���Ҵ���
    int           iReladate;                  // ��Լ����
    int           iRelasno;                   // ��Լ���
    char          chMarket;                   // �����г�
    char          szStkcode[10 + 1];          // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    char          chDirect;                   // ��������
    char          chPaykind;                  // ������ʽ
    char          szCreditdebtstype[128 + 1]; // ��ծ����
    char          szFundeffect[21 + 1];       // �ʽ�����
    int           iStkeffect;                 // �ɷݷ�����
    int           iSrcLogbizdate;             // ��Դ�ʽ���ˮ����
    int           iSrcLogsno;                 // ��Դ�ʽ���ˮ���
    int           iRelaLogbizdate;            // �����ʽ���ˮ����
    int           iRelaLogsno;                // �����ʽ���ˮ���
    LONGLONG      llRfscontractno;            // Լ����Լ���
    LONGLONG      llPositionid;               // ͷ����
};
//-------------------------------10103501:�ʽ��ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryRpcFundField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcFundField
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
    char          szMaxdraw[21 + 1];     // ��ȡ���
};
//-------------------------------10103502:�����ʽ���ˮ��ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryRpcFundDetailField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcFundDetailField
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
//-------------------------------10103503:�¹��깺�ͻ���ֵ��Ȳ�ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryRpcIPOSubscriptionLimitField
{
    char          szMarket[10 + 1]; // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szOrgid[4 + 1];   // ��������
    int           iCount;           // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcIPOSubscriptionLimitField
{
    char          szPosstr[64 + 1]; // ��λ��
    int           iServerid;        // �ڵ���
    int           iDbfrec;          // ���
    LONGLONG      llCustid;         // �ͻ�����
    char          szOrgid[4 + 1];   // ��������
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llCustquota;      // �ͻ���ֵ���
    int           iReceivedate;     // ��������
    char          szRemark[32 + 1]; // ��ע
};
//-------------------------------10103504:��֤ת��[����]--------------------------
struct MATRADEAPI CReqFislRpcBankStkTransField
{
    LONGLONG      llFundid;          // �ʽ��˺�
    char          chMoneytype;       // ���Ҵ���
    char          szFundpwd[32 + 1]; // �ʽ�����
    char          szBankcode[4 + 1]; // ���д���
    char          szBankpwd[32 + 1]; // ��������
    char          chBanktrantype;    // ת������
    char          szTranamt[21 + 1]; // ת�ʽ��
};
struct MATRADEAPI CRspFislRpcBankStkTransField
{
    int           iSno;             // ί�����
    int           iSyserrid;        // �������
    char          szErrmsg[64 + 1]; // ������Ϣ
};
//-------------------------------10103505:��ѯ�˻����[����]--------------------------
struct MATRADEAPI CReqFislQryRpcFundBalaField
{
    LONGLONG      llFundid;          // �ʽ��˺�
    char          chMoneytype;       // ���Ҵ���
    char          szFundpwd[32 + 1]; // �ʽ�����
    char          szBankcode[4 + 1]; // ���д���
    char          szBankpwd[32 + 1]; // ��������
};
struct MATRADEAPI CRspFislQryRpcFundBalaField
{
    int           iSno;                 // ί�����
    char          szErrmsg[64 + 1];     // ������Ϣ
    int           iSyserrid;            // �������
    char          szFundeffect[21 + 1]; // �������
};
//-------------------------------10103506:��֤ת�ʲ�ѯ[����]--------------------------
struct MATRADEAPI CReqFislQryRpcBankStkTransInfoField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ���Ҵ���
    int           iSno;             // ת�����
    int           iBegindate;       // ת�˿�ʼ����
    int           iEnddate;         // ת�˽�������
};
struct MATRADEAPI CRspFislQryRpcBankStkTransInfoField
{
    int           iOperdate;            // ת������
    int           iOpertime;            // ת��ʱ��
    LONGLONG      llFundid;             // �ʽ��˺�
    char          chMoneytype;          // ���Ҵ���
    LONGLONG      llCustid;             // �ͻ�����
    char          szBankcode[4 + 1];    // ���д���
    char          chBanktranid;         // ҵ������
    int           iSno;                 // ��ͬ���
    char          szFundeffect[21 + 1]; // ί�н��
    char          szFundbal[21 + 1];    // ���
    char          szRemark[32 + 1];     // ��ע��Ϣ
    char          chStatus;             // ������
    char          chSourcetype;         // ������
    char          szBankmsgid[16 + 1];  // �ⲿ��Ϣ����
    char          szBankmsg[64 + 1];    // �ⲿ��Ϣ����
    char          szErrormsg[64 + 1];   // ϵͳ������Ϣ
    int           iSyserrid;            // ϵͳ�������
};
//-------------------------------10103507:�޸��ʽ�����[����]--------------------------
struct MATRADEAPI CReqFislRpcChgFundPwdField
{
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szOldfundpwd[32 + 1]; // ���ʽ�����
    char          szNewfundpwd[32 + 1]; // ���ʽ�����
};
struct MATRADEAPI CRspFislRpcChgFundPwdField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103508:�޸Ľ�������[����]--------------------------
struct MATRADEAPI CReqFislRpcChgTrdPwdField
{
    char          szNewpwd[32 + 1]; // ������
};
struct MATRADEAPI CRspFislRpcChgTrdPwdField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103509:��ȡ��ͨת��(����)�˺�(410601) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcBankAcctField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chMoneytype;       // ���Ҵ���
    LONGLONG      llFundid;          // �ʽ��ʻ�
};
struct MATRADEAPI CRspFislQryRpcBankAcctField
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
//-------------------------------10103510:��ȡ��ͨ�ⲿ(����)�˺�(410602) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcOtherBankAcctField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chMoneytype;       // ���Ҵ���
    LONGLONG      llFundid;          // �ʽ��ʺ�
};
struct MATRADEAPI CRspFislQryRpcOtherBankAcctField
{
    LONGLONG      llCustid;            // �ͻ�����
    char          szOrgid[4 + 1];      // ��������
    char          szBankcode[4 + 1];   // ���д���
    char          szBankid[32 + 1];    // �����ʻ�
    char          szSubbankid[32 + 1]; // �������ʻ�
    LONGLONG      llFundid;            // �ʽ��ʺ�
};
//-------------------------------10103511:�����¹��嵥��ѯ(411549) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcIPOField
{
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iIssuedate;       // �깺����
};
struct MATRADEAPI CRspFislQryRpcIPOField
{
    char          chMarket;           // �����г�
    char          szStkcode[8 + 1];   // ֤ȯ����
    char          szStkname[64 + 1];  // ֤ȯ����
    char          szLinkstk[8 + 1];   // ���ɴ���
    char          chIssuetype;        // ���з�ʽ
    int           iIssuedate;         // �깺����
    char          szFixprice[21 + 1]; // �깺�۸�
    int           iBuyunit;           // �깺��λ
    int           iMinqty;            // �깺��С����
    int           iMaxqty;            // �깺�������
};
//-------------------------------10103512:��Ų�ѯ(411518) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcDistributionField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSecuid[32 + 1];  // �ɶ�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcDistributionField
{
    char          szPoststr[32 + 1];     // ��λ��
    int           iBizdate;              // �������
    char          chMarket;              // �����г�
    char          szSecuid[32 + 1];      // �ɶ�����
    char          szStkname[64 + 1];     // ֤ȯ����
    char          szStkcode[16 + 1];     // ֤ȯ����
    int           iMatchqty;             // �ɽ�����
    char          szMateno[32 + 1];      // �깺���
    char          szOrderid[10 + 1];     // ί�к�
    int           iOrderdate;            // ί������
    char          szMateerrmsg[128 + 1]; // ��ע
};
//-------------------------------10103513:��ֵ������ǩ��ѯ(411547) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcMktCapPlacingField
{
    char          szSecuid[10 + 1]; // �ɶ�����
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chIssuetype;      // ���з�ʽ
};
struct MATRADEAPI CRspFislQryRpcMktCapPlacingField
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
    char          szFrzamt[21 + 1];     // ��ǩ������
    int           iClearsno;            // ����˳��
    char          chIssuetype;          // ���з�ʽ
    char          chStatus;             // ����״̬
};
//-------------------------------10103514:��ǩ��ʷ��ѯ(411560) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcWinningHistoryField
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
struct MATRADEAPI CRspFislQryRpcWinningHistoryField
{
    char          szPoststr[32 + 1];    // ��λ��
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
    int           iClearsno;            // ����˳��
    char          chIssuetype;          // ���з�ʽ
    char          chStatus;             // ����״̬
};
//-------------------------------10103515:��ֵ���۽���˳���޸ģ�411548��[����]--------------------------
struct MATRADEAPI CReqFislRpcChgMktCapDistDeliOrderField
{
    int           iMatchdate;       // ��ǩ����
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    int           iClearsno;        // ����˳��
};
struct MATRADEAPI CRspFislRpcChgMktCapDistDeliOrderField
{
    int           iSerialno; // ������ˮ��
};
//-------------------------------10103516:�����ѯ(411520) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcDeliOrderField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcDeliOrderField
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
};
//-------------------------------10103517:���ʲ�ѯ(411521) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcChkAcctField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcChkAcctField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iSno;                 // �ʽ���ˮ���
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
//-------------------------------10103518:����ί�л���(410514) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcOrderSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspFislQryRpcOrderSummaryField
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
//-------------------------------10103519:���ճɽ�����(410516) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcMatchSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspFislQryRpcMatchSummaryField
{
    int           iOperdate;            // ��������
    LONGLONG      llCustid;             // �ͻ�����
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
//-------------------------------10103520:��ʷί����ϸ��ѯ(411511) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcHistoryOrderDetailField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    char          chCreditmethod;    // Լ��ҵ�����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcHistoryOrderDetailField
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
    int           iOperdate;             // ��������
    char          chCreditid;            // ���ý���
    char          chCreditflag;          // ���ý�������
    char          chCreditmethod;        // Լ��ҵ�����
};
//-------------------------------10103521:��ʷ�ɽ���ϸ��ѯ(411513) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcHistoryMatchDetailField
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
struct MATRADEAPI CRspFislQryRpcHistoryMatchDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iBizdate;             // �ɽ�����
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
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iStkbal;              // �ɷݱ������
};
//-------------------------------10103522:ת������ҵ����Ϣ(410211) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcBankTransBasicInfoField
{
    char          chMoneytype;       // ���Ҵ���
    char          szBankcode[4 + 1]; // ���д���
};
struct MATRADEAPI CRspFislQryRpcBankTransBasicInfoField
{
    char          szBankcode[4 + 1]; // ���д���
    char          chSourcetype;      // ����
    char          chBanktrantype;    // ת�ʷ�ʽ
    char          chFundpwdflag;     // �ʽ�����У��
    char          chBankpwdflag;     // ��������У��
    char          chCheckbankid;     // �����ʺ�У��
    char          chCheckidno;       // ֤��У���־
    char          szOrgid[4 + 1];    // ��������
    char          chMoneytype;       // ���Ҵ���
    char          chStatus;          // ����״̬
};
//-------------------------------10103523:���ʵ���ѯ(411525) [����]--------------------------
struct MATRADEAPI CReqFislQryRpcStatementField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMoneytype;       // ���Ҵ���
    char          chPrintflag;       // �ش��ʶ
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcStatementField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iCleardate;           // ��������
    int           iBizdate;             // ��������
    int           iSno;                 // �ʽ���ˮ���
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
    char          szStkeffect[21 + 1];  // �ɷݷ�����
};
//-------------------------------10103527:֤ȯ��Ϣ--------------------------
struct MATRADEAPI CReqFislRpcStkInfoField
{
    char          chMarket;         // �����г�
    char          chStklevel;       // ֤ȯ����
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislRpcStkInfoField
{
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
    char          chStklevel;             // ֤ȯ����
    int           iQuitdate;              // ����֤ȯ���׽�ֹ����
    char          szMemotext[128 + 1];    // ����֤ȯ��ʾ��Ϣ
};
//-------------------------------10103528:����������Ϣ(ҵ�����)--------------------------
struct MATRADEAPI CReqFislRpcOrgInfoField
{
    char          szQryorgid[4 + 1]; // ��������
};
struct MATRADEAPI CRspFislRpcOrgInfoField
{
    char          szOrgid[4 + 1];    // ��������
    char          szOrgname[32 + 1]; // �������
};
//-------------------------------10103526:ȡ�ֵ���Ϣ--------------------------
struct MATRADEAPI CReqFislRpcDictInfoField
{
    char          szDictitem[8 + 1]; // �ֵ���Ŀ
    char          szSubitem[4 + 1];  // �ֵ�����
};
struct MATRADEAPI CRspFislRpcDictInfoField
{
    char          szOrgid[4 + 1];        // ��������
    char          szDictitem[8 + 1];     // �ֵ���Ŀ
    char          szSubitem[4 + 1];      // �ֵ�����
    char          szSubitemname[32 + 1]; // ��������
};
//-------------------------------10103525:��ѯ��ǰϵͳ״̬--------------------------
struct MATRADEAPI CReqFislQryRpcCurSysStatField
{
};
struct MATRADEAPI CRspFislQryRpcCurSysStatField
{
    int           iSysdate;              // ϵͳ����
    int           iOrderdate;            // ί������
    char          chStatus;              // ϵͳ����״̬
    char          szNightremark[32 + 1]; // ҹ��״̬ע��
    int           iSystime;              // ����ʱ��
};
//-------------------------------10103530:�û���¼--------------------------
struct MATRADEAPI CReqFislRpcLoginField
{
    char          chInputtype;         // ��¼����
    char          szInputid[64 + 1];   // ��¼��ʶ
    char          szProcName[128 + 1]; // ��������������
    char          szLoginip[64 + 1];   // ��¼ip
    char          szLoginmac[32 + 1];  // ��¼mac
};
struct MATRADEAPI CRspFislRpcLoginField
{
    char          chCustprop;             // �ͻ�����
    char          chMarket;               // �����г�
    char          szSecuid[10 + 1];       // �ɶ�����
    char          chSecuidtype;           // �ɶ��ʻ�����
    char          szName[16 + 1];         // �ɶ�����
    LONGLONG      llFundid;               // ȱʡ�ʽ��ʻ�
    char          chFundidtype;           // �ʽ��ʻ�����
    LONGLONG      llCustid;               // �ͻ�����
    char          szCustname[16 + 1];     // �ͻ�����
    char          szOrgid[4 + 1];         // ��������
    char          szBankcode[4 + 1];      // ���д���
    char          szIdentitysign[64 + 1]; // ����ǩ��
    char          chTimeoutflag;          // ��ʱ����
    char          chAuthlevel;            // ��֤��ʽ/����
    int           iPwderrtimes;           // ��¼�������
    char          szCustcert[128 + 1];    // �ͻ�֤��
    char          szLastlogindate[8 + 1]; // �ϴε�¼����
    char          szLastlogintime[8 + 1]; // �ϴε�¼ʱ��
    char          szLastloginip[64 + 1];  // �ϴε�¼ip
    char          szLastloginmac[32 + 1]; // �ϴε�¼mac
};
//-------------------------------10103524:�ɶ���ʧ--------------------------
struct MATRADEAPI CReqFislRpcTrdacctReportLossField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspFislRpcTrdacctReportLossField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103529:�ʽ��ʻ���ʧ--------------------------
struct MATRADEAPI CReqFislRpcCuacctReportLossField
{
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szFundpwd[32 + 1]; // �ʽ�����
};
struct MATRADEAPI CRspFislRpcCuacctReportLossField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103531:�������ɶ��ʻ�--------------------------
struct MATRADEAPI CReqFislRpcSetMainTrdacctField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspFislRpcSetMainTrdacctField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103532:�������ʲ��˺�--------------------------
struct MATRADEAPI CReqFislRpcSetMainCuacctField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislRpcSetMainCuacctField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103533:�޸���ϵ��ʽ(���Ͻ���ʹ��)--------------------------
struct MATRADEAPI CReqFislRpcChgContactField
{
    char          szAddr[64 + 1];     // ��ַ
    char          szPostid[16 + 1];   // �ʱ�
    char          szTelno[32 + 1];    // �绰
    char          szMobileno[32 + 1]; // �ƶ��绰
    char          szEmail[32 + 1];    // EMAIL
    char          chContact;          // ���緽ʽ
    char          chContactfrep;      // ����Ƶ��
};
struct MATRADEAPI CRspFislRpcChgContactField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103534:�ͻ����ϲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCustInfoField
{
};
struct MATRADEAPI CRspFislQryRpcCustInfoField
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    char          szOrgid[4 + 1];     // ��������
    char          chSex;              // �Ա�
    char          szAddr[64 + 1];     // ��ַ
    char          szPostid[16 + 1];   // �ʱ�
    char          szTelno[32 + 1];    // �绰
    char          szMobileno[32 + 1]; // �ƶ��绰
    char          szEmail[32 + 1];    // EMAIL
    int           iOpendate;          // ��������
    char          chContact;          // ���緽ʽ
    char          chContactfrep;      // ����Ƶ��
    char          szRemark[32 + 1];   // ��ע��Ϣ
};
//-------------------------------10103535:�޸Ĵ���Ȩ��--------------------------
struct MATRADEAPI CReqFislRpcChgProxyPermissonField
{
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szAgentright[128 + 1]; // ����Ȩ��
};
struct MATRADEAPI CRspFislRpcChgProxyPermissonField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103536:�޸Ĳ�����ʽ--------------------------
struct MATRADEAPI CReqFislRpcChgOperModeField
{
    LONGLONG      llFundid;              // �ʽ��˻�
    char          szNewoperway[128 + 1]; // ������ʽ
};
struct MATRADEAPI CRspFislRpcChgOperModeField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103537:��ѯ�ͻ�������ʽ--------------------------
struct MATRADEAPI CReqFislQryRpcCustOperModeField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspFislQryRpcCustOperModeField
{
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          szOperway[128 + 1]; // ������ʽ
};
//-------------------------------10103538:�޸Ŀͻ���ϵ����Ϣ--------------------------
struct MATRADEAPI CReqFislRpcChgCustInfoField
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
struct MATRADEAPI CRspFislRpcChgCustInfoField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103540:��ѯ�ͻ��ʽ��ʺ�Ȩ��--------------------------
struct MATRADEAPI CReqFislQryRpcCuacctPermissionField
{
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspFislQryRpcCuacctPermissionField
{
    char          szOrgid[4 + 1];       // Ӫҵ������
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          szFundname[16 + 1];   // �ʽ�����
    char          szFundright[512 + 1]; // �ʽ�Ȩ��
};
//-------------------------------10103539:�޸��ʽ��ʺ�Ȩ��--------------------------
struct MATRADEAPI CReqFislRpcChgCuacctPermissionField
{
    LONGLONG      llFundid;           // �ʽ��˻�
    char          szFundright[2 + 1]; // �ʽ�Ȩ��
    char          chAction;           // ��������
};
struct MATRADEAPI CRspFislRpcChgCuacctPermissionField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103541:��ѯ�ͻ�֤ȯ�ʺ�Ȩ��--------------------------
struct MATRADEAPI CReqFislQryRpcTrdacctPermissionField
{
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    char          chMarket;         // �г�
};
struct MATRADEAPI CRspFislQryRpcTrdacctPermissionField
{
    char          chMarket;             // �г�
    char          szSecuid[10 + 1];     // ֤ȯ�˺�
    char          szSecuright[512 + 1]; // ֤ȯȨ��
};
//-------------------------------10103542:���ÿͻ�֤ȯ�ʺ�Ȩ��--------------------------
struct MATRADEAPI CReqFislRpcSetTrdacctPermissionField
{
    char          chAction;            // ��������
    char          chMarket;            // �г�
    char          szSecuid[10 + 1];    // ֤ȯ�˺�
    char          szFundright[2 + 1];  // ֤ȯȨ��
    int           iSigndate;           // ǩ������
    int           iEffectdate;         // Ȩ����Ч����
    char          szRemark[64 + 1];    // ��ע��Ϣ
};
struct MATRADEAPI CRspFislRpcSetTrdacctPermissionField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103543:������ȯ������޲�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcUpLimitQuotaField
{
    LONGLONG      llFundid;         // �ʽ��˺�
};
struct MATRADEAPI CRspFislQryRpcUpLimitQuotaField
{
    char          szLimitamt[21 + 1];     // �������
    char          szFundlimitamt[21 + 1]; // ԭ���ʶ��
    char          szStklimitamt[21 + 1];  // ԭ��ȯ���
    char          szAlllimitamt[21 + 1];  // ԭ�ܶ��
};
//-------------------------------10103544:������ȯ��ȱ��--------------------------
struct MATRADEAPI CReqFislRpcChgLimitQuotaField
{
    LONGLONG      llFundid;                 // �ʽ��˺�
    char          szApFundlimitamt[21 + 1]; // ���ʶ��
    char          szApStklimitamt[21 + 1];  // ��ȯ���
    char          szApAlllimitamt[21 + 1];  // �ܶ��
};
struct MATRADEAPI CRspFislRpcChgLimitQuotaField
{
};
//-------------------------------10103545:��ȱ������--------------------------
struct MATRADEAPI CReqFislRpcChgLimitQuotaApplicationField
{
    LONGLONG      llFundid;                 // �ʽ��˺�
    char          szApFundlimitamt[21 + 1]; // ���ʶ��
    char          szApStklimitamt[21 + 1];  // ��ȯ���
    char          szApAlllimitamt[21 + 1];  // �ܶ��
};
struct MATRADEAPI CRspFislRpcChgLimitQuotaApplicationField
{
};
//-------------------------------10103546:��ȱ������ȡ��--------------------------
struct MATRADEAPI CReqFislRpcChgLimitQuotaApplicationCancelField
{
    int           iSno;              // ������
    char          szRemark[255 + 1]; // ��ע
};
struct MATRADEAPI CRspFislRpcChgLimitQuotaApplicationCancelField
{
};
//-------------------------------10103547:��ȱ�������ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcChgLimitQuotaApplicationField
{
    LONGLONG      llFundid;          // �����ʽ��˺�
    int           iSno;              // ������
    int           iApplydatebegin;   // �������ڿ�ʼ
    int           iApplydateend;     // �������ڽ���
    char          szStatus[128 + 1]; // ����״̬
    int           iQrynum;           // ��ѯ����
    char          szPosstr[64 + 1];  // ��λ��
};
struct MATRADEAPI CRspFislQryRpcChgLimitQuotaApplicationField
{
    int           iServerid;                // ���ı��
    int           iSno;                     // ������
    int           iApplydate;               // ��������
    LONGLONG      llFundid;                 // �ʽ��˺�
    LONGLONG      llCustid;                 // �ͻ�����
    char          szOrgid[4 + 1];           // ��������
    char          szApFundlimitamt[21 + 1]; // �������ʶ��
    char          szApStklimitamt[21 + 1];  // ������ȯ���
    char          szApAlllimitamt[21 + 1];  // �����ܶ��
    char          chStatus;                 // ����״̬
    int           iApprovaldate;            // ��������
    char          szChkremark[255 + 1];     // ������ע
    char          szRemark[255 + 1];        // ��ע
    char          szPosstr[64 + 1];         // ��λ��
};
//-------------------------------10103571:ȡ֤ȯ����ǰ���¼۵�,֧����������--------------------------
struct MATRADEAPI CReqFislRpcStkAvlAndLatestPriceField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��˻�
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislRpcStkAvlAndLatestPriceField
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
//-------------------------------10103572:ȡ���������,֧����������--------------------------
struct MATRADEAPI CReqFislRpcMaxStkQtyField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chBsflag;          // �������
    char          szPrice[21 + 1];   // �۸�
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chCreditid;        // ���ý���
    char          chCreditflag;      // ���ý�������
    char          chCreditmethod;    // Լ��ҵ�����
    LONGLONG      llRfscontractno;   // Լ����Լ���
    char          chHiqtyflag;       // ������ޱ�־
    LONGLONG      llPositionid;      // ͷ����
};
struct MATRADEAPI CRspFislRpcMaxStkQtyField
{
    int           iMaxstkqty; // �ɷ�����
};
//-------------------------------10103573:ί������ҵ��,֧���������ף���ΧԼ��������ȯί��--------------------------
struct MATRADEAPI CReqFislRpcOrderField
{
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    LONGLONG      llFundid;            // �ʽ��˻�
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szBsflag[2 + 1];     // �������
    char          szPrice[21 + 1];     // �۸�
    int           iQty;                // ����
    int           iOrdergroup;         // ί������
    char          szBankcode[4 + 1];   // �ⲿ����
    char          szRemark[64 + 1];    // ��ע��Ϣ
    char          szTargetseat[6 + 1]; // �Է�ϯλ
    int           iPromiseno;          // Լ����
    char          chCreditid;          // ���ý���
    char          chCreditflag;        // ���ý�������
    char          chCreditmethod;      // Լ��ҵ�����
    LONGLONG      llRfscontractno;     // Լ����Լ���
    LONGLONG      llPositionid;        // ͷ����
    char          szLinkman[12 + 1];   // ��ϵ��
    char          szLinkway[30 + 1];   // ��ϵ��ʽ
};
struct MATRADEAPI CRspFislRpcOrderField
{
    int           iOrdersno;         // ί�����
    char          szOrderid[10 + 1]; // ��ͬ���
};
//-------------------------------10103574:ί�г���--------------------------
struct MATRADEAPI CReqFislRpcOrderCancelField
{
    int           iOrderdate;       // ί������
    LONGLONG      llFundid;         // �ʽ��ʻ�
    int           iOrdersno;        // ί�����
};
struct MATRADEAPI CRspFislRpcOrderCancelField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103575:ί�г�����ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcOrderCancelField
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
struct MATRADEAPI CRspFislQryRpcOrderCancelField
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
    char          chCreditid;           // ���ý���
    char          chCreditflag;         // ���ý�������
};
//-------------------------------10103576:���óɱ�--------------------------
struct MATRADEAPI CReqFislRpcResetCostField
{
    char          chMarket;            // �����г�
    char          szSecuid[10 + 1];    // �ɶ�����
    char          szStkcode[8 + 1];    // ֤ȯ����
    LONGLONG      llFundid;            // �ʽ��ʻ�
    char          szCostprice[21 + 1]; // �ɱ��۸�
};
struct MATRADEAPI CRspFislRpcResetCostField
{
    char          szMsgok[32 + 1]; // �ɹ���Ϣ
};
//-------------------------------10103577:ӯ�����ü���--------------------------
struct MATRADEAPI CReqFislRpcCalcFeeField
{
    char          chMarket;         // �����г�
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��ʻ�
    char          szPrice[21 + 1];  // �ɽ��۸�
    int           iQty;             // �ɽ�����
};
struct MATRADEAPI CRspFislRpcCalcFeeField
{
    char          szTradefee[21 + 1]; // �ܷ���
};
//-------------------------------10103676:�ͻ���ѯ����ѯ�ͻ��ɶ�����--------------------------
struct MATRADEAPI CReqFislQryRpcTrdacctField
{
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcTrdacctField
{
    char          szPoststr[32 + 1];  // ��λ��
    LONGLONG      llCustid;           // �ͻ�����
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
    char          szName[16 + 1];     // �ɶ�����
    int           iSecuseq;           // �ɶ����
    char          chSecuidtype;       // �ɶ��ʻ�����
    char          szNrsecuid[10 + 1]; // ��ͨ�ɶ�����
    char          szNrseat[6 + 1];    // ��ͨ�ɶ�ϯλ
};
//-------------------------------10103548:�ʽ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCuacctField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcCuacctField
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
    char          szCreditbal[21 + 1];   // �����ʽ����
    char          szCreditavl[21 + 1];   // �����ʽ����
};
//-------------------------------10103679:�ɷ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcStkDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcStkDetailField
{
    char          szPoststr[32 + 1];    // ��λ��
    LONGLONG      llCustid;             // �ͻ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrgid[4 + 1];       // ��������
    char          chMoneytype;          // ����
    int           iStkbal;              // �ɷ����
    int           iStkavl;              // �ɷݿ���
    int           iCreditstkbal;        // ��������ɷ����
    int           iCreditstkavl;        // ��������ɷݿ���
    int           iStkremain;           // �ͻ���ȯ
    char          szBuycost[21 + 1];    // ��ǰ�ɱ�
    char          szCostprice[21 + 1];  // �ɱ��۸�
    char          szMktval[21 + 1];     // ��ֵ
    char          szIncome[21 + 1];     // ӯ��
    char          chMtkcalflag;         // ��ֵ�����ʶ
    int           iStkqty;              // ��ǰӵ����
    char          szLastprice[21 + 1];  // ���¼۸�
    char          chStktype;            // ֤ȯ����
    char          szProfitcost[21 + 1]; // ����ӯ��
    LONGLONG      llStkdiff;            // ����������
    char          chIspledge;           // �Ƿ�Ϊ����Ʒ
    char          szPledgerate[21 + 1]; // ����Ʒ������
};
//-------------------------------10103680:�ɷݻ��ܲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcStkSummaryField
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    char          szStkcode[8 + 1]; // ֤ȯ����
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspFislQryRpcStkSummaryField
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
//-------------------------------10103681:�ʽ��ʻ���ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCuacct2Field
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcCuacct2Field
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    LONGLONG      llFundid;           // �ʽ��˻�
    char          szOrgid[4 + 1];     // ��������
    char          chMoneytype;        // ����
    char          szFundavl[21 + 1];  // �ʽ����
    char          szFundbal[21 + 1];  // �ʽ����
};
//-------------------------------10103682:�ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�����--------------------------
struct MATRADEAPI CReqFislQryRpcTrdacct2Field
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspFislQryRpcTrdacct2Field
{
    LONGLONG      llCustid;         // �ͻ�����
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
};
//-------------------------------10103683:�ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�����--------------------------
struct MATRADEAPI CReqFislQryRpcTrdacct3Field
{
    char          chMarket;         // �����г�
    char          szSecuid[10 + 1]; // �ɶ�����
    LONGLONG      llFundid;         // �ʽ��ʻ�
};
struct MATRADEAPI CRspFislQryRpcTrdacct3Field
{
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    char          szOrgid[4 + 1];     // ��������
    char          szBankcode[4 + 1];  // ���д���
    LONGLONG      llFundid;           // �ʽ��ʻ�
    char          chMarket;           // �����г�
    char          szSecuid[10 + 1];   // �ɶ�����
};
//-------------------------------10103684:����ί����ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcOrderDetailField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    int           iOrdersno;         // ί�����
    char          szBankcode[4 + 1]; // �ⲿ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
    char          chCreditmethod;    // Լ��ҵ�����
};
struct MATRADEAPI CRspFislQryRpcOrderDetailField
{
    char          szPoststr[32 + 1];     // ��λ��
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
    char          chCreditid;            // ���ý���
    char          chCreditflag;          // ���ʿ���ƽ��ǿƽ
    char          chCreditmethod;        // Լ��ҵ�����
};
//-------------------------------10103686:���ճɽ���ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcMatchDetailField
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
};
struct MATRADEAPI CRspFislQryRpcMatchDetailField
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
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          chMatchtype;          // �ɽ�����
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
};
//-------------------------------10103689:��ʷί�л��ܣ���֤ȯ�������������--------------------------
struct MATRADEAPI CReqFislRpcHisOrderSummaryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspFislRpcHisOrderSummaryField
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
//-------------------------------10103690:��ʷ�ɽ����ܣ���֤ȯ�������������--------------------------
struct MATRADEAPI CReqFislRpcHisMatchSummaryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          chMarket;          // �����г�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspFislRpcHisMatchSummaryField
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
};
//-------------------------------10103549:��ǩ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcLotteryField
{
    int           iStrdate;          // ��ʼ����
    int           iEnddate;          // ��ֹ����
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szSecuid[32 + 1];  // �ɶ�����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcLotteryField
{
    char          szPoststr[32 + 1];    // ��λ��
    int           iBizdate;             // ��ǩ����
    char          chMarket;             // �����г�
    char          szSecuid[32 + 1];     // �ɶ�����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szStkcode[16 + 1];    // ֤ȯ����
    char          szMatchprice[21 + 1]; // �ɽ��۸�
    int           iMatchqty;            // �ɽ�����
};
//-------------------------------10103692:����ί�л���ordergroup+stkcode+bsflag--------------------------
struct MATRADEAPI CReqFislRpcOrderSummaryField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szBankcode[4 + 1]; // �ⲿ����
};
struct MATRADEAPI CRspFislRpcOrderSummaryField
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
//-------------------------------10103550:����ί�в�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcBatchOrderField
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
};
struct MATRADEAPI CRspFislQryRpcBatchOrderField
{
    char          szPoststr[64 + 1];    // ��λ��
    char          szOrgid[4 + 1];       // ��������
    int           iOrdergroup;          // ί������
    int           iOrderdate;           // ί������
    int           iOrdersno;            // ί�����
    char          szOrderid[10 + 1];    // ��ͬ���
    LONGLONG      llFundid;             // �ʽ��ʻ�
    char          chMarket;             // �г�����
    char          szSeat[10 + 1];       // ϯλ
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[6 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szBankcode[4 + 1];    // ���д���
    char          chMoneytype;          // ���Ҵ���
    char          chOperway;            // ������ʽ
    char          szBsflag[2 + 1];      // ������ʶ
    int           iOrderqty;            // ί������
    char          szOrderprice[21 + 1]; // ί�м۸�
    char          chOrderstatus;        // ί��״̬
    int           iMatchqty;            // �ɽ�����
    char          szMatchamt[21 + 1];   // �ɽ����
    char          szMatchprice[21 + 1]; // �ɽ����
    int           iOperdate;            // ��������
    int           iOpertime;            // ����ʱ��
    int           iReporttime;          // �걨ʱ��
    int           iOrdernum;            // ί�б���
};
//-------------------------------10103551:�����ʽ��ȡ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCreditCuacctCanDrawField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcCreditCuacctCanDrawField
{
    LONGLONG      llCustid;          // �ͻ�����
    LONGLONG      llFundid;          // �ʽ��˻�
    char          szOrgid[4 + 1];    // ��������
    char          chMoneytype;       // ����
    char          szMaxdraw[21 + 1]; // ��ȡ���
};
//-------------------------------10103552:��Ʊ��ѯ����--------------------------
struct MATRADEAPI CReqFislQryRpcMktField
{
    char          chExchangeType;     // �����г�
    char          szStockCode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcMktField
{
    char          szStockName[64 + 1];       // ֤ȯ����
    char          szStockCode[6 + 1];        // ֤ȯ����
    char          chExchangeIndex;           // ָ��
    char          szLastPrice[21 + 1];       // ���¼�
    int           iMatchAmount;              // �ɽ�����
    char          szOpenPrice[21 + 1];       // ���̼�
    char          szClosePrice[21 + 1];      // ǰ���̼�
    char          szHighPrice[21 + 1];       // ��߼�
    char          szLowPrice[21 + 1];        // ��ͼ�
    char          szBusinessBalance[21 + 1]; // ��ɽ����
    int           iBusinessAmount;           // �ɽ�����
    char          szBuyPrice1[21 + 1];       // �����һ
    char          szBuyPrice2[21 + 1];       // ����۶�
    char          szBuyPrice3[21 + 1];       // �������
    char          szBuyPrice4[21 + 1];       // �������
    char          szBuyPrice5[21 + 1];       // �������
    char          szSalePrice1[21 + 1];      // ������һ
    char          szSalePrice2[21 + 1];      // �����۶�
    char          szSalePrice3[21 + 1];      // ��������
    char          szSalePrice4[21 + 1];      // ��������
    char          szSalePrice5[21 + 1];      // ��������
    int           iBuyAmount1;               // ������һ
    int           iBuyAmount2;               // ��������
    int           iBuyAmount3;               // ��������
    int           iBuyAmount4;               // ��������
    int           iBuyAmount5;               // ��������
    int           iSaleAmount1;              // ������һ
};
//-------------------------------10103695:���������ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcMktIntentionField
{
    char          chMarket;          // �г�
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szBsflag[128 + 1]; // ҵ�����
    int           iPromiseno;        // Լ����
    int           iQryrec;           // ��ѯ��¼��
    int           iPosstr;           // ��λ��
};
struct MATRADEAPI CRspFislQryRpcMktIntentionField
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
//-------------------------------10103696:��ѯӪҵ��ĳһҵ�������걨ϯλ--------------------------
struct MATRADEAPI CReqFislQryRpcSeatField
{
    char          chMarket;         // ����������
    char          szOrgid[4 + 1];   // Ӫ ҵ ��
    char          szBsflag[2 + 1];  // ҵ�����
    char          szSecuid[10 + 1]; // �ɶ�����
};
struct MATRADEAPI CRspFislQryRpcSeatField
{
    char          szSeat[6 + 1]; // �걨ϯλ
};
//-------------------------------10103697:��ѯ�ʽ��˻���Ϣ--------------------------
struct MATRADEAPI CReqFislQryRpcCuacctAcctInfoField
{
    LONGLONG      llFundid;         // �ʽ��˻�
};
struct MATRADEAPI CRspFislQryRpcCuacctAcctInfoField
{
    char          szFundname[16 + 1];        // �ʽ�����
    char          chIdtype;                  // ֤������
    char          szIdno[32 + 1];            // ֤������
    char          szOperway[128 + 1];        // ������ʽ
    char          szFundagentright[128 + 1]; // �ʽ����Ȩ��
    char          szFundright[128 + 1];      // �ʽ�Ȩ��
    char          chStatus;                  // �ʽ�״̬
};
//-------------------------------10103553:�ͻ����������Ѳ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCustSpecialFeeField
{
    LONGLONG      llFundid;             // �ʲ��˻�
    char          szMarket[32 + 1];     // �г�����
    char          szStktype[128 + 1];   // ֤ȯ���
    char          szTrdid[128 + 1];     // ��������
    char          szMoneytype[128 + 1]; // ��������
    char          szBsflag[128 + 1];    // �������
};
struct MATRADEAPI CRspFislQryRpcCustSpecialFeeField
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
//-------------------------------10103554:��Ϣ����˰������ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcDividendBonusTaxDetailField
{
    char          chMarket;          // �����г�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          szStatus[128 + 1]; // ��˰״̬
    int           iBegindate;        // ��ʼ����
    int           iEnddate;          // ��������
};
struct MATRADEAPI CRspFislQryRpcDividendBonusTaxDetailField
{
    int           iServerid;            // ��������
    char          chMarket;             // �����г�
    char          szOrgid[4 + 1];       // ��������
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ɶ�����
    int           iSenddate;            // ��������
    int           iNoticedate;          // ֪ͨ����
    char          szSno[10 + 1];        // ��˰���
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    int           iTaxdate;             // ��˰����
    int           iRegistdate;          // Ȩ��Ǽ�����
    int           iReducedate;          // ���ֽ�������
    char          chStatus;             // ��˰״̬
    char          szBusitype[2 + 1];    // ҵ�����
    char          chMoneytype;          // ���Ҵ���
    char          szTaxamt[21 + 1];     // Ӧ��˰��
    char          szPaidtaxamt[21 + 1]; // �ѿ�˰��
    LONGLONG      llTaxcount;           // �����ֹ���
    char          szBfjaccount[10 + 1]; // �������˺�
    char          szSeat[6 + 1];        // ϯλ����
    char          szClearseat[5 + 1];   // ����ϯλ
    char          szClearsno[8 + 1];    // ������
    int           iHolddate;            // ��ʼ��������
    char          szPrice[21 + 1];      // �۸�
    char          szTaxrate[21 + 1];    // ��˰˰��
    char          szAssistcode[10 + 1]; // ��������
    char          szResultcode[4 + 1];  // �������
    char          szRemarks[64 + 1];    // ��ע
};
//-------------------------------10103555:�趨����ת��ת���ƻ�--------------------------
struct MATRADEAPI CReqFislRpcSetPeriodicalTransferPlanField
{
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          szBankcode[4 + 1];    // ���д���
    char          chMoneytype;          // ���Ҵ���
    char          szFundeffect[21 + 1]; // ת�˽��
    char          chPlantype;           // ��������
    int           iActiondate;          // ִ����
    char          szWflag[8 + 1];       // ͨ�ñ�־
    char          szRemark[64 + 1];     // ��ע
};
struct MATRADEAPI CRspFislRpcSetPeriodicalTransferPlanField
{
    int           iSno; // ������ˮ��
};
//-------------------------------10103556:��ѯ����ת��ת���ƻ�--------------------------
struct MATRADEAPI CReqFislQryRpcPeriodicalTransferPlanField
{
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          szBankcode[4 + 1];    // ���д���
    char          chMoneytype;          // ���Ҵ���
    char          szFundeffect[21 + 1]; // ת�˽��
    int           iCount;               // ��ѯ����
    char          szPoststr[32 + 1];    // ��λ��
};
struct MATRADEAPI CRspFislQryRpcPeriodicalTransferPlanField
{
    char          szPoststr[12 + 1];    // ���
    int           iSno;                 // �ƻ����
    char          szBankcode[4 + 1];    // ���д���
    char          szBankname[32 + 1];   // ��������
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          szFundeffect[21 + 1]; // ��ת�ʽ�
    char          chPlantype;           // �ƻ�����
    int           iActiondate;          // ִ����
    char          szRemark[32 + 1];     // ��ע
    char          chActionret;          // ִ����ִ�н��
    char          szOperdate[8 + 1];    // ������
    int           iLinksno;             // ���ת����ˮ��
    char          szWflag[8 + 1];       // ͨ�ñ�־
};
//-------------------------------10103557:ɾ������ת��ת���ƻ�--------------------------
struct MATRADEAPI CReqFislRpcDelPeriodicalTransferPlanField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    int           iSno;             // �ƻ����
};
struct MATRADEAPI CRspFislRpcDelPeriodicalTransferPlanField
{
    int           iSno; // ������ˮ��
};
//-------------------------------10103558:����֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcGuaranteedStkField
{
    char          chMarket;          // �����г�
    char          chQryflag;         // ��ѯ����
    char          szPoststr[32 + 1]; // ��λ��
    int           iCount;            // ��������
};
struct MATRADEAPI CRspFislQryRpcGuaranteedStkField
{
    char          szPoststr[32 + 1];    // ��λ��
    char          chMarket;             // �����г�
    char          szStkcode[6 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szPledgerate[21 + 1]; // ������
};
//-------------------------------10103559:���֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcUnderlyingStkField
{
    char          chMarket;          // �����г�
    char          chQryflag;         // ��ѯ����
    char          szPoststr[32 + 1]; // ��λ��
    int           iCount;            // ��������
};
struct MATRADEAPI CRspFislQryRpcUnderlyingStkField
{
    char          szPoststr[32 + 1];        // ��λ��
    char          chMarket;                 // �����г�
    char          szStkcode[6 + 1];         // ֤ȯ����
    char          szStkname[64 + 1];        // ֤ȯ����
    char          chCreditfundctrl;         // ��������
    char          chCreditstkctrl;          // ��ȯ����
    char          szMarginratefund[21 + 1]; // ���ʱ�֤�����
    char          szMarginratestk[21 + 1];  // ��ȯ��֤�����
};
//-------------------------------10103560:�����������ݲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcFinancingCreditDataField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMoneytype;      // ����
    char          chMarket;         // �����г�
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcFinancingCreditDataField
{
    char          szMaxfamt[21 + 1];           // ������ʽ��
    char          szMarginavl[21 + 1];         // ���ñ�֤�����
    char          szFcreditbal[21 + 1];        // �������Ŷ��
    char          szFcreditavl[21 + 1];        // ���ʿ��õĶ��
    char          szFmarginrate[21 + 1];       // ���ʱ�֤�����
    char          szFunmatchamt[21 + 1];       // ����δ�ɽ����
    char          szFundavl[21 + 1];           // �ʽ������
    char          szFundavlfrz[21 + 1];        // �ʽ������������
    char          szFmarketval[21 + 1];        // ����֤ȯ����ֵ
    char          szGdismarketval[21 + 1];     // ����֤ȯ�������ֵ
    char          szFdebtbal[21 + 1];          // �����ܽ��
    char          szTotaldisfdebtbal[21 + 1];  // �� ���ʽ�� * ������
    char          szTotalratefdebtbal[21 + 1]; // �� ���ʽ�� * ���ʱ�֤�����
    char          szTotalffee[21 + 1];         // ���ʵ���Ϣ�ͷ��õ��ܺ�
    char          szTotaldisfmkval[21 + 1];    // �� ���ʵ���ֵ * ������
    char          chMarket;                    // �����г�
    char          szStkcode[6 + 1];            // ֤ȯ����
    char          szStkname[64 + 1];           // ֤ȯ����
};
//-------------------------------10103561:��ȯ�������ݲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcMarginCreditDataField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMoneytype;      // ����
    char          chMarket;         // �����г�
    char          szStkcode[6 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcMarginCreditDataField
{
    char          szMaxdamt[21 + 1];           // �����ȯ���
    char          szMarginavl[21 + 1];         // ���ñ�֤�����
    char          szDcreditbal[21 + 1];        // ��ȯ���Ŷ��
    char          szDcreditavl[21 + 1];        // ��ȯ���õĶ��
    char          chMarket;                    // �����г�
    char          szStkcode[6 + 1];            // ֤ȯ����
    char          szStkname[64 + 1];           // ֤ȯ����
    char          szDmarginrate[21 + 1];       // ��ȯ��֤�����
    char          szDunmatchamt[21 + 1];       // ��ȯδ�ɽ����
    char          szFundavl[21 + 1];           // �ʽ������
    char          szFundavlfrz[21 + 1];        // �ʽ������������
    char          szDsaleavl[21 + 1];          // ��ȯ������������
    char          szDsaleavlfrz[21 + 1];       // ��ȯ�������������Ķ�����
    char          szGmarketval[21 + 1];        // ����֤ȯ����ֵ
    char          szGdismarketval[21 + 1];     // ����֤ȯ�������ֵ
    char          szDsalebal[21 + 1];          // ��ȯ�����ʽ�
    char          szTotaldisdsalebal[21 + 1];  // �� ��ȯ�����ʽ� * ������
    char          szTotalratedsalebal[21 + 1]; // �� ��ȯ�����ʽ� * ��ȯ��֤�����
    char          szTotaldfee[21 + 1];         // ��ȯ����Ϣ�ͷ��õ��ܺ�
    char          szTotaldmkval[21 + 1];       // ��ȯ����ֵ
    char          szTotaldisdmkval[21 + 1];    // �� ��ȯ����ֵ * ������
    char          szTotalratdmkval[21 + 1];    // �� ��ȯ����ֵ * ��ȯ��֤�����
};
//-------------------------------10103562:���ÿͻ��ʲ���ծ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCreditCustBalanceField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcCreditCustBalanceField
{
    char          chMoneytype;              // ����
    LONGLONG      llFundid;                 // �ʽ��ʺ�
    char          szFundintrrate[21 + 1];   // ��������
    char          szStkintrrate[21 + 1];    // ��ȯ����
    char          szPunishintrrate[21 + 1]; // ��Ϣ����
    char          chCreditstatus;           // ����״̬
    char          szMarginrates[21 + 1];    // ά�ֵ�������
    char          szRealrate[21 + 1];       // ʵʱ��������
    char          szAsset[21 + 1];          // ���ʲ�
    char          szLiability[21 + 1];      // �ܸ�ծ
    char          szMarginavl[21 + 1];      // ��֤�������
    char          szFundbal[21 + 1];        // �ʽ����
    char          szFundavl[21 + 1];        // �ʽ������
    char          szDsaleamtbal[21 + 1];    // ��ȯ���������ʽ�
    char          szGuaranteeout[21 + 1];   // ��ת�������ʲ�
    char          szGagemktavl[21 + 1];     // ����֤ȯ��ֵ
    char          szFdealavl[21 + 1];       // ���ʱ���
    char          szFfee[21 + 1];           // ����Ϣ��
    char          szFtotaldebts[21 + 1];    // ���ʸ�ծ�ϼ�
    char          szDealfmktavl[21 + 1];    // Ӧ����ȯ��ֵ
    char          szDfee[21 + 1];           // ��ȯϢ��
    char          szDtotaldebts[21 + 1];    // ��ȯ��ծ�ϼ�
    char          szFcreditbal[21 + 1];     // �������Ŷ��
    char          szFcreditavl[21 + 1];     // ���ʿ��ö��
    char          szFcreditfrz[21 + 1];     // ���ʶ�ȶ���
    char          szDcreditbal[21 + 1];     // ��ȯ���Ŷ��
    char          szDcreditavl[21 + 1];     // ��ȯ���ö��
    char          szDcreditfrz[21 + 1];     // ��ȯ��ȶ���
    char          szRights[21 + 1];         // ����Ȩ��
    char          szUncomerqrights[21 + 1]; // ����Ȩ��(��;)
    int           iRightsqty;               // ���Ȩ��
    int           iUncomerqrightsqty;       // ���Ȩ��(��;)
    char          szAcreditbal[21 + 1];     // �ܶ��
    char          szAcreditavl[21 + 1];     // �ܿ��ö��
};
//-------------------------------10103563:������ȯ��Լ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcContractField
{
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          chMoneytype;            // ��    ��
    char          szCreditdirect[16 + 1]; // ������ȯ����
    char          szLifestatus[16 + 1];   // ״̬
    char          szMarket[16 + 1];       // �����г�
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          szBegindate[8 + 1];     // ��ʼ����
    char          szEnddate[8 + 1];       // ��������
    char          szPosstr[32 + 1];       // ��λ��
    int           iCount;                 // ��������
    LONGLONG      llRfscontractno;        // Լ����Լ���
    LONGLONG      llPositionid;           // ͷ����
};
struct MATRADEAPI CRspFislQryRpcContractField
{
    char          szOrgid[4 + 1];             // Ӫҵ��
    LONGLONG      llFundid;                   // �ʽ��ʺ�
    char          chMoneytype;                // ��    ��
    char          chMarket;                   // �����г�
    char          szStkcode[6 + 1];           // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    int           iOrderdate;                 // ί������
    char          szOrdersno[10 + 1];         // ί �� ��
    char          chCreditdirect;             // ������ȯ����
    int           iOrderqty;                  // ί������
    int           iMatchqty;                  // �ɽ�����
    char          szOrderamt[21 + 1];         // ί�н��
    char          szOrderfrzamt[21 + 1];      // ί�ж�����
    char          szMatchamt[21 + 1];         // �ɽ����
    char          szClearamt[21 + 1];         // ������
    char          chLifestatus;               // ��Լ״̬
    int           iEnddate;                   // ��ծ��ֹ����
    int           iOldenddate;                // ԭʼ�ĸ�ծ��ֹ����
    char          szCreditrepay[21 + 1];      // T��֮ǰ�黹���
    char          szCreditrepayunfrz[21 + 1]; // T�չ黹���
    char          szFundremain[21 + 1];       // Ӧ�����
    int           iStkrepay;                  // T��֮ǰ�黹����
    int           iStkrepayunfrz;             // T�չ黹����
    int           iStkremain;                 // Ӧ��֤ȯ����
    char          szStkremainvalue[21 + 1];   // Ӧ��֤ȯ��ֵ
    char          szFee[21 + 1];              // ������ȯϢ����
    char          szOverduefee[21 + 1];       // ����δ����Ϣ����
    char          szFeeRepay[21 + 1];         // ������Ϣ����
    char          szPunifee[21 + 1];          // ��Ϣ�����ķ�Ϣ
    char          szPunifeeRepay[21 + 1];     // ��������Ϣ
    char          szRights[21 + 1];           // δ����Ȩ����
    char          szOverduerights[21 + 1];    // ����δ����Ȩ��
    char          szRightsRepay[21 + 1];      // ������Ȩ��
    char          szLastprice[21 + 1];        // ���¼�
    char          szProfitcost[21 + 1];       // ����ӯ��
    char          szPoststr[32 + 1];          // ��λ��
    int           iSysdate;                   // ϵͳ����
    int           iSno;                       // ��Լ���
    int           iLastdate;                  // ���һ�μ���Ϣ������
    int           iClosedate;                 // ��Լȫ����������
    char          szPunidebts[21 + 1];        // ���ڱ���Ϣ
    char          szPunidebtsRepay[21 + 1];   // ����Ϣ����
    char          szPunidebtsunfrz[21 + 1];   // ���ڱ���Ϣ
    char          szPunifeeunfrz[21 + 1];     // ����Ϣ�ѷ�Ϣ
    char          szPunirights[21 + 1];       // ����Ȩ�淣Ϣ
    char          szPunirightsRepay[21 + 1];  // Ȩ�淣Ϣ����
    char          szPunirightsunfrz[21 + 1];  // ����Ȩ�淣Ϣ
    char          szFeeunfrz[21 + 1];         // ʵʱ������Ϣ
    char          szOverduefeeunfrz[21 + 1];  // ʵʱ����������Ϣ
    int           iRightsqty;                 // δ����Ȩ������
    int           iOverduerightsqty;          // ����δ����Ȩ������
    char          szSecuid[10 + 1];           // ֤ȯ�˺�
    char          chDebtsflag;                // ��Լ���ɷ�ʽ
    LONGLONG      llPositionid;               // ͷ����
    int           iDefertimes;                // չ�ڴ���
};
//-------------------------------10103564:��ͬ��Ϣ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcAgreementInfoField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    char          chMoneytype;      // ����
};
struct MATRADEAPI CRspFislQryRpcAgreementInfoField
{
    LONGLONG      llFundid;                 // �ʽ��ʺ�
    char          chMoneytype;              // ����
    int           iContractno;              // ��ͬ���
    int           iContractsno;             // ��ͬ˳���
    int           iContractlimit;           // ��ͬ����
    char          chAutodefer;              // ��ͬ�Զ����ڱ�־
    int           iBegindate;               // ��ͬ��ʼ����
    int           iEnddate;                 // ��ͬ��������
    char          chContractstatus;         // ��ͬ״̬
    char          szCreditbal[21 + 1];      // ���ö��
    char          szFcreditbal[21 + 1];     // ���ʶ��
    char          szFcreditrate[21 + 1];    // ����������
    char          szFyearmgfee[21 + 1];     // ���ʹ������
    char          szFyearsrfee[21 + 1];     // ���ʳ�ŵ����
    char          szFprate[21 + 1];         // �����귣Ϣ����
    char          szDcreditbal[21 + 1];     // ��ȯ���
    char          szDcreditrate[21 + 1];    // ��ȯ������
    char          szDyearmgfee[21 + 1];     // ��ȯ�������
    char          szDyearsrfee[21 + 1];     // ��ȯ��ŵ����
    char          szDprate[21 + 1];         // ��ȯ�귣Ϣ����
    char          szBaseloanrate[21 + 1];   // ���л�׼��������
    char          szBasepunishrate[21 + 1]; // ���л�׼��Ϣ��
    char          szFundintrrate[21 + 1];   // ��������(�������л�׼��)
    char          szStkintrrate[21 + 1];    // ��ȯ����(�������л�׼��)
};
//-------------------------------10103565:��ΧԼ��ֱ�ӻ��ֱ�ӻ���--------------------------
struct MATRADEAPI CReqFislRpcDirectRepaymentField
{
    LONGLONG      llFundid;             // �����ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          szFundeffect[21 + 1]; // ������
    char          szRemark[32 + 1];     // ��ע��Ϣ
    char          chCreditmethod;       // Լ��ҵ�����
    LONGLONG      llRfscontractno;      // Լ����Լ���
    int           iDebtdate;            // ��ծ��Լ����
    int           iDebtsno;             // ��ծ��Լ���
    char          szDebttype[128 + 1];  // ��ծ����
};
struct MATRADEAPI CRspFislRpcDirectRepaymentField
{
    char          szFundeffect[21 + 1]; // ʵ�ʻ�����
};
//-------------------------------10103566:��ѯȯ����ȯ�ʻ�ͷ��--------------------------
struct MATRADEAPI CReqFislQryRpcMarginAcctPosiField
{
    char          chMarket;            // �����г�
    char          szStkcode[8 + 1];    // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcMarginAcctPosiField
{
    char          chMarket;            // ��    ��
    char          szStkcode[8 + 1];    // ֤ȯ����
    char          szStkname[64 + 1];   // ֤ȯ����
    LONGLONG      llStkbal;            // ֤ȯ���
    LONGLONG      llStkavl;            // ֤ȯ����
};
//-------------------------------10103567:���ÿͻ���ת�뵣��֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCreditCustCanTransferInGuaranteedStkField
{
    char          chMarket;          // �����г�
    LONGLONG      llFundid;          // �ʽ��ʻ�
    char          szSecuid[10 + 1];  // �ɶ�����
    char          szStkcode[8 + 1];  // ֤ȯ����
    char          chQryflag;         // ��ѯ����
    int           iCount;            // ��������
    char          szPoststr[32 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcCreditCustCanTransferInGuaranteedStkField
{
    char          szPoststr[32 + 1];    // ��λ��
    LONGLONG      llCustid;             // �ͻ�����
    LONGLONG      llFundid;             // �ʽ��˻�
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrgid[4 + 1];       // ��������
    char          chMoneytype;          // ����
    int           iStkbal;              // �ɷ����
    int           iStkavl;              // �ɷݿ���
    int           iStkremain;           // �ͻ���ȯ
    char          szBuycost[21 + 1];    // ��ǰ�ɱ�
    char          szCostprice[21 + 1];  // �ɱ��۸�
    char          szMktval[21 + 1];     // ��ֵ
    char          szIncome[21 + 1];     // ӯ��
    char          chMtkcalflag;         // ��ֵ�����ʶ
    int           iStkqty;              // ��ǰӵ����
    char          szLastprice[21 + 1];  // ���¼۸�
    char          chStktype;            // ֤ȯ����
    char          chIspledge;           // �Ƿ񵣱�Ʒ
    char          szPledgerate[21 + 1]; // ����Ʒ������
};
//-------------------------------10103568:ͶƱ������ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcVotingSchemeField
{
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szProjectid[21 + 1];  // ������
    char          szMeetingseq[12 + 1]; // ������
};
struct MATRADEAPI CRspFislQryRpcVotingSchemeField
{
    char          chMarket;                // �����г�
    char          szStkcode[8 + 1];        // ֤ȯ����
    char          szStkname[64 + 1];       // ֤ȯ����
    char          szProjectid[21 + 1];     // ��������
    char          szProjectname[128 + 1];  // ��������
    int           iBegindate;              // ͶƱ��ʼ����
    int           iEnddate;                // ͶƱ��������
    int           iRegdate;                // ��Ȩ�Ǽ���
    char          chProjectkind;           // ��������
    char          szRemark[64 + 1];        // ��ע��Ϣ
    char          szMeetingseq[12 + 1];    // ������
    char          szMeetingdesc[1024 + 1]; // �������
};
//-------------------------------10103569:ͶƱ�µ�--------------------------
struct MATRADEAPI CReqFislRpcVotingOrderField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // ֤ȯ�ʺ�
    char          szOrgid[4 + 1];       // Ӫҵ������
    LONGLONG      llFundid;             // �ʽ��˻�
    LONGLONG      llAgentid;            // �����˴���
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iOrderqty;            // ί������
    char          chHaverelation;       // ���ڹ�ϵ
    char          chProjectkind;        // ��������
    char          szMeetingseq[12 + 1]; // ������
};
struct MATRADEAPI CRspFislRpcVotingOrderField
{
};
//-------------------------------10103570:ͶƱ�����ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcVotingResultField
{
    char          szOrgid[4 + 1];       // Ӫҵ������
    LONGLONG      llFundid;             // �ʽ��˺�
    char          chMarket;             // �г�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szOrderprice[21 + 1]; // ͶƱ�鰸
    char          szMeetingseq[12 + 1]; // ������
};
struct MATRADEAPI CRspFislQryRpcVotingResultField
{
    int           iSysdate;             // ��������
    int           iOperdate;            // ��������
    int           iOpertime;            // ����ʱ��
    LONGLONG      llCustid;             // �ͻ�����
    char          szCustname[16 + 1];   // �ͻ�����
    char          szOrgid[4 + 1];       // ��֧����
    char          szBrhid[4 + 1];       // ������֧
    LONGLONG      llFundid;             // �ʽ��ʺ�
    char          chMoneytype;          // ���Ҵ���
    char          szSecuid[10 + 1];     // �ɶ�����
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szLinkstk[8 + 1];     // ����֤ȯ����
    char          szLinkname[64 + 1];   // ����֤ȯ����
    char          szOrderprice[21 + 1]; // ί�м۸�
    int           iOrderqty;            // ί������
    LONGLONG      llStkbal;             // �ɷ����
    char          chHaverelation;       // ���ڹ�ϵ
    char          chProjectkind;        // ��������
    char          szMeetingseq[12 + 1]; // ������
};
//-------------------------------10103578:ͶƱ���ͳ��--------------------------
struct MATRADEAPI CReqFislRpcVotingResultStatisticsField
{
    char          chMarket;             // �����г�
    char          szStkcode[8 + 1];     // ͶƱ����
    char          szOrderprice[21 + 1]; // ͶƱ�鰸
    int           iBegindate;           // ��ʼʱ��
    int           iEnddate;             // ����ʱ��
    char          chHaverelation;       // ���ڹ�ϵ
    char          szMeetingseq[12 + 1]; // ������
};
struct MATRADEAPI CRspFislRpcVotingResultStatisticsField
{
    int           iServerid;            // �ڵ���
    char          chMarket;             // �г�����
    char          szStkcode[8 + 1];     // ͶƱ����
    char          szOrderprice[21 + 1]; // ͶƱ�鰸
    char          chProjectkind;        // �鰸����
    LONGLONG      llOrderqty;           // ����ע��Ϣ
    LONGLONG      llThisviewstkbal;     // ����ע��Ϣ
    int           iThisviewcustqty;     // ����ע��Ϣ
    int           iVotecustqty;         // ����ͶƱ�ͻ���
    int           iAllcustqty;          // �������ɿͻ���
    LONGLONG      llAllorderqty;        // ����ע��Ϣ
    char          szRate[21 + 1];       // ����ע��Ϣ
    char          szMeetingseq[12 + 1]; // ������
};
//-------------------------------10103579:�ͻ���ͶƱ�鰸��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCanVoteBillField
{
    char          szOrgid[4 + 1];   // Ӫҵ������
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �г�����
    char          szStkcode[8 + 1]; // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcCanVoteBillField
{
    char          chMarket;             // �����г�
    char          szSecuid[10 + 1];     // �ɶ�����
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szVotecode[8 + 1];    // ͶƱ����
    char          szStkname[64 + 1];    // ֤ȯ����
    char          szProjectid[21 + 1];  // ��������
    char          chProjectkind;        // ��������
    LONGLONG      llStkavl;             // �ɷݿ�����
    LONGLONG      llStkbal;             // �ɷ����
    LONGLONG      llHaveorderqty;       // ��ͶƱ����
    char          szMeetingseq[12 + 1]; // ������
};
//-------------------------------10103580:�ͻ���ͶƱָ���鰸�Ĺɷݲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCanVoteBillShareField
{
    char          szOrgid[4 + 1];       // Ӫҵ������
    LONGLONG      llFundid;             // �ʽ��˺�
    char          chMarket;             // �г�����
    char          szSecuid[10 + 1];     // ֤ȯ�˺�
    char          szStkcode[8 + 1];     // ֤ȯ����
    char          szProjectid[21 + 1];  // ͶƱ�鰸
    char          szMeetingseq[12 + 1]; // ������
};
struct MATRADEAPI CRspFislQryRpcCanVoteBillShareField
{
    LONGLONG      llVotablestk; // ��ͶƱ����
};
//-------------------------------10103581:��Ʊ��ʷ�ɷ�����ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcHisShareBalanceField
{
    char          szOrgid[4 + 1];   // Ӫҵ������
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chMarket;         // �г�����
    char          szSecuid[10 + 1]; // ֤ȯ�˺�
    char          szStkcode[8 + 1]; // ֤ȯ����
    char          chDatekind;       // ��ѯ��������
    int           iBizdate;         // ��ѯ����
};
struct MATRADEAPI CRspFislQryRpcHisShareBalanceField
{
    int           iHisstkbal; // ��ʷ�ɷ����
};
//-------------------------------10103582:������ȯ�ʺ���������--------------------------
struct MATRADEAPI CReqFislRpcSelfActivateField
{
    LONGLONG      llFundid;         // �ʽ��˺�
};
struct MATRADEAPI CRspFislRpcSelfActivateField
{
    char          chActiveflag;   // �˻������־
    char          chCreditstatus; // �˻���ǰ״̬
};
//-------------------------------10103583:��ͬ��Ϣ�޸�--------------------------
struct MATRADEAPI CReqFislRpcChgAgreementInfoField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iContractsno;     // ��ͬ˳���
    char          chAutodefer;      // ��ͬ�Զ����ڱ�־
};
struct MATRADEAPI CRspFislRpcChgAgreementInfoField
{
};
//-------------------------------10103584:�ͻ��˻������ò�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcAcctLvlFeeField
{
    LONGLONG      llFundid;         // �ʽ��˺�
};
struct MATRADEAPI CRspFislQryRpcAcctLvlFeeField
{
    LONGLONG      llFundid;                         // �ʽ��˺�
    char          szOrgid[4 + 1];                   // ��������
    char          chMoneytype;                      // ���Ҵ���
    LONGLONG      llCustid;                         // �ͻ�����
    char          szFundprofee[21 + 1];             // ���ʳ�ŵ��
    char          szStkprofee[21 + 1];              // ��ȯ��ŵ��
    char          szFundmanagefee[21 + 1];          // ���ʹ����
    char          szFundmanageoverdue[21 + 1];      // �������ڹ����
    char          szFundmanagepunintr[21 + 1];      // �������ڹ���ѷ�Ϣ
    char          szStkmanagefee[21 + 1];           // ��ȯ�����
    char          szStkmanageoverdue[21 + 1];       // ��ȯ���ڹ����
    char          szStkmanagepunintr[21 + 1];       // ��ȯ���ڹ���ѷ�Ϣ
    char          szFundprofeeunfrz[21 + 1];        // ���ճ������ʳ�ŵ��
    char          szStkprofeeunfrz[21 + 1];         // ���ճ�����ȯ��ŵ��
    char          szFundmanagefeeunfrz[21 + 1];     // ���ճ������ʹ����
    char          szFundmanageoverdueunfrz[21 + 1]; // ���ճ����������ڹ����
    char          szFundmanagepunintrunfrz[21 + 1]; // ���ճ������������ڹ���ѷ�Ϣ
    char          szStkmanagefeeunfrz[21 + 1];      // ���ճ�����ȯ�����
    char          szStkmanageoverdueunfrz[21 + 1];  // ���ճ�����ȯ���ڹ����
    char          szStkmanagepunintrunfrz[21 + 1];  // ���ճ�����ȯ���ڹ���ѷ�Ϣ
    char          szSpacctfee[21 + 1];              // ��ȯ����ר��ռ�÷�
    char          szSpacctfeeunfrz[21 + 1];         // ���ճ�����ȯ����ר��ռ�÷�
    char          szFundposifullfee[21 + 1];        // ����ͷ��ȫ��ռ�÷�
    char          szFundposifullfeeunfrz[21 + 1];   // ����ͷ��ȫ��ռ�÷ѳ���
    char          szFundposiunusefee[21 + 1];       // ����ͷ����з�
    char          szFundposiunusefeeunfrz[21 + 1];  // ����ͷ����зѳ���
    char          szFundposiusefee[21 + 1];         // ����ͷ��ʹ�÷�
    char          szFundposiusefeeunfrz[21 + 1];    // ����ͷ��ʹ�÷ѳ���
    char          szStkposifullfee[21 + 1];         // ��ȯͷ��ȫ��ռ�÷�
    char          szStkposifullfeeunfrz[21 + 1];    // ��ȯͷ��ȫ��ռ�÷ѳ���
    char          szStkposiunusefee[21 + 1];        // ��ȯͷ����з�
    char          szStkposiunusefeeunfrz[21 + 1];   // ��ȯͷ����зѳ���
    char          szStkposiusefee[21 + 1];          // ��ȯͷ��ʹ�÷�
    char          szStkposiusefeeunfrz[21 + 1];     // ��ȯͷ��ʹ�÷ѳ���
    int           iLastdate;                        // ����Ϣ����
};
//-------------------------------10103585:������ȯ�Զ����Լ����˳���ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCustomContractRepayOrderField
{
    LONGLONG      llFundid;                // �ʽ��˺�
    char          szOrgid[4 + 1];          // Ӫҵ������
    LONGLONG      llCustid;                // �ͻ�����
    char          chMarket;                // �г�
    char          szStkcode[8 + 1];        // ֤ȯ����
    char          szCreditdirect[128 + 1]; // ��Լ����
    char          szLifestatus[128 + 1];   // ��Լ״̬
    int           iSysdate;                // ��ծ����
    int           iSno;                    // ��ծ��Լ���
    int           iCount;                  // ��ѯ����
    char          szPoststr[128 + 1];      // ��λ��
};
struct MATRADEAPI CRspFislQryRpcCustomContractRepayOrderField
{
    int           iPrior;                     // �������ȼ�
    int           iOperdate;                  // ���ȼ���������
    char          szOrgid[4 + 1];             // Ӫҵ��
    LONGLONG      llFundid;                   // �ʽ��ʺ�
    char          chMoneytype;                // ��    ��
    char          chMarket;                   // �����г�
    char          szStkcode[6 + 1];           // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    int           iOrderdate;                 // ί������
    char          szOrdersno[10 + 1];         // ί �� ��
    char          chCreditdirect;             // ������ȯ����
    int           iOrderqty;                  // ί������
    int           iMatchqty;                  // �ɽ�����
    char          szOrderamt[21 + 1];         // ί�н��
    char          szOrderfrzamt[21 + 1];      // ί�ж�����
    char          szMatchamt[21 + 1];         // �ɽ����
    char          szClearamt[21 + 1];         // ������
    char          chLifestatus;               // ��Լ״̬
    int           iEnddate;                   // ��ծ��ֹ����
    int           iOldenddate;                // ԭʼ�ĸ�ծ��ֹ����
    char          szCreditrepay[21 + 1];      // T��֮ǰ�黹���
    char          szCreditrepayunfrz[21 + 1]; // T�չ黹���
    int           iStkrepay;                  // T��֮ǰ�黹����
    int           iStkrepayunfrz;             // T�չ黹����
};
//-------------------------------10103586:������ȯ�Զ����Լ����˳������--------------------------
struct MATRADEAPI CReqFislRpcSetCustomContractRepayOrderField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          szOrgid[4 + 1];   // Ӫҵ������
    LONGLONG      llCustid;         // �ͻ�����
    int           iSysdate;         // ��ծ����
    int           iSno;             // ��ծ��Լ���
    int           iPrior;           // �������ȼ�
};
struct MATRADEAPI CRspFislRpcSetCustomContractRepayOrderField
{
    LONGLONG      llFundid;       // �ʽ��˺�
    char          szOrgid[4 + 1]; // Ӫҵ������
    LONGLONG      llCustid;       // �ͻ�����
    int           iDebtdate;      // ��ծ����
    int           iDebtsno;       // ��ծ��Լ���
    int           iPrior;         // �������ȼ�
    int           iOperdate;      // ��������
};
//-------------------------------10103587:��ȯ����ר��֤ȯ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcSpecialMarginAcctStkField
{
    char          chMarket;          // �г�����
    char          szStkcode[6 + 1];  // ֤ȯ����
};
struct MATRADEAPI CRspFislQryRpcSpecialMarginAcctStkField
{
    LONGLONG      llCustid;          // �ͻ�����
    LONGLONG      llSpcustid;        // ר���ͻ�����
    char          szOrgid[4 + 1];    // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    char          chMarket;          // �г�����
    char          szStkcode[6 + 1];  // ֤ȯ����
    char          szStkname[64 + 1]; // ֤ȯ����
    LONGLONG      llStkbal;          // �ɷ����
    LONGLONG      llStklastbal;      // �ɷ��ϴ����
    LONGLONG      llStkavl;          // �ɷݿ���
};
//-------------------------------10103588:������ȯ��ʷ���˽��Լ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcHisClosedContractField
{
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          chMoneytype;            // ��    ��
    char          szCreditdirect[16 + 1]; // ������ȯ����
    char          szMarket[16 + 1];       // �����г�
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          szBegindate[8 + 1];     // ��ʼ����
    char          szEnddate[8 + 1];       // ��������
    char          szPoststr[32 + 1];      // ��λ��
    int           iCount;                 // ��������
};
struct MATRADEAPI CRspFislQryRpcHisClosedContractField
{
    char          szOrgid[4 + 1];             // Ӫҵ��
    LONGLONG      llFundid;                   // �ʽ��ʺ�
    char          chMoneytype;                // ��    ��
    char          chMarket;                   // �����г�
    char          szStkcode[6 + 1];           // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    int           iOrderdate;                 // ί������
    char          szOrdersno[10 + 1];         // ί �� ��
    char          chCreditdirect;             // ������ȯ����
    int           iOrderqty;                  // ί������
    int           iMatchqty;                  // �ɽ�����
    char          szOrderamt[21 + 1];         // ί�н��
    char          szOrderfrzamt[21 + 1];      // ί�ж�����
    char          szMatchamt[21 + 1];         // �ɽ����
    char          szClearamt[21 + 1];         // ������
    char          chLifestatus;               // ��Լ״̬
    int           iEnddate;                   // ��ծ��ֹ����
    int           iOldenddate;                // ԭʼ�ĸ�ծ��ֹ����
    char          szCreditrepay[21 + 1];      // T��֮ǰ�黹���
    char          szCreditrepayunfrz[21 + 1]; // T�չ黹���
    int           iStkrepay;                  // T��֮ǰ�黹����
    int           iStkrepayunfrz;             // T�չ黹����
    char          szFee[21 + 1];              // ������ȯϢ����
    char          szOverduefee[21 + 1];       // ����δ����Ϣ����
    char          szFeeRepay[21 + 1];         // ������Ϣ����
    char          szPunifee[21 + 1];          // ��Ϣ�����ķ�Ϣ
    char          szRights[21 + 1];           // δ����Ȩ����
    char          szOverduerights[21 + 1];    // ����δ����Ȩ��
    char          szRightsRepay[21 + 1];      // ������Ȩ��
    char          szLastprice[21 + 1];        // ���¼�
    char          szPoststr[32 + 1];          // ��λ��
    int           iSysdate;                   // ϵͳ����
    int           iSno;                       // ��Լ���
    int           iLastdate;                  // ���һ�μ���Ϣ������
    int           iClosedate;                 // ��Լȫ����������
    char          szPunifeeRepay[21 + 1];     // ��������Ϣ
    char          szPunidebts[21 + 1];        // ���ڱ���Ϣ
    char          szPunidebtsRepay[21 + 1];   // ����Ϣ����
    char          szPunidebtsunfrz[21 + 1];   // ���ڱ���Ϣ
    char          szPunifeeunfrz[21 + 1];     // ����Ϣ�ѷ�Ϣ
    char          szPunirights[21 + 1];       // ����Ȩ�淣Ϣ
    char          szPunirightsRepay[21 + 1];  // Ȩ�淣Ϣ����
    char          szPunirightsunfrz[21 + 1];  // ����Ȩ�淣Ϣ
    char          szFeeunfrz[21 + 1];         // ʵʱ������Ϣ
    char          szOverduefeeunfrz[21 + 1];  // ʵʱ����������Ϣ
    int           iRightsqty;                 // δ����Ȩ������
    int           iOverduerightsqty;          // ����δ����Ȩ������
};
//-------------------------------10103589:��Χ���ý������Բ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCreditTradeAttributeField
{
    LONGLONG      llFundid;         // �����ʽ��˻�
};
struct MATRADEAPI CRspFislQryRpcCreditTradeAttributeField
{
    char          chTradeflag;      // ���ý�������
    char          chLimitflag;      // ����ͷű�־
    LONGLONG      llPositionidFund; // ���ʿ���ͷ��
    LONGLONG      llPositionidStk;  // ��ȯ����ͷ��
    char          chCrdtlevel;      // �ͻ����õȼ�
};
//-------------------------------10103590:��Լչ������--------------------------
struct MATRADEAPI CReqFislRpcContractExtensionApplicationField
{
    int           iDebtsno;          // ��ծ��ˮ��
    int           iDebtdate;         // ��ծ����
    int           iDeferdays;        // ����չ������
    char          szRemark[255 + 1]; // ��ע
};
struct MATRADEAPI CRspFislRpcContractExtensionApplicationField
{
    int           iSno;       // ������ˮ��
    int           iApplydate; // ��������
};
//-------------------------------10103591:�ͻ��ȱȶ���ͷű�־�޸�--------------------------
struct MATRADEAPI CReqFislRpcChgGeometricQuotaReleaseFlagField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    char          chLimitflag;      // ����ͷű�־
};
struct MATRADEAPI CRspFislRpcChgGeometricQuotaReleaseFlagField
{
    int           iServerid;          // ��������
    char          szOrgid[4 + 1];     // ��������
    LONGLONG      llCustid;           // �ͻ�����
    char          szCustname[16 + 1]; // �ͻ�����
    LONGLONG      llFundid;           // �ʽ��˺�
    char          chLimitflag;        // ����ͷű�ע
};
//-------------------------------10103592:��Լչ�������ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcContractExtensionApplicationField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iSno;             // ������ˮ��
    int           iStartdate;       // ���뿪ʼ����
    int           iEnddate;         // �����ֹ����
    char          chStatus;         // ����״̬
    int           iDebtdate;        // ��ծ����
    int           iDebtsno;         // ��ծ���
};
struct MATRADEAPI CRspFislQryRpcContractExtensionApplicationField
{
    int           iSno;                 // ������ˮ��
    char          szOrgid[4 + 1];       // �������
    LONGLONG      llFundid;             // �����ʽ��ʺ�
    int           iApplydate;           // ��������
    int           iDebtdate;            // ��ծ����
    int           iDebtsno;             // ��ծ���
    int           iDeferdays;           // չ������
    char          chStatus;             // ����״̬
    int           iApprovaldate;        // ��������
    char          szChkremark[255 + 1]; // ������ע
    char          szRemark[255 + 1];    // ��ע
};
//-------------------------------10103593:��Լչ������ȡ��--------------------------
struct MATRADEAPI CReqFislRpcContractExtensionApplicationCancelField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iSno;             // ������ˮ��
    int           iApplydate;       // ��������
};
struct MATRADEAPI CRspFislRpcContractExtensionApplicationCancelField
{
};
//-------------------------------10103594:��Χ���ղ������Ͳ�ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcRiskEvaluationModeField
{
};
struct MATRADEAPI CRspFislQryRpcRiskEvaluationModeField
{
    int           iServerid;   // ���������
    LONGLONG      llCustid;    // �ͻ�����
    char          chRiskkind;  // ��������
    int           iAssessdate; // ����ʱ��
};
//-------------------------------10103595:չ�ڹ����ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcExtensionRuleField
{
    char          szStatus[128 + 1]; // ����״̬
};
struct MATRADEAPI CRspFislQryRpcExtensionRuleField
{
    int           iRuleid;            // �������
    char          szRulename[64 + 1]; // ��������
    char          chStatus;           // ����״̬
    char          szChkvalue[64 + 1]; // ����ֵ
};
//-------------------------------10103596:��չ�ں�Լ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcCanExtendContractField
{
    LONGLONG      llFundid;               // �ʽ��ʺ�
    char          szCreditdirect[16 + 1]; // ������ȯ����
    char          szMarket[16 + 1];       // �����г�
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          szBegindate[8 + 1];     // ��ʼ����
    char          szEnddate[8 + 1];       // ��������
    int           iSno;                   // ��Լ���
    LONGLONG      llPositionid;           // ͷ����
    char          szPosstr[32 + 1];       // ��λ��
    int           iCount;                 // ��������
};
struct MATRADEAPI CRspFislQryRpcCanExtendContractField
{
    char          szOrgid[4 + 1];             // Ӫҵ��
    LONGLONG      llFundid;                   // �ʽ��ʺ�
    char          chMoneytype;                // ��    ��
    char          chMarket;                   // �����г�
    char          szStkcode[6 + 1];           // ֤ȯ����
    char          szStkname[64 + 1];          // ֤ȯ����
    int           iOrderdate;                 // ί������
    char          szOrdersno[10 + 1];         // ί �� ��
    char          chCreditdirect;             // ������ȯ����
    int           iOrderqty;                  // ί������
    int           iMatchqty;                  // �ɽ�����
    char          szOrderamt[21 + 1];         // ί�н��
    char          szOrderfrzamt[21 + 1];      // ί�ж�����
    char          szMatchamt[21 + 1];         // �ɽ����
    char          szClearamt[21 + 1];         // ������
    char          chLifestatus;               // ��Լ״̬
    int           iEnddate;                   // ��ծ��ֹ����
    int           iOldenddate;                // ԭʼ�ĸ�ծ��ֹ����
    char          szCreditrepay[21 + 1];      // T��֮ǰ�黹���
    char          szCreditrepayunfrz[21 + 1]; // T�չ黹���
    char          szFundremain[21 + 1];       // Ӧ�����
    int           iStkrepay;                  // T��֮ǰ�黹����
    int           iStkrepayunfrz;             // T�չ黹����
    int           iStkremain;                 // Ӧ��֤ȯ����
    char          szStkremainvalue[21 + 1];   // Ӧ��֤ȯ��ֵ
    char          szFee[21 + 1];              // ������ȯϢ����
    char          szOverduefee[21 + 1];       // ����δ����Ϣ����
    char          szFeeRepay[21 + 1];         // ������Ϣ����
    char          szPunifee[21 + 1];          // ��Ϣ�����ķ�Ϣ
    char          szPunifeeRepay[21 + 1];     // ��������Ϣ
    char          szRights[21 + 1];           // δ����Ȩ����
    char          szOverduerights[21 + 1];    // ����δ����Ȩ��
    char          szRightsRepay[21 + 1];      // ������Ȩ��
    char          szLastprice[21 + 1];        // ���¼�
    char          szProfitcost[21 + 1];       // ����ӯ��
    char          szPoststr[32 + 1];          // ��λ��
    int           iSysdate;                   // ϵͳ����
    int           iSno;                       // ��Լ���
    int           iLastdate;                  // ���һ�μ���Ϣ������
    int           iClosedate;                 // ��Լȫ����������
    char          szPunidebts[21 + 1];        // ���ڱ���Ϣ
    char          szPunidebtsRepay[21 + 1];   // ����Ϣ����
    char          szPunidebtsunfrz[21 + 1];   // ���ڱ���Ϣ
    char          szPunifeeunfrz[21 + 1];     // ����Ϣ�ѷ�Ϣ
    char          szPunirights[21 + 1];       // ����Ȩ�淣Ϣ
    char          szPunirightsRepay[21 + 1];  // Ȩ�淣Ϣ����
    char          szPunirightsunfrz[21 + 1];  // ����Ȩ�淣Ϣ
    char          szFeeunfrz[21 + 1];         // ʵʱ������Ϣ
    char          szOverduefeeunfrz[21 + 1];  // ʵʱ����������Ϣ
    int           iRightsqty;                 // δ����Ȩ������
    int           iOverduerightsqty;          // ����δ����Ȩ������
    char          szSecuid[10 + 1];           // ֤ȯ�˺�
    char          chDebtsflag;                // ��Լ���ɷ�ʽ
    LONGLONG      llPositionid;               // ͷ����
    int           iDefertimes;                // չ�ڴ���
};
//-------------------------------10103597:�ͻ�����Ȩ�������ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcGuaranteeInterestAdjustmentDetailField
{
};
struct MATRADEAPI CRspFislQryRpcGuaranteeInterestAdjustmentDetailField
{
    int           iServerid;             // ���������
    LONGLONG      llCustid;              // �ͻ�����
    char          szOrgid[4 + 1];        // ��������
    LONGLONG      llFundid;              // �ʽ��ʺ�
    char          chMoneytype;           // ���Ҵ���
    char          chMarket;              // �����г�
    char          szSecuid[10 + 1];      // �ɶ�����
    char          szStkcode[8 + 1];      // Ȩ��֤ȯ����
    char          szRelastkcode[8 + 1];  // ����֤ȯ����
    char          chRightskind;          // Ȩ������
    char          chAdjustflag;          // ������ʽ
    LONGLONG      llAdjustqty;           // �ɷݵ�������
    char          szAdjustprice[21 + 1]; // �����ɷ�ÿ�ɼ۸�
    char          szAdjustamt[21 + 1];   // �������
    char          szRemark[64 + 1];      // ��ע
};
//-------------------------------10103598:�ͻ���ʷά�ֵ���������ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcHisMaintainGuaranteeRatioField
{
    LONGLONG      llFundid;           // �ʽ��˺�
    int           iBegindate;         // ��ʼ����
    int           iEnddate;           // ��������
    char          szPoststr[128 + 1]; // ��λ��
    int           iCount;             // ��������
};
struct MATRADEAPI CRspFislQryRpcHisMaintainGuaranteeRatioField
{
    int           iSysdate;            // ϵͳ����
    char          szOrgid[4 + 1];      // ��������
    LONGLONG      llFundid;            // �ʽ��ʺ�
    char          chMoneytype;         // ���Ҵ���
    LONGLONG      llCustid;            // �ͻ�����
    char          szCustname[16 + 1];  // �ͻ�����
    char          szKeeprate[21 + 1];  // ά�ֵ�������
    char          szMarginavl[21 + 1]; // ��֤��
    char          chClosestatus;       // ƽ��״̬
    char          chCreditstatus;      // ����״̬
    char          chNoticestatus;      // ׷��״̬
    char          szPoststr[8 + 1];    // ��λ��
};
//-------------------------------10103600:����ͷ��ԤԼ����--------------------------
struct MATRADEAPI CReqFislRpcFinancingPosiSubApplicationField
{
    LONGLONG      llFundid;              // �ʽ��˺�
    char          szReqintrrate[21 + 1]; // �������
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // �����������
    char          szReqamtmin[21 + 1];   // ����������
    char          szReqamtmax[21 + 1];   // ����������
    char          szRemark[255 + 1];     // ��ע
};
struct MATRADEAPI CRspFislRpcFinancingPosiSubApplicationField
{
    int           iReqsno; // ������
};
//-------------------------------10103601:����ͷ��ԤԼ�����ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcFinancingPosiSubApplicationField
{
    int           iReqsno;           // ������
    char          chReqtype;         // ��������
    LONGLONG      llFundid;          // �ʽ��˺�
    int           iBeginsysdate;     // ���뵥���ڿ�ʼ
    int           iEndsysdate;       // ���뵥���ڽ���
    int           iChkdatebegin;     // ������ʼ����
    int           iChkdateend;       // ������������
    int           iCheckdate;        // ��������
    char          szStatus[128 + 1]; // ����״̬
    int           iQrynum;           // ��������
    char          szPosstr[64 + 1];  // ��λ��
};
struct MATRADEAPI CRspFislQryRpcFinancingPosiSubApplicationField
{
    int           iServerid;             // ���������
    int           iReqsno;               // ������
    int           iSysdate;              // ���뵥����
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // ���뵽������
    char          chReqtype;             // ��������
    char          szOrgid[4 + 1];        // ��������
    LONGLONG      llFundid;              // �ʽ��˺�
    char          szReqamtmin[21 + 1];   // ����������
    char          szReqamtmax[21 + 1];   // ����������
    char          szReqintrrate[21 + 1]; // �������
    char          szChkamt[21 + 1];      // �������
    char          szChkintrrate[21 + 1]; // ��������
    int           iChkdatebegin;         // ������ʼ����
    int           iChkdateend;           // ������������
    int           iCheckdate;            // ��������
    char          szChkremark[255 + 1];  // ������ע
    LONGLONG      llLinkposition;        // ����ͷ��
    int           iOperid;               // ������Ա
    char          szStatus[128 + 1];     // ����״̬
    char          szRemark[255 + 1];     // ��ע
};
//-------------------------------10103602:����ͷ����ԤԼ����--------------------------
struct MATRADEAPI CReqFislRpcChgFinancingPosiSubApplicationField
{
    LONGLONG      llFundid;              // �ʽ��˺�
    char          szReqintrrate[21 + 1]; // �������
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // �����������
    char          szReqamtmin[21 + 1];   // ����������
    char          szReqamtmax[21 + 1];   // ����������
    LONGLONG      llLinkposition;        // ����ͷ��
    char          szRemark[255 + 1];     // ��ע
};
struct MATRADEAPI CRspFislRpcChgFinancingPosiSubApplicationField
{
    int           iReqsno; // ������
};
//-------------------------------10103603:ȡ������ͷ��ԤԼ����--------------------------
struct MATRADEAPI CReqFislRpcCancelFinancingPosiSubApplicationField
{
    int           iReqsno;           // ������
    char          szRemark[255 + 1]; // ��ע
};
struct MATRADEAPI CRspFislRpcCancelFinancingPosiSubApplicationField
{
};
//-------------------------------10103604:�ͻ���������ͷ���ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcLinkFinancingPosiField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    LONGLONG      llPositionid;     // ͷ����
    int           iQrynum;          // ��������
    char          szPosstr[64 + 1]; // ��λ��
};
struct MATRADEAPI CRspFislQryRpcLinkFinancingPosiField
{
    char          szOrgid[4 + 1];         // ��������
    LONGLONG      llFundid;               // �ʽ��˺�
    LONGLONG      llCustid;               // �ͻ�����
    char          szFundname[16 + 1];     // �ͻ�����
    LONGLONG      llPositionid;           // ͷ�����
    char          szPositionname[32 + 1]; // ͷ������
    char          chPositype;             // ͷ������
    char          szTotalamt[21 + 1];     // �ܶ�
    char          szAmtlast[21 + 1];      // ���ս��
    char          szAvlamt[21 + 1];       // ʵʱ����
    char          szUsedamt[21 + 1];      // ��ʹ��
    char          szUsedamtreal[21 + 1];  // ʵʱ��ʹ��
    char          szRepayamt[21 + 1];     // ����ֱ�ӻ�����
    char          szRepayamtreal[21 + 1]; // ʵʱ�ѳ���
    char          szFullrate[21 + 1];     // ȫ��ռ�÷���
    char          szUnuserate[21 + 1];    // ����ռ�÷���
    char          szUserate[21 + 1];      // ʹ�÷���
    char          szIntrrate[21 + 1];     // ���ַ���
    char          szPunirate[21 + 1];     // ��Ϣ����
    char          chIntrkind;             // ������������
    int           iLastdate;              // ����Ϣ��
    int           iEnddate;               // ��������
    char          szTrdflag[128 + 1];     // ��������
    char          chStatus;               // ״̬
    char          szPosstr[64 + 1];       // ��λ��
};
//-------------------------------10103605:����Ĭ�����ʿ���ͷ��--------------------------
struct MATRADEAPI CReqFislRpcSetDefaultFinancingOpenPosiField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    LONGLONG      llPositionid;     // �ʽ�ͷ����
};
struct MATRADEAPI CRspFislRpcSetDefaultFinancingOpenPosiField
{
};
//-------------------------------10103606:��ȯͷ��ԤԼ����--------------------------
struct MATRADEAPI CReqFislRpcMarginPosiSubApplicationField
{
    LONGLONG      llFundid;              // �ʽ��˺�
    char          chMarket;              // �г�����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szReqintrrate[21 + 1]; // �������
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // �����������
    LONGLONG      llReqqtymin;           // ������������
    LONGLONG      llReqqtymax;           // ������������
    char          szRemark[255 + 1];     // ��ע
};
struct MATRADEAPI CRspFislRpcMarginPosiSubApplicationField
{
    int           iReqsno; // ������
};
//-------------------------------10103607:��ȯͷ��������--------------------------
struct MATRADEAPI CReqFislRpcChgMarginPosiApplicationField
{
    LONGLONG      llFundid;              // �ʽ��˺�
    char          chMarket;              // �г�����
    char          szStkcode[8 + 1];      // ֤ȯ����
    char          szReqintrrate[21 + 1]; // �������
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // �����������
    LONGLONG      llReqqtymin;           // ������������
    LONGLONG      llReqqtymax;           // ������������
    char          szRemark[255 + 1];     // ��ע
};
struct MATRADEAPI CRspFislRpcChgMarginPosiApplicationField
{
    int           iReqsno; // ������
};
//-------------------------------10103608:��ȯͷ��ԤԼ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcMarginPosiSubField
{
    int           iReqsno;           // ������
    char          chReqtype;         // ��������
    int           iSysdate;          // ��������
    LONGLONG      llFundid;          // �����ʽ��˺�
    int           iDatebegin;        // ���뿪ʼ����
    int           iDateend;          // �����������
    int           iChkdatebegin;     // ������ʼ����
    int           iChkdateend;       // ������������
    int           iCheckdate;        // ��������
    char          chStatus;          // ����״̬
    int           iQrynum;           // ��ѯ����
    char          szPosstr[64 + 1];  // ��λ��
    char          szRemark[255 + 1]; // ��ע
};
struct MATRADEAPI CRspFislQryRpcMarginPosiSubField
{
    int           iServerid;             // ���ı��
    int           iReqsno;               // ������
    int           iSysdate;              // ��������
    char          chReqtype;             // ��������
    LONGLONG      llCustid;              // �ͻ�����
    char          szOrgid[5 + 1];        // ��������
    LONGLONG      llFundid;              // �ʽ��˻�
    char          chMarket;              // �����г�
    char          szStkcode[8 + 1];      // ֤ȯ����
    LONGLONG      llReqqtymin;           // ������������
    LONGLONG      llReqqtymax;           // ������������
    char          szReqintrrate[21 + 1]; // �������
    int           iDatebegin;            // ���뿪ʼ����
    int           iDateend;              // ���뵽������
    LONGLONG      llChkqty;              // ��������
    char          szChkintrrate[21 + 1]; // ��������
    int           iChkdatebegin;         // ������ʼ����
    int           iChkdateend;           // ������������
    int           iCheckdate;            // ��������
    char          szChkremark[255 + 1];  // �������
    LONGLONG      llLinkposition;        // ����ͷ��
    int           iOperid;               // ������
    char          chStatus;              // ����״̬
    char          szRemark[255 + 1];     // ��ע
};
//-------------------------------10103609:��ȯ����ͷ��ָ��--------------------------
struct MATRADEAPI CReqFislRpcMarginOpenPosiAppointField
{
    LONGLONG      llFundid;         // �ʽ��ʺ�
    LONGLONG      llPositionid;     // ��ȯͷ����
};
struct MATRADEAPI CRspFislRpcMarginOpenPosiAppointField
{
};
//-------------------------------10103610:�ͻ�������ȯͷ���ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcLinkMarginPosiField
{
    LONGLONG      llFundid;            // �ʽ��˺�
    LONGLONG      llPositionid;        // ͷ����
    char          szPositype[128 + 1]; // ͷ������
    char          szMarket[128 + 1];   // �����г�
    char          szStkcode[8 + 1];    // ֤ȯ����
    int           iQrynum;             // ��������
    char          szPosstr[64 + 1];    // ��λ��
};
struct MATRADEAPI CRspFislQryRpcLinkMarginPosiField
{
    char          szOrgid[4 + 1];         // ��������
    LONGLONG      llFundid;               // �ʽ��˺�
    LONGLONG      llCustid;               // �ͻ�����
    LONGLONG      llPositionid;           // ͷ�����
    char          szPositionname[32 + 1]; // ͷ������
    char          chPositype;             // ͷ������
    char          chMarket;               // �����г�
    char          szStkcode[8 + 1];       // ֤ȯ����
    char          szStkname[64 + 1];      // ֤ȯ����
    LONGLONG      llStktotal;             // ͷ������
    LONGLONG      llStklast;              // ��������
    LONGLONG      llStkavl;               // ͷ��ʵʱ����
    LONGLONG      llStkused;              // ͷ����ʹ��
    LONGLONG      llStkusedreal;          // ͷ��ʵʱʹ��
    LONGLONG      llStkrepayreal;         // ʵʱ�ѳ���
    char          szFullrate[21 + 1];     // ȫ��ռ�÷���
    char          szUnuserate[21 + 1];    // ����ռ�÷���
    char          szUserate[21 + 1];      // ʹ�÷���
    char          szIntrrate[21 + 1];     // ���ַ���
    char          szPunirate[21 + 1];     // ��Ϣ����
    char          chIntrkind;             // ������������
    int           iBegindate;             // ��Ч��ʼ����
    int           iEnddate;               // ��Ч��������
    char          chStatus;               // ״̬
    char          szPosstr[64 + 1];       // ��λ��
};
//-------------------------------10103611:��ȯͷ��ԤԼȡ��--------------------------
struct MATRADEAPI CReqFislRpcCancelMarginPosiSubField
{
    int           iReqsno;           // ������
    int           iSysdate;          // ��������
    char          szRemark[255 + 1]; // ��ע
};
struct MATRADEAPI CRspFislRpcCancelMarginPosiSubField
{
};
//-------------------------------10103612:�ⶳ��ǩ��Ԥ������ʽ�--------------------------
struct MATRADEAPI CReqFislRpcUnfreezePreFrozenFundsField
{
    LONGLONG      llFundid;         // �ʽ��˺�
    int           iMatchdate;       // ��ǩ����
};
struct MATRADEAPI CRspFislRpcUnfreezePreFrozenFundsField
{
    int           iSno;               // �ⶳ��ˮ���
    char          szUnfrzamt[21 + 1]; // �ⶳ���
};
//-------------------------------10103613:�������۽ɿ�, ֧����������--------------------------
struct MATRADEAPI CReqFislRpcCancelRationField
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
struct MATRADEAPI CRspFislRpcCancelRationField
{
};

//-------------------------------10349001:ϵͳ̽��--------------------------
struct MATRADEAPI CReqFislBizStatusField
{
  char            szStkbd[2 + 1];             // ���װ�� ����ʱΪϵͳ̽�⣬���ص�һ������� �;�����ʱ�����ظð���Ƿ�����µ��Լ��������ڵ���Ϣ; ��*����@ʱ�������а���Ƿ���µ���Ϣ
};

struct MATRADEAPI CRspFislBizStatusField
{
  char            szStkbd[2 + 1];             // ���װ�� 
  int             iTrdDate;                   // ��ǰ������ 
  int             iPhysicalDate;              // �������� 
  char            chTrdStatus;                // ����״̬ 0:��ֹ����  1��������
  char            szRemark[128 + 1];          // ��ע �����µ�������
};

//-------------------------------10303008:��Ѻ�ɷ���ϸ��ѯ(���ͻ�)--------------------------
struct MATRADEAPI CReqFislQryPledgeSharesField
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

struct MATRADEAPI CRspFislQryPledgeSharesField
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
struct MATRADEAPI CReqFislQryFundFlowField
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

struct MATRADEAPI CRspFislQryFundFlowField
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

//-------------------------------10302002:����ί��(����)--------------------------
struct MATRADEAPI CReqFislOrderExField
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

struct MATRADEAPI CRspFislOrderExField
{
  char            szOrderId[10 + 1];          // ��ͬ��� 
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
};

//-------------------------------10309007:�ɷ���ˮ��ѯ--------------------------
struct MATRADEAPI CReqFislQryStockFlowField
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

struct MATRADEAPI CRspFislQryStockFlowField
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
//-------------------------------10309041:�ʽ�䶯���ܲ�ѯ--------------------------
struct MATRADEAPI CReqFislQryFundEffectSummaryField
{
  LONGLONG        llCuacctCode;             // �ʽ��˻�
  char			  szIntOrg[4096 + 1];	    // �ڲ�����
  int             iBizCode;                 // ҵ����� 
};

struct MATRADEAPI CRspFislQryFundEffectSummaryField
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
struct MATRADEAPI CReqFislQryStockEffectSummaryField
{
  LONGLONG        llCuacctCode;               // �ʽ��˻�
  char			  szIntOrg[4096 + 1];		  // �ڲ�����
  char			  szStkbd[32 + 1];			  // ���װ��
  int             iBizCode;                   // ҵ����� 
};
struct MATRADEAPI CRspFislQryStockEffectSummaryField
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
//-------------------------------10306028:���н����ղ�ѯ--------------------------
struct MATRADEAPI CReqFislQrySettDateField
{
};

struct MATRADEAPI CRspFislQrySettDateField
{
  int             iTrdDate;                   // �������� 
  int             iSettDate;                  // ��һ������ 
  int             iSubsysSn;                  // ��ϵͳ��� 
};

//-------------------------------10305015:�ʽ𻮲�(������ȯ)--------------------------
struct MATRADEAPI CReqFislFundTransferJzjyField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            chDirect;                   // �������� ��1�����н��׻���������ϵͳ���� ��2�����н��׻��롢����ϵͳ����
  char            szBizAmt[21 + 1];           // ������� 
  LONGLONG        llOpCode;                   // ������Ա��� ��ѯ���н��׹ɷ���Ҫ��ԱȨ��
  char            chIsEffectBln;              // �Ƿ񻮲���� ��0��:��������� ��1��:������� ��Ĭ��ֵ��1����
};

struct MATRADEAPI CRspFislFundTransferJzjyField
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

//-------------------------------10321028:������ȯ��Լչ������--------------------------
struct MATRADEAPI CReqFislContApplyField
{
  LONGLONG        llContDays;                 // չ������ 
  int             iContStopDate;              // չ�ڽ�ֹ���� 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  LONGLONG        llCustCode;                 // �ͻ����� 
  char            szStkbd[2 + 1];             // ���װ�� 
  int             iOpeningDate;               // �������� 
  char            chCompIniFlag;              // ���ø�����־ 0-������ 1-����
};

struct MATRADEAPI CRspFislContApplyField
{
};

//-------------------------------10305036:��֤ת��--------------------------
struct MATRADEAPI CReqFislBankStkTransferField
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

struct MATRADEAPI CRspFislBankStkTransferField
{
  LONGLONG        llSerialNo;                 // ��ˮ��� 
  char            szErrorMess[128 + 1];       // ������Ϣ 
};

//-------------------------------10321076:��ȯͷ����ϸ��ѯ--------------------------
struct MATRADEAPI CReqFislQryCashDetailField
{
  LONGLONG        llCashNo;                   // ͷ���� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            szStkCode[8 + 1];           // ֤ȯ���� 
};

struct MATRADEAPI CRspFislQryCashDetailField
{
  LONGLONG        llCashNo;                   // ͷ���� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  int             iIntOrg;                    // �ڲ����� 
  char            chStkex;                    // ֤ȯ������ 
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  char            szStkName[64 + 1];          // ֤ȯ���� 
  int             iEndDate;                   // �������� 
  LONGLONG        llStkBln;                   // ͷ����� 
  LONGLONG        llStkRepayReal;             // ʵʱ�������� 
  LONGLONG        llStkUsed;                  // ������� 
  int             iContractNo;                // ��� 
  int             iSlContractDate;            // ��Լ���� 
  char            szUserName[32 + 1];         // �û����� 
  LONGLONG        llDeferQty;                 // ��;չ������ 
  LONGLONG        llRightsQty;                // δ����Ȩ������ 
};

//-------------------------------10321012:��ѯ������ϸ--------------------------
struct MATRADEAPI CReqFislQryRepayDetailField
{
  int             iTrdDate;                   // �������� 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  int             iConTrdDate;                // ��Լ�������� 
  char            chConStkex;                 // ��Լ�г� 
  char            szConStkbd[32 + 1];         // ��Լ��� 
  char            szConOrderId[10 + 1];       // ��Լ��ͬ��� 
  LONGLONG        llCustCode;                 // �ͻ����� 
  char            szOrgId[1024 + 1];          // ��֧���� 
};

struct MATRADEAPI CRspFislQryRepayDetailField
{
  int             iTrdDate;                   // �������� 
  LONGLONG        llSno;                      // ��ˮ�� 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  int             iOrderDate;                 // ί������ 
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  char            chRepayType;                // �������� 0:��������Ƿ�� 1:������ȯ����
  LONGLONG        llCustCode;                 // �ͻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            szTrdacct[20 + 1];          // �����˻� 
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  int             iConTrdDate;                // ��Լ�������� 
  char            chConStkex;                 // ��Լ�г� 
  char            szConStkbd[2 + 1];          // ��Լ��� 
  char            szConOrderId[10 + 1];       // ��Լ��ͬ��� 
  LONGLONG        llRltRepayAmt;              // ʵʱ������� 
  LONGLONG        llRltRepayInt;              // ʵʱ������Ϣ 
  char            szOrgId[4 + 1];             // ��֧���� 
  char            chCreditdebtsType;          // ��ծ���� 
  LONGLONG        llFundEffect;               // ��ծ�ʽ����� 
  int             iRelaDate;                  // ������ծ���� 
  int             iRelasNo;                   // ������ծ��ˮ�� 
  char            szRemark[255 + 1];          // ��ע 
  char            szStkName[64 + 1];          // ֤ȯ���� 
};

//-------------------------------10103614:�Ӷ���VIPϵͳ�ʽ�ת--------------------------
struct MATRADEAPI CReqFislRpcFundTransferVipField
{
  LONGLONG        llFundid;                   // �ʽ��˺� 
  char            chMoneytype;                // ���Ҵ��� 
  char            szFundpwd[32 + 1];          // �ʽ����� ������Ҫ����
  char            szBankcode[4 + 1];          // ���д��� 
  char            szBankpwd[32 + 1];          // �������� ������Ҫ����
  char            chBanktrantype;             // ת������ 1:����ת֤ȯ 2:֤ȯת����
  char            szTranamt[21 + 1];          // ת�ʽ�� 
};

struct MATRADEAPI CRspFislRpcFundTransferVipField
{
  int             iSno;                       // ί����� 
};

//-------------------------------10103615:ȯԴͷ���Լ��ѯ--------------------------
struct MATRADEAPI CReqFislQryRpcPositionContractSrcField
{
  char            chQrytype;                  // ��ѯ���� 0:��ǰ 1:��ʷ
  int             iSysdateBeg;                // ��Լ����(��) 
  int             iSysdateEnd;                // ��Լ����(ֹ) 
  int             iSno;                       // ��Լ��� 
  char            szSourcetype[8 + 1];        // ȯԴ���� 0:ԤԼȯ(Ĭ��) 1:���ȯ���� 2:׼���ȯ����
  char            szOrgid[2048 + 1];          // �������� 
  LONGLONG        llFundid;                   // �ʽ��ʺ� 
  char            szMarket[8 + 1];            // �����г� 0:��A  1:��A
  char            szStkcode[10 + 1];          // ֤ȯ���� 
  char            szStatus[8 + 1];            // ��Լ״̬ 0:δ�˽� 1:���˽�
  char            szRatediffbeg[21 + 1];      // ��ʼ����������� 
  char            szRatediffend[21 + 1];      // ��������������� 
  int             iQrynum;                    // ��ѯ��Ŀ 
  char            szPosstr[128 + 1];          // ��λ�� 
};

struct MATRADEAPI CRspFislQryRpcPositionContractSrcField
{
  int             iSysdate;                   // ��Լ���� 
  int             iSno;                       // ��Լ��� 
  char            szSourcetypename[32 + 1];   // ȯԴ�������� 
  char            chSourcetype;               // ȯԴ���� 
  char            szOrgid[4 + 1];             // �������� 
  LONGLONG        llFundid;                   // �ʽ��˺� 
  char            szFundname[16 + 1];         // �ͻ����� 
  char            szMarketname[32 + 1];       // �г����� 
  char            chMarket;                   // �г����� 
  char            szStkcode[10 + 1];          // ֤ȯ���� 
  char            szStkname[64 + 1];          // ֤ȯ���� 
  char            szInteratemodelname[16 + 1];// ��Ϣģʽ���� 
  char            chInteratemodel;            // ��Ϣģʽ 0:ȫ��ռ�÷� 1:���з�+��ծʹ�� 2:���з�+ͷ��ʹ��
  char            szFullrate[21 + 1];         // ȫ��ռ�÷��� 
  char            szUnuserate[21 + 1];        // ����ռ�÷��� 
  char            szUserate[21 + 1];          // ʹ�÷��� 
  char            szTermrate[21 + 1];         // ֤������ 
  char            szRatediff[21 + 1];         // ������֤���������� 
  int             iPositionid;                // ͷ���� 
  LONGLONG        llStktotal;                 // ͷ������ 
  LONGLONG        llStkused;                  // ��ʹ������ 
  LONGLONG        llStkavl;                   // �������� 
  LONGLONG        llUnlockqty;                // �ѽ������� 
  LONGLONG        llRightsqty;                // Ȩ������ 
  LONGLONG        llUnpaidrightsqty;          // δ��Ȩ������ 
  int             iContractno;                // ֤���Լ��� 
  int             iEnddate;                   // �������� 
  int             iReqdate;                   // �������� 
  int             iReqsno;                    // ���뵥�� 
  int             iAssigndate;                // �������� 
  char            szPosistkprice[21 + 1];     // ��Ϣ�۸� 
  char            szFee[21 + 1];              // �ۼ�Ϣ�� 
  LONGLONG        llRegstkavl;                // �Ǽ���δ�������� 
  LONGLONG        llUnuserights;              // �ۻ�δ���ֲ���Ȩ���� 
  LONGLONG        llDeferqty;                 // ��;չ������ 
  int             iDefersysdate;              // չ���º�Լ���� 
  int             iDefersno;                  // չ���º�Լ��� 
  char            szStatusname[32 + 1];       // ��Լ״̬���� 
  char            chStatus;                   // ��Լ״̬ 
  int             iClosedate;                 // �˽����� 
  int             iPreparedate;               // ��ȯ���� 
  char            szRemark[255 + 1];          // ��ע 
  int             iLenderid;                  // �����˴��� 
  char            szLendername[64 + 1];       // ���������� 
  char            szPosstr[128 + 1];          // ��λ�� 
};

//-------------------------------10304013:��֤��Ϣ����(����¼��/�޸�)--------------------------
struct MATRADEAPI CReqFislAuthDataSetJzjyField
{
  LONGLONG        llUserCode;                 // �û����� 
  char            szAuthData[256 + 1];        // ��֤���� ����
  char            szSrcAuthData[256 + 1];     // ԭ��֤���� ����
  char            chUseScope;                 // ʹ�÷�Χ 0: ��Ʊ�������� 2�����ý�������
};

struct MATRADEAPI CRspFislAuthDataSetJzjyField
{
  char            szMsgOk[32 + 1];            // �ɹ���Ϣ 
};

//-------------------------------10305019:�ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮��--------------------------
struct MATRADEAPI CReqFislFundTransferNodeField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            chDirect;                   // �������� ��0������ ��1������
  char            szTransFund[21 + 1];        // ������� 
  char            chTranType;                 // ��������  '0'-�������� '1'-������ȡ
};

struct MATRADEAPI CRspFislFundTransferNodeField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            szTransFund[21 + 1];        // ������� 
  LONGLONG        llSerialNo;                 // ��ˮ��� 
  char            chTransStatus;              // ����״̬ 0-�ѵ��� 1-�ɹ� 2-ʧ�� 3-��ʱ
  char            szRemark[256 + 1];          // ��ע ����״̬Ϊ2/3ʱ���ش���ԭ��
};

//-------------------------------10349044:�ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮��[��ϯ����]------------------
struct MATRADEAPI CReqFislFundTransferNodeCiXiField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            szTransFund[21 + 1];        // ������� 
  char            chDirect;                   // ��������  '0'-���� '1'-����
  char            szStkbd[2 + 1];             // ���װ�� 
  int             iSyncSubsysSn;              // ����Ŀ��ڵ� 
  char            chTranType;                 // ��������  '0'-�������� '1'-������ȡ
};

struct MATRADEAPI CRspFislFundTransferNodeCiXiField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� 
  char            szTransFund[21 + 1];        // ������� 
  LONGLONG        llSerialNo;                 // ��ˮ��� 
  char            chTransStatus;              // ����״̬ 0-�ѵ��� 1-�ɹ� 2-ʧ�� 3-��ʱ
  char            szRemark[256 + 1];          // ��ע ����״̬Ϊ2/3ʱ���ش���ԭ��
};

//-------------------------------10323074:������ȯ�ʽ�����ö�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqFislQryFundAvlField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
};

struct MATRADEAPI CRspFislQryFundAvlField
{
  LONGLONG        llCustCode;                 // �ͻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            chCurrency;                 // ���Ҵ��� �ֵ�[CURRENCY]
  int             iIntOrg;                    // �ڲ����� 
  char            szFundAvl[21 + 1];          // �ʽ���ý�� 
  char            szCreditFundBln[21 + 1];    // ��ȯ������� 
  char            szCreditFundUsed[21 + 1];   // �����ʽ�ռ�� 
  char            szMarginValue[21 + 1];      // ��֤�������� 
  char            szFiCreditAvl[21 + 1];      // ���ʿ��ö�� 
  char            szSlCreditAvl[21 + 1];      // ��ȯ���ö�� 
  LONGLONG        llCashFiNo;                 // ����ͷ���� 
  LONGLONG        llCashSlNo;                 // ��ȯͷ���� 
  char            szFiCashAvl[21 + 1];        // ����ͷ����� 
  char            szCreditLine[21 + 1];       // ���ö�� 
  char            chCreditType;               // ���ö������ 
  char            szFiCredit[21 + 1];         // �������ö�� 
  char            szSlCredit[21 + 1];         // ��ȯ���ö�� 
};

//-------------------------------10103616:�û��������--------------------------
struct MATRADEAPI CReqFislAutuDataMngField
{
  char            chOperationType;            // �������� 1:�޸� 3:����
  char            chUseScope;                 // ʹ�÷�Χ 0:��������
  char            chAuthType;                 // ��֤���� 0:����
  char            szOldAuthData[256 + 1];     // ԭ��֤��Ϣ 
  char            szNewAuthData[256 + 1];     // ����֤��Ϣ 
  char            szOpRemark[128 + 1];        // ������ע 
  char            chFislSameFlag;             // ͬ����ͨ��־ 1:ȡ�����������ͬ������
  char            chSubsysFlag;               // ͬ����ʾ 0:���غͶԽ�ϵͳ������ 1:�����¶Խ�ϵͳ 2:�����±���
  char            chEncryptType;              // �������� 1:���ݿ�洢�㷨 ����:ͨ�ż����㷨
  LONGLONG        llCuacctCode;               // �ʲ��˻� �Խ�����֧����ϵͳ����ά������
};

struct MATRADEAPI CRspFislAutuDataMngField
{
};

//-------------------------------10301082:���ڽ���������Ϣ��ѯ--------------------------
struct MATRADEAPI CReqFislQryBlockTradingMktInfoField
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

struct MATRADEAPI CRspFislQryBlockTradingMktInfoField
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
struct MATRADEAPI CReqFislQryClosingBlockTradingMktInfoField
{
  char            chStkex;                    // �г� 
  char            szStkCode[32 + 1];          // ֤ȯ���� 
  char            chStkPhQuoteType;           // �̺󱨼����� ��1�������̼� ��2����ƽ����
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ�� 
  int             iQueryNum;                  // ��ѯ���� 
};

struct MATRADEAPI CRspFislQryClosingBlockTradingMktInfoField
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
struct MATRADEAPI CReqFislQryClosingMktSecondboardField
{
  char            chStkex;                    // �г� 
  char            szStkCode[32 + 1];          // ֤ȯ���� 
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ�� 
  int             iQueryNum;                  // ��ѯ���� 
};

struct MATRADEAPI CRspFislQryClosingMktSecondboardField
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

//-------------------------------10302003:���ί��------------------------------------
struct MATRADEAPI CReqFislCombOrderField
{
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  int             iOrderBsn;                  // ί������ �������ű�ʾ��ί�д���,Ϊ-1���ͱ�ʾ��ʼί��
  int             iCuacctSn;                  // �˻���� 
  char            chErrorFlag;                // �������ױ�־ 0:��һ��ί�г���ʱ���߱�ί��ȫ��ʧ�ܣ������� 1:��һ��ί�г���ʱ���߱�ί�м���ִ�У�������ÿһ��ί�н����Ϣ
  char            szStrategyText[32768 + 1];  // ������Ϣ ��ʽ1��{ί����Ϣ1}{ί����Ϣ2}��{ί����ϢN} ί����Ϣ��ʽ�����װ��|֤ȯ�˻�|֤ȯ����|ί�м۸�|ί������|���׵�Ԫ ��ʽ����ί����Ϣ1|ί����Ϣ2|��|ί����ϢN  ί����Ϣ��ʽ�����װ��^֤ȯ�˻�^֤ȯ����^ί�м۸�^ί������^���׵�Ԫ ���׵�ԪΪ��ѡ�����Ϊ��ѡ
  LONGLONG        llCustCode;                 // �ͻ����� 
  char            szClientInfo[256 + 1];      // �ն���Ϣ Ӳ�̺�\CPU\�������� ��ʽ�� "PC;IIP=����IP��ַ;IPORT=����IP�˿ں�;LIP=����IP;MAC=MAC��ַ;HD=Ӳ�����к�;PCN=PC�ն��豸��;CPU=CPU���к�;PI=Ӳ�̷�����Ϣ;VOL=ϵͳ�̾���@��չ��Ϣ1;��չ��Ϣ2;��չ��Ϣ3"
  char            szTrdTermcode[20 + 1];      // �ն������� 
  char            chSecurityLevel;            // ��ȫ�ֶ� 1:У��Ựƾ֤
  char            szSecurityInfo[256 + 1];    // ��ȫ��Ϣ �Զ���д
  char            chPublishCtrlFlag;          // ��Ʊ��ر�־ 0:������ 1:���ƹ�Ʊ����ֲֲ������ܹɱ�һ������ �������޲����󣬲�����Ϻ�̨��������ò���������Ч
  int             iTgwIndex;                  // ָ�����̵��±�
};

struct MATRADEAPI CRspFislCombOrderField
{
  int             iOrderBsn;                  // ί������ 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
  int             iCuacctSn;                  // �˻���� 
  int             iOrderRet;                  // ί�н�� 0:��ʾ�ɹ� -1:��ʾʧ��
  char            szRetInfo[256 + 1];         // ������Ϣ ����ί�н����Ϣ
  char            szOrderPrice[21 + 1];       // ί�м۸� 
  LONGLONG        llOrderQty;                 // ί������ 
  char            szOrderAmt[21 + 1];         // ί�н�� 
  char            szOrderFrzAmt[21 + 1];      // ������ 
  char            szStkpbu[8 + 1];            // ���׵�Ԫ 
  char            szStkName[64 + 1];          // ֤ȯ���� 
  int             iStkBizAction;              // ҵ����Ϊ �ֵ�[STK_BIZ_ACTION]
  char            szTrdacct[20 + 1];          // ֤ȯ�˻� 
};

//-------------------------------10301108:ģ��ͻ���¼--------------------------
struct MATRADEAPI CReqFislUserLoginImpersonateField
{
  LONGLONG        llCustCode;                 // �ͻ����� �ͻ�����
  LONGLONG        llCuacctCode;               // �ʲ��˻� �ʲ��˻�
  char            chQueryFlag;                // ��ѯ���� 0:��ǰȡ���� 1:���ȡ����
  char            szQueryPos[32 + 1];         // ��λ�� 
  int             iQueryNum;                  // ��ѯ���� 
  char            chChannel;                  // ��������
  char            szSerChannel[8 + 1];        // ��������
};

struct MATRADEAPI CRspFislUserLoginImpersonateField
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
  int             iSubsysSn;                  // Զ����ϵͳ��� ָ�ʲ������Ӧ��ϵͳ���� �ԽӼ��н���ϵͳʱ�Ǽ��н���ϵͳ�Ľڵ���� �Խ��ʲ��й�ϵͳʱ,ָ���ǲ����й�ϵͳ
  char            chTrdacctExcls;             // ֤ȯ�˻���� 
};

//-------------------------------10303097:�Ϻ����ֹɷݶ�Ȳ�ѯ--------------------------
struct MATRADEAPI CReqFislQryReductLimitShField
{
  char            szTrdacct[20 + 1];          // �����˻� 
  char            szStkCode[32 + 1];          // ֤ȯ���� 
};

struct MATRADEAPI CRspFislQryReductLimitShField
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
struct MATRADEAPI CReqFislQryReductLimitSzField
{
  char            szTrdacct[20 + 1];          // �����˻� 
  char            szStkCode[32 + 1];          // ֤ȯ���� 
  char            szStkPbu[8 + 1];            // ���׵�Ԫ 
};

struct MATRADEAPI CRspFislQryReductLimitSzField
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
struct MATRADEAPI CReqFislOrderFlashField
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

struct MATRADEAPI CRspFislOrderFlashField
{
  char            szOrderId[10 + 1];          // ��ͬ���
  int             iOrderBsn;                  // ί������
  int             iCuacctSn;                  // �˻����
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  int             iStkBiz;                    // ֤ȯҵ�� �ֵ�[STK_BIZ]
};

//-------------------------------10302104:ί�г���(����)------------------------------------
struct MATRADEAPI CReqFislCancelOrderFlashField
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

struct MATRADEAPI CRspFislCancelOrderFlashField
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
struct MATRADEAPI CReqFislCombOrderFlashField
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

struct MATRADEAPI CRspFislCombOrderFlashField
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

//-------------------------------00102030:�ɽ��ر�����(����)------------------------------------
struct MATRADEAPI CRtnFislOrderFillFlashField
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
struct MATRADEAPI CRtnFislOrderConfirmFlashField
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

#endif  //__MA_CLI_FISL_TRADE_API_STRUCT_H__