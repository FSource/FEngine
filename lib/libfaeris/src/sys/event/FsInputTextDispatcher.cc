#include "sys/event/FsInputTextDispatcher.h"

NS_FS_BEGIN

InputTextEventListener* InputTextEventListener::create()
{
	InputTextEventListener* ret=new InputTextEventListener();
	return ret;
}

InputTextEventListener::InputTextEventListener()
{
}

InputTextEventListener::~InputTextEventListener()
{
}


void InputTextEventListener::textInput(const char* text,int length)
{
}

const char* InputTextEventListener::className()
{
	return FS_INPUT_TEXT_EVENT_LISTENER_CLASS_NAME;
}


InputTextDispatcher* InputTextDispatcher::create()
{
	InputTextDispatcher* ret=new InputTextDispatcher();
	return ret;
}

const char* InputTextDispatcher::className()
{
	return FS_INPUT_TEXT_DISPATCHER_CLASS_NAME;
}


NS_FS_END

