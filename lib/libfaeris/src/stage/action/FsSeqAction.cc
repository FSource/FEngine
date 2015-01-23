/*************************************************************************/
/*  FsSeqAction.cc                                                       */
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


#include "stage/action/FsSeqAction.h"
#include "stage/entity/FsEntity.h"


NS_FS_BEGIN
const char* SeqAction::className()
{
	return FS_SEQ_ACTION_CLASS_NAME;
}

SeqAction::SeqAction()
{
	m_actions=NULL;
	m_curIndex=0;
}

SeqAction* SeqAction::create()
{
	SeqAction* ret=new SeqAction;
	ret->init();
	return ret;
}

SeqAction::~SeqAction()
{
	destruct();
}




bool SeqAction::init()
{
	m_actions=FsArray::create();
	FS_NO_REF_DESTROY(m_actions);
	return true;

}

void SeqAction::destruct()
{
	FS_DESTROY(m_actions);
}


void SeqAction::addAction(Action* action)
{
	m_actions->push(action);
}


void SeqAction::removeAction(Action* action)
{
	m_actions->remove(action);
}

void SeqAction::clearAction()
{
	m_actions->clear();
}


bool SeqAction::run(ActionTarget* target,float dt,float* out)
{
	float ret_time=0.0f;

	do{
		int size=m_actions->size();
		if(m_curIndex>=size)
		{
			*out=ret_time;
			return true;
		}
		Action* a=(Action*)m_actions->get(m_curIndex);
		bool ret=a->update(target,dt,&ret_time);

		if(ret)
		{
			m_curIndex++;
			if(ret_time!=0)
			{
				dt=ret_time;
				continue;
			}
			else 
			{
				if(m_curIndex>=size)
				{
					*out=0;
					return true;
				}
				else 
				{
					*out=0;
					return false;
				}
			}
		}
		break;
	}while(true);

	*out=0;
	return false;
}

bool SeqAction::restart()
{
	Action::restart();
	int size=m_actions->size();
	for(int i=0;i<size;i++)
	{
		Action* a=(Action*)m_actions->get(i);
		a->restart();
	}
	return true;
}

NS_FS_END







