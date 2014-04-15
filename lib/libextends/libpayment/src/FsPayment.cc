#include "FsPayment.h"


#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/fake/FsPaymentFake.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/fake/FsPaymentFake.cc"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsPaymentAndroid.cc"
#else 
	#error "unsupport platform"
#endif 



