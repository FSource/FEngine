#ifndef _FS_EVENT_LISTENER_H_
#define _FS_EVENT_LISTENER_H_
#include "FsMacros.h"
#include "core/FsEvent.h"

FAERIS_NAMESPACE_BEGIN
class Window;
class EventListener
{
	public:
		virtual void onResize(Window* win,ResizeEvent* e);
		virtual void onMouse(Window* win,MouseEvent* e);
		virtual void onMotion(Window* win,MotionEvent* e);
		virtual void onKey(Window* win,KeyEvent* e);
		virtual void onTouch(Window* win,TouchEvent* e);
		virtual void onFocus(Window* win,FocusEvent* e);
		virtual void onQuit(Window* win,QuitEvent* e);
		virtual ~EventListener();
};
FAERIS_NAMESPACE_END

#endif /*_FS_EVENT_LISTENER_H_*/


