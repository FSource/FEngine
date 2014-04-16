#include "FsGpsProvider.h" 


#if FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/FsGpsProviderWin32.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "platform/FsGpsProviderAndroid.cc"

#else
	#error "Unkown Platform For GpsProvider"

#endif 





