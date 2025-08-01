#include "Event.h"
#include <iconv.h>

std::string gbk_to_utf8(const std::string& gbk_str) {
	iconv_t cd = iconv_open("UTF-8", "GBK");
	if (cd == (iconv_t)-1) {
		throw std::runtime_error("Failed to open iconv");
	}

	size_t in_bytes_left = gbk_str.size();
	size_t out_bytes_left = in_bytes_left * 4; // UTF-8最多占用4个字节
	char* in_buf = const_cast<char*>(gbk_str.data());
	std::string utf8_str(out_bytes_left, '\0');
	char* out_buf = &utf8_str[0];

	if (iconv(cd, &in_buf, &in_bytes_left, &out_buf, &out_bytes_left) == (size_t)-1) {
		iconv_close(cd);
		throw std::runtime_error("Failed to convert encoding");
	}

	iconv_close(cd);

	// 去除未使用的空间
	utf8_str.resize(utf8_str.size() - out_bytes_left);
	return utf8_str;
}

namespace maclicpp
{

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
  CEvent::CEvent() 
	{
    m_hHdl = CreateEvent(NULL, FALSE, FALSE, NULL);   //�Զ��ָ������ź�״̬���ҳ�ʼ״̬Ϊ���ź�
  }
	
	CEvent::~CEvent()
	{
    if(NULL != m_hHdl)
    {
      ::CloseHandle(m_hHdl);
      m_hHdl = NULL;
    }
	}

	bool CEvent::Wait(CLock &lock, long milliseconds)
	{
		bool bRet = true;

    if(milliseconds<0 && -1!=milliseconds)
    {
      return false;
    }

		lock.Unlock();

		if(-1 == milliseconds)
		{
			if (WAIT_OBJECT_0 != WaitForSingleObject(m_hHdl, INFINITE))
			{
				bRet = false;
			}
		}
		else if(0 <= milliseconds)
		{
			DWORD dwRet = WaitForSingleObject(m_hHdl, milliseconds);
			if(WAIT_OBJECT_0!=dwRet && WAIT_TIMEOUT!=dwRet)
			{
				bRet = false;
			}
		}

		lock.Lock();

		return bRet;;
	}

	bool CEvent::Signal()
	{
		return ::SetEvent(m_hHdl);	
	}

#else
  CEvent::CEvent() 
    : m_iSigCnt(0)
    , m_cond(PTHREAD_COND_INITIALIZER)
  {
    pthread_cond_init(&m_cond, NULL);
  }

  CEvent::~CEvent()
  {
    pthread_cond_destroy(&m_cond);
    m_cond = PTHREAD_COND_INITIALIZER;
  }

  bool CEvent::Wait(CLock &lock, long milliseconds)
  {
    bool bRet = true;

		do 
		{
			if(milliseconds<0 && -1!=milliseconds)
			{
				bRet = false;
				break;
			}

			if(0 == m_iSigCnt)
			{
				if(-1 == milliseconds)
				{
					if(0 != pthread_cond_wait(&m_cond, &lock.GetMu().GetMutex())) bRet = false;
				}
				else if(0 <= milliseconds)
				{
					struct timespec stAbstime;
					struct timeval stNow;
					gettimeofday(&stNow, NULL);
					long llNasec = stNow.tv_usec*1000 + (milliseconds%1000)*1000000;
					stAbstime.tv_sec = stNow.tv_sec + llNasec/1000000000 + milliseconds/1000;
					stAbstime.tv_nsec = llNasec % 1000000000;

					int iRetCode = pthread_cond_timedwait(&m_cond, &lock.GetMu().GetMutex(), &stAbstime);
					if(0!= iRetCode && ETIMEDOUT!=iRetCode) bRet = false;
				}
			}

		} while (false);

    if(m_iSigCnt > 0) --m_iSigCnt;

    return bRet;
  }

  bool CEvent::Signal()
  {
    ++m_iSigCnt;
    if(-1 == pthread_cond_signal(&m_cond)) return false;
    return true;
  }
#endif

}