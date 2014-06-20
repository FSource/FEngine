#include "FsFixTimeAction.h"

NS_FS_BEGIN

const char* FixTimeAction::className()
{
	return FS_FIX_TIME_ACTION_CLASS_NAME;
}


FixTimeAction::FixTimeAction()
{
	m_totalTime=0;
	m_curTime=0;
	m_easing=NULL;
	m_reverse=false;
}

FixTimeAction::FixTimeAction(float time)
{
	m_totalTime=time;
	m_curTime=0;
	m_easing=NULL;
	m_reverse=false;
}

FixTimeAction::~FixTimeAction()
{
	FS_SAFE_DEC_REF(m_easing);
}


bool FixTimeAction::run(ActionTarget* target,float dt,float* out)
{
	bool ret=false;
	*out=0;

	m_curTime=m_curTime+dt;

	if(m_curTime>=m_totalTime)
	{
		*out=m_curTime-m_totalTime;
		m_curTime=m_totalTime;
		ret=true;
	}

	float percent=m_curTime/m_totalTime;
	if(m_reverse)
	{
		percent=1-percent;
	}

	if(m_easing)
	{
		percent=m_easing->getValue(percent);
	}

	step(target,percent);
	return ret;
}

bool FixTimeAction::restart()
{
	Action::restart();
	m_curTime=0;
	return true;
}

NS_FS_END


