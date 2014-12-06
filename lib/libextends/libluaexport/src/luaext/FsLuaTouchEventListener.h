#ifndef _FS_LUA_TOUCH_EVENT_LISTENER_H_
#define _FS_LUA_TOUCH_EVENT_LISTENER_H_

#include "FsMacros.h"
#include "sys/event/FsTouchDispatcher.h"

NS_FS_BEGIN
class LuaTouchEventListener:public TouchEventListener
{
	public:
		static LuaTouchEventListener* create();


	public:
		/* multi touch */
		void touchesBegin(TouchEvent* event);
		void touchesPointerDown(TouchEvent* event);
		void touchesMove(TouchEvent* event);
		void touchesPointerUp(TouchEvent* event);
		void touchesEnd(TouchEvent* event);

		/*  single touch */
		void touchBegin(float x,float y);
		void touchMove(float x,float y);
		void touchEnd(float x,float y);

	public:
		virtual const char* className();
};
NS_FS_END

#endif /*_FS_LUA_TOUCH_EVENT_LISTENER_H_*/


