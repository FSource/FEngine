/*************************************************************************/
/*  FsGLFrameBuffer.cc                                                   */
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
#else 
	#include "GL/glew.h"
#endif 


#include "FsGLFrameBuffer.h"
#include "graphics/FsRenderDevice.h"

NS_FS_BEGIN


const char* FrameBuffer::className()
{
	return FS_FRAME_BUFFER_CLASS_NAME;
}


FrameBuffer* FrameBuffer::create(int width,int height)
{
	FrameBuffer* ret= new FrameBuffer();
	if(!ret->init(width,height)) 
	{
		delete ret;
		return NULL;
	}

	return ret;
}

FrameBuffer::FrameBuffer()
{
	m_colorTexture=NULL;
	m_fboId=0;
	m_depthBuffer=0;
	m_stencilBuffer=0;
	m_width=0;
	m_height=0;
}


FrameBuffer::~FrameBuffer()
{
	destruct();
}


bool FrameBuffer::init(int width,int height)
{
	GLenum  status;
	/* Create Frame Buffer Object */
	glGenFramebuffers(1,&m_fboId);

	/* Get Old Frame Buffer Object */
	int32_t old_fbo_id;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &old_fbo_id);

	/* Bind Frame Buffer */
	glBindFramebuffer(GL_FRAMEBUFFER,m_fboId);


	/* Color Buffer */
	m_colorTexture=Texture2D::create(E_PixelFormat::RGBA8888,width,height,NULL,
									E_TextureFilter::LINEAR,E_TextureFilter::LINEAR,
									E_TextureWrap::CLAMP_TO_EDGE,E_TextureWrap::CLAMP_TO_EDGE);
	if(!m_colorTexture)
	{
		FS_TRACE_WARN("Create Texture2D Failed");
		goto error;
	}

	glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,
							m_colorTexture->getPlatformTexture(),0);
	FS_SAFE_ADD_REF(m_colorTexture);


	/* Depth Bufffer */
	glGenRenderbuffers(1,&m_depthBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer); 


	/* Stencil Buffer */
	/*
	glGenRenderbuffers(1,&m_stencilBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, m_stencilBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_stencilBuffer); 
	*/



	status=glCheckFramebufferStatus(GL_FRAMEBUFFER);
	 
	if(status !=GL_FRAMEBUFFER_COMPLETE)
	{
		FS_TRACE_WARN("UNCOMPLETE FRAME BUFFER");
		goto error;
	}

	//FS_TRACE_WARN("Old FrameBuffer=%d,New FrameBuffer=%d",old_fbo_id,m_fboId);
	glBindFramebuffer(GL_FRAMEBUFFER,old_fbo_id);

	m_width=width;
	m_height=height;

	return true;

error:
	glBindFramebuffer(GL_FRAMEBUFFER,old_fbo_id);
	destruct();
	return false;
}


void FrameBuffer::setSize(int width,int height)
{
	int32_t old_fbo_id;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &old_fbo_id);

	/* Bind Frame Buffer */
	glBindFramebuffer(GL_FRAMEBUFFER,m_fboId);
	glBindRenderbuffer(GL_RENDERBUFFER,m_depthBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH_COMPONENT16,width,height);


	/* Color Buffer */
	glBindTexture(GL_TEXTURE_2D,m_colorTexture->getPlatformTexture());
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,NULL);


	/* restore */
	glBindFramebuffer(GL_FRAMEBUFFER,old_fbo_id);

	m_width=width;
	m_height=height;



}




void FrameBuffer::destruct()
{
	FS_SAFE_DEC_REF(m_colorTexture);
	if(m_fboId != 0)
	{
		glDeleteFramebuffers(1,&m_fboId);
	}

	if(m_depthBuffer !=0 )
	{
		glDeleteRenderbuffers(1,&m_depthBuffer);
	}


	if(m_stencilBuffer != 0)
	{
		glDeleteRenderbuffers(1,&m_stencilBuffer);
	}

}



Texture2D* FrameBuffer::getColorTexture()
{
	return m_colorTexture;
}


void FrameBuffer::swapBuffers()
{
}


void FrameBuffer::makeCurrent(RenderDevice* r)
{
	glBindFramebuffer(GL_FRAMEBUFFER,m_fboId);

	r->setViewport(0,0,m_width,m_height);

}

void FrameBuffer::loseCurrent(RenderDevice* r)
{
	//FS_TRACE_WARN("FrameBuffer,loseCurrent");
	glBindFramebuffer(GL_FRAMEBUFFER,0);
}













NS_FS_END


