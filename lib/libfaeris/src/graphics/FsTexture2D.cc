#include "graphics/FsTexture2D.h"


#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE)
	#include "platform/FsGLTexture2D.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 

