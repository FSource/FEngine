#include "graphics/FsRenderDevice.h"

#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE)
	#include "platform/FsESRenderDevice.cc"
#else 
	#error "UnSupport Render"
#endif 


