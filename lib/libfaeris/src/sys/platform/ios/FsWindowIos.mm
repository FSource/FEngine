#include "sys/FsWindow.h"
#include "GL_IOS/gl_ios_es.h"
#include "graphics/FsRenderDevice.h"






NS_FS_BEGIN 

Window* Window::create()
{
	Window* ret=new Window();
	ret->init();

	return ret;
}


void Window::makeCurrent(RenderDevice* r)
{

	/*
	glBindFramebuffer(GL_FRAMEBUFFER,0);
	r->setViewport(0,0,m_window->m_width,m_window->m_height);

	m_renderDevice=r;
	*/
}


void Window::loseCurrent(RenderDevice* r)
{
	/*
	m_renderDevice=NULL;
	*/
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
	/*
	m_window->m_width=width;
	m_window->m_height=height;
	if(m_renderDevice)
	{
		m_renderDevice->setViewport(0,0,width,height);
	}
	*/
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
	//return m_window->m_width;
    return 0;
}

int Window::getHeight()
{
	//return m_window->m_height;
    return 0;
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
	//m_window=new PlatformWindow();
    return true;
}


NS_FS_END 

