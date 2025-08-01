#pragma once
#include "../EventQueue/EventQueue.h"
#include "MyFuncs.h"
#include "Event.h"
#include "Mutex.h"
#include "maBpuTradeUtil.h"
#include "iniFileRW.h"
#include "MaThirdParty.h"
#include "maCliStkTradeApi.h"
#include "maCliStkTradeApiStruct.h"
#include "maBpuTradeDefine.h"
#include "maBpuTradeGlobal.h"
#include "maBpuStkReq.h"
#include "logger.h"
#include <vector>
#include "../EventQueue/EventQueue.h"
#include "../macli/global.h"

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#include <Windows.h>
#define atoll _atoi64
#else
#include <sys/types.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>
#endif

using std::string;
using std::cout;
using std::endl;
using maclicpp::CLock;

//class EventQueue;

struct errordata {
  LONGLONG request_id;
};

// static std::mutex re_mutex;

USE_NAMESPACE_MACLI

class CBpuStkTradeSpi : public CCliStkTradeSpi
{
public:
  bool is_connected = false;
  std::shared_ptr<spdlog::logger> logger;
  CBpuStkTradeSpi(CBpuStkTradeApi *p_pClientStkTradeApi, EventQueue* que) : m_pExCliStkTradeApi(p_pClientStkTradeApi), m_que(que)
  {
    logger = Logger::get();
    m_bLoginFlag = false;
  }

  ~CBpuStkTradeSpi(void) {}

  //客户端与服务器成功建立通信连接后，该方法被调用
  virtual int OnConnected(void)
  {
    cout << "客户端与股票服务器成功建立通信连接" <<  std::endl;
    is_connected = true;
    return 0;
  }

  //客户端与服务器成功的通信连接断开时，该方法被调用
  virtual int OnDisconnected(int p_nReason, const char *p_pszErrInfo)
  {
    cout << "客户端与服务器通信连接断开[" << p_nReason << "][" << p_pszErrInfo << "]" << std::endl;
    return 0;
  }

  //心跳应答
  virtual int OnRspHeartBeat(CFirstSetField *p_pFirstSet, CRspHeartBeatField *p_pRspHeartBeatField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << " OnRspHeartBeat:" << "MsgCode:" <<  p_pFirstSet->iMsgCode;
      cout << " MsgLevel:" << p_pFirstSet->chMsgLevel;
      cout << " MsgDebug:" << p_pFirstSet->szMsgDebug;
      cout << " MsgText:" << p_pFirstSet->szMsgText << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL != p_pRspHeartBeatField)
    {
      cout << " OnRspHeartBeat:[" << p_iFieldNum << "," << p_iFieldIndex << "]\n";
      cout << " ServerName:" << p_pRspHeartBeatField->szServerSiteName;
      cout << " IP:" << p_pRspHeartBeatField->szServerSiteIP;
      cout << " NodeID:" << p_pRspHeartBeatField->szServerNodeId;
      cout << " NodeGID:" << p_pRspHeartBeatField->szServerNodeGid;
      cout << " NodePW:" << p_pRspHeartBeatField->szServerNodePwd;
      cout << " NodeType:" << p_pRspHeartBeatField->szServerNodeType;
      cout << " NodeUse:" << p_pRspHeartBeatField->szServerNodeUse;
      cout << " LocalNodeID:" << p_pRspHeartBeatField->szServerLocalNodeId;
      cout << " BackupIP:" << p_pRspHeartBeatField->szServerBackIp << std::endl;
    }
    return 0;
  }

  //用户登录请求应答
  virtual int OnRspUserLogin(CFirstSetField *p_pFirstSet, CRspStkUserLoginField *p_pRspUserLoginField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) 
  {
    // printf("%s:%d\n", __FILE__, __LINE__);

    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      string msg = p_pFirstSet->szMsgText;
      std::string utf8_str = gbk_to_utf8(msg);
      cout << "股票登录应答:" << p_pFirstSet->iMsgCode  <<  "|" << utf8_str << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspUserLoginField)
    {
      cout << "-------------------------------------------------------------------------------" <<  std::endl;
      std::cerr << "股票登录应答:(" << p_iFieldNum << ',' << p_iFieldIndex << ")\n";
      m_bLoginFlag = true;
      cout << " 客户代码:" << p_pRspUserLoginField->llCustCode ;
      cout << " 资产账户:" << p_pRspUserLoginField->llCuacctCode ;       
      cout << " 交易市场:" << p_pRspUserLoginField->chStkex;
      cout << " 交易板块:" << p_pRspUserLoginField->szStkbd;
      cout << " 证券账户:" << p_pRspUserLoginField->szStkTrdacct;
      cout << " 内部机构:" << p_pRspUserLoginField->iIntOrg;
      cout << " 账户状态:" << p_pRspUserLoginField->chTrdacctStatus;
      cout << " 交易单元:" << p_pRspUserLoginField->szStkpbu;
      cout << " 账户类型:" << p_pRspUserLoginField->szAcctType;
      cout << " 账户标识:" << p_pRspUserLoginField->szAcctId;
      cout << " 账户名称:" << gbk_to_utf8(p_pRspUserLoginField->szTrdacctName);
      cout << " 深圳软加速模式:" << p_pRspUserLoginField->chSzFlashMode;
      cout << " 上海软加速模式:" << p_pRspUserLoginField->chShFlashMode;
      cout << " 加速启用标志:" << p_pRspUserLoginField->chFlashEnableFlag;
      cout << " 会话凭证:" << p_pRspUserLoginField->szSessionId <<  std::endl;
      session_ID = p_pRspUserLoginField->szSessionId;

      if(1 == p_iFieldIndex)
      {
        g_stBpuCtx.trdCtxMap[StkSys].llCustCode = p_pRspUserLoginField->llCustCode;
        g_stBpuCtx.trdCtxMap[StkSys].llCuacctCode = p_pRspUserLoginField->llCuacctCode;
        g_stBpuCtx.trdCtxMap[StkSys].iIntOrg = p_pRspUserLoginField->iIntOrg;
        string strCliRemark = m_pExCliStkTradeApi->GetClientInfo();
        strncpy(g_stBpuCtx.trdCtxMap[StkSys].szCliRemark, strCliRemark.c_str(), sizeof(g_stBpuCtx.trdCtxMap[StkSys].szCliRemark)-1);

      }

      g_stBpuCtx.trdCtxMap[StkSys].mapBdTrdAcct[p_pRspUserLoginField->szStkbd] = p_pRspUserLoginField->szStkTrdacct;   //获取证券账户
    }
    return 0;
  }

  //订阅应答
  virtual int OnRtnSubTopic(CRspSubTopicField* p_pRspSubTopicField)
  {
    if (p_pRspSubTopicField == NULL)
    {
      cout << "订阅失败" << std::endl;
      return -1;
    }
    cout << "-------------------------------------------------------------------------------" <<  std::endl;
    cout << "订阅应答:\n";
    cout << " Topic:" << p_pRspSubTopicField->szTopic;
    cout << " Filter:" << p_pRspSubTopicField->szFilter;
    cout << " Channel:" << p_pRspSubTopicField->szChannel;
    cout << " DataSet:" << p_pRspSubTopicField->chDataSet;
    cout << " AcceptSn:" << p_pRspSubTopicField->llAcceptSn << std::endl;
    logger->info("subscribe successfully AcceptSn : {}", p_pRspSubTopicField->llAcceptSn);
    return 0;
  }

  //取消订阅应答
  virtual int OnRtnUnsubTopic(CRspUnsubTopicField* p_pRspUnsubTopicField)
  {
    if (p_pRspUnsubTopicField == NULL)
    {
      cout << "退订失败" << std::endl;
      return -1;
    }
    cout << "-------------------------------------------------------------------------------" <<  std::endl;
    cout << "退订应答:\n";
    cout << " Topic:" << p_pRspUnsubTopicField->szTopic;	 
    cout << " AcceptSn:" << p_pRspUnsubTopicField->llAcceptSn << std::endl;
    return 0;
  }

  //买卖委托应答
  virtual int OnRspOrder(CFirstSetField *p_pFirstSet, CRspStkOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      if (p_pFirstSet->iMsgCode != 0) {
        std::lock_guard<std::mutex> a_lock(re_mutex);
        auto error_data = std::make_shared<EventData>();
        error_data->type = Error;
        auto tmp = std::make_shared<errordata>();
        tmp->request_id = p_llRequestId;
        error_data->data = std::static_pointer_cast<void>(tmp);
        m_que->enqueue(Error, error_data);
      }
      if (p_pFirstSet->iMsgCode == 11314) {
        std::cerr << "request id : " << p_llRequestId << std::endl;
      }
      cout << "买卖委托应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << gbk_to_utf8(p_pFirstSet->szMsgText) << std::endl;
      logger->info("买卖委托应答: {} | {}", p_pFirstSet->iMsgCode, gbk_to_utf8(p_pFirstSet->szMsgText));
    }

    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" <<  std::endl;
      cout << "委托应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 资产账户:" << p_pRspField->llCuacctCode;                  
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                    
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 交易单元:" << p_pRspField->szStkpbu;               
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券代码:" << p_pRspField->szStkCode;              
      cout << " 证券名称:" << gbk_to_utf8(p_pRspField->szStkName);
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 业务行为:" << p_pRspField->iStkBizAction;                 
      cout << " 证券账户:" << p_pRspField->szTrdacct;             
      cout << " 账户序号:" << p_pRspField->iCuacctSn << std::endl;

      auto order_data = std::make_shared<EventData>();
      order_data->type = Order;
      auto order_copy = std::make_shared<CRspStkOrderField>(*p_pRspField);
      order_data->data = std::static_pointer_cast<void>(order_copy);
      m_que->enqueue(Order, order_data);
      logger->info("委托确认： 委托批号: {} | 证券代码: {} | 委托价格: {} | 委托数量 : {} | 证券业务: {}",
                   p_pRspField->iOrderBsn, p_pRspField->szStkCode, p_pRspField->szOrderPrice, p_pRspField->llOrderQty, p_pRspField->iStkBiz);
    }
    return 0;
  }

  // 买卖委托(快速)响应
  virtual int OnRspOrderEx(CFirstSetField *p_pFirstSet, CRspStkOrderExField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "买卖委托应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;
    }

    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" <<  std::endl;
      cout << "委托应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 账户序号:" << p_pRspField->iCuacctSn << std::endl;  
    }
    return 0;

  }


  //确认回报
  virtual int OnRtnOrderConfirm(CRtnStkOrderConfirmField *p_pRtnOrderConfirmField)
  {
    if (p_pRtnOrderConfirmField == NULL)
    {
      return -1;
    }

    cout << "-------------------------------------------------------------------------------" <<  std::endl;
    cout << "[委托确认回报]" << std::endl;
    cout << " 交易市场:" << p_pRtnOrderConfirmField->chStkex;
    cout << " 证券代码:" << p_pRtnOrderConfirmField->szStkCode;
    cout << " 合同序号:" << p_pRtnOrderConfirmField->szOrderId;
    cout << " 交易账户:" << p_pRtnOrderConfirmField->szTrdacct;
    cout << " 撤单标志:" << p_pRtnOrderConfirmField->chIsWithdraw;
    cout << " 客户代码:" << p_pRtnOrderConfirmField->llCustCode;
    cout << " 资产账户:" << p_pRtnOrderConfirmField->llCuacctCode;
    cout << " 委托批号:" << p_pRtnOrderConfirmField->iOrderBsn;
    cout << " 账户序号:" << p_pRtnOrderConfirmField->iCuacctSn;
    cout << " 交易板块:" << p_pRtnOrderConfirmField->szStkbd;
    cout << " 委托状态:" << p_pRtnOrderConfirmField->chOrderStatus;
    cout << " 证券业务:" << p_pRtnOrderConfirmField->iStkBiz;
    cout << " 业务行为:" << p_pRtnOrderConfirmField->iStkBizAction;
    cout << " 账户属性:" << p_pRtnOrderConfirmField->chCuacctAttr;
    cout << " 委托日期" << p_pRtnOrderConfirmField->iOrderDate;
    cout << " 委托序号" << p_pRtnOrderConfirmField->iOrderSn;
    cout << " 内部机构" << p_pRtnOrderConfirmField->iIntOrg;
    cout << " 交易单元" << p_pRtnOrderConfirmField->szStkpbu;
    cout << " 委托价格" << p_pRtnOrderConfirmField->szOrderPrice;
    cout << " 委托数量" << p_pRtnOrderConfirmField->llOrderQty << std::endl;
    return 0;
  }

  //成交回报
  virtual int OnRtnOrderFill(CRtnStkOrderFillField *p_pRtnOrderFillField)
  {
    if (p_pRtnOrderFillField == NULL) 
    {
      cout << "p_pRtnOrderFillField is NULL" << std::endl;			
      return -1;
    }

    cout << "-------------------------------------------------------------------------------" <<  std::endl;
    cout << "[成交回报]" << std::endl;
    cout << " 交易账户:" << p_pRtnOrderFillField->szTrdacct;
    cout << " 账户序号:" << p_pRtnOrderFillField->iCuacctSn;	
    cout << " 成交日期:" << p_pRtnOrderFillField->iMatchedDate;
    cout << " 成交时间:" << p_pRtnOrderFillField->szMatchedTime;
    cout << " 交易市场:" << p_pRtnOrderFillField->chStkex;
    cout << " 交易板块:" << p_pRtnOrderFillField->szStkbd;
    cout << " 成交编号:" << p_pRtnOrderFillField->szMatchedSn;
    cout << " 证券代码:" << p_pRtnOrderFillField->szStkCode;
    cout << " 合同序号:" << p_pRtnOrderFillField->szOrderId;			
    cout << " 成交数量:" << p_pRtnOrderFillField->llMatchedQty;
    cout << " 成交价格:" << p_pRtnOrderFillField->szMatchedPrice;
    cout << " 实时清算金额:" << p_pRtnOrderFillField->szRltSettAmt;
    cout << " 资金可用金额(成交后):" << p_pRtnOrderFillField->szFundAvl;
    cout << " 证券可用数量(成交后):" << p_pRtnOrderFillField->llStkAvl;
    cout << " 撤单标志:" << p_pRtnOrderFillField->chIsWithdraw;
    cout << " 委托批号:" << p_pRtnOrderFillField->iOrderBsn;		
    cout << " 成交类型:" << p_pRtnOrderFillField->chMatchedType;
    cout << " 证券业务:" << p_pRtnOrderFillField->iStkBiz;
    cout << " 业务行为:" << p_pRtnOrderFillField->iStkBizAction;
    cout << " 申报信息:" << p_pRtnOrderFillField->szOfferRetMsg << std::endl;

    auto fill_data = std::make_shared<EventData>();
    fill_data->type = Trade;
    auto fill_copy = std::make_shared<CRtnStkOrderFillField>(*p_pRtnOrderFillField);
    fill_data->data = std::static_pointer_cast<void>(fill_copy);
    m_que->enqueue(Trade, fill_data);
    logger->info("成交确认： 撤单: {} | 证券代码: {} | 成交价格: {} | 成交数量 : {} | 成交时间: {} | 累计成交: {}",
      p_pRtnOrderFillField->chIsWithdraw, p_pRtnOrderFillField->szStkCode, p_pRtnOrderFillField->szMatchedPrice, p_pRtnOrderFillField->llMatchedQty, p_pRtnOrderFillField->szMatchedTime, p_pRtnOrderFillField->llTotalMatchedQty);

    return 0;
  }

  //委托撤单应答
  virtual int OnRspCancelOrder(CFirstSetField *p_pFirstSet, CRspStkCancelOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "委托撤单应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "委托撤单应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 资产账户:" << p_pRspField->llCuacctCode;                  
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                    
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 交易单元:" << p_pRspField->szStkpbu;               
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券代码:" << p_pRspField->szStkCode;              
      cout << " 证券名称:" << p_pRspField->szStkName;             
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 业务行为:" << p_pRspField->iStkBizAction;                 
      cout << " 内部撤单标志:" << p_pRspField->chCancelStatus;               
      cout << " 证券账户:" << p_pRspField->szTrdacct;             
      cout << " 内撤信息:" << p_pRspField->szMsgOk;               
      cout << " 撤单列表:" << p_pRspField->szCancelList << std::endl;        
    }
    return 0;
  }

  //ETF 篮子委托应答
  virtual int OnRspEtfOrder(CFirstSetField *p_pFirstSet, CRspStkEtfOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "ETF篮子委托应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;

    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "ETF篮子委托应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;				   
      cout << " 合同序号:" << p_pRspField->szOrderId;           
      cout << " 资产账户:" << p_pRspField->llCuacctCode;					   
      cout << " 委托价格:" << p_pRspField->szOrderPrice;        
      cout << " 委托数量:" << p_pRspField->llOrderQty;						
      cout << " 委托金额:" << p_pRspField->szOrderAmt;          
      cout << " 冻结金额:" << p_pRspField->szOrderFrzAmt;       
      cout << " 交易单元:" << p_pRspField->szStkpbu;             
      cout << " 交易板块:" << p_pRspField->szStkbd;              
      cout << " 证券账户:" << p_pRspField->szTrdacct;           
      cout << " 证券代码:" << p_pRspField->szStkCode;          
      cout << " 证券名称:" << p_pRspField->szStkName;           
      cout << " 证券业务:" << p_pRspField->iStkBiz;                    
      cout << " 业务行为:" << p_pRspField->iStkBizAction << std::endl;              
    }
    return 0;
  }

  //组合委托应答
  virtual int OnRspCombOrder(CFirstSetField *p_pFirstSet, CRspStkCombOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "组合委托应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;										

    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "组合委托应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 资产账户:" << p_pRspField->llCuacctCode;                       
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                         
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 交易单元:" << p_pRspField->szStkpbu;               
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券代码:" << p_pRspField->szStkCode;              
      cout << " 证券名称:" << p_pRspField->szStkName;             
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 业务行为:" << p_pRspField->iStkBizAction;                 
      cout << " 证券账户:" << p_pRspField->szTrdacct;             
      cout << " 账户序号:" << p_pRspField->iCuacctSn;                     
      cout << " 委托结果:" << p_pRspField->iOrderRet;                     
      cout << " 返回信息:" << p_pRspField->szRetInfo << std::endl;   
    }
    return 0;
  }

  // 买卖委托响应(极速)
  virtual int OnRspOrderFlash(CFirstSetField *p_pFirstSet, CRspStkOrderFlashField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) 
  {
    char szBuf[512]={0};
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "极速买卖委托应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;

    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" <<  std::endl;
      cout << "极速买卖委托应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout <<" 委托批号:"<<p_pRspField->iOrderBsn;                     
      cout <<" 合同序号:"<<p_pRspField->szOrderId;             
      cout <<" 交易板块:"<<p_pRspField->szStkbd;                
      cout <<" 证券业务:"<<p_pRspField->iStkBiz;                       
      cout <<" 账户序号:"<<p_pRspField->iCuacctSn<<std::endl;  
    }

    return 0;
  }

  // 委托撤单响应(极速)
  virtual int OnRspCancelOrderFlash(CFirstSetField *p_pFirstSetField, CRspStkCancelOrderFlashField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "极速委托撤单应答:" <<  p_pFirstSetField->iMsgCode  <<  "|" << p_pFirstSetField->szMsgText << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "极速委托撤单应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 资产账户:" << p_pRspField->llCuacctCode;                  
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                    
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 交易单元:" << p_pRspField->szStkpbu;               
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券代码:" << p_pRspField->szStkCode;              
      cout << " 证券名称:" << p_pRspField->szStkName;
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 业务行为:" << p_pRspField->iStkBizAction;                 
      cout << " 内部撤单标志:" << p_pRspField->chCancelStatus;               
      cout << " 证券账户:" << p_pRspField->szTrdacct;             
      cout << " 内撤信息:" << p_pRspField->szMsgOk;               
      cout << " 撤单列表:" << p_pRspField->szCancelList << std::endl;        
    }
    return 0;

  }

  // 组合委托响应(极速)
  virtual int OnRspCombOrderFlash(CFirstSetField *p_pFirstSetField, CRspStkCombOrderFlashField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "极速组合委托应答:" <<  p_pFirstSetField->iMsgCode  <<  "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "极速组合委托应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 委托批号:" << p_pRspField->iOrderBsn;                     
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 资产账户:" << p_pRspField->llCuacctCode;                       
      cout << " 交易板块:" << p_pRspField->szStkbd;                
      cout << " 证券代码:" << p_pRspField->szStkCode;              
      cout << " 证券业务:" << p_pRspField->iStkBiz;                       
      cout << " 业务行为:" << p_pRspField->iStkBizAction;                 
      cout << " 账户序号:" << p_pRspField->iCuacctSn;                     
      cout << " 委托结果:" << p_pRspField->iOrderRet;                     
      cout << " 返回信息:" << p_pRspField->szRetInfo << std::endl;   
    }

    return 0;
  }

  //可用资金查询应答
  virtual int OnRspQryExpendableFund(CFirstSetField *p_pFirstSet, CRspStkQryExpendableFundField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "可用资金查询应答:" <<  p_pFirstSet->iMsgCode << "|" << p_pFirstSet->szMsgText << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "可用资金查询应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 客户代码:" << p_pRspField->llCustCode;                
      cout << " 资产账户:" << p_pRspField->llCuacctCode;              
      cout << " 货币代码:" << p_pRspField->chCurrency;            
      cout << " 内部机构:" << p_pRspField->iIntOrg;              
      cout << " 资产总值:" << p_pRspField->szMarketValue;         
      cout << " 资金资产:" << p_pRspField->szFundValue;           
      cout << " 市值:" << p_pRspField->szStkValue;            
      cout << " 融资总金额:" << p_pRspField->szFundLoan;            
      cout << " 资金昨日余额:" << p_pRspField->szFundPrebln;          
      cout << " 资金余额:" << p_pRspField->szFundBln;             
      cout << " 资金可用金额:" << p_pRspField->szFundAvl;             
      cout << " 资金冻结金额:" << p_pRspField->szFundFrz;             
      cout << " 资金解冻金额:" << p_pRspField->szFundUfz;             
      cout << " 资金交易冻结金额:" << p_pRspField->szFundTrdFrz;          
      cout << " 资金交易解冻金额:" << p_pRspField->szFundTrdUfz;          
      cout << " 资金交易在途金额:" << p_pRspField->szFundTrdOtd;          
      cout << " 资金交易轧差金额:" << p_pRspField->szFundTrdBln;          
      cout << " 资金状态:" << p_pRspField->chFundStatus;          
      cout << " 资产账户属性:" << p_pRspField->chCuacctAttr << std::endl;          
    }
    return 0;
  }

  //可用股份查询应答
  virtual int OnRspQryExpendableShares(CFirstSetField *p_pFirstSet, CRspStkQryExpendableSharesField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }    
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "可用股份查询应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;			
    }

    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "可用股份查询应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 定位串:" <<      p_pRspField->szQryPos;					   
      cout << " 内部机构:" <<  p_pRspField->iIntOrg;                     
      cout << " 客户代码:" <<  p_pRspField->llCustCode;                       
      cout << " 资产账户:" <<  p_pRspField->llCuacctCode;                     
      cout << " 交易板块:" <<  p_pRspField->szStkbd;                      
      cout << " 交易单元:" <<  p_pRspField->szStkpbu;                     
      cout << " 货币代码:" <<  p_pRspField->chCurrency;                   
      cout << " 证券代码:" <<  p_pRspField->szStkCode;                    
      cout << " 证券名称:" <<  p_pRspField->szStkName;                    
      cout << " 证券类别:" <<  p_pRspField->chStkCls;                     
      cout << " 证券昨日余额:" <<  p_pRspField->llStkPrebln;                      
      cout << " 证券余额:" <<  p_pRspField->llStkBln;                         
      cout << " 证券可用数量:" <<  p_pRspField->llStkAvl;                         
      cout << " 证券冻结数量:" <<  p_pRspField->llStkFrz;                         
      cout << " 证券解冻数量:" <<  p_pRspField->llStkUfz;                         
      cout << " 证券交易冻结数量 :" <<  p_pRspField->llStkTrdFrz;                      
      cout << " 证券交易解冻数量 :" <<  p_pRspField->llStkTrdUfz;                      
      cout << " 证券交易在途数量 :" <<  p_pRspField->llStkTrdOtd;                      
      cout << " 证券买入成本:" << p_pRspField-> szStkBcost;             
      cout << " 证券买入成本（实时）:" << p_pRspField-> szStkBcostRlt;         
      cout << " 证券盈亏金额:" << p_pRspField-> szStkPlamt;             
      cout << " 证券盈亏金额（实时）:" << p_pRspField-> szStkPlamtRlt;         
      cout << " 市值:" << p_pRspField->szMktVal;               
      cout << " 成本价格:" << p_pRspField->szCostPrice;            
      cout << " 参考盈亏:" << p_pRspField->szProIncome;            
      cout << " 市值计算标识:" << p_pRspField->chStkCalMktval;         
      cout << " 当前拥股数:" << p_pRspField->llStkQty;                   
      cout << " 最新价格:" << p_pRspField->szCurrentPrice;         
      cout << " 参考成本价:" << p_pRspField->szProfitPrice;          
      cout << " 可申赎数量:" << p_pRspField->llStkDiff;                  
      cout << " 已申赎数量:" << p_pRspField->llStkTrdUnfrz;              
      cout << " 交易账户:" << p_pRspField->szTrdacct;              
      cout << " 盈亏:" << p_pRspField->szIncome;               
      cout << " 余券可用数量:" << p_pRspField->llStkRemain << std::endl;               

      if(p_iFieldIndex == p_iFieldNum)
      {
        if(p_iFieldNum < g_iQryCntPer)
        {
          g_bFinish = true;
        }
        else
        {
          strncpy(g_szPos, p_pRspField->szQryPos, sizeof(g_szPos) - 1);
          g_szPos[strlen(g_szPos)] = '\0';
        }

        g_ExpShsCnt += p_iFieldNum; 

        CLock lock(g_mutex);
        g_event.Signal();
      }
    }
    else
    {
      g_bFinish = true;
      CLock lock(g_mutex);
      g_event.Signal();
    }
    return 0;
  }

  //当日委托查询应答
  virtual int OnRspQryCurrDayOrder(CFirstSetField *p_pFirstSet, CRspStkQryCurrDayOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;

      return -1;
    }
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "当日委托查询应答:" << p_pFirstSet->iMsgCode << "|" << p_pFirstSet->szMsgText << std::endl;			
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "当日委托查询应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 定位串查询  :" << p_pRspField->szQryPos;              
      cout << " 内部机构:" << p_pRspField-> iIntOrg;              
      cout << " 交易日期:" << p_pRspField-> iTrdDate;             
      cout << " 委托日期:" << p_pRspField-> iOrderDate;           
      cout << " 委托时间:" << p_pRspField->szOrderTime;           
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 委托状态:" << p_pRspField->chOrderStatus;         
      cout << " 委托有效标志:" << p_pRspField->chOrderValidFlag;      
      cout << " 客户代码:" << p_pRspField->llCustCode;                
      cout << " 资产账户:" << p_pRspField->llCuacctCode;              
      cout << " 交易板块:" << p_pRspField->szStkbd;               
      cout << " 交易单元:" << p_pRspField->szStkpbu;              
      cout << " 证券业务:" << p_pRspField-> iStkBiz;              
      cout << " 业务行为:" << p_pRspField-> iStkBizAction;        
      cout << " 证券代码:" << p_pRspField->szStkCode;             
      cout << " 证券名称:" << p_pRspField->szStkName;             
      cout << " 货币代码:" << p_pRspField->chCurrency;            
      cout << " 债券利息:" << p_pRspField->szBondInt;             
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 委托冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 委托解冻金额:" << p_pRspField->szOrderUfzAmt;         
      cout << " 申报数量:" << p_pRspField->llOfferQty;                
      cout << " 申报时间:" << p_pRspField->     iOfferStime;          
      cout << " 已撤单数量:" << p_pRspField->llWithdrawnQty;            
      cout << " 已成交数量:" << p_pRspField->llMatchedQty;              
      cout << " 撤单标志:" << p_pRspField->chIsWithdraw;          
      cout << " 已撤单标志:" << p_pRspField->chIsWithdrawn;         
      cout << " 委托批号:" << p_pRspField-> iOrderBsn;            
      cout << " 成交金额:" << p_pRspField->szMatchedAmt;          
      cout << " 交易账户:" << p_pRspField->szTrdacct;             
      cout << " 账户序号:" << p_pRspField-> iCuacctSn;            
      cout << " 原合同序号:" << p_pRspField->szRawOrderId;          
      cout << " 申报信息:" << p_pRspField->szOfferRetMsg;         
      cout << " 操作站点:" << p_pRspField->szOpSite;              
      cout << " 操作渠道:" << p_pRspField->chChannel << std::endl;             
    }
    return 0;
  }

  //当日成交查询应答
  virtual int OnRspQryCurrDayFill(CFirstSetField *p_pFirstSet, CRspStkQryCurrDayFillField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;

      return -1;
    }
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "当日成交查询应答:" <<  p_pFirstSet->iMsgCode  <<  "|" << p_pFirstSet->szMsgText << std::endl;


    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "当日成交查询应答:(" << p_iFieldNum << "," << p_iFieldIndex << ")" << std::endl;
      cout << " 定位串查询:" << p_pRspField->          szQryPos;              
      cout << " 成交时间:" << p_pRspField->szMatchedTime;         
      cout << " 委托日期:" << p_pRspField-> iOrderDate;           
      cout << " 委托序号:" << p_pRspField-> iOrderSn;             
      cout << " 委托批号:" << p_pRspField-> iOrderBsn;            
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 内部机构:" << p_pRspField-> iIntOrg;              
      cout << " 客户代码:" << p_pRspField->llCustCode;                
      cout << " 资产账户:" << p_pRspField->llCuacctCode;              
      cout << " 交易板块:" << p_pRspField->szStkbd;               
      cout << " 交易单元:" << p_pRspField->szStkpbu;              
      cout << " 证券账户:" << p_pRspField->szStkTrdacct;          
      cout << " 证券业务:" << p_pRspField-> iStkBiz;              
      cout << " 证券业务行为:" << p_pRspField->iStkBizAction;        
      cout << " 证券代码:" << p_pRspField->szStkCode;             
      cout << " 证券名称:" << p_pRspField->szStkName;             
      cout << " 货币代码:" << p_pRspField->chCurrency;            
      cout << " 债券利息:" << p_pRspField->szBondInt;             
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                
      cout << " 委托金额:" << p_pRspField->szOrderAmt;            
      cout << " 委托冻结金额:" << p_pRspField->szOrderFrzAmt;         
      cout << " 成交编号:" << p_pRspField->szMatchedSn;            
      cout << " 成交价格:" << p_pRspField->szMatchedPrice;         
      cout << " 已成交数量:" << p_pRspField->szMatchedQty;           
      cout << " 已成交金额:" << p_pRspField->szMatchedAmt;           
      cout << " 成交类型:" << p_pRspField->chMatchedType;          
      cout << " 账户序号:" << p_pRspField->iCuacctSn;             
      cout << " 撤单标志:" << p_pRspField->chIsWithdraw;           
      cout << " 委托状态:" << p_pRspField->chOrderStatus << std::endl;         
    }
    return 0;
  }

  //可撤单委托查询应答
  virtual int OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSet, CRspStkQryCanWithdrawOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;

      return -1;
    }
    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "可撤单委托查询应答:" << p_pFirstSet->iMsgCode << "|" << p_pFirstSet->szMsgText << std::endl;
    }
    if (/*p_iFieldNum > 0 &&*/ NULL!=p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "可撤单委托查询应答:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 定位串查询   :" << p_pRspField->szQryPos;              
      cout << " 内部机构:" << p_pRspField-> iIntOrg;              
      cout << " 交易日期:" << p_pRspField-> iTrdDate;             
      cout << " 委托日期:" << p_pRspField-> iOrderDate;           
      cout << " 委托时间:" << p_pRspField->szOrderTime;           
      cout << " 合同序号:" << p_pRspField->szOrderId;             
      cout << " 委托状态:" << p_pRspField->chOrderStatus;         
      cout << " 委托有效标志 :" << p_pRspField->chOrderValidFlag;      
      cout << " 客户代码:" << p_pRspField->llCustCode;                
      cout << " 资产账户:" << p_pRspField->llCuacctCode;              
      cout << " 交易板块:" << p_pRspField->szStkbd;               
      cout << " 交易单元:" << p_pRspField->szStkpbu;              
      cout << " 证券业务:" << p_pRspField-> iStkBiz;              
      cout << " 业务行为:" << p_pRspField-> iStkBizAction;        
      cout << " 证券代码:" << p_pRspField->szStkCode;             
      cout << " 证券名称:" << p_pRspField->szStkName;             
      cout << " 货币代码:" << p_pRspField->chCurrency;            
      cout << " 委托价格:" << p_pRspField->szOrderPrice;          
      cout << " 委托数量:" << p_pRspField->llOrderQty;                
      cout << " 委托金额:" << p_pRspField->    szOrderAmt;            
      cout << " 委托冻结金额 :" << p_pRspField->szOrderFrzAmt;         
      cout << " 委托解冻金额 :" << p_pRspField->szOrderUfzAmt;         
      cout << " 申报数量 :" << p_pRspField-> llOfferQty;                   
      cout << " 申报时间 :" << p_pRspField->      iOfferStime;             
      cout << " 已撤单数量:" << p_pRspField-> llWithdrawnQty;              
      cout << " 已成交数量:" << p_pRspField-> llMatchedQty;                
      cout << " 撤单标志 :" << p_pRspField-> chIsWithdraw;             
      cout << " 已撤单标志:" << p_pRspField-> chIsWithdrawn;           
      cout << " 委托批号 :" << p_pRspField->  iOrderBsn;               
      cout << " 成交金额 :" << p_pRspField-> szMatchedAmt;             
      cout << " 交易账户 :" << p_pRspField-> szTrdacct;                
      cout << " 账户序号:" << p_pRspField->  iCuacctSn << std::endl;            
    }
    return 0;
  }

  //证券市值额度查询应答
  virtual int OnRspQryMktQuota(CFirstSetField *p_pFirstSet, CRspStkMktQuotaField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSet == NULL) 
    {
      cout << "p_pFirstSet is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "证券市值额度查询返回结果:" << p_pFirstSet->iMsgCode << "|" << p_pFirstSet->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "证券市值额度查询返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 交易市场:" << p_pRspField->chStkex ;
      cout << " 交易板块:" << p_pRspField->szStkbd ;
      cout << " 证券账户:" << p_pRspField->szTrdacct ;
      cout << " 交易单元:" << p_pRspField->szStkpbu;
      cout << " 市值额度:" << p_pRspField->llMktQuota <<  std::endl;
    }

    return 0;
  }

  // 回购合约查询响应
  virtual int OnRspQryRepchContract(CFirstSetField *p_pFirstSetField, CRspStkQryRepchContractField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) 
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "回购合约查询返回结果:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "回购合约查询返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 证券代码:" << p_pRspField->szStkCode;
      cout << " 证券业务:" << p_pRspField->iStkBiz;
      cout << " 委托价格:" << p_pRspField->szOrderPrice;
      cout << " 成交价格:" << p_pRspField->szMatchedPrice;
      cout << " 委托数量:" << p_pRspField->llOrderQty;
      cout << " 成交数量:" << p_pRspField->llMatchQty;
      cout << " 回购数量:" << p_pRspField->llRepchQty;
      cout << " 到期金额:" << p_pRspField->szRepchAmt;
      cout << " 定位串:" << p_pRspField->szQryPos<<  std::endl;
    }

    return 0;
  }

  // 证券信息查询响应
  virtual int OnRspQryStkInfo(CFirstSetField *p_pFirstSetField, CRspStkQryStkInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "证券信息查询响应:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "证券信息查询响应返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 交易板块:" << p_pRspField->szStkbd;
      cout << " 证券代码:" << p_pRspField->szStkCode;
      cout << " 证券名称:" << p_pRspField->szStkName;
      cout << " 涨停价格:" << p_pRspField->szStkUplmtPrice;
      cout << " 跌停价格:" << p_pRspField->szStkLwlmtPrice;
      cout << " 分层信息标志:" << p_pRspField->chStkLayerFlag;
      cout << " 证券分层信息:" << p_pRspField->szStkLayerInfo << std::endl;
    }

    return 0;
  }

  // 共享内存品种信息查询响应
  virtual int OnRspQryStkInfoShm(CFirstSetField *p_pFirstSetField, CRspStkQryStkInfoShmField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "共享内存品种信息查询响应:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "共享内存品种信息查询响应返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 交易板块:" << p_pRspField->szStkbd;
      cout << " 证券代码:" << p_pRspField->szStkCode;
      cout << " 涨停价格:" << p_pRspField->szStkUplmtPrice;
      cout << " 跌停价格:" << p_pRspField->szStkLwlmtPrice;
      cout << " 定位串:" << p_pRspField->szQryPos << std::endl;
    }

    return 0;
  }


  //资金划拨
  virtual int OnRspQryFundTransfer(CFirstSetField *p_pFirstSetField, CRspStkFundTransferField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "资金划拨返回结果:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "资金划拨返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 操作流水号:" << p_pRspField->iSNo;
      cout << " VIP操作流水号:" << p_pRspField->iVipSno <<  std::endl;
    }

    return 0;
  }

  //转帐银行业务信息
  virtual int OnRspQryBankTransBasicInfo(CFirstSetField *p_pFirstSetField, CRspStkBankTransBasicInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "转帐银行业务信息返回结果:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "转帐银行业务信息返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 银行代码:" << p_pRspField->szBankCode;
      cout << " 银行状态:" << p_pRspField->chStatus << std::endl;
    }

    return 0;
  }

  //银证转帐
  virtual int OnRspBankStkTrans(CFirstSetField *p_pFirstSetField, CRspStkBankStkTransField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex)
  {
    if (p_pFirstSetField == NULL) 
    {
      cout << "p_pFirstSetField is NULL" << std::endl;
      return -1;
    }

    if (p_iFieldNum == 0 || p_iFieldIndex == 1) 
    {
      cout << "银证转帐返回结果:" << p_pFirstSetField->iMsgCode << "|" << p_pFirstSetField->szMsgText << std::endl;
    }

    if (NULL != p_pRspField)
    {
      cout << "-------------------------------------------------------------------------------" << std::endl;
      cout << "银证转帐返回结果:(" <<  p_iFieldNum  << "," << p_iFieldIndex <<  ")" << std::endl;
      cout << " 委托序号:" << p_pRspField->iSNo;
      cout << " 错误代码:" << p_pRspField->iSysErrorId<< std::endl;
    }

    return 0;
  }

  bool login_success()
  {
    return m_bLoginFlag;
  }

private:
  CBpuStkTradeApi *m_pExCliStkTradeApi;
  bool m_bLoginFlag;
  EventQueue* m_que;
};

