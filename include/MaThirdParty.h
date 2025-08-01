#ifndef _MA_THIRD_PARTY_H_
#define _MA_THIRD_PARTY_H_

#if defined(_MSC_VER)
#ifdef _DLL_MA_THIRD_PARTY
#define DLL_MA_THIRD_PARTY __declspec(dllexport)
#else
#define DLL_MA_THIRD_PARTY __declspec(dllimport)
#endif
#else
#define DLL_MA_THIRD_PARTY
#endif

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
// 功能描述：获取第三方字段
// 参数说明：
//      [IN]  p_szThirdParty     第三方字段
//      [IN]  p_iThirdPartySize  第三方字段空间大小：sizeof(p_szThirdParty)>1024
// 返回说明：
//      0：获取成功
//     -1：获取失败
// 调用方法：
//      char szThirdParty[1024+1]={0};
//      GetThirdParty(szThirdParty, sizeof(szThirdParty));
int DLL_MA_THIRD_PARTY GetThirdParty(char *p_szThirdParty, int p_iThirdPartySize);

#ifdef __cplusplus
}
#endif

#endif  // ifndef _MA_THIRD_PARTY_H_ 