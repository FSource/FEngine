#include "graphics/FsRenderDevice.h"

#if FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsESRenderDevice.cc"
#elif FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLRenderDevice.cc"
#else 
	#error "UnSupport Render"
#endif 


