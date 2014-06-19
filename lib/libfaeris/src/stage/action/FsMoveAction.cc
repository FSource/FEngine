#include "FsMoveAction.h"


NS_FS_BEGIN 
const char* MoveAction::className()
{
	return FS_MOVE_ACTION_CLASS_NAME;
}

MoveAction::MoveAction()
	:Curve3Action(NULL,0)
{
}

MoveAction* MoveAction::createFromTo(const Vector3& from,const Vector3& to,float time)
{
	MoveAction* ret=new MoveAction();
	ret->initWithFromTo(from,to,time);
	return ret;
}

MoveAction* MoveAction::createBy(cosnt Vector3& from,const Vector3& to,float time)
{
	MoveAction* ret=new MoveAction();
	ret->initWithBy(from,to,time);
	return ret;
}

MoveAction* MoveAction::create(Curve3* curve,float time)
{
	MoveAction* ret= new MoveAction();
	ret->InitWithCurve(curve,time);
	return ret;
}



void MoveAction::initWithFromTo(const Vector3& from,const Vector3& to,float time)
{
	LinearCurve* curve=LinearCurve3::create(from,to);
	setCurve(curve);
	setTotalTime(time);
}

void MoveAction::initWithBy(const Vector3& from,const Vector3& by,float time)
{
	LinearCurve* curve=LinearCurve3::create(from,from+by);
	setCurve(curve);
	setTotalTime(time);
}

void MoveAction::InitWithCurve(Curve3* curve,float time)
{
	setCurve(curve);
	setTotalTime(time);
}


bool MoveAction::step(ActionTarget* target,float percent)
{
	Vector3 pos=getCurveValue(percent);

	if(m_markBit&CurveUsedMarkBit::USED_X)
	{
		target->setPostionX(pos.x);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Y)
	{
		target->setPostionY(pos.y);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Z)
	{
		target->setPostionZ(pos.z);
	}
}


NS_FS_END 


