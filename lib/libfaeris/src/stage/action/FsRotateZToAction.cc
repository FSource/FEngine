#include "stage/action/FsRotateZToAction.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

const char* RotateZToAction::className()
{
	return FS_ROTATE_Z_TO_ACTION_CLASS_NAME;
}

RotateZToAction* RotateZToAction::create(float angle,float time)
{
	return new RotateZToAction(angle,time);
}

bool RotateZToAction::run(ActionTarget* target,float dt)
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
		FS_TRACE_WARN("MoveByAction Can't Only Effect Entity");
		return true;
	}

	float angle=entity->getRotateZ();
	float diff=(m_targetAngle-angle)/(m_lifeTime-m_elapse)*dt;
	entity->setRotateZ(angle+diff);

	m_elapse+=old_dt;

	return false;
}

RotateZToAction::RotateZToAction(float angle,float time)
{
	m_lifeTime=time;
	m_elapse=0;
	m_targetAngle=angle;
}

NS_FS_END


