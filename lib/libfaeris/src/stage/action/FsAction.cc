#include "FsMacros.h"
#include "FsAction.h"


NS_FS_BEGIN

Action* Action::create()
{
	Action* ret=new Action;
	return ret;
}


const char* Action::className()
{
	return FS_ACTION_CLASS_NAME;
}

Action::Action()
{
	m_begined=false;
	onRun=nullptr;
	onBegin=nullptr;
	onFinish=nullptr;
}

Action::~Action()
{
}

bool Action::update(ActionTarget* target,float dt,float* out)
{
	if(!m_begined)
	{
		FS_OBJECT_LAMBDA_CALL(this,onBegin,begin);
		m_begined=true;
	}

	bool ret=FS_OBJECT_LAMBDA_CALL(this,onRun,run,target,dt,out);

	if (ret)
	{
		FS_OBJECT_LAMBDA_CALL(this,onFinish,finish);
	}

	return ret;
}

bool Action::run(ActionTarget* target,float dt,float* out)
{
	*out=0;
	return true;
}


void Action::finish()
{
}

void Action::begin()
{
}


bool Action::restart()
{
	m_begined=false;
	return true;
}


NS_FS_END


