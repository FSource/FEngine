#include "FsRotateZByAction.h"
#include "stage/entity/FsEntity.h"


NS_FS_BEGIN
const char* RotateZByAction::className()
{
	return FS_ROTATE_Z_BY_ACTION_CLASS_NAME;

}

RotateZByAction* RotateZByAction::create(float angle,float time)
{
	return new RotateZByAction(angle,time);
}

bool RotateZByAction::run(ActionTarget* target,float dt)
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
		FS_TRACE_WARN("RotateZByAction Can Only Effect Entity");
		return true;
	}
	float angle=entity->getRotateZ();
	entity->setRotateZ(angle+m_stepAngle);

	m_elapse+=old_dt;
	return false;
}


RotateZByAction::RotateZByAction(float angle,float time)
{
	m_lifeTime=time;
	m_elapse=0;
	m_stepAngle=angle/time;
}







NS_FS_END

