#include "sys/FsWindow.h"
#include "graphics/FsRenderDevice.h"



NS_FS_BEGIN


Window::Window()
{
	m_renderDevice=NULL;
	m_window=NULL;
	m_caption=FS_DEFAULT_WINDOW_NAME;
}

const char* Window::className()
{
	return FS_WINDOW_CLASS_NAME;
}

NS_FS_END


#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/linux/FsWindowLinux.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/win32/FsWindowWin32.cc"
#else 
	#include "platform/android/FsWindowAndroid.cc"
#endif 

