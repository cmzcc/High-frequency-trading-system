#ifndef __eq_application_h__
#define __eq_application_h__

#include <string>
#include <vector>
#include <cstdint>
#include "quotedata.h"

//  compiler options for msvc
#ifdef MSVC
#ifndef EQ_API
#   ifdef EQ_API_EXPORTS
#       define EQ_API __declspec(dllexport)
#   else
#       define EQ_API __declspec(dllimport)
#   endif
#endif
#else 
#   define EQ_API
#endif

namespace eqapi
{
    // 服务器和账户信息
    struct EqSetting
    {
        std::string ip;
        std::int32_t port;
        std::string user;
        std::string passwd;
		std::string configPath;
    };
    enum class EqState
    {
        EQ_STATE_CONNECT,
        EQ_STATE_ERROR,
        EQ_STATE_DISCONNECT
    };
    // 回调接口
    class UserCallback
    {
    public:
        // 链接服务器成功， 返回服务器和账户信息
        virtual void onConnect(const std::string& msg) = 0;
        // 行情回调，返回一组行情数据，行情数据为JSON字符串
        virtual void onQuote(const std::vector<std::string>& quotes) = 0;
        // 重传回调，返回请求的行情数据
        virtual void onRebuild(const std::vector<std::string>& quotes) = 0;
        // 服务器日志回调，返回服务器运行信息
        virtual void onLog(const std::string& msg) = 0;
        // 错误信息回调，返回API运行的错误信息
        virtual void onError(const std::string& msg) = 0;
        // 服务器断开，返回服务器和账户信息
        virtual void onDisconnect(const std::string& msg) = 0;


        // for binary
        virtual void onQuote(const Quote_Msg_Head* head, void* data) = 0;
        virtual void onRebuild(const Quote_Msg_Head* head, void* data) = 0;
    };

    // 实时应用
    class EQ_API RqApplication : public UserCallback
    {
    public:
        /*
        * 描述：
        *          实时应用，需要提供一组服务器账户信息和一个回调接口。
        *          实时应用将会自动重连服务器，循环链接服务器
        *          客户端不需要对回调接口做出会话响应，api会自动完成会话功能
        *          注意：api重新链接之后，将会自动进行订阅之前订阅的所有行情
        *          
        *          conf: 配置文件路径，包含文件名，例如："./config/config.rqClient"
        *                默认的位置是程序运行目录下config/config.rqClient
        */
        RqApplication(const std::vector<EqSetting>& settings);
        RqApplication(const std::vector<EqSetting>& settings, const std::string& conf);
        ~RqApplication();

        RqApplication(const RqApplication&) = delete;
        RqApplication(const RqApplication&&) = delete;

        /*
        * 名称:      start
        * 描述:      启动实时api，api会自动完成会话和重连
        * 参数:      none
        * 返回值:    void
        */
        void start();
        /*
        * 名称:      stop
        * 描述:      关闭实时api，关闭之后可以运行start进行重新启动
        * 参数:      none
        * 返回值:    void
        */
        void stop();
        /*
        * 名称:      status
        * 描述:      获取api的状态
        * 参数:      none
        * 返回值:    eqapi::EqState
        */
        eqapi::EqState state();
        /*
        * 名称:      sub
        * 描述:      行情订阅，同步操作，api将会自动保存订阅记录
        * 参数:
        *
        *            line               --  订阅字符串，字符串的结构如下：marketID:quotetypeID:codeID|codeID|...+marketID:quotetypeID:codeID|codeID|...
        *                                   三元组：marketID、quoteType、code通过:号组成
        *                                   三元组通过+号组成一个完整的字符串，各ID的定义见eqapi文档
        *            type               --  0 = sub, default; 1 = unsub;
        * 返回值:    void
        */
        void sub(const std::string& line, std::int32_t type = 0);
        /*
        * 名称:      sub
        * 描述:      行情订阅，同步操作，api将会自动保存订阅记录
        * 参数:
        *
        *            market             --  订阅的市场
        *            quoteType          --  订阅的行情类型
        *            codes              --  订阅的代码
        *            type               --  0 = sub, default; 1 = unsub;
        * 返回值:    void
        * 注意:      订阅最终将生成一个字符串键值，类似于market.quoteType.code。因此如果某个字段为空则将订阅所有该字段的行情，
        *            如果前一个字段为空，则后面的字段将被忽略。
        *            例如：shl2.tick.6，将订阅上海以6开头的所有代码的Level-2行情
        */
        void sub(const std::string& market, const std::string& quoteType, const std::vector<std::string>& codes, std::int32_t type = 0);
        /*
        * 名称:      rebuild
        * 描述:      重传行情
        * 参数:
        *
        *            line               --  重传字符串，字符串的结构如下：marketID:quotetypeID:codeID|codeID|...+marketID:quotetypeID:codeID|codeID|...
        *                                   三元组：marketID、quoteType、code通过:号组成
        *                                   三元组通过+号组成一个完整的字符串，各ID的定义见eqapi文档
        *            start              --  起始时间，单位毫秒，整数，如：133033999.
        *            end                --  终止时间
        * 返回值:    void
        */
        void rebuild(const std::string& line, std::int32_t start, std::int32_t end = 235959999);
        /*
        * 名称:      rebuild
        * 描述:      行情重传
        * 参数:
        *
        *            market             --  重传的市场
        *            quoteType          --  重传的行情类型
        *            codes              --  重传的代码
        *            start              --  起始时间，单位毫秒，整数，如：133033999.
        *            end                --  终止时间
        * 返回值:    void
        * 注意:      重传最终将生成一个字符串键值，类似于market.quoteType.code。因此如果某个字段为空则将重传所有该字段在[start, end)的行情，
        *            如果前一个字段为空，则后面的字段将被忽略。
        *            例如：shl2.tick.6，将重传上海以6开头的所有代码的Level-2在[start, end)行情
        */
        void rebuild(const std::string& market, const std::string& quoteType, const std::vector<std::string>& codes, std::int32_t start, std::int32_t end = 235959999);
        /*
        * 名称:      wait_rebuild
        * 描述:      rebuild函数的同步工具，只有当前一个rebuild完成之后，才能进行下一个rebuild，此时需要调用wait_rebuild
        * 参数:      none
        * 返回值:    void
        */
        void wait_rebuild();

        /*
        * 名称:      rebuildSync
        * 描述:      行情同步重传，需要明确给定市场、类型、代码
        * 参数:
        *
        *            market             --  重传的市场
        *            quoteType          --  重传的行情类型
        *            code               --  重传的代码
        *            start              --  起始时间，单位毫秒，整数，如：133033999.
        *            end                --  终止时间
        * 返回值:    [start, end)时间范围内的数据
        * 注意:      
        *            
        *            
        */
        std::vector<std::string> rebuildSync(const std::string& market, const std::string& quoteType, const std::string& code, std::int32_t start, std::int32_t end = 235959999);

        /*
        * 名称:      rebuildTradeOrderSync
        * 描述:      行情同步重传，需要明确给定市场、类型、索引范围
        * 参数:
        *
        *            market             --  重传的市场
        *            channel            --  通道号
        *            startIndex         --  起始索引.
        *            endIndex           --  终止索引，结果将不包含endIndex
        * 返回值:    [startIndex, endIndex)逐笔数据
        * 注意:      暂定大索引范围是100000，即endIndex - startIndex <= 100000
        *            
        *
        */
        std::vector<std::string> getTradeOrderSync(const std::string& market, std::int32_t channel, std::int64_t startIndex, std::int64_t endIndex);

        /*
        * 名称:      getAllLastSnapshot
        * 描述:      行情同步重传，需要明确给定市场
        * 参数:
        *
        *            market             --  重传的市场
        * 返回值:    返回服务器上最新的全市场快照
        * 注意:      
        *
        *
        */
        std::vector<std::string> getAllLastSnapshot(const std::string& market);

        /*
        * 名称:      getLastSnapshot
        * 描述:      行情同步重传，需要明确给定市场
        * 参数:
        *         
        *            market             --  重传的市场
        *            securityID         --  代码
        * 返回值:    返回服务器上最新的全市场快照
        * 注意:
        *
        *
        */
        std::string getLastSnapshot(const std::string& market, const std::string& securityID);

        /*
        * 名称:      getByCountSync
        * 描述:      获取固定时间点附近行情数据操作，同步
        * 参数:
        *            market         --  市场
        *            quoteType      --  行情类型
        *            codes          --  代码
        *
        *            time      --  时间如：104530000
        *            count     --  数量
        *            backward  --  查询方向：true -> 过去；false -> 未来
        * 返回值:    std::vector<std::string>
        */
        std::vector<std::vector<std::string>> getByCountSync(const std::string& market, const std::string& quoteType, const std::vector<std::string>& securityIDs, std::int32_t time, std::int32_t count, bool backward);

        /*
        * 名称：   getMode
        * 描述：   获取服务的数据模式
        *
        *
        *
        *
        * 返回值：    0 - json; 1 - binary
        */
        int getMode();

        // 链接服务器成功， 返回服务器和账户信息
        virtual void onConnect(const std::string& msg) {};
        // 行情回调，返回一组行情数据，行情数据为JSON字符串
        virtual void onQuote(const std::vector<std::string>& quotes) {};
        // 重传回调，返回请求的行情数据
        virtual void onRebuild(const std::vector<std::string>& quotes) {};
        // 服务器日志回调，返回服务器运行信息
        virtual void onLog(const std::string& msg) {};
        // 错误信息回调，返回API运行的错误信息
        virtual void onError(const std::string& msg) {};
        // 服务器断开，返回服务器和账户信息
        virtual void onDisconnect(const std::string& msg) {};

        // for binary
        virtual void onQuote(const Quote_Msg_Head* head, void* data) {};
        virtual void onRebuild(const Quote_Msg_Head* head, void* data) {};

    private:
        void* _rqApp = nullptr;
    };

    // 历史应用
    class EQ_API HqApplication : public UserCallback
    {
    public:
        /*
        * 描述：
        *          历史应用，需要提供一组服务器账户信息和一个回调接口。
        *          历史应用将会自动重连服务器，循环链接服务器
        *          客户端不需要对回调接口做出会话响应，api会自动完成会话功能
        *          
        *
        *          conf: 配置文件路径，包含文件名，例如："./config/config.hqClient"
        *                默认的位置是程序运行目录下config/config.rqClient
        */
        HqApplication(const std::vector<EqSetting>& settings);
        HqApplication(const std::vector<EqSetting>& settings, const std::string& conf);
        ~HqApplication();

        HqApplication(const HqApplication&) = delete;
        HqApplication(const HqApplication&&) = delete;

        /*
        * 名称:      start
        * 描述:      启动历史api，api会自动完成会话和重连
        * 参数:      none
        * 返回值:    void
        */
        void start();
        /*
        * 名称:      stop
        * 描述:      关闭历史api，关闭之后可以运行start进行重新启动
        * 参数:      none
        * 返回值:    void
        */
        void stop();
        /*
        * 名称:      status
        * 描述:      获取api的状态
        * 参数:      none
        * 返回值:    eqapi::EqState
        */
        eqapi::EqState state();
        /*
        * 名称:      get
        * 描述:      获取行情数据操作，异步
        * 参数:
        *            
        *            line     --  订阅字符串，字符串的结构如下：marketID:quotetypeID:codeID|codeID|...+marketID:quotetypeID:codeID|codeID|...
        *                         三元组：marketID、quoteType、code通过:号组成
        *                         三元组通过+号组成一个完整的字符串，各ID的定义见eqapi文档
        *            startDate      --  日期如：20180326
        *            startTime      --  时间如：104530000
        *            endDate        --  日期如：20180326
        *            endTime        --  时间如：104530000
        *            rate           --  -1 -> 不排序；0 -> 排序；N（N > 0） -> 排序且设定回放速度
        * 返回值:    void
        */
        void get(const std::string& line,
            std::int32_t startDate, std::int32_t startTime, std::int32_t endDate, std::int32_t endTime, std::int32_t rate);
        /*
        * 名称:      get
        * 描述:      获取行情数据操作，异步
        * 参数:
        *
        *            market         --  市场
        *            quoteType      --  行情类型
        *            codes          --  代码
        *            startDate      --  日期如：20180326
        *            startTime      --  时间如：104530000
        *            endDate        --  日期如：20180326
        *            endTime        --  时间如：104530000
        *            rate           --  -1 -> 不排序；0 -> 排序；N（N > 0） -> 排序且设定回放速度
        * 返回值:    void
        */
        void get(const std::string& market, const std::string& quoteType, const std::vector<std::string>& codes,
            std::int32_t startDate, std::int32_t startTime, std::int32_t endDate, std::int32_t endTime, std::int32_t rate);

        /*
        * 名称:      wait
        * 描述:      get函数的同步工具，只有当前一个get完成之后，才能进行下一个get，此时需要调用wait
        * 参数:      none
        * 返回值:    void
        */
        void wait();


        /*
        * 名称:      getSync
        * 描述:      获取行情数据操作，同步
        * 参数:
        *
        *            market         --  市场
        *            quoteType      --  行情类型
        *            codes          --  代码
        *            startDate      --  日期如：20180326
        *            startTime      --  时间如：104530000
        *            endDate        --  日期如：20180326
        *            endTime        --  时间如：104530000
        *            rate           --  -1 -> 不排序；0 -> 排序
        * 返回值:    std::vector<std::string>
        */
        std::vector<std::string> getSync(const std::string& market, const std::string& quoteType, const std::string& code,
            std::int32_t startDate, std::int32_t startTime, std::int32_t endDate, std::int32_t endTime, std::int32_t rate = -1);


        /*
        * 名称:      getByCountSync
        * 描述:      获取固定时间点附近行情数据操作，同步
        * 参数:
        *            market         --  市场
        *            quoteType      --  行情类型
        *            codes          --  代码
        *            date      --  日期如：20180326
        *            time      --  时间如：104530000
        *            backward  --  查询方向：true -> 过去；false -> 未来
        * 返回值:    std::vector<std::string> 
        */
        std::vector<std::string> getByCountSync(const std::string& market, const std::string& quoteType, const std::string& code,
            std::int32_t date, std::int32_t time, std::int32_t count, bool backward);

        // 链接服务器成功， 返回服务器和账户信息
        virtual void onConnect(const std::string& msg) {};
        // 行情回调，返回一组行情数据，行情数据为JSON字符串
        virtual void onQuote(const std::vector<std::string>& quotes) {};
        // 服务器日志回调，返回服务器运行信息
        virtual void onLog(const std::string& msg) {};
        // 错误信息回调，返回API运行的错误信息
        virtual void onError(const std::string& msg) {};
        // 服务器断开，返回服务器和账户信息
        virtual void onDisconnect(const std::string& msg) {};
		// 历史接口没有重传
		virtual void onRebuild(const std::vector<std::string>& quotes) {};
        // for binary
        virtual void onQuote(const Quote_Msg_Head* head, void* data) {};
        virtual void onRebuild(const Quote_Msg_Head* head, void* data) {};

    private:
        void* _hqApp = nullptr;
    };
}

#endif // __eq_application_h__
