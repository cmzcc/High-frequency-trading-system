#if !defined(__MA_CLI_ALL_TRADE_API_H__)
#define __MA_CLI_ALL_TRADE_API_H__

#include "maCliTradeApi.h"
#include "maCliStkTradeApi.h"
#include "maCliFislTradeApi.h"
#include "maCliOptTradeApi.h"
#include "maCliFutureTradeApi.h"
#include "maCliCosTradeApi.h"

BGN_NAMESPACE_MACLI

class MATRADEAPI CCliAllTradeSpi : public CCliStkTradeSpi, public CCliFislTradeSpi, public CCliOptTradeSpi, public CCliFutureTradeSpi, public CCliCosTradeSpi
{
public:
  // Ĭ�Ϲ��캯��
  CCliAllTradeSpi() {}
  // ��������
  virtual ~CCliAllTradeSpi() {}

};

class MATRADEAPI CCliAllTradeApi : public CCliStkTradeApi, public CCliFislTradeApi, public CCliOptTradeApi, public CCliFutureTradeApi, public CCliCosTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliAllTradeApi(void);
  // ��������
  virtual ~CCliAllTradeApi(void);
  // ע��������Ϣ
  virtual int RegisterServer(CReqSysField* p_pstSysField);

public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);
  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

private:
};

END_NAMESPACE_MACLI
#endif //__MA_CLI_ALL_TRADE_API_H__