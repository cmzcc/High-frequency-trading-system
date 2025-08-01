#ifndef _QUEUE_TEST_H
#define _QUEUE_TEST_H


#include <iostream>
#include "constant.h"
#include "../macli/maBpuTradeApiTest.h"
#include "EventQueue.h"
#include <string.h>
#include <cassert>
#include <thread>


/// @brief 根据收到的行情数据判断是否买卖
/// @param data  队头数据
void marketListener(EventData* data){
    EventQueue* que = EventQueue::getInstance();
    std::cout << __FILE__ << ":" << __LINE__ << " : " << "marketListener: " << data->type << ", " << que->getQueueSize(data->type) << std::endl;
    while (que->getQueueSize(MarketData) > 11) {
        que->pop(MarketData);
    }
    int size = que->getQueueSize(MarketData);
    int64_t sum = que->getMkSum();
    // t+0
    auto *p = (eqapi::Snapshot_L2*)data->data;
    int64_t last = p->last;
    // t-1
    auto *p1 = (eqapi::Snapshot_L2*)que->getPreData(MarketData)->data;
    int64_t last1 = p1->last;
    // t-10
    auto *p2 = (eqapi::Snapshot_L2*)que->getfront(MarketData)->data;
    // t-9 - t+0
    double e_last1 = (sum - last1) / 10.0;
    // t-10 - t-1
    double e_last2 = (sum - last) / 10.0;
    // 买卖判断
    if (last > e_last1 && last1 < e_last2){
        std::cout << "买入" << std::endl;
        EventData orderData;
        orderData.type = Order;
        orderData.data = malloc(sizeof(CReqStkOrderField));
        // TODO 更新报单信息 updateOrderField
        que->enqueue(Order, &orderData);
    }else if (last < e_last1 && last1 > e_last2){
        std::cout << "卖出" << std::endl;
        EventData orderData;
        orderData.type = Order;
        orderData.data = malloc(sizeof(CReqStkOrderField));
        // TODO 更新报单信息 updateOrderField
        que->enqueue(Order, &orderData);
    }
    else {
        // 测试
        EventData orderData;
        orderData.type = Order;
        orderData.data = malloc(sizeof(CReqStkOrderField));
        // TODO 更新报单信息 updateOrderField
        que->enqueue(Order, &orderData);
    }
    que->pop(MarketData);
    que->updatePreData(MarketData, data);
}


/// @brief 从order队列获取数据，报单，放入trade队列订阅
/// @param data 
void orderListener(EventData* data){
    EventQueue* que = EventQueue::getInstance();
    std::cout << __FILE__ << ":" << __LINE__ << ": " << "orderListener: " << data->type << ", " << que->getQueueSize(data->type) << std::endl;
    auto* porder = (CReqStkOrderField*)data->data;
    //reqStkOrder(*porder);
}

/// @brief 跟踪maCli的订阅应答
/// @param data 
void tradeListener(EventData* data){
    EventQueue* que = EventQueue::getInstance();
    std::cout << __FILE__ << ":" << __LINE__ << ": " << "tradeListener: " << data->type << ", " << que->getQueueSize(data->type) << std::endl;
    CRspSubTopicField* p_pRspSubTopicField = (CRspSubTopicField*)data->data;
}




void onQuote(const eqapi::Quote_Msg_Head* head, void* data){
    EventQueue* que = EventQueue::getInstance();
    while(true){
        if (head->quote_data_type == eqapi::Quote_Data_Snapshot_L2){
            auto* p = (eqapi::Snapshot_L2*)data;
            //assert(head->quote_data_len == sizeof(eqapi::Snapshot_L2));
            // std::cout << "-------------------------------------------------------------------------------" <<  std::endl;
            // std::cout << "SecurityID: " << p->security_id << " Time: "<<p->time<< " Last: " << p->last 
            //     << " Value: " << p->total_value_trade << "weighted_avg_price:" <<  p->weighted_avg_price   << std::endl;
            
            EventData* eventdata = new EventData();
            eventdata->data = malloc(sizeof(eqapi::Snapshot_L2));
            memcpy(eventdata->data, data, sizeof(eqapi::Snapshot_L2));
            eventdata->type = MarketData;
            que->enqueue(MarketData, eventdata);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}
int OnRtnSubTopic(CRspSubTopicField* p_pRspSubTopicField)
{
    EventQueue* que = EventQueue::getInstance();
    while(true){
        if (p_pRspSubTopicField == NULL)
        {
            std::cout << "订阅失败" << std::endl;
            return -1;
        }
        // std::cout << "-------------------------------------------------------------------------------" <<  std::endl;
        // std::cout << "订阅应答:";
        // std::cout << " Topic:" << p_pRspSubTopicField->szTopic;
        // std::cout << " Filter:" << p_pRspSubTopicField->szFilter;
        // std::cout << " Channel:" << p_pRspSubTopicField->szChannel;
        // std::cout << " DataSet:" << p_pRspSubTopicField->chDataSet;
        // std::cout << " AcceptSn:" << p_pRspSubTopicField->llAcceptSn << std::endl;
        EventData* eventdata = new EventData();
        eventdata->type = Trade;
        eventdata->data = malloc(sizeof(CRspSubTopicField));
        memcpy(eventdata->data, p_pRspSubTopicField, sizeof(CRspSubTopicField));
        que->enqueue(Trade, eventdata);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
    

void runQuote()
{
    eqapi::Quote_Msg_Head* head = new eqapi::Quote_Msg_Head();
    head->quote_data_type = eqapi::Quote_Data_Snapshot_L2;
    eqapi::Snapshot_L2* data = new eqapi::Snapshot_L2();
    memcpy(data->security_id, "600011", 6);
    data->time = 94920000;
    data->last = 68600;
    data->total_value_trade = 26435971;
    data->weighted_avg_price = 0;
    void* voidData = data;
    onQuote(head, voidData);
}

void runSubscribe()
{
    CRspSubTopicField* p_pRspSubTopicField = new CRspSubTopicField();
    // Topic:CONFIRM00 Filter:0899003180 Channel:61002/SUB/TCP/@@IP DataSet:1 AcceptSn:243127085129000073
    memcpy(p_pRspSubTopicField->szTopic, "CONFIRM00", 10);
    memcpy(p_pRspSubTopicField->szFilter, "0899003180", 10);
    memcpy(p_pRspSubTopicField->szChannel, "61002/SUB/TCP/@@IP", 18);
    p_pRspSubTopicField->chDataSet = 1;
    p_pRspSubTopicField->llAcceptSn = 243127085129000073;
    OnRtnSubTopic(p_pRspSubTopicField);
}



int event_que_test() {
    EventQueue* que = EventQueue::getInstance();
    std::function<void(EventData*)> f1 = std::bind(marketListener, std::placeholders::_1);
    que->add_listener(MarketData, f1);
    std::function<void(EventData*)> f2 = std::bind(orderListener, std::placeholders::_1);
    que->add_listener(Order, f2);
    std::function<void(EventData*)> f3 = std::bind(tradeListener, std::placeholders::_1);
    que->add_listener(Trade, f3);

    std::vector<std::thread> threads;
    threads.push_back(std::thread(runQuote));
    // 启动runSubscribe对应的线程并添加到线程向量中
    threads.push_back(std::thread(runSubscribe));
   
    // 等待所有线程执行完毕
    for (auto& th : threads) {
        if (th.joinable()) {
            th.detach();
        }
    }
    getchar();
    return 0;
}

#endif