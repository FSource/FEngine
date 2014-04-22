#include "stage/action/FsScaleByAction.h"
#include "stage/entity/FsEntity.h"


NS_FS_BEGIN

const char* ScaleByAction::className()
{
	return FS_SCALE_BY_ACTION_CLASS_NAME;
}

ScaleByAction* ScaleByAction::create(float sx,float sy,float sz,float time)
{
	return new ScaleByAction(sx,sy,sz,time);
}


bool ScaleByAction::run(ActionTarget* target,float dt)
{
	float old_dt=dt;
	if(m_elapse>m_lifeTime)
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
		FS_TRACE_WARN("ScaleByAction Can Only Effect Entity");
		return true;
	}

	Vector3 scale=entity->getScale();
	entity->setScale(scale+m_stepScale);
	m_elapse+=old_dt;
	return false;
}

ScaleByAction::ScaleByAction(float sx,float sy,float sz,float time)
{
	m_stepScale=Vector3(sx,sy,sz);
	m_elapse=0;
	m_lifeTime=time;
}



NS_FS_END
