#include "FsScaleAction.h"
#include "stage/entity/FsEntity.h"
#include "math/curve/FsLinearCurve.h"

NS_FS_BEGIN 


const char* ScaleAction::className()
{
	return FS_SCALE_ACTION_CLASS_NAME;
}

ScaleAction::ScaleAction()
{
}



ScaleAction* ScaleAction::createFromTo(const Vector3& from,const Vector3& to,float time)
{
	ScaleAction* ret=new ScaleAction();
	ret->initWithFromTo(from,to,time);
	return ret;
}


ScaleAction* ScaleAction::createBy(const Vector3& from,const Vector3& by,float time)
{
	ScaleAction* ret=new ScaleAction();
	ret->initWithBy(from,by,time);

	return ret;
}

ScaleAction* ScaleAction::create(Curve3* curve,float time)
{
	ScaleAction* ret= new ScaleAction();
	ret->initWithCurve(curve,time);
	return ret;
}


void ScaleAction::initWithFromTo(const Vector3& from,const Vector3& to,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,to);
	setCurve(curve);
	setTotalTime(time);
}

void ScaleAction::initWithBy(const Vector3& from,const Vector3& by,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,from+by);
	setCurve(curve);
	setTotalTime(time);
}

void ScaleAction::initWithCurve(Curve3* curve,float time)
{
	setCurve(curve);
	setTotalTime(time);
}


void ScaleAction::step(ActionTarget* target,float percent)
{
	Entity* entity=dynamic_cast<Entity*>(target);

	Vector3 s=getCurveValue(percent);
	if(m_markBit& CurveUsedMarkBit::USED_X)
	{
		entity->setScaleX(s.x);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Y)
	{
		entity->setScaleY(s.y);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Z)
	{
		entity->setScaleZ(s.z);
	}
}










NS_FS_END 


