#ifndef _FS_KEYPAD_DISPATCHER_H_
#define _FS_KEYPAD_DISPATCHER_H_ 

#include "FsMacros.h"
#include "sys/event/FsTEventDispatcher.h"
#include "sys/FsKeyCode.h"

NS_FS_BEGIN
class KeypadEvent 
{
	public:
		enum 
		{
			KEYPAD_DOWN,
			KEYPAD_UP,
			KEYPAD_REPEAT

		};
	public:
		KeypadEvent(int _keycode,int _type)
		{
			keycode=_keycode;
			type=_type;
		}
	public:
		int keycode;
		int type;
};

class KeypadEventListener:public FsObject
{
	public:
		KeypadEventListener* create();

	protected:
		KeypadEventListener();
		virtual ~KeypadEventListener();
	public:
		void handleEvent(KeypadEvent* event)
		{
			onKeypadEvent(event->type,event->keycode);
		}

	public:
		virtual void onKeypadEvent(int type,int keycode);
		
		/* Override FsObject*/
		virtual const char* className();
};



class KeypadDispatcher:public TEventDispatcher<KeypadEvent,KeypadEventListener>
{
	public:

	public:
		static KeypadDispatcher* create();
		const char* className();

};




NS_FS_END 


#endif /*_FS_KEYPAD_DISPATCHER_H_*/

