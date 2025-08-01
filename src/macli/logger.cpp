//
// Created by qt8 on 25-4-11.
//

#include "logger.h"
#include "MyFuncs.h"  // 确保此处能找到 get_current_date() 函数

std::shared_ptr<spdlog::logger> Logger::logger;

void Logger::init() {
    std::string log_filename = get_current_date();
    spdlog::init_thread_pool(8192, 1); // 8192个日志条目，1个工作线程
    logger = spdlog::basic_logger_mt("async_logger", log_filename);
    logger->set_level(spdlog::level::info);
}

std::shared_ptr<spdlog::logger> Logger::get() {
    return logger;
}

void Logger::shutdown() {
    if (logger) {
        // 确保所有日志消息都被刷新到目标输出
        logger->flush();

        // 重置logger指针
        logger.reset();
    }

    // 关闭并清理spdlog库的所有资源
    spdlog::shutdown();
}
