#include "FsMacros.h"
#include "FsLoopAction.h"

NS_FS_BEGIN

const char* LoopAction::className()
{
	return FS_LOOP_ACTION_CLASS_NAME;
}

LoopAction::LoopAction()
{
	m_action=NULL;
	m_totalLoopNu=-1;
	m_curLoopNu=0;
}
LoopAction::~LoopAction()
{
	FS_SAFE_DEC_REF(m_action);
}



void LoopAction::init(Action* action,int count)
{
	FS_SAFE_ASSIGN(m_action,action);
	m_totalLoopNu=count;
}

LoopAction* LoopAction::create(Action* action,int count)
{
	LoopAction* ret=new LoopAction();
	ret->init(action,count);
	return ret;

}

LoopAction* LoopAction::create(Action* action)
{
	LoopAction* ret=new LoopAction();
	ret->init(action,-1);
	return ret;
}







bool LoopAction::update(ActionTarget* target,float dt,float* out)
{
	if(!m_begined)
	{
		FS_OBJECT_LAMBDA_CALL(this,onBegin,begin);
		m_begined=true;
		m_curLoopNu=1;
	}

	bool ret=run(target,dt,out);
	if(ret)
	{
		FS_OBJECT_LAMBDA_CALL(this,onFinish,finish);
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
	m_action->restart();
	return true;
}




NS_FS_END








