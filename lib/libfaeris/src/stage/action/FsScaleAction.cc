#include "FsScaleAction.h"

NS_FS_BEGIN 


const char* ScaleAction::className()
{
	return FS_SCALE_ACTION_CLASS_NAME;
}

MoveAction::MoveAction()
	:Curve3Action(NULL,0)
{
}



ScaleAction* ScaleAction::createFromTo(const Vector3* from,const Vector3* to,float time)
{
	ScaleAction* ret=new ScaleAction();
	ret->initWithFromTo(from,to,time);
	return ret;
}


ScaleAction* ScaleAction::createBy(const Vector3* from,const Vector3* by,float time)
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
	LinearCurve* curve=LinearCurve3::create(from,to);
	setCurve(curve);
	setTotalTime(time);
}

void ScaleAction::initWithBy(const Vector3& from,const Vector3& by,float time)
{
	LinearCurve* curve=LinearCurve3::create(from,from+by);
	setCurve(curve);
	setTotalTime(time);
}

void ScaleAction::InitWithCurve(Curve3* curve,float time)
{
	setCurve(curve);
	setTotalTime(time);
}


bool ScaleAction::step(ActionTarget* target,float percent)
{
	Vector3 s=getCurveValue();
	if(m_markBit& CurveUsedMarkBit::USED_X)
	{
		target->setScaleX(s.x);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Y)
	{
		target->setScaleY(s.y);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Z)
	{
		target->setScaleZ(s.z);
	}
}










NS_FS_END 


