#include "FsVertexBuffer.h"

NS_FS_BEGIN

const char* VertexBuffer::className()
{
	return "VertexBuffer";
}



NS_FS_END


#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE)
	#include "platform/FsGLVertexBuffer.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 





