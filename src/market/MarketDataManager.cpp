#include "MarketDataManager.h"
#include "../macli/logger.h"


MarketDataManager::MarketDataManager(const std::vector<eqapi::EqSetting>& settings, EventQueue* queue)
    : eqapi::RqApplication(settings), eventQueue(queue) {
    logger = Logger::get();
}

bool MarketDataManager::loadTargetStocks(const std::string& excelPath) {
    OpenXLSX::XLDocument doc;
    doc.open(excelPath);
    auto workbook = doc.workbook();
    auto worksheet = workbook.worksheet("Sheet1");
    auto rowCount = worksheet.rowCount();

    std::unordered_set<std::string> tempStocks;
    logger->info("Reading Excel file: {}, total rows: {}", excelPath, rowCount);
        
    // 完全按照write_stk_grid的方式实现
    for (uint32_t row = 2; row <= rowCount; ++row)
    {
        auto stk_code = worksheet.cell(row, 1);
        auto tmp = stk_code.value().get<std::string>();
        size_t dot_pos = tmp.find('.');
        std::string code = tmp.substr(0, dot_pos);
        tempStocks.insert(code);
    }
    // 快速更新，最小化锁持有时间
    {
        std::lock_guard<std::mutex> lock(targetStocksMutex_);
        targetStocks = std::move(tempStocks);
    }
    logger->info("Successfully loaded {} target stocks from Excel file", targetStocks.size());
    return true;

}

// 回调函数实现
void MarketDataManager::onConnect(const std::string& msg) {
    std::cout << "onConnect called. Message: " << msg << std::endl;
    logger->info("Market data connection established: {}", msg);
    wait_to_sub=true;
}

void MarketDataManager::onQuote(const std::string& quote) {
    // 字符串格式的行情数据处理
    std::cout << "onQuote (string) received: " << quote << std::endl;
}

void MarketDataManager::onQuote(const eqapi::Quote_Msg_Head* head, void* data) {
    std::cout << "onQuote (struct) received." << std::endl;
    if (!head || !data) {
        std::cout << "onQuote (struct): head or data is null." << std::endl;
        return;
    }
    if (!head || !data) return;
    
    // 根据数据类型处理不同的行情数据
    if(head->quote_data_type==eqapi::Quote_Data_Snapshot_L2) {
        auto* snapshot = static_cast<eqapi::Snapshot_L2*>(data);
        if (!snapshot) return;
        std::string stockCode(snapshot->security_id);

        // 检查是否为目标股票
        {
            std::cout << "[QuoteThread] Attempting to lock targetStocksMutex_ in onQuote..." << std::endl;
            std::lock_guard<std::mutex> lock(targetStocksMutex_); // 在访问前加锁
            std::cout << "[QuoteThread] Locked targetStocksMutex_ in onQuote." << std::endl;
            if (targetStocks.find(stockCode) != targetStocks.end()) {
                logger->debug("Found target stock: {}. Preparing to enqueue.", stockCode);
                // 创建EventData
                auto eventData = std::make_shared<EventData>();
                eventData->type = EventType::MarketData;

                // 创建Snapshot_L2的副本
                auto snapshotCopy = std::make_shared<eqapi::Snapshot_L2>(*snapshot);
                eventData->data = std::static_pointer_cast<void>(snapshotCopy);

                // 将EventData入队
                eventQueue->enqueue(EventType::MarketData, eventData);
                logger->debug("Enqueued market data for stock: {}", stockCode);

                logger->debug("Processed market data for stock: {} at price: {}",stockCode, snapshot->last);
            } // 这个 if 结束
            std::cout << "[QuoteThread] Unlocking targetStocksMutex_ in onQuote." << std::endl;
        }
    }
}

void MarketDataManager::onRebuild(const std::string& quote) {
    logger->debug("Rebuild quote received: {}", quote);
}

void MarketDataManager::onRebuild(const eqapi::Quote_Msg_Head* head, void* data) {

}

void MarketDataManager::onLog(const std::string& msg) {
    logger->info("Market data log: {}", msg);
}

void MarketDataManager::onError(const std::string& msg) {
    std::cout << "onError called. Message: " << msg << std::endl;
    logger->error("Market data error: {}", msg);
}

void MarketDataManager::onDisconnect(const std::string& msg) {
    std::cout << "onDisconnect called. Message: " << msg << std::endl;
    logger->warn("Market data disconnected: {}", msg);
}