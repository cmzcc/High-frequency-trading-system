//
// Created by qt8 on 25-4-16.
//
#include "strategy_non_linear.h"

void Strategy_non_linear::marketListener(const std::shared_ptr<EventData> &data) {

}

void Strategy_non_linear::orderListener(const std::shared_ptr<EventData> &order_data){
    auto porder = std::static_pointer_cast<CRspStkOrderField>(order_data->data);
    string name = porder->szStkCode;
    string orderId = porder->szOrderId;
    CRspStkOrderField detail = *porder;
    auto logger = Logger::get();

    lock_guard<mutex> lock(cancel_mutex);
    
    // 更新当前订单状态
    if (detail.iStkBiz == 100) {
        stk_map[name]->current_buy_order[porder->iOrderBsn]=orderId;//监听到来自交易所的回复后追踪id
        stk_map[name]->unknown_buy_orders.erase(porder->iOrderBsn);
        update_order_status(name, porder->iOrderBsn, Stk::OrderStatus::CONFIRMED);
    }
    else if (detail.iStkBiz == 101) {
        stk_map[name]->current_sell_order[porder->iOrderBsn]=orderId;
        stk_map[name]->unknown_sell_orders.erase(porder->iOrderBsn);
        update_order_status(name, porder->iOrderBsn, Stk::OrderStatus::CONFIRMED);
    }
    else {
        std::cout << "委托批号: " << detail.iOrderBsn << std::endl;
        std::cerr << "Error: stk biz: " << detail.iStkBiz << std::endl;
    }

    order_detail[orderId] = detail;
    orderid_bsn_map[orderId] = detail.iOrderBsn;
    db.order_update(detail.iOrderBsn, detail.szOrderId, 0, "pending");
    logger->info("order listener: BsnID : {} , order is confirmed", detail.iOrderBsn);

    // 处理等待确认的交易
    if (stk_map[name]->retrade_order_list.find(orderId) != stk_map[name]->retrade_order_list.end()) {
        cerr << orderId << " is confirmed after the trade is completed" << endl;
        tradeListener(stk_map[name]->retrade_order_list[orderId]);
        stk_map[name]->retrade_order_list.erase(orderId);//从等待队列删除
    }
}

void Strategy_non_linear::tradeListener(const std::shared_ptr<EventData> &fill_data) {
    StrategyTemplate::tradeListener(fill_data);
    auto ptrade = std::static_pointer_cast<CRtnStkOrderFillField>(fill_data->data);
    string name = ptrade->szStkCode;
    string time = convertToStandardTime(ptrade->iMatchedDate, ptrade->szMatchedTime);
    std::lock_guard<std::mutex> lock(order_mutex);
    
    // 如果订单id为空表示还未确认，放入等待列表（单独拿出进行判断，减少冗余代码）
    string id = ptrade->szOrderId;
    if (ptrade->iStkBiz == 100 && stk_map[name]->current_buy_order.find(ptrade->iOrderBsn) == stk_map[name]->current_buy_order.end()) {
        stk_map[name]->retrade_order_list[id] = fill_data;
        return;
    }
    if (ptrade->iStkBiz == 101 && stk_map[name]->current_sell_order.find(ptrade->iOrderBsn) == stk_map[name]->current_sell_order.end()) {
        stk_map[name]->retrade_order_list[id] = fill_data;
        return;
    }
    
    // 处理撤单
    if (ptrade->chIsWithdraw == 'T') {
        int order_bsn = order_detail[id].iOrderBsn;
        db.order_update(order_bsn, ptrade->szOrderId, -1, "canceled");
        
        if (ptrade->iStkBiz == 100) {
            stk_map[name]->current_buy_order.erase(order_bsn);
            update_order_status(name, order_bsn, Stk::OrderStatus::CANCELED);
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "buy", 1, time.c_str(), session_ID.c_str());
        } else {
            stk_map[name]->current_sell_order.erase(order_bsn);
            update_order_status(name, order_bsn, Stk::OrderStatus::CANCELED);
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "sell", 1, time.c_str(), session_ID.c_str());
        }

        return;
    }
    
    // 处理成交
    int order_bsn = ptrade->iOrderBsn;
    if (total_order_list_by_orderBSN[order_bsn].ORDER_QTY == ptrade->llTotalMatchedQty) {
        // 完全成交，生成反方向订单
        std::stringstream ss;
        
        if (ptrade->iStkBiz == 100) {
            // 买单成交，生成卖单
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "buy", 0, time.c_str(), session_ID.c_str());
            db.order_update(order_bsn, ptrade->szOrderId, static_cast<int>(ptrade->llTotalMatchedQty), "filled");
            
            stk_map[name]->current_buy_order.erase(order_bsn);
            update_order_status(name, order_bsn, Stk::OrderStatus::FILLED);
            
            // 生成新的卖单
            StkOrder new_sell_order;
            new_sell_order.STK_BIZ = 101;
            new_sell_order.ORDER_QTY = ptrade->llTotalMatchedQty;
            new_sell_order.STK_CODE = name;
            new_sell_order.STKBD = ptrade->szStkbd;
            
            double new_price = std::stod(total_order_list_by_orderBSN[order_bsn].ORDER_PRICE) + std::stod(stk_map[name]->stk_grid.grid_size);
            ss << std::fixed << std::setprecision(3) << new_price;
            new_sell_order.ORDER_PRICE = ss.str();
            
            // 在 tradeListener 函数中 - 买单成交生成卖单 (第115行)
            auto logger = Logger::get();
            logger->info("[BSN_TRACE] Before modify_bsn() in tradeListener (buy filled, generating sell order) - Current BSN: {}", get_bsn());
            modify_bsn();
            int new_bsn = get_bsn();
            logger->info("[BSN_TRACE] After modify_bsn() in tradeListener (buy filled, generating sell order) - New BSN: {}", new_bsn);
            new_sell_order.ORDER_BSN = new_bsn;
            total_order_list_by_orderBSN[new_bsn] = new_sell_order;
            order_time_stamp[new_bsn] = chrono::steady_clock::now();
            update_order_status(name, new_bsn, Stk::OrderStatus::PENDING_SEND);
            
            // 检查是否需要替换现有卖单
            check_and_replace_order(name, 101, new_price, new_bsn);

            // 补买单
            add_order(name, 1);
            
        } else {
            // 卖单成交，生成买单
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "sell", 0, time.c_str(), session_ID.c_str());
            db.order_update(order_bsn, ptrade->szOrderId, static_cast<int>(ptrade->llTotalMatchedQty), "filled");
            
            stk_map[name]->current_sell_order.erase(order_bsn);
            update_order_status(name, order_bsn, Stk::OrderStatus::FILLED);
            
            // 生成新的买单
            StkOrder new_buy_order;
            new_buy_order.STK_BIZ = 100;
            new_buy_order.ORDER_QTY = ptrade->llTotalMatchedQty;
            new_buy_order.STK_CODE = name;
            new_buy_order.STKBD = ptrade->szStkbd;
            
            double new_price = std::stod(total_order_list_by_orderBSN[order_bsn].ORDER_PRICE) - 
                              std::stod(stk_map[name]->stk_grid.grid_size);
            ss << std::fixed << std::setprecision(3) << new_price;
            new_buy_order.ORDER_PRICE = ss.str();
            auto logger = Logger::get();
            // 在 tradeListener 函数中 - 卖单成交生成买单 (第150行)
            logger->info("[BSN_TRACE] Before modify_bsn() in tradeListener (sell filled, generating buy order) - Current BSN: {}", get_bsn());
            modify_bsn();
            int new_bsn = get_bsn();
            logger->info("[BSN_TRACE] After modify_bsn() in tradeListener (sell filled, generating buy order) - New BSN: {}", new_bsn);
            new_buy_order.ORDER_BSN = new_bsn;
            total_order_list_by_orderBSN[new_bsn] = new_buy_order;
            order_time_stamp[new_bsn] = chrono::steady_clock::now();
            update_order_status(name, new_bsn, Stk::OrderStatus::PENDING_SEND);
            
            // 检查是否需要替换现有买单
            check_and_replace_order(name, 100, new_price, new_bsn);
            logger->info("[BSN_TRACE] modify_bsn() in tradeListener (check) - New BSN: {}", get_bsn());
            // 补卖单
            add_order(name, 0);
            logger->info("[BSN_TRACE] modify_bsn() in tradeListener (add) - New BSN: {}", get_bsn());
        }
    } else {
        // 部分成交
        if (ptrade->iStkBiz == 100) {
            update_order_status(name, order_bsn, Stk::OrderStatus::PARTIALLY_FILLED);
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "buy", 0, time.c_str(), session_ID.c_str());
            db.order_update(order_bsn, ptrade->szOrderId, static_cast<int>(ptrade->llTotalMatchedQty), "partially_filled");
        } else {
            update_order_status(name, order_bsn, Stk::OrderStatus::PARTIALLY_FILLED);
            db.trade_create(order_bsn, ptrade->szStkCode, ptrade->szMatchedSn, ptrade->szOrderId, 
                          static_cast<int>(ptrade->llMatchedQty), std::stod(ptrade->szMatchedPrice), 
                          "sell", 0, time.c_str(), session_ID.c_str());
            db.order_update(order_bsn, ptrade->szOrderId, static_cast<int>(ptrade->llTotalMatchedQty), "partially_filled");
        }
    }

    auto logger = Logger::get();
    logger->info("trade listener: TradeID : {} ", ptrade->szMatchedSn);
}
void Strategy_non_linear::errorListener(const std::shared_ptr<EventData> &data) {
    StrategyTemplate::errorListener(data);
}
// 检查并替换订单的核心函数
void Strategy_non_linear::check_and_replace_order(const std::string& stk_code, int direction, double new_price, int new_bsn) {
    auto stk = stk_map[stk_code];

    if (direction == 101) { // 新生成的是卖单
        if (!stk->current_sell_order.empty()) {
            // 有现存卖单，比较价格
            int current_bsn=stk->current_sell_order.begin()->first;
            double current_price = std::stod(total_order_list_by_orderBSN[current_bsn].ORDER_PRICE);
            if (new_price < current_price && stk->order_status_map.find(current_bsn)->second != Stk::OrderStatus::PARTIALLY_FILLED) {
                // 新价格更低且可以撤销，如果是部分成交就不能撤单
                    cancel_order_by_bsn(stk_code, stk->current_sell_order);
                    add_to_waiting_map(stk_code,new_bsn,new_price,101);
                    update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
                    add_order(stk_code, 0);
            } else if (new_price == current_price) {
                // 价格相同，同时挂出
                stk->pending_sell_orders.insert(new_bsn);
                update_order_status(stk_code, new_bsn, Stk::OrderStatus::PENDING_SEND);
            } else {
                // 新价格更高，放入waiting队列
                add_to_waiting_map(stk_code, new_bsn, new_price, 101);
                update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
            }
        }
        else {
            add_to_waiting_map(stk_code, new_bsn, new_price, 101);
            update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
            add_order(stk_code, 0);
        }
    } else if (direction == 100) { // 新生成的是买单
        if (!stk->current_buy_order.empty()) {
            // 有现存买单，比较价格
            int current_bsn=stk->current_buy_order.begin()->first;
            double current_price = std::stod(total_order_list_by_orderBSN[current_bsn].ORDER_PRICE);
            if (new_price > current_price && stk->order_status_map.find(current_bsn)->second != Stk::OrderStatus::PARTIALLY_FILLED) {
                // 新价格更高且能执行撤单
                cancel_order_by_bsn(stk_code,stk->current_buy_order);
                add_to_waiting_map(stk_code,new_bsn,new_price,100);
                update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
                add_order(stk_code, 1);
            } else if (new_price == current_price) {
                // 价格相同，同时挂出
                stk->pending_buy_orders.insert(new_bsn);
                update_order_status(stk_code, new_bsn, Stk::OrderStatus::PENDING_SEND);
            } else {
                // 新价格更低，放入waiting队列
                add_to_waiting_map(stk_code, new_bsn, new_price, 100);
                update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
            }
        } else {
            //没有买单
            add_to_waiting_map(stk_code, new_bsn, new_price, 100);
            update_order_status(stk_code, new_bsn, Stk::OrderStatus::WAITING_SEND);
            add_order(stk_code, 1);
        }
    }
}


// 更新订单状态
void Strategy_non_linear::update_order_status(const std::string& stk_code, int bsn, Stk::OrderStatus status) {
    auto stk_it = stk_map.find(stk_code);
    if (stk_it == stk_map.end() || !stk_it->second) {
        auto logger = Logger::get();
        logger->error("Invalid stock code {} in update_order_status", stk_code);
        return;
    }
    stk_it->second->order_status_map[bsn] = status;
}

void Strategy_non_linear::add_to_waiting_map(const std::string& stk_code, int bsn, double price, int direction) {
    auto stk_it = stk_map.find(stk_code);
    if (stk_it == stk_map.end() || !stk_it->second) {
        auto logger = Logger::get();
        logger->error("Invalid stock code {} in add_to_waiting_map", stk_code);
        return;
    }
    auto stk = stk_it->second;
    if (direction == 100) {
        stk->buy_waiting_orders.emplace(price, bsn);
    } else {
        stk->sell_waiting_orders.emplace(price, bsn);
    }
}


// 撤销指定BSN的订单
void Strategy_non_linear::cancel_order_by_bsn(const std::string& stk_code, map<int,std::string> bsn_map) {
    auto stk = stk_map[stk_code];
    for (auto& entry:bsn_map) {
        int current_bsn = entry.first;
        std::string current_id = entry.second;
        // 根据订单状态判断是否需要发送撤单请求
        auto status_it = stk->order_status_map.find(current_bsn);
        if (status_it != stk->order_status_map.end()) {
            Stk::OrderStatus status = status_it->second;
            // 如果订单已发送（无论是否确认），都需要发送撤单请求
            if (status == Stk::OrderStatus::SENT_UNCONFIRMED || status == Stk::OrderStatus::CONFIRMED) {

                StkCancel cancel_req;
                cancel_req.iOrderBsn = current_bsn;
                cancel_req.szStkbd = stk->stk_grid.STKBD;

                // 根据订单类型设置订单ID
                if (total_order_list_by_orderBSN[current_bsn].STK_BIZ == 100) {
                    cancel_req.szOrderId = current_id;
                } else if (total_order_list_by_orderBSN[current_bsn].STK_BIZ == 101) {
                    cancel_req.szOrderId = current_id;
                }
                TestStkCancelOrder(stkTradeApi, cancel_req);
                
                // 添加数据库更新：将订单状态更新为已撤单
                db.order_update(current_bsn, current_id.c_str(), -1, "canceled");
            }
            // 从队列中移除
            remove_order_from_queues(stk_code, current_bsn,status );
        }
        // 将订单放入waiting队列以备后续使用
        add_to_waiting_map(stk_code, current_bsn, std::stod(total_order_list_by_orderBSN[current_bsn].ORDER_PRICE), total_order_list_by_orderBSN[current_bsn].STK_BIZ);
    }
}

// 从各种队列中移除订单
void Strategy_non_linear::remove_order_from_queues(const std::string& stk_code, int bsn,Stk::OrderStatus status) {
    auto stk = stk_map[stk_code];

    // status是即将发送，从发送队列中移除
    if (status==Stk::OrderStatus::PENDING_SEND) {
        std::queue<int> temp_queue;
        while (!order_to_send.empty()) {
            int current_bsn = order_to_send.front();
            order_to_send.pop();
            if (current_bsn != bsn) {
                temp_queue.push(current_bsn);
            }
        }
        order_to_send = temp_queue;
    }
    else if (status==Stk::OrderStatus::CONFIRMED) {
        // status是已发送，从当前代码撤单后仍需要移除队列
        stk->current_buy_order.erase(bsn);
        stk->current_sell_order.erase(bsn);
    }
    else {

        stk->unknown_buy_orders.erase(bsn);
        stk->unknown_sell_orders.erase(bsn);
        stk->Wrong_buy_orders.erase(bsn);
        stk->Wrong_sell_orders.erase(bsn);
    }
}



void Strategy_non_linear::preorder() {
    for (auto& p : stk_map) {
        double bench_price = std::stod(p.second->stk_grid.bench_price);
        double highest_price = floor(bench_price * (1 + 0.09) * 1000) / 1000;
        double lowest_price = ceil(bench_price * (1 - 0.09) * 1000) / 1000;
        double curr_price = bench_price;
        
        // 生成价格队列
        for (int i=1; curr_price <= highest_price; i++) {
            curr_price = bench_price + std::stod(p.second->stk_grid.grid_size) * i;
            p.second->HighOrder.push(curr_price);
        }
        curr_price = bench_price;
        for (int i=1; curr_price >= lowest_price; i++) {
            curr_price = bench_price - std::stod(p.second->stk_grid.grid_size) * i;
            p.second->LowOrder.push(curr_price);
        }

        std::stringstream ss;
        
        // 只生成一个卖单
        if (!p.second->HighOrder.empty()) {
            std::lock_guard<std::mutex> lock(order_mutex);
            StkOrder sell_order;
            sell_order.STKBD = p.second->stk_grid.STKBD;
            sell_order.STK_CODE = p.first;
            sell_order.STK_BIZ = 101;
            
            double sell_price = p.second->HighOrder.front();
            p.second->HighOrder.pop();
            
            if (sell_price > std::stod(p.second->stk_grid.seg_price)) {
                sell_order.ORDER_QTY = p.second->stk_grid.high_volume;
            } else {
                sell_order.ORDER_QTY = p.second->stk_grid.low_volume;
            }
            
            if (sell_order.ORDER_QTY > 0) {
                ss << std::fixed << std::setprecision(3) << sell_price;
                sell_order.ORDER_PRICE = ss.str();
                ss.str(""); ss.clear();
                
                modify_bsn();
                sell_order.ORDER_BSN = get_bsn();
                total_order_list_by_orderBSN[sell_order.ORDER_BSN] = sell_order;
                order_to_send.push(sell_order.ORDER_BSN);
                //pending_sell_orders[p.first] = sell_order.ORDER_BSN;
            }
        }

        // 只生成一个买单
        if (!p.second->LowOrder.empty()) {
            std::lock_guard<std::mutex> lock(order_mutex);
            StkOrder buy_order;
            buy_order.STKBD = p.second->stk_grid.STKBD;
            buy_order.STK_CODE = p.first;
            buy_order.STK_BIZ = 100;
            
            double buy_price = p.second->LowOrder.front();
            p.second->LowOrder.pop();
            
            if (buy_price > std::stod(p.second->stk_grid.seg_price)) {
                buy_order.ORDER_QTY = p.second->stk_grid.high_volume;
            } else {
                buy_order.ORDER_QTY = p.second->stk_grid.low_volume;
            }
            
            if (buy_order.ORDER_QTY > 0) {
                ss << std::fixed << std::setprecision(3) << buy_price;
                buy_order.ORDER_PRICE = ss.str();
                ss.str(""); ss.clear();
                
                modify_bsn();
                buy_order.ORDER_BSN = get_bsn();
                total_order_list_by_orderBSN[buy_order.ORDER_BSN] = buy_order;
                order_to_send.push(buy_order.ORDER_BSN);
            }
        }
    }
}

void Strategy_non_linear::add_order(string stk_code, int direction) {
    auto stk = stk_map[stk_code];
    stringstream ss;

    if (direction == 1) { // 补买单
        if (!stk->current_buy_order.empty()) {

            return; // 已有活跃买单，不再补单
        }
        
        // 先从waiting队列获取最高价格的买单，同时发送相同价格的所有订单
        if (!stk->buy_waiting_orders.empty()) {
            double highest_price = stk->buy_waiting_orders.rbegin()->first;
            
            // 发送所有最高价格的买单
            while (!stk->buy_waiting_orders.empty() && 
                   stk->buy_waiting_orders.rbegin()->first == highest_price) {
                auto it = stk->buy_waiting_orders.end();
                --it; // 指向最后一个元素（最高价格）
                int bsn = it->second;
                stk->buy_waiting_orders.erase(it);
                stk->pending_buy_orders.insert(bsn);
                update_order_status(stk_code, bsn, Stk::OrderStatus::PENDING_SEND);
            }
            return; // 发送完waiting队列中的订单后直接返回
        }
        
        // waiting队列为空时从LowOrder生成新订单
        if (stk->LowOrder.empty()) return;

        StkOrder stk_order;
        stk_order.STK_BIZ = 100;
        stk_order.STK_CODE = stk_code;
        stk_order.STKBD = stk_map[stk_code]->stk_grid.STKBD;
        
        double price = stk->LowOrder.front();
        stk->LowOrder.pop();
        ss << std::fixed << std::setprecision(3) << price;
        stk_order.ORDER_PRICE = ss.str();
        
        if (price > std::stod(stk->stk_grid.seg_price)) {
            stk_order.ORDER_QTY = stk->stk_grid.high_volume;
        } else {
            stk_order.ORDER_QTY = stk->stk_grid.low_volume;
        }
        
        if (stk_order.ORDER_QTY > 0) {
            auto logger = Logger::get();
            logger->info("[BSN_TRACE] Before modify_bsn() in add_order - Current BSN: {}", get_bsn());
            modify_bsn();
            logger->info("[BSN_TRACE] After modify_bsn() in add_order - New BSN: {}", get_bsn());
            stk_order.ORDER_BSN = get_bsn();
            total_order_list_by_orderBSN[stk_order.ORDER_BSN] = stk_order;
            order_time_stamp[stk_order.ORDER_BSN] = chrono::steady_clock::now();
            stk->pending_buy_orders.insert(stk_order.ORDER_BSN);
            update_order_status(stk_code, stk_order.ORDER_BSN, Stk::OrderStatus::PENDING_SEND);
        }
    }
    
    if (direction == 0) { // 补卖单
        if (!stk->current_sell_order.empty()) {
            return; // 已有卖单，不再补单
        }
        
        // 先从waiting队列获取最低价格的卖单，同时发送相同价格的所有订单
        if (!stk->sell_waiting_orders.empty()) {
            double lowest_price = stk->sell_waiting_orders.begin()->first;
            
            // 发送所有最低价格的卖单
            while (!stk->sell_waiting_orders.empty() && 
                   stk->sell_waiting_orders.begin()->first == lowest_price) {
                auto it = stk->sell_waiting_orders.begin(); // 最低价格
                int bsn = it->second;
                stk->sell_waiting_orders.erase(it);
                stk->pending_sell_orders.insert(bsn);
                update_order_status(stk_code, bsn, Stk::OrderStatus::PENDING_SEND);
            }
            return; // 发送完waiting队列中的订单后直接返回
        }
        
        // waiting队列为空时从HighOrder生成新订单
        if (stk->HighOrder.empty()) return;

        StkOrder stk_order;
        stk_order.STK_BIZ = 101;
        stk_order.STK_CODE = stk_code;
        stk_order.STKBD = stk_map[stk_code]->stk_grid.STKBD;
        
        double price = stk->HighOrder.front();
        stk->HighOrder.pop();
        ss << std::fixed << std::setprecision(3) << price;
        stk_order.ORDER_PRICE = ss.str();
        
        if (price > std::stod(stk->stk_grid.seg_price)) {
            stk_order.ORDER_QTY = stk->stk_grid.high_volume;
        } else {
            stk_order.ORDER_QTY = stk->stk_grid.low_volume;
        }
        
        if (stk_order.ORDER_QTY > 0) {
            auto logger = Logger::get();
            logger->info("[BSN_TRACE] Before modify_bsn() in add_order - Current BSN: {}", get_bsn());
            modify_bsn();
            logger->info("[BSN_TRACE] After modify_bsn() in add_order - New BSN: {}", get_bsn());
            stk_order.ORDER_BSN = get_bsn();
            total_order_list_by_orderBSN[stk_order.ORDER_BSN] = stk_order;
            order_time_stamp[stk_order.ORDER_BSN] = chrono::steady_clock::now();
            stk->pending_sell_orders.insert(stk_order.ORDER_BSN);
            update_order_status(stk_code, stk_order.ORDER_BSN, Stk::OrderStatus::PENDING_SEND);
        }
    }
}

void Strategy_non_linear::retry() {
    std::lock_guard<std::mutex> a_lock(re_mutex);
    StkOrder stk_order;
    for (auto& stk : stk_map) {
        for (auto &tmp:stk.second->Wrong_buy_orders) {
            auto t = order_time_stamp.find(tmp);
            if (t == order_time_stamp.end()) {
                cerr << "error: order not found in wrong_order_time" << endl;
                continue;
            }
            
            auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - t->second).count();
            if (elapsedTime < 600) break;
            
            std::lock_guard<std::mutex> lock(order_mutex);
            stk_order = total_order_list_by_orderBSN[tmp];
            auto logger = Logger::get();
            logger->info("[BSN_TRACE] Before modify_bsn() in retry - Current BSN: {}", get_bsn());
            modify_bsn();
            logger->info("[BSN_TRACE] After modify_bsn() in retry - New BSN: {}", get_bsn());
            stk_order.ORDER_BSN = get_bsn();
            total_order_list_by_orderBSN[stk_order.ORDER_BSN] = stk_order;
            order_to_send.push(stk_order.ORDER_BSN);
        }
        
        for (auto& tmp:stk.second->Wrong_sell_orders) {
            auto t = order_time_stamp.find(tmp);
            if (t == order_time_stamp.end()) {
                cerr << "error: order not found in wrong_order_time" << endl;
                continue;
            }
            
            auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - t->second).count();
            if (elapsedTime < 600) break;
            
            std::lock_guard<std::mutex> lock(order_mutex);
            stk_order = total_order_list_by_orderBSN[tmp];
            modify_bsn();
            stk_order.ORDER_BSN = get_bsn();
            total_order_list_by_orderBSN[stk_order.ORDER_BSN] = stk_order;
            order_to_send.push(stk_order.ORDER_BSN);
        }
    }
}

void Strategy_non_linear::pending_list() {
    std::lock_guard<std::mutex> lock(order_mutex);
    StkOrder stk_order;
    for (auto& p : stk_map) {

        // 修复 pending_buy_orders 的迭代删除问题
        for (auto it = p.second->pending_buy_orders.begin(); it != p.second->pending_buy_orders.end();) {
            int tmp = *it;
            auto t = order_time_stamp.find(tmp);
            if (t == order_time_stamp.end()) {
                cerr << "error: order not found in wrong_order_time" << endl;
                ++it;
                continue;
            }
            auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - t->second).count();
            if (elapsedTime < 2) {
                break;
            }
            stk_order = total_order_list_by_orderBSN[tmp];
            order_to_send.push(stk_order.ORDER_BSN);
            it = p.second->pending_buy_orders.erase(it);  // 安全删除并更新迭代器
        }

        // 修复 pending_sell_orders 的迭代删除问题
        for (auto it = p.second->pending_sell_orders.begin(); it != p.second->pending_sell_orders.end();) {
            int tmp = *it;
            auto t = order_time_stamp.find(tmp);
            if (t == order_time_stamp.end()) {
                cerr << "error: order not found in wrong_order_time" << endl;
                ++it;
                continue;
            }
            auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - t->second).count();
            if (elapsedTime < 1) {
                break;
            }
            stk_order = total_order_list_by_orderBSN[tmp];
            order_to_send.push(stk_order.ORDER_BSN);
            it = p.second->pending_sell_orders.erase(it);  // 安全删除并更新迭代器
        }
    }
}
void Strategy_non_linear::send_order() {
    std::vector<StkOrder> orders_to_send;
    long long request_id;
    retry();
    pending_list();
    flag_listen();
    cancel_listen();

    { // 锁定队列操作
        std::lock_guard<std::mutex> lock(order_mutex);
        if (order_to_send.empty() || !send_order_flag) {
            return;
        }
        while (!order_to_send.empty()) {
            int order_bsn = order_to_send.front();
            order_to_send.pop();
            orders_to_send.push_back(total_order_list_by_orderBSN[order_bsn]);
        }
    }//将公共order存放到私有order，防止因为发送加锁阻塞io

    for (size_t i = 0; i < orders_to_send.size(); ++i) {
        request_id = g_llRequestId + 1; // 使用预测的请求 ID
        const StkOrder& stk_order = orders_to_send[i];

        // 发送订单
        total_order_list_by_requestID[request_id] = stk_order.ORDER_BSN;
        TestStkOrder(stkTradeApi, stk_order);
        db.order_create(stk_order.ORDER_BSN, stk_order.STK_CODE.c_str(),
                        static_cast<int>(stk_order.ORDER_QTY), std::stod(stk_order.ORDER_PRICE),
                        stk_order.STK_BIZ, session_ID.c_str(), "NONLINEAR");
        
        // 更新订单状态
        update_order_status(stk_order.STK_CODE, stk_order.ORDER_BSN, Stk::OrderStatus::SENT_UNCONFIRMED);
        
        if (stk_order.STK_BIZ == 100) {
            stk_map[stk_order.STK_CODE]->unknown_buy_orders.insert(stk_order.ORDER_BSN);
        } else if (stk_order.STK_BIZ == 101) {
            stk_map[stk_order.STK_CODE]->unknown_sell_orders.insert(stk_order.ORDER_BSN);
        }
        else {
            cerr << "error: unknown order stk_biz" << endl;
        }
    }
}

void Strategy_non_linear::flag_listen() {
    time_t now = time(0);
    struct tm* localTime = localtime(&now);
    int currentMinutes = localTime->tm_hour * 60 + localTime->tm_min;
    send_order_flag=true;
    cancel_order_flag=true;
    // if (currentMinutes >= 557 && currentMinutes < 565) {
    //     send_order_flag = true;
    // }
    // else if (currentMinutes >= 565 && currentMinutes < 570) {
    //     send_order_flag = false;
    // }
    // else if (currentMinutes >= 570 && currentMinutes < 690) {
    //     send_order_flag = true;
    // }
    // else if (currentMinutes >= 690 && currentMinutes < 780) {
    //     send_order_flag = false;
    // }
    // else if (currentMinutes >= 780 && currentMinutes < 896) {
    //     send_order_flag = true;
    //     // cancel_order_flag = true;
    // }
    // else if (currentMinutes >= 896 && currentMinutes < 897) {
    //     send_order_flag = false;
    //     cancel_order_flag = true;
    // }
    // else if (currentMinutes >= 897) {
    //     cancel_order_flag = false;
    // }
}

void Strategy_non_linear::cancel_listen() {
    if (!cancel_order_flag) {
        return;
    }
    time_t now = time(0);
    struct tm* localTime = localtime(&now);
    int current_seconds = localTime->tm_hour * 3600 + localTime->tm_min * 60 + localTime->tm_sec;
    if (current_seconds == cancel_time) {
        return;
    }
    cancel_time = current_seconds;
    int amount = 0;
    StkCancel stk_cancel;
    for (auto& p : stk_map) {
        lock_guard<mutex> lock(cancel_mutex);
        if (!p.second->current_buy_order.empty()) {
            for (auto q : p.second->current_buy_order) {
                order_to_cancel.push(q.second);
            }
            p.second->current_buy_order.clear();
        }
        if (!p.second->current_sell_order.empty()) {
            for (auto q : p.second->current_sell_order) {
                order_to_cancel.push(q.second);
            }
            p.second->current_sell_order.clear();
        }
    }
    while (!order_to_cancel.empty() && amount < 80) {
        auto tmp = order_to_cancel.front();
        order_to_cancel.pop();
        stk_cancel.iOrderBsn = orderid_bsn_map[tmp];
        stk_cancel.szStkbd = order_detail[tmp].szStkbd;
        stk_cancel.szOrderId = tmp;
        TestStkCancelOrder(stkTradeApi, stk_cancel);
        
        // 添加数据库更新：将订单状态更新为已撤单
        db.order_update(stk_cancel.iOrderBsn, tmp.c_str(), -1, "canceled");
        
        ++amount;
    }
}


