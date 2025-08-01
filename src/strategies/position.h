//
// Created by qt8 on 25-3-27.
//

#ifndef POSITION_H
#define POSITION_H
#include <maCliTradeApi.h>

class position {
public:
    LONGLONG td_fact_position;
    LONGLONG td_able_position;
    LONGLONG yd_fact_position;
    LONGLONG yd_able_position;
    void position_change(int direction, LONGLONG volume);// direction:0买,1卖 offset:0多,1空 volume:手数
    void position_frozen(int direction, LONGLONG volume);
};

#endif //POSITION_H
