#if !defined(__kbss_encrypt_h__)
#define __kbss_encrypt_h__

#if !defined(KBSS_ENCRYPT) && !defined(KBSS_DECRYPT)
#define KBSS_ENCRYPT
#undef KBSS_DECRYPT
#endif

#define KBSS_COMENCRYPT
#define KBSS_COMDECRYPT

#if defined(OS_IS_WINDOWS)

#ifdef  DLLEXPORTS
#define DLLEXPORT _declspec(dllexport)
#else
#define DLLEXPORT _declspec(dllimport)
#endif
#define KBSS_CALLTYPE _cdecl
#else
#define DLLEXPORT
#define KBSS_CALLTYPE
#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #if defined(WIN32)
  typedef __int64 LONGLONG;
  #elif defined(WIN64)
  typedef long long LONGLONG;
  #endif
#else
  typedef long long LONGLONG;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_encrypt
// 功能描述：数据存储加密算法
// 参数说明：p_pszOutput      [out]    密文
//           p_iFixedSize     [in]     密文缓冲区大小
//           p_pszInput       [int]    明文
//           p_pszKey         [in]     密钥
// 返回说明：(空)
// 函数备注：
#if defined(KBSS_ENCRYPT)
void DLLEXPORT KBSS_CALLTYPE kbss_encrypt(char *p_pszOutput, int p_iFixedSize, const char *p_pszInput, const char *p_pszKey);
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_decrypt
// 功能描述：数据存储解密算法
// 参数说明：p_pszOutput      [out]    明文
//           p_iFixedSize     [in]     明文缓冲区大小
//           p_pszInput       [int]    密文
//           p_pszKey         [in]     密钥
// 返回说明：(空)
// 函数备注：此函数不对外提供.
#if defined(KBSS_DECRYPT)
void DLLEXPORT KBSS_CALLTYPE kbss_decrypt(char *p_pszOutput, int p_iFixedSize, const char *p_pszInput, const char *p_pszKey);
#endif


//------------------------------------------------------------------------------
// 函数名称：kbss_recrypt
// 功能描述：数据存储重加密算法
// 参数说明：p_pszOutput      [out]    密文(更换后)
//           p_iFixedSize     [in]     密文(更换后)缓冲区大小
//           p_pszInput       [int]    密文(更换前)
//           p_pszOldKey      [in]     原密钥
//           p_pszNewKey      [in]     新密钥
// 返回说明：(空)
// 函数备注：此函数用于更换加密的密钥
#if defined(KBSS_ENCRYPT)
void DLLEXPORT KBSS_CALLTYPE kbss_recrypt(char *p_pszOutput, int p_iFixedSize, const char *p_pszInput, const char *p_pszOldKey, const char *p_pszNewKey);
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_encrypt1
// 功能描述：数据存储加密算法
// 参数说明：p_pszOutput      [out]    密文
//           p_iFixedSize     [in]     密文缓冲区大小
//           p_pszInput       [int]    明文
//           p_pszKey         [in]     密钥
//           p_nEncodeType    [in]     加密算法 0:KBSS标准算法
//                                              1:金证W版集中交易算法
//                                              2:金证U版集中交易算法
// 返回说明：0 表示成功 其他表示失败
// 函数备注：
#if defined(KBSS_ENCRYPT)
int DLLEXPORT KBSS_CALLTYPE kbss_encrypt1(char *p_pszOutput,
                                           int p_iFixedSize,
                                           const char *p_pszInput,
                                           const char *p_pszKey,
                                           int p_nEncodeType);
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_decrypt1
// 功能描述：数据存储解密算法
// 参数说明：p_pszOutput      [out]    明文
//           p_iFixedSize     [in]     明文缓冲区大小
//           p_pszInput       [int]    密文
//           p_pszKey         [in]     密钥
//           p_nEncodeType    [in]     加密算法 0:KBSS标准算法
//                                              1:金证W版集中交易算法
//                                              2:金证U版集中交易算法
// 返回说明：0 表示成功 其他表示失败
// 函数备注：此函数不对外提供.
#if defined(KBSS_DECRYPT)
int DLLEXPORT KBSS_CALLTYPE kbss_decrypt1(char *p_pszOutput,
                                          int p_iFixedSize,
                                          const char *p_pszInput,
                                          const char *p_pszKey,
                                          int p_nEncodeType);
#endif


//------------------------------------------------------------------------------
// 函数名称：kbss_recrypt
// 功能描述：数据存储重加密算法
// 参数说明：p_pszOutput      [out]    密文(更换后)
//           p_iFixedSize     [in]     密文(更换后)缓冲区大小
//           p_pszInput       [int]    密文(更换前)
//           p_pszOldKey      [in]     原密钥
//           p_pszNewKey      [in]     新密钥
//           p_nEncodeType    [in]     加密算法 0:KBSS标准算法
//                                              1:金证W版集中交易算法
//                                              2:金证U版集中交易算法
// 返回说明：0 表示成功 其他表示失败
// 函数备注：此函数用于更换加密的密钥
#if defined(KBSS_ENCRYPT)
int DLLEXPORT KBSS_CALLTYPE kbss_recrypt1(char *p_pszOutput,
                                          int p_iFixedSize,
                                          const char *p_pszInput,
                                          const char *p_pszOldKey,
                                          const char *p_pszNewKey,
                                          int p_nEncodeType);
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_comencrypt
// 功能描述：通信加密算法
// 参数说明：p_pszOutput      [out]    密文,大小不小于1024
//           p_pszInput       [int]    明文,大小不小于1024
//           p_pszKey         [in]     密钥,大小不大于224
// 返回说明：(空)
// 函数备注：用于通信过程中关键信息的加密
#if defined(KBSS_COMENCRYPT)
void DLLEXPORT KBSS_CALLTYPE kbss_comencrypt(char *p_pszOutput, const char *p_pszInput, const char *p_pszKey);
#endif

//------------------------------------------------------------------------------
// 函数名称：kbss_comdecrypt
// 功能描述：通信加密算法
// 参数说明：p_pszOutput      [out]    明文,大小不小于1024
//           p_pszInput       [int]    密文,大小不小于1024
//           p_pszKey         [in]     密钥,大小不大于224
// 返回说明：(空)
// 函数备注：用于通信过程中关键信息的解密
#if defined(KBSS_COMDECRYPT)
void DLLEXPORT KBSS_CALLTYPE kbss_comdecrypt(char *p_pszOutput, const char *p_pszInput, const char *p_pszKey);
#endif


//------------------------------------------------------------------------------
// 函数名称：AES_Encrypt1
// 功能描述：AES加密算法
// 参数说明：p_pszEncrResult  [out]    密文
//           p_iSize          [int]    密文缓冲区大小
//           p_llKey          [in]     密钥，如用户代码
//           p_pszEncrInfo    [in]     明文
// 返回说明：(空)
// 函数备注：前后台加解密认证数据时用
void DLLEXPORT KBSS_CALLTYPE AES_Encrypt1(char *p_pszEncrResult, int p_iSize, __int64 p_llKey, const char * p_pszEncrInfo);

//------------------------------------------------------------------------------
// 函数名称：AES_Decrypt1
// 功能描述：AES解密算法
// 参数说明：p_pszDecrResult  [out]    明文
//           p_iSize          [int]    明文缓冲区大小
//           p_llKey          [in]     密钥，如用户代码
//           p_pszDecrInfo    [in]     密文
// 返回说明：(空)
// 函数备注：前后台加解密认证数据时用
void DLLEXPORT KBSS_CALLTYPE AES_Decrypt1(char *p_pszDecrResult, int p_iSize, __int64 p_llKey, const char * p_pszDecrInfo);


//------------------------------------------------------------------------------
// 函数名称：MD5_Digist
// 功能描述：MD5报文摘要算法
// 参数说明：p_pszDigResult   [out]    密文
//           p_iSize          [int]    密文缓冲区大小
//           p_pszDigRetInt   [in]     摘要
//           p_pszDigInfo     [in]     信息串
// 返回说明：(空)
// 函数备注：此算法不可逆，用于通信过程中信息的防篡改
void DLLEXPORT KBSS_CALLTYPE MD5_Digist(char * p_pszDigResult, int p_iSize, unsigned char p_pszDigRetInt[16], unsigned char * p_pszDigInfo);


//------------------------------------------------------------------------------
// 函数名称：Base64_Encode
// 功能描述：Base64加密算法
// 参数说明：p_pszEnResult    [out]    密文
//           p_pszEnInfo      [in]     明文
//           p_iSize          [in]     明文长度
// 返回说明：(空)
// 函数备注：此算法用于通信过程中的不可见字符的转换。
void DLLEXPORT KBSS_CALLTYPE Base64_Encode(char * p_pszEnResult, const unsigned char * p_pszEnInfo, int p_iSize);

//------------------------------------------------------------------------------
// 函数名称：Base64_Decode
// 功能描述：Base64解密算法
// 参数说明：p_pszResult      [out]    明文
//           p_refiCount      [out]    明文长度
//           pszDeInfo        [in]     密文
// 返回说明：(空)
// 函数备注：此算法用于通信过程中的不可见字符的转换。
void DLLEXPORT KBSS_CALLTYPE Base64_Decode(unsigned char *p_pszResult, int & p_refiCount, const char * pszDeInfo);


//------------------------------------------------------------------------------
// 函数名称：RC5_Encrypt1
// 功能描述：RC5加密算法
// 参数说明：p_pszEnResult    [out]    密文
//           p_iSize          [in]     密文缓冲区大小
//           p_llKey          [in]     密钥：如用户代码
//           p_pszEnInfo      [in]     明文
// 返回说明：(空)
// 函数备注：此算法用于前后台加解密保密键(验证码)。
void DLLEXPORT KBSS_CALLTYPE RC5_Encrypt1(char * p_pszEnResult, int p_iSize, __int64 p_llKey, const char * p_pszEnInfo);

//------------------------------------------------------------------------------
// 函数名称：RC5_Decrypt1
// 功能描述：RC5解密算法
// 参数说明：p_pszDeResult    [out]    明文
//           p_iSize          [in]     明文缓冲区大小
//           p_llKey          [in]     密钥：如用户代码
//           p_pszDeInfo      [in]     密文
// 返回说明：(空)
// 函数备注：此算法用于前后台加解密保密键(验证码)。
void DLLEXPORT KBSS_CALLTYPE RC5_Decrypt1(char * p_pszDeResult, int p_iSize, __int64 p_llKey, const char * p_pszDeInfo);


// iEncryptType = 1 代表服务端加解密Key2。这时传入的pszKey与iKeySize没有作用，内部写死有密钥。
// iEncryptType = 2 其它情况加解密
void DLLEXPORT KBSS_CALLTYPE RC5_Encrypt(char * p_pszEnResult, int p_iSize, const unsigned char * p_pszKey, int p_iKeySize, int p_iEncryptType, const char * p_pszEnInfo);
void DLLEXPORT KBSS_CALLTYPE RC5_Decrypt(char * p_pszDeResult, int p_iSize, const unsigned char * p_pszKey, int p_iKeySize, int p_iDecryptType, const char * p_pszDeInfo);

//------------------------------------------------------------------------------
// 函数名称：RSA_GenRsaKey
// 功能描述：RSA密钥产生算法
// 参数说明：p_pszPublicKey   [out]    公钥
//           p_iPublicKeySize [in]     公钥缓冲区大小
//           p_pszPrivateKey  [out]    私钥
//           p_iPrivateKeySize[in]     私钥缓冲区大小
//           p_iKeySize       [in]     密钥强度:256bit
// 返回说明：int
// 函数备注：此算法用于产生RSA的公私钥
int DLLEXPORT KBSS_CALLTYPE RSA_GenRsaKey(char *p_pszPublicKey, int p_iPublicKeySize, char *p_pszPrivateKey, int p_iPrivateKeySize, int p_iKeySize = 256);



//----------------------------------------------------------------------------
// 签名函数:RSA_Encrypt\RSA_Decrypt
// 此组函数为用于签名:即用私钥加密,公钥进行解密
//------------------------------------------------------------------------------
// 函数名称：RSA_Encrypt
// 功能描述：RSA签名加密算法
// 参数说明：p_pszSignResult  [out]    密文
//           p_iSize          [in]     密文缓冲区大小
//           p_pszKey         [in]     私钥
//           p_pszSignInfo    [in]     明文
//           p_iLen           [in]     明文长度
// 返回说明：int
// 函数备注：此算法用于数字签名
int DLLEXPORT KBSS_CALLTYPE RSA_Encrypt(char *p_pszSignResult, int p_iSize, char * p_pszKey, const unsigned char *p_pszSignInfo, int p_iLen);

//------------------------------------------------------------------------------
// 函数名称：RSA_Decrypt
// 功能描述：RSA签名解密算法
// 参数说明：p_pszSignResult [out]     明文
//           p_iSize         [in]      明文缓冲区大小
//           p_refiCount     [out]     明文有效长度
//           p_pszKey        [in]      公钥
//           p_pszVerifyInfo [in]      密文
// 返回说明：int
// 函数备注：此算法用于数字签名
int DLLEXPORT KBSS_CALLTYPE RSA_Decrypt(char *p_pszDecrResult, int p_iSize, int &p_refiCount, const char *p_pszKey, const char *p_pszVerifyInfo);

//----------------------------------------------------------------------------
// RSA函数:RSA_Encrypt1\RSA_Decrypt1
// 此组函数为用于签名:即用公钥加密,私钥进行解密
//------------------------------------------------------------------------------
// 函数名称：RSA_Encrypt1
// 功能描述：RSA加密算法
// 参数说明：p_pszSignResult [out]     密文
//           p_iSize         [in]      密文缓冲区大小
//           p_pszKey        [in]      公钥
//           p_pszSignInfo   [in]      明文
//           p_iLen          [in]      明文长度
// 返回说明：int
// 函数备注：此算法用于数据加密
int DLLEXPORT KBSS_CALLTYPE RSA_Encrypt1(char *p_pszSignResult, int p_iSize, char * p_pszKey, const unsigned char *p_pszSignInfo, int p_iLen);


//------------------------------------------------------------------------------
// 函数名称：RSA_Decrypt1
// 功能描述：RSA解密算法
// 参数说明：p_pszSignResult [out]     明文
//           p_iSize         [in]      明文缓冲区大小
//           p_pszKey        [in]      私钥
//           p_pszVerifyInfo [in]      密文
// 返回说明：int
// 函数备注：此算法用于数据解密
int DLLEXPORT KBSS_CALLTYPE RSA_Decrypt1(char *p_pszDecrResult, int p_iSize, int &p_refiCount, const char *p_pszKey, const char *p_pszVerifyInfo);

//------------------------------------------------------------------------------
// 函数名称：RandomNo
// 功能描述：随机数
// 参数说明：p_pszRandNoBuf  [out]     缓冲区
//           p_iSize         [in]      缓冲区大小
// 返回说明：void
void DLLEXPORT KBSS_CALLTYPE RandomNo(char * p_pszRandNoBuf, int p_iSize);



//------------------------------------------------------------------------------
// 功能描述：通讯加密(U版)
// 入参说明：
//           p_lUserCode : 用户代码
//           p_lpszPlainText : 密码明文，最大有效加密长度为15位，
//                             取值范围：以'\0'结束的任意15位长度以内的字符串。
//           p_lpszCipherText : 密码密文，指针所指的空间大小必须大于等33个字节。
void DLLEXPORT KBSS_CALLTYPE UF_CommEncrypt(long p_lUserCode, const char * p_lpszPlainText, char * p_lpszCipherText);

//------------------------------------------------------------------------------
// 功能描述：通讯解密(U版)
// 入参说明：
//           p_lUserCode : 用户代码
//           p_lpszCipherText : 密码密文，以'\0'结束的32个字节的字符串。
//           p_lpszPlainText : 密码明文，指针所指的空间大小必须大于等17个字节。
void DLLEXPORT KBSS_CALLTYPE UF_CommDecrypt(long p_lUserCode, const char * p_lpszCipherText, char * p_lpszPlainText);

//------------------------------------------------------------------------------
// 功能描述：
//     OEM校验
// 参数说明：
//   p_pszOemName      厂商名称
//   p_pszOemCode      OEM代码
//   p_pszOemBzxx      OEM备注信息
//   p_pszZqszwmc      券商中文名称
//   p_iTrdDate        当前交易日期
//   p_refiValidDate   失效日期
//   p_iPinCode        PIN代码，缺省为6892
// 返回说明：
//   < 0 校验不通过
//   -1  OEM代码与厂商名称不符
//   -2  OEM非法！请向金证公司核实!(oldcrypt)
//   -3  OEM非法！请向金证公司核实!(newcrypt)
//   -4  备注信息有误,长度应为16/32位
//   >=0  校验通过, 返回值为尚余有效天数
int DLLEXPORT KBSS_CALLTYPE kbss_checkoem(unsigned char *p_pszOemName,
             char *p_pszOemCode,
             char *p_pszOemBzxx,
             char *p_pszZqszwmc,
             int p_iTrdDate,
             int &p_refiValidDate,
             int p_iPinCode = 6892);

#ifdef __cplusplus
}
#endif

#endif  // __kbss_encrypt_h__
