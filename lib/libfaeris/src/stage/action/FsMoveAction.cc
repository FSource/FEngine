/*************************************************************************/
/*  FsMoveAction.cc                                                      */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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


