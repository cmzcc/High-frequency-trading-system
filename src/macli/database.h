//
// Created by qt8 on 25-4-9.
//

#ifndef DATA_H
#define DATA_H
#include <sqlite3.h>
#include <iostream>

int updateCurrentSession(sqlite3* db);

class database {
private:
    sqlite3* db = nullptr;

public:
    database(std::string db_name); //加载数据库，创建报单成交单表格
    int order_create(int bsn_id_, const char* stock_code_, int quantity_, double price_, int order_type_, const char *session_id_, const char *strategy_ = "GRID");
    int trade_create(int bsn_id_, const char* stock_code_, const char* trade_id_, const char* order_id_, int quantity_, double price_, const char* order_type_, int withdraw_, const char *trade_time_, const char *session_id_);
    int order_update(int bsn_id_, const char *order_id_, int filled_quantity_, const char* status_);
    int show_order();
    int show_trade();
};



#endif //DATA_H
