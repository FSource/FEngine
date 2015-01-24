/*************************************************************************/
/*  FsGLFrameBuffer.h                                                    */
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


#ifndef _FS_GL_FRAME_BUFFER_H_
#define _FS_GL_FRAME_BUFFER_H_

#include "graphics/FsTexture2D.h"

NS_FS_BEGIN



class FrameBuffer:public RenderTarget 
{
	public:
		static FrameBuffer* create(int width,int height);

	public:
		/* inherit RenderTarget */
		virtual void swapBuffers();
		virtual void makeCurrent(RenderDevice* render);
		virtual void loseCurrent(RenderDevice* render);

		/* inherit FsObject */
		virtual const char*  className();

	public:
		Texture2D* getColorTexture();

		int getWidth(){return m_width;}
		int getHeight(){return m_height;}

		void setSize(int width,int height);

	protected:
		FrameBuffer();
		virtual ~FrameBuffer();

		bool init(int width,int height);
		void destruct();


	private:
		Texture2D* m_colorTexture;
		uint32_t m_fboId;

		uint32_t m_depthBuffer;
		uint32_t m_stencilBuffer;

		int m_width;
		int m_height;
};

NS_FS_END


#endif /*_FS_GL_FRAME_BUFFER_H_*/

