/*************************************************************************/
/*  FsActionTarget.cc                                                    */
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


#include "stage/FsActionTarget.h"
#include "support/util/FsSlowArray.h"
#include "action/FsAction.h"
#include "stage/FsScene.h"

NS_FS_BEGIN


const char* ActionTarget::className()
{
	return FS_ACTION_TARGET_CLASS_NAME;
}


void ActionTarget::doAction(Action* action)
{

	m_actions->push(action);
}

void ActionTarget::removeAction(Action* action)
{
	m_actions->remove(action);
}

void ActionTarget::clearAction()
{
	m_actions->clear();
}

void ActionTarget::update(float dt)
{
	updateAction(dt);
}
void ActionTarget::stopAction()
{
	m_stop=true;
}
bool ActionTarget::isActionStop()
{
	return m_stop;
}
void ActionTarget::resumeAction()
{
	m_stop=false;
}



void ActionTarget::updateAction(float dt)
{
	if(m_stop)
	{
		return;
	}

	m_actions->lock();

	int action_nu=m_actions->size();
	bool finish=false;

	float rest_time=0;
	for(int i=0;i<action_nu;i++)
	{
		Action* action=(Action*)m_actions->get(i);
		finish=action->update(this,dt,&rest_time);
		if(finish)
		{
			m_actions->remove(action);
		}
	}

	m_actions->unlock();
	m_actions->flush();
}


ActionTarget::ActionTarget()
{
	m_actions=FsSlowArray::create();
	FS_NO_REF_DESTROY(m_actions);
	m_stop=false;
}

ActionTarget::~ActionTarget()
{
	FS_DESTROY(m_actions);
}





NS_FS_END
























