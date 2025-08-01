#ifndef __quote_data_h__
#define __quote_data_h__

//
//
//  ?????????????
//
//

#include <cstdint>

namespace eqapi
{
#pragma pack(1)

	enum Quote_Data_Type : std::uint16_t
	{
		Quote_Data_Snapshot = 0x0000,
		Quote_Data_Snapshot_L1 = 0x0001,
		Quote_Data_Snapshot_L2 = 0x0002,
		Quote_Data_Snapshot_Index = 0x0003,
		Quote_Data_Snapshot_Future = 0x0004,
		Quote_Data_Snapshot_Sgex = 0x0005,
		Quote_Data_Snapshot_L2_Bond = 0x0006,
		Quote_Data_Snapshot_L1_Bond = 0x0007,
		Quote_Data_Snapshot_L2_Hkex = 0x0011,
		Quote_Data_Snapshot_Nq = 0x0012,
		Quote_Data_Snapshot_Nqzs = 0x0013,
		Quote_Data_Snapshot_Cnsi = 0x0014,
		Quote_Data_Snapshot_Main_Hkex = 0x0015,
		Quote_Data_Trade = 0x0100,
		Quote_Data_Trade_Bond = 0x0101,
		Quote_Data_Order = 0x0200,
		Quote_Data_Order_Bond = 0x0201,
		Quote_Data_Kline = 0x0300,
		Quote_Data_Indic = 0x8000,
		Quote_Data_Indic_MA = 0x8001,
		Quote_Data_Indic_KDJ = 0x8002,
		Quote_Data_String = 0xFFFE,
		Quote_Data_Unknown = 0xFFFF
	};




	struct Snapshot_L2_Bond       //??????????
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t last_trade_type;                 // ??????????????1=???????2 = §¿??????3 = ????????4 = ???????5 = ??????
		std::int64_t close;
		char tpc[8];
		std::int64_t offer_price[10];
		std::int64_t offer_volume[10];
		std::int64_t offer_num_order[10];
		std::int64_t bid_price[10];
		std::int64_t bid_volume[10];
		std::int64_t bid_num_order[10];
		std::int64_t num_trades;
		std::int64_t total_volume_trade;
		std::int64_t total_value_trade;
		std::int64_t total_offer_quant;                 // ????????
		std::int64_t total_bid_quant;                   // ????????
		std::int64_t weighted_avg_offer_price;
		std::int64_t weighted_avg_bid_price;

		std::int64_t updown1;
		std::int64_t updown2;
		std::int64_t weighted_avg_price;                // ???????????????????? & ?????????????????????????
		std::int32_t offer_one_order[50];
		std::int32_t bid_one_order[50];

		std::int64_t weighted_avg_rate;               // ???????????????????????????????????????
		std::int64_t weighted_avg_rate_updown;        // ?????????????????????BP
		std::int64_t preclose_weighted_average_rate;  // ????????????????????
		std::int64_t auction_trade_last;        // ?????????????
		std::int64_t auction_trade_volume;            // ??????????
		std::int64_t auction_trade_value;             // ???????????
		char sub_tpc[5][8];                           // ???????¦Ä???

		//std::int64_t auction_trade_last;              //??????????
		//std::int64_t consult_trade_last;              //§¿?????????
		//std::int64_t click_trade_last;                //???????????
		//std::int64_t inquiry_trade_last;              //??????????
		//std::int64_t bid_trade_last;                  //???????????

		std::int64_t reserved1;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;
	};

	struct Snapshot_L2_Hkex
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t offer_price[10];
		std::int64_t offer_volume[10];
		std::int64_t offer_num_order[10];
		std::int64_t bid_price[10];
		std::int64_t bid_volume[10];
		std::int64_t bid_num_order[10];
		std::int64_t total_volume_trade;
		std::int64_t total_value_trade;
		std::int64_t yield_to_maturity;

		// ??????????
		std::uint8_t suspension_indicator;          // ?????
		std::uint8_t trading_session_status;		// ?§Ô???????
		std::uint8_t trading_session_sub_id;		// ?§Ô?????????
		char trading_session_control_flag;		    // ?§Ô?????????
		std::int64_t nominal_price;					// ??????
		std::int64_t reference_price;				// ???????¦Ï????
		std::int64_t reference_upper_price;			// ?????????????
		std::int64_t reference_lower_price;			// ?????????????
		std::int64_t vcm_start_time;				// ?????????????????
		std::int64_t vcm_end_time;					// ??????????????????
		std::int64_t short_sell_shares_traded;		// ??????
		std::int64_t short_sell_turnover;			// ?????
		std::int64_t order_imbalance_quanty;		// ??§Ó??????
		std::int64_t indicative_equilibrium_price;	// ?????????
		std::int64_t indicative_equilibrium_volume; // ?????????

		std::int64_t vcm_reference_price;           // vcm?¦Ï????
		std::int64_t vcm_upper_price;               // vcm???????
		std::int64_t vcm_lower_price;               // vcm???????
		std::int64_t reserved1;
	};

	struct Snapshot_Main_Hkex
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;
		char tpc[8];		// ?????MktStatus?????MMDH??TradingSessionSubID; ?????TradingPhaseCode
		std::int64_t preclose;  // ???MMDH??PreviousClosingPrice
		std::int64_t high;  // ???MMDH??HighPrice
		std::int64_t low;   // ???MMDH??LowPrice
		std::int64_t last;  // ???MMDH??LastPrice
		std::int64_t close; // ???????MMDH??NominalPrice
		std::int64_t offer_price[5];    // ???MMDH??AskPrice1
		std::int64_t offer_volume[5];   // ???MMDH??AggregateAskQuantity1
		std::int64_t bid_price[5];  // ???MMDH??BidPrice1
		std::int64_t bid_volume[5]; // ???MMDH??AggregateBidQuantity1
		std::int64_t total_volume_trade;    // ???MMDH??SharesTraded
		std::int64_t total_value_trade; // ???MMDH??Turnover
		std::int64_t nominal_price; // ???MMDH??NominalPrice
		std::int64_t reference_price;   // ???MMDH??ReferencePrice/VCMReferencePrice
		std::int64_t pos_upper_price;   // ???MMDH??POSUpperPrice?????????????????xt
		std::int64_t pos_lower_price;   // ???MMDH??POSLowerPrice?????????????????xs
		std::int64_t reference_upper_price;   // ???MMDH??UpperPrice?????????????????xr
		std::int64_t reference_lower_price;		// ???MMDH??LowerPrice?????????????????xu
		std::int64_t vcm_start_time;	// ???MMDH??CoolingOffStartTime			
		std::int64_t vcm_end_time;		// ???MMDH??CoolingOffEndTime	
		std::int64_t vcm_reference_price;   // ???MMDH??VCMReferencePrice,???????????????xi
		std::int64_t vcm_upper_price;   // ???MMDH??VCMUpperPrice?????????????????xe
		std::int64_t vcm_lower_price;		// ???MMDH??VCMLowerPrice?????????????????xf
		std::uint8_t suspension_indicator;          // ???????????SecTradingStatus?????MMDH??SuspensionIndicator
		char order_imbalance_direction; // ???????????OrdImbDirection?????MMDH??OrderImbalanceDirection
		std::int64_t order_imbalance_quanty;    // ???????????OrdImbQty?????MMDH??OrderImbalanceQuantity

		std::int64_t reserved1;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;
	};

	struct Snapshot_L1
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		char symbol[16];
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		char instrument_status[8];
		char tpc[8];
		std::int64_t offer_price[5];
		std::int64_t offer_volume[5];
		std::int64_t bid_price[5];
		std::int64_t bid_volume[5];
		std::int64_t num_trades;
		std::int64_t total_volume_trade;
		std::int64_t total_value_trade;
		std::int64_t high_limited;
		std::int64_t low_limited;
		std::int64_t total_offer_num;
		std::int64_t total_bid_num;
		std::int64_t iopv;
		std::int64_t nav;
		std::int64_t position;
		std::int64_t pratio1;
		std::int64_t pratio2;
		std::int64_t updown1;
		std::int64_t updown2;
		std::int64_t weighted_avg_price;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;

	};

	struct Snapshot_L1_Bond
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t last_trade_type;                 // ??????????????1=???????2 = §¿??????3 = ????????4 = ???????5 = ??????
		std::int64_t close;
		char tpc[8];
		std::int64_t offer_price[5];
		std::int64_t offer_volume[5];
		std::int64_t bid_price[5];
		std::int64_t bid_volume[5];
		std::int64_t num_trades;
		std::int64_t total_volume_trade;
		std::int64_t total_value_trade;
		
		std::int64_t total_offer_quant;                 // ????????
		std::int64_t total_bid_quant;                   // ????????
		std::int64_t weighted_avg_offer_price;
		std::int64_t weighted_avg_bid_price;
		
		std::int64_t updown1;
		std::int64_t updown2;
		std::int64_t weighted_avg_price;
		std::int64_t weighted_avg_rate;               // ???????????????????????????????????????
		std::int64_t weighted_avg_rate_updown;        // ?????????????????????BP
		std::int64_t preclose_weighted_average_rate;  // ????????????????????
		std::int64_t auction_trade_last;        // ?????????????
		std::int64_t auction_trade_volume;            // ??????????
		std::int64_t auction_trade_value;             // ???????????
		char sub_tpc[5][8];                          // ???????¦Ä???

		//std::int64_t auction_trade_last;              //??????????
		//std::int64_t consult_trade_last;              //§¿?????????
		//std::int64_t click_trade_last;                //???????????
		//std::int64_t inquiry_trade_last;              //??????????
		//std::int64_t bid_trade_last;                  //???????????

		std::int64_t reserved1;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;
	};

	struct Snapshot_Index
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t total_num;
		std::int64_t total_volume;
		std::int64_t total_value;
	};

	struct Snapshot_Future
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		char symbol[16];
		char tpc[8];
		std::int32_t action_day;
		char settle_group_id[12];
		std::int32_t settle_id;
		std::int64_t preposition;
		std::int64_t preclose;
		std::int64_t presettle;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t settle;
		std::int64_t total_volume;
		std::int64_t total_value;
		std::int64_t total_position;
		std::int64_t high_limited;
		std::int64_t low_limited;
		std::int64_t predelta;
		std::int64_t current_delta;
		std::int64_t offer_price[5];
		std::int64_t offer_volume[5];
		std::int64_t bid_price[5];
		std::int64_t bid_volume[5];
		std::int64_t auction_price;
		std::int64_t auction_quant;
		std::int64_t avg_price;
		std::int64_t reserved1;      // ????¦Ï??????
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;      
	};

	struct Snapshot_Sgex
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		char symbol[32];
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t last_match_quanty;            /*????????*/
		std::int64_t total_volume;                 /*?????*/
		std::int64_t total_value;                  /*?????*/
		std::int64_t total_weight;                 /*???????*/
		std::int64_t init_open_interest;           /*????????*/
		std::int64_t open_interest;                /*?????*/
		std::int64_t interest_change;              /*???????*/
		std::int64_t settle;                       /*??????*/
		std::int64_t presettle;                    /*??????*/
		std::int64_t life_low;                     /*???????*/
		std::int64_t life_high;                    /*???????*/
		std::int64_t high_limited;                 /*?????*/
		std::int64_t low_limited;                  /*?????*/
		std::int64_t avg_price;                    /*???????*/
		std::int64_t bid_one_price;                /*?????*/
		std::int64_t bid_one_quanty;               /*??????*/
		std::int64_t bid_one_imply_quanty;         /*?????????*/
		std::int64_t ask_one_price;                /*?????*/
		std::int64_t ask_one_quanty;               /*??????*/
		std::int64_t ask_one_imply_quanty;         /*?????????*/
	};

	struct Trade
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t index;
		std::int64_t price;
		std::int64_t volume;
		char bsFlag;
		std::int64_t sellNo;
		std::int64_t buyNo;
		std::int16_t type;                          // ?????????
		std::int32_t channel;
		std::int64_t biz_index;                     // sh biz index
	};

	struct Trade_Bond
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t index;
		std::int64_t price;
		std::int64_t volume;
		char bsFlag;
		std::int64_t sellNo;
		std::int64_t buyNo;
		std::int16_t type;                          // ?????????
		std::int32_t channel;
		std::int64_t biz_index;                     // sh biz index

		std::uint8_t settlperiod;                //????????
		std::uint16_t settltype;                 //?????

		char secondaryorderid[16];               //????¦Á??
		std::uint16_t bidexecinsttype;           //?????????
		std::int64_t marginprice;                //?????
		std::int16_t method_type;                          // ?????? 1=???????2 = §¿??????3 = ????????4 = ???????5 = ??????
	};

	struct Order
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t index;
		std::int64_t price;
		std::int64_t volume;
		char side;
		char type;
		std::int32_t channel;
		std::int64_t origin_no;                    // for sh, ????????
		std::int64_t biz_index;                    // for sh, biz index
	};

	struct Order_Bond
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t index;
		std::int64_t price;
		std::int64_t volume;
		char side;
		char type;
		std::int32_t channel;
		std::int64_t origin_no;                    // for sh, ????????
		std::int64_t biz_index;                    // for sh, biz index

		// §¿????
		char confirmid[8];
		char contactor[12];
		char contactinfo[30];

		std::uint16_t expirationdays;
		std::uint8_t expirationtype;

		// ???????????????????????
		char quoteid[10];               //??????????? ?????????????
		char memberid[6];               //?????????
		char investortype[2];           //????????????
		char investorid[10];            //???????????
		char investorname[120];         //???????
		char tradercode[8];             //?????????
		std::uint8_t settlperiod;       //????????
		std::uint16_t settltype;       //?????
		char memo[160];                 //???

		char secondaryorderid[16];       //????¦Á??
		std::uint16_t bidtranstype;           //??????????
		std::uint16_t bidexecinsttype;        //?????????
		std::int64_t lowlimitprice;           //???????
		std::int64_t highlimitprice;          //???????
		std::int64_t minqty;                  //?????????
		std::uint32_t tradedate;              //????????
		std::int16_t method_type;             // ?????? 1=???????2 = §¿??????3 = ????????4 = ???????5 = ??????
	};

	struct Kline
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t numTrade;
		std::int64_t volume;
		std::int64_t value;
		std::int64_t position;
	};

	struct Snapshot_Nq
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t volume;
		std::int64_t value;
		std::int64_t position;
		std::int64_t high_limited;
		std::int64_t low_limited;
		std::int64_t offer_price[5];
		std::int64_t offer_volume[5];
		std::int64_t bid_price[5];
		std::int64_t bid_volume[5];
		std::int64_t reserved1;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;
	};

	struct Snapshot_Nqzs
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::int8_t eq_tpc;                        // eqapi trading phase code
		std::int64_t offer_tz_price[10];            // tz = ???
		std::int64_t offer_tz_volume[10];
		std::int32_t offer_tz_time[10];
		std::int64_t bid_tz_price[10];
		std::int64_t bid_tz_volume[10];
		std::int32_t bid_tz_time[10];
		std::int64_t offer_zs_price[10];            // zs = ????
		std::int64_t offer_zs_volume[10];
		std::int32_t offer_zs_time[10];
		std::int64_t bid_zs_price[10];
		std::int64_t bid_zs_volume[10];
		std::int32_t bid_zs_time[10];
		std::int64_t reserved1;
		std::int64_t reserved2;
		std::int64_t reserved3;
		std::int64_t reserved4;
	};

	struct Snapshot_Cnsi
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		char symbol[16];
		std::int8_t source;
		std::int64_t preclose;
		std::int64_t open;
		std::int64_t high;
		std::int64_t low;
		std::int64_t last;
		std::int64_t close;
		std::int64_t updown;
		std::int64_t updown_rate;
		std::int64_t volume;
		std::int64_t value;
		double exchange_rate;
		std::int8_t currency;
		std::int64_t close_asia;
		std::int64_t close_europe;
		std::int64_t reserved1;
		std::int64_t reserved2;
	};

	struct Indic_MA
	{
		char security_id[16];
		std::uint16_t market;
		std::int32_t date;
		std::int32_t time;
		std::uint8_t quote_type;
		std::uint8_t sub_type;              // reserved
		std::int64_t ma_1;                  // 1 min
		std::int64_t ma_5;                  // 5 min
		std::int64_t ma_15;                 // 15 min
		std::int64_t ma_30;                 // 30 min
		std::int64_t ma_60;                 // 60 min
	};

#pragma pack()
}


#endif // __quote_data_h__
