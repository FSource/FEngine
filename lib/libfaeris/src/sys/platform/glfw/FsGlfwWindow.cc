/*************************************************************************/
/*  FsGlfwWindow.cc                                                      */
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


#include "GL/glew.h"

#include <GLFW/glfw3.h>

#include "FsMacros.h"
#include "sys/FsWindow.h"


#include "FsGlobal.h"
#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsScheduler.h"
#include "sys/event/FsTouchDispatcher.h"


#define FS_GLFW_DEFAULT_WINDOW_WIDTH 800
#define FS_GLFW_DEFAULT_WINDOW_HEIGHT 600


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

static bool s_mouse_capture=false;

class PlatformWindow 
{
	public:
		static void keyEvent(GLFWwindow* glfw_window,int key,int scancode,int action,int mods)
		{
			E_KeyCode code;
			if((key>=48&&key<=57)
				||(key>=65&&key<=90)
				)
			{
				code=static_cast<E_KeyCode>(key);
			}
			else if(key>=320&&key<=329)
			{
				code=static_cast<E_KeyCode>(key-320-(E_KeyCode::KEY_NUMPAD0));
			}
			else 
			{
				switch(key)
				{
					case  	GLFW_KEY_BACKSPACE:
						code=E_KeyCode::KEY_BACKSPACE;
						break;

					case  	GLFW_KEY_TAB :
						code=E_KeyCode::KEY_TAB;
						break;

					case  	GLFW_KEY_ENTER :
						code=E_KeyCode::KEY_RETURN;
						break;

					case  	GLFW_KEY_LEFT_SHIFT:
					case  	GLFW_KEY_RIGHT_SHIFT: 
						code=E_KeyCode::KEY_SHIFT;
						break;


					case  	GLFW_KEY_LEFT_CONTROL:
					case  	GLFW_KEY_RIGHT_CONTROL:
						code =E_KeyCode::KEY_CONTROL;
						break;

					case  	GLFW_KEY_MENU:
						code=E_KeyCode::KEY_MENU;
						break;

					case  	GLFW_KEY_ESCAPE:
						code =E_KeyCode::KEY_ESCAPE;
						break;

					case  	GLFW_KEY_SPACE:
						code =E_KeyCode::KEY_SPACE;
						break;
					case  	GLFW_KEY_LEFT:
						code =E_KeyCode::KEY_LEFT;
						break;

					case  	GLFW_KEY_UP: 
						code =E_KeyCode::KEY_UP;
						break;

					case  	GLFW_KEY_RIGHT: 
						code =E_KeyCode::KEY_RIGHT;
						break;

					case  	GLFW_KEY_DOWN: 
						code =E_KeyCode::KEY_DOWN;
						break;

					case  	GLFW_KEY_DELETE: 
						code=E_KeyCode::KEY_DELETE;
						break;

					case  	GLFW_KEY_KP_ADD: 
						code =E_KeyCode::KEY_ADD;
						break;

					case  	GLFW_KEY_KP_SUBTRACT:
						code =E_KeyCode::KEY_SUBTRACT;
						break;

					case  	GLFW_KEY_KP_DECIMAL:
						code =E_KeyCode::KEY_DECIMAL;
						break;

					case  	GLFW_KEY_KP_DIVIDE:
						code =E_KeyCode::KEY_DIVIDE;
						break;

					case  	GLFW_KEY_KP_MULTIPLY: 
						code =E_KeyCode::KEY_MULTIPLY;
						break;

					default:
						code =E_KeyCode::KEY_UNKOWN;
				}
			}

			if(action==GLFW_PRESS)
			{
				Global::keypadDispatcher()->dispatchEvent(new KeypadEvent(code,KeypadEvent::KEYPAD_DOWN));

			}
			else if (action==GLFW_RELEASE )
			{
				Global::keypadDispatcher()->dispatchEvent(new KeypadEvent(code,KeypadEvent::KEYPAD_UP));
			}
			else if (action==GLFW_REPEAT)
			{
				Global::keypadDispatcher()->dispatchEvent(new KeypadEvent(code,KeypadEvent::KEYPAD_REPEAT));
			}

		}

		static void sizeFrameBufferChanged(GLFWwindow* glfw_window, int w, int h)
		{
			if(h==0)
			{
				h=1;
			}

			PlatformWindow* plt_window=(PlatformWindow*)glfwGetWindowUserPointer(glfw_window);
			plt_window->m_frameWidth=w;
			plt_window->m_frameHeight=h;

			Window* window=Global::window();
			if (window)
			{
				//FS_TRACE_WARN("sizeChanged(%d,%d)",w,h);
				window->sizeChanged(w,h);
			}
		}

		static void sizeWindowChanged(GLFWwindow* glfw_window,int w,int h)
		{
			if(h==0)
			{
				h=1;
			}

			PlatformWindow* plt_window=(PlatformWindow*)glfwGetWindowUserPointer(glfw_window);
			plt_window->m_width=w;
			plt_window->m_height=h;

		}


		static void mouseMoved(GLFWwindow* window, double x, double y)
		{
			PlatformWindow* plt_window=(PlatformWindow*)glfwGetWindowUserPointer(window);
			plt_window->m_mouseX=(float)x;
			plt_window->m_mouseY=(float)y;


			if(!plt_window->m_mousePress)
			{
				return ;
			}


			float fx=(float) x;
			float fy=(float) y;
			plt_window->translateViewPoint(&fx,&fy);

			TouchPoint p(0,fx,fy);

			Global::touchDispatcher()->dispatchEvent(
					new TouchEvent(TouchDispatcher::TOUCHES_MOVE,1,&p));

		}

		static void windowClose(GLFWwindow* window)
		{
			Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::QUIT));
		}

		static void windowFocus(GLFWwindow* window,int focus)
		{
			if(focus)
			{

				Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::FOREGROUND));
			}
			else 
			{
				Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::BACKGROUND));
			}
		}

		static void mouseButton(GLFWwindow* window,int button,int action,int mods)
		{
			PlatformWindow* plt_window=(PlatformWindow*)glfwGetWindowUserPointer(window);

			if(button!=GLFW_MOUSE_BUTTON_LEFT)
			{
				return;
			}

			//FS_TRACE_WARN("action=%d",action);

			if(action==GLFW_PRESS)
			{
				float x=plt_window->m_mouseX;
				float y=plt_window->m_mouseY;
				plt_window->translateViewPoint(&x,&y);

				TouchPoint p(0,x,y);

				Global::touchDispatcher()->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_BEGIN,1,&p));
				plt_window->m_mousePress=true;

			}
			else if(action==GLFW_RELEASE)
			{
				if(plt_window->m_mousePress)
				{
					float x=plt_window->m_mouseX;
					float y=plt_window->m_mouseY;
					plt_window->translateViewPoint(&x,&y);

					TouchPoint p(0,x,y);

					Global::touchDispatcher()->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_END,1,&p));
					plt_window->m_mousePress=false;
				}
			}

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
			m_frameWidth=0;
			m_frameHeight=0;
			m_mousePress=false;
			m_mouseX=0;
			m_mouseY=0;

		}

		void translateViewPoint(float* x,float*y )
		{
			*x=*x/m_width;
			*y=*y/m_height;
			*y=1.0f-*y;
		}



		~PlatformWindow()
		{
			if(m_window)
			{
				glfwDestroyWindow(m_window);
				m_window=NULL;
			}

			glfwTerminate();

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

			/* set glfw hint */
			glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
			glfwWindowHint(GLFW_VISIBLE,GL_FALSE);
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT,GL_TRUE);
			//glfwWindowHint(GLFW_CLIENT_API,GLFW_OPENGL_ES_API);



			m_window = glfwCreateWindow(FS_GLFW_DEFAULT_WINDOW_WIDTH, FS_GLFW_DEFAULT_WINDOW_HEIGHT, "FSource Game Engine", NULL, NULL);

			if(m_window==NULL)
			{
				FS_TRACE_WARN("Create glfw Window Failed");
				return false;
			}


			m_width=FS_GLFW_DEFAULT_WINDOW_WIDTH;
			m_height=FS_GLFW_DEFAULT_WINDOW_HEIGHT;
			m_frameWidth=FS_GLFW_DEFAULT_WINDOW_WIDTH;
			m_frameHeight=FS_GLFW_DEFAULT_WINDOW_HEIGHT;


			glfwSetFramebufferSizeCallback(m_window,PlatformWindow::sizeFrameBufferChanged);
			glfwSetWindowSizeCallback(m_window,PlatformWindow::sizeWindowChanged);
			glfwSetCursorPosCallback(m_window,PlatformWindow::mouseMoved);
			glfwSetWindowCloseCallback(m_window,PlatformWindow::windowClose);
			glfwSetWindowFocusCallback(m_window,PlatformWindow::windowFocus);
			glfwSetMouseButtonCallback(m_window,PlatformWindow::mouseButton);
			glfwSetKeyCallback(m_window,PlatformWindow::keyEvent);

			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window,this);

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
		int m_frameWidth;
		int m_frameHeight;
		float m_mouseX;
		float m_mouseY;
		bool m_mousePress;
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
	if(m_window)
	{
		glfwSetWindowTitle(m_window->m_window,name);
		m_caption=name;
	}

}

void Window::setPosition(int x,int y)
{
	if(m_window)
	{
		glfwSetWindowPos(m_window->m_window,x,y);
	}
}

void Window::setSize(uint width,uint height)
{
	if(m_window)
	{
		glfwSetWindowSize(m_window->m_window,width,height);
	}
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
	if(m_window)
	{
		glfwShowWindow(m_window->m_window);
	}

}

void Window::hide()
{
	if(m_window)
	{
		glfwHideWindow(m_window->m_window);
	}
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
	int x=0;
	int y=0;
	if(m_window)
	{
		glfwGetWindowPos(m_window->m_window,&x,&y);
	}

	return x;
}

int Window::getPosY() 
{
	int x=0;
	int y=0;
	if(m_window)
	{
		glfwGetWindowPos(m_window->m_window,&x,&y);
	}
	return y;
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
