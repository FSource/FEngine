#include "stage/action/FsPauseAction.h"

NS_FS_BEGIN

const char* PauseAction::className()
{
	return FS_PAUSE_ACTION_CLASS_NAME;
}

PauseAction* PauseAction::create(float time)
{
	return new PauseAction(time);
}


bool PauseAction::run(ActionTarget* target,float dt,float* out)
{
	m_elapse+=dt;
	if(m_elapse>=m_lifeTime)
	{
		*out=m_elapse-m_lifeTime;
		return true;
	}

	*out=0.0f;
	return false;
}


PauseAction::PauseAction(float time)
{
	m_elapse=0;
	m_lifeTime=time;
}


NS_FS_END



