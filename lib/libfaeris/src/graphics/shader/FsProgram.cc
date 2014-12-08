#include "FsProgram.h"
#include "graphics/FsRenderDevice.h"

#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE) 
	#include "graphics/platform/FsGLProgram.cc"
#else 
	#error "Unsupport PlatformProgram"
#endif 






