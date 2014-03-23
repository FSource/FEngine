#include "graphics/FsTexture2D.h"


#if FS_CONFIG(FS_GL_RENDER)||FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsGLTexture2D.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 

