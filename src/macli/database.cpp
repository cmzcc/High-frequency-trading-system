//
// Created by qt8 on 25-4-9.
//

#include "database.h"

int updateCurrentSession(sqlite3* db) {
    // SQL语句更新符合条件的记录
    const char* sql = R"(
        UPDATE orders
        SET is_current_session = 1
        WHERE is_current_session = 0
        AND date(create_time) = date('now', 'localtime');
    )";

    // 准备和执行SQL语句
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL update sessionid error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return rc;
    }

    return SQLITE_OK;
}

database::database(std::string db_name) {
    char *errMsg = 0;
    int rc = sqlite3_open(db_name.c_str(), &db);
    if (rc) {
        std::cerr <<  "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_exec(db, "PRAGMA journal_mode=WAL;", 0, 0, &errMsg);

    const char* sql_orders = R"(
CREATE TABLE IF NOT EXISTS orders (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    bsn_id INTEGER NOT NULL,
    order_id TEXT DEFAULT NULL,
    stock_code TEXT NOT NULL,
    quantity INTEGER NOT NULL,
    filled_quantity INTEGER NOT NULL DEFAULT 0,
    price REAL NOT NULL,
    order_type TEXT NOT NULL CHECK(order_type IN ('buy', 'sell')),
    status TEXT NOT NULL CHECK(status IN ('pending', 'partially_filled', 'filled', 'canceled', 'rejected', 'unknown')) DEFAULT 'unknown',
    create_time TEXT DEFAULT (datetime('now')),
    session_id TEXT NOT NULL,
    is_current_session INTEGER NOT NULL DEFAULT 0,
    update_time TEXT DEFAULT (datetime('now')),
    strategy TEXT DEFAULT GRID
);)";

    rc =  sqlite3_exec(db, sql_orders, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "orders table SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    updateCurrentSession(db);

    const char* sql_trade = R"(
CREATE TABLE IF NOT EXISTS trade (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    bsn_id INTEGER NOT NULL,
    stock_code TEXT NOT NULL,
    trade_id TEXT NOT NULL,
    order_id TEXT NOT NULL,
    quantity INTEGER NOT NULL,
    price REAL NOT NULL,
    order_type TEXT NOT NULL CHECK(order_type IN ('buy', 'sell')),
    withdraw INTEGER NOT NULL DEFAULT 0,
    trade_time TEXT NOT NULL,
    session_id TEXT NOT NULL
);)";

    rc =  sqlite3_exec(db, sql_trade, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "trade table SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // std::cout << "successful" << std::endl;
}

int database::order_create(int bsn_id_, const char *stock_code_, int quantity_, double price_, int order_type_, const char *session_id_, const char *strategy_) {
    const char* sql = "INSERT INTO orders (bsn_id, stock_code, quantity, price, order_type, session_id, strategy, status, create_time, update_time ) VALUES (?, ?, ?, ?, ?, ? , ?, 'unknown' ,DATETIME('now', 'localtime'), DATETIME('now', 'localtime'));";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "2Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return rc;  // 返回错误码
    }
   std::string side;
    if (order_type_ == 100) {
        side = "buy";
    }
    else if (order_type_ == 101) {
        side = "sell";
    }
    else{
        std::cerr << "Invalid order type" << std::endl;
        return -1;
    }

    sqlite3_bind_int(stmt, 1, bsn_id_);
    sqlite3_bind_text(stmt, 2, stock_code_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, quantity_);
    sqlite3_bind_double(stmt, 4, price_);
    sqlite3_bind_text(stmt, 5, side.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, session_id_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, strategy_, -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "failed: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}

int database::trade_create(int bsn_id_, const char *stock_code_, const char *trade_id_, const char *order_id_, int quantity_, double price_, const char *order_type_, int withdraw_, const char *trade_time_, const char *session_id_) {
    const char* sql = "INSERT INTO trade (bsn_id, stock_code, trade_id, order_id, quantity, price, order_type, withdraw, trade_time, session_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "3Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return rc;  // 返回错误码
    }
    sqlite3_bind_int(stmt, 1, bsn_id_);
    sqlite3_bind_text(stmt, 2, stock_code_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, trade_id_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, order_id_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, quantity_);
    sqlite3_bind_double(stmt, 6, price_);
    sqlite3_bind_text(stmt, 7, order_type_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 8, withdraw_);
    sqlite3_bind_text(stmt, 9, trade_time_, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 10, session_id_, -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}

int database::order_update(int bsn_id_, const char *order_id_, int filled_quantity_, const char *status_) {
    // 参数验证
    if (bsn_id_ <= 0) {
        std::cerr << "Invalid bsn_id" << std::endl;
        return SQLITE_ERROR;
    }

    // 至少需要一个参数更新
    if (filled_quantity_ < 0 && status_ == nullptr && order_id_ == nullptr) {
        std::cerr << "No parameters to update" << std::endl;
        return SQLITE_ERROR;
    }

    std::string sql = "UPDATE orders SET ";
    bool first = true;

    // 构建SQL语句 - 只添加非空参数
    if (filled_quantity_ >= 0) {
        sql += "filled_quantity = ?";
        first = false;
    }

    if (status_ != nullptr) {
        if (!first) sql += ", ";
        sql += "status = ?";
        first = false;
    }

    if (order_id_ != nullptr) {
        if (!first) sql += ", ";
        sql += "order_id = ?";
    }

    sql += ", update_time = DATETIME('now', 'localtime') WHERE bsn_id = ?";

    // 添加其他条件
    sql += " AND is_current_session = 0";

    // std::cerr << "Final SQL: " << sql << std::endl;

    // 准备语句
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << " SQL: " << sql << std::endl;
        return rc;
    }

    // 绑定参数
    int param_index = 1;

    // 只绑定非空参数
    if (filled_quantity_ >= 0) {
        rc = sqlite3_bind_int(stmt, param_index++, filled_quantity_);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to bind filled_quantity: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return rc;
        }
    }

    if (status_ != nullptr) {
        rc = sqlite3_bind_text(stmt, param_index++, status_, -1, SQLITE_STATIC);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to bind status: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return rc;
        }
    }

    if (order_id_ != nullptr) {
        rc = sqlite3_bind_text(stmt, param_index++, order_id_, -1, SQLITE_STATIC);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to bind order_id: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return rc;
        }
    }

    // 绑定bsn_id
    rc = sqlite3_bind_int(stmt, param_index, bsn_id_);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to bind bsn_id: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return rc;
    }

    // 执行语句
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cerr << "Update successful, update bsn: " << bsn_id_ << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}


int database::show_order() {
    std::cerr << "show order : -----------------------------------------------------------------------------------------" << std::endl;
    const char *sql = "SELECT * FROM orders WHERE is_current_session = 0;";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        int bsn_id = sqlite3_column_int(stmt, 1);
        const unsigned char *order_id = sqlite3_column_text(stmt, 2);
        const unsigned char *stock_code = sqlite3_column_text(stmt, 3);
        int quantity = sqlite3_column_int(stmt, 4);
        int filled_quantity = sqlite3_column_int(stmt, 5);
        double price = sqlite3_column_double(stmt, 6);
        const unsigned char *order_type = sqlite3_column_text(stmt, 7);
        const unsigned char *status = sqlite3_column_text(stmt, 8);
        const unsigned char *create_time = sqlite3_column_text(stmt, 9);
        const unsigned char *session_id = sqlite3_column_text(stmt, 10);
        int is_current_session = sqlite3_column_int(stmt, 11);
        const unsigned char *update_time = sqlite3_column_text(stmt, 12);
        std::cerr << "ID: " << id << ", BSN ID: " << bsn_id << ", Order ID: " << order_id << std::flush
                  << ", Stock Code: " << stock_code << ", Quantity: " << quantity << std::flush
                  << ", Filled Quantity: " << filled_quantity << ", Price: " << price << std::flush
                  << ", Order Type: " << order_type << ", Status: " << status << std::flush
                  << ", Create Time: " << create_time << ", Update Time: " << update_time << std::flush
                  << ", Session ID: " << session_id
                  << std::endl;
    }

    std::cerr << "-----------------------------------------------------------------------------------------" << std::endl;

    sqlite3_finalize(stmt);
    return rc;
}

int database::show_trade() {
    std::cout << "show trade : -----------------------------------------------------------------------------------------" << std::endl;
    const char *sql = "SELECT * FROM trade;";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        int bsn_id = sqlite3_column_int(stmt, 1);
        const unsigned char *stock_code = sqlite3_column_text(stmt, 2);
        const unsigned char *trade_id = sqlite3_column_text(stmt, 3);
        const unsigned char *order_id = sqlite3_column_text(stmt, 4);
        int quantity = sqlite3_column_int(stmt, 5);
        double price = sqlite3_column_double(stmt, 6);
        const unsigned char *order_type = sqlite3_column_text(stmt, 7);
        int withdraw = sqlite3_column_int(stmt, 8);
        const unsigned char *trade_time = sqlite3_column_text(stmt, 9);
        const unsigned char *session_id = sqlite3_column_text(stmt, 10);

        std::cout << "ID: " << id << ", BSN ID: " << bsn_id << ", Stock Code: " << stock_code
                  << ", Trade ID: " << trade_id << ", Order ID: " << order_id
                  << ", Quantity: " << quantity << ", Price: " << price
                  << ", Order Type: " << order_type << ", Withdraw: " << withdraw
                  << ", Trade Time: " << trade_time
                  << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;

    sqlite3_finalize(stmt);
    return rc;
}
