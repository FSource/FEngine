#include "FsConfig.h"
#include "sys/FsSys.h"

#include "support/util/FsString.h"
#include "support/util/FsDict.h"

NS_FS_BEGIN

FsDict* Sys::m_env=NULL;
char Sys::m_tempBuf[FS_SYS_TEMP_BUF_SIZE];
const char* Sys::getEnv(const char* key)
{
	if(m_env==NULL) return NULL;

	FsString* ret=(FsString*)m_env->lookup(key);
	if(ret)
	{
		return ret->cstr();
	}
	return NULL;

}
void Sys::setEnv(const char* key,const char* value)
{
	if(key==NULL||value==NULL) return ;
	if(m_env==NULL)
	{
		m_env=FsDict::create();
	}
	FsString* t_key=FsString::create(key);
	FsString* t_value=FsString::create(value);
	m_env->insert(t_key,t_value);
}

NS_FS_END 



#if FS_PLATFORM_OS(FS_OS_LINUX)  ||  FS_PLATFORM_OS(FS_OS_OSX)
	#include "platform/linux/FsSysLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/android/FsSysAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/win32/FsSysWin32.cc"

#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

