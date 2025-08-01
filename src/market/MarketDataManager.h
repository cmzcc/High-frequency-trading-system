#pragma once
#include "../EventQueue/EventQueue.h"
#include "../../include/eqapiinclude/eqapi.h"
#include "../include/eqapiinclude/quotesdbtype.h"
#include <unordered_set>
#include <memory>
#include <string>
#include <mutex> // 添加 mutex 头文件
#include "constant.h"
#include "../macli/logger.h"
#include <OpenXLSX.hpp>

class MarketDataManager : public eqapi::RqApplication {
private:
    EventQueue* eventQueue;
    std::unordered_set<std::string> targetStocks; // 从Excel文件加载的目标股票代码
    std::mutex targetStocksMutex_; // 添加互斥锁
    std::shared_ptr<spdlog::logger> logger;
    
public:
    MarketDataManager(const std::vector<eqapi::EqSetting>& settings, EventQueue* queue);
    virtual ~MarketDataManager() = default;
    
    // 加载Excel文件中的股票代码
    bool loadTargetStocks(const std::string& excelPath);

    bool wait_to_sub=false;
    // 重写回调函数
    virtual void onConnect(const std::string& msg) override;
    virtual void onQuote(const std::string& quote);
    virtual void onRebuild(const std::string& quote);
    virtual void onLog(const std::string& msg) override;
    virtual void onError(const std::string& msg) override;
    virtual void onDisconnect(const std::string& msg) override;
    
    // 二进制数据回调
    virtual void onQuote(const eqapi::Quote_Msg_Head* head, void* data) override;
    virtual void onRebuild(const eqapi::Quote_Msg_Head* head, void* data) override;

};