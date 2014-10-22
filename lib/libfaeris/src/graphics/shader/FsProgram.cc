#include "FsProgram.h"
#include "graphics/FsRenderDevice.h"

#if FS_CONFIG(FS_GL_RENDER) || FS_CONFIG(FS_GLES_RENDER)
	#include "graphics/platform/FsGLProgram.cc"
#else 
	#error "Unsupport PlatformProgram"
#endif 




