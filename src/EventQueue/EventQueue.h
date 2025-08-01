//
// Created by BrianMe on 2024/8/19.
//

#ifndef YIDA_EVENTQUEUE_H
#define YIDA_EVENTQUEUE_H
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>
#include <constant.h>
#include <functional>
#include <map>
#include <thread>
#include <unordered_map>
#include <cstring>

class EventQueue {

private:
    std::map<EventType, std::condition_variable> cvs;
    static std::mutex mutex;
    std::map<EventType, std::queue<std::shared_ptr<EventData>>> queues;
    int64_t mkSum;
    std::condition_variable cv;
    bool stopped;
    std::map<EventType, std::vector<std::function<void(std::shared_ptr<EventData>)>>> listeners;
    std::map<EventType, std::thread> threads;
    std::unordered_map<EventType, std::shared_ptr<EventData>> preData;
private:
    EventQueue(): stopped(false), mkSum(0){
        for(int i = static_cast<int>(EventType::First); i < static_cast<int>(EventType::Last); ++i){
        threads[static_cast<EventType>(i)] = std::thread([this, i](){ single_process(static_cast<EventType>(i));});
        }
    };
    EventQueue(const EventQueue&) = delete;
    // 私有赋值运算符重载，禁止赋值操作
    EventQueue& operator=(const EventQueue&) = delete;
    ~EventQueue() {
        join_all();
    }
public:
    //Meyers’ Singleton代替双重检查锁
    static EventQueue* getInstance(){
        static EventQueue instance;
        return &instance;
    }

    void updatePreData(EventType _type, std::shared_ptr<EventData> data);
    std::shared_ptr<EventData> getPreData(EventType _type);
    std::shared_ptr<EventData> getfront(EventType _type);
    std::shared_ptr<void> getback(EventType _type);
    void pop(EventType _type);
    int64_t getMkSum();
    int getQueueSize(EventType _type);
    int64_t getEverage(EventType _type);
    void single_process(EventType _type);
    void enqueue(EventType _type, std::shared_ptr<EventData> data);
    void add_listener(EventType _type, std::function<void(std::shared_ptr<EventData>)> listener) {
        listeners[_type].push_back(listener);
        if (threads.find(_type) == threads.end()) {
            threads[_type] = std::thread(&EventQueue::single_process, this, _type);
        }
    }
    void join_all();

};


#endif //YIDA_EVENTQUEUE_H
