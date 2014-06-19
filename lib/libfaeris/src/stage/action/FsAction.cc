#include "FsMacros.h"
#include "FsAction.h"


NS_FS_BEGIN

const char* Action::className()
{
	return FS_ACTION_CLASS_NAME;
}

Action::Action()
{
	m_begined=false;
}

Action::~Action()
{
}

bool Action::update(ActionTarget* target,float dt,float* out)
{
	if(!m_begined)
	{
		begin();
		m_begined=true;
	}

	bool ret=run(target,dt,out);

	if (ret)
	{
		finish();
	}

	return ret;
}


void Action:finish()
{
}

void Action::begin()
{
}


void Action::restart()
{
	m_begined=false;
}


NS_FS_END


