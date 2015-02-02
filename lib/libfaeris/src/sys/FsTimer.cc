#include "FsTimer.h"
 
#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_OSX) || FS_PLATFORM_OS(FS_OS_ANDROID) || FS_PLATFORM_OS(FS_OS_IOS) 
	#include "platform/linux/FsTimeLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/win32/FsTimeWin32.cc"
#else 
	#error "Unsupport Platform OS"
#endif 
