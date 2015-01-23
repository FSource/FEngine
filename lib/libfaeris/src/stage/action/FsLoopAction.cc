/*************************************************************************/
/*  FsLoopAction.cc                                                      */
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


#include "FsMacros.h"
#include "FsLoopAction.h"

NS_FS_BEGIN

const char* LoopAction::className()
{
	return FS_LOOP_ACTION_CLASS_NAME;
}

LoopAction::LoopAction()
{
	m_action=NULL;
	m_totalLoopNu=-1;
	m_curLoopNu=0;
}
LoopAction::~LoopAction()
{
	FS_SAFE_DEC_REF(m_action);
}



void LoopAction::init(Action* action,int count)
{
	FS_SAFE_ASSIGN(m_action,action);
	m_totalLoopNu=count;
}

LoopAction* LoopAction::create(Action* action,int count)
{
	LoopAction* ret=new LoopAction();
	ret->init(action,count);
	return ret;

}

LoopAction* LoopAction::create(Action* action)
{
	LoopAction* ret=new LoopAction();
	ret->init(action,-1);
	return ret;
}







bool LoopAction::update(ActionTarget* target,float dt,float* out)
{
	if(!m_begined)
	{
		FS_OBJECT_LAMBDA_CALL(this,onBegin,begin);
		m_begined=true;
		m_curLoopNu=1;
	}

	bool ret=run(target,dt,out);
	if(ret)
	{
		FS_OBJECT_LAMBDA_CALL(this,onFinish,finish);
	}

	return ret;
}


bool LoopAction::run(ActionTarget* target,float dt,float* out)
{
	float reset_time=0;

	while(m_action->update(target,dt,&reset_time))
	{
		m_curLoopNu++;

		if(m_totalLoopNu==-1|| (m_curLoopNu<=m_totalLoopNu))
		{
			dt=reset_time;
			if(dt!=0)
			{
				m_action->restart();
				continue;
			}
			break;
		}
		else 
		{
			*out=reset_time;
			return true;
		}
	}

	*out=0;
	return false;
}

bool LoopAction::restart()
{
	Action::restart();
	m_curLoopNu=0;
	m_action->restart();
	return true;
}




NS_FS_END








