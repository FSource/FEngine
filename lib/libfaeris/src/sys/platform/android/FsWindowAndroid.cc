#include "sys/FsWindow.h"
#include "GL_Android/gles_2.0.h"
#include "graphics/FsRender.h"

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


void Window::makeCurrent(Render* r)
{

	glBindFramebuffer(GL_FRAMEBUFFER,0);
	r->setViewport(0,0,m_window->m_width,m_window->m_height);

	/*TODO*/
	m_render=r;
}

void Window::loseCurrent(Render* r)
{
	m_render=NULL;
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
	if(m_render)
	{
		m_render->setViewport(0,0,width,height);
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





















