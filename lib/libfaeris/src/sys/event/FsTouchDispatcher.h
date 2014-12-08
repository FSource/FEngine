#ifndef _FS_TOUCH_DISPATCHER_H_
#define _FS_TOUCH_DISPATCHER_H_
#include "FsMacros.h"
#include "sys/event/FsTEventDispatcher.h"


NS_FS_BEGIN

class TouchPoint
{
	public:
		TouchPoint(int _id,float _x,float _y)
			:id(_id),x(_x),y(_y)	{}
		TouchPoint()
			:id(0),x(0),y(0){}
	public:
		int id;
		float x;
		float y;
};

class TouchEvent 
{	
	public:
		TouchEvent(int type,int point_nu,TouchPoint* points);
		~TouchEvent();
	public:
		const TouchPoint* getPoints(){return m_points;}
		const TouchPoint* getPoint(int index)
		{
			if(index>=m_count||index<0)
			{
				return NULL;
			}
			return m_points+index;
		}
		const TouchPoint* operator[](int index)
		{
			return getPoint(index);
		}
		int getPointsNu(){return m_count;}
		int getType(){return m_type;}

	private:
		int m_type;
		int m_count;
		TouchPoint* m_points;
};

class TouchEventListener:public FsObject
{
	public:
		static TouchEventListener* create();

	protected:
		TouchEventListener();
		virtual ~TouchEventListener();

	public:
		void handleEvent(TouchEvent* event)
		{
			onTouchEvent(event);
		}

	public:
		void onTouchEvent(TouchEvent* event);
	public:
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);

		virtual void touchesBegin(TouchEvent* event);
		virtual void touchesPointerDown(TouchEvent* event);
		virtual void touchesMove(TouchEvent* event);
		virtual void touchesPointerUp(TouchEvent* event);
		virtual void touchesEnd(TouchEvent* event);

		/* inherit FsObject */
		virtual const char* className();
};


class TouchDispatcher:public TEventDispatcher<TouchEvent,TouchEventListener>
{
	public:
		enum 
		{
			TOUCHES_BEGIN,
			TOUCHES_POINTER_DOWN,
			TOUCHES_MOVE,
			TOUCHES_POINTER_UP,
			TOUCHES_END,
			TOUCHES_CANCEL,
		};

	public:
		static TouchDispatcher* create();

		/* inherit FsObject */
		const char* className() ;

};
NS_FS_END
#endif /*_FS_TOUCH_DISPATCHER_H_*/









