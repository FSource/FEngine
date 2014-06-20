#include "FsGpsProvider.h" 


#if FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/fake/FsGpsProviderFake.cc"

#elif FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/fake/FsGpsProviderFake.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "platform/android/FsGpsProviderAndroid.cc"

#else
	#error "Unkown Platform For GpsProvider"

#endif 





