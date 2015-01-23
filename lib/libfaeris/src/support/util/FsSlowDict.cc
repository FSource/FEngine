/*************************************************************************/
/*  FsSlowDict.cc                                                        */
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


#include "support/util/FsSlowDict.h"

NS_FS_BEGIN


const char* FsSlowDict::className()
{
	return FS_SLOW_DICT_CLASS_NAME;
}


FsSlowDict* FsSlowDict::create()
{
	return new FsSlowDict();
}


void FsSlowDict::lock() 
{
	m_lock=true;
}


void FsSlowDict::unlock()
{
	m_lock=false;
}


void FsSlowDict::flush()
{
	int pend_nu=m_pendingCommand.size();
	for( int i=0;i<pend_nu;i++)
	{
		PendingCommand* cm=m_pendingCommand[i];
		switch(cm->m_type)
		{
			case CM_INSERT:
				m_dict->insert(cm->m_key,cm->m_value);
				break;
			case CM_REMOVE:
				m_dict->remove(cm->m_key);
				break;
			case CM_CLEAR:
				m_dict->clear();
				break;
			default:
				assert(0);
				break;
		}
		delete cm;
	}
	m_pendingCommand.clear();
}


FsObject* FsSlowDict::lookup(FsObject* key)
{
	return m_dict->lookup(key);
}
FsObject* FsSlowDict::lookup(const char* key)
{
	return m_dict->lookup(key);
}


void FsSlowDict::insert(FsObject* key,FsObject* value)
{
	if(m_lock)
	{
		PendingCommand* cm =new PendingCommand(CM_INSERT,key,value);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_dict->insert(key,value);
	}

}

void FsSlowDict::remove(FsObject* key)
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_REMOVE,key,NULL);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_dict->remove(key);
	}
}

void FsSlowDict::clear() 
{
	if(m_lock)
	{
		PendingCommand* cm=new PendingCommand(CM_CLEAR,NULL,NULL);
		m_pendingCommand.push_back(cm);
	}
	else 
	{
		m_dict->clear();
	}

}

ulong FsSlowDict::size()
{
	return m_dict->size();
}


FsSlowDict::FsSlowDict()
{
	m_lock=false;
	m_dict=FsDict::create();
	FS_NO_REF_DESTROY(m_dict);
}

FsSlowDict::~FsSlowDict()
{
	FS_DESTROY(m_dict);

	int pending_nu=m_pendingCommand.size();

	for(int i=0;i<pending_nu;i++)
	{
		PendingCommand* cm=m_pendingCommand[i];
		delete cm;
	}
	m_pendingCommand.clear();
}

FsDict::Iterator* FsSlowDict::takeIterator()
{
	return new FsDict::Iterator(m_dict);
}






NS_FS_END 



