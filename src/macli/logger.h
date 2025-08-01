//
// Created by qt8 on 25-4-11.
//

#ifndef LOGGER_H
#define LOGGER_H

#include "spdlog/spdlog.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>
#include <spdlog/details/null_mutex.h>

class Logger {
public:
    static void init();  // 初始化日志记录器

    static std::shared_ptr<spdlog::logger> get();  // 获取日志记录器

    static void shutdown();

private:
    static std::shared_ptr<spdlog::logger> logger;  // 日志记录器实例
};



#endif //LOGGER_H
