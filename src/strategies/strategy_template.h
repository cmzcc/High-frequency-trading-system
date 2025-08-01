//
// Created by qt8 on 25-3-27.
//

#ifndef STRATEGY_TEMPLATE_H
#define STRATEGY_TEMPLATE_H

#include "../EventQueue/EventQueue.h"
#include "../macli/maBpuStkRsp.h"
#include "../../include/constant.h"
#include "../macli/database.h"
#include "../macli/logger.h"
#include "../macli/global.h"
#include <chrono>

using namespace std;

// 使用系统时间作为入库时间
using TimePoint = chrono::steady_clock::time_point;

// extern std::unordered_map <LONGLONG, int> total_order_list_by_requestID;
// extern std::unordered_map <int, StkOrder> total_order_list_by_orderBSN;
// extern std::unordered_map <string, CRspStkOrderField> order_detail; //orderid对应具体的报单相应
// static std::queue <int> order_to_send;

// static std::mutex order_mutex;
// static std::mutex request_mutex;

class StrategyTemplate {
protected:
    EventQueue* que;
    CBpuStkTradeApi* stkTradeApi;
    std::unordered_map <string, CRspStkOrderField> order_detail;
    std::unordered_map <LONGLONG, int> total_order_list_by_requestID;
    std::unordered_map <int, StkOrder> total_order_list_by_orderBSN;
    std::unordered_map <int, TimePoint> order_time_stamp;
    std::mutex order_mutex;
    std::mutex cancel_mutex;
    std::unordered_map <string, int> orderid_bsn_map;
    database db;

public:
    virtual ~StrategyTemplate() = default;

    explicit StrategyTemplate(EventQueue* q, CBpuStkTradeApi* pclStkTradeApi, string database_name) : que(q), stkTradeApi(pclStkTradeApi), db(database_name) {
        q->add_listener(EventType::MarketData, [this](const std::shared_ptr<EventData> &data) { this->marketListener(data); });
        q->add_listener(EventType::Order, [this](const std::shared_ptr<EventData> &data) { this->orderListener(data); });
        q->add_listener(EventType::Trade, [this](const std::shared_ptr<EventData> &data) { this->tradeListener(data); });
        q->add_listener(EventType::Error, [this](const std::shared_ptr<EventData> &data) { this->errorListener(data); });
    };

    virtual void marketListener(const std::shared_ptr<EventData>& data);
    virtual void orderListener(const std::shared_ptr<EventData>& order_data);
    virtual void tradeListener(const std::shared_ptr<EventData>& fill_data);
    virtual void errorListener(const std::shared_ptr<EventData>& error_data);
    void buyOrder(const string &stk_code, double price, int volume, const string &stk_bd);
    void sellOrder(const string &stk_code, double price, int volume, const string &stk_bd);

};

#endif //STRATEGY_TEMPLATE_H
