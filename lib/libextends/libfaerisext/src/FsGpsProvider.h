#ifndef _FS_PGS_PROVIDER_H_
#define _FS_PGS_PROVIDER_H_

#include "FsMacros.h"
#include "FsObject.h"

#if FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/fake/FsGpsProviderFake.h"

#elif FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/fake/FsGpsProviderFake.h"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsGpsProviderAndroid.h"

#else 
	#error "Unkown Platform For GpsProvider"
#endif 


#endif /*_FS_PGS_PROVIDER_H_*/


