#include "FsMacros.h"

#include "FsFrameBuffer.h"

#if FS_CONFIG(FS_GL_RENDER) || FS_CONFIG(FS_GLES_RENDER) 
	#include "platform/FsGLFrameBuffer.cc"
#else 
	#error "Unsupport PlatformTexture" 
#endif 
