#include "stage/action/FsMoveByAction.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

const char* MoveByAction::className()
{
	return FS_MOVE_BY_ACTION_CLASS_NAME;
}

MoveByAction* MoveByAction::create(const Vector3& pos,float time)
{
	return new MoveByAction(pos,time);
}

bool MoveByAction::run(ActionTarget* target,float dt)
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
		FS_TRACE_WARN("MoveByAction Can Only Effect Entity");
		return true;
	}

	Vector3 pos=entity->getPosition();
	Vector3 step=m_stepPos*dt;
	entity->setPosition(pos+step);

	m_elapse+=old_dt;
	return false;
}

MoveByAction::MoveByAction(const Vector3& pos,float time)
{
	m_stepPos=pos/time;
	m_elapse=0;
	m_lifeTime=time;
}



NS_FS_END



