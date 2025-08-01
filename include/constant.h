#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include <cstdint>
#include <iostream>
#include "../src/macli/iniFileRW.h"
#include <string>

enum EventType {
    First,
    MarketData,
    Order,
    Trade,
    Error,
    Last,
};


struct EventData {
    EventType type;
    std::shared_ptr<void> data;
};

// static int bsn = 1;
struct StkGrid {
    std::string STKBD;        // 交易板块
    std::string stk_code;     // 股票代码
    std::string grid_size;    // 网格间距
    int grid_num;             // 网格数量
    std::string seg_price;    // 分段价格
    std::string bench_price;  // 基准价格
    int high_volume;          // 高价位交易量
    int low_volume;           // 低价位交易量
};

struct StkOrder {
    std::string STKBD = "10";        // 股票板块代码，默认"10"（通常表示沪深A股）
    std::string STK_CODE;            // 股票代码（如"000001"）
    std::string ORDER_PRICE;         // 委托价格（字符串格式）
    int64_t ORDER_QTY;              // 委托数量（64位整数）
    int STK_BIZ;                     // 股票业务类型（如100=买入，101=卖出）
    int STK_BIZ_ACTION = 100;        // 股票业务动作，默认100
    int ORDER_BSN;                   // 订单业务序号（唯一标识）
    int CUACCT_SN = 666;            // 客户账户序号，默认666
};

struct StkCancel {
    std::string szStkbd;
    std::string szOrderId;
    int iOrderBsn;
};

struct Stk // 单只股票的所有相关信息
{
    std::string stk_code;
    StkGrid stk_grid;

    std::queue<double> HighOrder;  // 高价位卖单队列
    std::queue<double> LowOrder;   // 低价位买单队列

    // 非线性动量策略，只追踪当前的唯一卖单和买单(重复除外）
    std::map<int,std::string>current_buy_order;
    std::map<int,std::string>current_sell_order;
    // 订单状态枚举
    enum OrderStatus {
        WAITING_SEND,     //未发送
        PENDING_SEND,    // 即将发送  order_to_send队列
        SENT_UNCONFIRMED, // 已发送未确认     wrong,unknown
        CONFIRMED,       // 已确认     current_ _order
        PARTIALLY_FILLED, // 部分成交
        FILLED,          // 完全成交
        CANCELED         // 已撤销
    };
    
    // 订单状态跟踪
    std::unordered_map<int, OrderStatus> order_status_map;
    
    // 简化的订单状态管理
    std::unordered_map<std::string, std::shared_ptr<EventData>> retrade_order_list; // 等待确认的订单
    
    // 新增waiting队列 - 使用multimap按价格排序
    std::multimap<double, int> buy_waiting_orders;  // 买单waiting队列，价格作为key（降序）
    std::multimap<double, int> sell_waiting_orders; // 卖单waiting队列，价格作为key（升序）
    
    // 保留错误重试机制
    std::unordered_set<int> Wrong_sell_orders;
    std::unordered_set<int> Wrong_buy_orders;
    std::unordered_set<int> unknown_buy_orders;
    std::unordered_set<int> unknown_sell_orders;
    std::unordered_set<int> pending_sell_orders;
    std::unordered_set<int> pending_buy_orders;
};


//static char* eqapi_buffer[60] = {"103.77.28.28", "12010", "jiyou_sm_cs", "jiyou_sm_cs", "103.77.28.28", "12010", "jiyou_sm_cs", "jiyou_sm_cs", "shl2:tick:600011"};

namespace eqapi{

struct Quote_Msg_Head
{
    std::int8_t mode;                       // data mode, 0 = json; 1 = binary
    std::int8_t compress;                   // quote compress. 0 = no compress, 1 = snappy, 2 = gzip
    std::uint16_t quote_data_type;
    std::int32_t quote_data_len;            //
};
struct Snapshot_L2
{
    char security_id[16];                   // 证券代码
    std::uint16_t market;                   // 市场代码 (例如: 上海, 深圳)
    std::int32_t date;                      // 当前日期 (格式: YYYYMMDD)
    std::int32_t time;                      // 当前时间 (格式: HHMMSSmmm, 包含毫秒)
    std::uint8_t quote_type;                // 行情数据类型 (例如: 快照, 委托)
    std::int8_t eq_tpc;                     // EQAPI 定义的交易阶段代码 (数字)
    std::int64_t preclose;                  // 昨日收盘价
    std::int64_t open;                      // 今日开盘价
    std::int64_t high;                      // 今日最高价
    std::int64_t low;                       // 今日最低价
    std::int64_t last;                      // 最新成交价
    std::int64_t close;                     // 今日收盘价 (在收盘后有效)
    char instrument_status[8];              // 证券状态 (例如: 正常交易, 停牌)
    char tpc[8];                            // 交易阶段代码 (字符串形式)
    std::int64_t offer_price[10];           // 卖方十档报价
    std::int64_t offer_volume[10];          // 卖方十档委托量
    std::int64_t offer_num_order[10];       // 卖方十档委托笔数
    std::int64_t bid_price[10];             // 买方十档报价
    std::int64_t bid_volume[10];            // 买方十档委托量
    std::int64_t bid_num_order[10];         // 买方十档委托笔数
    std::int64_t num_trades;                // 总成交笔数
    std::int64_t total_volume_trade;        // 总成交数量
    std::int64_t total_value_trade;         // 总成交金额
    std::int64_t total_offer_quant;         // 委托卖出总量
    std::int64_t total_bid_quant;           // 委托买入总量
    std::int64_t weighted_avg_offer_price;  // 加权平均委卖价格
    std::int64_t weighted_avg_bid_price;    // 加权平均委买价格
    std::int64_t altWeighted_avg_offer_price; // 备用加权平均委卖价格
    std::int64_t altWeighted_avg_bid_price; // 备用加权平均委买价格
    std::int64_t num_offer_order;           // 卖方委托价位的数量
    std::int64_t num_bid_order;             // 买方委托价位的数量
    std::int64_t high_limited;              // 涨停价
    std::int64_t low_limited;               // 跌停价
    std::int64_t withdraw_sell_num;         // 卖方撤单总笔数 (此字段也可能被复用，如注释所示)
    std::int64_t withdraw_sell_amount;      // 卖方撤单总量
    std::int64_t withdraw_sell_money;       // 卖方撤单总金额
    std::int64_t withdraw_buy_num;          // 买方撤单总笔数
    std::int64_t withdraw_buy_amount;       // 买方撤单总量
    std::int64_t withdraw_buy_money;        // 买方撤单总金额
    std::int64_t total_offer_num;           // 卖方总委托笔数
    std::int64_t total_bid_num;             // 买方总委托笔数
    std::int64_t offer_trade_max_duration;  // 卖方成交最长等待时间
    std::int64_t bid_trade_max_duration;    // 买方成交最长等待时间
    std::int64_t etf_buy_num;               // ETF 申购笔数
    std::int64_t etf_buy_amount;            // ETF 申购数量
    std::int64_t etf_buy_money;             // ETF 申购金额
    std::int64_t etf_sell_num;              // ETF 赎回笔数
    std::int64_t etf_sell_amount;           // ETF 赎回数量
    std::int64_t etf_sell_money;            // ETF 赎回金额
    std::int64_t iopv;                      // ETF 基金份额参考净值
    std::int64_t nav;                       // 基金单位净值
    std::int64_t position;                  // 持仓量
    std::int64_t yield_to_maturity;         // 到期收益率 (适用于债券)
    std::int64_t pratio1;                   // 市盈率1
    std::int64_t pratio2;                   // 市盈率2
    std::int64_t updown1;                   // 涨跌1
    std::int64_t updown2;                   // 涨跌2
    std::int64_t weighted_avg_price;        // 加权平均价 (适用于特定品种，如债券回购)
    std::int64_t reserved2;                 // 保留字段2 (可能用于匹配成交最新价)
    std::int64_t reserved3;                 // 保留字段3 (可能用于匹配成交成交量)
    std::int64_t reserved4;                 // 保留字段4 (可能用于匹配成交成交金额)
    std::int32_t offer_one_order[50];       // 卖一价的前50笔订单
    std::int32_t bid_one_order[50];         // 买一价的前50笔订单
};



}

// struct CRspSubTopicField
// {
//   char          szTopic[12 + 1];            
//   char          szFilter[512 + 1];          
//   long long      llAcceptSn;                 
//   char          szChannel[64 + 1];          
//   char          chDataSet;                 
// };

// struct CReqStkOrderField
// {
//   long long       llCuacctCode;               // 资产账户 
//   char            szStkbd[2 + 1];             // 交易板块 字典[STKBD]
//   char            szStkCode[8 + 1];           // 证券代码 
//   char            szOrderPrice[21 + 1];       // 委托价格 科创板市价委托填保护价
//   long long       llOrderQty;                 // 委托数量 
//   int             iStkBiz;                    // 证券业务 字典[STK_BIZ]
//   int             iStkBizAction;              // 业务行为 字典[STK_BIZ_ACTION]
//   int             iOrderBsn;                  // 委托批号 
//   char            szClientInfo[256 + 1];      // 终端信息 包括硬盘号\CPU\机器名等 格式： "PC;IIP=公网IP地址;IPORT=公网IP端口号;LIP=内网IP;MAC=MAC地址;HD=硬盘序列号;PCN=PC终端设备名;CPU=CPU序列号;PI=硬盘分区信息;VOL=系统盘卷标号@扩展信息1;扩展信息2;扩展信息3"
//   char            szTrdacct[20 + 1];          // 证券账户 
//   char			  szTrdacctCommon[20 + 1];	  // 普通证券账户
//   int             iCuacctSn;                  // 账户序号 客户端标识，用于多个客户端共用同一个资产账号下单时，区分不同客户端的委托与成交信息，并提供了相关的接口查询功能。
//   long long       llCustCode;                 // 客户代码 
//   char            szStkpbu[8 + 1];            // 交易单元 
//   char            szOrderText[1024 + 1];       // 委托扩展 格式:关键字1=值1,关键字2=值2 格式:关键字1=值1,关键字2=值2 业务适当性检查，关键字为PROP_RISK_NO（匹配流水号）例如：PROP_RISK_NO=匹配流水号 基金概要确认标识，关键字为OF_CTR_FLAGS 例如：OF_CTR_FLAGS=1，1：已确认，其它值：未确认
//   char            chSecurityLevel;            // 安全手段 1:校验会话凭证
//   char            szSecurityInfo[256 + 1];    // 安全信息 自动填写
//   char            szComponetStkCode[8 + 1];   // 成份股代码 ETF网下股票认购启用
//   char            szComponetStkbd[2 + 1];     // 成份股板块 ETF网下股票认购、ETF实物申赎启用
//   char            szStkbdLink[2 + 1];         // 关联板块 ETF网下股票认购、ETF实物申赎启用
//   char            chPublishCtrlFlag;          // 股票风控标志 0：不控制 1：控制股票买入持仓不超过总股本一定比例 仅限于限仓需求，并需配合后台的相关设置参数方可生效
//   char            szRepayOrderId[10 + 1];     // 偿还合同序号 用于融资融券交易
//   int             iRepayOpeningDate;          // 偿还合约日期 用于融资融券交易
//   char            szRepayStkCode[8 + 1];      // 偿还证券代码 用于融资融券交易
//   char            szTrdacctLink[20 + 1];      // 关联股东 用于跨市场ETF交易
//   char            szInitTrdAmt[21 + 1];       // 初始交易金额 用于股票质押交易
//   int             iRepchDay;                  // 购回天数 用于股票质押交易
//   char            szLoanerTrdacct[20 + 1];    // 出借人证券账户 用于股票质押交易
//   char            szRepaySno[32 + 1];         // 合约编号 用于股票质押交易
//   char            szContactInfo[32 + 1];      // 大宗交易时送联系方式
//   int             iItemno;                    // 合约序号 用于股票质押交易
//   char            chOutputDelayFlag;          // 输出时延标志 0:不输出服务器处理延时 1:输出服务器处理延时 默认为0
//   char            chCloseOutMode;             // 平仓方式 用于股票质押交易
//   char            chEtfMode;                  // ETF模式 适用于ETF申购交易 字典[ETF_MODE]
//   char            szMeetingSeq[10 + 1];       // 股东大会编码 用于网络投票交易
//   char            szVoteId[10 + 1];           // 议案编号 用于网络投票交易
//   char            szOppLofCode[3 + 1];        // 转入方基金编码 用于上证LOF基金转换交易
//   long long       llMatchNo;                  // 成交约定号 
//   char            szOpptStkpbu[8 + 1];        // 对手方交易单元 
//   char            szOpptTrdacct[20 + 1];      // 对手方股东账户 
//   char            szStkprop[2 + 1];           // 股份性质 
//   char            szLoanerName[40 + 1];       // 联系人姓名 
// };





#endif //_CONSTANT_H_