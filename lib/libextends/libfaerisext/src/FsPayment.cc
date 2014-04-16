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


NS_FS_BEGIN

static Payment* S_Payment=NULL;

void FsPayment_SetGlobal(Payment* ment)
{
	FS_SAFE_ASSIGN(S_Payment,ment);
}

Payment* FsPayment_GetGlobal()
{
	return S_Payment;
}

void FsPayment_DropGlobal()
{
	FS_SAFE_DEC_REF(S_Payment);
	S_Payment=NULL;
}

NS_FS_END



