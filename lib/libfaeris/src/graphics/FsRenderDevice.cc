#include "graphics/FsRender.h"

#if FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsESRender.cc"
#elif FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLRender.cc"
#else 
	#error "UnSupport Render"
#endif 


