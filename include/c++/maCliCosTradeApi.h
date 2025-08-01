#if !defined(__MA_CLI_COS_TRADE_API_H__)
#define __MA_CLI_COS_TRADE_API_H__

#include "maCliTradeApi.h"
#include "maCliCosTradeApiStruct.h"
#include "maCliStkTradeApiStruct.h"

BGN_NAMESPACE_MACLI

class MATRADEAPI CCliCosTradeSpi : virtual public CCliTradeSpi
{
public:
  // ��Ʊ�û���¼������Ӧ
  virtual int OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, CRspStkUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����û���¼������Ӧ
  virtual int OnRspFislUserLogin(CFirstSetField *p_pFirstSetField, CRspFislUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ȩ�û���¼������Ӧ
  virtual int OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, CRspOptUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ȩ�û���¼����(��)��Ӧ
  virtual int OnRspOptRpcUserLogin(CFirstSetField *p_pFirstSetField, CRspOptRpcUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ڻ��û���¼������Ӧ
  virtual int OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, CRspFutureUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��ϵͳ��ѯ
  virtual int OnRspQryConf(CFirstSetField *p_pFirstSet, CRspCosConfField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ϵͳ����
  virtual int OnRspChgConf(CFirstSetField *p_pFirstSet, CRspCosChgConfField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����ί��
  virtual int OnRspOrder(CFirstSetField *p_pFirstSet, CRspCosOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ί�г���
  virtual int OnRspCancelOrder(CFirstSetField *p_pFirstSet, CRspCosCancelOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ί�иĵ�
  virtual int OnRspChgOrder(CFirstSetField *p_pFirstSet, CRspCosChgOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�������ί��
  virtual int OnRspCombOrder(CFirstSetField *p_pFirstSet, CRspCosCombOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ڵ���
  virtual int OnRspChgNode(CFirstSetField *p_pFirstSet, CRspCosChgNodeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ڵ�������
  virtual int OnRspChgNodeOnline(CFirstSetField *p_pFirstSet, CRspCosChgNodeOnlineField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����ί�в�ѯ
  virtual int OnRspQryOrderInfo(CFirstSetField *p_pFirstSet, CRspCosOrderInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ͻ����ڽڵ��Ų�ѯ
  virtual int OnRspQryNodeInfo(CFirstSetField *p_pFirstSet, CRspCosNodeInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ڵ�Ŀͻ���ѯ
  virtual int OnRspQryNodeCustInfo(CFirstSetField *p_pFirstSet, CRspCosNodeCustInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ӿ����ò�ѯ
  virtual int OnRspQryItfInfo(CFirstSetField *p_pFirstSet, CRspCosItfInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ӿ���������
  virtual int OnRspChgItf(CFirstSetField *p_pFirstSet, CRspCosChgItfField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�����ɳ���ί�в�ѯ
  virtual int OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSet, CRspCosCanWithdrawOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�����ɽ���ѯ
  virtual int OnRspQryMatch(CFirstSetField *p_pFirstSet, CRspCosMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //������ί�в�ѯ
  virtual int OnRspQrySubOrder(CFirstSetField *p_pFirstSet, CRspCosSubOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ʷί�в�ѯ
  virtual int OnRspQryHisOrderInfo(CFirstSetField *p_pFirstSet, CRspCosHisOrderInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ʷ�ɽ���ѯ
  virtual int OnRspQryHisFillInfo(CFirstSetField *p_pFirstSet, CRspCosHisFillInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //���ί�в�ѯ
  virtual int OnRspQryCombOrderInfo(CFirstSetField *p_pFirstSet, CRspCosCombOrderInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ʲ��û���ѯ
  virtual int OnRspQryCuacctCodeInfo(CFirstSetField *p_pFirstSet, CRspCosCuacctCodeInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ڵ��˻���ѯ
  virtual int OnRspQryNodeUsers(CFirstSetField *p_pFirstSet, CRspCosNodeUsersField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�������ί�б�Ų�ѯ���ί��
  virtual int OnRspQryCombOrderInfoEx(CFirstSetField *p_pFirstSet, CRspCosCombOrderInfoExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //���鴦�����
  virtual int OnRspSnapshot(CFirstSetField *p_pFirstSet, CRspCosSnapshotField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����طŹ���
  virtual int OnRspReplay(CFirstSetField *p_pFirstSet, CRspCosReplayField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��������ѯί��
  virtual int OnRspQryMktDataInfo(CFirstSetField *p_pFirstSet, CRspCosMktDataInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�����¼����
  virtual int OnRspRecordMktData(CFirstSetField *p_pFirstSet, CRspCosRecordMktDataField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����طŽ��Ȳ�ѯ
  virtual int OnRspQryReplayInfo(CFirstSetField *p_pFirstSet, CRspCosReplayInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ʷ�����ѯί��
  virtual int OnRspQryHisMktData(CFirstSetField *p_pFirstSet, CRspCosHisMktDataField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����ͬ��
  virtual int OnRspSync(CFirstSetField *p_pFirstSet, CRspCosSyncField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ʲ��˻�����
  virtual int OnRspOpenAccount(CFirstSetField *p_pFirstSet, CRspCosOpenAccountField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ʲ��˻�����
  virtual int OnRspCloseAccount(CFirstSetField *p_pFirstSet, CRspCosCloseAccountField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ʽ�ͬ��
  virtual int OnRspFundSync(CFirstSetField *p_pFirstSet, CRspCosFundSyncField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ɷ�ͬ��
  virtual int OnRspStkSync(CFirstSetField *p_pFirstSet, CRspCosStkSyncField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��������
  virtual int OnRspCutoff(CFirstSetField *p_pFirstSet, CRspCosCutoffField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ
  virtual int OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableFundField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ùɷݲ�ѯ��Ӧ
  virtual int OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableSharesField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //�ɽ���Ϣ��������: 
  //  1.����ί�еĳɽ���Ϣ
  //   2.�����������ĳɽ���Ϣ��ί�����걨����������
  //   3.�ڲ������ĳɽ���Ϣ��ί��δ�걨����������
  //   4.�Ƿ�ί�еĳ����ɽ���Ϣ��ί�б��������ܾ���
  virtual int OnRtnOrder(CRtnOrderField * p_pOrderField){return 0;}
  //����ί��ȷ�ϻر�
  virtual int OnRtnTsuOrder(CRtnTsuOrderField* p_pOrderField){return 0;}
  ///////////////////////////////////////////////////////////////////////  
  //�ڲ��ӿڹ���
  //�ɽ��ر�����
  virtual int OnRspMatchReport(CFirstSetField *p_pFirstSet, CRspCosMatchReportField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ί��Ӧ������
  virtual int OnRspOrderAnswer(CFirstSetField *p_pFirstSet, CRspCosOrderAnswerField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  //��ѡ�ɱ༭
  virtual int OnRspPortfolio(CFirstSetField *p_pFirstSet, CRspCosPortfolioField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ѡ�ɲ�ѯ
  virtual int OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, CRspCosPortfolioInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ETF����ί��
  virtual int OnRspEtfBasketOrder(CFirstSetField *p_pFirstSet, CRspCosEtfBasketOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�Զ�������ί��
  virtual int OnRspCustomBasketOrder(CFirstSetField *p_pFirstSet, CRspCosCustomBasketOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //֤ȯ��Ϣ��ѯ
  virtual int OnRspQryStkInfo(CFirstSetField *p_pFirstSet, CRspCosQryStkInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�㷨��ί����Ӧ
  virtual int OnRspOrderStrategy(CFirstSetField *p_pFirstSet, CRspCosOrderStrategyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //������ͣ��Ӧ
  virtual int OnRspStrategySwitch(CFirstSetField *p_pFirstSet, CRspCosStrategySwitchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //���н����ղ�ѯ��Ӧ
  virtual int OnRspQrySettDate(CFirstSetField *p_pFirstSetField, CRspStkQrySettDateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ȡ��һ����������Ӧ
  virtual int OnRspQryTradeDate(CFirstSetField *p_pFirstSetField, CRspCosQryTradeDateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��Ȩ��ϱ�֤�����Ȩָ��ϲ�ί����Ӧ
  virtual int OnRspCombStraAndExerciseOrder(CFirstSetField *p_pFirstSetField, CRspCosCombStraAndExerciseOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��Ȩ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryOptInfo(CFirstSetField *p_pFirstSetField, CRspCosQryOptInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ڻ���Ϣ��ѯ��Ӧ
  virtual int OnRspQryFutInfo(CFirstSetField *p_pFirstSetField, CRspCosQryFutInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ֻ���Ȩ�ڻ���Ϣ��ѯ��Ӧ
  virtual int OnRspQryStkOptFutInfo(CFirstSetField *p_pFirstSetField, CRspCosQryStkOptFutInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //��ʷ��ί�в�ѯ��Ӧ
  virtual int OnRspQryHisSubOrder(CFirstSetField *p_pFirstSetField, CRspCosQryHisSubOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ɱ���Ǩ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryChgShareCapital(CFirstSetField *p_pFirstSetField, CRspCosQryChgShareCapitalField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����ʱ��Ƭ��ѯ��Ӧ
  virtual int OnRspQryTrdTimeSlice(CFirstSetField *p_pFirstSetField, CRspCosQryTrdTimeSliceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����������Ӧ
  virtual int OnRspStrategyExtension(CFirstSetField *p_pFirstSetField, CRspCosStrategyExtensionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�в�ѯ(ͨ��)��Ӧ
  virtual int OnRspQryStrategyOrder(CFirstSetField *p_pFirstSetField, CRspCosQryStrategyOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί���µ���Ӧ
  virtual int OnRspMarketOrder(CFirstSetField *p_pFirstSetField, CRspCosMarketOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����˫�߱�����Ӧ
  virtual int OnRspBilateralQuote(CFirstSetField *p_pFirstSetField, CRspCosBilateralQuoteField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
 };

class MATRADEAPI CCliCosTradeApi : virtual public CCliTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliCosTradeApi(void);
  // ��������
  virtual ~CCliCosTradeApi(void);
  
  //�û��ֻ���¼����
  virtual int ReqStkUserLogin(CReqStkUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  //�û����õ�¼����
  virtual int ReqFislUserLogin(CReqFislUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  //�û���Ȩ��¼����
  virtual int ReqOptUserLogin(CReqOptUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  //�û���Ȩ��¼����(��)
  virtual int ReqOptRpcUserLogin(CReqOptRpcUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  //�û��ڻ���¼����
  virtual int ReqFutureUserLogin(CReqFutureUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  //��ϵͳ��ѯ
  virtual int ReqQryConf(CReqCosConfField *p_pReqField, LONGLONG p_llRequestId);
  //��ϵͳ����
  virtual int ReqChgConf(CReqCosChgConfField *p_pReqField, LONGLONG p_llRequestId);
  //����ί��
  virtual int ReqOrder(CReqCosOrderField *p_pReqField, LONGLONG p_llRequestId);
  //ί�г���
  virtual int ReqCancelOrder(CReqCosCancelOrderField *p_pReqField, LONGLONG p_llRequestId);
  //ί�иĵ�
  virtual int ReqChgOrder(CReqCosChgOrderField *p_pReqField, LONGLONG p_llRequestId);
  //�������ί��
  virtual int ReqCombOrder(CReqCosCombOrderField *p_pReqField, LONGLONG p_llRequestId);
  //�ڵ���
  virtual int ReqChgNode(CReqCosChgNodeField *p_pReqField, LONGLONG p_llRequestId);
  //�ڵ�������
  virtual int ReqChgNodeOnline(CReqCosChgNodeOnlineField *p_pReqField, LONGLONG p_llRequestId);
  //����ί�в�ѯ
  virtual int ReqQryOrderInfo(CReqCosOrderInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ͻ����ڽڵ��Ų�ѯ
  virtual int ReqQryNodeInfo(CReqCosNodeInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ڵ�Ŀͻ���ѯ
  virtual int ReqQryNodeCustInfo(CReqCosNodeCustInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ӿ����ò�ѯ
  virtual int ReqQryItfInfo(CReqCosItfInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ӿ�����
  virtual int ReqChgItf(CReqCosChgItfField *p_pReqField, LONGLONG p_llRequestId);
  //�����ɳ���ί�в�ѯ
  virtual int ReqQryCanWithdrawOrder(CReqCosCanWithdrawOrderField *p_pReqField, LONGLONG p_llRequestId);
  //�����ɽ���ѯ
  virtual int ReqQryMatch(CReqCosMatchField *p_pReqField, LONGLONG p_llRequestId);
  //������ί�в�ѯ
  virtual int ReqQrySubOrder(CReqCosSubOrderField *p_pReqField, LONGLONG p_llRequestId);
  //��ʷί�в�ѯ
  virtual int ReqQryHisOrderInfo(CReqCosHisOrderInfoField *p_pReqField, LONGLONG p_llRequestId);
  //��ʷ�ɽ���ѯ
  virtual int ReqQryHisFillInfo(CReqCosHisFillInfoField *p_pReqField, LONGLONG p_llRequestId);
  //���ί�в�ѯ
  virtual int ReqQryCombOrderInfo(CReqCosCombOrderInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ʲ��û���ѯ
  virtual int ReqQryCuacctCodeInfo(CReqCosCuacctCodeInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�ڵ��˻���ѯ
  virtual int ReqQryNodeUsers(CReqCosNodeUsersField *p_pReqField, LONGLONG p_llRequestId);
  //�������ί�б�Ų�ѯ���ί��
  virtual int ReqQryCombOrderInfoEx(CReqCosCombOrderInfoExField *p_pReqField, LONGLONG p_llRequestId);
  //���鴦�����
  virtual int ReqSnapshot(CReqCosSnapshotField *p_pReqField, LONGLONG p_llRequestId);
  //����طŹ���
  virtual int ReqReplay(CReqCosReplayField *p_pReqField, LONGLONG p_llRequestId);
  //��������ѯί��
  virtual int ReqQryMktDataInfo(CReqCosMktDataInfoField *p_pReqField, LONGLONG p_llRequestId);
  //�����¼����
  virtual int ReqRecordMktData(CReqCosRecordMktDataField *p_pReqField, LONGLONG p_llRequestId);
  //����طŽ��Ȳ�ѯ
  virtual int ReqQryReplayInfo(CReqCosReplayInfoField *p_pReqField, LONGLONG p_llRequestId);
  //��ʷ�����ѯί��
  virtual int ReqQryHisMktData(CReqCosHisMktDataField *p_pReqField, LONGLONG p_llRequestId);
  //����ͬ��
  virtual int ReqSync(CReqCosSyncField *p_pReqField, LONGLONG p_llRequestId);
  //�ʲ��˻�����
  virtual int ReqOpenAccount(CReqCosOpenAccountField *p_pReqField, LONGLONG p_llRequestId);
  //�ʲ��˻�����
  virtual int ReqCloseAccount(CReqCosCloseAccountField *p_pReqField, LONGLONG p_llRequestId);
  //�ʽ�ͬ��
  virtual int ReqFundSync(CReqCosFundSyncField *p_pReqField, LONGLONG p_llRequestId);
  //�ɷ�ͬ��
  virtual int ReqStkSync(CReqCosStkSyncField *p_pReqField, LONGLONG p_llRequestId);
  //��������
  virtual int ReqCutoff(CReqCosCutoffField *p_pReqField, LONGLONG p_llRequestId);
  // �����ʽ��ѯ����
  virtual int ReqQryExpendableFund(CReqStkQryExpendableFundField *p_pReqField, LONGLONG p_llRequestId);
  // ���ùɷݲ�ѯ����
  virtual int ReqQryExpendableShares(CReqStkQryExpendableSharesField *p_pReqField, LONGLONG p_llRequestId);

  //////////////////////////////////////////////////////////////////////////////////////////////
  //�ڲ��ӿڹ���
  //�ɽ��ر�����
  virtual int ReqMatchReport(CReqCosMatchReportField *p_pReqField, LONGLONG p_llRequestId);
  //ί��Ӧ������
  virtual int ReqOrderAnswer(CReqCosOrderAnswerField *p_pReqField, LONGLONG p_llRequestId);
  
  //��ѡ�ɱ༭
  virtual int ReqPortfolio(CReqCosPortfolioField *p_pReqField, LONGLONG p_llRequestId);
  //��ѡ�ɲ�ѯ
  virtual int ReqQryPortfolioInfo(CReqCosPortfolioInfoField *p_pReqField, LONGLONG p_llRequestId);
  //ETF����ί��
  virtual int ReqEtfBasketOrder(CReqCosEtfBasketOrderField *p_pReqField, LONGLONG p_llRequestId);
  //�Զ�������ί��
  virtual int ReqCustomBasketOrder(CReqCosCustomBasketOrderField *p_pReqField, LONGLONG p_llRequestId);
  //֤ȯ��Ϣ��ѯ
  virtual int ReqQryStkInfo(CReqCosQryStkInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �㷨��ί������
  virtual int ReqOrderStrategy(CReqCosOrderStrategyField *p_pReqField, LONGLONG p_llRequestId);
  // ������ͣ����
  virtual int ReqStrategySwitch(CReqCosStrategySwitchField *p_pReqField, LONGLONG p_llRequestId);
  // ���н����ղ�ѯ����
  virtual int ReqQrySettDate(CReqStkQrySettDateField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ��һ������������
  virtual int ReqQryTradeDate(CReqCosQryTradeDateField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ȩ��ϱ�֤�����Ȩָ��ϲ�ί������
  virtual int ReqCombStraAndExerciseOrder(CReqCosCombStraAndExerciseOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ȩ��Ϣ��ѯ����
  virtual int ReqQryOptInfo(CReqCosQryOptInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ڻ���Ϣ��ѯ����
  virtual int ReqQryFutInfo(CReqCosQryFutInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����Ʒ����Ϣ��ѯ[����]����
  virtual int ReqQryStkOptFutInfo(CReqCosQryStkOptFutInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷ��ί�в�ѯ����
  virtual int ReqQryHisSubOrder(CReqCosQryHisSubOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �ɱ���Ǩ��Ϣ��ѯ����
  virtual int ReqQryChgShareCapital(CReqCosQryChgShareCapitalField *p_pReqField, LONGLONG p_llRequestId);
  // ����ʱ��Ƭ��ѯ����
  virtual int ReqQryTrdTimeSlice(CReqCosQryTrdTimeSliceField *p_pReqField, LONGLONG p_llRequestId);
  // ������������
  virtual int ReqStrategyExtension(CReqCosStrategyExtensionField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�в�ѯ(ͨ��)����
  virtual int ReqQryStrategyOrder(CReqCosQryStrategyOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί���µ�����
  virtual int ReqMarketOrder(CReqCosMarketOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ����˫�߱�������
  virtual int ReqBilateralQuote(CReqCosBilateralQuoteField *p_pReqField, LONGLONG p_llRequestId);

public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);
  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

private:
  // �û��ֻ���¼������Ӧ
  void OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û����õ�¼������Ӧ
  void OnRspFislUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û���Ȩ��¼������Ӧ
  void OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û���Ȩ��¼����(��)��Ӧ
  void OnRspOptRpcUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û��ڻ���¼������Ӧ
  void OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //��ϵͳ��ѯ
  void OnRspQryConf(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��ϵͳ����
  void OnRspChgConf(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //����ί��
  void OnRspOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��������
  void OnRspCancelOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //ί�иĵ�
  void OnRspChgOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //���ί��
  void OnRspCombOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ڵ���
  void OnRspChgNode(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ڵ�������
  void OnRspChgNodeOnline(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //����ί�в�ѯ
  void OnRspQryOrderInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ͻ����ڽڵ��Ų�ѯ
  void OnRspQryNodeInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ڵ�Ŀͻ���ѯ
  void OnRspQryNodeCustInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ӿ����ò�ѯ
  void OnRspQryItfInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ӿ���������
  void OnRspChgItf(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�����ɳ���ί�в�ѯ
  void OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�����ɽ���ѯ
  void OnRspQryMatch(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //������ί�в�ѯ
  void OnRspQrySubOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��ʷί�в�ѯ
  void OnRspQryHisOrderInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��ʷ�ɽ���ѯ
  void OnRspQryHisFillInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //���ί�в�ѯ
  void OnRspQryCombOrderInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ʲ��û���ѯ
  void OnRspQryCuacctCodeInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ڵ��˻���ѯ
  void OnRspQryNodeUsers(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�������ί�б�Ų�ѯ���ί��
  void OnRspQryCombOrderInfoEx(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //���鴦�����
  void OnRspSnapshot(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //����طŹ���
  void OnRspReplay(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��������ѯί��
  void OnRspQryMktDataInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�����¼����
  void OnRspRecordMktData(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //����طŽ��Ȳ�ѯ
  void OnRspQryReplayInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��ʷ�����ѯί��
  void OnRspQryHisMktData(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //����ͬ��
  void OnRspSync(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ʲ��˻�����
  void OnRspOpenAccount(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ʲ��˻�����
  void OnRspCloseAccount(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ʽ�ͬ��
  void OnRspFundSync(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�ɷ�ͬ��
  void OnRspStkSync(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��������
  void OnRspCutoff(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ʽ��ѯ��Ӧ
  void OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ùɷݲ�ѯ��Ӧ
  void OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  /////////////////////////////////////////////////////////////////////////
  //�ڲ��ӿڹ���
  //�ɽ��ر�����
  void OnRspMatchReport(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //ί��Ӧ������
  void OnRspOrderAnswer(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  
  //��ѡ�ɱ༭
  void OnRspPortfolio(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //��ѡ�ɲ�ѯ
  void OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //ETF����ί��
  void OnRspEtfBasketOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //�Զ�������ί��
  void OnRspCustomBasketOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  //֤ȯ��Ϣ��ѯ
  void OnRspQryStkInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  // �㷨��ί����Ӧ
  void OnRspOrderStrategy(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ͣ��Ӧ
  void OnRspStrategySwitch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���н����ղ�ѯ��Ӧ
  void OnRspQrySettDate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ��һ����������Ӧ
  void OnRspQryTradeDate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ȩ��ϱ�֤�����Ȩָ��ϲ�ί����Ӧ
  void OnRspCombStraAndExerciseOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ȩ��Ϣ��ѯ����
  void OnRspQryOptInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ڻ���Ϣ��ѯ����
  void OnRspQryFutInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ֻ���Ȩ�ڻ���Ϣ��ѯ����
  void OnRspQryStkOptFutInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷ��ί�в�ѯ����
  void OnRspQryHisSubOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɱ���Ǩ��Ϣ��ѯ����
  void OnRspQryChgShareCapital(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ʱ��Ƭ��ѯ����
  void OnRspQryTrdTimeSlice(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����������Ӧ
  void OnRspStrategyExtension(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�в�ѯ(ͨ��)��Ӧ
  void OnRspQryStrategyOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί���µ���Ӧ
  void OnRspMarketOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����˫�߱�����Ӧ
  void OnRspBilateralQuote(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

};

END_NAMESPACE_MACLI
#endif //__MA_CLI_COS_TRADE_API_H__