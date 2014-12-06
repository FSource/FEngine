#include "sys/event/FsKeypadDispatcher.h"

NS_FS_BEGIN

KeypadEventListener* KeypadEventListener::create()
{
	return new KeypadEventListener;
}

KeypadEventListener::KeypadEventListener() { }
KeypadEventListener::~KeypadEventListener() { }

void KeypadEventListener::onKeypadEvent(int type,int keycode){}


const char* KeypadEventListener::className()
{
	return FS_KEYPAD_EVENT_LISTENER_CLASS_NAME;
}



KeypadDispatcher* KeypadDispatcher::create()
{
	return new KeypadDispatcher;
}

const char* KeypadDispatcher::className()
{
	return FS_KEYPAD_DISPATCHER_CLASS_NAME;
}


NS_FS_END
