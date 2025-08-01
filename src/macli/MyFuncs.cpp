//
// Created by qt8 on 25-4-2.
//
#include "MyFuncs.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <filesystem>
#include <regex>
#include <iostream>
#include <chrono>

void write_stk_grid(std::unordered_map<std::string, std::shared_ptr<Stk>>& stk_map, OpenXLSX::XLWorksheet& sheet) {
    auto row_len = sheet.rowCount();
    for (uint32_t row = 2; row <= row_len; ++row) {
        auto stk_code = sheet.cell(row, 1);
        auto tmp = stk_code.value().get<std::string>();
        size_t dot_pos = tmp.find('.');
        std::string code = tmp.substr(0, dot_pos);
        // std::cout << "stk code: " << code << std::endl;
        std::string id = tmp.substr(dot_pos + 1);
        std::string stk_bd = "10";
        if (id == "SSE") {
            stk_bd = "10";
        }
        else if (id == "SZSE") {
            stk_bd = "00";
        }
        else {
            std::cerr << "Wrong stk_bd in row : " << row << std::endl;
            continue;
        }
        Stk temp;
        temp.stk_code = code;
        temp.stk_grid.STKBD = stk_bd;
        temp.stk_grid.stk_code = code;

        auto stk_gridsize = sheet.cell(row, 3);
        float tmp_size = stk_gridsize.value().get<float>();
        std::string grid_size = std::to_string(tmp_size);
        temp.stk_grid.grid_size = grid_size;

        auto stk_gridnum = sheet.cell(row, 4);
        int grid_num = stk_gridnum.value().get<int>();
        if (grid_num == 0) continue;
        temp.stk_grid.grid_num = grid_num;

        auto stk_seg_price = sheet.cell(row, 5);
        float tmp_seg_price = stk_seg_price.value().get<float>();
        std::string seg_price = std::to_string(tmp_seg_price);
        temp.stk_grid.seg_price = seg_price;

        auto stk_bench_price = sheet.cell(row, 6);
        float tmp_bench_price = stk_bench_price.value().get<float>();
        std::string bench_price = std::to_string(tmp_bench_price);
        temp.stk_grid.bench_price = bench_price;

        auto stk_high_volume = sheet.cell(row, 7);
        int high_volume = stk_high_volume.value().get<int>();
        temp.stk_grid.high_volume = high_volume;

        auto stk_low_volume = sheet.cell(row, 8);
        int low_volume = stk_low_volume.value().get<int>();
        temp.stk_grid.low_volume = low_volume;
        auto stk = std::make_shared<Stk>(temp);
        stk_map[code] = stk;
    }
}

std::string generate_random_string(size_t length) {
    const std::string charset =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, charset.size() - 1);

    std::string result;
    result.reserve(length);

    for(size_t i = 0; i < length; ++i) {
        result += charset[distribution(generator)];
    }

    return result;
}

std::string convertToStandardTime(int dateInt, const char* timeStr) {
    // 提取年份、月份和日期
    int year = dateInt / 10000;
    int month = (dateInt / 100) % 100;
    int day = dateInt % 100;

    // 提取小时、分钟和秒钟
    int hour = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int minute = (timeStr[2] - '0') * 10 + (timeStr[3] - '0');
    int second = (timeStr[4] - '0') * 10 + (timeStr[5] - '0');

    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day << " "
        << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second;

    return oss.str();
}

std::string get_current_date() {
    // 获取当前时间
    std::time_t now = std::time(nullptr);
    std::tm local_tm = *std::localtime(&now);

    // 格式化日期（格式：YYYY-MM-DD）
    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d") << ".log";
    return oss.str();
}

std::string find_latest_file(const std::string& folder_path, const std::string& prefix) {
    namespace fs = std::filesystem;
    std::string latest_file;
    std::string latest_date;  // 用于存储最新日期的字符串

    // 使用正则表达式匹配文件名，包含 .xlsx 后缀
    std::regex pattern(prefix + "ETF下单(\\d{8})\\.xlsx"); // 匹配例如 prefixETF下单YYYYMMDD.xlsx 的格式

    // 遍历文件夹中的所有文件
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (fs::is_regular_file(entry.status())) {
            const auto& file_name = entry.path().filename().string();
            std::smatch match;

            // 如果文件名符合命名规则
            if (std::regex_match(file_name, match, pattern)) {
                // 提取日期部分
                std::string date = match[1].str();

                // 比较日期，找出最新的日期
                if (date > latest_date) { // 字符串比较可以按字典序比较 YYYYMMDD
                    latest_date = date;
                    latest_file = entry.path().string();
                }
            }
        }
    }

    // 返回最新文件的路径，如果没有找到则返回相应消息
    return latest_file.empty() ? "没有找到符合条件的文件." : latest_file;
}
eqapi::EqSetting loadMarketSettings(int serverIndex) {
    //设置配置段
    set_section("MarketData");

    std::string ipKey,portKey,userKey,pwdKey;
    ipKey="MARKET_SERVER_IP";
    portKey="MARKET_SERVER_PORT";
    userKey="MARKET_USER";
    pwdKey="MARKET_PASSWORD";

    char serverIp[64];
    char serverPort[16];
    char user[64];
    char password[64];

    read_profile_string(ipKey.c_str(),serverIp,sizeof(serverIp),"103.77.28.28");
    read_profile_string(portKey.c_str(),serverPort,sizeof(serverPort),"12010");
    read_profile_string(userKey.c_str(),user,sizeof(user),"guest");
    read_profile_string(pwdKey.c_str(),password,sizeof(password),"password");

    std::cout << "Loading market settings: IP=" << serverIp << ", Port=" << serverPort << ", User=" << user << std::endl;

    eqapi::EqSetting setting;
    setting.ip=serverIp;
    setting.port=atoi(serverPort);
    setting.user=user;
    setting.passwd=password;
    setting.configPath="../../../bin/config/config.rqClient";
    return setting;
}

static const unsigned char to_b64[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    static const unsigned char un_b64[] = {
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62,  255, 255, 255, 63,
            52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  255, 255, 255, 255, 255, 255,
            255, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
            15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  255, 255, 255, 255, 255,
            255, 26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
            41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255
    };

#define UNSIG_CHAR_PTR(x) ((const unsigned char *)(x))
    unsigned char *acl_base64_encode( const char *in, int len){
        const unsigned char *cp;
        int     count, size = len * 4 /3;

        unsigned char * out = (unsigned char *)malloc(size + 1);
        int out_index = 0;
        for (cp = UNSIG_CHAR_PTR(in), count = len; count > 0; count -= 3, cp += 3) {
            out[out_index++] = to_b64[cp[0] >> 2];
            if (count > 1) {
                out[out_index++] = to_b64[(cp[0] & 0x3) << 4 | cp[1] >> 4];
                if (count > 2) {
                    out[out_index++] = to_b64[(cp[1] & 0xf) << 2 | cp[2] >> 6];
                    out[out_index++] = to_b64[cp[2] & 0x3f];
                }else{
                    out[out_index++] = to_b64[(cp[1] & 0xf) << 2];
                    out[out_index++] = '=';
                    break;
                }
            } else {
                out[out_index++] = to_b64[(cp[0] & 0x3) << 4];
                out[out_index++] = '=';
                out[out_index++] = '=';
                break;
            }
        }
        out[out_index] = 0;
        return out;
    }

    unsigned char *acl_base64_decode(const char *in, int len){
        const unsigned char *cp;
        int     count;
        int     ch0;
        int     ch1;
        int     ch2;
        int     ch3;

        /*
	 * Sanity check.
	 */
        if (len % 4)
            return (NULL);

#define INVALID		0xff

        unsigned char * out = (unsigned char *)malloc(len + 1);
        int out_index = 0;
        for (cp = UNSIG_CHAR_PTR(in), count = 0; count < len; count += 4) {
            if ((ch0 = un_b64[*cp++]) == INVALID
                || (ch1 = un_b64[*cp++]) == INVALID)
                return (0);
            out[out_index++] = ch0 << 2 | ch1 >> 4;
            if ((ch2 = *cp++) == '=')
                break;
            if ((ch2 = un_b64[ch2]) == INVALID)
                return (0);
            out[out_index++] = ch1 << 4 | ch2 >> 2;
            if ((ch3 = *cp++) == '=')
                break;
            if ((ch3 = un_b64[ch3]) == INVALID)
                return (0);
            out[out_index++] = ch2 << 6 | ch3;
        }

        out[out_index] = 0;
        return out;
    }
