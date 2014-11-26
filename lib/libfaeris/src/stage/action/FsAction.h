#ifndef _FS_ACTION_H_
#define _FS_ACTION_H_

#include <functional>
#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN

class ActionTarget;

class Action:public FsObject 
{

	public:
		virtual bool update(ActionTarget* target,float dt,float* out);

		/* If return true, mean Action done */
		virtual bool run(ActionTarget* target,float dt,float* out);

		/* When action first run, begin will be called */
		virtual void begin();

		/* When Action done, finish will called  */ 
		virtual void finish();


		/* used for LoopAction, reset Action status to init */
		virtual bool restart();


		virtual const char* className();

	public:
		std::function<bool(Action*,ActionTarget* target,float ,float*)> onRun;
		std::function<void(Action*)> onBegin;
		std::function<void(Action*)> onFinish;
 

	protected:
		Action();
		virtual ~Action();

	protected:
		bool m_begined;



};
NS_FS_END




#endif /*_FS_ACTION_H_*/



