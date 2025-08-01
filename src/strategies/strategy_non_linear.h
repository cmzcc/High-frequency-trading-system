//
// Created by qt8 on 25-4-16.
//

#ifndef STRATEGY_GRID_H
#define STRATEGY_GRID_H

#include "strategy_template.h"
#include "../macli/global.h"
#include <sstream>
#include <iomanip>

class Strategy_non_linear : public StrategyTemplate {
private:
    std::queue<int> order_to_send;
    std::queue<int> cancel_order_to_send;
    bool send_order_flag = false;
    bool cancel_order_flag = false;
    std::queue<string> order_to_cancel;
    int cancel_time;

    std::mutex re_mutex;
    
    void flag_listen(); // 实时判断两个flag条件是否需要改变
    void cancel_listen();
    
public:
    Strategy_non_linear(EventQueue* q,CBpuStkTradeApi* pclStkTradeApi, string database_name)
        : StrategyTemplate(q, pclStkTradeApi, database_name) {}

    ~Strategy_non_linear() override = default;

    void marketListener(const std::shared_ptr<EventData>& data) override;
    void orderListener(const std::shared_ptr<EventData>& order_data) override;
    void tradeListener(const std::shared_ptr<EventData>& fill_data) override;
    void errorListener(const std::shared_ptr<EventData>& error_data) override;

    void preorder(); // 初始订单-只发送一对订单
    void add_order(string stk_code, int direction); // 补单
    void retry(); // 将重试的订单放入等待发送队列
    void pending_list(); // push waitlist 中的订单进入等待发送队列
    
    // 核心重构函数
    void check_and_replace_order(const std::string& stk_code, int direction, double new_price, int new_bsn);

    void cancel_order_by_bsn(const std::string& stk_code, map<int,std::string> bsn_map);
    void remove_order_from_queues(const std::string& stk_code, int bsn, Stk::OrderStatus status);

    void add_to_waiting_map(const std::string& stk_code, int bsn, double price, int direction);

    void update_order_status(const std::string& stk_code, int bsn, Stk::OrderStatus status);
    void send_order(); // 将等待发送队列正式发出
    std::queue<int> get_order_to_send(){return order_to_send;}

};
#endif //STRATEGY_GRID_H
