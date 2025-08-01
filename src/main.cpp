#include <iostream>
#include "EventQueue/EventQueue.h"
#include "macli/maBpuTradeApiTest.h"
#include "macli/maBpuStkRsp.h"
#include "market/MarketDataManager.h"
#include <thread>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <OpenXLSX.hpp>
#include "macli/logger.h"
#include "strategies/strategy_non_linear.h"
#include "macli/global.h"
#include <sys/wait.h>
#include <unistd.h>
#include <atomic>
#include <memory>

// 使用原子变量提高线程安全性
std::atomic<bool> kill_thread{false};
static pid_t maCliCPlusApp_pid = 0;

// 常量定义
namespace {
    constexpr int TARGET_CLOSE_HOUR = 20;
    constexpr int TARGET_CLOSE_MINUTE = 15;
    constexpr int TARGET_CLOSE_SECOND = 0;
    constexpr int CONNECTION_WAIT_MS = 500;
    constexpr int LOGIN_WAIT_MS = 200;
    constexpr int STARTUP_WAIT_SECONDS = 2;
    constexpr int MARKETSETTING_NUM=1;
}

void send_order(Strategy_non_linear &grid) {
    while (!kill_thread.load()) {
        grid.send_order();
        // 添加短暂休眠避免过度占用CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

bool is_time_to_close() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&current_time);

    if (local_time->tm_hour > TARGET_CLOSE_HOUR ||
        (local_time->tm_hour == TARGET_CLOSE_HOUR && local_time->tm_min > TARGET_CLOSE_MINUTE) ||
        (local_time->tm_hour == TARGET_CLOSE_HOUR && local_time->tm_min == TARGET_CLOSE_MINUTE &&
         local_time->tm_sec >= TARGET_CLOSE_SECOND)) {
        cerr << "Time to close." << endl;
        return true;
    }
    return false;
}

bool startMaCliCPlusApp() {
    maCliCPlusApp_pid = fork();
    if (maCliCPlusApp_pid == 0) {
        // 子进程：执行 maCliCPlusApp
        if (chdir("../Lnx64") != 0) {
            std::cerr << "Failed to change directory" << std::endl;
            exit(1);
        }
        execl("./maCliCPlusApp", "maCliCPlusApp", nullptr);
        exit(1); // 如果 execl 失败
    } else if (maCliCPlusApp_pid > 0) {
        // 父进程：等待一段时间让 maCliCPlusApp 启动
        sleep(STARTUP_WAIT_SECONDS);
        cout << "maCliCPlusApp started with PID: " << maCliCPlusApp_pid << endl;
        return true;
    } else {
        // fork 失败
        cerr << "Failed to start maCliCPlusApp" << endl;
        return false;
    }
}

int main(int argc, char* argv[]) {
    Logger::init();
    auto logger = Logger::get();

        /// 初始化EventQueue
        EventQueue* eventQueue = EventQueue::getInstance();

        // 配置文件加载
        int load_res;
        bool ini_name = false;
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-c") == 0) {
                if (i + 1 < argc) {
                    ini_name = true;
                    const char* arg = argv[i+1];
                    load_res = load_ini_file(arg);
                    cout << "inifile path : " << arg << endl;
                    i++;
                } else {
                    std::cerr << "Error: -c option requires an argument." << std::endl;
                    return 1;
                }
            }
        }
        if (!ini_name) {
            load_res = load_ini_file(CONF_FILE);
        }



        /***stk***/
        //创建stk Api实例
        std::unique_ptr<CBpuStkTradeApi> pclStkTradeApi(new CBpuStkTradeApi());
        //创建stk应答处理的实例
        CBpuStkTradeSpi stkBpuSpi(pclStkTradeApi.get(), eventQueue);
        //注册stk应答实例
        pclStkTradeApi->RegisterSpi(&stkBpuSpi);

        // 在 InitCliTrdApi 之前启动 maCliCPlusApp
        if (!startMaCliCPlusApp()) {
            cout << "Failed to start maCliCPlusApp, exiting..." << endl;
            return -1;
        }

        InitCliTrdApi(pclStkTradeApi.get());

        //初始化连接
        int iStkRetCode = pclStkTradeApi->Init();
        if (iStkRetCode != 0) {
            printf("C++股票API 初始化失败(RetCode=%d, RetMsg=%s)\n", iStkRetCode, pclStkTradeApi->GetLastErrorText());
            return -1;
        } else {
            printf("C++股票API 初始化成功!\n");
        }

        // 等待连接
        while (!stkBpuSpi.is_connected) {
            std::this_thread::sleep_for(std::chrono::milliseconds(CONNECTION_WAIT_MS));
            cout << "wait for connection..." << std::endl;
        }

        logger->info("successfully init");
        TestStkLogin(pclStkTradeApi.get());

        // 等待登录
        while (!stkBpuSpi.login_success()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(LOGIN_WAIT_MS));
            cout << "wait for login..." << std::endl;
        }
        if (stkBpuSpi.login_success()) logger->info("successfully login");

        //初始化策略
        char szAcctId[32 + 1];
        read_profile_string("ACCT_ID", szAcctId, sizeof(szAcctId), "0000000000000000");
        string acctId(szAcctId);
        string database_name = "grid_record_" + acctId + ".db";
        Strategy_non_linear grid = Strategy_non_linear(eventQueue, pclStkTradeApi.get(), database_name);

        // 读取网格配置
        set_section("GridRead");
        std::string gridpath(256, '\0');
        int result = read_profile_string("GRID_PATH", &gridpath[0], gridpath.size(), nullptr);
        if (result == 0) {
            std::cerr << "Error: GRID_PATH not found in config file." << std::endl;
            return -1;
        }
        gridpath.erase(gridpath.find('\0'));

        std::string prefix(16, '\0');
        result = read_profile_string("PREFIX_CODE", &prefix[0], prefix.size(), nullptr);
        if (result == 0) {
            std::cerr << "Error: PREFIX_CODE not found in config file." << std::endl;
            return -1;
        }
        prefix.erase(prefix.find('\0'));

        string gridfile = find_latest_file(gridpath, prefix);
        cout << "gridfile: " << gridfile << std::endl;

        OpenXLSX::XLDocument doc;
        doc.open(gridfile);

        auto sheet = doc.workbook().worksheet("Sheet1");
        write_stk_grid(stk_map, sheet); //读取下单excel并写入到stk_grid里面
        grid.preorder();
        doc.close();


        std::vector<eqapi::EqSetting> settings;
        settings.emplace_back(loadMarketSettings(1));
        std::unique_ptr<MarketDataManager>marketDataManager=std::make_unique<MarketDataManager>(settings, eventQueue);
        marketDataManager->start();
        while (!marketDataManager->wait_to_sub) {
            cout << "wait to connect..." << std::endl;
        }
        // 连接成功后自动订阅行情
        if (marketDataManager->state() == eqapi::EqState::EQ_STATE_CONNECT) {
            std::vector<std::string>vec;
            std::cout << "Attempting to subscribe"<< std::endl;
            logger->info("subscribing to {}");
            marketDataManager->sub("shl1","tick",vec,0); // 0表示订阅
            logger->info("Subscribed to Shanghai L1 tick data");
            std::cout << "Subscription request sent." << std::endl;
        } else {
            std::cout << "Cannot subscribe: not connected to market data server. State: " << static_cast<int>(marketDataManager->state()) << std::endl;
            logger->error("Cannot subscribe: not connected to market data server");
        }
        // 加载目标股票列表并订阅行情
        if (!marketDataManager->loadTargetStocks(gridfile)) {
        logger->error("Failed to load target stocks");
        return -1;
        }

        // 股票订阅确认
        TestStkSubTopic(pclStkTradeApi.get(), "CONFIRM");

        std::thread sendOrder([&grid]() {
            send_order(grid);
        });
        sendOrder.detach();

        // 主循环
        while (!is_time_to_close()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        // 资源清理
        kill_thread.store(true);

        // // 先停止行情数据管理器
        // marketDataManager->stop();

        if (pclStkTradeApi != nullptr) {
            pclStkTradeApi->Exit();
        }

        Logger::shutdown();
        eventQueue->join_all();
        cerr << "que close" << std::endl;

        return 0;
}
