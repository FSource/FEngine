#include "sys/FsWindow.h"
#include "GL_IOS/gl_ios_es.h"
#include "graphics/FsRenderDevice.h"

#import "FsAppDelegate.h"
#import "FsGLESView.h"





NS_FS_BEGIN

class PlatformWindow
{
    public:
        static PlatformWindow* create()
        {
            return new PlatformWindow;
        }
    
    public:
        PlatformWindow()
        {
            m_glesView=nil;
        }
    public:
        FsGLESView* m_glesView;
};

Window* Window::create()
{

	Window* ret=new Window();
	ret->init();

	return ret;
}


void Window::makeCurrent(RenderDevice* r)
{



	glBindFramebuffer(GL_FRAMEBUFFER,[m_window->m_glesView getFrameBuffer]);
  	glBindRenderbuffer(GL_RENDERBUFFER,[m_window->m_glesView getColorRenderBuffer]);
    
	int width=[m_window->m_glesView getWidth];
	int height=[m_window->m_glesView getHeight];


	r->setViewport(0,0,width,height);
	m_renderDevice=r;

}


void Window::loseCurrent(RenderDevice* r)
{
	m_renderDevice=NULL;
}


void Window::swapBuffers()
{
    [m_window->m_glesView swapBuffers];
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
	if(m_renderDevice)
	{
		m_renderDevice->setViewport(0,0,width,height);
	}
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
	if(m_window)
	{
		return [m_window->m_glesView getWidth];
	}
    return 0;
}

int Window::getHeight()
{
	if(m_window)
	{
		return [m_window->m_glesView getHeight];
	}
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
	FsAppDelegate* delegate=[FsAppDelegate getShareAppDelegate];
    m_window=PlatformWindow::create();
    m_window->m_glesView=[delegate getGlesView];
    [m_window->m_glesView setFsWindow:this];
    
    return true;
}


NS_FS_END 

