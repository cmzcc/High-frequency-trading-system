//
// Created by qt8 on 25-4-17.
//

#include "global.h"
#include "../macli/logger.h"
#include <mutex>

static int bsn = 0;

void modify_bsn() {
    ++bsn;
}

int get_bsn() {
    return bsn;
}

std::unordered_map<std::string, std::shared_ptr<Stk>> stk_map;

std::string database_name;

std::mutex re_mutex;

std::string session_ID;