#include "iniFileRW.h"
#include "../../include/constant.h"
#include "maBpuTradeUtil.h"
#include "MaThirdParty.h"
#include "maBpuTradeDefine.h"
#include "maBpuTradeGlobal.h"
#include "maBpuStkReq.h"
#include "MyFuncs.h"

using maclicpp::CLock;
using std::cout;
using std::cin;


//??????
void TestStkLogin(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkUserLoginField stReqUserLoginField = {0};
  char szThirdParty[1024 + 1] = {'\0'};
  int rn = GetThirdParty(szThirdParty, sizeof(szThirdParty));

  set_section("StkUserLogin");
  read_profile_string("ACCT_TYPE", stReqUserLoginField.szAcctType, sizeof(stReqUserLoginField.szAcctType), "Z");		//???????
  read_profile_string("ACCT_ID", stReqUserLoginField.szAcctId, sizeof(stReqUserLoginField.szAcctId), "165000004");   //??????  	
  read_profile_string("ENCRYPT_KEY", stReqUserLoginField.szEncryptKey, sizeof(stReqUserLoginField.szEncryptKey), "10301105");//????????
  char tmp[256+1];
  read_profile_string("AUTH_DATA", tmp, sizeof(stReqUserLoginField.szAuthData), "111111");
  char *szAuthData = (char*) acl_base64_decode(tmp, strlen(tmp));
  std::cout << "szAuthData:" << szAuthData << std::endl;
  strncpy(stReqUserLoginField.szAuthData, szAuthData, sizeof(stReqUserLoginField.szAuthData) - 1);
  stReqUserLoginField.chUseScope = read_profile_char("USE_SCOPE", '0');            //??????? '0':????????
  stReqUserLoginField.chAuthType = read_profile_char("AUTH_TYPE", '0');            //??????? '0':????
  strncpy(stReqUserLoginField.szThirdParty, szThirdParty, strlen(szThirdParty));
  g_stBpuCtx.trdCtxMap[StkSys].Reset();  //????
  cout
  << "Auth Data: " << stReqUserLoginField.szAuthData
  << std::endl
  << "Acct ID: " << stReqUserLoginField.szAcctId
  << std::endl
  << "Acct Type: " << stReqUserLoginField.szAcctType
  << std::endl
  << "Encrypt Key: " << stReqUserLoginField.szEncryptKey
  << std::endl
  << "Use Scope: " << stReqUserLoginField.chUseScope
  << std::endl
  << "Auth Type: " << stReqUserLoginField.chAuthType
  << std::endl
  << "Third Party: " << stReqUserLoginField.szThirdParty
  << std::endl;
  int iRetCode=p_pclTradeApi->ReqUserLogin(&stReqUserLoginField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//????????????
void TestStkSubTopic(CCliStkTradeApi *p_pclTradeApi, const char *pTopic)
{
  int  iRetCode = 0;
  char szTopic[16 + 1] = {'\0'};

  set_section("Common");

  char chDataSet = read_profile_char("DATA_SET", '0');    

  map<string, string>::iterator it = g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct.begin();

  for(; it!=g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct.end(); ++it)
  {
    memset(szTopic, 0, sizeof(szTopic));
    sprintf(szTopic, "%s%s", pTopic, it->first.c_str());
    iRetCode = p_pclTradeApi->SubTopic(szTopic, it->second.c_str(), chDataSet);
    CHECK_RETCODE(iRetCode,p_pclTradeApi);
  }
}

//???????
int TestStkUnSubTopic(CCliStkTradeApi *p_pclTradeApi)
{
  char szTopic[16 + 1] = {'\0'};
  long long llAcceptSn = 0LL;

  cout << "Topic: ";
  cin >> szTopic;
  cout << "AcceptSn: ";
  cin >> llAcceptSn;

  // ???????
  int iRetCode = p_pclTradeApi->UnsubTopic(szTopic, llAcceptSn);
  CHECK_RETCODE(iRetCode, p_pclTradeApi);

  return iRetCode;
}

//???????
void TestStkOrder(CCliStkTradeApi *p_pclTradeApi, StkOrder stk_order)
{
  CReqStkOrderField stField = {0};
  set_section("StkOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  strncpy(stField.szStkbd, stk_order.STKBD.c_str(), sizeof(stField.szStkbd) - 1);
  stField.szStkbd[sizeof(stField.szStkbd) - 1] = '\0';
  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[stField.szStkbd].c_str(), sizeof(stField.szTrdacct) - 1);
  stField.llOrderQty = stk_order.ORDER_QTY;
  stField.iStkBiz	= stk_order.STK_BIZ;
  stField.iStkBizAction = stk_order.STK_BIZ_ACTION;
  strncpy(stField.szOrderPrice, stk_order.ORDER_PRICE.c_str(), sizeof(stField.szOrderPrice) - 1);
  stField.szOrderPrice[sizeof(stField.szOrderPrice) - 1] = '\0';
  strncpy(stField.szStkCode, stk_order.STK_CODE.c_str(), sizeof(stField.szStkCode) - 1);
  stField.szStkCode[sizeof(stField.szStkCode) - 1] = '\0';
  stField.iOrderBsn = stk_order.ORDER_BSN;
  stField.iCuacctSn = stk_order.CUACCT_SN;
  stField.chSecurityLevel = '1';
  int iRetCode=p_pclTradeApi->ReqOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//???????
void TestStkOrderEx(CCliStkTradeApi *p_pclTradeApi)
{	
  CReqStkOrderExField stField = {0};
  set_section("StkOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode; 
  read_profile_string("STKBD", stField.szStkbd, sizeof(stField.szStkbd), "10");   //??????
  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[stField.szStkbd].c_str(), sizeof(stField.szTrdacct) - 1);
  stField.llOrderQty = read_profile_int64("ORDER_QTY", 100);	
  stField.iStkBiz	= read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 120);
  read_profile_string("ORDER_PRICE", stField.szOrderPrice, sizeof(stField.szOrderPrice), "0.0");	
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "000001");	
  stField.iOrderBsn = read_profile_int("ORDER_BSN", 0);
  stField.iCuacctSn = read_profile_int("CUACCT_SN", 0);
  int iRetCode=p_pclTradeApi->ReqOrderEx(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//???????????
void TestStkCancelOrder(CCliStkTradeApi *p_pclTradeApi, const StkCancel& stk_cancel)
{
  CReqStkCancelOrderField stField = {'\0'};
  char szStkbd[2+1] = {'\0'};
  char szOrderId[32+1] = {'\0'};

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  strncpy(stField.szStkbd, stk_cancel.szStkbd.c_str(), sizeof(stField.szStkbd) - 1);
  strncpy(stField.szOrderId, stk_cancel.szOrderId.c_str(), sizeof(stField.szOrderId) - 1);
  stField.iOrderBsn = stk_cancel.iOrderBsn;

  int iRetCode=p_pclTradeApi->ReqCancelOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//ETF ???????????
void TestEtfBasketOrder(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkEtfOrderField stField = {0};

  set_section("ETFOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STKBD", stField.szStkbd, sizeof(stField.szStkbd), "10");   //??????
  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[stField.szStkbd].c_str(), sizeof(stField.szTrdacct) - 1);
  read_profile_string("ETF_CODE", stField.szEtfCode, sizeof(stField.szEtfCode),"0");
  stField.llOrderQty = read_profile_int64("ORDER_QTY", 1);
  stField.iStkBiz = read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 120); 
  stField.chBizType	= read_profile_char("STK_BIZ_TYPE", 'B'); //????
  stField.chSecurityLevel = '1';

  int iRetCode=p_pclTradeApi->ReqEtfOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//??????????
void TestStkCombOrder(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkCombOrderField stField = {0};

  set_section("StkCombOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STRATEGY_TEXT", stField.szStrategyText, sizeof(stField.szStrategyText), "{0|0|0|0|0|0}");
  stField.iStkBiz	= read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 100);
  stField.chErrorFlag = read_profile_char("ERROR_FLAG",'0');
  stField.chSecurityLevel = '1';

  int iRetCode=p_pclTradeApi->ReqCombOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//?????????
void TestStkOrderFlash(CCliStkTradeApi *pclTradeApi)
{
  CReqStkOrderFlashField stField = {0};
  set_section("StkOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STKBD", stField.szStkbd, sizeof(stField.szStkbd), "10");   //??????
  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[stField.szStkbd].c_str(), sizeof(stField.szTrdacct) - 1);
  stField.llOrderQty = read_profile_int64("ORDER_QTY", 100);	
  stField.iStkBiz	= read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 120);
  read_profile_string("ORDER_PRICE", stField.szOrderPrice, sizeof(stField.szOrderPrice), "0.0");	
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "000001");	
  stField.iOrderBsn = read_profile_int("ORDER_BSN", 0);
  stField.iCuacctSn = read_profile_int("CUACCT_SN", 0);

  int iRetCode = pclTradeApi->ReqOrderFlash(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode, pclTradeApi);
}

//?????????
void TestStkCancelOrderFlash(CCliStkTradeApi *pclTradeApi)
{
  CReqStkCancelOrderFlashField stField = {0};

  cout << "?????????????????: ";
  cin >> stField.szStkbd;

  cout << "?????????????????: ";
  cin >> stField.szOrderId;

  cout << "???????????: ";
  cin >> stField.iStkBiz;

  cout << "?????????????: ";
  cin >> stField.iOrderBsn;

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;

  int iRetCode = pclTradeApi->ReqCancelOrderFlash(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode, pclTradeApi);
}

//????????????????
void TestStkCombOrderFlash(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkCombOrderFlashField stField = {0};

  set_section("StkCombOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STRATEGY_TEXT", stField.szStrategyText, sizeof(stField.szStrategyText), "{0|0|0|0|0|0}");
  stField.iStkBiz	= read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 100);
  stField.chErrorFlag = read_profile_char("ERROR_FLAG",'0');

  int iRetCode=p_pclTradeApi->ReqCombOrderFlash(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//?????
void TestStkOrderIPO(CCliStkTradeApi *p_pclTradeApi)
{	
  CReqStkOrderField stField = {0};
  set_section("OrderIPO");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode; 
  read_profile_string("STKBD", stField.szStkbd, sizeof(stField.szStkbd), "10");   //??????
  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[stField.szStkbd].c_str(), sizeof(stField.szTrdacct) - 1);
  stField.llOrderQty = read_profile_int64("ORDER_QTY", 100);	
  stField.iStkBiz	= read_profile_int("STK_BIZ", 100);
  stField.iStkBizAction = read_profile_int("STK_BIZ_ACTION", 120);
  read_profile_string("ORDER_PRICE", stField.szOrderPrice, sizeof(stField.szOrderPrice), "0.0");	
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "000001");	
  stField.chSecurityLevel = '1';
  int iRetCode=p_pclTradeApi->ReqOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//??????????????
void TestStkQryOrderInfo(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryCurrDayOrderField stField = {0};

  set_section("QryCurrDayOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "");
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');
  stField.iQueryNum = read_profile_int("QUERY_NUM", 1000);
  stField.chFlag = read_profile_char("FLAG", '\0');

  int iRetCode=p_pclTradeApi->ReqQryCurrDayOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}
//?????????????
void TestStkQryMatch(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryCurrDayFillField stField = {0};

  set_section("QryCurrDayFill");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "");
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');
  stField.iQueryNum = read_profile_int("QUERY_NUM", 1000);
  stField.chFlag = read_profile_char("FLAG", '\0');

  int iRetCode=p_pclTradeApi->ReqQryCurrDayFill(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//???????????????
void TestStkQryCanWithdrawOrder(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryCanWithdrawOrderField stField = {0};

  set_section("QryCanWithdrawOrder");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "");
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');
  stField.iQueryNum = read_profile_int("QUERY_NUM", 1000);

  int iRetCode=p_pclTradeApi->ReqQryCanWithdrawOrder(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//?????????????
void TestStkQryExpendableFund(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryExpendableFundField stField = {0};

  set_section("ExpendableFund");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  stField.chCurrency = read_profile_char("CURRENCY", '0');
  stField.iValueFlag = read_profile_int("VALUE_FLAG", 31);

  int iRetCode=p_pclTradeApi->ReqQryExpendableFund(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//?????????????
void TestStkQryExpendableShares(CCliStkTradeApi *p_pclTradeApi)
{
  int iRetCode = 0;
  g_ExpShsCnt = 0LL;
  g_bFinish = false;
  memset(g_szPos, 0, sizeof(g_szPos));
  CReqStkQryExpendableSharesField stField = {0};

  set_section("ExpendableShares");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');
  g_iQryCntPer = read_profile_int("QUERY_NUM", 1000);  //????????
  stField.iQueryNum = g_iQryCntPer;

  {
    CLock lock(g_mutex);
    while(!g_bFinish)
    {
      strncpy(stField.szQueryPos, g_szPos, sizeof(stField.szQueryPos)-1);  //??????
      stField.szQueryPos[strlen(stField.szQueryPos)] = '\0';
      iRetCode = p_pclTradeApi->ReqQryExpendableShares(&stField, ++g_llRequestId);
      CHECK_RETCODE(iRetCode,p_pclTradeApi);
      g_event.Wait(lock);
    }
  }

  cout << "-------------------------------------------------------------------------------" << std::endl;
  cout << "???????????????:" << g_ExpShsCnt << std::endl;
}

//??????????????
void TestStkQryMktQuota(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkMktQuotaField stField={0};
  char szStkBd[2 + 1] = {'\0'};

  cout << "??????????: ";
  cin >> szStkBd;

  strncpy(stField.szTrdacct, g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[szStkBd].c_str(), sizeof(stField.szTrdacct) - 1);

  int iRetCode = p_pclTradeApi->ReqQryMktQuota(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//?????????
void TestStkQryRepchContract(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryRepchContractField stField={0};

  set_section("RepchContract");

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  stField.chFlag = read_profile_char("FLAG", '0');
  stField.iIntOrg = g_stBpuCtx.trdCtxMap[StkSys].iIntOrg;
  stField.iRepchDate = read_profile_int("REPCH_DATE", 0);
  stField.iBgnDate = read_profile_int("BEIGN_DATE", 0);
  stField.iEndDate = read_profile_int("END_DATE", 0);
  read_profile_string("QUERY_POS", stField.szQueryPos, sizeof(stField.szQueryPos), "");
  stField.iQueryNum = read_profile_int("QUERY_NUM", 0);
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');

  int iRetCode = p_pclTradeApi->ReqQryRepchContract(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//????????
void TestStkQryStkInfo(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryStkInfoField stField={0};

  set_section("QryStkInfo");

  read_profile_string("STK_BD", stField.szStkbd, sizeof(stField.szStkbd), "");
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "");

  int iRetCode = p_pclTradeApi->ReqQryStkInfo(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//????????????????
void TestStkQryStkInfoShm(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkQryStkInfoShmField stField={0};

  set_section("QryStkInfoShm");

  read_profile_string("STK_BD", stField.szStkbd, sizeof(stField.szStkbd), "");
  read_profile_string("STK_CODE", stField.szStkCode, sizeof(stField.szStkCode), "");
  stField.chQueryFlag = read_profile_char("QUERY_FLAG", '0');
  read_profile_string("QUERY_POS", stField.szQueryPos, sizeof(stField.szQueryPos), "");
  stField.iQueryNum = read_profile_int("QUERY_NUM", 0);

  int iRetCode = p_pclTradeApi->ReqQryStkInfoShm(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//???????????
void TestRpcStkFundTransfer(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkFundTransferField stField = {'\0'};
  long long llTransAmt = 0L;
  char chDirect = '\0';
  char szOrgId[4 + 1] = {'\0'};

  set_section("FundTransfer");

  sprintf(stField.szOrgId, "%d", g_stBpuCtx.trdCtxMap[StkSys].iIntOrg);
  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  stField.chCurrency = '0';
  read_profile_string("TRANS_AMT", stField.szFundAvl, sizeof(stField.szFundAvl), "1000");
  stField.chDirect = read_profile_char("DIRECT", '0');

  int iRetCode = p_pclTradeApi->ReqQryFundTransfer(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//????????????????
void TestRpcStkBankTransBasicInfo(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkBankTransBasicInfoField stField = {'\0'};

  cout << "??????????????";
  cin >> stField.szBankCode;
  stField.chCurrency = '0';

  int iRetCode = p_pclTradeApi->ReqQryBankTransBasicInfo(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}

//??????
void TestRpcStkBankStkTrans(CCliStkTradeApi *p_pclTradeApi)
{
  CReqStkBankStkTransField stField = {'\0'};

  char szBankCode[4+1] = {'\0'};
  char chTranType = '\0';
  long long llTransAmt = 0L;

  cout << "????????";
  cin >> stField.szBankCode;

  cout << "????????";
  cin >> stField.chBankTranType;

  cout << "?????";
  cin >> stField.szTransAmt;

  stField.llCuacctCode = g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode;
  stField.chCurrency = '0';

  int iRetCode = p_pclTradeApi->ReqBankStkTrans(&stField, ++g_llRequestId);
  CHECK_RETCODE(iRetCode,p_pclTradeApi);
}
