#ifndef __QUOTES_DB_TYPE_H__
#define  __QUOTES_DB_TYPE_H__

#include <string>

/*
        basic data for quotes db
*/
namespace qdb
{
    enum class Delimiter
    {
        line = 1,           // for separate lines
        word = 2,           // for separate words, which can include whitespace
        quote = 3           // for separate quotes
    };

    enum class MaxLength
    {
        collection_length = 64,
        key_length = 128,
        quote_length = 1024 * 1024
    };

	enum class TickGap
	{
		level1 = 3,
		level2 = 3,
		option = 3,
		future = 1
	};

    enum class TimeMovingStep : std::int64_t
    {
        quarter_step = 60000000,
    };
        
    namespace dic
    {
        // key
        const char securityid[]                                  = "0";
        const char market[]                                      = "1";
        const char security_type[]                               = "2";
        const char date[]                                        = "3";
        const char time[]                                        = "4";
        const char quote_type[]                                  = "5";
        const char sub_quote_type[]                              = "6";

        // tick中的统一值，为了避免将交易所定义字段强制统一而造成信息丢失，因此另建一个统一值而保留交易所各自定义的字段
        // 统一值丢失了一些信息，但是能够满足绝大部分使用的情况，有特殊需求可以自行解析交易所定义的字段
        // 这些统一的字段以eq开头
        const char eq_trading_phase_code[]                       = "20";
                                                               
        // snapshot, default name                                      
        const char preclose[]                                    = "100";
        const char open[]                                        = "101";
        const char high[]                                        = "102";
        const char low[]                                         = "103";
        const char last[]                                        = "104";
        const char close[]                                       = "105";
        const char instrument_status[]                           = "106";
        const char trading_phase_code[]                          = "107";
        const char offer_prices[]                                = "108";
        const char offer_volumes[]                               = "109";
        const char bid_prices[]                                  = "110";
        const char bid_volumes[]                                 = "111";
        const char num_trades[]                                  = "112";
        const char total_volume_trade[]                          = "113";
        const char total_value_trade[]                           = "114";
        const char total_bid_qty[]                               = "115";
        const char weighted_avg_bid_price[]                      = "116";
        const char alt_weighted_avg_bid_price[]                  = "117";
        const char total_offer_qty[]                             = "118";
        const char weighted_avg_offer_price[]                    = "119";
        const char alt_weighted_avg_offer_price[]                = "120";
        const char num_bid_orders[]                              = "121";
        const char num_offer_orders[]                            = "122";
        const char high_limited_price[]                          = "123";            //涨停价 & 债券价格上限
        const char low_limited_price[]                           = "124";            //跌停 & 债券价格下限
        const char peratio1[]                                    = "125";
        const char peratio2[]                                    = "126";
        const char updown1[]                                     = "127";
        const char updown2[]                                     = "128";
        const char total_position[]                              = "129";
        const char weighted_avg_price[]                          = "130";             //加权平均价格
        const char weighted_avg_rate[]                           = "131";             //加权平均利率

        const char symbol[]                                      = "135";
        const char source_market[]                               = "136";
        const char exchange_rate[]                               = "137";
        const char currency[]                                    = "138";
        const char close_asia[]                                  = "139";
        const char close_europe[]                                = "140";
                                                         
        const char bid_one_orders[]                              = "150";
        const char bid_num_orders[]                              = "151";
        const char offer_one_orders[]                            = "152";
        const char offer_num_orders[]                            = "153";

        const char threshold_amount[]                            = "160";               // 每日交易限额
        const char pos_amount[]                                  = "161";               // 当日交易余额
        const char amount_status[]                               = "162";               // 余额状态
        
        const char buy_turnover[]                                = "174";               // total buy value
        const char sell_turnover[]                               = "175";               // total sell value
        const char buy_sell_turnover[]                           = "176";               // total buy and sell value
        const char vcm_reference_price[]                         = "177";
        const char vcm_lower_price[]                             = "178";
        const char vcm_upper_price[]                             = "179";
        const char reference_price[]                             = "180";               // 联交所字段 & 期权集中竞价交易熔断参考价格
        const char vcm_start_time[]                              = "181";               // 联交所字段
        const char vcm_end_time[]                                = "182";               // 联交所字段
        const char trading_session_status[]                      = "183";               // 联交所字段
        const char trading_session_sub_id[]                      = "184";               // 联交所字段
        const char nominal_price[]                               = "185";               // 联交所字段
        const char reference_lower_price[]                       = "186";               // 联交所字段
        const char reference_upper_price[]                       = "187";               // 联交所字段
        const char short_sell_shares_traded[]                    = "188";               // 联交所字段
        const char short_sell_turnover[]                         = "189";               // 联交所字段
        const char trading_session_control_flag[]                = "190";               // 联交所字段
        const char order_imbalance_quanty[]                      = "191";               // 联交所字段
        const char indicative_equilibrium_price[]                = "192";               // 联交所字段  虚拟匹配价格
        const char indicative_equilibrium_volume[]               = "193";               // 联交所字段  虚拟匹配量
        const char suspension_indicator[]                        = "194";               // 停牌标志
        const char trading_session_id[]                          = "195";               // 深交所港股状态字段
        const char stock_connection_market[]                     = "196";               // 联交所，沪深市场
        const char trading_direction[]                           = "197";               // 联交所，北上、南下方向
        
        const char preclose_iopv[]                               = "200";
        const char iopv[]                                        = "201";
        const char etf_buy_num[]                                 = "202";
        const char etf_buy_amount[]                              = "203";
        const char etf_buy_money[]                               = "204";
        const char etf_sell_num[]                                = "205";
        const char etf_sell_amount[]                             = "206";
        const char etf_sell_money[]                              = "207";
        const char yield_to_maturity[]                           = "208";
        const char total_warrant_exec_qty[]                      = "209";
        const char warrant_lower_price[]                         = "210";
        const char warrant_upper_price[]                         = "211";
        const char withdraw_buy_num[]                            = "212";
        const char withdraw_buy_amount[]                         = "213";
        const char withdraw_buy_money[]                          = "214";
        const char withdraw_sell_num[]                           = "215";
        const char withdraw_sell_amount[]                        = "216";
        const char withdraw_sell_money[]                         = "217";
        const char total_bid_num[]                               = "218";
        const char total_offer_num[]                             = "219";
        const char bid_trade_max_duration[]                      = "220";
        const char offer_trade_max_duration[]                    = "221";
              
        const char net_value_t_x[]                               = "230";
        const char warrant_premium_rate[]                        = "231";
        
        const char auction_price[]                               = "250";
        const char auction_qty[]                                 = "251";
        const char settle_price[]                                = "252";
        const char settle_group_id[]                             = "253";
        const char settle_id[]                                   = "254";
                                                        
        const char preopen_interest[]                            = "300";
        const char presettle_price[]                             = "301";
        const char predelta[]                                    = "302";
        const char currdelta[]                                   = "303";  
        const char average_trade_price[]                         = "304";
        const char action_day[]                                  = "305";

        const char match_weight[]                                = "350";
        const char total_match_weight[]                          = "351";
        const char up_down_price[]                               = "352";
        const char up_down_rate[]                                = "353";
        const char last_match_volume[]                           = "354";
        const char init_open_interest[]                          = "355";
        const char interest_change[]                             = "356";
        const char life_lowest[]                                 = "357";
        const char life_hightest[]                               = "358";
        const char bid_imply_qty[]                               = "359";
        const char ask_imply_qty[]                               = "360";

        const char preclose_yield_or_rate[]                      = "361";
        const char preclose_weighted_average_yield_or_rate[]     = "362";
        const char open_yield_or_rate[]                          = "363";
        const char high_yield_or_rate[]                          = "364";
        const char low_yield_or_rate[]                           = "365";
        const char last_yield_or_rate[]                          = "366";
        const char weighted_average_yield_or_rate[]              = "367";
        const char preclose_weighted_averaged_price[]            = "368";       //深交所债券昨收盘成交量加权平均利率
                                                               
        //  neeq
        const char offer_tz_prices[]                             = "401";
        const char offer_tz_volumes[]                            = "402";
        const char offer_tz_times[]                              = "403";
        const char bid_tz_prices[]                               = "404";
        const char bid_tz_volumes[]                              = "405";
        const char bid_tz_times[]                                = "406";
        const char offer_zs_prices[]                             = "407";
        const char offer_zs_volumes[]                            = "408";
        const char offer_zs_times[]                              = "409";
        const char bid_zs_prices[]                               = "410";
        const char bid_zs_volumes[]                              = "411";
        const char bid_zs_times[]                                = "412";

        // bond
		const char last_trade_type[]                             = "500";   //债券最新价成交方式，1=匹配成交，2 = 协商成交，3 = 点击成交，4 = 询价成交，5 = 竞买成交
        const char weighted_avg_rate_updown[]                    = "501";   //质押式回购的加权平均利率涨跌BP
        //const char preclose_weighted_average_rate[]              = "502";   //昨收盘成交量加权平均利率
        const char auction_trade_last[]                          = "503";   //匹配成交最新成交价
        const char auction_trade_volume[]                        = "504";   //匹配成交成交量
        const char auction_trade_value[]                         = "505";   //匹配成交成交金额
        const char sub_tpc[]                                     = "506";   //细分交易阶段代码
        const char sub_trade_type[]                              = "507";   //细分交易方式

		const char quote_id[]                                    = "508";   //报价消息编号
		const char member_id[]                                   = "509";   //交易商代码
		const char investor_type[]                               = "510";   //交易主体类型
		const char investor_id[]                                 = "511";   //交易主体代码
		const char investor_name[]                               = "512";   //客户名称
		const char trader_code[]                                 = "513";   //交易员代码
		const char settl_period[]                                = "514";   //结算周期
		const char settl_type[]                                  = "515";   //结算方式
		const char memo[]                                        = "516";   //备注

		const char secondary_order_id[]                          = "517";    //竞买场次编号
		const char bid_trans_type[]                              = "518";    //竞买业务类别
		const char bid_exec_inst_type[]                          = "519";    //竞买成交方式
		const char min_qty[]                                     = "520";    //最低成交数量
		const char trade_date[]                                  = "521";    //交易日期
		const char margin_price[]                                = "522";    //达成成交的边际价格

        //const char auction_trade_last[]                          = "523";    //匹配成交最新价
        //const char consult_trade_last[]                          = "524";    //协商成交最新价
        //const char click_trade_last[]                            = "525";    //点击成交最新价
        //const char inquiry_trade_last[]                          = "526";    //询价成交最新价
        //const char bid_trade_last[]                              = "527";    //竞买成交最新价
        const char method_type[]                                 = "528";    //交易方式，1=匹配成交，2 = 协商成交，3 = 点击成交，4 = 询价成交，5 = 竞买成交 

        // trade                                             
        const char trade_index[]                                 = "600";
        const char trade_price[]                                 = "601";
        const char trade_volume[]                                = "602";
        const char trade_money[]                                 = "603";
        const char trade_bs_flag[]                               = "604";
        const char trade_sell_no[]                               = "605";
        const char trade_buy_no[]                                = "606";
        const char trade_hk_type[]                               = "607";
        // bond trade 
        const char trade_fullprice[]                             = "608";
        const char trade_interest[]                              = "609";
        // sh biz index
        const char biz_index[]                                   = "620";
        // channel
        const char trade_order_channel[]                         = "621";
        // order                                             
        const char order_index[]                                 = "700";
        const char order_price[]                                 = "701";
        const char order_volume[]                                = "702";
        const char order_side[]                                  = "703";
        const char order_type[]                                  = "704";
        const char order_confirm_id[]                            = "705";
        const char order_contator[]                              = "706";
        const char order_contact_info[]                          = "707";
        const char order_expiration_days[]                       = "708";
        const char order_expiration_type[]                       = "709";
        const char order_origin_no[]                             = "710";

        // static
        const char static_security_type[]                        = "800";
        const char static_security_zh_name[]                     = "801";
        const char static_security_en_name[]                     = "802";
        const char static_etf_file[]                             = "803";
        const char static_lot_size[]                             = "804";       // 联交所量交易单位
        const char static_security_layer[]                       = "805";       // 股转公司分层类型 1 = 基础层; 2 = 创新层; 3 = 精选层;
        const char static_trade_id[]                             = "850";
        const char static_underline_id[]                         = "851";
        const char static_spread_code[]                          = "852";       // 联交所价格交易区间
        const char static_market_code[]                          = "853";       // 联交所市场
        const char static_POS_flag[]                             = "854";       // 联交所是否参与盘前交易标志Y/N
        const char static_POS_upper_limit[]                      = "855";       // 联交所盘前交易价格上限
        const char static_POS_lower_limit[]                      = "856";       // 联交所盘前交易价格下限

        //indicator
        const char indicator_args[]                              = "900";
        const char indicator_result[]                            = "901";
        const char indicator_day_factor[]                        = "902";

		//otc
		const char investor_offer_price[] = "1000";
		const char investor_offer_volume[] = "1001";
		const char investor_best_offer_price[] = "1002";
		const char investor_offer_volume_at_best_price[] = "1003";
		const char investor_bid_price[] = "1004";
		const char investor_bid_volume[] = "1005";
		const char investor_best_bid_price[] = "1006";
		const char investor_bid_volume_at_best_price[] = "1007";
    };

    namespace mkt
    {
        const char none[] = { "none" };
        // 上交所
        const char sh[]   = { "sh" };
        const char shl1[] = { "shl1" };
        const char shl2[] = { "shl2" };
        const char shop[] = { "shop" };
        const char shzq[] = { "shzq" };
        const char shhk[] = { "shhk" };
        const char shkl[] = { "shkl" };
        const char shin[] = { "shin" };
		const char shotc[] = { "shotc" };
        const char shbd[] = { "shbd" };
        // 深交所
        const char sz[]   = { "sz" };
        const char szl1[] = { "szl1" };
        const char szl2[] = { "szl2" };
        const char szop[] = { "szop" };
        const char szkl[] = { "szkl" };
        const char szhk[] = { "szhk" };
        const char szin[] = { "szin" };
		const char szotc[] = { "szotc" };
        const char szbd1[] = { "szbd1" };
        const char szbd2[] = { "szbd2" };
        // 中国金融期货交易所
        const char ccfx[] = { "CCFX" };
        const char cfl1[] = { "cfl1" };
        const char cfl2[] = { "cfl2" };
        const char cfop[] = { "cfop" };
        const char cfop2[] = { "cfop2" };
        const char cfkl[] = { "cfkl" };
        const char cfl1n[] = { "cfl1n" };
        const char cfl2n[] = { "cfl2n" };
        const char cfkln[] = { "cfkln" };
        const char cfopn[] = { "cfopn" };
        const char cfop2n[] = { "cfop2n" };
        const char cfin[] = { "cfin" };
        // 大连商品交易所
        const char xdce[] = { "XDCE" };
        const char dcl1[] = { "dcl1" };
        const char dcl2[] = { "dcl2" };
        const char dcop[] = { "dcop" };
        const char dcop2[] = { "dcop2" };
        const char dckl[] = { "dckl" };
        const char dcl1n[] = { "dcl1n" };
        const char dcl2n[] = { "dcl2n" };
        const char dckln[] = { "dckln" };
        const char dcopn[] = { "dcopn" };
        const char dcop2n[] = { "dcop2n" };
        const char dcin[] = { "dcin" };
        // 郑州商品交易所
        const char xzce[] = { "XZCE" };
        const char zcl1[] = { "zcl1" };
        const char zcl2[] = { "zcl2" };
        const char zcop[] = { "zcop" };
        const char zcop2[] = { "zcop2" };
        const char zckl[] = { "zckl" };
        const char zcl1n[] = { "zcl1n" };
        const char zcl2n[] = { "zcl2n" };
        const char zckln[] = { "zckln" };
        const char zcopn[] = { "zcopn" };
        const char zcop2n[] = { "zcop2n" };
        const char zcin[] = { "zcin" };
        // 上海期货交易所
        const char xsge[] = { "XSGE" };
        const char sfl1[] = { "sfl1" };
        const char sfl2[] = { "sfl2" };
        const char sfop[] = { "sfop" };
        const char sfop2[] = { "sfop2" };
        const char sfkl[] = { "sfkl" };
        const char sfl1n[] = { "sfl1n" };
        const char sfl2n[] = { "sfl2n" };
        const char sfkln[] = { "sfkln" };
        const char sfopn[] = { "sfopn" };
        const char sfop2n[] = { "sfop2n" };
        const char sfin[] = { "sfin" };
        // 上海黄金交易所
        const char sgex[] = { "SGEX" };
        const char sgl1[] = { "sgl1" };
        const char sgl2[] = { "sgl2" };
        const char sgop[] = { "sgop" };
        const char sgop2[] = { "sgop2" };
        const char sgopn[] = { "sgopn" };
        const char sgop2n[] = { "sgop2n" };
        const char sgkl[] = { "sgkl" };
        const char sgl1n[] = { "sgl1n" };
        const char sgl2n[] = { "sgl2n" };
        const char sgkln[] = { "sgkln" };
        const char sgin[] = { "sgin" };
        // 上海国际能源交易中心
        const char xine[] = { "XINE" };
        const char inl1[] = { "inl1" };
        const char inl2[] = { "inl2" };
        const char inop[] = { "inop" };
        const char inop2[] = { "inop2" };
        const char inkl[] = { "inkl" };
        const char inl1n[] = { "inl1n" };
        const char inl2n[] = { "inl2n" };
        const char inkln[] = { "inkln" };
        const char inopn[] = { "inopn" };
        const char inop2n[] = { "inop2n" };
        const char inin[] = { "inin" };
        // 中国外汇交易中心
        const char xcfe[] = { "XCFE" };
        const char cel1[] = { "cel1" };
        const char cel2[] = { "cel2" };
        const char cekl[] = { "cekl" };
        const char cein[] = { "cein" };
        // 全国中小企业股份转让系统
        const char neeq[] = { "NEEQ" };
        const char nql1[] = { "nql1" };
        const char nql2[] = { "nql2" };
        const char nqkl[] = { "nqkl" };
        const char nqzs[] = { "nqzs" };
        const char nqin[] = { "nqin" };
        
        // 香港证券交易所
        const char xhkg[] = { "XHKG" };
        const char hkl1[] = { "hkl1" };
        const char hkl2[] = { "hkl2" };
        const char hkkl[] = { "hkkl" };
        const char hkin[] = { "hkin" };
        const char hkbh[] = { "hkbh" };
        // 中证指数
        const char cnsi[] = { "cnsi" };
        const char cnsikl[] = { "cnsikl" };

		// 北交所
		const char bjl1[] = { "bjl1" };
		const char bjkl[] = { "bjkl" };

        // 外部数据
        // 森浦
        const char senpu[] = { "senpu" };
        const char senpu_bond[] = { "senpubd" };

        // static db name, 实时没有这个数据，只有db name， 用户是不知道该名字;
        // 暂时无用
        const char static_db[] = { "static" };
    };

    enum class Market : uint16_t
    {
        none                        = 0x0000,
        // 上交所
        sh                          = 0x0100,
        shl1                        = 0x0102,
        shl2                        = 0x0103,
        shop                        = 0x0104,
        shhk                        = 0x0105,
        shzq                        = 0x0106,
        shbd                        = 0x0107,
        shkl                        = 0x0111,
        shin                        = 0x0112,
		shotc						= 0x0120,
        // 深交所
        sz                          = 0x0200,
        szl1                        = 0x0201,
        szl2                        = 0x0202,
        szop                        = 0x0203,
        szbd1                       = 0x0204,
        szbd2                       = 0x0205,
        szkl                        = 0x0211,
        szin                        = 0x0212,
        szhk                        = 0x0221,
		szotc						= 0x0230,
        // 中国金融期货交易所
        ccfx                        = 0x0300,
        cfl1                        = 0x0301,
        cfl2                        = 0x0302,
        cfkl                        = 0x0303,
        cfl1n                       = 0x0304,
        cfl2n                       = 0x0305,
        cfkln                       = 0x0306,
        cfin                        = 0x0307,
        cfop                        = 0x0311,
        cfop2                       = 0x0312,
        cfopn                       = 0x0313,
        cfop2n                      = 0x0314,
        // 大连商品交易所
        xdce                        = 0x0400,
        dcl1                        = 0x0401,
        dcl2                        = 0x0402,
        dckl                        = 0x0403,
        dcl1n                       = 0x0404,
        dcl2n                       = 0x0405,
        dckln                       = 0x0406,
        dcin                        = 0x0407,
        dcop                        = 0x0411,
        dcop2                       = 0x0412,
        dcopn                       = 0x0413,
        dcop2n                      = 0x0414,
        // 郑州商品交易所
        xzce                        = 0x0500,
        zcl1                        = 0x0501,
        zcl2                        = 0x0502,
        zckl                        = 0x0503,
        zcl1n                       = 0x0504,
        zcl2n                       = 0x0505,
        zckln                       = 0x0506,
        zcin                        = 0x0507,
        zcop                        = 0x0511,
        zcop2                       = 0x0512,
        zcopn                       = 0x0513,
        zcop2n                      = 0x0514,
        // 上海期货交易所
        xsge                        = 0x0600,
        sfl1                        = 0x0601,
        sfl2                        = 0x0602,
        sfkl                        = 0x0603,
        sfl1n                       = 0x0604,
        sfl2n                       = 0x0605,
        sfkln                       = 0x0606,
        sfin                        = 0x0607,
        sfop                        = 0x0611,
        sfop2                       = 0x0612,
        sfopn                       = 0x0613,
        sfop2n                      = 0x0614,

        // 上海黄金交易所
        sgex                        = 0x0700,
        sgl1                        = 0x0701,
        sgl2                        = 0x0702,
        sgkl                        = 0x0703,
        sgl1n                       = 0x0704,
        sgl2n                       = 0x0705,
        sgkln                       = 0x0706,
        sgin                        = 0x0707,
        sgop                        = 0x0711,
        sgop2                       = 0x0712,
        sgopn                       = 0x0713,
        sgop2n                      = 0x0714,
        // 上海国际能源交易中心
        xine                        = 0x0800,
        inl1                        = 0x0801,
        inl2                        = 0x0802,
        inkl                        = 0x0803,
        inl1n                       = 0x0804,
        inl2n                       = 0x0805,
        inkln                       = 0x0806,
        inin                        = 0x0807,
        inop                        = 0x0811,
        inop2                       = 0x0812,
        inopn                       = 0x0813,
        inop2n                      = 0x0814,
        // 中国外汇交易中心
        xcfe                        = 0x0900,
        cel1                        = 0x0901,
        cel2                        = 0x0902,
        cekl                        = 0x0903,
        cein                        = 0x0904,
        // 全国中小企业股份转让系统
        neeq                        = 0x0a00,
        nql1                        = 0x0a01,
        nql2                        = 0x0a02,
        nqkl                        = 0x0a03,
        nqzs                        = 0x0a04,
        nqin                        = 0x0a05,
        // 香港证券交易所                 
        xhkg                        = 0x0b00,
        hkl1                        = 0x0b01,
        hkl2                        = 0x0b02,
        hkkl                        = 0x0b03,
        hkin                        = 0x0b04,
        hkbh                        = 0x0b05,
        // 中证指数
        cnsi                        = 0x0c01,
        cnsikl                      = 0x0c02,
			
		// 北交所
		bjl1						= 0x0d01,
		bjzs						= 0x0d02,
		bjkl						= 0x0d03,

        // 外部数据
        // 森浦
        senpu                       = 0xa110,
        senpu_bond                  = 0xa111,
    };

    // 证券类别定义
    enum class SecurityType : uint16_t
    {
        index                               = 0x0000,          // 指数
        index_house                         = 0x0001,          // 交易所指数
        index_asia                          = 0x0002,          // 亚洲指数
        index_oversea                       = 0x0003,          // 国际指数
        index_future                        = 0x0004,          // 期货指数
        index_spot                          = 0x0005,          // 现货指数
        index_china                         = 0x0006,          // 国证指数
        shares                              = 0x0100,          // 股票
        shares_A                            = 0x0101,          // A股
        shares_zxb                          = 0x0102,          // 中小板
        shares_cyb                          = 0x0103,          // 创业板
        shares_xsb                          = 0x0104,          // 新三板
        shares_B                            = 0x0105,          // B股
        shares_H                            = 0x0106,          // H股
        shares_K                            = 0x0107,          // 科创版
        shares_preference                   = 0x0111,          // 优先股
        shares_rights                       = 0x0112,          // 
        shares_depository_receipt_ordinary  = 0x0113,          // Depository Receipt - Ordinary shares
        shares_depository_receipt_preference= 0x0114,          // Depository Receipt - Preference shares
        fund                                = 0x0200,          // 基金
        fund_etf                            = 0x0201,          // 交易所开放式基金
        fund_reits                          = 0x0202,          // 公募REITS
        trust                               = 0x0250,
        trust_real_estate_investment        = 0x0251,          // Real Estate Investment Trust
        trust_other_unit                    = 0x0252,          // Other Unit Trusts
        trust_leveraged_and_inverse_product = 0x0253,          // Leveraged and Inverse Product
        bond                                = 0x0300,          // 债券
        bond_government                     = 0x0301,          // 国债
        bond_company                        = 0x0302,          // 企债
        bond_financial                      = 0x0303,          // 金融债
        bond_convert                        = 0x0304,          // 可转换债
        bond_exchange                       = 0x0305,          // 可交换债
        repo                                = 0x0400,          // 回购
        repo_government                     = 0x0401,          // 国债回购
        repo_company                        = 0x0402,          // 企债回购
        warrant                             = 0x0500,          // 权证
        warrant_call                        = 0x0501,          // 认购权证
        warrant_put                         = 0x0502,          // 认沽权证
        warrant_derivative                  = 0x0511,          // Derivative Warrant
        warrant_callable_bull_bear_contract = 0x0512,          // Callable Bull/Bear Contract
        warrant_equity                      = 0x0513,          // Equity Warrant
        warrant_equity_linked_instrument    = 0x0514,          // Equity Linked Instrument Warrant
        warrant_inline                      = 0x0515,          // Inline Warrant
        warrant_basket                      = 0x0516,
        equity                              = 0x0550,
        future                              = 0x0600,          // 期货
        future_index                        = 0x0601,          // 指数期货
        future_commodity                    = 0x0602,          // 商品期货
        future_shares                       = 0x0603,          // 金融期货
        foreign_currency                    = 0x0700,          // 外汇
        foreign_currency_base               = 0x0701,          // 基本外汇
        foreign_currency_cross              = 0x0702,          // 交叉外汇
        foreign_currency_reverse            = 0x0703,          // 反向外汇
        option                              = 0x0800,          // 期权
        option_call                         = 0x0810,          // 认购期权
        option_put                          = 0x0820,          // 认沽期权
        option_index_call                   = 0x0811,          // 指数认购期权
        option_index_put                    = 0x0821,          // 指数认沽期权
        option_commodity_call               = 0x0812,          // 商品认沽期权
        option_commodity_put                = 0x0822,          // 商品认购期权
        bankrate                            = 0x0900,          // 利率
        nobal_metal                         = 0x0a00,          // 贵金属
        other                               = 0xffff           // 其它
    };

    namespace quote_type
    {
        const char none[] = "none";
        const char tick[] = "tick";
        const char index[] = "index";
        const char trade[] = "trade";
        const char order[] = "order";
        const char queue[] = "queue";
        const char kl1m[] = "kl1m";
        const char kl15m[] = "kl15m";
        const char kl30m[] = "kl30m";
        const char kl1h[] = "kl1h";
        const char kl1D[] = "kl1D";
        const char kl1W[] = "kl1W";
        const char kl1M[] = "kl1M";
        const char kl1Y[] = "kl1Y";
        const char kl5m[] = "kl5m";
        const char kl10m[] = "kl10m";
        const char code[] = "code";
        const char etff[] = "etff";
        const char indic[] = "indic";
    }

    enum class QuoteType : uint8_t
    {
        none                    = 0x00,
        tick                    = 0x01,
        index                   = 0x02,
        trade                   = 0x03,
        order                   = 0x04,
        queue                   = 0x05,
        kl1m                    = 0x06,
        kl15m                   = 0x07,
        kl30m                   = 0x08,
        kl1h                    = 0x09,
        kl1D                    = 0x0a,
        kl1W                    = 0x0b,
        kl1M                    = 0x0c,
        kl1Y                    = 0x0d,
        kl5m                    = 0x0e,
        kl10m                   = 0x10,
        code                    = 0x80,
        etff                    = 0x81,
        indic                   = 0x82
    };

    namespace tpc
    {
        const char start                        = 'S';  // 开始前
        const char call_auction                 = 'C';  // 集中竞价
        const char break_trade                  = 'B';  // 休市
        const char conintus_auction             = 'T';  // 连续竞价
        const char suspend                      = 'P';  // 停牌
        const char vola                         = 'V';  // 波动性中断
        const char pre_out_trade                = 'A';  // 非盘中交易，盘前或者盘后交易
        const char end_trade                    = 'E';  // 闭市
        const char no_or_unknown                = 'X';  // 没有tpc标志或未知标志，例如上海的指数
    }

    namespace quote_status
    {
        const char unknown[]                    = "unknown";
        const char create[]                     = "create";
        const char update[]                     = "update";
        const char deleted[]                    = "deleted";
    }

    // mongo db json key
    namespace json_key
    {
        const char id[]                         = "_id";
        const char market[]                     = "market";
        const char securityID[]                 = "securityID";
        const char securityType[]               = "securityType";
        const char quoteType[]                  = "quoteType";
        const char datetime[]                   = "datetime";
        const char tpc[]                        = "tpc";
        const char status[]                     = "status";
        const char tag[]                        = "tag";
        const char quote[]                      = "quote";
        const char operate[]                    = "operate";
    };

    // quote line
    struct QuoteLine
    {
        std::string market_;                // db name
        std::string securityID_;
        std::string quoteType_;
        int64_t datetime_;
        char eqTradingPhaseCode_;                
        std::string quote_;
    };


    inline const char* quoteTypeString(QuoteType type)
    {
        const char* str;
        switch (type)
        {
        case qdb::QuoteType::index: str = qdb::quote_type::index;   break;
        case qdb::QuoteType::tick:  str = qdb::quote_type::tick;    break;
        case qdb::QuoteType::trade: str = qdb::quote_type::trade;   break;
        case qdb::QuoteType::order: str = qdb::quote_type::order;   break;
        case qdb::QuoteType::queue: str = qdb::quote_type::queue;   break;
        case qdb::QuoteType::kl1m:  str = qdb::quote_type::kl1m;    break;
        case qdb::QuoteType::kl15m: str = qdb::quote_type::kl15m;   break;
        case qdb::QuoteType::kl30m: str = qdb::quote_type::kl30m;   break;
        case qdb::QuoteType::kl1h:  str = qdb::quote_type::kl1h;    break;
        case qdb::QuoteType::kl1D:  str = qdb::quote_type::kl1D;    break;
        case qdb::QuoteType::kl1W:  str = qdb::quote_type::kl1W;    break;
        case qdb::QuoteType::kl1M:  str = qdb::quote_type::kl1M;    break;
        case qdb::QuoteType::kl1Y:  str = qdb::quote_type::kl1Y;    break;
        case qdb::QuoteType::kl5m:  str = qdb::quote_type::kl5m;    break;
        case qdb::QuoteType::kl10m:  str = qdb::quote_type::kl10m;    break;
        case qdb::QuoteType::code:  str = qdb::quote_type::code;    break;
        case qdb::QuoteType::etff:  str = qdb::quote_type::etff;    break;
        case qdb::QuoteType::indic:  str = qdb::quote_type::indic;    break;
        default:
            str = qdb::quote_type::none;
            break;
        }

        return str;
    }

    inline const char* marketString(qdb::Market market)
    {
        const char* str;
        switch (market)
        {
        case qdb::Market::sh:   str = qdb::mkt::sh;     break;
        case qdb::Market::shl1: str = qdb::mkt::shl1;   break;
        case qdb::Market::shl2: str = qdb::mkt::shl2;   break;
        case qdb::Market::shop: str = qdb::mkt::shop;   break;
        case qdb::Market::shzq: str = qdb::mkt::shzq;   break;
        case qdb::Market::shhk: str = qdb::mkt::shhk;   break;
        case qdb::Market::shbd: str = qdb::mkt::shbd;   break;
        case qdb::Market::shkl: str = qdb::mkt::shkl;   break;
        case qdb::Market::shin: str = qdb::mkt::shin;   break;
		case qdb::Market::shotc: str = qdb::mkt::shotc;   break;
        case qdb::Market::sz:   str = qdb::mkt::sz;     break;
        case qdb::Market::szl1: str = qdb::mkt::szl1;   break;
        case qdb::Market::szl2: str = qdb::mkt::szl2;   break;
        case qdb::Market::szop: str = qdb::mkt::szop;   break;
        case qdb::Market::szbd1: str = qdb::mkt::szbd1;   break;
        case qdb::Market::szbd2: str = qdb::mkt::szbd2;   break;
        case qdb::Market::szkl: str = qdb::mkt::szkl;   break;
        case qdb::Market::szhk: str = qdb::mkt::szhk;   break;
        case qdb::Market::szin: str = qdb::mkt::szin;   break;
		case qdb::Market::szotc: str = qdb::mkt::szotc;   break;
        case qdb::Market::ccfx: str = qdb::mkt::ccfx;   break;
        case qdb::Market::cfl1: str = qdb::mkt::cfl1;   break;
        case qdb::Market::cfl2: str = qdb::mkt::cfl2;   break;
        case qdb::Market::cfop: str = qdb::mkt::cfop;   break;
        case qdb::Market::cfop2: str = qdb::mkt::cfop2;   break;
        case qdb::Market::cfopn: str = qdb::mkt::cfopn;   break;
        case qdb::Market::cfop2n: str = qdb::mkt::cfop2n;   break;
        case qdb::Market::cfkl: str = qdb::mkt::cfkl;   break;
        case qdb::Market::cfl1n: str = qdb::mkt::cfl1n;   break;
        case qdb::Market::cfl2n: str = qdb::mkt::cfl2n;   break;
        case qdb::Market::cfkln: str = qdb::mkt::cfkln;   break;
        case qdb::Market::cfin: str = qdb::mkt::cfin;   break;
        case qdb::Market::xdce: str = qdb::mkt::xdce;   break;
        case qdb::Market::dcl1: str = qdb::mkt::dcl1;   break;
        case qdb::Market::dcl2: str = qdb::mkt::dcl2;   break;
        case qdb::Market::dcop: str = qdb::mkt::dcop;   break;
        case qdb::Market::dcop2: str = qdb::mkt::dcop2;   break;
        case qdb::Market::dcopn: str = qdb::mkt::dcopn;   break;
        case qdb::Market::dcop2n: str = qdb::mkt::dcop2n;   break;
        case qdb::Market::dckl: str = qdb::mkt::dckl;   break;
        case qdb::Market::dcl1n: str = qdb::mkt::dcl1n;   break;
        case qdb::Market::dcl2n: str = qdb::mkt::dcl2n;   break;
        case qdb::Market::dckln: str = qdb::mkt::dckln;   break;
        case qdb::Market::dcin: str = qdb::mkt::dcin;   break;
        case qdb::Market::xzce: str = qdb::mkt::xzce;   break;
        case qdb::Market::zcl1: str = qdb::mkt::zcl1;   break;
        case qdb::Market::zcl2: str = qdb::mkt::zcl2;   break;
        case qdb::Market::zcop: str = qdb::mkt::zcop;   break;
        case qdb::Market::zcop2: str = qdb::mkt::zcop2;   break;
        case qdb::Market::zcopn: str = qdb::mkt::zcopn;   break;
        case qdb::Market::zcop2n: str = qdb::mkt::zcop2n;   break;
        case qdb::Market::zckl: str = qdb::mkt::zckl;   break;
        case qdb::Market::zcl1n: str = qdb::mkt::zcl1n;   break;
        case qdb::Market::zcl2n: str = qdb::mkt::zcl2n;   break;
        case qdb::Market::zckln: str = qdb::mkt::zckln;   break;
        case qdb::Market::zcin: str = qdb::mkt::zcin;   break;
        case qdb::Market::xsge: str = qdb::mkt::xsge;   break;
        case qdb::Market::sfl1: str = qdb::mkt::sfl1;   break;
        case qdb::Market::sfl2: str = qdb::mkt::sfl2;   break;
        case qdb::Market::sfop: str = qdb::mkt::sfop;   break;
        case qdb::Market::sfop2: str = qdb::mkt::sfop2;   break;
        case qdb::Market::sfopn: str = qdb::mkt::sfopn;   break;
        case qdb::Market::sfop2n: str = qdb::mkt::sfop2n;   break;
        case qdb::Market::sfkl: str = qdb::mkt::sfkl;   break;
        case qdb::Market::sfl1n: str = qdb::mkt::sfl1n;   break;
        case qdb::Market::sfl2n: str = qdb::mkt::sfl2n;   break;
        case qdb::Market::sfkln: str = qdb::mkt::sfkln;   break;
        case qdb::Market::sfin: str = qdb::mkt::sfin;   break;
        case qdb::Market::sgex: str = qdb::mkt::sgex;   break;
        case qdb::Market::sgl1: str = qdb::mkt::sgl1;   break;
        case qdb::Market::sgl2: str = qdb::mkt::sgl2;   break;
        case qdb::Market::sgop: str = qdb::mkt::sgop;   break;
        case qdb::Market::sgop2: str = qdb::mkt::sgop2;   break;
        case qdb::Market::sgopn: str = qdb::mkt::sgopn;   break;
        case qdb::Market::sgop2n: str = qdb::mkt::sgop2n;   break;
        case qdb::Market::sgkl: str = qdb::mkt::sgkl;   break;
        case qdb::Market::sgl1n: str = qdb::mkt::sgl1n;   break;
        case qdb::Market::sgl2n: str = qdb::mkt::sgl2n;   break;
        case qdb::Market::sgkln: str = qdb::mkt::sgkln;   break;
        case qdb::Market::sgin: str = qdb::mkt::sgin;   break;
        case qdb::Market::xine: str = qdb::mkt::xine;   break;
        case qdb::Market::inl1: str = qdb::mkt::inl1;   break;
        case qdb::Market::inl2: str = qdb::mkt::inl2;   break;
        case qdb::Market::inop: str = qdb::mkt::inop;   break;
        case qdb::Market::inop2: str = qdb::mkt::inop2;   break;
        case qdb::Market::inopn: str = qdb::mkt::inopn;   break;
        case qdb::Market::inop2n: str = qdb::mkt::inop2n;   break;
        case qdb::Market::inkl: str = qdb::mkt::inkl;   break;
        case qdb::Market::inin: str = qdb::mkt::inin;   break;
        case qdb::Market::inl1n: str = qdb::mkt::inl1n;   break;
        case qdb::Market::inl2n: str = qdb::mkt::inl2n;   break;
        case qdb::Market::inkln: str = qdb::mkt::inkln;   break;
        case qdb::Market::xcfe: str = qdb::mkt::xcfe;   break;
        case qdb::Market::cel1: str = qdb::mkt::cel1;   break;
        case qdb::Market::cel2: str = qdb::mkt::cel2;   break;
        case qdb::Market::cekl: str = qdb::mkt::cekl;   break;
        case qdb::Market::cein: str = qdb::mkt::cein;   break;
        case qdb::Market::neeq: str = qdb::mkt::neeq;   break;
        case qdb::Market::nql1: str = qdb::mkt::nql1;   break;
        case qdb::Market::nql2: str = qdb::mkt::nql2;   break;
        case qdb::Market::nqkl: str = qdb::mkt::nqkl;   break;
        case qdb::Market::nqin: str = qdb::mkt::nqin;   break;
		case qdb::Market::nqzs: str = qdb::mkt::nqzs;   break;
        case qdb::Market::xhkg: str = qdb::mkt::xhkg;   break;
        case qdb::Market::hkl1: str = qdb::mkt::hkl1;   break;
        case qdb::Market::hkl2: str = qdb::mkt::hkl2;   break;
        case qdb::Market::hkkl: str = qdb::mkt::hkkl;   break;
        case qdb::Market::hkin: str = qdb::mkt::hkin;   break;
        case qdb::Market::hkbh: str = qdb::mkt::hkbh;   break;
        case qdb::Market::cnsi: str = qdb::mkt::cnsi;   break;
        case qdb::Market::cnsikl: str = qdb::mkt::cnsikl; break;
        case qdb::Market::senpu: str = qdb::mkt::senpu; break;
		case qdb::Market::senpu_bond: str = qdb::mkt::senpu_bond; break;
		case qdb::Market::bjl1: str = qdb::mkt::bjl1; break; // 北交所
		case qdb::Market::bjkl: str = qdb::mkt::bjkl; break;
        default:
            str = qdb::mkt::none;
            break;
        }

        return str;
    }
}

#endif // __QUOTES_DB_TYPE_H__
