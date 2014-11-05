#include "FsMacros.h"

#include "FsFrameBuffer.h"

#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE) 
	#include "platform/FsGLFrameBuffer.cc"
#else 
	#error "Unsupport PlatformTexture" 
#endif 
