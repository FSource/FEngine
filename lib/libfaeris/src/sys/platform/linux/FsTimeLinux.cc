#include "sys/FsTimer.h"
#include <sys/time.h>

NS_FS_BEGIN
Timer::Timer()
{
	gettimeofday(&m_begin,NULL);
}
void Timer::reset()
{
	gettimeofday(&m_begin,NULL);
}
float Timer::now() const
{
	struct timeval cur;
	gettimeofday(&cur,NULL);
	return float(cur.tv_sec-m_begin.tv_sec)*1000.0f+float(cur.tv_usec-m_begin.tv_usec)/1000.0f;
}

NS_FS_END

