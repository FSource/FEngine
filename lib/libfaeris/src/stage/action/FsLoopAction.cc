#include "FsMacros.h"
#include "FsLoopAction.h"

NS_FS_BEGIN

const char* LoopAction::className()
{
	return FS_LOOP_ACTION_CLASS_NAME;
}

LoopAction::LoopAction(int count)
{
	m_totalLoopNu=count;
	m_curLoopNu=0;
	m_action=NULL;
}


LoopAction* LoopAction::create(Action* action,int count)
{
	LoopAction* ret=new LoopAction(action,count);
	return ret;

}


LoopAction* LoopAction::create(Action* action)
{
	LoopAction* ret=new LoopAction(action,-1);
	return ret;
}


LoopAction::LoopAction(Action* action,int count)
{
	FS_SAFE_ASSIGN(m_action,action);
	m_totalLoopNu=count;
	m_curLoopNu=0;
}





bool LoopAction::update(ActionTarget* target,float dt,float* out)
{
	if(!m_begin)
	{
		begin();
		m_begin=true;
		m_curLoopNu=1;
	}

	bool ret=run(target,dt,out);
	if(ret)
	{
		finish();
	}

	return ret;
}


bool LoopAction::run(ActionTarget* target,float dt,float* out)
{
	float reset_time=0;

	while(m_action->update(target,dt,&reset_time))
	{
		m_curLoopNu++;

		if(m_totalLoopNu==-1|| (m_curLoopNu<=m_totalLoopNu))
		{
			dt=reset_time;
			if(dt!=0)
			{
				m_action->restart();
				continue;
			}
			break;
		}
		else 
		{
			*out=reset_time;
			return true;
		}
	}

	*out=0;
	return false;
}

bool LoopAction::restart()
{
	Action::restart();
	m_curLoopNu=0;
}




NS_FS_END








