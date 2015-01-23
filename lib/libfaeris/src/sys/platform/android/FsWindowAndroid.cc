/*************************************************************************/
/*  FsWindowAndroid.cc                                                   */
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


#include "sys/FsWindow.h"
#include "GL_Android/gles_2.0.h"
#include "graphics/FsRenderDevice.h"

NS_FS_BEGIN

class PlatformWindow
{
	public:
		PlatformWindow()
		{
			m_width=0;
			m_height=0;
		}

	public:
		uint m_width;
		uint m_height;


};

Window* Window::create()
{
	static bool window_exist=false;
	if(window_exist)
	{
		FS_TRACE_WARN("Only One Window Can Exist");
		return NULL;
	}
	window_exist=true;
	Window* ret=new Window();
	ret->init();

	return ret;
}


void Window::makeCurrent(RenderDevice* r)
{

	glBindFramebuffer(GL_FRAMEBUFFER,0);
	r->setViewport(0,0,m_window->m_width,m_window->m_height);

	/*TODO*/
	m_renderDevice=r;
}

void Window::loseCurrent(RenderDevice* r)
{
	m_renderDevice=NULL;
	/* TODO */
}

void Window::swapBuffers()
{
	/* TODO */
}

void Window::setCaption(const char* name)
{
	/* TODO */
}

void Window::setPosition(int x,int y)
{
	/* TODO */
}

void Window::setSize(uint width,uint height)
{
	sizeChanged(width,height);
}


void Window::sizeChanged(uint width,uint height)
{
	m_window->m_width=width;
	m_window->m_height=height;
	if(m_renderDevice)
	{
		m_renderDevice->setViewport(0,0,width,height);
	}
	/* TODO */
}


void Window::show()
{
	/* TODO */
}

void Window::hide()
{
	/* TODO */
}

void Window::setStyle(long flags)
{
	/* TODO */
}

void Window::setFullScreen(bool full) 
{
	/* TODO */
}


int  Window::getWidth()
{
	return m_window->m_width;
}

int Window::getHeight()
{
	return m_window->m_height;
}




int Window::getPosX()
{
	return 0;
}

int Window::getPosY()
{
	return 0;
}

void Window::setCenter()
{
	/* TODO */
}


Window::~Window()
{
}

bool Window::init()
{
	m_window=new PlatformWindow();
}


NS_FS_END 





















