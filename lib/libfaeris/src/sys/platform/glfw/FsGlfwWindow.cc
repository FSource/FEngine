#include "GL/glew.h"

#include <GLFW/glfw3.h>

#include "FsMacros.h"
#include "sys/FsWindow.h"


#include "FsGlobal.h"
#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsScheduler.h"
#include "sys/event/FsTouchDispatcher.h"


NS_FS_BEGIN
class PlatformWindow;

class EventGraper:public SchedulerTarget
{
	public:
		static EventGraper* create(PlatformWindow* win);

	public:
		/* inherit SchedulerTarget */
		virtual void update(int priority,float dt);

	protected:
		EventGraper();
	private:
		PlatformWindow* m_window;
};

EventGraper::EventGraper()
{
	m_window=NULL;
}


EventGraper* EventGraper::create(PlatformWindow* win)
{
	EventGraper* ret=new EventGraper;
	ret->m_window=win;
	return ret;
}

void EventGraper::update(int priority,float dt)
{
	glfwPollEvents();
}



class PlatformWindow 
{
	public:
		static void sizeChanged(GLFWwindow* glfw_window, int w, int h)
		{
			Window* window=Global::window();
			if (window)
			{
				FS_TRACE_WARN("sizeChanged(%d,%d)",w,h);
				window->sizeChanged(w,h);
			}
		}
		static void mouseMoved(GLFWwindow* window, double x, double y)
		{
			float fx=x;
			float fy=y;
			FS_TRACE_WARN("mouseMoved(%f,%f)",fx,fy);
		}

	public:
		static PlatformWindow* create()
		{
			PlatformWindow* ret=new PlatformWindow();
			if(!ret->init())
			{
				delete ret;
				return NULL;
			}
			return ret;
		}

	public:
		PlatformWindow()
		{
			m_window=NULL;
			m_eventGrap=NULL;
			m_width=0;
			m_height=0;
		}


		~PlatformWindow()
		{
			if(m_window)
			{
				glfwTerminate();
			}

			if(m_eventGrap)
			{
				Global::scheduler()->remove(m_eventGrap,Scheduler::HIGHEST);
			}
		}

	protected:
		bool init()
		{
			/* glfw init */
			if(!glfwInit())
			{
				FS_TRACE_WARN("glfwInit Failed");
				return false;
			}
			m_window = glfwCreateWindow(960, 640, "FSource Game Engine", NULL, NULL);
			m_width=960;
			m_height=640;
			

			glfwSetFramebufferSizeCallback(m_window,PlatformWindow::sizeChanged);
			glfwSetCursorPosCallback(m_window,PlatformWindow::mouseMoved);

			glfwMakeContextCurrent(m_window);

			/* check opengl version */

			const GLubyte* gl_version=glGetString(GL_VERSION);
			FsUtil_Log("OpenGL Version=%s",gl_version);
			if(atof((char*)gl_version)<1.5)
			{
				char str_compain[256]={0};
				sprintf(str_compain,"OpenGL 1.5 or higher is required(your version is %s), \
						please upgrade the driver of your video card",gl_version);
				FsUtil_Log("%s",str_compain);
				return false;
			}

			/* glew init */
			GLenum ret=glewInit();
			if(ret!=GLEW_OK)
			{
				FS_TRACE_WARN("Init Glew Failed %s",glewGetErrorString(ret));
				return false;
			}

			/* event grapper init */
			m_eventGrap=EventGraper::create(this);
			Global::scheduler()->add(m_eventGrap,Scheduler::HIGHEST);
			return true;
		}


	public:
		GLFWwindow* m_window;
		EventGraper* m_eventGrap;
		int m_width;
		int m_height;

};





/*  ------------------- Window --------------- */


Window* Window::create()
{
	PlatformWindow* plt_window=PlatformWindow::create();
	if(plt_window==NULL)
	{
		return NULL;
	}
	Window* ret=new Window;
	ret->m_window=plt_window;
	return ret;
}

void Window::makeCurrent(RenderDevice* r)
{
	if(m_window)
	{
		glBindFramebuffer(GL_FRAMEBUFFER,0);
	}

	m_renderDevice=r;
	r->setViewport(0,0,getWidth(),getHeight());
}

void Window::loseCurrent(RenderDevice* r)
{
	if(m_window)
	{
		//wglMakeCurrent(NULL,m_window->hrc);
	}
	m_renderDevice=NULL;
}

void Window::swapBuffers()
{
	if(m_window)
	{
		glfwSwapBuffers(m_window->m_window);
	}
}

void Window::setCaption(const char* name)
{

}

void Window::setPosition(int x,int y)
{
}

void Window::setSize(uint width,uint height)
{

}


void Window::sizeChanged(uint width,uint height)
{
	if(m_renderDevice)
	{
		m_renderDevice->setViewport(0,0,width,height);
	}
	if(m_window)
	{
		m_window->m_width=width;
		m_window->m_height=height;
	}

}


void Window::show()
{

}

void Window::hide()
{
}

void Window::setStyle(long flags)
{
}

void Window::setFullScreen(bool full)
{
}

int Window::getWidth() 
{
	if(m_window)
	{
		return m_window->m_width;
	}
	return 0;
}

int Window::getHeight()
{
	if(m_window)
	{
		return m_window->m_height;
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


Window::~Window()
{
	if(m_renderDevice)
	{
		m_renderDevice->setRenderTarget(NULL);
		m_renderDevice=NULL;
	}
	delete m_window;
	m_window=NULL;
}

bool Window::init()
{
	return true;
}


NS_FS_END
