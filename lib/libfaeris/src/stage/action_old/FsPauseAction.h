#ifndef _FS_PAUSE_ACTION_H_
#define _FS_PAUSE_ACTION_H_

#include "stage/action/FsAction.h"

NS_FS_BEGIN
class PauseAction:public Action 
{
	public:
		static PauseAction* create(float time);

	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		PauseAction(float time);

	private:
		float m_elapse;
		float m_lifeTime;
};

NS_FS_END



#endif /*_FS_PAUSE_ACTION_H_*/

