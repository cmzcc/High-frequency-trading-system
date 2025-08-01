#include "../include/eqapiinclude/eqapi.h"
#include "../include/eqapiinclude/quotesdbtype.h"

#include <assert.h>
#include <iostream>
#include <thread>
#include<stdlib.h>
#include<time.h>


std::string code = "{\"0\":\"";
void printQuote(const eqapi::Quote_Msg_Head* head, void* data);
class MyRqApplication : public eqapi::RqApplication
{
public:
    MyRqApplication(const std::vector<eqapi::EqSetting>& settings): eqapi::RqApplication(settings)
    {

    }

    MyRqApplication(const std::vector<eqapi::EqSetting>& settings, const std::string& conf_path) : eqapi::RqApplication(settings, conf_path)
    {

    }

    void onConnect(const std::string& msg)
    {
        std::cout << msg<< std::endl;
    }
    void onQuote(const std::vector<std::string>& quotes)
    {

         std::cout << "receive " << quotes.size() << std::endl;
         for (auto& item : quotes)
         {
             std::cout << item.c_str() << std::endl;;
         }
    }
    void onQuote(const eqapi::Quote_Msg_Head* head, void* data) 
    {
        printQuote(head, data);
    };
    void onRebuild(const eqapi::Quote_Msg_Head* head, void* data) 
    {
        printQuote(head, data);
    };
    void onLog(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }
    void onError(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }
    void onDisconnect(const std::string& msg)
    {
        std::cout << msg<< std::endl;
    }
};

void printQuote(const eqapi::Quote_Msg_Head* head, void* data)
{
    switch (head->quote_data_type)
    {
    case eqapi::Quote_Data_Snapshot_L2:
    {
        auto* p = (eqapi::Snapshot_L2*)data;
        assert(head->quote_data_len == sizeof(eqapi::Snapshot_L2));
        std::cout << "SecurityID: " << p->security_id << " Time: "<<p->time<< " Last: " << p->last << " Value: " << p->total_value_trade << "weighted_avg_price:" <<  p->weighted_avg_price   << std::endl;
        //utils::log_info("SecurityID: %s, Time: %d, Last: %ld, Value: %ld, Volume: %ld", p->security_id, p->time, p->last, p->total_value_trade, p->total_volume_trade);
    }
    break;
    case eqapi::Quote_Data_Snapshot_Index:
    {
        auto* p = (eqapi::Snapshot_Index*)data;
        assert(head->quote_data_len == sizeof(eqapi::Snapshot_Index));
        std::cout << "SecurityID: " << p->security_id << " Time: " << p->time << " Last: " << p->last << " Value: " << p->total_value << std::endl;
    }
    break;
    case eqapi::Quote_Data_Trade:
    {
        auto* p = (eqapi::Trade*)data;
        assert(head->quote_data_len == sizeof(eqapi::Trade));
		std::cout << "Trade SecurityID: " << p->security_id << " Channel: " << p->channel << " Index: " << p->index << std::endl;
    }
    break;
    case eqapi::Quote_Data_Order:
    {
        auto* p = (eqapi::Order*)data;
        assert(head->quote_data_len == sizeof(eqapi::Order));
        std::cout << "Order SecurityID: " << p->security_id << " Channel: " << p->channel << " Index: " << p->index <<  std::endl;
    }
    break;
    case eqapi::Quote_Data_Kline:
    {
        auto* p = (eqapi::Kline*)data;
        assert(head->quote_data_len == sizeof(eqapi::Kline));
//         utils::log_info("SecurityID : %s, Date : %d, Time : %d, Open : %ld, High : %ld, Low : %ld, Last : %ld, Volume : %lld, Value : %lld",
//             p->security_id, p->date, p->time, p->open, p->high, p->low, p->last, p->volume, p->value);
        std::cout << "Kline SecurityID: " << p->security_id << " Open: " << p->open << " High: "<< p->high<< " Low: " << p->low << " Last: " << p->last <<" Volume: " << p->volume << " Value: " << p->value << std::endl;
    }
    break;
    case eqapi::Quote_Data_Snapshot_Future:
    {
        auto* p = (eqapi::Snapshot_Future*)data;
        assert(head->quote_data_len == sizeof(eqapi::Snapshot_Future));
        //         utils::log_info("SecurityID : %s, Date : %d, Time : %d, Open : %ld, High : %ld, Low : %ld, Last : %ld, Volume : %lld, Value : %lld",
        //             p->security_id, p->date, p->time, p->open, p->high, p->low, p->last, p->volume, p->value);
        std::cout << "Kline SecurityID: " << p->security_id << " Open: " << p->open << " High: " << p->high << " Low: " << p->low << " Last: " << p->last << " Volume: " << p->total_volume << " Value: " << p->total_value << std::endl;
    }
    break;
	case eqapi::Quote_Data_Snapshot_L2_Hkex:
	{
		auto* p = (eqapi::Snapshot_L2_Hkex*)data;
		assert(head->quote_data_len == sizeof(eqapi::Snapshot_L2_Hkex));
		//         utils::log_info("SecurityID : %s, Date : %d, Time : %d, Open : %ld, High : %ld, Low : %ld, Last : %ld, Volume : %lld, Value : %lld",
		//             p->security_id, p->date, p->time, p->open, p->high, p->low, p->last, p->volume, p->value);
		std::cout << "hk SecurityID: " << p->security_id  << "  indicative_equilibrium_volume: " << p->indicative_equilibrium_volume << " vcm_ref: " << p->vcm_reference_price << " vcm_upper: " << p->vcm_upper_price << " vcm_low: " << p->vcm_lower_price << "reserved1: " << p->reserved1 << std::endl;
	}
	break;
	case eqapi::Quote_Data_Snapshot_Main_Hkex:
	{
		auto* p = (eqapi::Snapshot_Main_Hkex*)data;
		assert(head->quote_data_len == sizeof(eqapi::Snapshot_Main_Hkex));
		//         utils::log_info("SecurityID : %s, Date : %d, Time : %d, Open : %ld, High : %ld, Low : %ld, Last : %ld, Volume : %lld, Value : %lld",
		//             p->security_id, p->date, p->time, p->open, p->high, p->low, p->last, p->volume, p->value);
		std::cout << "security_id : " << p->security_id << std::endl;
		std::cout << "market : " << p->market << std::endl;
		std::cout << "date : " << p->date << std::endl;
		std::cout << "time : " << p->time << std::endl;
		std::cout << "quote_type : " << int(p->quote_type) << std::endl;
		std::cout << "eq_tpc : " << p->eq_tpc << std::endl;
		std::cout << "tpc : " << p->tpc << std::endl;
		std::cout << "preclose : " << p->preclose << std::endl;
		std::cout << "high : " << p->high << std::endl;
		std::cout << "low : " << p->low << std::endl;
		std::cout << "last :" << p->last << std::endl;
		std::cout << "close : " << p->close << std::endl;
		std::cout << "offer_price : " << p->offer_price[0] << std::endl;
		std::cout << "offer_volume : " << p->offer_volume[0] << std::endl;
		std::cout << "bid_price : " << p->bid_price[0] << std::endl;
		std::cout << "bid_volume : " << p->bid_volume[0] << std::endl;
		std::cout << "total_volume_trade : " << p->total_volume_trade << std::endl;
		std::cout << "total_value_trade : " << p->total_value_trade << std::endl;
		std::cout << "nominal_price :  " << p->nominal_price << std::endl;
		std::cout << "reference_price : " << p->reference_price << std::endl;
		std::cout << "pos_upper_price : " << p->pos_upper_price << std::endl;
		std::cout << "pos_lower_price : " << p->pos_lower_price << std::endl;
		std::cout << "reference_upper_price : " << p->reference_upper_price << std::endl;
		std::cout << "reference_lower_price : " << p->reference_lower_price << std::endl;
		std::cout << "vcm_start_time :  " << p->vcm_start_time << std::endl;
		std::cout << "vcm_end_time : " << p->vcm_end_time << std::endl;
		std::cout << "vcm_reference_price : " << p->vcm_reference_price << std::endl;
		std::cout << "vcm_upper_price : " << p->vcm_upper_price << std::endl;
		std::cout << "vcm_lower_price : " << p->vcm_lower_price << std::endl;
		std::cout << "suspension_indicator : " << int(p->suspension_indicator) << std::endl;
		std::cout << "order_imbalance_direction :  " << int(p->order_imbalance_direction) << std::endl;
		std::cout << "order_imbalance_quanty : " << int(p->order_imbalance_quanty) << std::endl;
		std::cout << "reserv1 : " << p->reserved1 << std::endl;
		std::cout << "reserv2 : " << p->reserved2 << std::endl;
		std::cout << "reserv3 : " << p->reserved3 << std::endl;
		std::cout << "reserv4 : " << p->reserved4 << std::endl;
		std::cout << "\n\n\n" << std::endl;
	}
	break;
    default:
    {
        std::cout << "unknown quote data type" << std::endl;
    }
        break;
    }
}

void printQuote(const std::string& quote)
{
    if (quote.size() == 0)
    {
        std::cout << "get null quote" << std::endl;
        return;
    }
    auto* head = (eqapi::Quote_Msg_Head*)quote.c_str();
    void* data = head + 1;
    printQuote(head, data);
}


int main(int argc, char** argv)
{
    if (argc < 9)
    {
        std::cout << "read me: " << std::endl;
        std::cout << "input (tcp server1{ip} {port} {user} {passwd}) (tcp server2{ip} {port} {user} {passwd}) {marketID:quotetypeID:codeID|codeID|...codeID+marketID:quotetypeID:codeID|codeID|...codeID+...}" << std::endl;
        std::cout << "a triple is comprised of a market with securityID sequence which split by '|' and a type separated by ':', and then grouped by '+' " << std::endl;
        std::cout << "sample: 'test test  shl2:tick:600000|600004+szl2:tick:000001' " << std::endl;
        std::cout << "code could be head characters, for example, 600 for securityCode start with 600" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        getchar();

        return 0;
    }
	std::cout << argv[1] << std::endl;

    std::vector<eqapi::EqSetting> settings;
    // server one
    eqapi::EqSetting setting;
    setting.ip = argv[1];
    setting.port = std::atoi(argv[2]);
    setting.user = argv[3];
    setting.passwd = argv[4];
    settings.emplace_back(setting);
    // server two
    eqapi::EqSetting setting1;
    setting1.ip = argv[5];
    setting1.port = std::atoi(argv[6]);
    setting1.user = argv[7];
    setting1.passwd = argv[8];
    settings.emplace_back(setting1);


    //code += argv[10];
    // app
    MyRqApplication rqApp(settings);
    // start
    rqApp.start();

    // get code table
    if (rqApp.state() == eqapi::EqState::EQ_STATE_CONNECT)
    {
		rqApp.sub(argv[9], 0);
        auto ct = rqApp.rebuildSync("szl2", "tick", "000001", 0);
        std::cout << "receive code num " << ct.size() << std::endl;
 		for (auto& item : ct)
// 		{
//             //printQuote(item);
// 			std::cout << "codes:" << item.c_str() << std::endl;
// 		}
//         rqApp.rebuild("szl2:trade:@.*", 92500000, 92600000);
//         rqApp.wait_rebuild();
// 		ct = rqApp.rebuildSync("shl2", "etff", "", 0, 0);
// 		std::cout << "receive etff num " << ct.size() << std::endl;
// // 		for (auto& item : ct)
// // 		{
// // 			std::cout << "codes:" << item.c_str() << std::endl;
// // 		}
// 		ct = rqApp.rebuildSync("szl2", "code", "", 0, 0);
// 		std::cout << "receive code num " << ct.size() << std::endl;
// 		for (auto& item : ct)
// 		{
// 			std::cout << "codes:" << item.c_str() << std::endl;
// 		}
// 		ct = rqApp.rebuildSync("szl2", "etff", "", 0, 0);
// 		std::cout << "receive etff num " << ct.size() << std::endl;
// // 		for (auto& item : ct)
// // 		{
// // 			std::cout << "codes:" << item.c_str() << std::endl;
// // 		}
     }
//     std::cout << "rebuildsync tick..." << std::endl;
//     auto quotes = rqApp.rebuildSync("szl2", "tick", "000001", 90000000, 93000000);
//     for (auto& item : quotes)
//     {
//         //printQuote(item);
//         std::cout << item << std::endl;
//     }
//     std::cout << "rebuildsync trade..." << std::endl;
//     auto trades = rqApp.rebuildSync("shl2", "trade", "600000", 0, 160000000);
//     for (auto& item : trades)
//     {
//         printQuote(item);
//     }
//     std::cout << "rebuildsync order..." << std::endl;
//     auto orders = rqApp.rebuildSync("szl2", "order", "000001", 90000000, 150000000);
//     for (auto& item : orders)
//     {
//         printQuote(item);
//     }
//
//     std::cout << "getLastSnapshot ..." << std::endl;
//     auto lastSnapshot = rqApp.getLastSnapshot("szl2", "000001");
//     printQuote(lastSnapshot);
//
//     std::cout << "getAllLastSnapshot .." << std::endl;
//         auto lastSnapshots = rqApp.getAllLastSnapshot("shl2");
//         for (auto& item: lastSnapshots)
//         {
//             printQuote(item);
//         }
//
/*	std::cout << "getTradeOrderIndex  trade ..." << std::endl;
    auto tradeByIndex = rqApp.getTradeOrderSync("szl2", 2012, 1000, 1100);
    for (auto& item: tradeByIndex)
    {
        printQuote(item);
    }*/
//
/*       std::cout << "getTradeOrderIndex  order ..." << std::endl;
	   auto orderByIndex = rqApp.getTradeOrderSync("szl2", "trade", 2013, 308070, 308177);  //16116758);
       for (auto& item : orderByIndex)
       {
          printQuote(item);
       }*/
//     std::cout << "getByCountSync   ..." << std::endl;
//     std::vector<std::string> sids;
//     sids.emplace_back("000001");
//     sids.emplace_back("000002");
//     auto quotesVec = rqApp.getByCountSync("szl2", "trade", sids, 95225000, 10, true);
//     for (auto& quotes : quotesVec)
//     {
//         for (auto& quote : quotes)
//         {
//             printQuote(quote);
//             //std::cout << quote << std::endl;
//         }
//     }


/*	if (rqApp.state() == eqapi::EqState::EQ_STATE_CONNECT)
    {
        std::cout << "Sub: " << argv[9] << std::endl;
        rqApp.sub(argv[9]);
    }*/

    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    // unsub
    /* if (rqApp.state() == eqapi::EqState::EQ_STATE_CONNECT)
     {
         rqApp.sub(argv[10], 0);
     }*/

    std::cout << "\nexit...\n";
    getchar();

   // rqApp.stop();

    return 0;
}
