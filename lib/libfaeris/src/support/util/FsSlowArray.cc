#include "support/util/FsSlowArray.h"

NS_FS_BEGIN
FsSlowArray* FsSlowArray::create()
{
	return new FsSlowArray();
}

const char* FsSlowArray::className()  
{
	return FS_SLOW_ARRAY_CLASS_NAME;
}


void FsSlowArray::lock()
{
	m_lock=true;
}
void FsSlowArray::unlock()
{
	m_lock=false;
}

void FsSlowArray::flush()
{
	int pend_nu=m_pendingCommand.size();

	for( int i=0;i<pend_nu;i++)
	{
		PendingCommand* cm=m_pendingCommand[i];
		switch(cm->m_type)
		{
			case CM_POP:
				m_items->pop();
				break;
			case CM_PUSH:
				m_items->push(cm->m_object);
				break;
			case CM_REMOVE:
				m_items->remove(cm->m_object);
				break;
			case CM_SET:
				m_items->set(cm->m_pos,cm->m_object);
				break;
			case CM_INSERT:
				m_items->insert(cm->m_pos,cm->m_object);
				break;
			case CM_CLEAR:
				m_items->clear();
				break;
			default:
				assert(0);
				break;

		}
		delete cm;
	}
	m_pendingCommand.clear();


}

void FsSlowArray::push(FsObject* object)
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_PUSH,0,object);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->push(object);
	}
}

void FsSlowArray::pop()
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_POP,0,NULL);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->pop();
	}
}

void FsSlowArray::remove(FsObject* object)
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_REMOVE,0,object);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->remove(object);
	}
}
void FsSlowArray::set(int pos,FsObject* object)
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_SET,pos,object);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->set(pos,object);
	}
}
void FsSlowArray::insert(int pos,FsObject* object)
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_INSERT,pos,object);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->insert(pos,object);
	}
}

void FsSlowArray::clear() 
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_CLEAR,0,NULL);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_items->clear();
	}
}

FsObject* FsSlowArray::get(ulong index)
{
	return m_items->get(index);
}
FsObject* FsSlowArray::top()
{
	return m_items->top();
}
int FsSlowArray::size()
{
	return m_items->size();
}

FsSlowArray::FsSlowArray()
{
	init();
}
FsSlowArray::~FsSlowArray()
{
	destruct();
}

void FsSlowArray::init()
{
	m_lock=false;
	m_items=FsArray::create();
	FS_NO_REF_DESTROY(m_items);

}

void FsSlowArray::destruct()
{
	FS_DESTROY(m_items);

	int pending_nu=m_pendingCommand.size();
	for( int i=0;i<pending_nu;i++)
	{
		PendingCommand* cm=m_pendingCommand[i];
		delete cm;
	}
	m_pendingCommand.clear();
}

NS_FS_END









