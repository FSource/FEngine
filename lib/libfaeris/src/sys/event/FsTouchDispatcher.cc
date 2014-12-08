#include "sys/event/FsTouchDispatcher.h"
#include "FsGlobal.h"

NS_FS_BEGIN

/* touch event */
TouchEvent::TouchEvent(int type,int point_nu,TouchPoint* points)
{
	assert(point_nu>0);
	m_type=type;
	m_points=new TouchPoint[point_nu];

	for(int i=0;i<point_nu;i++)
	{
		m_points[i]=points[i];
	}
	m_count=point_nu;
}
TouchEvent::~TouchEvent()
{
	delete[] m_points;
	m_points=NULL;
}


TouchEventListener* TouchEventListener::create()
{
	return new TouchEventListener;
}

TouchEventListener::TouchEventListener() { }
TouchEventListener::~TouchEventListener() {} 

void TouchEventListener::onTouchEvent(TouchEvent* event)
{
	int type=event->getType();
	const TouchPoint* point=event->getPoints();
	int point_nu=event->getPointsNu();

	if(point_nu<=0)
	{
		FS_TRACE_WARN("Touches Pointer Number Is Zero");
		return;
	}

	float x=point->x;
	float y=point->y;

	switch(type)
	{
		case TouchDispatcher::TOUCHES_BEGIN:
			touchesBegin(event);
			touchBegin(x,y);
			break;
		case TouchDispatcher::TOUCHES_POINTER_DOWN:
			touchesPointerDown(event);
			break;
		case TouchDispatcher::TOUCHES_MOVE:
			touchesMove(event);
			touchMove(x,y);
			break;
		case TouchDispatcher::TOUCHES_POINTER_UP:
			touchesPointerUp(event);
			break;
		case TouchDispatcher::TOUCHES_END:
			touchesEnd(event);
			touchEnd(x,y);
			break;
	}
}

void TouchEventListener::touchBegin(float x,float y){}
void TouchEventListener::touchMove(float x,float y){}
void TouchEventListener::touchEnd(float x,float y){}

void TouchEventListener::touchesBegin(TouchEvent* event){}
void TouchEventListener::touchesPointerDown(TouchEvent* event){}
void TouchEventListener::touchesMove(TouchEvent* event){}
void TouchEventListener::touchesPointerUp(TouchEvent* event){}
void TouchEventListener::touchesEnd(TouchEvent* event){}


const char* TouchEventListener::className()
{
	return FS_TOUCH_EVENT_LISTENER_CLASS_NAME;
}



const char* TouchDispatcher::className()  
{
	return FS_TOUCH_DISPATCHER_CLASS_NAME;
}

TouchDispatcher* TouchDispatcher::create()
{
	return new TouchDispatcher();
}






NS_FS_END








