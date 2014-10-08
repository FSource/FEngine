#include "FsVertexBuffer.h"

NS_FS_BEGIN

const char* VertexBuffer::className()
{
	return "VertexBuffer";
}



NS_FS_END


#if FS_CONFIG(FS_GL_RENDER)||FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsGLVertexBuffer.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 





