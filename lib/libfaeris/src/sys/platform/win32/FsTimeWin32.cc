#include <Windows.h>

#include "sys/FsTimer.h"

NS_FS_BEGIN 
Timer::Timer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_begin.count);
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_begin.frequency);
}
void Timer::reset()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_begin.count);
}

float Timer::now() const 
{
	__int64 current;
	QueryPerformanceCounter((LARGE_INTEGER*)&current);
	return  float(current-m_begin.count)/float(m_begin.frequency)*1000.0f;
}

NS_FS_END 

