#if !defined(__MA_CLI_STK_TRADE_API_H__)
#define __MA_CLI_STK_TRADE_API_H__

#include "maCliTradeApi.h"
#include "maCliStkTradeApiStruct.h"

BGN_NAMESPACE_MACLI

class MATRADEAPI CCliStkTradeSpi : virtual public CCliTradeSpi
{
public:
  // ֤ȯ��Ϣ��ѯ��Ӧ[����]
  virtual int OnRspQryStkInfoEx(CFirstSetField *p_pFirstSetField, CRspStkQryInfoExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ֤ȯ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryStkInfo(CFirstSetField *p_pFirstSetField, CRspStkQryStkInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �̺������ѯ(�Ϻ��ƴ���)��Ӧ
  virtual int OnRspQryClosingMkt(CFirstSetField *p_pFirstSetField, CRspStkQryClosingMktField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // LOF��Ϣ��ѯ
  virtual int OnRspQryLofInfo(CFirstSetField *p_pFirstSetField, CRspStkQryLofInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ETF��Ϣ��ѯ
  virtual int OnRspQryEtfInfo(CFirstSetField *p_pFirstSetField, CRspStkQryEtfInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ETF����Ϣ��ѯ
  virtual int OnRspQryEtfBasket(CFirstSetField *p_pFirstSetField, CRspStkQryEtfBasketField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί����Ӧ
  virtual int OnRspOrder(CFirstSetField *p_pFirstSetField, CRspStkOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ί����Ӧ
  virtual int OnRspCombOrder(CFirstSetField *p_pFirstSetField, CRspStkCombOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ί�г�����Ӧ
  virtual int OnRspCancelOrder(CFirstSetField *p_pFirstSetField, CRspStkCancelOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ɽ�����������Ӧ
  virtual int OnRspMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspStkMaxTradeQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί����Ӧ
  virtual int OnRspQuantityOrder(CFirstSetField *p_pFirstSetField, CRspStkQuantityOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����������Ӧ
  virtual int OnRspQuantityCancelOrder(CFirstSetField *p_pFirstSetField, CRspStkQuantityCancelOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί����Ӧ(����)
  virtual int OnRspOrderFlash(CFirstSetField *p_pFirstSetField, CRspStkOrderFlashField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ί�г�����Ӧ(����)
  virtual int OnRspCancelOrderFlash(CFirstSetField *p_pFirstSetField, CRspStkCancelOrderFlashField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ί����Ӧ(����)
  virtual int OnRspCombOrderFlash(CFirstSetField *p_pFirstSetField, CRspStkCombOrderFlashField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ETF ����ί����Ӧ
  virtual int OnRspEtfOrder(CFirstSetField *p_pFirstSetField, CRspStkEtfOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί�����ɽ�����������Ӧ
  virtual int OnRspEtfMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspStkEtfMaxTradeQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ
  virtual int OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableFundField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ(��ϯ����)
  virtual int OnRspQryExpendableFundCiXi(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableFundCiXiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ùɷݲ�ѯ��Ӧ
  virtual int OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableSharesField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί�в�ѯ��Ӧ
  virtual int OnRspQryCurrDayOrder(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ճɽ���ѯ��Ӧ
  virtual int OnRspQryCurrDayFill(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayFillField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɶ��˻���ѯ��Ӧ
  virtual int OnRspQryStkholderAcct(CFirstSetField *p_pFirstSetField, CRspStkQryStkholderAcctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɳ���ί�в�ѯ��Ӧ
  virtual int OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSetField, CRspStkQryCanWithdrawOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ[����]
  virtual int OnRspQryExpendableFundEx(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableFundExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ùɷݲ�ѯ��Ӧ[����]
  virtual int OnRspQryExpendableSharesEx(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableSharesExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί�в�ѯ��Ӧ[����]
  virtual int OnRspQryCurrDayOrderEx(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayOrderExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ճɽ���ѯ��Ӧ[����]
  virtual int OnRspQryCurrDayFillEx(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayFillExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɶ��˻���ѯ��Ӧ[����]
  virtual int OnRspQryStkholderAcctEx(CFirstSetField *p_pFirstSetField, CRspStkQryStkholderAcctExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɳ���ί�в�ѯ��Ӧ[����]
  virtual int OnRspQryCanWithdrawOrderEx(CFirstSetField *p_pFirstSetField, CRspStkQryCanWithdrawOrderExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ETF �ɷֹɳֲֲ�ѯ��Ӧ
  virtual int OnRspQryEtfCotPosition(CFirstSetField *p_pFirstSetField, CRspStkQryEtfCotPositionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ������Ϣ��ѯ��Ӧ
  virtual int OnRspQryRateInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRateInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ�г�״̬��Ϣ��ѯ��Ӧ
  virtual int OnRspQryMktStatusInfo(CFirstSetField *p_pFirstSetField, CRspStkQryMktStatusInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ���֤ȯ״̬��ѯ��Ӧ
  virtual int OnRspQryUndlStkStatus(CFirstSetField *p_pFirstSetField, CRspStkQryUndlStkStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ�����ʽ�̨�˲�ѯ��Ӧ
  virtual int OnRspQryFundAcctLvlTwo(CFirstSetField *p_pFirstSetField, CRspStkQryFundAcctLvlTwoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ������С�۲��ѯ��Ӧ
  virtual int OnRspQryTradeMinSpread(CFirstSetField *p_pFirstSetField, CRspStkQryTradeMinSpreadField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �۹�ͨ�ͻ���ծ��ѯ��Ӧ
  //virtual int OnRspQryCustDebts(CFirstSetField *p_pFirstSetField, CRspStkQryCustDebtsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ع���Լ��ѯ��Ӧ
  virtual int OnRspQryRepchContract(CFirstSetField *p_pFirstSetField, CRspStkQryRepchContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ͻ��ʵ��Բ�ѯ��Ӧ
  virtual int OnRspQryCustAppropriate(CFirstSetField *p_pFirstSetField, CRspStkQryCustAppropriateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��Ʒ�ʵ��Բ�ѯ��Ӧ
  virtual int OnRspQryProdAppropriate(CFirstSetField *p_pFirstSetField, CRspStkQryProdAppropriateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ʵ���ƥ������Ӧ
  virtual int OnRspAppropriateCheck(CFirstSetField *p_pFirstSetField, CRspStkAppropriateCheckField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ʵ���ƥ������¼��Ӧ
  virtual int OnRspAppropriateResult(CFirstSetField *p_pFirstSetField, CRspStkAppropriateResultField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ع��ʽ�ռ��������ѯ��Ӧ
  virtual int OnRspQryRepchFund(CFirstSetField *p_pFirstSetField, CRspStkQryRepchFundField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �û���¼������Ӧ
  virtual int OnRspUserLogin(CFirstSetField *p_pFirstSetField, CRspStkUserLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ʷί�в�ѯ��Ӧ
  virtual int OnRspQryHisOrder(CFirstSetField *p_pFirstSetField, CRspStkQryHisOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ʷ�ɽ���ѯ��Ӧ
  virtual int OnRspQryHisFill(CFirstSetField *p_pFirstSetField, CRspStkQryHisFillField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����/��ʷί�в�ѯ��Ӧ
  virtual int OnRspQryCurrDayHisOrder(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayHisOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����/��ʷ�ɽ���ѯ��Ӧ
  virtual int OnRspQryCurrDayHisFill(CFirstSetField *p_pFirstSetField, CRspStkQryCurrDayHisFillField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ȷ�ϻر�
  virtual int OnRtnOrderConfirm(CRtnStkOrderConfirmField *p_pRtnField) {return 0;}

  // �ɽ��ر�
  virtual int OnRtnOrderFill(CRtnStkOrderFillField *p_pRtnField) {return 0;}

  // ����ɽ�����
  virtual int OnRtnOrderFill(CRtnStkPefEtfFillField *p_pRtnField) {return 0;}

  // ȷ�ϻر�(����)
  virtual int OnRtnOrderConfirmFlash(CRtnStkOrderConfirmFlashField *p_pRtnField) {return 0;}

  // �ɽ��ر�(����)
  virtual int OnRtnOrderFillFlash(CRtnStkOrderFillFlashField *p_pRtnField) {return 0;}

  //ת������ҵ����Ϣ    2015/8/12
  virtual int OnRspQryBankTransBasicInfo(CFirstSetField *p_pFirstSetField, CRspStkBankTransBasicInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��֤ת��       2015/8/12
  virtual int OnRspBankStkTrans(CFirstSetField *p_pFirstSetField, CRspStkBankStkTransField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��ѯ�˻����   2015/8/12
  virtual int OnRspQryFundBala(CFirstSetField *p_pFirstSetField, CRspStkFundBalaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��֤ת�ʲ�ѯ   2015/8/12
  virtual int OnRspQryBankStkTrans(CFirstSetField *p_pFirstSetField, CRspStkBankStkTransInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //�޸Ľ�������   2015/8/12
  virtual int OnRspChgTrdPwd(CFirstSetField *p_pFirstSetField, CRspStkChgTrdPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //�޸��ʽ�����   2015/8/12
  virtual int OnRspChgFundPwd(CFirstSetField *p_pFirstSetField, CRspStkChgFundPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //���ʵ���ѯ     2015/8/12
  virtual int OnRspQryStatement(CFirstSetField *p_pFirstSetField, CRspStkStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //�ʽ𻮲�
  virtual int OnRspQryFundTransfer(CFirstSetField *p_pFirstSetField, CRspStkFundTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ֤ȯ��ֵ��Ȳ�ѯ��Ӧ
  virtual int OnRspQryMktQuota(CFirstSetField *p_pFirstSetField, CRspStkMktQuotaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��֤LOF��Ϣ��ѯ��Ӧ
  virtual int OnRspQryScLofInfo(CFirstSetField *p_pFirstSetField, CRspStkQryScLofInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ʷί����ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcHistoryOrderDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHistoryOrderDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷ�ɽ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcHistoryMatchDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHistoryMatchDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����¹��嵥��ѯ��Ӧ
  virtual int OnRspQryRpcIPO(CFirstSetField *p_pFirstSetField, CRspStkQryRpcIPOField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ�¹��깺��ֵ��ȱ���ѯ��Ӧ
  virtual int OnRspQryRpcIPOSubscriptionLimit(CFirstSetField *p_pFirstSetField, CRspStkQryRpcIPOSubscriptionLimitField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ų�ѯ��Ӧ
  virtual int OnRspQryRpcDistribution(CFirstSetField *p_pFirstSetField, CRspStkQryRpcDistributionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ֵ������ǩ��ѯ��Ӧ
  virtual int OnRspQryRpcMktCapPlacing(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMktCapPlacingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ǩ��ʷ��ѯ��Ӧ
  virtual int OnRspQryRpcWinningHistory(CFirstSetField *p_pFirstSetField, CRspStkQryRpcWinningHistoryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ֵ���۽���˳���޸���Ӧ
  virtual int OnRspRpcChgMktCapDistDeliOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcChgMktCapDistDeliOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ѯ��Ӧ
  virtual int OnRspQryRpcDeliOrder(CFirstSetField *p_pFirstSetField, CRspStkQryRpcDeliOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ʲ�ѯ��Ӧ
  virtual int OnRspQryRpcChkAcct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcChkAcctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȡ��ͨת��(����)�˺Ų�ѯ��Ӧ
  virtual int OnRspQryRpcBankAcct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBankAcctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȡ��ͨ�ⲿ(����)�˺Ų�ѯ��Ӧ
  virtual int OnRspQryRpcOtherBankAcct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOtherBankAcctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ѯ��Ӧ
  virtual int OnRspQryRpcFund(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFundField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ʽ���ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcFundDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFundDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�л���(410514)��Ӧ
  virtual int OnRspQryRpcOrderSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrderSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ�����(410516)��Ӧ
  virtual int OnRspQryRpcMatchSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMatchSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ѯ��ǰϵͳ״̬��Ӧ
  virtual int OnRspQryRpcCurSysStat(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCurSysStatField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ�ֵ���Ϣ��Ӧ
  virtual int OnRspRpcDictInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcDictInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ��Ϣ��Ӧ
  virtual int OnRspRpcStkInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcStkInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ������Ϣ��Ӧ
  virtual int OnRspQryRpcOrgInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrgInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��֤ͨת������ҵ����Ϣ��Ӧ
  virtual int OnRspRpcBankStkTransferBankBizInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcBankStkTransferBankBizInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �û���½��Ӧ
  virtual int OnRspRpcLogin(CFirstSetField *p_pFirstSetField, CRspStkRpcLoginField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����ʲ���ѯ(��)��Ӧ
  virtual int OnRspQryRpcTotalAssets(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTotalAssetsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸���ϵ��ʽ�����Ͻ���ʹ�ã���Ӧ
  virtual int OnRspRpcChgContact(CFirstSetField *p_pFirstSetField, CRspStkRpcChgContactField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����ϲ�ѯ��Ӧ
  virtual int OnRspQryRpcCustInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ĳ�����ʽ��Ӧ
  virtual int OnRspRpcChgOperMode(CFirstSetField *p_pFirstSetField, CRspStkRpcChgOperModeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���ͨ�Ĳ�����ʽ��Ӧ
  virtual int OnRspQryRpcCustOperMode(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustOperModeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ŀͻ���ϵ����Ϣ��Ӧ
  virtual int OnRspRpcChgCustInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcChgCustInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ�����չ������Ӧ
  virtual int OnRspRpcSetCustAttrEx(CFirstSetField *p_pFirstSetField, CRspStkRpcSetCustAttrExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��������ǩ����Ӧ
  virtual int OnRspRpcSetDigitalSign(CFirstSetField *p_pFirstSetField, CRspStkRpcSetDigitalSignField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ�޸��ʽ��ʺ�Ȩ����Ӧ
  virtual int OnRspRpcChgCuacctPermission(CFirstSetField *p_pFirstSetField, CRspStkRpcChgCuacctPermissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ʺſ�ͨ�ʽ�Ȩ�޲�ѯ��Ӧ
  virtual int OnRspQryRpcCuacctPermission(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctPermissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ�ʺſ�ͨȨ�޲�ѯ��Ӧ
  virtual int OnRspQryRpcTrdacctPermission(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTrdacctPermissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�Ȩ����Ч����Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcCustPermissionValidPeriod(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustPermissionValidPeriodField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ����ͻ�Ȩ����Ӧ
  virtual int OnRspRpcActivateCustPermission(CFirstSetField *p_pFirstSetField, CRspStkRpcActivateCustPermissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����������Ѳ�ѯ��Ӧ
  virtual int OnRspQryRpcCustSpecialFee(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustSpecialFeeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // һ���Է���Ӷ����ȡ��Ӧ
  virtual int OnRspRpcOneTimeServiceCommission(CFirstSetField *p_pFirstSetField, CRspStkRpcOneTimeServiceCommissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // һ���Է���Ӷ�𳷵���Ӧ
  virtual int OnRspRpcCancelOneTimeServiceCommission(CFirstSetField *p_pFirstSetField, CRspStkRpcCancelOneTimeServiceCommissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �̶����޷���Ӷ�������Ӧ
  virtual int OnRspRpcFixedTermServiceCommission(CFirstSetField *p_pFirstSetField, CRspStkRpcFixedTermServiceCommissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �̶����޷���Ӷ���˿���Ӧ
  virtual int OnRspRpcFixedTermServiceCommissionRefund(CFirstSetField *p_pFirstSetField, CRspStkRpcFixedTermServiceCommissionRefundField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // һ���Է���Ӷ�����ò�ѯ��Ӧ
  virtual int OnRspQryRpcOneTimeServiceCommissionSetting(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOneTimeServiceCommissionSettingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // һ���Է���Ӷ����ȡ��ѯ��Ӧ
  virtual int OnRspQryRpcOneTimeServiceCommissions(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOneTimeServiceCommissionsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ��ѯ���������Ӧ
  virtual int OnRspQryRpcConsultationPaymentCategory(CFirstSetField *p_pFirstSetField, CRspStkQryRpcConsultationPaymentCategoryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ѯ���������Ӧ
  virtual int OnRspRpcAddConsultationPaymentCategory(CFirstSetField *p_pFirstSetField, CRspStkRpcAddConsultationPaymentCategoryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ά���ͻ�����״̬��Ӧ
  virtual int OnRspRpcMaintainCustSubStatus(CFirstSetField *p_pFirstSetField, CRspStkRpcMaintainCustSubStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�������ˮ��Ӧ
  virtual int OnRspQryRpcCustSubStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustSubStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�����������Ӧ
  virtual int OnRspRpcCustSubSetting(CFirstSetField *p_pFirstSetField, CRspStkRpcCustSubSettingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������շѽṹ��Ӧ
  virtual int OnRspRpcThirdPartyChargingStructure(CFirstSetField *p_pFirstSetField, CRspStkRpcThirdPartyChargingStructureField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Ͷ����ѯ��Ʒ���ñ�֤��֧����Ӧ
  virtual int OnRspRpcInvestmentAdvisoryProductFee(CFirstSetField *p_pFirstSetField, CRspStkRpcInvestmentAdvisoryProductFeeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����У����Ӧ
  virtual int OnRspRpcCuacctPwdCheck(CFirstSetField *p_pFirstSetField, CRspStkRpcCuacctPwdCheckField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ����ϲ�ѯ��Ӧ
  virtual int OnRspQryRpcCuacctInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȡ�ͻ����Ϻ˲�״̬��Ӧ
  virtual int OnRspRpcCustInfoCheck(CFirstSetField *p_pFirstSetField, CRspStkRpcCustInfoCheckField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ���¼У����Ϣ��Ӧ
  virtual int OnRspRpcSetLoginCheckMode(CFirstSetField *p_pFirstSetField, CRspStkRpcSetLoginCheckModeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ����Ϻ˲��ʶ��Ӧ
  virtual int OnRspRpcSetCustInfoCheckMode(CFirstSetField *p_pFirstSetField, CRspStkRpcSetCustInfoCheckModeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ���Ϣ״̬��Ӧ
  virtual int OnRspRpcSetCustMsgStatus(CFirstSetField *p_pFirstSetField, CRspStkRpcSetCustMsgStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���Ϣ������Ӧ
  virtual int OnRspQryRpcCustMsgService(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustMsgServiceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸�����������Ӧ
  virtual int OnRspRpcChgBankPwd(CFirstSetField *p_pFirstSetField, CRspStkRpcChgBankPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ�̨�ʼ�ת����Ӧ
  virtual int OnRspRpcTransferBetweenCuacct(CFirstSetField *p_pFirstSetField, CRspStkRpcTransferBetweenCuacctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ�ͻ������ʻ��ʽ�鼯��Ӧ
  virtual int OnRspRpcCuacctCashConcentration(CFirstSetField *p_pFirstSetField, CRspStkRpcCuacctCashConcentrationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡͬһ�ͻ�����̨�ʡ�ת��̨����Ӧ
  virtual int OnRspRpcCuacctInfo2(CFirstSetField *p_pFirstSetField, CRspStkRpcCuacctInfo2Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ȡ����ѯ��Ӧ
  virtual int OnRspQryRpcCuacctMaxDraw(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctMaxDrawField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ȡ�ʽ��ѯ��Ӧ
  virtual int OnRspQryRpcCuacctMaxDrawForTencentPay(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctMaxDrawForTencentPayField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ֤ȯ����ǰ���¼۵�,֧������������Ӧ
  virtual int OnRspRpcStkAvlAndLatestPrice(CFirstSetField *p_pFirstSetField, CRspStkRpcStkAvlAndLatestPriceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ���������,֧������������Ӧ
  virtual int OnRspRpcMaxStkQty(CFirstSetField *p_pFirstSetField, CRspStkRpcMaxStkQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί��ҵ��,֧������������Ӧ
  virtual int OnRspRpcOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����Ӧ
  virtual int OnRspRpcOrderCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcOrderCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����ѯ��Ӧ
  virtual int OnRspQryRpcOrderCancel(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrderCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���óɱ���Ӧ
  virtual int OnRspRpcResetCost(CFirstSetField *p_pFirstSetField, CRspStkRpcResetCostField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ӯ�����ü�����Ӧ
  virtual int OnRspRpcCalcFee(CFirstSetField *p_pFirstSetField, CRspStkRpcCalcFeeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί������ҵ��,֧���������ף�������Χ���ã���Ӧ
  virtual int OnRspRpcOrderForTencentPay(CFirstSetField *p_pFirstSetField, CRspStkRpcOrderForTencentPayField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʹܷݶ�ת��T+0ί����Ӧ
  virtual int OnRspRpcTransferCapitalManagementShare(CFirstSetField *p_pFirstSetField, CRspStkRpcTransferCapitalManagementShareField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������۽ɿ�, ֧������������Ӧ
  virtual int OnRspRpcCancelRation(CFirstSetField *p_pFirstSetField, CRspStkRpcCancelRationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������۽ɿ�, ֧������������Ӧ
  virtual int OnRspQryRpcCancelRation(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCancelRationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�ҡ�Ų�ѯ��Ӧ
  virtual int OnRspQryRpcCustLottery(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustLotteryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�����Χ�ⶳ��ǩԤ�����ʽ���Ӧ
  virtual int OnRspRpcUnfreezePreFrozenFunds(CFirstSetField *p_pFirstSetField, CRspStkRpcUnfreezePreFrozenFundsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ʒ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeProductInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeProductInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����Ѻ���֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeNegotiableSecurity(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeNegotiableSecurityField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���Ѻ��������ʲ�ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgePledgeConversionRate(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgePledgeConversionRateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���������Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeLoanQuota(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeLoanQuotaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����Ѻ֤ȯ�ֲֲ�ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeNegotiableSecurityPosi(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeNegotiableSecurityPosiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ɴ������ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeMaxLoanAmt(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeMaxLoanAmtField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����������Ӧ
  virtual int OnRspRpcStkPledgeLoanApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeLoanApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����������Ӧ
  virtual int OnRspRpcStkPledgeRepaymentApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeRepaymentApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����֤ȯ��Ѻ��������Ӧ
  virtual int OnRspRpcStkPledgeSupplementaryPledgeSecurityApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeSupplementaryPledgeSecurityApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լ����������������Ӧ
  virtual int OnRspRpcStkPledgeDeferredContractRepaymentApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeDeferredContractRepaymentApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լ�貹����Ѻ������ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeInsufficientPledge(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeInsufficientPledgeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ҵ�����������ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeBizApplicationStatus(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeBizApplicationStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����Լ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeLoanContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeLoanContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����Լ��Ѻ��ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeLoanContractPledgeDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeLoanContractPledgeDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ʊ��Ѻ����޸���Ӧ
  virtual int OnRspRpcStkPledgeChgStkPledgeQuota(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeChgStkPledgeQuotaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ֻ���������Ӧ
  virtual int OnRspRpcStkPledgePartialRepaymentApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgePartialRepaymentApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����˶�Ȳ�ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeLenderQuota(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeLenderQuotaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ��ԼΥԼ״̬Ϊ׷���ĺ�Լ��Ӧ
  virtual int OnRspQryRpcStkPledgeAdditionalMarginContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeAdditionalMarginContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ׷����Լ��Ҫ׷����������Ӧ
  virtual int OnRspQryRpcStkPledgeAdditionalMarginQty(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeAdditionalMarginQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����𳥻���Ӧ
  virtual int OnRspRpcStkPledgeLoanPrincipalRepayment(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeLoanPrincipalRepaymentField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ڻ����ʽ��ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgeAvailableQtyForRepayment(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgeAvailableQtyForRepaymentField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷݲ��ֽ����Ѻ������Ӧ
  virtual int OnRspRpcStkPledgePartialCancellationPledgeApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgePartialCancellationPledgeApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����Ի��������ʲ�ѯ��Ӧ
  virtual int OnRspQryRpcStkPledgePersonalizedInterestRate(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkPledgePersonalizedInterestRateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լ��Ϣ����������Ӧ
  virtual int OnRspRpcStkPledgeRepaymentContractInterestApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcStkPledgeRepaymentContractInterestApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Լ�����ؿͻ���Ȳ�ѯ��Ӧ
  virtual int OnRspQryRpcAgreementRepurchaseDebtContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcAgreementRepurchaseDebtContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Լ�����ؿͻ���Ȳ�ѯ��Ӧ
  virtual int OnRspQryRpcAgreementRepurchaseQuota(CFirstSetField *p_pFirstSetField, CRspStkQryRpcAgreementRepurchaseQuotaField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Լ�����س�ʼ������Ӧ
  virtual int OnRspRpcAgreementRepurchaseInitialTransaction(CFirstSetField *p_pFirstSetField, CRspStkRpcAgreementRepurchaseInitialTransactionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Լ�����ع��ؽ�����Ӧ
  virtual int OnRspRpcAgreementRepurchaseRepurchaseTransaction(CFirstSetField *p_pFirstSetField, CRspStkRpcAgreementRepurchaseRepurchaseTransactionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Լ���������ڹ���������Ӧ
  virtual int OnRspRpcAgreementRepurchaseDelayedRepurchaseApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcAgreementRepurchaseDelayedRepurchaseApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡȨ֤��Ϣ��Ӧ
  virtual int OnRspRpcWarrantInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcWarrantInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�������Ȩί��Ԥ������˰��ѯ��Ӧ
  virtual int OnRspQryRpcExpectedIncomeTax(CFirstSetField *p_pFirstSetField, CRspStkQryRpcExpectedIncomeTaxField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լ��ѯ(410983)��Ӧ
  virtual int OnRspQryRpcContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩί�в�ѯ(410989)��Ӧ
  virtual int OnRspQryRpcFinancingRightCommission(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingRightCommissionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ȩ������Ա��Ϣ��ѯ��410990����Ӧ
  virtual int OnRspQryRpcEquityIncentivePersonnelInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcEquityIncentivePersonnelInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩ������Ϣ��ѯ��410991����Ӧ
  virtual int OnRspQryRpcFinancingExerciseParams(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingExerciseParamsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩ�ʲ���ծ��ѯ��410992����Ӧ
  virtual int OnRspQryRpcFinancingExerciseAssetsLiability(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingExerciseAssetsLiabilityField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩ�ͻ������Ϣ��ѯ��410993����Ӧ
  virtual int OnRspQryRpcFinancingExerciseCustQuotaInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingExerciseCustQuotaInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֱ�ӻ���(410984)��Ӧ
  virtual int OnRspRpcDirectRepayment(CFirstSetField *p_pFirstSetField, CRspStkRpcDirectRepaymentField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩҵ��(410985)��Ӧ
  virtual int OnRspRpcFinancingExerciseBiz(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancingExerciseBizField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ������Ȩ��ί������(410986)��Ӧ
  virtual int OnRspRpcFinancingExerciseMaxOrderQty(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancingExerciseMaxOrderQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩί�г���(410987)��Ӧ
  virtual int OnRspRpcFinancingExerciseCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancingExerciseCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������Ȩ����֤ȯ��ѯ(410988)��Ӧ
  virtual int OnRspQryRpcFinancingExerciseGuaranteedSecurityInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingExerciseGuaranteedSecurityInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�ɷݹ��嵥��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcETFStkList(CFirstSetField *p_pFirstSetField, CRspStkQryRpcETFStkListField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�����Ϲ����루�ֽ��Ϲ�����Ʊ�Ϲ�����Ӧ
  virtual int OnRspRpcETFOfflineApplication(CFirstSetField *p_pFirstSetField, CRspStkRpcETFOfflineApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�����Ϲ����볷����Ӧ
  virtual int OnRspRpcETFOfflineApplicationCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcETFOfflineApplicationCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�����Ϲ������ѯ��Ӧ
  virtual int OnRspQryRpcETFOfflineApplication(CFirstSetField *p_pFirstSetField, CRspStkQryRpcETFOfflineApplicationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����LOF����ֲ�ϲ���Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcSzLOFFundSplitMerge(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzLOFFundSplitMergeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �Ϻ�LOF����ֲ�ϲ���Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcShLOFFundSplitMerge(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShLOFFundSplitMergeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �̺����ֲ�/�ϲ����������깺��õ��Ľ���ֵ��Ӧ
  virtual int OnRspRpcAfterCloseFundSplitMergeRecommendedValue(CFirstSetField *p_pFirstSetField, CRspStkRpcAfterCloseFundSplitMergeRecommendedValueField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���ծԤ���гֲ���ϸ��Ӧ
  virtual int OnRspQryRpcTreasuryBondsPreIssuePosi(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTreasuryBondsPreIssuePosiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���ծԤ����ƽ����ϸ��Ӧ
  virtual int OnRspQryRpcTreasuryBondsPreIssueClosePosi(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTreasuryBondsPreIssueClosePosiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���ծԤ����Ӧ����Լ����ϸ��Ӧ
  virtual int OnRspQryRpcTreasuryBondsPreIssuePerformanceBond(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTreasuryBondsPreIssuePerformanceBondField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͶƱ�ɶ������Ϣ��ѯ(440001)��Ӧ
  virtual int OnRspQryRpcNetworkVotingTrdacctsConferenceInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcNetworkVotingTrdacctsConferenceInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͶƱ�鰸��Ϣ��ѯ(440002)��Ӧ
  virtual int OnRspQryRpcNetworkVotingMotionInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcNetworkVotingMotionInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͶƱ�����ѯ(440003)��Ӧ
  virtual int OnRspQryRpcNetworkVotingResult(CFirstSetField *p_pFirstSetField, CRspStkQryRpcNetworkVotingResultField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͶƱ(440101)��Ӧ
  virtual int OnRspRpcNetworkVoting(CFirstSetField *p_pFirstSetField, CRspStkRpcNetworkVotingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͶƱί�в�ѯ(440103)��Ӧ
  virtual int OnRspQryRpcNetworkVoting(CFirstSetField *p_pFirstSetField, CRspStkQryRpcNetworkVotingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��׼ȯ���ܲ�ѯ��Ӧ
  virtual int OnRspQryRpcStdBondSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStdBondSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ѻ���׼ȯ��ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcPledgeBankStdBondDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcPledgeBankStdBondDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ع��ʽ�ռ��������ѯ��Ӧ
  virtual int OnRspQryRpcRepurchaseFundOccupancyDays(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRepurchaseFundOccupancyDaysField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // δ���ڻع���ѯ��Ӧ
  virtual int OnRspQryRpcUndueRepurchase(CFirstSetField *p_pFirstSetField, CRspStkQryRpcUndueRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����ʻع����ղ�ѯ��Ӧ
  virtual int OnRspQryRpcFinancingRepurchaseRisk(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancingRepurchaseRiskField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ����ۻع�Ʒ����Ϣ��Ӧ
  virtual int OnRspQryRpcShQuoteRepurchaseProductInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShQuoteRepurchaseProductInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ǰ������Ӧ
  virtual int OnRspRpcShQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, CRspStkRpcShQuoteRepurchaseAdvanceRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع�ԤԼ��Ӧ
  virtual int OnRspRpcShQuoteRepurchaseReservation(CFirstSetField *p_pFirstSetField, CRspStkRpcShQuoteRepurchaseReservationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع�ԤԼ��ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcShQuoteRepurchaseReservationStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShQuoteRepurchaseReservationStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�δ���ڵı��ۻع���Ϣ��Ӧ
  virtual int OnRspQryRpcShQuoteRepurchaseUndueRepurchase(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShQuoteRepurchaseUndueRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع���Ӧ��Ѻ����ϸ��Ӧ
  virtual int OnRspRpcShQuoteRepurchasePledgeDetail(CFirstSetField *p_pFirstSetField, CRspStkRpcShQuoteRepurchasePledgeDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �Ϻ����ۻع���Ȩ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcShQuoteRepurchasePledgeInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShQuoteRepurchasePledgeInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع�����ί�б�����Ȳ�ѯ��Ӧ
  virtual int OnRspQryRpcShQuoteRepurchaseBatchOrderRetentionLimit(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShQuoteRepurchaseBatchOrderRetentionLimitField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع�����ί�б������������Ӧ
  virtual int OnRspRpcShQuoteRepurchaseSetBatchOrderRetentionLimit(CFirstSetField *p_pFirstSetField, CRspStkRpcShQuoteRepurchaseSetBatchOrderRetentionLimitField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع���Ʒ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseAdvanceRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع�ԤԼ��Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseReservation(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseReservationField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع�ԤԼȡ����Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseReservationCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseReservationCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع�ԤԼִ����Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseReservationExecution(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseReservationExecutionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع���ǰ������Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseAdvanceRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع�ԤԼ��ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseReservationStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseReservationStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع���Լ����������Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseChgContractQty(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseChgContractQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع�չ��ȡ����Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseExtensionCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseExtensionCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ���ڿͻ�δ���ڵı��ۻع���Ϣ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseUndueRepurchase(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseUndueRepurchaseField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ���ڱ��ۻع���Ѻ��������Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchasePledgeConversionRate(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchasePledgeConversionRateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع��ֽ���Ѻ��ѯ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseCashPledge(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseCashPledgeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڱ��ۻع���Ȩ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseMortgage(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseMortgageField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ���ڱ��ۻع��ͻ��ض�������Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchaseSpecificOffer(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchaseSpecificOfferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�����Ͷ���ʵ�����Ϣά����Ӧ
  virtual int OnRspRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriateness(CFirstSetField *p_pFirstSetField, CRspStkRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriatenessField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ۻع���Ѻ���ѯ��Ӧ
  virtual int OnRspQryRpcSzQuoteRepurchasePledge(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzQuoteRepurchasePledgeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯЭ��ع�ί���걨��Ӧ
  virtual int OnRspRpcBondAgreementRepurchaseOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcBondAgreementRepurchaseOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯЭ��ع�ί�г����걨��Ӧ
  virtual int OnRspRpcBondAgreementRepurchaseCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcBondAgreementRepurchaseCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯЭ��ع�ί����ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcBondAgreementRepurchaseStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondAgreementRepurchaseStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯЭ��ع��ɽ���ѯ��Ӧ
  virtual int OnRspQryRpcBondAgreementRepurchaseMatch(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondAgreementRepurchaseMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯЭ��ع���Լ��ѯ��Ӧ
  virtual int OnRspQryRpcBondAgreementRepurchaseContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondAgreementRepurchaseContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������ί���걨��Ӧ
  virtual int OnRspRpcPwdServiceOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcPwdServiceOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɶ���ѯ����ѯ�ͻ���Ӧ�Ĺɶ�������Ӧ
  virtual int OnRspQryRpcTrdacct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTrdacctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ѯ(������ҵ��)��Ӧ
  virtual int OnRspQryRpcCuacct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʲ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcAssetDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcAssetDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcStkDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷݻ��ܲ�ѯ��Ӧ
  virtual int OnRspQryRpcStkSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ�ʽ��ʻ��ʽ������ѯ��Ӧ
  virtual int OnRspQryRpcCuacct2(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacct2Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�������Ӧ
  virtual int OnRspQryRpcTrdacct2(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTrdacct2Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�������Ӧ
  virtual int OnRspQryRpcTrdacct3(CFirstSetField *p_pFirstSetField, CRspStkQryRpcTrdacct3Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�в�ѯ��Ӧ
  virtual int OnRspQryRpcOrderDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrderDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�в�ѯ(������ҵ��)��Ӧ
  virtual int OnRspQryRpcOrder2(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrder2Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcMatchDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMatchDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ���ѯ(������ҵ��)��Ӧ
  virtual int OnRspQryRpcMatch(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ���ѯ��΢֤ȯר�ã���Ӧ
  virtual int OnRspQryRpcMatchForTencentPay(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMatchForTencentPayField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷί�л��ܲ�ѯ, ��֤ȯ���������������Ӧ
  virtual int OnRspQryRpcHisOrderSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHisOrderSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɽ����ܲ�ѯ, ��֤ȯ���������������Ӧ
  virtual int OnRspQryRpcHisMatchSummary(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHisMatchSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ѯ�����ݹ�̨��ͨ���ʵ�ժҪ���ô�ӡ��Ϣ��ӡ���ݡ�΢֤ȯר����Ӧ
  virtual int OnRspQryRpcDeliveryForTencentPay(CFirstSetField *p_pFirstSetField, CRspStkQryRpcDeliveryForTencentPayField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�л��ܲ�ѯ,ordergroup+stkcode+bsflag��Ӧ
  virtual int OnRspQryRpcOrderSummary2(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrderSummary2Field *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�������ѯ��Ӧ
  virtual int OnRspQryRpcOrg(CFirstSetField *p_pFirstSetField, CRspStkQryRpcOrgField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ����Ժ��ʽ��ʺ�������Ӧ
  virtual int OnRspQryRpcAcctInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcAcctInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���������ѯ��Ӧ
  virtual int OnRspQryRpcMktIntention(CFirstSetField *p_pFirstSetField, CRspStkQryRpcMktIntentionField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ��Ӧ
  virtual int OnRspQryRpcSeat(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSeatField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ʽ��˻���Ϣ��Ӧ
  virtual int OnRspQryRpcCuacctAcctInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCuacctAcctInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͨ�ɷ�����ѯ�����У���Ӧ
  virtual int OnRspQryRpcShNonCirculatingShareBalance(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShNonCirculatingShareBalanceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڷ���ͨ�ɷ�����ѯ��Ӧ
  virtual int OnRspQryRpcSzNonCirculatingShareBalance(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzNonCirculatingShareBalanceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ϣ������˰��ѯ��Ӧ
  virtual int OnRspQryRpcDividendWithholdingTax(CFirstSetField *p_pFirstSetField, CRspStkQryRpcDividendWithholdingTaxField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�����������Ӧ
  virtual int OnRspQryRpcCustOrg(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCustOrgField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ����ʽ��˺���Ӧ
  virtual int OnRspQryRpcDepositoryCuacct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcDepositoryCuacctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڻ�������ʧ�ܲ�ѯ��Ӧ
  virtual int OnRspQryRpcFloorFundRedemptionFailure(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFloorFundRedemptionFailureField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcBlacklistStk(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBlacklistStkField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڴ��ڽ��������ѯ��Ӧ
  virtual int OnRspQryRpcSzBlockTradingMkt(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzBlockTradingMktField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �Ϻ����ڽ��������ѯ��Ӧ
  virtual int OnRspQryRpcShBlockTradingMkt(CFirstSetField *p_pFirstSetField, CRspStkQryRpcShBlockTradingMktField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڳ��ڻ���ֺ췽ʽ��ѯ��Ӧ
  virtual int OnRspQryRpcSzFloorFundDividends(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSzFloorFundDividendsField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���޹ɶ����ֶ�Ȳ�ѯ��Ӧ
  virtual int OnRspQryRpcLimitedTrdacctReductionLimit(CFirstSetField *p_pFirstSetField, CRspStkQryRpcLimitedTrdacctReductionLimitField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ�ʽ��ʲ���ѯ��Ӧ
  virtual int OnRspQryRpcHkCuacct(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkCuacctField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ�ͻ���ծ��ѯ��Ӧ
  virtual int OnRspQryRpcHkLiability(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkLiabilityField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Ȩ���ѯ��Ӧ
  virtual int OnRspQryRpcHkEquity(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkEquityField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ����׼����Ӧ
  virtual int OnRspRpcHkPreparationForOpeningAccount(CFirstSetField *p_pFirstSetField, CRspStkRpcHkPreparationForOpeningAccountField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨδ������ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcHkUndeliveryDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkUndeliveryDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�֤ͨȯ��Ϸѽ�����ϸ��Ӧ
  virtual int OnRspRpcHkStkCombinationFeeDeliveryDetail(CFirstSetField *p_pFirstSetField, CRspStkRpcHkStkCombinationFeeDeliveryDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ�����ѯ��Ӧ
  virtual int OnRspQryRpcHkDelivery(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkDeliveryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ���ʵ���ѯ��Ӧ
  virtual int OnRspQryRpcHkStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ��С�۲��ѯ��Ӧ
  virtual int OnRspQryRpcHkMinSpread(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkMinSpreadField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ�ο����ʲ�ѯ��Ӧ
  virtual int OnRspQryRpcHkExchangeRate(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkExchangeRateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ�г�����״̬��ѯ��Ӧ
  virtual int OnRspQryRpcHkMarketStatus(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkMarketStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ���֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcHkUnderlyingSecurity(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkUnderlyingSecurityField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ����������ѯ��Ӧ
  virtual int OnRspQryRpcHkCalendar(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkCalendarField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨί������������Ӧ
  virtual int OnRspRpcHkOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcHkOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ����ί����Ӧ
  virtual int OnRspRpcHkCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcHkCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����ѯ��Ӧ
  virtual int OnRspQryRpcHkCancel(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ���ɽ���������ѯ��Ӧ
  virtual int OnRspQryRpcHkMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkMaxTradeQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ����ί����ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcHkOrderDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkOrderDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ���׳ɽ���ѯ��Ӧ
  virtual int OnRspQryRpcHkMatch(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ������ʷί�в�ѯ��Ӧ
  virtual int OnRspQryRpcHkHisOrder(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkHisOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �۹�ͨ���׳ɽ���ʷ��ѯ��Ӧ
  virtual int OnRspQryRpcHkHisMatch(CFirstSetField *p_pFirstSetField, CRspStkQryRpcHkHisMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��תϵͳ֤ȯί���걨��Ӧ
  virtual int OnRspRpcStkTranSysStkOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcStkTranSysStkOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��תϵͳЭ��ת�������ѯ��Ӧ
  virtual int OnRspQryRpcStkTranSysAgreementTransferMkt(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkTranSysAgreementTransferMktField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��תϵͳȡ���������,֧������������Ӧ
  virtual int OnRspRpcStkTranSysMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspStkRpcStkTranSysMaxTradeQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��תϵͳ����Ͷ���߲�ѯ��Ӧ
  virtual int OnRspQryRpcStkTranSysRestrictedInvestor(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkTranSysRestrictedInvestorField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ת�г�����ͨ�ɷ�����ѯ��Ӧ
  virtual int OnRspQryRpcStkTranSysNonCirculatingSharesBalance(CFirstSetField *p_pFirstSetField, CRspStkQryRpcStkTranSysNonCirculatingSharesBalanceField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨����ί����ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcFixedIncomeSysOrderDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFixedIncomeSysOrderDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨������ʷί����ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcFixedIncomeSysHisOrderDetail(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFixedIncomeSysHisOrderDetailField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨���׳ɽ���ѯ��Ӧ
  virtual int OnRspQryRpcFixedIncomeSysMatch(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFixedIncomeSysMatchField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨���ɽ���������ѯ��Ӧ
  virtual int OnRspQryRpcFixedIncomeSysMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFixedIncomeSysMaxTradeQtyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨ί������������Ӧ
  virtual int OnRspRpcFixedIncomeSysOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcFixedIncomeSysOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ƽ̨����ί����Ӧ
  virtual int OnRspRpcFixedIncomeSysCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcFixedIncomeSysCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����ѯ��Ӧ
  virtual int OnRspQryRpcFixedIncomeSysCancel(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFixedIncomeSysCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯ������Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcBondBasicInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondBasicInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨ծȯ�����ѯ��Ӧ
  virtual int OnRspQryRpcBondMkt(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondMktField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒ�ݶ�ת�ó�����Ӧ
  virtual int OnRspRpcFinancialProductShareTransferCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancialProductShareTransferCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒ�ݶ�ת��ҵ����Ӧ
  virtual int OnRspRpcFinancialProductShareTransfer(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancialProductShareTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒת����ϵ����Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcFinancialProductShareTransferContactInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancialProductShareTransferContactInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒ�ݶ�ת�÷��ü�����Ӧ
  virtual int OnRspRpcFinancialProductShareTransferFee(CFirstSetField *p_pFirstSetField, CRspStkRpcFinancialProductShareTransferFeeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨ծȯ������Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcBondParamInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondParamInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί����ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcBondIntentionOrderStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcBondIntentionOrderStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒ�����ѯ��Ӧ
  virtual int OnRspQryRpcFinancialProductMarket(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancialProductMarketField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��̨���Ʋ�Ʒί�в�ѯ��Ӧ
  virtual int OnRspQryRpcFinancialProductOrder(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFinancialProductOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ����ί����Χ�ӿ���Ӧ
  virtual int OnRspRpcRefinancingStkLendingOrder(CFirstSetField *p_pFirstSetField, CRspStkRpcRefinancingStkLendingOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ����ί�г�����Χ�ӿ���Ӧ
  virtual int OnRspRpcRefinancingStkLendingCancel(CFirstSetField *p_pFirstSetField, CRspStkRpcRefinancingStkLendingCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�в�ѯ��Χ�ӿ���Ӧ
  virtual int OnRspQryRpcRefinancingOrder(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ǰ������Χ�ӿ���Ӧ
  virtual int OnRspRpcRefinancingAdvanceRevert(CFirstSetField *p_pFirstSetField, CRspStkRpcRefinancingAdvanceRevertField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͬ��չ����Χ�ӿ���Ӧ
  virtual int OnRspRpcRefinancingExtentionApprove(CFirstSetField *p_pFirstSetField, CRspStkRpcRefinancingExtentionApproveField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ����ɳ���¼��ѯ��Χ�ӿ���Ӧ
  virtual int OnRspQryRpcRefinancingStkLendingCanWithdraw(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingStkLendingCanWithdrawField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ת��ȯδ�˽��Լ��ѯ��Χ�ӿ���Ӧ
  virtual int OnRspQryRpcRefinancingOpenContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingOpenContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɳ�����ȯ��ѯ��Χ�ӿ���Ӧ
  virtual int OnRspQryRpcRefinancingUnderlyingStkForLending(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingUnderlyingStkForLendingField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��������Ϣ��ѯ��Χ�ӿ���Ӧ
  virtual int OnRspQryRpcRefinancingLenderInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingLenderInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷ����ί�в�ѯ��Ӧ
  virtual int OnRspQryRpcRefinancingHisLendingOrder(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingHisLendingOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ�������˽��Լ��ѯ��Ӧ
  virtual int OnRspQryRpcRefinancingStkLendingClosedContract(CFirstSetField *p_pFirstSetField, CRspStkQryRpcRefinancingStkLendingClosedContractField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ���Ԥ����Ϣ��Ӧ
  virtual int OnRspQryRpcSysSecurityCustReservedInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSysSecurityCustReservedInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ�Ԥ����Ϣ��Ӧ
  virtual int OnRspRpcSysSecuritySetCustReservedInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecuritySetCustReservedInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͬ���ͻ���̬������Ӧ
  virtual int OnRspRpcSysSecuritySyncDynamicToken(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecuritySyncDynamicTokenField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�֤���ȡ�������Ӧ
  virtual int OnRspRpcSysSecurityCertificateRandomCode(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecurityCertificateRandomCodeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���̬����״̬������Ӧ
  virtual int OnRspRpcSysSecuritySetDynamicTokenStatus(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecuritySetDynamicTokenStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ȡһ���Զ�̬������Ӧ
  virtual int OnRspRpcSysSecurityOneTimeDynamicPwd(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecurityOneTimeDynamicPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���½����Ϣ������Ӧ
  virtual int OnRspRpcSysSecuritySetLoginBindingInfo(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecuritySetLoginBindingInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���½����Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcSysSecurityLoginBindingInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcSysSecurityLoginBindingInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // У��ͻ�����������Ӧ
  virtual int OnRspRpcSysSecurityVerifyTrdPwd(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecurityVerifyTrdPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ȡ�ֻ�һ���Զ�̬������Ӧ
  virtual int OnRspRpcSysSecurityMobileOneTimeDynamicPwd(CFirstSetField *p_pFirstSetField, CRspStkRpcSysSecurityMobileOneTimeDynamicPwdField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�ETF�����ɷֹɵĳֲ�������Ӧ
  virtual int OnRspQryRpcETFConstituentStkPosi(CFirstSetField *p_pFirstSetField, CRspStkQryRpcETFConstituentStkPosiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ͨ�ڵ��VIPϵͳ��֤ȯ������Ӧ
  virtual int OnRspRpcCommVIPStkTransfer(CFirstSetField *p_pFirstSetField, CRspStkRpcCommVIPStkTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ֽ��ʲ�ת������Ӧ
  virtual int OnRspRpcCashAssetBankTransfer(CFirstSetField *p_pFirstSetField, CRspStkRpcCashAssetBankTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ𻮲���ˮ��ѯ��Ӧ
  virtual int OnRspQryRpcCapitalTransferStatement(CFirstSetField *p_pFirstSetField, CRspStkQryRpcCapitalTransferStatementField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Vip�ͻ��ʽ��ʲ�ͬ������ѯ��Ӧ
  virtual int OnRspQryRpcVIPCuacctSyncTable(CFirstSetField *p_pFirstSetField, CRspStkQryRpcVIPCuacctSyncTableField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڲ�Ʒ�ʵ�����Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcFloorTradingProductAppropriatenessInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcFloorTradingProductAppropriatenessInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ��ʵ�����Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcAppropriatenessInfo(CFirstSetField *p_pFirstSetField, CRspStkQryRpcAppropriatenessInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ��볡�ڲ�Ʒ�ʵ���ƥ��У����Ӧ
  virtual int OnRspRpcAppropriatenessMatchingCheck(CFirstSetField *p_pFirstSetField, CRspStkRpcAppropriatenessMatchingCheckField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��¼����ҵ����ս�ʾ��ǩ����ˮ��Ӧ
  virtual int OnRspRpcFloorTradingRiskDisclosureStatementSignedRecordFlow(CFirstSetField *p_pFirstSetField, CRspStkRpcFloorTradingRiskDisclosureStatementSignedRecordFlowField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ϵͳ̽����Ӧ
  virtual int OnRspBizStatus(CFirstSetField *p_pFirstSetField, CRspStkBizStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)��Ӧ
  virtual int OnRspQryPledgeShares(CFirstSetField *p_pFirstSetField, CRspStkQryPledgeSharesField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ���ˮ��ѯ��Ӧ
  virtual int OnRspQryFundFlow(CFirstSetField *p_pFirstSetField, CRspStkQryFundFlowField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί��(����)��Ӧ
  virtual int OnRspOrderEx(CFirstSetField *p_pFirstSetField, CRspStkOrderExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷ���ˮ��ѯ��Ӧ
  virtual int OnRspQryStockFlow(CFirstSetField *p_pFirstSetField, CRspStkQryStockFlowField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���н����ղ�ѯ��Ӧ
  virtual int OnRspQrySettDate(CFirstSetField *p_pFirstSetField, CRspStkQrySettDateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �̺���������ѯ��Ӧ
  virtual int OnRspQryLofMktInfo(CFirstSetField *p_pFirstSetField, CRspStkQryLofMktInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ𻮲�(���н���)��Ӧ
  virtual int OnRspFundTransferJzjy(CFirstSetField *p_pFirstSetField, CRspStkFundTransferJzjyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ʽ��ѯ(���н���)��Ӧ
  virtual int OnRspQryExpendableFundJzjy(CFirstSetField *p_pFirstSetField, CRspStkQryExpendableFundJzjyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��֤��Ϣ����(����¼��/�޸�)��Ӧ
  virtual int OnRspAuthDataSetJzjy(CFirstSetField *p_pFirstSetField, CRspStkAuthDataSetJzjyField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮����Ӧ
  virtual int OnRspFundTransferNode(CFirstSetField *p_pFirstSetField, CRspStkFundTransferNodeField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮����Ӧ[��ϯ����]
  virtual int OnRspFundTransferNodeCiXi(CFirstSetField *p_pFirstSetField, CRspStkFundTransferNodeCiXiField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��֤ת����Ӧ
  virtual int OnRspBankStkTransfer(CFirstSetField *p_pFirstSetField, CRspStkBankStkTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ҪԼ�չ��չ�����Ϣ��ѯ��Ӧ
  virtual int OnRspQryTenderSgrInfo(CFirstSetField *p_pFirstSetField, CRspStkQryTenderSgrInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�����Ϲ����볷����Ӧ
  virtual int OnRspEtfOfflineCancelOrder(CFirstSetField *p_pFirstSetField, CRspStkEtfOfflineCancelOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ETF�����Ϲ������ѯ��Ӧ
  virtual int OnRspQryEtfOfflineOrder(CFirstSetField *p_pFirstSetField, CRspStkQryEtfOfflineOrderField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �¹�������ѯ��Ӧ
  virtual int OnRspQryNewStkCal(CFirstSetField *p_pFirstSetField, CRspStkQryNewStkCalField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ڴ�Ʒ����Ϣ��ѯ��Ӧ
  virtual int OnRspQryStkInfoShm(CFirstSetField *p_pFirstSetField, CRspStkQryStkInfoShmField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯ����ҵ��ԤԼί�г�����Ӧ
  virtual int OnRspReserveOrderCancel(CFirstSetField *p_pFirstSetField, CRspStkReserveOrderCancelField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ծȯ���������ѯ��Ӧ
  virtual int OnRspQryBondQuote(CFirstSetField *p_pFirstSetField, CRspStkQryBondQuoteField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // Э�̳ɽ��ر�������Ϣ��ѯ��Ӧ
  virtual int OnRspQryReportMktInfo(CFirstSetField *p_pFirstSetField, CRspStkQryReportMktInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ծȯ��ȯ���׾���ԤԼί����Ϣ��ѯ��Ӧ
  virtual int OnRspQryCashBondReserveOrderInfo(CFirstSetField *p_pFirstSetField, CRspStkQryCashBondReserveOrderInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ί�л��ܲ�ѯ��Ӧ
  virtual int OnRspQryOrderSummary(CFirstSetField *p_pFirstSetField, CRspStkQryOrderSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ɹ����ܲ�ѯ��Ӧ
  virtual int OnRspQryMatchSummary(CFirstSetField *p_pFirstSetField, CRspStkQryMatchSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ�䶯���ܲ�ѯ��Ӧ
  virtual int OnRspQryFundEffectSummary(CFirstSetField *p_pFirstSetField, CRspStkQryFundEffectSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // �ɷݱ䶯���ܲ�ѯ��Ӧ
  virtual int OnRspQryStockEffectSummary(CFirstSetField *p_pFirstSetField, CRspStkQryStockEffectSummaryField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  //ծȯ��ȯ���׾���ԤԼ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryCashBondTradeReservationInfo(CFirstSetField *p_pFirstSetField, CRspStkQryCashBondTradeReservationInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ծȯ��ȯ����ҵ��ο���Ϣ��ѯ��Ӧ
  virtual int OnRspQryCashBondTradeProfitInfo(CFirstSetField *p_pFirstSetField, CRspStkQryCashBondTradeProfitInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //ծȯͨ����Ѻʽ�ع�ҵ��ο���Ϣ��ѯ��Ӧ
  virtual int OnRspQryBondPledgeRepchProfitInfo(CFirstSetField *p_pFirstSetField, CRspStkQryBondPledgeRepchProfitInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ڽ���������Ϣ��ѯ��Ӧ
  virtual int OnRspQryBlockTradingMktInfo(CFirstSetField *p_pFirstSetField, CRspStkQryBlockTradingMktInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �̺����������Ϣ��ѯ��Ӧ
  virtual int OnRspQryClosingBlockTradingMktInfo(CFirstSetField *p_pFirstSetField, CRspStkQryClosingBlockTradingMktInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ҵ���̺󶨼������ѯ��Ӧ
  virtual int OnRspQryClosingMktSecondboard(CFirstSetField *p_pFirstSetField, CRspStkQryClosingMktSecondboardField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // REITs�����ǵ���״̬��ѯ��Ӧ
  virtual int OnRspQryPriceStatus(CFirstSetField *p_pFirstSetField, CRspStkQryPriceStatusField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // ģ��ͻ���¼��Ӧ
  virtual int OnRspUserLoginImpersonate(CFirstSetField *p_pFirstSetField, CRspStkUserLoginImpersonateField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // �ɷݻ�����Ӧ
  virtual int OnRspStockTransfer(CFirstSetField *p_pFirstSetField, CRspStkStockTransferField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // ETF�ͻ����Ӻ�ͬ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryEtfContractInfo(CFirstSetField *p_pFirstSetField, CRspStkQryEtfContractInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // �Ϻ����ֹɷݶ�Ȳ�ѯ��Ӧ
  virtual int OnRspQryReductLimitSh(CFirstSetField *p_pFirstSetField, CRspStkQryReductLimitShField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // ���ڼ��ֹɷݶ�Ȳ�ѯ��Ӧ
  virtual int OnRspQryReductLimitSz(CFirstSetField *p_pFirstSetField, CRspStkQryReductLimitSzField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
  // ��Ƶ�������Ʋ�����ѯ��Ӧ
  virtual int OnRspQryFreqTradeLmtParam(CFirstSetField* p_pFirstSetField, CRspStkQryFreqTradeLmtParamField* p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) { return 0; }
};

class MATRADEAPI CCliStkTradeApi : virtual public CCliTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliStkTradeApi(void);

  // ��������
  virtual ~CCliStkTradeApi(void);

  // ֤ȯ��Ϣ��ѯ����[����]
  virtual int ReqQryStkInfo(CReqStkQryInfoExField *p_pReqField, LONGLONG p_llRequestId);

  // ֤ȯ��Ϣ��ѯ����
  virtual int ReqQryStkInfo(CReqStkQryStkInfoField *p_pReqField, LONGLONG p_llRequestId);

  // �̺������ѯ(�Ϻ��ƴ���)����
  virtual int ReqQryClosingMkt(CReqStkQryClosingMktField *p_pReqField, LONGLONG p_llRequestId);

  // LOF��Ϣ��ѯ����
  virtual int ReqQryLofInfo(CReqStkQryLofInfoField *p_pReqField, LONGLONG p_llRequestId);

  // ETF��Ϣ��ѯ����
  virtual int ReqQryEtfInfo(CReqStkQryEtfInfoField *p_pReqField, LONGLONG p_llRequestId);

  // ETF����Ϣ��ѯ����
  virtual int ReqQryEtfBasket(CReqStkQryEtfBasketField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί������
  virtual int ReqOrder(CReqStkOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ���ί������
  virtual int ReqCombOrder(CReqStkCombOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ί�г�������
  virtual int ReqCancelOrder(CReqStkCancelOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ���ɽ�������������
  virtual int ReqMaxTradeQty(CReqStkMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί������
  virtual int ReqQuantityOrder(CReqStkQuantityOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ������������
  virtual int ReqQuantityCancelOrder(CReqStkQuantityCancelOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί������(����)
  virtual int ReqOrderFlash(CReqStkOrderFlashField *p_pReqField, LONGLONG p_llRequestId);

  // ί�г�������(����)
  virtual int ReqCancelOrderFlash(CReqStkCancelOrderFlashField *p_pReqField, LONGLONG p_llRequestId);

  // ���ί������(����)
  virtual int ReqCombOrderFlash(CReqStkCombOrderFlashField *p_pReqField, LONGLONG p_llRequestId);

  // ETF ����ί������
  virtual int ReqEtfOrder(CReqStkEtfOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί�����ɽ�������������
  virtual int ReqEtfMaxTradeQty(CReqStkEtfMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);

  // �����ʽ��ѯ����
  virtual int ReqQryExpendableFund(CReqStkQryExpendableFundField *p_pReqField, LONGLONG p_llRequestId);

  // �����ʽ��ѯ����(��ϯ����)
  // virtual int ReqQryExpendableFundCiXi(CReqStkQryExpendableFundCiXiField *p_pReqField, LONGLONG p_llRequestId);

  // ���ùɷݲ�ѯ����
  virtual int ReqQryExpendableShares(CReqStkQryExpendableSharesField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί�в�ѯ����
  virtual int ReqQryCurrDayOrder(CReqStkQryCurrDayOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ���ճɽ���ѯ����
  virtual int ReqQryCurrDayFill(CReqStkQryCurrDayFillField *p_pReqField, LONGLONG p_llRequestId);

  // �ɶ��˻���ѯ����
  virtual int ReqQryStkholderAcct(CReqStkQryStkholderAcctField *p_pReqField, LONGLONG p_llRequestId);

  // �ɳ���ί�в�ѯ����
  virtual int ReqQryCanWithdrawOrder(CReqStkQryCanWithdrawOrderField *p_pReqField, LONGLONG p_llRequestId);

  // �����ʽ��ѯ����[����]
  virtual int ReqQryExpendableFundEx(CReqStkQryExpendableFundExField *p_pReqField, LONGLONG p_llRequestId);

  // ���ùɷݲ�ѯ����[����]
  virtual int ReqQryExpendableSharesEx(CReqStkQryExpendableSharesExField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί�в�ѯ����[����]
  virtual int ReqQryCurrDayOrderEx(CReqStkQryCurrDayOrderExField *p_pReqField, LONGLONG p_llRequestId);

  // ���ճɽ���ѯ����[����]
  virtual int ReqQryCurrDayFillEx(CReqStkQryCurrDayFillExField *p_pReqField, LONGLONG p_llRequestId);

  // �ɶ��˻���ѯ����[����]
  virtual int ReqQryStkholderAcctEx(CReqStkQryStkholderAcctExField *p_pReqField, LONGLONG p_llRequestId);

  // �ɳ���ί�в�ѯ����[����]
  virtual int ReqQryCanWithdrawOrderEx(CReqStkQryCanWithdrawOrderExField *p_pReqField, LONGLONG p_llRequestId);

  // ETF �ɷֹɳֲֲ�ѯ����
  virtual int ReqQryEtfCotPosition(CReqStkQryEtfCotPositionField *p_pReqField, LONGLONG p_llRequestId);

  // �û���¼����
  virtual int ReqUserLogin(CReqStkUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // ��ʷί�в�ѯ����
  virtual int ReqStkQryHisOrder(CReqStkQryHisOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ��ʷ�ɽ���ѯ����
  virtual int ReqStkQryHisFill(CReqStkQryHisFillField *p_pReqField, LONGLONG p_llRequestId);

  // ����/��ʷί�в�ѯ����
  virtual int ReqStkQryCurrDayHisOrder(CReqStkQryCurrDayHisOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ����/��ʷ�ɽ���ѯ����
  virtual int ReqStkQryCurrDayHisFill(CReqStkQryCurrDayHisFillField *p_pReqField, LONGLONG p_llRequestId);

  //ת������ҵ����Ϣ 2015/8/12
  virtual int ReqQryBankTransBasicInfo(CReqStkBankTransBasicInfoField *p_pReqField, LONGLONG p_llRequestId);

  //��֤ת��       2015/8/12
  virtual int ReqBankStkTrans(CReqStkBankStkTransField *p_pReqField, LONGLONG p_llRequestId);

  //��ѯ�˻����   2015/8/12
  virtual int ReqQryFundBala(CReqStkFundBalaField *p_pReqField, LONGLONG p_llRequestId);

  //��֤ת�ʲ�ѯ   2015/8/12
  virtual int ReqQryBankStkTrans(CReqStkBankStkTransInfoField *p_pReqField, LONGLONG p_llRequestId);

  //�޸Ľ�������   2015/8/12
  virtual int ReqChgTrdPwd(CReqStkChgTrdPwdField *p_pReqField, LONGLONG p_llRequestId);

  //�޸��ʽ�����   2015/8/12
  virtual int ReqChgFundPwd(CReqStkChgFundPwdField *p_pReqField, LONGLONG p_llRequestId);

  //���ʵ���ѯ     2015/8/12
  virtual int ReqQryStatement(CReqStkStatementField *p_pReqField, LONGLONG p_llRequestId);

  //�ʽ𻮲�
  virtual int ReqQryFundTransfer(CReqStkFundTransferField *p_pReqField, LONGLONG p_llRequestId);

  // ֤ȯ��ֵ��Ȳ�ѯ
  virtual int ReqQryMktQuota(CReqStkMktQuotaField *p_pReqField, LONGLONG p_llRequestId);

  // �۹�ͨ������Ϣ��ѯ����
  virtual int ReqQryRateInfo(CReqStkQryRateInfoField *p_pReqField, LONGLONG p_llRequestId);

  // �۹�ͨ�г�״̬��Ϣ��ѯ����
  virtual int ReqQryMktStatusInfo(CReqStkQryMktStatusInfoField *p_pReqField, LONGLONG p_llRequestId);

  // �۹�ͨ���֤ȯ״̬��ѯ����
  virtual int ReqQryUndlStkStatus(CReqStkQryUndlStkStatusField *p_pReqField, LONGLONG p_llRequestId);

  // �۹�ͨ�����ʽ�̨�˲�ѯ����
  virtual int ReqQryFundAcctLvlTwo(CReqStkQryFundAcctLvlTwoField *p_pReqField, LONGLONG p_llRequestId);

  // �۹�ͨ������С�۲��ѯ����
  virtual int ReqQryTradeMinSpread(CReqStkQryTradeMinSpreadField *p_pReqField, LONGLONG p_llRequestId);

  // �ع���Լ��ѯ����
  virtual int ReqQryRepchContract(CReqStkQryRepchContractField *p_pReqField, LONGLONG p_llRequestId);

  // �ͻ��ʵ��Բ�ѯ
  virtual int ReqQryCustAppropriate(CReqStkQryCustAppropriateField *p_pReqField, LONGLONG p_llRequestId);

  // ��Ʒ�ʵ��Բ�ѯ
  virtual int ReqQryProdAppropriate(CReqStkQryProdAppropriateField *p_pReqField, LONGLONG p_llRequestId);

  // �ʵ���ƥ����
  virtual int ReqAppropriateCheck(CReqStkAppropriateCheckField *p_pReqField, LONGLONG p_llRequestId);

  // �ʵ���ƥ������¼
  virtual int ReqAppropriateResult(CReqStkAppropriateResultField *p_pReqField, LONGLONG p_llRequestId);

  // �ع��ʽ�ռ��������ѯ
  virtual int ReqQryRepchFund(CReqStkQryRepchFundField *p_pReqField, LONGLONG p_llRequestId);

  // ��֤LOF��Ϣ��ѯ
  virtual int ReqQryScLofInfo(CReqStkQryScLofInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷί����ϸ��ѯ����
  virtual int ReqQryRpcHistoryOrderDetail(CReqStkQryRpcHistoryOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷ�ɽ���ϸ��ѯ����
  virtual int ReqQryRpcHistoryMatchDetail(CReqStkQryRpcHistoryMatchDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �����¹��嵥��ѯ����
  virtual int ReqQryRpcIPO(CReqStkQryRpcIPOField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ�¹��깺��ֵ��ȱ���ѯ����
  virtual int ReqQryRpcIPOSubscriptionLimit(CReqStkQryRpcIPOSubscriptionLimitField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ų�ѯ����
  virtual int ReqQryRpcDistribution(CReqStkQryRpcDistributionField *p_pReqField, LONGLONG p_llRequestId);
  // ��ֵ������ǩ��ѯ����
  virtual int ReqQryRpcMktCapPlacing(CReqStkQryRpcMktCapPlacingField *p_pReqField, LONGLONG p_llRequestId);
  // ��ǩ��ʷ��ѯ����
  virtual int ReqQryRpcWinningHistory(CReqStkQryRpcWinningHistoryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ֵ���۽���˳���޸�����
  virtual int ReqRpcChgMktCapDistDeliOrder(CReqStkRpcChgMktCapDistDeliOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �����ѯ����
  virtual int ReqQryRpcDeliOrder(CReqStkQryRpcDeliOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ���ʲ�ѯ����
  virtual int ReqQryRpcChkAcct(CReqStkQryRpcChkAcctField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ��ͨת��(����)�˺Ų�ѯ����
  virtual int ReqQryRpcBankAcct(CReqStkQryRpcBankAcctField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ��ͨ�ⲿ(����)�˺Ų�ѯ����
  virtual int ReqQryRpcOtherBankAcct(CReqStkQryRpcOtherBankAcctField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ѯ����
  virtual int ReqQryRpcFund(CReqStkQryRpcFundField *p_pReqField, LONGLONG p_llRequestId);
  // �����ʽ���ˮ��ѯ����
  virtual int ReqQryRpcFundDetail(CReqStkQryRpcFundDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�л���(410514)����
  virtual int ReqQryRpcOrderSummary(CReqStkQryRpcOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ�����(410516)����
  virtual int ReqQryRpcMatchSummary(CReqStkQryRpcMatchSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ��ǰϵͳ״̬����
  virtual int ReqQryRpcCurSysStat(CReqStkQryRpcCurSysStatField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ�ֵ���Ϣ����
  virtual int ReqRpcDictInfo(CReqStkRpcDictInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ��Ϣ����
  virtual int ReqRpcStkInfo(CReqStkRpcStkInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ������Ϣ����
  virtual int ReqQryRpcOrgInfo(CReqStkQryRpcOrgInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��֤ͨת������ҵ����Ϣ����
  virtual int ReqRpcBankStkTransferBankBizInfo(CReqStkRpcBankStkTransferBankBizInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �û���½����
  virtual int ReqRpcLogin(CReqStkRpcLoginField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����ʲ���ѯ(��)����
  virtual int ReqQryRpcTotalAssets(CReqStkQryRpcTotalAssetsField *p_pReqField, LONGLONG p_llRequestId);
  // �޸���ϵ��ʽ�����Ͻ���ʹ�ã�����
  virtual int ReqRpcChgContact(CReqStkRpcChgContactField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����ϲ�ѯ����
  virtual int ReqQryRpcCustInfo(CReqStkQryRpcCustInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ĳ�����ʽ����
  virtual int ReqRpcChgOperMode(CReqStkRpcChgOperModeField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���ͨ�Ĳ�����ʽ����
  virtual int ReqQryRpcCustOperMode(CReqStkQryRpcCustOperModeField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ŀͻ���ϵ����Ϣ����
  virtual int ReqRpcChgCustInfo(CReqStkRpcChgCustInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ�����չ��������
  virtual int ReqRpcSetCustAttrEx(CReqStkRpcSetCustAttrExField *p_pReqField, LONGLONG p_llRequestId);
  // ��������ǩ������
  virtual int ReqRpcSetDigitalSign(CReqStkRpcSetDigitalSignField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ�޸��ʽ��ʺ�Ȩ������
  virtual int ReqRpcChgCuacctPermission(CReqStkRpcChgCuacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ʺſ�ͨ�ʽ�Ȩ�޲�ѯ����
  virtual int ReqQryRpcCuacctPermission(CReqStkQryRpcCuacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ�ʺſ�ͨȨ�޲�ѯ����
  virtual int ReqQryRpcTrdacctPermission(CReqStkQryRpcTrdacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�Ȩ����Ч����Ϣ��ѯ����
  virtual int ReqQryRpcCustPermissionValidPeriod(CReqStkQryRpcCustPermissionValidPeriodField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ����ͻ�Ȩ������
  virtual int ReqRpcActivateCustPermission(CReqStkRpcActivateCustPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����������Ѳ�ѯ����
  virtual int ReqQryRpcCustSpecialFee(CReqStkQryRpcCustSpecialFeeField *p_pReqField, LONGLONG p_llRequestId);
  // һ���Է���Ӷ����ȡ����
  virtual int ReqRpcOneTimeServiceCommission(CReqStkRpcOneTimeServiceCommissionField *p_pReqField, LONGLONG p_llRequestId);
  // һ���Է���Ӷ�𳷵�����
  virtual int ReqRpcCancelOneTimeServiceCommission(CReqStkRpcCancelOneTimeServiceCommissionField *p_pReqField, LONGLONG p_llRequestId);
  // �̶����޷���Ӷ���������
  virtual int ReqRpcFixedTermServiceCommission(CReqStkRpcFixedTermServiceCommissionField *p_pReqField, LONGLONG p_llRequestId);
  // �̶����޷���Ӷ���˿�����
  virtual int ReqRpcFixedTermServiceCommissionRefund(CReqStkRpcFixedTermServiceCommissionRefundField *p_pReqField, LONGLONG p_llRequestId);
  // һ���Է���Ӷ�����ò�ѯ����
  virtual int ReqQryRpcOneTimeServiceCommissionSetting(CReqStkQryRpcOneTimeServiceCommissionSettingField *p_pReqField, LONGLONG p_llRequestId);
  // һ���Է���Ӷ����ȡ��ѯ����
  virtual int ReqQryRpcOneTimeServiceCommissions(CReqStkQryRpcOneTimeServiceCommissionsField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ��ѯ�����������
  virtual int ReqQryRpcConsultationPaymentCategory(CReqStkQryRpcConsultationPaymentCategoryField *p_pReqField, LONGLONG p_llRequestId);
  // ������ѯ�����������
  virtual int ReqRpcAddConsultationPaymentCategory(CReqStkRpcAddConsultationPaymentCategoryField *p_pReqField, LONGLONG p_llRequestId);
  // ά���ͻ�����״̬����
  virtual int ReqRpcMaintainCustSubStatus(CReqStkRpcMaintainCustSubStatusField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�������ˮ����
  virtual int ReqQryRpcCustSubStatement(CReqStkQryRpcCustSubStatementField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�������������
  virtual int ReqRpcCustSubSetting(CReqStkRpcCustSubSettingField *p_pReqField, LONGLONG p_llRequestId);
  // �������շѽṹ����
  virtual int ReqRpcThirdPartyChargingStructure(CReqStkRpcThirdPartyChargingStructureField *p_pReqField, LONGLONG p_llRequestId);
  // Ͷ����ѯ��Ʒ���ñ�֤��֧������
  virtual int ReqRpcInvestmentAdvisoryProductFee(CReqStkRpcInvestmentAdvisoryProductFeeField *p_pReqField, LONGLONG p_llRequestId);
  // ����У������
  virtual int ReqRpcCuacctPwdCheck(CReqStkRpcCuacctPwdCheckField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ����ϲ�ѯ����
  virtual int ReqQryRpcCuacctInfo(CReqStkQryRpcCuacctInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ�ͻ����Ϻ˲�״̬����
  virtual int ReqRpcCustInfoCheck(CReqStkRpcCustInfoCheckField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ���¼У����Ϣ����
  virtual int ReqRpcSetLoginCheckMode(CReqStkRpcSetLoginCheckModeField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ����Ϻ˲��ʶ����
  virtual int ReqRpcSetCustInfoCheckMode(CReqStkRpcSetCustInfoCheckModeField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ���Ϣ״̬����
  virtual int ReqRpcSetCustMsgStatus(CReqStkRpcSetCustMsgStatusField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���Ϣ��������
  virtual int ReqQryRpcCustMsgService(CReqStkQryRpcCustMsgServiceField *p_pReqField, LONGLONG p_llRequestId);
  // �޸�������������
  virtual int ReqRpcChgBankPwd(CReqStkRpcChgBankPwdField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ�̨�ʼ�ת������
  virtual int ReqRpcTransferBetweenCuacct(CReqStkRpcTransferBetweenCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ�ͻ������ʻ��ʽ�鼯����
  virtual int ReqRpcCuacctCashConcentration(CReqStkRpcCuacctCashConcentrationField *p_pReqField, LONGLONG p_llRequestId);
  // ȡͬһ�ͻ�����̨�ʡ�ת��̨������
  virtual int ReqRpcCuacctInfo2(CReqStkRpcCuacctInfo2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ȡ����ѯ����
  virtual int ReqQryRpcCuacctMaxDraw(CReqStkQryRpcCuacctMaxDrawField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ȡ�ʽ��ѯ����
  virtual int ReqQryRpcCuacctMaxDrawForTencentPay(CReqStkQryRpcCuacctMaxDrawForTencentPayField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ֤ȯ����ǰ���¼۵�,֧��������������
  virtual int ReqRpcStkAvlAndLatestPrice(CReqStkRpcStkAvlAndLatestPriceField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ���������,֧��������������
  virtual int ReqRpcMaxStkQty(CReqStkRpcMaxStkQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί��ҵ��,֧��������������
  virtual int ReqRpcOrder(CReqStkRpcOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�������
  virtual int ReqRpcOrderCancel(CReqStkRpcOrderCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�����ѯ����
  virtual int ReqQryRpcOrderCancel(CReqStkQryRpcOrderCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ���óɱ�����
  virtual int ReqRpcResetCost(CReqStkRpcResetCostField *p_pReqField, LONGLONG p_llRequestId);
  // ӯ�����ü�������
  virtual int ReqRpcCalcFee(CReqStkRpcCalcFeeField *p_pReqField, LONGLONG p_llRequestId);
  // ί������ҵ��,֧���������ף�������Χ���ã�����
  virtual int ReqRpcOrderForTencentPay(CReqStkRpcOrderForTencentPayField *p_pReqField, LONGLONG p_llRequestId);
  // �ʹܷݶ�ת��T+0ί������
  virtual int ReqRpcTransferCapitalManagementShare(CReqStkRpcTransferCapitalManagementShareField *p_pReqField, LONGLONG p_llRequestId);
  // �������۽ɿ�, ֧��������������
  virtual int ReqRpcCancelRation(CReqStkRpcCancelRationField *p_pReqField, LONGLONG p_llRequestId);
  // �������۽ɿ�, ֧��������������
  virtual int ReqQryRpcCancelRation(CReqStkQryRpcCancelRationField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�ҡ�Ų�ѯ����
  virtual int ReqQryRpcCustLottery(CReqStkQryRpcCustLotteryField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�����Χ�ⶳ��ǩԤ�����ʽ�����
  virtual int ReqRpcUnfreezePreFrozenFunds(CReqStkRpcUnfreezePreFrozenFundsField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ʒ��Ϣ��ѯ����
  virtual int ReqQryRpcStkPledgeProductInfo(CReqStkQryRpcStkPledgeProductInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����Ѻ���֤ȯ��ѯ����
  virtual int ReqQryRpcStkPledgeNegotiableSecurity(CReqStkQryRpcStkPledgeNegotiableSecurityField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���Ѻ��������ʲ�ѯ����
  virtual int ReqQryRpcStkPledgePledgeConversionRate(CReqStkQryRpcStkPledgePledgeConversionRateField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���������Ϣ��ѯ����
  virtual int ReqQryRpcStkPledgeLoanQuota(CReqStkQryRpcStkPledgeLoanQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // ����Ѻ֤ȯ�ֲֲ�ѯ����
  virtual int ReqQryRpcStkPledgeNegotiableSecurityPosi(CReqStkQryRpcStkPledgeNegotiableSecurityPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ���ɴ������ѯ����
  virtual int ReqQryRpcStkPledgeMaxLoanAmt(CReqStkQryRpcStkPledgeMaxLoanAmtField *p_pReqField, LONGLONG p_llRequestId);
  // ������������
  virtual int ReqRpcStkPledgeLoanApplication(CReqStkRpcStkPledgeLoanApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ������������
  virtual int ReqRpcStkPledgeRepaymentApplication(CReqStkRpcStkPledgeRepaymentApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ����֤ȯ��Ѻ����������
  virtual int ReqRpcStkPledgeSupplementaryPledgeSecurityApplication(CReqStkRpcStkPledgeSupplementaryPledgeSecurityApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լ������������������
  virtual int ReqRpcStkPledgeDeferredContractRepaymentApplication(CReqStkRpcStkPledgeDeferredContractRepaymentApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լ�貹����Ѻ������ѯ����
  virtual int ReqQryRpcStkPledgeInsufficientPledge(CReqStkQryRpcStkPledgeInsufficientPledgeField *p_pReqField, LONGLONG p_llRequestId);
  // ҵ�����������ѯ����
  virtual int ReqQryRpcStkPledgeBizApplicationStatus(CReqStkQryRpcStkPledgeBizApplicationStatusField *p_pReqField, LONGLONG p_llRequestId);
  // �����Լ��ѯ����
  virtual int ReqQryRpcStkPledgeLoanContract(CReqStkQryRpcStkPledgeLoanContractField *p_pReqField, LONGLONG p_llRequestId);
  // �����Լ��Ѻ��ϸ��ѯ����
  virtual int ReqQryRpcStkPledgeLoanContractPledgeDetail(CReqStkQryRpcStkPledgeLoanContractPledgeDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ʊ��Ѻ����޸�����
  virtual int ReqRpcStkPledgeChgStkPledgeQuota(CReqStkRpcStkPledgeChgStkPledgeQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // ���ֻ�����������
  virtual int ReqRpcStkPledgePartialRepaymentApplication(CReqStkRpcStkPledgePartialRepaymentApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // �����˶�Ȳ�ѯ����
  virtual int ReqQryRpcStkPledgeLenderQuota(CReqStkQryRpcStkPledgeLenderQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ��ԼΥԼ״̬Ϊ׷���ĺ�Լ����
  virtual int ReqQryRpcStkPledgeAdditionalMarginContract(CReqStkQryRpcStkPledgeAdditionalMarginContractField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ׷����Լ��Ҫ׷������������
  virtual int ReqQryRpcStkPledgeAdditionalMarginQty(CReqStkQryRpcStkPledgeAdditionalMarginQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ����𳥻�����
  virtual int ReqRpcStkPledgeLoanPrincipalRepayment(CReqStkRpcStkPledgeLoanPrincipalRepaymentField *p_pReqField, LONGLONG p_llRequestId);
  // �����ڻ����ʽ��ѯ����
  virtual int ReqQryRpcStkPledgeAvailableQtyForRepayment(CReqStkQryRpcStkPledgeAvailableQtyForRepaymentField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷݲ��ֽ����Ѻ��������
  virtual int ReqRpcStkPledgePartialCancellationPledgeApplication(CReqStkRpcStkPledgePartialCancellationPledgeApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����Ի��������ʲ�ѯ����
  virtual int ReqQryRpcStkPledgePersonalizedInterestRate(CReqStkQryRpcStkPledgePersonalizedInterestRateField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լ��Ϣ������������
  virtual int ReqRpcStkPledgeRepaymentContractInterestApplication(CReqStkRpcStkPledgeRepaymentContractInterestApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // Լ�����ؿͻ���Ȳ�ѯ����
  virtual int ReqQryRpcAgreementRepurchaseDebtContract(CReqStkQryRpcAgreementRepurchaseDebtContractField *p_pReqField, LONGLONG p_llRequestId);
  // Լ�����ؿͻ���Ȳ�ѯ����
  virtual int ReqQryRpcAgreementRepurchaseQuota(CReqStkQryRpcAgreementRepurchaseQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // Լ�����س�ʼ��������
  virtual int ReqRpcAgreementRepurchaseInitialTransaction(CReqStkRpcAgreementRepurchaseInitialTransactionField *p_pReqField, LONGLONG p_llRequestId);
  // Լ�����ع��ؽ�������
  virtual int ReqRpcAgreementRepurchaseRepurchaseTransaction(CReqStkRpcAgreementRepurchaseRepurchaseTransactionField *p_pReqField, LONGLONG p_llRequestId);
  // Լ���������ڹ�����������
  virtual int ReqRpcAgreementRepurchaseDelayedRepurchaseApplication(CReqStkRpcAgreementRepurchaseDelayedRepurchaseApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ȡȨ֤��Ϣ����
  virtual int ReqRpcWarrantInfo(CReqStkRpcWarrantInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�������Ȩί��Ԥ������˰��ѯ����
  virtual int ReqQryRpcExpectedIncomeTax(CReqStkQryRpcExpectedIncomeTaxField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լ��ѯ(410983)����
  virtual int ReqQryRpcContract(CReqStkQryRpcContractField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩί�в�ѯ(410989)����
  virtual int ReqQryRpcFinancingRightCommission(CReqStkQryRpcFinancingRightCommissionField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ȩ������Ա��Ϣ��ѯ��410990������
  virtual int ReqQryRpcEquityIncentivePersonnelInfo(CReqStkQryRpcEquityIncentivePersonnelInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩ������Ϣ��ѯ��410991������
  virtual int ReqQryRpcFinancingExerciseParams(CReqStkQryRpcFinancingExerciseParamsField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩ�ʲ���ծ��ѯ��410992������
  virtual int ReqQryRpcFinancingExerciseAssetsLiability(CReqStkQryRpcFinancingExerciseAssetsLiabilityField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩ�ͻ������Ϣ��ѯ��410993������
  virtual int ReqQryRpcFinancingExerciseCustQuotaInfo(CReqStkQryRpcFinancingExerciseCustQuotaInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ֱ�ӻ���(410984)����
  virtual int ReqRpcDirectRepayment(CReqStkRpcDirectRepaymentField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩҵ��(410985)����
  virtual int ReqRpcFinancingExerciseBiz(CReqStkRpcFinancingExerciseBizField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ������Ȩ��ί������(410986)����
  virtual int ReqRpcFinancingExerciseMaxOrderQty(CReqStkRpcFinancingExerciseMaxOrderQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩί�г���(410987)����
  virtual int ReqRpcFinancingExerciseCancel(CReqStkRpcFinancingExerciseCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ������Ȩ����֤ȯ��ѯ(410988)����
  virtual int ReqQryRpcFinancingExerciseGuaranteedSecurityInfo(CReqStkQryRpcFinancingExerciseGuaranteedSecurityInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�ɷݹ��嵥��Ϣ��ѯ����
  virtual int ReqQryRpcETFStkList(CReqStkQryRpcETFStkListField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�����Ϲ����루�ֽ��Ϲ�����Ʊ�Ϲ�������
  virtual int ReqRpcETFOfflineApplication(CReqStkRpcETFOfflineApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�����Ϲ����볷������
  virtual int ReqRpcETFOfflineApplicationCancel(CReqStkRpcETFOfflineApplicationCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�����Ϲ������ѯ����
  virtual int ReqQryRpcETFOfflineApplication(CReqStkQryRpcETFOfflineApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ����LOF����ֲ�ϲ���Ϣ��ѯ����
  virtual int ReqQryRpcSzLOFFundSplitMerge(CReqStkQryRpcSzLOFFundSplitMergeField *p_pReqField, LONGLONG p_llRequestId);
  // �Ϻ�LOF����ֲ�ϲ���Ϣ��ѯ����
  virtual int ReqQryRpcShLOFFundSplitMerge(CReqStkQryRpcShLOFFundSplitMergeField *p_pReqField, LONGLONG p_llRequestId);
  // �̺����ֲ�/�ϲ����������깺��õ��Ľ���ֵ����
  virtual int ReqRpcAfterCloseFundSplitMergeRecommendedValue(CReqStkRpcAfterCloseFundSplitMergeRecommendedValueField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���ծԤ���гֲ���ϸ����
  virtual int ReqQryRpcTreasuryBondsPreIssuePosi(CReqStkQryRpcTreasuryBondsPreIssuePosiField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���ծԤ����ƽ����ϸ����
  virtual int ReqQryRpcTreasuryBondsPreIssueClosePosi(CReqStkQryRpcTreasuryBondsPreIssueClosePosiField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���ծԤ����Ӧ����Լ����ϸ����
  virtual int ReqQryRpcTreasuryBondsPreIssuePerformanceBond(CReqStkQryRpcTreasuryBondsPreIssuePerformanceBondField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͶƱ�ɶ������Ϣ��ѯ(440001)����
  virtual int ReqQryRpcNetworkVotingTrdacctsConferenceInfo(CReqStkQryRpcNetworkVotingTrdacctsConferenceInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͶƱ�鰸��Ϣ��ѯ(440002)����
  virtual int ReqQryRpcNetworkVotingMotionInfo(CReqStkQryRpcNetworkVotingMotionInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͶƱ�����ѯ(440003)����
  virtual int ReqQryRpcNetworkVotingResult(CReqStkQryRpcNetworkVotingResultField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͶƱ(440101)����
  virtual int ReqRpcNetworkVoting(CReqStkRpcNetworkVotingField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͶƱί�в�ѯ(440103)����
  virtual int ReqQryRpcNetworkVoting(CReqStkQryRpcNetworkVotingField *p_pReqField, LONGLONG p_llRequestId);
  // ��׼ȯ���ܲ�ѯ����
  virtual int ReqQryRpcStdBondSummary(CReqStkQryRpcStdBondSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ѻ���׼ȯ��ϸ��ѯ����
  virtual int ReqQryRpcPledgeBankStdBondDetail(CReqStkQryRpcPledgeBankStdBondDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ع��ʽ�ռ��������ѯ����
  virtual int ReqQryRpcRepurchaseFundOccupancyDays(CReqStkQryRpcRepurchaseFundOccupancyDaysField *p_pReqField, LONGLONG p_llRequestId);
  // δ���ڻع���ѯ����
  virtual int ReqQryRpcUndueRepurchase(CReqStkQryRpcUndueRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����ʻع����ղ�ѯ����
  virtual int ReqQryRpcFinancingRepurchaseRisk(CReqStkQryRpcFinancingRepurchaseRiskField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ����ۻع�Ʒ����Ϣ����
  virtual int ReqQryRpcShQuoteRepurchaseProductInfo(CReqStkQryRpcShQuoteRepurchaseProductInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ǰ��������
  virtual int ReqRpcShQuoteRepurchaseAdvanceRepurchase(CReqStkRpcShQuoteRepurchaseAdvanceRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع�ԤԼ����
  virtual int ReqRpcShQuoteRepurchaseReservation(CReqStkRpcShQuoteRepurchaseReservationField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع�ԤԼ��ˮ��ѯ����
  virtual int ReqQryRpcShQuoteRepurchaseReservationStatement(CReqStkQryRpcShQuoteRepurchaseReservationStatementField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�δ���ڵı��ۻع���Ϣ����
  virtual int ReqQryRpcShQuoteRepurchaseUndueRepurchase(CReqStkQryRpcShQuoteRepurchaseUndueRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع���Ӧ��Ѻ����ϸ����
  virtual int ReqRpcShQuoteRepurchasePledgeDetail(CReqStkRpcShQuoteRepurchasePledgeDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �Ϻ����ۻع���Ȩ��Ϣ��ѯ����
  virtual int ReqQryRpcShQuoteRepurchasePledgeInfo(CReqStkQryRpcShQuoteRepurchasePledgeInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع�����ί�б�����Ȳ�ѯ����
  virtual int ReqQryRpcShQuoteRepurchaseBatchOrderRetentionLimit(CReqStkQryRpcShQuoteRepurchaseBatchOrderRetentionLimitField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع�����ί�б��������������
  virtual int ReqRpcShQuoteRepurchaseSetBatchOrderRetentionLimit(CReqStkRpcShQuoteRepurchaseSetBatchOrderRetentionLimitField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع���Ʒ��Ϣ��ѯ����
  virtual int ReqQryRpcSzQuoteRepurchaseAdvanceRepurchase(CReqStkQryRpcSzQuoteRepurchaseAdvanceRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع�ԤԼ����
  virtual int ReqRpcSzQuoteRepurchaseReservation(CReqStkRpcSzQuoteRepurchaseReservationField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع�ԤԼȡ������
  virtual int ReqRpcSzQuoteRepurchaseReservationCancel(CReqStkRpcSzQuoteRepurchaseReservationCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع�ԤԼִ������
  virtual int ReqRpcSzQuoteRepurchaseReservationExecution(CReqStkRpcSzQuoteRepurchaseReservationExecutionField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع���ǰ��������
  virtual int ReqRpcSzQuoteRepurchaseAdvanceRepurchase(CReqStkRpcSzQuoteRepurchaseAdvanceRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع�ԤԼ��ˮ��ѯ����
  virtual int ReqQryRpcSzQuoteRepurchaseReservationStatement(CReqStkQryRpcSzQuoteRepurchaseReservationStatementField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع���Լ������������
  virtual int ReqRpcSzQuoteRepurchaseChgContractQty(CReqStkRpcSzQuoteRepurchaseChgContractQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع�չ��ȡ������
  virtual int ReqRpcSzQuoteRepurchaseExtensionCancel(CReqStkRpcSzQuoteRepurchaseExtensionCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ���ڿͻ�δ���ڵı��ۻع���Ϣ����
  virtual int ReqQryRpcSzQuoteRepurchaseUndueRepurchase(CReqStkQryRpcSzQuoteRepurchaseUndueRepurchaseField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ���ڱ��ۻع���Ѻ����������
  virtual int ReqQryRpcSzQuoteRepurchasePledgeConversionRate(CReqStkQryRpcSzQuoteRepurchasePledgeConversionRateField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع��ֽ���Ѻ��ѯ����
  virtual int ReqQryRpcSzQuoteRepurchaseCashPledge(CReqStkQryRpcSzQuoteRepurchaseCashPledgeField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڱ��ۻع���Ȩ��Ϣ��ѯ����
  virtual int ReqQryRpcSzQuoteRepurchaseMortgage(CReqStkQryRpcSzQuoteRepurchaseMortgageField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ���ڱ��ۻع��ͻ��ض���������
  virtual int ReqQryRpcSzQuoteRepurchaseSpecificOffer(CReqStkQryRpcSzQuoteRepurchaseSpecificOfferField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�����Ͷ���ʵ�����Ϣά������
  virtual int ReqRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriateness(CReqStkRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriatenessField *p_pReqField, LONGLONG p_llRequestId);
  // ���ۻع���Ѻ���ѯ����
  virtual int ReqQryRpcSzQuoteRepurchasePledge(CReqStkQryRpcSzQuoteRepurchasePledgeField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯЭ��ع�ί���걨����
  virtual int ReqRpcBondAgreementRepurchaseOrder(CReqStkRpcBondAgreementRepurchaseOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯЭ��ع�ί�г����걨����
  virtual int ReqRpcBondAgreementRepurchaseCancel(CReqStkRpcBondAgreementRepurchaseCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯЭ��ع�ί����ˮ��ѯ����
  virtual int ReqQryRpcBondAgreementRepurchaseStatement(CReqStkQryRpcBondAgreementRepurchaseStatementField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯЭ��ع��ɽ���ѯ����
  virtual int ReqQryRpcBondAgreementRepurchaseMatch(CReqStkQryRpcBondAgreementRepurchaseMatchField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯЭ��ع���Լ��ѯ����
  virtual int ReqQryRpcBondAgreementRepurchaseContract(CReqStkQryRpcBondAgreementRepurchaseContractField *p_pReqField, LONGLONG p_llRequestId);
  // �������ί���걨����
  virtual int ReqRpcPwdServiceOrder(CReqStkRpcPwdServiceOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �ɶ���ѯ����ѯ�ͻ���Ӧ�Ĺɶ���������
  virtual int ReqQryRpcTrdacct(CReqStkQryRpcTrdacctField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ѯ(������ҵ��)����
  virtual int ReqQryRpcCuacct(CReqStkQryRpcCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // �ʲ���ϸ��ѯ����
  virtual int ReqQryRpcAssetDetail(CReqStkQryRpcAssetDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷ���ϸ��ѯ����
  virtual int ReqQryRpcStkDetail(CReqStkQryRpcStkDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷݻ��ܲ�ѯ����
  virtual int ReqQryRpcStkSummary(CReqStkQryRpcStkSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ�ʽ��ʻ��ʽ������ѯ����
  virtual int ReqQryRpcCuacct2(CReqStkQryRpcCuacct2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ���������
  virtual int ReqQryRpcTrdacct2(CReqStkQryRpcTrdacct2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ���������
  virtual int ReqQryRpcTrdacct3(CReqStkQryRpcTrdacct3Field *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�в�ѯ����
  virtual int ReqQryRpcOrderDetail(CReqStkQryRpcOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�в�ѯ(������ҵ��)����
  virtual int ReqQryRpcOrder2(CReqStkQryRpcOrder2Field *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ���ϸ��ѯ����
  virtual int ReqQryRpcMatchDetail(CReqStkQryRpcMatchDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ���ѯ(������ҵ��)����
  virtual int ReqQryRpcMatch(CReqStkQryRpcMatchField *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ���ѯ��΢֤ȯר�ã�����
  virtual int ReqQryRpcMatchForTencentPay(CReqStkQryRpcMatchForTencentPayField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷί�л��ܲ�ѯ, ��֤ȯ�����������������
  virtual int ReqQryRpcHisOrderSummary(CReqStkQryRpcHisOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // �ɽ����ܲ�ѯ, ��֤ȯ�����������������
  virtual int ReqQryRpcHisMatchSummary(CReqStkQryRpcHisMatchSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // �����ѯ�����ݹ�̨��ͨ���ʵ�ժҪ���ô�ӡ��Ϣ��ӡ���ݡ�΢֤ȯר������
  virtual int ReqQryRpcDeliveryForTencentPay(CReqStkQryRpcDeliveryForTencentPayField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�л��ܲ�ѯ,ordergroup+stkcode+bsflag����
  virtual int ReqQryRpcOrderSummary2(CReqStkQryRpcOrderSummary2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�������ѯ����
  virtual int ReqQryRpcOrg(CReqStkQryRpcOrgField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ����Ժ��ʽ��ʺ���������
  virtual int ReqQryRpcAcctInfo(CReqStkQryRpcAcctInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���������ѯ����
  virtual int ReqQryRpcMktIntention(CReqStkQryRpcMktIntentionField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ����
  virtual int ReqQryRpcSeat(CReqStkQryRpcSeatField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ʽ��˻���Ϣ����
  virtual int ReqQryRpcCuacctAcctInfo(CReqStkQryRpcCuacctAcctInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͨ�ɷ�����ѯ�����У�����
  virtual int ReqQryRpcShNonCirculatingShareBalance(CReqStkQryRpcShNonCirculatingShareBalanceField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڷ���ͨ�ɷ�����ѯ����
  virtual int ReqQryRpcSzNonCirculatingShareBalance(CReqStkQryRpcSzNonCirculatingShareBalanceField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ϣ������˰��ѯ����
  virtual int ReqQryRpcDividendWithholdingTax(CReqStkQryRpcDividendWithholdingTaxField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�������������
  virtual int ReqQryRpcCustOrg(CReqStkQryRpcCustOrgField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ����ʽ��˺�����
  virtual int ReqQryRpcDepositoryCuacct(CReqStkQryRpcDepositoryCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڻ�������ʧ�ܲ�ѯ����
  virtual int ReqQryRpcFloorFundRedemptionFailure(CReqStkQryRpcFloorFundRedemptionFailureField *p_pReqField, LONGLONG p_llRequestId);
  // ������֤ȯ��ѯ����
  virtual int ReqQryRpcBlacklistStk(CReqStkQryRpcBlacklistStkField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڴ��ڽ��������ѯ����
  virtual int ReqQryRpcSzBlockTradingMkt(CReqStkQryRpcSzBlockTradingMktField *p_pReqField, LONGLONG p_llRequestId);
  // �Ϻ����ڽ��������ѯ����
  virtual int ReqQryRpcShBlockTradingMkt(CReqStkQryRpcShBlockTradingMktField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڳ��ڻ���ֺ췽ʽ��ѯ����
  virtual int ReqQryRpcSzFloorFundDividends(CReqStkQryRpcSzFloorFundDividendsField *p_pReqField, LONGLONG p_llRequestId);
  // ���޹ɶ����ֶ�Ȳ�ѯ����
  virtual int ReqQryRpcLimitedTrdacctReductionLimit(CReqStkQryRpcLimitedTrdacctReductionLimitField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ�ʽ��ʲ���ѯ����
  virtual int ReqQryRpcHkCuacct(CReqStkQryRpcHkCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ�ͻ���ծ��ѯ����
  virtual int ReqQryRpcHkLiability(CReqStkQryRpcHkLiabilityField *p_pReqField, LONGLONG p_llRequestId);
  // Ȩ���ѯ����
  virtual int ReqQryRpcHkEquity(CReqStkQryRpcHkEquityField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ����׼������
  virtual int ReqRpcHkPreparationForOpeningAccount(CReqStkRpcHkPreparationForOpeningAccountField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨδ������ϸ��ѯ����
  virtual int ReqQryRpcHkUndeliveryDetail(CReqStkQryRpcHkUndeliveryDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�֤ͨȯ��Ϸѽ�����ϸ����
  virtual int ReqRpcHkStkCombinationFeeDeliveryDetail(CReqStkRpcHkStkCombinationFeeDeliveryDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ�����ѯ����
  virtual int ReqQryRpcHkDelivery(CReqStkQryRpcHkDeliveryField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ���ʵ���ѯ����
  virtual int ReqQryRpcHkStatement(CReqStkQryRpcHkStatementField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ��С�۲��ѯ����
  virtual int ReqQryRpcHkMinSpread(CReqStkQryRpcHkMinSpreadField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ�ο����ʲ�ѯ����
  virtual int ReqQryRpcHkExchangeRate(CReqStkQryRpcHkExchangeRateField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ�г�����״̬��ѯ����
  virtual int ReqQryRpcHkMarketStatus(CReqStkQryRpcHkMarketStatusField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ���֤ȯ��ѯ����
  virtual int ReqQryRpcHkUnderlyingSecurity(CReqStkQryRpcHkUnderlyingSecurityField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ����������ѯ����
  virtual int ReqQryRpcHkCalendar(CReqStkQryRpcHkCalendarField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨί��������������
  virtual int ReqRpcHkOrder(CReqStkRpcHkOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ����ί������
  virtual int ReqRpcHkCancel(CReqStkRpcHkCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�����ѯ����
  virtual int ReqQryRpcHkCancel(CReqStkQryRpcHkCancelField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ���ɽ���������ѯ����
  virtual int ReqQryRpcHkMaxTradeQty(CReqStkQryRpcHkMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ����ί����ϸ��ѯ����
  virtual int ReqQryRpcHkOrderDetail(CReqStkQryRpcHkOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ���׳ɽ���ѯ����
  virtual int ReqQryRpcHkMatch(CReqStkQryRpcHkMatchField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ������ʷί�в�ѯ����
  virtual int ReqQryRpcHkHisOrder(CReqStkQryRpcHkHisOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �۹�ͨ���׳ɽ���ʷ��ѯ����
  virtual int ReqQryRpcHkHisMatch(CReqStkQryRpcHkHisMatchField *p_pReqField, LONGLONG p_llRequestId);
  // ��תϵͳ֤ȯί���걨����
  virtual int ReqRpcStkTranSysStkOrder(CReqStkRpcStkTranSysStkOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ��תϵͳЭ��ת�������ѯ����
  virtual int ReqQryRpcStkTranSysAgreementTransferMkt(CReqStkQryRpcStkTranSysAgreementTransferMktField *p_pReqField, LONGLONG p_llRequestId);
  // ��תϵͳȡ���������,֧��������������
  virtual int ReqRpcStkTranSysMaxTradeQty(CReqStkRpcStkTranSysMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ��תϵͳ����Ͷ���߲�ѯ����
  virtual int ReqQryRpcStkTranSysRestrictedInvestor(CReqStkQryRpcStkTranSysRestrictedInvestorField *p_pReqField, LONGLONG p_llRequestId);
  // ��ת�г�����ͨ�ɷ�����ѯ����
  virtual int ReqQryRpcStkTranSysNonCirculatingSharesBalance(CReqStkQryRpcStkTranSysNonCirculatingSharesBalanceField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨����ί����ϸ��ѯ����
  virtual int ReqQryRpcFixedIncomeSysOrderDetail(CReqStkQryRpcFixedIncomeSysOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨������ʷί����ϸ��ѯ����
  virtual int ReqQryRpcFixedIncomeSysHisOrderDetail(CReqStkQryRpcFixedIncomeSysHisOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨���׳ɽ���ѯ����
  virtual int ReqQryRpcFixedIncomeSysMatch(CReqStkQryRpcFixedIncomeSysMatchField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨���ɽ���������ѯ����
  virtual int ReqQryRpcFixedIncomeSysMaxTradeQty(CReqStkQryRpcFixedIncomeSysMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨ί��������������
  virtual int ReqRpcFixedIncomeSysOrder(CReqStkRpcFixedIncomeSysOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ����ƽ̨����ί������
  virtual int ReqRpcFixedIncomeSysCancel(CReqStkRpcFixedIncomeSysCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�����ѯ����
  virtual int ReqQryRpcFixedIncomeSysCancel(CReqStkQryRpcFixedIncomeSysCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯ������Ϣ��ѯ����
  virtual int ReqQryRpcBondBasicInfo(CReqStkQryRpcBondBasicInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨ծȯ�����ѯ����
  virtual int ReqQryRpcBondMkt(CReqStkQryRpcBondMktField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒ�ݶ�ת�ó�������
  virtual int ReqRpcFinancialProductShareTransferCancel(CReqStkRpcFinancialProductShareTransferCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒ�ݶ�ת��ҵ������
  virtual int ReqRpcFinancialProductShareTransfer(CReqStkRpcFinancialProductShareTransferField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒת����ϵ����Ϣ��ѯ����
  virtual int ReqQryRpcFinancialProductShareTransferContactInfo(CReqStkQryRpcFinancialProductShareTransferContactInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒ�ݶ�ת�÷��ü�������
  virtual int ReqRpcFinancialProductShareTransferFee(CReqStkRpcFinancialProductShareTransferFeeField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨ծȯ������Ϣ��ѯ����
  virtual int ReqQryRpcBondParamInfo(CReqStkQryRpcBondParamInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί����ˮ��ѯ����
  virtual int ReqQryRpcBondIntentionOrderStatement(CReqStkQryRpcBondIntentionOrderStatementField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒ�����ѯ����
  virtual int ReqQryRpcFinancialProductMarket(CReqStkQryRpcFinancialProductMarketField *p_pReqField, LONGLONG p_llRequestId);
  // ��̨���Ʋ�Ʒί�в�ѯ����
  virtual int ReqQryRpcFinancialProductOrder(CReqStkQryRpcFinancialProductOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ����ί����Χ�ӿ�����
  virtual int ReqRpcRefinancingStkLendingOrder(CReqStkRpcRefinancingStkLendingOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ����ί�г�����Χ�ӿ�����
  virtual int ReqRpcRefinancingStkLendingCancel(CReqStkRpcRefinancingStkLendingCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ί�в�ѯ��Χ�ӿ�����
  virtual int ReqQryRpcRefinancingOrder(CReqStkQryRpcRefinancingOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ��ǰ������Χ�ӿ�����
  virtual int ReqRpcRefinancingAdvanceRevert(CReqStkRpcRefinancingAdvanceRevertField *p_pReqField, LONGLONG p_llRequestId);
  // ͬ��չ����Χ�ӿ�����
  virtual int ReqRpcRefinancingExtentionApprove(CReqStkRpcRefinancingExtentionApproveField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ����ɳ���¼��ѯ��Χ�ӿ�����
  virtual int ReqQryRpcRefinancingStkLendingCanWithdraw(CReqStkQryRpcRefinancingStkLendingCanWithdrawField *p_pReqField, LONGLONG p_llRequestId);
  // ת��ȯδ�˽��Լ��ѯ��Χ�ӿ�����
  virtual int ReqQryRpcRefinancingOpenContract(CReqStkQryRpcRefinancingOpenContractField *p_pReqField, LONGLONG p_llRequestId);
  // �ɳ�����ȯ��ѯ��Χ�ӿ�����
  virtual int ReqQryRpcRefinancingUnderlyingStkForLending(CReqStkQryRpcRefinancingUnderlyingStkForLendingField *p_pReqField, LONGLONG p_llRequestId);
  // ��������Ϣ��ѯ��Χ�ӿ�����
  virtual int ReqQryRpcRefinancingLenderInfo(CReqStkQryRpcRefinancingLenderInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷ����ί�в�ѯ����
  virtual int ReqQryRpcRefinancingHisLendingOrder(CReqStkQryRpcRefinancingHisLendingOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ�������˽��Լ��ѯ����
  virtual int ReqQryRpcRefinancingStkLendingClosedContract(CReqStkQryRpcRefinancingStkLendingClosedContractField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ���Ԥ����Ϣ����
  virtual int ReqQryRpcSysSecurityCustReservedInfo(CReqStkQryRpcSysSecurityCustReservedInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ�Ԥ����Ϣ����
  virtual int ReqRpcSysSecuritySetCustReservedInfo(CReqStkRpcSysSecuritySetCustReservedInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ͬ���ͻ���̬��������
  virtual int ReqRpcSysSecuritySyncDynamicToken(CReqStkRpcSysSecuritySyncDynamicTokenField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�֤���ȡ���������
  virtual int ReqRpcSysSecurityCertificateRandomCode(CReqStkRpcSysSecurityCertificateRandomCodeField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���̬����״̬��������
  virtual int ReqRpcSysSecuritySetDynamicTokenStatus(CReqStkRpcSysSecuritySetDynamicTokenStatusField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ȡһ���Զ�̬��������
  virtual int ReqRpcSysSecurityOneTimeDynamicPwd(CReqStkRpcSysSecurityOneTimeDynamicPwdField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���½����Ϣ��������
  virtual int ReqRpcSysSecuritySetLoginBindingInfo(CReqStkRpcSysSecuritySetLoginBindingInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���½����Ϣ��ѯ����
  virtual int ReqQryRpcSysSecurityLoginBindingInfo(CReqStkQryRpcSysSecurityLoginBindingInfoField *p_pReqField, LONGLONG p_llRequestId);
  // У��ͻ�������������
  virtual int ReqRpcSysSecurityVerifyTrdPwd(CReqStkRpcSysSecurityVerifyTrdPwdField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ȡ�ֻ�һ���Զ�̬��������
  virtual int ReqRpcSysSecurityMobileOneTimeDynamicPwd(CReqStkRpcSysSecurityMobileOneTimeDynamicPwdField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�ETF�����ɷֹɵĳֲ���������
  virtual int ReqQryRpcETFConstituentStkPosi(CReqStkQryRpcETFConstituentStkPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ��ͨ�ڵ��VIPϵͳ��֤ȯ��������
  virtual int ReqRpcCommVIPStkTransfer(CReqStkRpcCommVIPStkTransferField *p_pReqField, LONGLONG p_llRequestId);
  // �ֽ��ʲ�ת��������
  virtual int ReqRpcCashAssetBankTransfer(CReqStkRpcCashAssetBankTransferField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ𻮲���ˮ��ѯ����
  virtual int ReqQryRpcCapitalTransferStatement(CReqStkQryRpcCapitalTransferStatementField *p_pReqField, LONGLONG p_llRequestId);
  // Vip�ͻ��ʽ��ʲ�ͬ������ѯ����
  virtual int ReqQryRpcVIPCuacctSyncTable(CReqStkQryRpcVIPCuacctSyncTableField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڲ�Ʒ�ʵ�����Ϣ��ѯ����
  virtual int ReqQryRpcFloorTradingProductAppropriatenessInfo(CReqStkQryRpcFloorTradingProductAppropriatenessInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ��ʵ�����Ϣ��ѯ����
  virtual int ReqQryRpcAppropriatenessInfo(CReqStkQryRpcAppropriatenessInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ��볡�ڲ�Ʒ�ʵ���ƥ��У������
  virtual int ReqRpcAppropriatenessMatchingCheck(CReqStkRpcAppropriatenessMatchingCheckField *p_pReqField, LONGLONG p_llRequestId);
  // ��¼����ҵ����ս�ʾ��ǩ����ˮ����
  virtual int ReqRpcFloorTradingRiskDisclosureStatementSignedRecordFlow(CReqStkRpcFloorTradingRiskDisclosureStatementSignedRecordFlowField *p_pReqField, LONGLONG p_llRequestId);
  // ϵͳ̽������
  virtual int ReqBizStatus(CReqStkBizStatusField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)����
  virtual int ReqQryPledgeShares(CReqStkQryPledgeSharesField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ���ˮ��ѯ����
  virtual int ReqQryFundFlow(CReqStkQryFundFlowField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί������
  virtual int ReqOrderEx(CReqStkOrderExField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷ���ˮ��ѯ����
  virtual int ReqQryStockFlow(CReqStkQryStockFlowField *p_pReqField, LONGLONG p_llRequestId);
  // ���н����ղ�ѯ����
  virtual int ReqQrySettDate(CReqStkQrySettDateField *p_pReqField, LONGLONG p_llRequestId);
  // �̺���������ѯ����
  virtual int ReqQryLofMktInfo(CReqStkQryLofMktInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ𻮲�(���н���)����
  virtual int ReqFundTransferJzjy(CReqStkFundTransferJzjyField *p_pReqField, LONGLONG p_llRequestId);
  // �����ʽ��ѯ(���н���)����
  virtual int ReqQryExpendableFundJzjy(CReqStkQryExpendableFundJzjyField *p_pReqField, LONGLONG p_llRequestId);
  // ��֤��Ϣ����(����¼��/�޸�)����
  virtual int ReqAuthDataSetJzjy(CReqStkAuthDataSetJzjyField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮������
  virtual int ReqFundTransferNode(CReqStkFundTransferNodeField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮������[��ϯ����]
  // virtual int ReqFundTransferNodeCiXi(CReqStkFundTransferNodeCiXiField *p_pReqField, LONGLONG p_llRequestId);
  // ��֤ת������
  virtual int ReqBankStkTransfer(CReqStkBankStkTransferField *p_pReqField, LONGLONG p_llRequestId);
  // ҪԼ�չ��չ�����Ϣ��ѯ����
  virtual int ReqQryTenderSgrInfo(CReqStkQryTenderSgrInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�����Ϲ����볷������
  virtual int ReqEtfOfflineCancelOrder(CReqStkEtfOfflineCancelOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�����Ϲ������ѯ����
  virtual int ReqQryEtfOfflineOrder(CReqStkQryEtfOfflineOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �¹�������ѯ����
  virtual int ReqQryNewStkCal(CReqStkQryNewStkCalField *p_pReqField, LONGLONG p_llRequestId);
  // �����ڴ�Ʒ����Ϣ��ѯ����
  virtual int ReqQryStkInfoShm(CReqStkQryStkInfoShmField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯ����ҵ��ԤԼί�г�������
  virtual int ReqReserveOrderCancel(CReqStkReserveOrderCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ����ծȯ���������ѯ����
  virtual int ReqQryBondQuote(CReqStkQryBondQuoteField *p_pReqField, LONGLONG p_llRequestId);
  // Э�̳ɽ��ر�������Ϣ��ѯ����
  virtual int ReqQryReportMktInfo(CReqStkQryReportMktInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯ��ȯ���׾���ԤԼί����Ϣ��ѯ����
  virtual int ReqQryCashBondReserveOrderInfo(CReqStkQryCashBondReserveOrderInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ί�л��ܲ�ѯ����
  virtual int ReqQryOrderSummary(CReqStkQryOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // �ɽ����ܲ�ѯ����
  virtual int ReqQryMatchSummary(CReqStkQryMatchSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ�䶯���ܲ�ѯ����
  virtual int ReqQryFundEffectSummary(CReqStkQryFundEffectSummaryField *p_ReqField, LONGLONG p_llRequestId);
  // �ɷݱ䶯���ܲ�ѯ����
  virtual int ReqQryStockEffectSummary(CReqStkQryStockEffectSummaryField *p_ReqField, LONGLONG p_llRequestId);
  // ծȯ��ȯ���׾���ԤԼ��Ϣ��ѯ����
  virtual int ReqQryCashBondTradeReservationInfo(CReqStkQryCashBondTradeReservationInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯ��ȯ����ҵ��ο���Ϣ��ѯ����
  virtual int ReqQryCashBondTradeProfitInfo(CReqStkQryCashBondTradeProfitInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ծȯͨ����Ѻʽ�ع�ҵ��ο���Ϣ��ѯ����
  virtual int ReqQryBondPledgeRepchProfitInfo(CReqStkQryBondPledgeRepchProfitInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڽ���������Ϣ��ѯ����
  virtual int ReqQryBlockTradingMktInfo(CReqStkQryBlockTradingMktInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �̺����������Ϣ��ѯ����
  virtual int ReqQryClosingBlockTradingMktInfo(CReqStkQryClosingBlockTradingMktInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ҵ���̺󶨼������ѯ����
  virtual int ReqQryClosingMktSecondboard(CReqStkQryClosingMktSecondboardField *p_pReqField, LONGLONG p_llRequestId);
  // REITs�����ǵ���״̬��ѯ����
  virtual int ReqQryPriceStatus(CReqStkQryPriceStatusField *p_pReqField, LONGLONG p_llRequestId);
  // ģ��ͻ���¼����
  virtual int ReqUserLoginImpersonate(CReqStkUserLoginImpersonateField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷݻ�������
  virtual int ReqStockTransfer(CReqStkStockTransferField *p_pReqField, LONGLONG p_llRequestId);
  // ETF�ͻ����Ӻ�ͬ��Ϣ��ѯ����
  virtual int ReqQryEtfContractInfo(CReqStkQryEtfContractInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �Ϻ����ֹɷݶ�Ȳ�ѯ����
  virtual int ReqQryReductLimitSh(CReqStkQryReductLimitShField *p_pReqField, LONGLONG p_llRequestId);
  // ���ڼ��ֹɷݶ�Ȳ�ѯ����
  virtual int ReqQryReductLimitSz(CReqStkQryReductLimitSzField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ƶ�������Ʋ�����ѯ
  // virtual int ReqQryFreqTradeLmtParam(CReqStkQryFreqTradeLmtParamField* p_pReqField, LONGLONG p_llRequestId);
public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

private:
  // ֤ȯ��Ϣ��ѯ��Ӧ[����]
  void OnRspQryStkInfoEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ֤ȯ��Ϣ��ѯ��Ӧ
  void OnRspQryStkInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �̺������ѯ(�Ϻ��ƴ���)��Ӧ
  void OnRspQryClosingMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // LOF��Ϣ��ѯ
  void OnRspQryLofInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF��Ϣ��ѯ
  void OnRspQryEtfInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF����Ϣ��ѯ
  void OnRspQryEtfBasket(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί����Ӧ
  void OnRspOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ί����Ӧ
  void OnRspCombOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ί�г�����Ӧ
  void OnRspCancelOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ɽ�����������Ӧ
  void OnRspMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί����Ӧ
  void OnRspQuantityOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����������Ӧ
  void OnRspQuantityCancelOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF ����ί����Ӧ
  void OnRspEtfOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�����ɽ�����������Ӧ
  void OnRspEtfMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �����ʽ��ѯ��Ӧ
  void OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �����ʽ��ѯ(��ϯ����)
  void OnRspQryExpendableFundCiXi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ùɷݲ�ѯ��Ӧ
  void OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�в�ѯ��Ӧ
  void OnRspQryCurrDayOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ճɽ���ѯ��Ӧ
  void OnRspQryCurrDayFill(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɶ��˻���ѯ��Ӧ
  void OnRspQryStkholderAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɳ���ί�в�ѯ��Ӧ
  void OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �����ʽ��ѯ��Ӧ[����]
  void OnRspQryExpendableFundEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ùɷݲ�ѯ��Ӧ[����]
  void OnRspQryExpendableSharesEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�в�ѯ��Ӧ[����]
  void OnRspQryCurrDayOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ճɽ���ѯ��Ӧ[����]
  void OnRspQryCurrDayFillEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɶ��˻���ѯ��Ӧ[����]
  void OnRspQryStkholderAcctEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɳ���ί�в�ѯ��Ӧ[����]
  void OnRspQryCanWithdrawOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF �ɷֹɳֲֲ�ѯ��Ӧ
  void OnRspQryEtfCotPosition(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ������Ϣ��ѯ��Ӧ
  void OnRspQryRateInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ�г�״̬��Ϣ��ѯ��Ӧ
  void OnRspQryMktStatusInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ���֤ȯ״̬��ѯ��Ӧ
  void OnRspQryUndlStkStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ�����ʽ�̨�˲�ѯ��Ӧ
  void OnRspQryFundAcctLvlTwo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ������С�۲��ѯ��Ӧ
  void OnRspQryTradeMinSpread(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �۹�ͨ�ͻ���ծ��ѯ��Ӧ
  //void OnRspQryCustDebts(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ع���Լ��ѯ��Ӧ
  void OnRspQryRepchContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ͻ��ʵ��Բ�ѯ��Ӧ
  void OnRspQryCustAppropriate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��Ʒ�ʵ��Բ�ѯ��Ӧ
  void OnRspQryProdAppropriate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ʵ���ƥ������Ӧ
  void OnRspAppropriateCheck(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ʵ���ƥ������¼��Ӧ
  void OnRspAppropriateResult(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ع��ʽ�ռ��������ѯ��Ӧ
  void OnRspQryRepchFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �û���¼������Ӧ
  void OnRspUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��ʷί�в�ѯ��Ӧ
  void OnRspQryHisOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��ʷ�ɽ���ѯ��Ӧ
  void OnRspQryHisFill(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����/��ʷί�в�ѯ��Ӧ
  void OnRspQryCurrDayHisOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����/��ʷ�ɽ���ѯ��Ӧ
  void OnRspQryCurrDayHisFill(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //ת������ҵ����Ϣ 2015/8/12
  void OnRspQryBankTransBasicInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //��֤ת��       2015/8/12
  void OnRspBankStkTrans(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //��ѯ�˻����   2015/8/12
  void OnRspQryFundBala(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //��֤ת�ʲ�ѯ   2015/8/12
  void OnRspQryBankStkTrans(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //�޸Ľ�������   2015/8/12
  void OnRspChgTrdPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //�޸��ʽ�����   2015/8/12
  void OnRspChgFundPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //���ʵ���ѯ     2015/8/12
  void OnRspQryStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  //�ʽ𻮲�
  void OnRspQryFundTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ֤ȯ��ֵ��Ȳ�ѯ��Ӧ
  void OnRspQryMktQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��֤LOF��Ϣ��ѯ��Ӧ
  void OnRspQryScLofInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  
  // ��ʷί����ϸ��ѯ��Ӧ
  void OnRspQryRpcHistoryOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷ�ɽ���ϸ��ѯ��Ӧ
  void OnRspQryRpcHistoryMatchDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����¹��嵥��ѯ��Ӧ
  void OnRspQryRpcIPO(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ�¹��깺��ֵ��ȱ���ѯ��Ӧ
  void OnRspQryRpcIPOSubscriptionLimit(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ų�ѯ��Ӧ
  void OnRspQryRpcDistribution(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ֵ������ǩ��ѯ��Ӧ
  void OnRspQryRpcMktCapPlacing(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ǩ��ʷ��ѯ��Ӧ
  void OnRspQryRpcWinningHistory(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ֵ���۽���˳���޸���Ӧ
  void OnRspRpcChgMktCapDistDeliOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ѯ��Ӧ
  void OnRspQryRpcDeliOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ʲ�ѯ��Ӧ
  void OnRspQryRpcChkAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ��ͨת��(����)�˺Ų�ѯ��Ӧ
  void OnRspQryRpcBankAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ��ͨ�ⲿ(����)�˺Ų�ѯ��Ӧ
  void OnRspQryRpcOtherBankAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ѯ��Ӧ
  void OnRspQryRpcFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ʽ���ˮ��ѯ��Ӧ
  void OnRspQryRpcFundDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�л���(410514)��Ӧ
  void OnRspQryRpcOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ�����(410516)��Ӧ
  void OnRspQryRpcMatchSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ��ǰϵͳ״̬��Ӧ
  void OnRspQryRpcCurSysStat(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ�ֵ���Ϣ��Ӧ
  void OnRspRpcDictInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ��Ϣ��Ӧ
  void OnRspRpcStkInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ������Ϣ��Ӧ
  void OnRspQryRpcOrgInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��֤ͨת������ҵ����Ϣ��Ӧ
  void OnRspRpcBankStkTransferBankBizInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û���½��Ӧ
  void OnRspRpcLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����ʲ���ѯ(��)��Ӧ
  void OnRspQryRpcTotalAssets(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸���ϵ��ʽ�����Ͻ���ʹ�ã���Ӧ
  void OnRspRpcChgContact(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����ϲ�ѯ��Ӧ
  void OnRspQryRpcCustInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ĳ�����ʽ��Ӧ
  void OnRspRpcChgOperMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���ͨ�Ĳ�����ʽ��Ӧ
  void OnRspQryRpcCustOperMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ŀͻ���ϵ����Ϣ��Ӧ
  void OnRspRpcChgCustInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ�����չ������Ӧ
  void OnRspRpcSetCustAttrEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��������ǩ����Ӧ
  void OnRspRpcSetDigitalSign(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ�޸��ʽ��ʺ�Ȩ����Ӧ
  void OnRspRpcChgCuacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ʺſ�ͨ�ʽ�Ȩ�޲�ѯ��Ӧ
  void OnRspQryRpcCuacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ�ʺſ�ͨȨ�޲�ѯ��Ӧ
  void OnRspQryRpcTrdacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�Ȩ����Ч����Ϣ��ѯ��Ӧ
  void OnRspQryRpcCustPermissionValidPeriod(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ����ͻ�Ȩ����Ӧ
  void OnRspRpcActivateCustPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����������Ѳ�ѯ��Ӧ
  void OnRspQryRpcCustSpecialFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // һ���Է���Ӷ����ȡ��Ӧ
  void OnRspRpcOneTimeServiceCommission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // һ���Է���Ӷ�𳷵���Ӧ
  void OnRspRpcCancelOneTimeServiceCommission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �̶����޷���Ӷ�������Ӧ
  void OnRspRpcFixedTermServiceCommission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �̶����޷���Ӷ���˿���Ӧ
  void OnRspRpcFixedTermServiceCommissionRefund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // һ���Է���Ӷ�����ò�ѯ��Ӧ
  void OnRspQryRpcOneTimeServiceCommissionSetting(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // һ���Է���Ӷ����ȡ��ѯ��Ӧ
  void OnRspQryRpcOneTimeServiceCommissions(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ��ѯ���������Ӧ
  void OnRspQryRpcConsultationPaymentCategory(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ѯ���������Ӧ
  void OnRspRpcAddConsultationPaymentCategory(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ά���ͻ�����״̬��Ӧ
  void OnRspRpcMaintainCustSubStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�������ˮ��Ӧ
  void OnRspQryRpcCustSubStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�����������Ӧ
  void OnRspRpcCustSubSetting(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������շѽṹ��Ӧ
  void OnRspRpcThirdPartyChargingStructure(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Ͷ����ѯ��Ʒ���ñ�֤��֧����Ӧ
  void OnRspRpcInvestmentAdvisoryProductFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����У����Ӧ
  void OnRspRpcCuacctPwdCheck(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ����ϲ�ѯ��Ӧ
  void OnRspQryRpcCuacctInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ�ͻ����Ϻ˲�״̬��Ӧ
  void OnRspRpcCustInfoCheck(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ���¼У����Ϣ��Ӧ
  void OnRspRpcSetLoginCheckMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ����Ϻ˲��ʶ��Ӧ
  void OnRspRpcSetCustInfoCheckMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ���Ϣ״̬��Ӧ
  void OnRspRpcSetCustMsgStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���Ϣ������Ӧ
  void OnRspQryRpcCustMsgService(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸�����������Ӧ
  void OnRspRpcChgBankPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ�̨�ʼ�ת����Ӧ
  void OnRspRpcTransferBetweenCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ�ͻ������ʻ��ʽ�鼯��Ӧ
  void OnRspRpcCuacctCashConcentration(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡͬһ�ͻ�����̨�ʡ�ת��̨����Ӧ
  void OnRspRpcCuacctInfo2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ȡ����ѯ��Ӧ
  void OnRspQryRpcCuacctMaxDraw(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ȡ�ʽ��ѯ��Ӧ
  void OnRspQryRpcCuacctMaxDrawForTencentPay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ֤ȯ����ǰ���¼۵�,֧������������Ӧ
  void OnRspRpcStkAvlAndLatestPrice(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ���������,֧������������Ӧ
  void OnRspRpcMaxStkQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί��ҵ��,֧������������Ӧ
  void OnRspRpcOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����Ӧ
  void OnRspRpcOrderCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����ѯ��Ӧ
  void OnRspQryRpcOrderCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���óɱ���Ӧ
  void OnRspRpcResetCost(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ӯ�����ü�����Ӧ
  void OnRspRpcCalcFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί������ҵ��,֧���������ף�������Χ���ã���Ӧ
  void OnRspRpcOrderForTencentPay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʹܷݶ�ת��T+0ί����Ӧ
  void OnRspRpcTransferCapitalManagementShare(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������۽ɿ�, ֧������������Ӧ
  void OnRspRpcCancelRation(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������۽ɿ�, ֧������������Ӧ
  void OnRspQryRpcCancelRation(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�ҡ�Ų�ѯ��Ӧ
  void OnRspQryRpcCustLottery(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�����Χ�ⶳ��ǩԤ�����ʽ���Ӧ
  void OnRspRpcUnfreezePreFrozenFunds(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ʒ��Ϣ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeProductInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����Ѻ���֤ȯ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeNegotiableSecurity(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���Ѻ��������ʲ�ѯ��Ӧ
  void OnRspQryRpcStkPledgePledgeConversionRate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���������Ϣ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeLoanQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����Ѻ֤ȯ�ֲֲ�ѯ��Ӧ
  void OnRspQryRpcStkPledgeNegotiableSecurityPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ɴ������ѯ��Ӧ
  void OnRspQryRpcStkPledgeMaxLoanAmt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����������Ӧ
  void OnRspRpcStkPledgeLoanApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����������Ӧ
  void OnRspRpcStkPledgeRepaymentApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����֤ȯ��Ѻ��������Ӧ
  void OnRspRpcStkPledgeSupplementaryPledgeSecurityApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լ����������������Ӧ
  void OnRspRpcStkPledgeDeferredContractRepaymentApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լ�貹����Ѻ������ѯ��Ӧ
  void OnRspQryRpcStkPledgeInsufficientPledge(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ҵ�����������ѯ��Ӧ
  void OnRspQryRpcStkPledgeBizApplicationStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����Լ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeLoanContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����Լ��Ѻ��ϸ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeLoanContractPledgeDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ʊ��Ѻ����޸���Ӧ
  void OnRspRpcStkPledgeChgStkPledgeQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ֻ���������Ӧ
  void OnRspRpcStkPledgePartialRepaymentApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����˶�Ȳ�ѯ��Ӧ
  void OnRspQryRpcStkPledgeLenderQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ��ԼΥԼ״̬Ϊ׷���ĺ�Լ��Ӧ
  void OnRspQryRpcStkPledgeAdditionalMarginContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ׷����Լ��Ҫ׷����������Ӧ
  void OnRspQryRpcStkPledgeAdditionalMarginQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����𳥻���Ӧ
  void OnRspRpcStkPledgeLoanPrincipalRepayment(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ڻ����ʽ��ѯ��Ӧ
  void OnRspQryRpcStkPledgeAvailableQtyForRepayment(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷݲ��ֽ����Ѻ������Ӧ
  void OnRspRpcStkPledgePartialCancellationPledgeApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����Ի��������ʲ�ѯ��Ӧ
  void OnRspQryRpcStkPledgePersonalizedInterestRate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լ��Ϣ����������Ӧ
  void OnRspRpcStkPledgeRepaymentContractInterestApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Լ�����ؿͻ���Ȳ�ѯ��Ӧ
  void OnRspQryRpcAgreementRepurchaseDebtContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Լ�����ؿͻ���Ȳ�ѯ��Ӧ
  void OnRspQryRpcAgreementRepurchaseQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Լ�����س�ʼ������Ӧ
  void OnRspRpcAgreementRepurchaseInitialTransaction(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Լ�����ع��ؽ�����Ӧ
  void OnRspRpcAgreementRepurchaseRepurchaseTransaction(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Լ���������ڹ���������Ӧ
  void OnRspRpcAgreementRepurchaseDelayedRepurchaseApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡȨ֤��Ϣ��Ӧ
  void OnRspRpcWarrantInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�������Ȩί��Ԥ������˰��ѯ��Ӧ
  void OnRspQryRpcExpectedIncomeTax(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լ��ѯ(410983)��Ӧ
  void OnRspQryRpcContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩί�в�ѯ(410989)��Ӧ
  void OnRspQryRpcFinancingRightCommission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ȩ������Ա��Ϣ��ѯ��410990����Ӧ
  void OnRspQryRpcEquityIncentivePersonnelInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩ������Ϣ��ѯ��410991����Ӧ
  void OnRspQryRpcFinancingExerciseParams(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩ�ʲ���ծ��ѯ��410992����Ӧ
  void OnRspQryRpcFinancingExerciseAssetsLiability(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩ�ͻ������Ϣ��ѯ��410993����Ӧ
  void OnRspQryRpcFinancingExerciseCustQuotaInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֱ�ӻ���(410984)��Ӧ
  void OnRspRpcDirectRepayment(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩҵ��(410985)��Ӧ
  void OnRspRpcFinancingExerciseBiz(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ������Ȩ��ί������(410986)��Ӧ
  void OnRspRpcFinancingExerciseMaxOrderQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩί�г���(410987)��Ӧ
  void OnRspRpcFinancingExerciseCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������Ȩ����֤ȯ��ѯ(410988)��Ӧ
  void OnRspQryRpcFinancingExerciseGuaranteedSecurityInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�ɷݹ��嵥��Ϣ��ѯ��Ӧ
  void OnRspQryRpcETFStkList(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�����Ϲ����루�ֽ��Ϲ�����Ʊ�Ϲ�����Ӧ
  void OnRspRpcETFOfflineApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�����Ϲ����볷����Ӧ
  void OnRspRpcETFOfflineApplicationCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�����Ϲ������ѯ��Ӧ
  void OnRspQryRpcETFOfflineApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����LOF����ֲ�ϲ���Ϣ��ѯ��Ӧ
  void OnRspQryRpcSzLOFFundSplitMerge(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �Ϻ�LOF����ֲ�ϲ���Ϣ��ѯ��Ӧ
  void OnRspQryRpcShLOFFundSplitMerge(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �̺����ֲ�/�ϲ����������깺��õ��Ľ���ֵ��Ӧ
  void OnRspRpcAfterCloseFundSplitMergeRecommendedValue(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���ծԤ���гֲ���ϸ��Ӧ
  void OnRspQryRpcTreasuryBondsPreIssuePosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���ծԤ����ƽ����ϸ��Ӧ
  void OnRspQryRpcTreasuryBondsPreIssueClosePosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���ծԤ����Ӧ����Լ����ϸ��Ӧ
  void OnRspQryRpcTreasuryBondsPreIssuePerformanceBond(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͶƱ�ɶ������Ϣ��ѯ(440001)��Ӧ
  void OnRspQryRpcNetworkVotingTrdacctsConferenceInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͶƱ�鰸��Ϣ��ѯ(440002)��Ӧ
  void OnRspQryRpcNetworkVotingMotionInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͶƱ�����ѯ(440003)��Ӧ
  void OnRspQryRpcNetworkVotingResult(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͶƱ(440101)��Ӧ
  void OnRspRpcNetworkVoting(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͶƱί�в�ѯ(440103)��Ӧ
  void OnRspQryRpcNetworkVoting(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��׼ȯ���ܲ�ѯ��Ӧ
  void OnRspQryRpcStdBondSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ѻ���׼ȯ��ϸ��ѯ��Ӧ
  void OnRspQryRpcPledgeBankStdBondDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ع��ʽ�ռ��������ѯ��Ӧ
  void OnRspQryRpcRepurchaseFundOccupancyDays(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // δ���ڻع���ѯ��Ӧ
  void OnRspQryRpcUndueRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����ʻع����ղ�ѯ��Ӧ
  void OnRspQryRpcFinancingRepurchaseRisk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ����ۻع�Ʒ����Ϣ��Ӧ
  void OnRspQryRpcShQuoteRepurchaseProductInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ǰ������Ӧ
  void OnRspRpcShQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع�ԤԼ��Ӧ
  void OnRspRpcShQuoteRepurchaseReservation(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع�ԤԼ��ˮ��ѯ��Ӧ
  void OnRspQryRpcShQuoteRepurchaseReservationStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�δ���ڵı��ۻع���Ϣ��Ӧ
  void OnRspQryRpcShQuoteRepurchaseUndueRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع���Ӧ��Ѻ����ϸ��Ӧ
  void OnRspRpcShQuoteRepurchasePledgeDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �Ϻ����ۻع���Ȩ��Ϣ��ѯ��Ӧ
  void OnRspQryRpcShQuoteRepurchasePledgeInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع�����ί�б�����Ȳ�ѯ��Ӧ
  void OnRspQryRpcShQuoteRepurchaseBatchOrderRetentionLimit(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع�����ί�б������������Ӧ
  void OnRspRpcShQuoteRepurchaseSetBatchOrderRetentionLimit(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع���Ʒ��Ϣ��ѯ��Ӧ
  void OnRspQryRpcSzQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع�ԤԼ��Ӧ
  void OnRspRpcSzQuoteRepurchaseReservation(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع�ԤԼȡ����Ӧ
  void OnRspRpcSzQuoteRepurchaseReservationCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع�ԤԼִ����Ӧ
  void OnRspRpcSzQuoteRepurchaseReservationExecution(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع���ǰ������Ӧ
  void OnRspRpcSzQuoteRepurchaseAdvanceRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع�ԤԼ��ˮ��ѯ��Ӧ
  void OnRspQryRpcSzQuoteRepurchaseReservationStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع���Լ����������Ӧ
  void OnRspRpcSzQuoteRepurchaseChgContractQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع�չ��ȡ����Ӧ
  void OnRspRpcSzQuoteRepurchaseExtensionCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ���ڿͻ�δ���ڵı��ۻع���Ϣ��Ӧ
  void OnRspQryRpcSzQuoteRepurchaseUndueRepurchase(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ���ڱ��ۻع���Ѻ��������Ӧ
  void OnRspQryRpcSzQuoteRepurchasePledgeConversionRate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع��ֽ���Ѻ��ѯ��Ӧ
  void OnRspQryRpcSzQuoteRepurchaseCashPledge(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڱ��ۻع���Ȩ��Ϣ��ѯ��Ӧ
  void OnRspQryRpcSzQuoteRepurchaseMortgage(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ���ڱ��ۻع��ͻ��ض�������Ӧ
  void OnRspQryRpcSzQuoteRepurchaseSpecificOffer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�����Ͷ���ʵ�����Ϣά����Ӧ
  void OnRspRpcSzQuoteRepurchaseMaintenanceFundInvestmentAppropriateness(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ۻع���Ѻ���ѯ��Ӧ
  void OnRspQryRpcSzQuoteRepurchasePledge(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯЭ��ع�ί���걨��Ӧ
  void OnRspRpcBondAgreementRepurchaseOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯЭ��ع�ί�г����걨��Ӧ
  void OnRspRpcBondAgreementRepurchaseCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯЭ��ع�ί����ˮ��ѯ��Ӧ
  void OnRspQryRpcBondAgreementRepurchaseStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯЭ��ع��ɽ���ѯ��Ӧ
  void OnRspQryRpcBondAgreementRepurchaseMatch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯЭ��ع���Լ��ѯ��Ӧ
  void OnRspQryRpcBondAgreementRepurchaseContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������ί���걨��Ӧ
  void OnRspRpcPwdServiceOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɶ���ѯ����ѯ�ͻ���Ӧ�Ĺɶ�������Ӧ
  void OnRspQryRpcTrdacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ѯ(������ҵ��)��Ӧ
  void OnRspQryRpcCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʲ���ϸ��ѯ��Ӧ
  void OnRspQryRpcAssetDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷ���ϸ��ѯ��Ӧ
  void OnRspQryRpcStkDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷݻ��ܲ�ѯ��Ӧ
  void OnRspQryRpcStkSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ�ʽ��ʻ��ʽ������ѯ��Ӧ
  void OnRspQryRpcCuacct2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�������Ӧ
  void OnRspQryRpcTrdacct2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�������Ӧ
  void OnRspQryRpcTrdacct3(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�в�ѯ��Ӧ
  void OnRspQryRpcOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�в�ѯ(������ҵ��)��Ӧ
  void OnRspQryRpcOrder2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ���ϸ��ѯ��Ӧ
  void OnRspQryRpcMatchDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ���ѯ(������ҵ��)��Ӧ
  void OnRspQryRpcMatch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ���ѯ��΢֤ȯר�ã���Ӧ
  void OnRspQryRpcMatchForTencentPay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷί�л��ܲ�ѯ, ��֤ȯ���������������Ӧ
  void OnRspQryRpcHisOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɽ����ܲ�ѯ, ��֤ȯ���������������Ӧ
  void OnRspQryRpcHisMatchSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ѯ�����ݹ�̨��ͨ���ʵ�ժҪ���ô�ӡ��Ϣ��ӡ���ݡ�΢֤ȯר����Ӧ
  void OnRspQryRpcDeliveryForTencentPay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�л��ܲ�ѯ,ordergroup+stkcode+bsflag��Ӧ
  void OnRspQryRpcOrderSummary2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�������ѯ��Ӧ
  void OnRspQryRpcOrg(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ����Ժ��ʽ��ʺ�������Ӧ
  void OnRspQryRpcAcctInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���������ѯ��Ӧ
  void OnRspQryRpcMktIntention(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ��Ӧ
  void OnRspQryRpcSeat(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ʽ��˻���Ϣ��Ӧ
  void OnRspQryRpcCuacctAcctInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͨ�ɷ�����ѯ�����У���Ӧ
  void OnRspQryRpcShNonCirculatingShareBalance(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڷ���ͨ�ɷ�����ѯ��Ӧ
  void OnRspQryRpcSzNonCirculatingShareBalance(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ϣ������˰��ѯ��Ӧ
  void OnRspQryRpcDividendWithholdingTax(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�����������Ӧ
  void OnRspQryRpcCustOrg(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ����ʽ��˺���Ӧ
  void OnRspQryRpcDepositoryCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڻ�������ʧ�ܲ�ѯ��Ӧ
  void OnRspQryRpcFloorFundRedemptionFailure(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������֤ȯ��ѯ��Ӧ
  void OnRspQryRpcBlacklistStk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڴ��ڽ��������ѯ��Ӧ
  void OnRspQryRpcSzBlockTradingMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �Ϻ����ڽ��������ѯ��Ӧ
  void OnRspQryRpcShBlockTradingMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڳ��ڻ���ֺ췽ʽ��ѯ��Ӧ
  void OnRspQryRpcSzFloorFundDividends(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���޹ɶ����ֶ�Ȳ�ѯ��Ӧ
  void OnRspQryRpcLimitedTrdacctReductionLimit(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ�ʽ��ʲ���ѯ��Ӧ
  void OnRspQryRpcHkCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ�ͻ���ծ��ѯ��Ӧ
  void OnRspQryRpcHkLiability(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Ȩ���ѯ��Ӧ
  void OnRspQryRpcHkEquity(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ����׼����Ӧ
  void OnRspRpcHkPreparationForOpeningAccount(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨδ������ϸ��ѯ��Ӧ
  void OnRspQryRpcHkUndeliveryDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�֤ͨȯ��Ϸѽ�����ϸ��Ӧ
  void OnRspRpcHkStkCombinationFeeDeliveryDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ�����ѯ��Ӧ
  void OnRspQryRpcHkDelivery(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ���ʵ���ѯ��Ӧ
  void OnRspQryRpcHkStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ��С�۲��ѯ��Ӧ
  void OnRspQryRpcHkMinSpread(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ�ο����ʲ�ѯ��Ӧ
  void OnRspQryRpcHkExchangeRate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ�г�����״̬��ѯ��Ӧ
  void OnRspQryRpcHkMarketStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ���֤ȯ��ѯ��Ӧ
  void OnRspQryRpcHkUnderlyingSecurity(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ����������ѯ��Ӧ
  void OnRspQryRpcHkCalendar(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨί������������Ӧ
  void OnRspRpcHkOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ����ί����Ӧ
  void OnRspRpcHkCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����ѯ��Ӧ
  void OnRspQryRpcHkCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ���ɽ���������ѯ��Ӧ
  void OnRspQryRpcHkMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ����ί����ϸ��ѯ��Ӧ
  void OnRspQryRpcHkOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ���׳ɽ���ѯ��Ӧ
  void OnRspQryRpcHkMatch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ������ʷί�в�ѯ��Ӧ
  void OnRspQryRpcHkHisOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �۹�ͨ���׳ɽ���ʷ��ѯ��Ӧ
  void OnRspQryRpcHkHisMatch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��תϵͳ֤ȯί���걨��Ӧ
  void OnRspRpcStkTranSysStkOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��תϵͳЭ��ת�������ѯ��Ӧ
  void OnRspQryRpcStkTranSysAgreementTransferMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��תϵͳȡ���������,֧������������Ӧ
  void OnRspRpcStkTranSysMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��תϵͳ����Ͷ���߲�ѯ��Ӧ
  void OnRspQryRpcStkTranSysRestrictedInvestor(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ת�г�����ͨ�ɷ�����ѯ��Ӧ
  void OnRspQryRpcStkTranSysNonCirculatingSharesBalance(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨����ί����ϸ��ѯ��Ӧ
  void OnRspQryRpcFixedIncomeSysOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨������ʷί����ϸ��ѯ��Ӧ
  void OnRspQryRpcFixedIncomeSysHisOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨���׳ɽ���ѯ��Ӧ
  void OnRspQryRpcFixedIncomeSysMatch(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨���ɽ���������ѯ��Ӧ
  void OnRspQryRpcFixedIncomeSysMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨ί������������Ӧ
  void OnRspRpcFixedIncomeSysOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ƽ̨����ί����Ӧ
  void OnRspRpcFixedIncomeSysCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����ѯ��Ӧ
  void OnRspQryRpcFixedIncomeSysCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯ������Ϣ��ѯ��Ӧ
  void OnRspQryRpcBondBasicInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨ծȯ�����ѯ��Ӧ
  void OnRspQryRpcBondMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒ�ݶ�ת�ó�����Ӧ
  void OnRspRpcFinancialProductShareTransferCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒ�ݶ�ת��ҵ����Ӧ
  void OnRspRpcFinancialProductShareTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒת����ϵ����Ϣ��ѯ��Ӧ
  void OnRspQryRpcFinancialProductShareTransferContactInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒ�ݶ�ת�÷��ü�����Ӧ
  void OnRspRpcFinancialProductShareTransferFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨ծȯ������Ϣ��ѯ��Ӧ
  void OnRspQryRpcBondParamInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί����ˮ��ѯ��Ӧ
  void OnRspQryRpcBondIntentionOrderStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒ�����ѯ��Ӧ
  void OnRspQryRpcFinancialProductMarket(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��̨���Ʋ�Ʒί�в�ѯ��Ӧ
  void OnRspQryRpcFinancialProductOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ����ί����Χ�ӿ���Ӧ
  void OnRspRpcRefinancingStkLendingOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ����ί�г�����Χ�ӿ���Ӧ
  void OnRspRpcRefinancingStkLendingCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�в�ѯ��Χ�ӿ���Ӧ
  void OnRspQryRpcRefinancingOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ǰ������Χ�ӿ���Ӧ
  void OnRspRpcRefinancingAdvanceRevert(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͬ��չ����Χ�ӿ���Ӧ
  void OnRspRpcRefinancingExtentionApprove(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ����ɳ���¼��ѯ��Χ�ӿ���Ӧ
  void OnRspQryRpcRefinancingStkLendingCanWithdraw(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ת��ȯδ�˽��Լ��ѯ��Χ�ӿ���Ӧ
  void OnRspQryRpcRefinancingOpenContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɳ�����ȯ��ѯ��Χ�ӿ���Ӧ
  void OnRspQryRpcRefinancingUnderlyingStkForLending(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��������Ϣ��ѯ��Χ�ӿ���Ӧ
  void OnRspQryRpcRefinancingLenderInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷ����ί�в�ѯ��Ӧ
  void OnRspQryRpcRefinancingHisLendingOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ�������˽��Լ��ѯ��Ӧ
  void OnRspQryRpcRefinancingStkLendingClosedContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ���Ԥ����Ϣ��Ӧ
  void OnRspQryRpcSysSecurityCustReservedInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ�Ԥ����Ϣ��Ӧ
  void OnRspRpcSysSecuritySetCustReservedInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͬ���ͻ���̬������Ӧ
  void OnRspRpcSysSecuritySyncDynamicToken(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�֤���ȡ�������Ӧ
  void OnRspRpcSysSecurityCertificateRandomCode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���̬����״̬������Ӧ
  void OnRspRpcSysSecuritySetDynamicTokenStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ȡһ���Զ�̬������Ӧ
  void OnRspRpcSysSecurityOneTimeDynamicPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���½����Ϣ������Ӧ
  void OnRspRpcSysSecuritySetLoginBindingInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���½����Ϣ��ѯ��Ӧ
  void OnRspQryRpcSysSecurityLoginBindingInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // У��ͻ�����������Ӧ
  void OnRspRpcSysSecurityVerifyTrdPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ȡ�ֻ�һ���Զ�̬������Ӧ
  void OnRspRpcSysSecurityMobileOneTimeDynamicPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�ETF�����ɷֹɵĳֲ�������Ӧ
  void OnRspQryRpcETFConstituentStkPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ͨ�ڵ��VIPϵͳ��֤ȯ������Ӧ
  void OnRspRpcCommVIPStkTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ֽ��ʲ�ת������Ӧ
  void OnRspRpcCashAssetBankTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ𻮲���ˮ��ѯ��Ӧ
  void OnRspQryRpcCapitalTransferStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Vip�ͻ��ʽ��ʲ�ͬ������ѯ��Ӧ
  void OnRspQryRpcVIPCuacctSyncTable(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڲ�Ʒ�ʵ�����Ϣ��ѯ��Ӧ
  void OnRspQryRpcFloorTradingProductAppropriatenessInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ��ʵ�����Ϣ��ѯ��Ӧ
  void OnRspQryRpcAppropriatenessInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ��볡�ڲ�Ʒ�ʵ���ƥ��У����Ӧ
  void OnRspRpcAppropriatenessMatchingCheck(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��¼����ҵ����ս�ʾ��ǩ����ˮ��Ӧ
  void OnRspRpcFloorTradingRiskDisclosureStatementSignedRecordFlow(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ϵͳ̽����Ӧ
  void OnRspBizStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)��Ӧ
  void OnRspQryPledgeShares(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ���ˮ��ѯ��Ӧ
  void OnRspQryFundFlow(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί��(����)��Ӧ
  void OnRspOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷ���ˮ��ѯ��Ӧ
  void OnRspQryStockFlow(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���н����ղ�ѯ��Ӧ
  void OnRspQrySettDate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �̺���������ѯ��Ӧ
  void OnRspQryLofMktInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ𻮲�(���н���)��Ӧ
  void OnRspFundTransferJzjy(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ʽ��ѯ(���н���)��Ӧ
  void OnRspQryExpendableFundJzjy(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��֤��Ϣ����(����¼��/�޸�)��Ӧ
  void OnRspAuthDataSetJzjy(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮����Ӧ
  void OnRspFundTransferNode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ𻮲�(���˻���ڵ�) �����ڵ�֮�仮����Ӧ[��ϯ����]
  void OnRspFundTransferNodeCiXi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��֤ת����Ӧ
  void OnRspBankStkTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ҪԼ�չ��չ�����Ϣ��ѯ��Ӧ
  void OnRspQryTenderSgrInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�����Ϲ����볷����Ӧ
  void OnRspEtfOfflineCancelOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�����Ϲ������ѯ��Ӧ
  void OnRspQryEtfOfflineOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �¹�������ѯ��Ӧ
  void OnRspQryNewStkCal(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ڴ�Ʒ����Ϣ��ѯ��Ӧ
  void OnRspQryStkInfoShm(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯ����ҵ��ԤԼί�г�����Ӧ
  void OnRspReserveOrderCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ծȯ���������ѯ��Ӧ
  void OnRspQryBondQuote(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // Э�̳ɽ��ر�������Ϣ��ѯ��Ӧ
  void OnRspQryReportMktInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯ��ȯ���׾���ԤԼί����Ϣ��ѯ��Ӧ
  void OnRspQryCashBondReserveOrderInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�л��ܲ�ѯ��Ӧ
  void OnRspQryOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɽ����ܲ�ѯ��Ӧ
  void OnRspQryMatchSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ�䶯���ܲ�ѯ��Ӧ
  void OnRspQryFundEffectSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷݱ䶯���ܲ�ѯ��Ӧ
  void OnRspQryStockEffectSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯ��ȯ���׾���ԤԼ��Ϣ��ѯ��Ӧ
  void OnRspQryCashBondTradeReservationInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯ��ȯ����ҵ��ο���Ϣ��ѯ��Ӧ
  void OnRspQryCashBondTradeProfitInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ծȯͨ����Ѻʽ�ع�ҵ��ο���Ϣ��ѯ��Ӧ
  void OnRspQryBondPledgeRepchProfitInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڽ���������Ϣ��ѯ��Ӧ
  void OnRspQryBlockTradingMktInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �̺����������Ϣ��ѯ��Ӧ
  void OnRspQryClosingBlockTradingMktInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ҵ���̺󶨼������ѯ��Ӧ
  void OnRspQryClosingMktSecondboard(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // REITs�����ǵ���״̬��ѯ��Ӧ
  void OnRspQryPriceStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ģ��ͻ���¼��Ӧ
  void OnRspUserLoginImpersonate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷݻ�����Ӧ
  void OnRspStockTransfer(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ETF�ͻ����Ӻ�ͬ��Ϣ��ѯ��Ӧ
  void OnRspQryEtfContractInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �Ϻ����ֹɷݶ�Ȳ�ѯ��Ӧ
  void OnRspQryReductLimitSh(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ڼ��ֹɷݶ�Ȳ�ѯ��Ӧ
  void OnRspQryReductLimitSz(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ƶ�������Ʋ�����ѯ
  void OnRspQryFreqTradeLmtParam(CFirstSetField* p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

};

END_NAMESPACE_MACLI

#endif  //__MA_CLI_STK_TRADE_API_H__