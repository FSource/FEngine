#include "stage/action/FsMoveToAction.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

const char* MoveToAction::className()
{
	return FS_MOVE_TO_ACTION_CLASS_NAME;
}

MoveToAction* MoveToAction::create(const Vector3& pos,float time)
{
	return new MoveToAction(pos,time);
}

bool MoveToAction::run(ActionTarget* target,float dt)
{
	float old_dt=dt;
	if(m_elapse>=m_lifeTime)
	{
		return true;
	}
	if(m_elapse+dt>m_lifeTime)
	{
		dt=m_lifeTime-m_elapse;
	}

	Entity* entity=dynamic_cast<Entity*>(target);
	if(!entity)
	{
		FS_TRACE_WARN("MoveToAction Can Only Effect Entity");
		return true;
	}
	Vector3 pos=entity->getPosition();
	Vector3 diff=(m_targetPos-pos)/(m_lifeTime-m_elapse)*dt;
	entity->setPosition(pos+diff);

	m_elapse+=old_dt;

	return false;
}

MoveToAction::MoveToAction(const Vector3& pos,float time)
{
	m_targetPos=pos;
	m_elapse=0;
	m_lifeTime=time;
}












NS_FS_END





















