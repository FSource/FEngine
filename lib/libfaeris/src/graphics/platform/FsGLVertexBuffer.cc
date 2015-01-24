/*************************************************************************/
/*  FsGLVertexBuffer.cc                                                  */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#elif FS_PLATFORM_OS(FS_OS_OSX)
	#include "GL/glew.h"
#elif FS_PLATFORM_OS(FS_OS_IOS)
    #include "GL_IOS/gl_ios_es.h"
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







