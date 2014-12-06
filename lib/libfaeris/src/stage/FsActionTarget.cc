#include "stage/FsActionTarget.h"
#include "support/util/FsSlowArray.h"
#include "action/FsAction.h"
#include "stage/FsScene.h"

NS_FS_BEGIN


const char* ActionTarget::className()
{
	return FS_ACTION_TARGET_CLASS_NAME;
}


void ActionTarget::doAction(Action* action)
{

	m_actions->push(action);
}

void ActionTarget::removeAction(Action* action)
{
	m_actions->remove(action);
}

void ActionTarget::clearAction()
{
	m_actions->clear();
}

void ActionTarget::update(float dt)
{
	updateAction(dt);
}
void ActionTarget::stopAction()
{
	m_stop=true;
}
bool ActionTarget::isActionStop()
{
	return m_stop;
}
void ActionTarget::resumeAction()
{
	m_stop=false;
}



void ActionTarget::updateAction(float dt)
{
	if(m_stop)
	{
		return;
	}

	m_actions->lock();

	int action_nu=m_actions->size();
	bool finish=false;

	float rest_time=0;
	for(int i=0;i<action_nu;i++)
	{
		Action* action=(Action*)m_actions->get(i);
		finish=action->update(this,dt,&rest_time);
		if(finish)
		{
			m_actions->remove(action);
		}
	}

	m_actions->unlock();
	m_actions->flush();
}


ActionTarget::ActionTarget()
{
	m_actions=FsSlowArray::create();
	FS_NO_REF_DESTROY(m_actions);
	m_stop=false;
}

ActionTarget::~ActionTarget()
{
	FS_DESTROY(m_actions);
}





NS_FS_END
























