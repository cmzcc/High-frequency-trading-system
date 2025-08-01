#pragma once

#include <iostream>
#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#include <Windows.h>
#else
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>
#endif

namespace maclicpp
{
  class CMutex
  {
#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
  public:
    CMutex()
		{
			::InitializeCriticalSection(&m_mtx);
		}
    virtual ~CMutex()
		{
			::DeleteCriticalSection(&m_mtx);
		}

    void Lock()
    {
      ::EnterCriticalSection(&m_mtx);
    }

    void Unlock()
    {
      ::LeaveCriticalSection(&m_mtx);
    }

    inline CRITICAL_SECTION& getMutex(){return m_mtx;}

  private:
    CRITICAL_SECTION m_mtx;                    
#else
  public:
    CMutex() : m_mtx(PTHREAD_MUTEX_INITIALIZER) {}

    virtual ~CMutex(){ m_mtx = PTHREAD_MUTEX_INITIALIZER;}

    void Lock()
    {
      pthread_mutex_lock(&m_mtx);
    }

    void Unlock()
    {
      pthread_mutex_unlock(&m_mtx);
    };

    inline pthread_mutex_t& GetMutex(){return m_mtx;}

  private:
    pthread_mutex_t m_mtx;      
#endif
  };

  class CLock
  {
  public:
    CLock(CMutex &ctx) : m_ctx(ctx)
    {
      m_ctx.Lock();
    }

    virtual ~CLock()
    {
      m_ctx.Unlock();
    }

		void Lock()
		{
      m_ctx.Lock();
		}

		void Unlock()
		{
      m_ctx.Unlock();
		}



    CMutex& GetMu() { return m_ctx; }

  private:
    CMutex &m_ctx;
  };
}