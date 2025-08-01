//
// Created by BrianMe on 2024/8/19.
//

#include "EventQueue.h"


// 静态互斥锁初始化
std::mutex EventQueue::mutex;


/// @brief 更新t-1
/// @param _type
/// @param data
void EventQueue::updatePreData(EventType _type, std::shared_ptr<EventData> data)
{
    preData[_type] = data;
}
/// @brief 获取t-1
/// @param _type
/// @return
std::shared_ptr<EventData> EventQueue::getPreData(EventType _type)
{
    return preData[_type];
}

std::shared_ptr<EventData> EventQueue::getfront(EventType _type)
{
    if (!queues[_type].empty()) {
        return queues[_type].front();
    }
    return nullptr; // 返回空指针表示队列为空
}

void EventQueue::pop(EventType _type)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (!queues[_type].empty()) {
        if (_type == MarketData){
            int64_t last = std::static_pointer_cast<eqapi::Snapshot_L2>(queues[_type].front()->data)->last;
            mkSum -= last;
        }
        queues[_type].pop();
    }
}

int64_t EventQueue::getMkSum()
{
    return mkSum;
}

int EventQueue::getQueueSize(EventType _type)
{
    return queues[_type].size();
}


// enqueue 方法优化
void EventQueue::enqueue(EventType _type, std::shared_ptr<EventData> data) {
    std::lock_guard<std::mutex> lock(mutex);
    updatePreData(_type, data);
    queues[_type].push(data);
    if (_type == MarketData) {
        auto p = std::static_pointer_cast<eqapi::Snapshot_L2>(data->data);
        mkSum += p->last;
    }
    cvs[_type].notify_one();  // 只唤醒对应类型的线程
}

// single_process 方法优化
void EventQueue::single_process(EventType _type) {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        cvs[_type].wait(lock, [this, _type] { return stopped || !queues[_type].empty(); });
        if (stopped) {
            return;
        }
        // 队首数据
        std::shared_ptr<EventData> data = queues[_type].front();
        if (_type == MarketData && queues[_type].size() <= 10){
            lock.unlock();
            continue;
        }
        queues[_type].pop();

        lock.unlock();
        for (auto const &listener : listeners[_type]) {
            listener(data);
        }
    }
}

// join_all 方法优化
void EventQueue::join_all() {
    {
        std::lock_guard<std::mutex> lock(mutex);
        stopped = true;
    }
    // 通知所有类型的条件变量
    for (auto& [type, cv] : cvs) {
        cv.notify_all();
    }
    for (auto &thread : threads) {
        if(thread.second.joinable()) {
            thread.second.join();
        }
    }
}




// void reqStkOrder(CReqStkOrderField stField)
// {
//     // 发送报单
//     /*
//      * TODO: 封装TradeApi，发送报单
//      * int iRetCode=p_pclTradeApi->ReqOrder(&stField, ++g_llRequestId);
//     */
// }

// void subTopic(const char *pTopic){

// }