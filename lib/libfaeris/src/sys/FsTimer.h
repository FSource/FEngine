#ifndef _FAERY_TIMER_H_
#define _FAERY_TIMER_H_ 
#include "FsMacros.h"
#include "FsConfig.h"

#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_ANDROID) || FS_PLATFORM_OS(FS_OS_OSX) || FS_PLATFORM_OS(FS_OS_IOS)
	#include <sys/time.h>
	typedef struct timeval PlatformTimeVal;
#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include <Windows.h>
	struct  PlatformTimeVal
	{
		__int64 count;
		__int64 frequency;
	};
#else 
	#error "Unsupport Platform OS"
#endif 


NS_FS_BEGIN


class Timer
{
	public:
		Timer();
		void reset();
		float now() const ;
	private:
		PlatformTimeVal m_begin;
};

NS_FS_END

#endif /*_FAERY_TIMER_H_*/

