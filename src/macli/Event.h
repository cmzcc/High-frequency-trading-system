#pragma once
#include "Mutex.h"
#include <iostream>
#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#include <Windows.h>
#else
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

#endif

std::string gbk_to_utf8(const std::string& gbk_str);

namespace maclicpp
{
	class CEvent
	{
	public:
		CEvent();
		virtual ~CEvent();
		bool Wait(CLock &lock, long milliseconds = -1L);
		bool Signal();

	private:
#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
		HANDLE m_hHdl;
#else
		pthread_cond_t m_cond;
    int            m_iSigCnt;
#endif
	};
}

