#pragma once

#include "maCliStkTradeApi.h"
#include "maCliStkTradeApiStruct.h"
#include "iniFileRW.h"

USE_NAMESPACE_MACLI

class CBpuStkTradeApi : public CCliStkTradeApi       //��Ʊ
{
public:
  // Ĭ�Ϲ��캯��
  CBpuStkTradeApi(void) {}

  // ��������
  virtual ~CBpuStkTradeApi(void) {}

  // ������Ϣ
  inline string GetClientInfo() { return string(CCliTradeApi::m_szClientInfo); }
};

  //��Ʊ��¼
extern void TestStkLogin(CCliStkTradeApi *p_pclTradeApi);

//������������
extern void TestStkSubTopic(CCliStkTradeApi *p_pclTradeApi, const char *pTopic);

//�˶�����
extern int TestStkUnSubTopic(CCliStkTradeApi *p_pclTradeApi);

//ί������
extern void TestStkOrder(CCliStkTradeApi *p_pclTradeApi, StkOrder stk_order);

//ί������EX
extern void TestStkOrderEx(CCliStkTradeApi *p_pclTradeApi);

//ί�г�������
extern void TestStkCancelOrder(CCliStkTradeApi *p_pclTradeApi, const StkCancel& stk_cancel);

//ETF ����ί������
extern void TestEtfBasketOrder(CCliStkTradeApi *p_pclTradeApi);

//���ί������
extern void TestStkCombOrder(CCliStkTradeApi *p_pclTradeApi);

//������ί��
extern void TestStkOrderFlash(CCliStkTradeApi *pclTradeApi);

//�����ٳ���
extern void TestStkCancelOrderFlash(CCliStkTradeApi *pclTradeApi);

//���������ί������
extern void TestStkCombOrderFlash(CCliStkTradeApi *p_pclTradeApi);

//�¹��깺
extern void TestStkOrderIPO(CCliStkTradeApi *p_pclTradeApi);

//����ί�в�ѯ����
extern void TestStkQryOrderInfo(CCliStkTradeApi *p_pclTradeApi);

//���ճɽ���ѯ����
extern void TestStkQryMatch(CCliStkTradeApi *p_pclTradeApi);

//�ɳ���ί�в�ѯ����
extern void TestStkQryCanWithdrawOrder(CCliStkTradeApi *p_pclTradeApi);

//�����ʽ��ѯ����
extern void TestStkQryExpendableFund(CCliStkTradeApi *p_pclTradeApi);

//���ùɷݲ�ѯ����
extern void TestStkQryExpendableShares(CCliStkTradeApi *p_pclTradeApi);

//֤ȯ��ֵ��Ȳ�ѯ����
extern void TestStkQryMktQuota(CCliStkTradeApi *p_pclTradeApi);

//�ع���Լ��ѯ
extern void TestStkQryRepchContract(CCliStkTradeApi *p_pclTradeApi);

//֤ȯ��Ϣ��ѯ
extern void TestStkQryStkInfo(CCliStkTradeApi *p_pclTradeApi);

//�����ڴ�Ʒ����Ϣ��ѯ
extern void TestStkQryStkInfoShm(CCliStkTradeApi *p_pclTradeApi);

//������̨�ʽ𻮲�
extern void TestRpcStkFundTransfer(CCliStkTradeApi *p_pclTradeApi);

//��ѯת������ҵ����Ϣ
extern void TestRpcStkBankTransBasicInfo(CCliStkTradeApi *p_pclTradeApi);

//��֤ת��
extern void TestRpcStkBankStkTrans(CCliStkTradeApi *p_pclTradeApi);

