#include "FsMoveAction.h"
#include "math/curve/FsLinearCurve.h"
#include "stage/entity/FsEntity.h"


NS_FS_BEGIN 
const char* MoveAction::className()
{
	return FS_MOVE_ACTION_CLASS_NAME;
}

MoveAction::MoveAction()
{
}

MoveAction* MoveAction::createFromTo(const Vector3& from,const Vector3& to,float time)
{
	MoveAction* ret=new MoveAction();
	ret->initWithFromTo(from,to,time);
	return ret;
}

MoveAction* MoveAction::createBy(const Vector3& from,const Vector3& to,float time)
{
	MoveAction* ret=new MoveAction();
	ret->initWithBy(from,to,time);
	return ret;
}

MoveAction* MoveAction::create(Curve3* curve,float time)
{
	MoveAction* ret= new MoveAction();
	ret->initWithCurve(curve,time);
	return ret;
}



void MoveAction::initWithFromTo(const Vector3& from,const Vector3& to,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,to);
	setCurve(curve);
	setTotalTime(time);
}

void MoveAction::initWithBy(const Vector3& from,const Vector3& by,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,from+by);
	setCurve(curve);
	setTotalTime(time);
}

void MoveAction::initWithCurve(Curve3* curve,float time)
{
	setCurve(curve);
	setTotalTime(time);
}


void MoveAction::step(ActionTarget* target,float percent)
{
	Entity* entity=dynamic_cast<Entity*>(target);
	Vector3 pos=getCurveValue(percent);

	if(m_markBit&CurveUsedMarkBit::USED_X)
	{
		entity->setPositionX(pos.x);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Y)
	{
		entity->setPositionY(pos.y);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Z)
	{
		entity->setPositionZ(pos.z);
	}
}


NS_FS_END 


