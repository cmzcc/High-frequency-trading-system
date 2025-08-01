//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maCliTradeApi.h
// ģ�����ƣ�ma΢�ܹ�C++����API�ӿڵ���CTP��װ�ӿ�
// ģ��������
// �������ߣ������
// �������ڣ�2015-06-25
// ģ��汾��001.000.000
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2015-06-25    001.000.000   �����          ԭ��
//----------------------------------------------------------------------------
#if !defined(__MA_CLI_TRADE_API_H__)
#define __MA_CLI_TRADE_API_H__

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #define FORMAT_LONGLONG "%I64d"
  #if defined(WIN32)
  typedef __int64 LONGLONG;
  #endif
#else
  #define FORMAT_LONGLONG "%lld"
  typedef long long LONGLONG;
#endif

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
  #if defined MA_TRADE_API_EXPORTS
    #define MATRADEAPI __declspec(dllexport)
  #else
    #define MATRADEAPI __declspec(dllimport)
  #endif
#else
  #define MATRADEAPI
#endif

#if !defined(BGN_NAMESPACE_MACLI)
  #define BGN_NAMESPACE_MACLI   namespace macli {
  #define END_NAMESPACE_MACLI   }
  #define USE_NAMESPACE_MACLI   using namespace macli;  
#endif

BGN_NAMESPACE_MACLI

#if defined(OS_IS_LINUX)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

// ϵͳ���Ӳ���
struct MATRADEAPI CReqSysField
{
  char          szSvrAddress[39 + 1];       // ������IP��ַ
  int           nSvrPort;                   // �������˿�
  char          szLocalAddress[39 + 1];     // ����IP��ַ
  int           nLocalPort;                 // ���ض˿�
  int           iSsl;                       // ����ͨ�� 0:�Ǽ��� 1:���� -1:������
  char          szPktVer[2 + 1];            // ����Э��汾 01:Jason 02:PB
  unsigned int  uiTimeout;                  // ��ʱʱ��(��)
  char          chDataSet;                  // �����Զ����� '0':������ '1':���˻� 0:������
  int           iFlashModule;               // ������ģ������ 0:Ĭ������ 1:��ͨ���� 2:TCP_DIRECT����[Lnx64֧��] 4:RDMA���� 8:exanic���� [Lnx64֧��]
  char          chFlashPub;                 // ����������ģʽ '0':���˻���ͨ  '1':���˻�����  '2':��������ͨ '3':�����Ӿ���
};

// ����̶�����
struct MATRADEAPI CReqFixField
{
  char          szOpUser[32 + 1];           // �����û�����
  char          chOpRole;                   // �����û���ɫ
  char          szOpSite[256 + 1];          // ����վ��
  char          chChannel;                  // ��������
  char          szSession[128 + 1];         // �Ựƾ֤
  char          szFunction[16 + 1];         // ���ܴ���
  char          szRuntime[32 + 1];          // ����ʱ�� YYYY-MM-DD HH24:MI:SS.nnnnnn
  int           iOpOrg;                     // ��������
  char          szCuacctCode[32 + 1];       // �����ʲ��˻�
  char          chCuacctType;               // �����˻�����
  char          szTrdPwd[32 + 1];           // �������� ���н��׽ӿ�ʹ��
  char          szSerChannel[8 + 1];        // ��������
};

// �ն���Ϣ����
struct MATRADEAPI CReqClientField
{
  char          szIip[39 + 1];              // ����IP
  char          szIport[5 + 1];             // ����IP�˿ں�
  char          szLip[39 + 1];              // ����IP
  char          szMac[18 + 1];              // MAC��ַ
  char          szHd[32 + 1];               // Ӳ�����к�
  char          szPcn[20 + 1];              // PC�ն��豸��
  char          szCpu[20 + 1];              // CPU���к�
  char          szPi[20 + 1];               // Ӳ�̷�����Ϣ
  char          szVol[10 + 1];              // ϵͳ�̾����
  char          szExt[53 + 1];              // ��չ��Ϣ �ԡ�;�����зָ�
};

// ��1���������
struct MATRADEAPI CFirstSetField
{
  int           iMsgCode;                   // ��Ϣ����
  char          chMsgLevel;                 // ��Ϣ����
  char          szMsgText[256 + 1];         // ��Ϣ����
  char          szMsgDebug[1024 + 1];       // ��̨������Ϣ
};

//-------------------------------00102012:��������------------------------------------
struct MATRADEAPI CReqSubTopicField
{
  char          szTopic[12 + 1];            // ����
  char          szFilter[512 + 1];          // ��������
  char          chDataSet;                  // �ɽ����ݼ� '0':���������ӷ���ί�еĳɽ���Ϣ '1':���������ӷ���ί�еĳɽ���Ϣ
};

struct MATRADEAPI CRspSubTopicField
{
  char          szTopic[12 + 1];            // ����
  char          szFilter[512 + 1];          // ��������
  LONGLONG      llAcceptSn;                 // ����������
  char          szChannel[64 + 1];          // ����ͨ��
  char          chDataSet;                  // �ɽ����ݼ� '0':���������ӷ���ί�еĳɽ���Ϣ '1':���������ӷ���ί�еĳɽ���Ϣ
};

//-------------------------------00102013:�˶�����------------------------------------
struct MATRADEAPI CReqUnsubTopicField
{
  char          szTopic[12 + 1];            // ����
  LONGLONG      llAcceptSn;                 // ����������
};

struct MATRADEAPI CRspUnsubTopicField
{
  char          szTopic[12 + 1];            // ����
  LONGLONG      llAcceptSn;                 // ����������
};

//-------------------------------00102014:�ϴ��ļ�����------------------------------------
struct MATRADEAPI CReqFileUploadField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szLocalFileName[512 + 1];   // �����ļ���
};

struct MATRADEAPI CRspFileUploadField
{
  char            szFileName[512 + 1];        // �����ļ���
};

//-------------------------------00102015:�����ļ�����------------------------------------
struct MATRADEAPI CReqFileDownloadField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szLocalFileName[512 + 1];   // �����ļ���
};

struct MATRADEAPI CRspFileDownloadField
{
  char            szFileName[512 + 1];        // �����ļ���
};

//-------------------------------00102014:�ϴ�Ŀ¼�ļ�����------------------------------------
struct MATRADEAPI CReqFolderUploadField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szLocalFolder[512 + 1];     // ���Ŀ¼·��
};

struct MATRADEAPI CRspFolderUploadField
{
  char            szFileName[512 + 1];        // ���·���ļ���
};

//-------------------------------00102015:����Ŀ¼�ļ�����------------------------------------
struct MATRADEAPI CReqFolderDownloadField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szLocalFolder[512 + 1];     // ���Ŀ¼·��
};

struct MATRADEAPI CRspFolderDownloadField
{
  char            szFileName[512 + 1];        // ���·���ļ���
};

//-------------------------------00102016:�ļ���Ϣ��ѯ------------------------------------
struct MATRADEAPI CReqQryFileInfoField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szFilePath[512 + 1];        // ���·��Ŀ¼
  char            szFileFilter[32 + 1];       // �ļ�����  ���� *.dll Ĭ��Ϊ��
};

struct MATRADEAPI CRspQryFileInfoField
{
  char            szFileId[32 + 1];           // �ļ�ID
  LONGLONG        llFileSize;                 // �ļ���С
  char            szFileMd5[32 + 1];          // �ļ�MD5
  char            szFileTime[32 + 1];         // ����ʱ��
  char            szFileName[512 + 1];        // ���·���ļ���
};

//-------------------------------00102017:������������------------------------------------
struct MATRADEAPI CReqStgyStartField
{
  char            szFileId[32 + 1];           // �ļ�ID
  char            szCuacctCode[32 + 1];       // �ʽ��˻�
  char            szStgyId[32 + 1];           // ����ID
  char            szStgyParam[512 + 1];       // ���Բ���
};

struct MATRADEAPI CRspStgyStartField
{
  char            szRunningId[32 + 1];        // ����ʵ��
  char            szFileId[32 + 1];           // �ļ�ID
  char            szCuacctCode[32 + 1];       // �ʽ��˻�
  char            szStgyId[32 + 1];           // ����ID
  char            chRunningStatus;            // ����״̬
};

//-------------------------------00102018:����ֹͣ����------------------------------------
struct MATRADEAPI CReqStgyStopField
{
  char            szRunningId[32 + 1];        // ����ʵ��
  char            szFileId[32 + 1];           // �ļ�ID
  char            szCuacctCode[32 + 1];       // �ʽ��˻�
  char            szStgyId[32 + 1];           // ����ID
};

struct MATRADEAPI CRspStgyStopField
{
  char            szRunningId[32 + 1];        // ����ʵ��
  char            szFileId[32 + 1];           // �ļ�ID
  char            szCuacctCode[32 + 1];       // �ʽ��˻�
  char            szStgyId[32 + 1];           // ����ID
  char            chRunningStatus;            // ����״̬
};

//-------------------------------00102019:����״̬��ѯ------------------------------------
struct MATRADEAPI CReqQryStgyStatField
{
  char            szRunningId[32 + 1];        // ����ʵ��
  char            szFileId[32 + 1];           // �ļ�ID
  char            szStgyId[32 + 1];           // ����ID
};

struct MATRADEAPI CRspQryStgyStatField
{
  char            szRunningId[32 + 1];        // ����ʵ��
  char            szFileId[32 + 1];           // �ļ�ID
  char            szCuacctCode[32 + 1];       // �ʽ��˻�
  char            szStgyId[32 + 1];           // ����ID
  char            chRunningStatus;            // ����״̬
};

//-------------------------------00103003:���ӱ���------------------------------------
struct MATRADEAPI CReqHeartBeatField
{
  ;
};

struct MATRADEAPI CRspHeartBeatField
{
  char          szServerLocalNodeId[32 + 1];  // ���ڵ���
  char          szServerNodeId[32 + 1];       // �ڵ���
  char          szServerNodeGid[32 + 1];      // �ڵ����
  char          szServerSiteName[32 + 1];     // ����վ����
  char          szServerNodeType[32 + 1];     // �ڵ�����
  char          szServerSiteIP[32 + 1];       // վ��IP
  char          szServerNodePwd[128 + 1];     // �ڵ�·��
  char          szServerNodeUse[4 + 1];       // �ڵ���; ��n��:�����ڵ� ��s��:�����ڵ� ��a��:���ýڵ�
  char          szServerBackIp[32 + 1];       // ����վ��IP
};

//-------------------------------00103004:��ȫ���------------------------------------
struct MATRADEAPI CReqSafeCheckField
{
  char          szCuacctCode[32 + 1];         // �ʽ��˻�
  char          chPlainType;                  // �������� ��2��:�ͻ���IP ��3��:����MAC ��4��:������APP
  char          szCipherText[128 + 1];        // �������� RSA��������
};

struct MATRADEAPI CRspSafeCheckField
{
  int           iEffectDate;                  // ��Ч����
  int           iExpireDate;                  // ʧЧ����
};

//-------------------------------00102028:�����Ϣ��������------------------------------------
struct MATRADEAPI CRtnTradeRiskInfoField
{
  char            chRiskCls;                  // ������� 
  char            szRiskId[2 + 1];            // ���ձ�ʶ 
  char            chRiskIdLevel;              // ���ռ��� 
  char            szRiskName[256 + 1];        // �������� 
  LONGLONG        llCustCode;                 // �ͻ����� 
  LONGLONG        llCuacctCode;               // �ʲ��˻� 
  char            szStkbd[2 + 1];             // ֤ȯ��� �ֵ�[STKBD]
  char            szContent[2048 + 1];        // ֪ͨ���� 
};

//-------------------------------00102021:ϵͳ״̬��������------------------------------------
struct MATRADEAPI CRtnSystemInfoField
{
  int             iSubsys;                    // ϵͳ���� 
  int             iSubsysSn;                  // ϵͳ�ڵ��� �˻�����ϵͳ���
  int             iTrdDate;                   // �������� 
  int             iOrderDate;                 // ί������ 
  char            chTrdStatus;                // ����״̬ ��1��:�����µ� ��0��:��ֹ�µ�
  char            szRemark[128 + 1];          // ״̬˵�� 
};

//-------------------------------00102029:�˻�֪ͨ��������--------------------------
struct MATRADEAPI CRtnNoticeInfoField
{
  int             iSubsys;                    // ϵͳ���� 
  char            chNotyType;                 // ֪ͨ���� ��0��:�������� ��1��:������ֹ ��2��:�ɼ۱䶯��ֹ
  char            szNotyInfo[256 + 1];        // ֪ͨ���� 
  int             iSettDate;                  // �������� 
  int             iOrderDate;                 // ί������ 
  int             iOrderBsn;                  // ί������ 
  LONGLONG        llOrderNo;                  // ί�б�� 
  LONGLONG        llOrderGroupNo;             // ��ϱ�� 
  char            szOrderTime[32 + 1];        // ί��ʱ�� 
  char            chExeStatus;                // ί��״̬ 
  int             iTrdDate;                   // �������� 
  int             iOrderValidDate;            // ��Ч���� 
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            chCuacctType;               // �˻����� 
  char            szTrdCode[30 + 1];          // Ʒ�ִ��� 
  int             iTrdBiz;                    // ����ҵ�� 
  int             iTrdBizAcction;             // ҵ�� 
  LONGLONG        llOrderQty;                 // ί������ 
  char            szOrderPrice[21 + 1];       // ί�м۸� 
  char            szOptUndlCode[8 + 1];       // ���֤ȯ���� 
  char            chStrategyType;             // �������� 
  char            szStrategyName[32 + 1];     // �������� 
  char            chChannel;                  // ��������
};

//-------------------------------10388750:COSϵͳ��¼����--------------------------
struct MATRADEAPI CReqCosLoginField
{
  char            szUserCode[16 + 1];         // �û����� Ҳ�������ֻ��ŵ�¼
  char            szAuthData[256 + 1];        // ��֤���� 
  char            szEncryptKey[32 + 1];       // �������� 
  char            szThirdParty[1024 + 1];     // ������ ʹ�õ������ͻ��˵��û��������,�ֶ���������Կdllָ���ӿڻ�ȡ;
  char            chChannel;                  // ��������
  char            szSerChannel[8 + 1];        // ��������
};

struct MATRADEAPI CRspCosLoginField
{
  char            szUserCode[16 + 1];         // �û����� 
  char            szPhoneNum[16 + 1];         // �ֻ��� 
  char            szUserGroupRight[8 + 1];    // �û���Ȩ�� 
  char            szSessionId[128 + 1];       // �Ựƾ֤ �ͻ����豣�棬����������д���̶���λỰƾ֤(8814)�У�����������󽫱��ܾ���
};

#if defined(OS_IS_LINUX)
#pragma pack()
#else
#pragma pack(pop)
#endif

class MATRADEAPI CCliTradeSpi
{
public:
  // �ͻ�����������ɹ�����ͨ�����Ӻ󣬸÷���������
  virtual int OnConnected(void) {return 0;}

  // �ͻ�����������ɹ���ͨ�����ӶϿ�ʱ���÷���������
  virtual int OnDisconnected(int p_nReason, const char *p_pszErrInfo) {return 0;}

  // �ͻ����ϴ��ļ�ʱ���÷��������� p_nResult:���Ȱٷֱ�
  virtual int OnFileUpload(const char *p_pszFileName, int p_nResult) {return 0;}

  // �ͻ��������ļ�ʱ���÷��������� p_nResult:���Ȱٷֱ�
  virtual int OnFileDownload(const char *p_pszFileName, int p_nResult) {return 0;}

  // �ͻ����ϴ�Ŀ¼ʱ��ÿ���ļ��ϴ�ʱ�÷��������� p_nResult:���Ȱٷֱ�
  virtual int OnFolderUpload(const char *p_pszFileName, int p_nResult) {return 0;}

  // �ͻ�������Ŀ¼ʱ��ÿ���ļ�����ʱ�÷��������� p_nResult:���Ȱٷֱ�
  virtual int OnFolderDownload(const char *p_pszFileName, int p_nResult) {return 0;}

  // ���ӱ�����Ӧ
  virtual int OnRspHeartBeat(CFirstSetField *p_pFirstSetField, CRspHeartBeatField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ȫ�����Ӧ
  virtual int OnRspSafeCheck(CFirstSetField *p_pFirstSetField, CRspSafeCheckField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ļ���Ϣ��ѯ��Ӧ
  virtual int OnRspQryFileInfo(CFirstSetField *p_pFirstSetField, CRspQryFileInfoField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����������Ӧ
  virtual int OnRspStgyStart(CFirstSetField *p_pFirstSetField, CRspStgyStartField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ֹͣ��Ӧ
  virtual int OnRspStgyStop(CFirstSetField *p_pFirstSetField, CRspStgyStopField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����״̬��ѯ��Ӧ
  virtual int OnRspQryStgyStat(CFirstSetField *p_pFirstSetField, CRspQryStgyStatField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // COSϵͳ��¼������Ӧ
  virtual int OnRspCosLogin(CFirstSetField *p_pFirstSet, CRspCosLoginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������Ӧ
  virtual int OnRtnSubTopic(CRspSubTopicField* p_pRspField) {return 0;}

  // ȡ��������Ӧ
  virtual int OnRtnUnsubTopic(CRspUnsubTopicField* p_pRspField) {return 0;}

  // �����Ϣ������Ϣ ����TRADERISK+X
  virtual int OnRtnTradeRisk(CRtnTradeRiskInfoField* p_pRspField) {return 0;}

  // ϵͳ״̬������Ϣ ����SYSTEM00
  virtual int OnRtnSystemInfo(CRtnSystemInfoField* p_pRspField) {return 0;}

  // �˻�֪ͨ������Ϣ ����NOTICE+XX
  virtual int OnRtnNoticeInfo(CRtnNoticeInfoField* p_pRspField) {return 0;}

};

class MATRADEAPI CCliTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliTradeApi(void);

  // ��������
  virtual ~CCliTradeApi(void);

  // ��ʼ��
  virtual int Init(void);

  // �˳�
  virtual int Exit(void);

  // ע��������Ϣ
  virtual int RegisterServer(const char *p_pszIp, int p_iPort, unsigned int p_uiTimeout = 1, const char* p_pszPktVer = "01", bool p_bCos = false, int p_iSsl = -1);

  // ע��������Ϣ
  virtual int RegisterServer(CReqSysField* p_pstSysField);

  ///ע��ص��ӿ�
  virtual int RegisterSpi(CCliTradeSpi *p_pSpi);

  // ע���˺���Ϣ
  virtual int RegisterAcct(char p_chChannel, const char* p_pszOpSite = 0, int p_iSiteLen = 0);

  // ע���˺���Ϣ
  virtual int RegisterAcct(CReqFixField* p_pstFixField);

  // ע���ն���Ϣ
  virtual int RegisterClient(CReqClientField* p_pstClientField);

  // ���ӱ�������
  virtual int ReqHeartBeat(CReqHeartBeatField *p_pReqField, LONGLONG p_llRequestId);

  // ��ȫ�������
  virtual int ReqSafeCheck(CReqSafeCheckField *p_pReqField, LONGLONG p_llRequestId);

  // �ϴ��ļ�����
  virtual int ReqFileUpload(CReqFileUploadField *p_pReqField, LONGLONG p_llRequestId);

  // �����ļ�����
  virtual int ReqFileDownload(CReqFileDownloadField *p_pReqField, LONGLONG p_llRequestId);

  // �ϴ�Ŀ¼����
  virtual int ReqFolderUpload(CReqFolderUploadField *p_pReqField, LONGLONG p_llRequestId);

  // ����Ŀ¼����
  virtual int ReqFolderDownload(CReqFolderDownloadField *p_pReqField, LONGLONG p_llRequestId);

  // �ļ���Ϣ��ѯ����
  virtual int ReqQryFileInfo(CReqQryFileInfoField *p_pReqField, LONGLONG p_llRequestId);

  // ������������
  virtual int ReqStgyStart(CReqStgyStartField *p_pReqField, LONGLONG p_llRequestId);

  // ����ֹͣ����
  virtual int ReqStgyStop(CReqStgyStopField *p_pReqField, LONGLONG p_llRequestId);

  // ����״̬��ѯ����
  virtual int ReqQryStgyStat(CReqQryStgyStatField *p_pReqField, LONGLONG p_llRequestId);

  // COSϵͳ��¼��������
  virtual int ReqCosLogin(CReqCosLoginField *p_pReqField, LONGLONG p_llRequestId);

  // ����ҵ���ͷ��Ϣ
  int SetBizPackHead(const char *p_pszFuncId, LONGLONG p_llRequestId, char *p_pszMsgId, char p_chPkgType, char p_chPkgVer = '2', char p_chFuncType = 0);

  // ��������
  int SubTopic(const char *p_pszTopic, const char *p_pszFilter, char p_chDataSet = '0');

  // �˶�����
  int UnsubTopic(const char *p_pszTopic, LONGLONG llAcceptSn = 0);

  // ����������Ӧ
  void OnRspSubTopic(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �˶�������Ӧ
  void OnRspUnsubTopic(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ӱ���������Ӧ
  void OnRspHeartBeat(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ��ȫ���������Ӧ
  void OnRspSafeCheck(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �ļ���Ϣ��ѯ������Ӧ
  void OnRspQryFileInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��������������Ӧ
  void OnRspStgyStart(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ֹͣ������Ӧ
  void OnRspStgyStop(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����״̬��ѯ������Ӧ
  void OnRspQryStgyStat(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ϵͳע�Ṧ����Ӧ
  void OnRspCosLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��ȡ��������Ϣ
  const char* GetLastErrorText(void);

public:
  // �첽�ص�����
  virtual void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  virtual void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // ���ӻص�����
  virtual void OnNetCallback(const char *p_pszNetState, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �ļ��ϴ��ص�
  virtual void OnFileUpCallback(const char *p_pszFileName, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �ļ����ػص�
  virtual void OnFileDownCallback(const char *p_pszFileName, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // Ŀ¼�ϴ��ص�
  virtual void OnFolderUpCallback(const char *p_pszFileName, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // Ŀ¼���ػص�
  virtual void OnFolderDownCallback(const char *p_pszFileName, const unsigned char *p_pszDataBuff, int p_iDataLen);

protected:
  int OnBeginCall(void);
  int OnEndCall(void);
  int OnDoCall(void* p_pvAsynCall);
  int OnCheckPointer(void* p_pVar, const char* p_pszVar);
  
protected:
  void             *m_hAsynCall;                 // ϵͳ���þ��
  void             *m_hAnsParse;                 // Ӧ�������
  void             *m_hPubParse;                 // ���ͽ�����
  CReqSysField      m_stSysField;                // ϵͳ���Ӳ���
  CReqFixField      m_stReqFixField;             // ����̶�����
  CReqClientField   m_stReqClientField;          // �����ն˲���
  CCliTradeSpi     *m_pTradeSpi;                 // �ص�ʵ��ָ��
  char              m_szLastErrorText[1024 + 1]; // ��������Ϣ
  char              m_szClientInfo[256 + 1];     // �����ն���Ϣ
  void             *m_pAcctInfo;                 // ��¼�˻���Ϣ
};

END_NAMESPACE_MACLI

#endif  // __MA_CLI_TRADE_API_H__