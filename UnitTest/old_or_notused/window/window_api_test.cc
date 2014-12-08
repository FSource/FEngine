#include "fsys/FsWindow.h"
#include "fsys/FsFrame.h"
#include "graphics/FsRender.h"
#include "fsys/FsEventListener.h"
#include "fsys/FsEventDispatcher.h"
#include<stdio.h>
#include <string>
#include "GL/glew.h"


using namespace Faeris;


class WinListener:public EventListener
{
	public:
		virtual void onFocus(FocusEvent* e)
		{
			if(e->focus)
			{
				printf("FocusIn\n");
			}
			else 
			{
				printf("FocusOut\n");
			}
		}

		virtual void onKey(KeyEvent* e)
		{
			printf("key event\n");
		}
		virtual void onResize(ResizeEvent* e)
		{
			printf("window resize(%d,%d)\n",e->width,e->height);
		}
		virtual void onMotion(MotionEvent* e)
		{
			printf("mouse motion (%d,%d) \n",e->x,e->y);
		}
		virtual void onMouse(MouseEvent* e)
		{
			if(e->button==FS_LBUTTON)
			{
				printf("Left Button");
			}
			else if(e->button==FS_MBUTTON)
			{
				printf("Middle Button");
			}
			else if(e->button==FS_RBUTTON)
			{
				printf("Right Button");
			}
			else 
			{
				printf("unkown Button");
			}
			printf("(%d,%d)",e->x,e->y);
			printf(":");
			if(e->state==FS_DOWN)
			{
				printf("Down");
			}
			else if(e->state==FS_UP)
			{
				printf("Up");
			}
			printf("\n");
		}
};
class MyFrameListener:public FrameListener 
{
	public:
		MyFrameListener()
		{
			m_time=0;
		}

	public:
		virtual void frameUpdate(FsLong diff)
		{
			m_time++;
			printf("my frame update (%d), avgFps=%d\n",m_time,Frame::shareFrame()->getAvgFPS());
			Render::shareRender()->clear(true);
			Render::shareRender()->swapBuffers();
		}
	private:
		FsInt m_time;
};


int main()
{
	
	Window* win=Window::shareWindow();
	printf("win address %lx\n",(long)win);
	WinListener* listener=new WinListener;
	EventDispatcher::shareEventDispatcher()->addEventListener(listener);
	if(win==NULL)
	{
		printf("Create Win Error\n");
		return 0;
	}
	Render* render=Render::shareRender();

	win->show();
	win->setSize(1024,800);
	win->setCaption("Faeris.V1.0.1");
	win->setPosition(600,200);


	
	render->setRenderTarget(win);

	render->setClearColor(Color(255,0,0));
	render->clear(true);
	render->swapBuffers();


	MyFrameListener* framelistener=new MyFrameListener();
	Frame::shareFrame()->addListener(framelistener);
	Frame::shareFrame()->setFPS(40);
	Frame::shareFrame()->start();
	//render->setRenderTarget(NULL);


	Window::purgeShareWindow();

	delete listener;
	delete framelistener;
	printf("exit\n");



	return 0;

}


