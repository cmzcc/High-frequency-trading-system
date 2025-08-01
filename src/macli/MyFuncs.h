#pragma once

#include "iniFileRW.h"
#include "../../include/constant.h"
#include "../../include/eqapiinclude/eqapi.h"
void write_stk_grid(std::unordered_map<std::string, std::shared_ptr<Stk>>& stk_map, OpenXLSX::XLWorksheet& sheet);

eqapi::EqSetting loadMarketSettings(int serverIndex);

std::string generate_random_string(size_t length);

std::string convertToStandardTime(int dateInt, const char* timeStr);

std::string get_current_date();

std::string find_latest_file(const std::string& folder_path, const std::string& prefix);

unsigned char *acl_base64_encode( const char *in, int len);

unsigned char *acl_base64_decode(const char *in, int len);