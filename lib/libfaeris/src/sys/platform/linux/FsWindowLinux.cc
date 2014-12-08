#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include "GL/glew.h"

#include <GL/glx.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "support/util/FsLog.h"
#include "sys/FsWindow.h"

#include "FsGlobal.h"
#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsScheduler.h"
#include "sys/event/FsTouchDispatcher.h"

#define FS_XWINDOW_EVENT_MASK ( \
		ExposureMask \
		|KeyPressMask \
		|ButtonPressMask \
		|ButtonReleaseMask \
		|ButtonMotionMask \
		|StructureNotifyMask \
		|PointerMotionMask \
		|FocusChangeMask \
		)

NS_FS_BEGIN
typedef ::Window XWindow;

#if 0
static const char *event_names[] = {
   "",
   "",
   "KeyPress",
   "KeyRelease",
   "ButtonPress",
   "ButtonRelease",
   "MotionNotify",
   "EnterNotify",
   "LeaveNotify",
   "FocusIn",
   "FocusOut",
   "KeymapNotify",
   "Expose",
   "GraphicsExpose",
   "NoExpose",
   "VisibilityNotify",
   "CreateNotify",
   "DestroyNotify",
   "UnmapNotify",
   "MapNotify",
   "MapRequest",
   "ReparentNotify",
   "ConfigureNotify",
   "ConfigureRequest",
   "GravityNotify",
   "ResizeRequest",
   "CirculateNotify",
   "CirculateRequest",
   "PropertyNotify",
   "SelectionClear",
   "SelectionRequest",
   "SelectionNotify",
   "ColormapNotify",
   "ClientMessage",
   "MappingNotify"
};
#endif 


class EventGraper;
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
		bool pointInView(float x,float y);
		void transformViewPoint(float* x,float* y);
		void handleEvent(XEvent* event);

	private:
		PlatformWindow* m_window;
};


class PlatformWindow
{
	public:
		XWindow m_X11Window;
		Display* m_dpy;
		GLXContext m_contex;
		Atom m_delete_msg;
		XVisualInfo* m_vi;
		
	protected:
		bool initWin();
		bool initGL();
	public:
		static PlatformWindow* create();
		PlatformWindow();
		~PlatformWindow();
	private:
		EventGraper* m_eventGrap;
};

PlatformWindow::PlatformWindow()
{
	m_X11Window=0;
	m_dpy=NULL;
	m_contex=NULL;
	m_delete_msg=0;
	m_eventGrap=EventGraper::create(this);
	FS_NO_REF_DESTROY(m_eventGrap);
	Global::scheduler()->add(m_eventGrap,Scheduler::HIGHEST);
}
PlatformWindow::~PlatformWindow()
{
	glXDestroyContext(m_dpy,m_contex);
	XDestroyWindow(m_dpy,m_X11Window);
	XCloseDisplay(m_dpy);
	XFree(m_vi);
	Global::scheduler()->remove(m_eventGrap,Scheduler::HIGHEST);
	FS_DESTROY(m_eventGrap);
}

PlatformWindow* PlatformWindow::create()
{
	PlatformWindow* ret=new PlatformWindow();
	if(!ret->initWin())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

bool PlatformWindow::initWin()
{
	m_dpy=XOpenDisplay(NULL);
	if(!m_dpy)
	{
		FS_TRACE_WARN("Can't Connect to x Server ");
		return false;
	}
	m_delete_msg=XInternAtom(m_dpy,"WM_DELETE_WINDOW",False);

	GLint attr[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
	XWindow root;

	XSetWindowAttributes swa;

	root=DefaultRootWindow(m_dpy);
	m_vi=glXChooseVisual(m_dpy,0,attr);
	if(m_vi==NULL)
	{
		FS_TRACE_WARN("No Appropriate Visual Found");
		return false;
	}
	Colormap cmap=XCreateColormap(m_dpy,root,m_vi->visual,AllocNone);
	swa.colormap=cmap;
	swa.event_mask=FS_XWINDOW_EVENT_MASK;
	m_X11Window=XCreateWindow(
			m_dpy,
			root,
			0,0,600,600,
			0,m_vi->depth,
			InputOutput,
			m_vi->visual,
			CWColormap|CWEventMask,&swa);

	XMapWindow(m_dpy,m_X11Window);
	XSetWMProtocols(m_dpy, m_X11Window, &m_delete_msg, 1);

	if(!initGL())
	{
		return false;
	}

	XSync(m_dpy,false);
	
	return true;
}

bool PlatformWindow::initGL()
{
	m_contex=glXCreateContext(m_dpy,m_vi,NULL,GL_TRUE);
	glXMakeCurrent(m_dpy,m_X11Window,m_contex);
	const GLubyte* gl_version=glGetString(GL_VERSION);
	GLenum ret=glewInit();
	FsUtil_Log("OpenGL Version=%s",gl_version);
	if(atof((char*)gl_version)<1.5)
	{
		char str_compain[256]={0};
		sprintf(str_compain,"OpenGL 1.5 or higher is required(your version is %s), \
				please upgrade the driver of your video card",gl_version);
		FsUtil_Log("%s",str_compain);
		return false;
	}
	if(ret!=GLEW_OK)
	{
		FsUtil_Log("Init Glew Failed %s",glewGetErrorString(ret));
		return false;
	}
	return true;
}


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

	if(!m_window)
	{
		return ;
	}
	Display* dpy=m_window->m_dpy;
	XEvent event;
	XSync(dpy,False);
	while(XEventsQueued(dpy,QueuedAfterReading))
	{
		XNextEvent(dpy,&event);
		handleEvent(&event);
	}
}


bool EventGraper::pointInView(float x,float y)
{
	if(x>=0&&x<=1.0f)
	{
		if(y>=0&&y<=1.0f)
		{
			return true;
		}
	}
	return false;
}

void EventGraper::transformViewPoint(float* x,float* y)
{
	int vx,vy;
	uint width,height;
	uint border;
	uint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&vx,&vy,&width,&height,&border,&depth);

	*x=*x/width;
	*y=*y/height;
	*y=1.0f-*y;
}


void EventGraper::handleEvent(XEvent* src_event)
{
	PlatformWindow* plt_window=m_window;
	if(!plt_window)
	{
		return ;
	}


	switch(src_event->type)
	{
		case ClientMessage:
			{
				if((Atom)(src_event->xclient.data.l[0])==plt_window->m_delete_msg)
				{
					Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::QUIT));
				}
				break;
			}
		case ConfigureNotify:
			{
				uint width,height;
				width=src_event->xconfigure.width;
				height=src_event->xconfigure.height;
				Render* render=Global::render();
				if(render)
				{
					render->setViewport(0,0,width,height);
				}
			//	FS_TRACE_WARN("Resize: width=%d,height=%d",width,height);
				break;
			}
		case ButtonPress:
			{
				XButtonEvent* e=(XButtonEvent*) src_event;
				if(e->button==Button1)
				{
					float x=e->x;
					float y=e->y;
					transformViewPoint(&x,&y);
					TouchPoint p(0,x,y);
					Global::touchDispatcher()->dispatchEvent(
							new TouchEvent(TouchDispatcher::TOUCHES_BEGIN,1,&p));
				}
				break;
			}
		case ButtonRelease:
			{
				XButtonEvent* e=(XButtonEvent*) src_event;
				if(e->button==Button1)
				{
					float x=e->x;
					float y=e->y;
					transformViewPoint(&x,&y);
					TouchPoint p(0,x,y);
					Global::touchDispatcher()->dispatchEvent(
							new TouchEvent(TouchDispatcher::TOUCHES_END,1,&p));
				}
				break;
			}
		case MotionNotify:
			{
				XMotionEvent* e=(XMotionEvent*) src_event;
				uint xmask=e->state;
				if(xmask&Button1Mask) 
				{
					float x=e->x;
					float y=e->y;
					transformViewPoint(&x,&y);
					TouchPoint p(0,x,y);
					Global::touchDispatcher()->dispatchEvent(
							new TouchEvent(TouchDispatcher::TOUCHES_MOVE,1,&p));
				}
				break;
			}
		case FocusIn:
			{
				Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::FOREGROUND));
				break;
			}
		case FocusOut:
			{
				Global::sysDispatcher()->dispatchEvent(new SysEvent(SysDispatcher::BACKGROUND));
				break;
			}
		case DestroyNotify:
			{
				Global::scheduler()->stop();
				break;
			}

		case KeyPress:
			/*TODO*/
			break;
		default:
			//FS_TRACE_WARN("Unkown XEvent(%s)",event_names[src_event->type]);
			break;
	}
}



Window* Window::create()
{
	PlatformWindow* plt_window=PlatformWindow::create();
	if(!plt_window)
	{
		FS_TRACE_WARN("Create PlatformWindow Failed");
		return NULL;
	}
	Window* ret=new Window;
	ret->m_window=plt_window;
	return ret;
}


void Window::setCaption(const char* name)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XStoreName(m_window->m_dpy,m_window->m_X11Window,name);
	m_caption=std::string(name);
	XSync(m_window->m_dpy,False);
}

void Window::setPosition(int x,int y)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XMoveWindow(m_window->m_dpy,m_window->m_X11Window,x,y);
	XSync(m_window->m_dpy,False);
}

void Window::setSize(uint width,uint height)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XResizeWindow(m_window->m_dpy,m_window->m_X11Window,width,height);
	XSync(m_window->m_dpy,False);
}

void Window::show()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XMapWindow(m_window->m_dpy,m_window->m_X11Window);
	XSync(m_window->m_dpy,False);

}
void Window::hide()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XUnmapWindow(m_window->m_dpy,m_window->m_X11Window);
	XSync(m_window->m_dpy,False);
}

void Window::setStyle(long flags)
{
}
void Window::setFullScreen(bool full)
{
}

int Window::getWidth()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	int x,y;
	uint width,height;
	uint border;
	uint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
int Window::getHeight()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	int x,y;
	uint width,height;
	uint border;
	uint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
int Window::getPosX()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	int x,y;
	uint width,height;
	uint border;
	uint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return x;
}
int Window::getPosY()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	int x,y;
	uint width,height;
	uint border;
	uint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return y;
}


void Window::makeCurrent(Render* r)
{
	if(m_window)
	{
		glXMakeCurrent(m_window->m_dpy,m_window->m_X11Window,m_window->m_contex);
		XSync(m_window->m_dpy,False);
	}
	m_render=r;
}

void Window::loseCurrent(Render* r)
{
	if(m_window)
	{
		//glXMakeCurrent(m_window->m_dpy,None,m_window->m_contex);
	}
	m_render=NULL;
}

void Window::swapBuffers()
{
	if(m_window)
	{
		glXSwapBuffers(m_window->m_dpy,m_window->m_X11Window);
	}
}
Window::~Window()
{
	if(m_render)
	{
		m_render->setRenderTarget(NULL);
		m_render=NULL;
	}
	delete m_window;
	m_window=NULL;

}

NS_FS_END

















