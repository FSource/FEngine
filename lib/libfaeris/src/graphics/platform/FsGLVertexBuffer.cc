#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#if FS_PLATFORM_OS(FS_OS_OSX)
	#include "GL/glew.h"
#else 
	#include "GL/glew.h"
#endif 


#include "graphics/FsVertexBuffer.h"

NS_FS_BEGIN


static int S_VertexTarget_To_GL(int v)
{
	switch(v)
	{
		case VertexBuffer::TARGET_ARRAY:
			return GL_ARRAY_BUFFER;

		case VertexBuffer::TARGET_ELEMENT:
			return GL_ELEMENT_ARRAY_BUFFER;

		default:
			FS_TRACE_ERROR("Unkown Target Type");
	}

	return 0;
}

static int S_VertexUsage_To_GL(int v)
{
	switch(v)
	{
		case VertexBuffer::USAGE_DYNAMIC:
			return GL_DYNAMIC_DRAW;
		case VertexBuffer::USAGE_STATIC:
			return GL_STATIC_DRAW;
		case VertexBuffer::USAGE_STREAM:
			return GL_STREAM_DRAW;
		default:
			FS_TRACE_ERROR("Unkown Usage Type");
	}

	return 0;
}




VertexBuffer::VertexBuffer()
	:m_cacheInGpu(false),
	m_target(TARGET_ARRAY),
	m_usage(USAGE_DYNAMIC),
	m_gpuVBO(-1),
	m_dirty(true)
{ }



VertexBuffer::~VertexBuffer()
{
	if(m_gpuVBO>0)
	{
		GLuint vbo=m_gpuVBO;

		glDeleteBuffers(1,&vbo);

		m_gpuVBO=-1;
	}
}





void VertexBuffer::updateBufferInGpu()
{
	if(!m_cacheInGpu||m_gpuVBO==0)
	{
		return;
	}

	if(!m_dirty)
	{
		return;
	}

	if(m_gpuVBO==-1)
	{
		GLuint vbo=0;
		glGenBuffers(1,&vbo);
		m_gpuVBO=vbo;
	}

	if(!(m_gpuVBO>0))
	{
		m_gpuVBO=0;
		return;
	}


	int size=getItemNu()*getItemSize();
	void* data=getBufferData();

	glBindBuffer(S_VertexTarget_To_GL(m_target),m_gpuVBO);
	glBufferData(S_VertexTarget_To_GL(m_target),size,data,S_VertexUsage_To_GL(m_usage));
	glBindBuffer(S_VertexTarget_To_GL(m_target),0);

}


NS_FS_END







