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
// ������������ȡ�������ֶ�
// ����˵����
//      [IN]  p_szThirdParty     �������ֶ�
//      [IN]  p_iThirdPartySize  �������ֶοռ��С��sizeof(p_szThirdParty)>1024
// ����˵����
//      0����ȡ�ɹ�
//     -1����ȡʧ��
// ���÷�����
//      char szThirdParty[1024+1]={0};
//      GetThirdParty(szThirdParty, sizeof(szThirdParty));
int DLL_MA_THIRD_PARTY GetThirdParty(char *p_szThirdParty, int p_iThirdPartySize);

#ifdef __cplusplus
}
#endif

#endif  // ifndef _MA_THIRD_PARTY_H_ 