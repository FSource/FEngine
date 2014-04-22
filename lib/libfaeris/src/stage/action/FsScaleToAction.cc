#include "stage/action/FsScaleToAction.h"

#include "stage/entity/FsEntity.h"
NS_FS_BEGIN

const char* ScaleToAction::className()
{
	return FS_SCALE_TO_ACTION_CLASS_NAME;
}

ScaleToAction* ScaleToAction::create(float sx,float sy,float sz,float time)
{
	return new ScaleToAction(sx,sy,sz,time);
}

bool ScaleToAction::run(ActionTarget* target,float dt)
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
		FS_TRACE_WARN("ScaleToAction Can Only Effect Entity");
		return true;
	}

	Vector3 scale=entity->getScale();
	Vector3 diff=(m_targetScale-scale)/(m_lifeTime-m_elapse)*dt;

	entity->setScale(scale+diff);

	m_elapse+=old_dt;
	return false;
}

ScaleToAction::ScaleToAction(float sx,float sy,float sz,float time)
{
	m_targetScale=Vector3(sx,sy,sz);
	m_elapse=0;
	m_lifeTime=time;
}







NS_FS_END
