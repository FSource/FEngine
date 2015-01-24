/*************************************************************************/
/*  FsTouchDispatcher.h                                                  */
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









