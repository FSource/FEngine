#include "sys/event/FsSysDispatcher.h"
#include "support/util/FsSlowArray.h"
NS_FS_BEGIN

/* SysEventListener */

SysEventListener* SysEventListener::create()
{
	SysEventListener* ret=new SysEventListener;
	return ret;
}

SysEventListener::SysEventListener() { }
SysEventListener::~SysEventListener() { }

void SysEventListener::handleEvent(SysEvent* event)
{
	switch(event->type)
	{
		case SysDispatcher::FOREGROUND:
			foreground();
			break;
		case SysDispatcher::BACKGROUND:
			background();
			break;
		case SysDispatcher::QUIT:
			quit();
			break;
		case SysDispatcher::EXIT:
			exit();
			break;
	}
}

void SysEventListener::foreground() { }
void SysEventListener::background() { }
void SysEventListener::quit() { }
void SysEventListener::exit() { }

const char* SysEventListener::className()
{
	return FS_SYS_EVENT_LISTENER_CLASS_NAME;
}


/* SysDispatcher */
const char* SysDispatcher::className()
{
	return FS_SYS_DISPATCHER_CLASS_NAME;
}

SysDispatcher* SysDispatcher::create()
{
	SysDispatcher* ret=new SysDispatcher;
	return ret;
}


NS_FS_END



