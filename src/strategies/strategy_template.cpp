//
// Created by qt8 on 25-3-27.
//

#include "strategy_template.h"

void StrategyTemplate::marketListener(const std::shared_ptr<EventData>& data) {
        if (data->type == EventType::MarketData) {
            auto snapshot = std::static_pointer_cast<eqapi::Snapshot_L2>(data->data);
            
            // 处理行情数据
            std::string stockCode(snapshot->security_id);
            int64_t lastPrice = snapshot->last;
            int64_t volume = snapshot->total_volume_trade;
            
            // 在这里添加您的策略逻辑
            //processMarketData(snapshot);
        
    }
}


void StrategyTemplate::orderListener(const std::shared_ptr<EventData>& order_data) {

}

void StrategyTemplate::tradeListener(const std::shared_ptr<EventData>& fill_data) {}

void StrategyTemplate::errorListener(const std::shared_ptr<EventData>& error_data) {
    auto tmp = std::static_pointer_cast<errordata>(error_data->data);
    LONGLONG request_id = tmp->request_id;
    if (total_order_list_by_requestID.find(request_id) == total_order_list_by_requestID.end()) {
        cout << "error: request id : " << request_id << " not found" << endl;
    }
    int order_bsn = total_order_list_by_requestID[request_id];

    std::lock_guard<std::mutex> a_lock(re_mutex);

    if (total_order_list_by_orderBSN[order_bsn].STK_BIZ == 100) {
        stk_map[total_order_list_by_orderBSN[order_bsn].STK_CODE]->Wrong_buy_orders.insert(order_bsn);
    } else {
        stk_map[total_order_list_by_orderBSN[order_bsn].STK_CODE]->Wrong_sell_orders.insert(order_bsn);
        // cout <<"size of wrong sellorder : " <<  stk_map[total_order_list_by_orderBSN[order_bsn].STK_CODE].Wrong_sell_orders.size() << endl;
    }

    order_time_stamp[order_bsn] = chrono::steady_clock::now();
    // auto duration =std::chrono::duration_cast<std::chrono::seconds>(wrong_order_time[order_bsn].time_since_epoch());
    // std::cout << "Time since epoch: " << duration.count() << " seconds\n";
    // cerr << "order_bsn: " << order_bsn << endl;
    auto t = order_time_stamp.find(order_bsn);
    if (t == order_time_stamp.end()) {
        cerr << "error: order not found" << tmp << endl;
        for (auto p : order_time_stamp) {
            cerr << p.first << endl;
        }
    }

    db.order_update(order_bsn, nullptr, -1, "rejected");
    auto logger = Logger::get();
    logger->info("error listener: BsnID : {} ", order_bsn);
}

// 在 buyOrder 函数中 (第132行)
void StrategyTemplate::buyOrder(const string &stk_code, const double price, const int volume, const string &stk_bd) {
    StkOrder stk_order;
    if (stk_bd == "SSE") {
        stk_order.STKBD = "10";
    }
    else if (stk_bd == "SZSE") {
        stk_order.STKBD = "00";
    }
    else {
        std::cerr << "Wrong stk code" << std::endl;
        return;
    }
    stk_order.STK_BIZ = 100;
    stk_order.STK_CODE = stk_code;
    stk_order.ORDER_PRICE = std::to_string(price);
    stk_order.ORDER_QTY = volume;
    auto logger = Logger::get();
    logger->info("[BSN_TRACE] Before modify_bsn() in buyOrder - Current BSN: {}", get_bsn());
    modify_bsn();
    int bsn_id = get_bsn();
    logger->info("[BSN_TRACE] After modify_bsn() in buyOrder - New BSN: {}", bsn_id);
    stk_order.ORDER_BSN = bsn_id;
    total_order_list_by_orderBSN[bsn_id] = stk_order;
    // order_to_send.push(bsn_id);
}

// 在 sellOrder 函数中 (第155行)
void StrategyTemplate::sellOrder(const string &stk_code, const double price, const int volume, const string &stk_bd) {
    StkOrder stk_order;
    if (stk_bd == "SSE") {
        stk_order.STKBD = "10";
    }
    else if (stk_bd == "SZSE") {
        stk_order.STKBD = "00";
    }
    else {
        std::cerr << "Wrong stk code" << std::endl;
        return;
    }
    stk_order.STK_BIZ = 101;
    stk_order.STK_CODE = stk_code;
    stk_order.ORDER_PRICE = std::to_string(price);
    stk_order.ORDER_QTY = volume;
    auto logger = Logger::get();
    logger->info("[BSN_TRACE] Before modify_bsn() in sellOrder - Current BSN: {}", get_bsn());
    modify_bsn();
    int bsn_id = get_bsn();
    logger->info("[BSN_TRACE] After modify_bsn() in sellOrder - New BSN: {}", bsn_id);
    stk_order.ORDER_BSN = bsn_id;
    total_order_list_by_orderBSN[bsn_id] = stk_order;
    // order_to_send.push(bsn);
}






