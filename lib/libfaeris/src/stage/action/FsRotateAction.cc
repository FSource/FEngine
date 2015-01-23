/*************************************************************************/
/*  FsRotateAction.cc                                                    */
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


#include "FsRotateAction.h"
#include "math/curve/FsLinearCurve.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

const char* RotateAction::className()
{
	return FS_ROTATE_ACTION_CLASS_NAME;
}

RotateAction::RotateAction()
{
}


RotateAction* RotateAction::createFromTo(const Vector3& from,const Vector3& to,float time)
{
	RotateAction* ret=new RotateAction();
	ret->initWithFromTo(from,to,time);
	return ret;
}

RotateAction* RotateAction::createBy(const Vector3& from,const Vector3& by,float time)
{
	RotateAction* ret=new RotateAction();
	ret->initWithBy(from,by,time);
	return ret;
}

RotateAction* RotateAction::create(Curve3* curve,float time)
{
	RotateAction* ret=new RotateAction();
	ret->initWithCurve(curve,time);
	return ret;
}


void RotateAction::initWithFromTo(const Vector3& from,const Vector3& to,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,to);
	setCurve(curve);
	setTotalTime(time);
}

void RotateAction::initWithBy(const Vector3& from,const Vector3& by,float time)
{
	LinearCurve3* curve=LinearCurve3::create(from,from+by);
	setCurve(curve);
	setTotalTime(time);
}

void RotateAction::initWithCurve(Curve3* curve,float time)
{
	setCurve(curve);
	setTotalTime(time);
}


void RotateAction::step(ActionTarget* target,float percent)
{

	Entity* entity=dynamic_cast<Entity*>(target);
	Vector3 pos=getCurveValue(percent);

	if(m_markBit&CurveUsedMarkBit::USED_X)
	{
		entity->setRotateX(pos.x);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Y)
	{
		entity->setRotateY(pos.y);
	}

	if(m_markBit&CurveUsedMarkBit::USED_Z)
	{
		entity->setRotateZ(pos.z);
	}
}


NS_FS_END 

