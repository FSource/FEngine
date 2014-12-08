#ifndef _FS_SYS_DISPATCHER_H_
#define _FS_SYS_DISPATCHER_H_

#include <vector>

#include "FsMacros.h"
#include "sys/event/FsTEventDispatcher.h"

NS_FS_BEGIN

class SysEvent 
{
	public:
		SysEvent(int _type)
		{
			type=_type;
		}
	public:
		int type;
};

class SysEventListener:public FsObject 
{
	public:
		SysEventListener* create();

	protected:
		SysEventListener();
		virtual ~SysEventListener();

	public:
		void handleEvent(SysEvent* event);

	public:
		virtual void foreground();
		virtual void background();
		virtual void quit();
		virtual void exit();

	public:
		/* inherit FsObject */
		virtual const char* className();
};


class SysDispatcher: public TEventDispatcher<SysEvent,SysEventListener>
{
	public:
		enum 
		{
			FOREGROUND,
			BACKGROUND,
			QUIT,
			EXIT,
		};
		/* inherit FsObject */
		virtual const char* className();

	public:
		static SysDispatcher* create();
};
NS_FS_END 

#endif /*_FS_SYS_DISPATCHER_H_*/


