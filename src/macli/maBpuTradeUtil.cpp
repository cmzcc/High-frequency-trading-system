#include "maBpuTradeUtil.h"
#include <time.h>
#include <stdio.h>

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#include <Windows.h>
#else
#include <unistd.h>
#endif

namespace maclicpp
{
  char* GetCurrTime(char *pszBufTime)
  { 
    time_t timep;
    struct tm *p;
    time(&timep); /*获得time_t结构的时间，UTC时间*/
    p = localtime(&timep); /*转换为struct tm结构的当地时间*/
    sprintf(pszBufTime, "%04d%02d%02d%02d%02d%02d%03d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, 0);
    return pszBufTime;
  }

  void sleep(long llMilliSeconds)
  {
#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
    Sleep(llMilliSeconds);
#else
    usleep(llMilliSeconds * 1000);
#endif
  }
}


