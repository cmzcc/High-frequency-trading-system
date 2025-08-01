//
// Created by qt8 on 25-4-17.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include <unordered_map>
#include "../../include/constant.h"
#include "../macli/database.h"
#include <mutex>

int get_bsn();
void modify_bsn();

extern std::unordered_map<std::string, std::shared_ptr<Stk>> stk_map;
// extern database db;
extern std::mutex re_mutex;
extern std::string session_ID;
extern std::string database_name;


#endif //GLOBAL_H
