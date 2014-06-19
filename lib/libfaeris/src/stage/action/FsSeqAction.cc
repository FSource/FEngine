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
		Action* a=m_actions->getItem(m_curIndex);
		bool ret=a->update(target,dt,&ret_time);

		if(ret)
		{
			m_curIndex++;
			if(ret_time~=0)
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
	return false
}

bool SeqAction::restart()
{
	Action::restart();
	int size=m_actions->size();
	for(int i=0;i<size;i++)
	{
		Action* a=m_actions->getItem(i);
		a->restart();
	}
	return true;
}

NS_FS_END







