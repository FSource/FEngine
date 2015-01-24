/*************************************************************************/
/*  FsFixTimeAction.cc                                                   */
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


#include "FsFixTimeAction.h"

NS_FS_BEGIN

const char* FixTimeAction::className()
{
	return FS_FIX_TIME_ACTION_CLASS_NAME;
}


FixTimeAction* FixTimeAction::create(float total_time)
{
	FixTimeAction* ret=new FixTimeAction(total_time);
	return ret;
}



FixTimeAction::FixTimeAction()
{
	m_totalTime=0;
	m_curTime=0;
	m_easing=NULL;
	m_reverse=false;
	onStep=nullptr;

}

FixTimeAction::FixTimeAction(float time)
{
	m_totalTime=time;
	m_curTime=0;
	m_easing=NULL;
	m_reverse=false;
	onStep=nullptr;
}

FixTimeAction::~FixTimeAction()
{
	FS_SAFE_DEC_REF(m_easing);
}


bool FixTimeAction::run(ActionTarget* target,float dt,float* out)
{
	bool ret=false;
	*out=0;

	m_curTime=m_curTime+dt;

	if(m_curTime>=m_totalTime)
	{
		*out=m_curTime-m_totalTime;
		m_curTime=m_totalTime;
		ret=true;
	}

	float percent=m_curTime/m_totalTime;
	if(m_reverse)
	{
		percent=1-percent;
	}

	if(m_easing)
	{
		percent=m_easing->getValue(percent);
	}

	FS_OBJECT_LAMBDA_CALL(this,onStep,step,target,percent);
	return ret;
}

bool FixTimeAction::restart()
{
	Action::restart();
	m_curTime=0;
	return true;
}

void FixTimeAction::step(ActionTarget* target,float percent)
{
}


NS_FS_END


