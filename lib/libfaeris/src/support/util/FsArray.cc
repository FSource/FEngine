/*************************************************************************/
/*  FsArray.cc                                                           */
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


#include <stdlib.h>
#include <string.h>
#include "support/util/FsArray.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"

#define FS_ARRAY_MIN_SIZE 8
NS_FS_BEGIN

static const char* s_FsArrayName=FS_ARRAY_CLASS_NAME;
const char* FsArray::className()
{
	return s_FsArrayName;
}

bool FsArray::checkType(FsObject* ob)
{
	return ob->className()==s_FsArrayName;
}

FsArray::FsArray()
{
	m_cap=FS_ARRAY_MIN_SIZE;
	m_obs=(FsObject**)malloc(sizeof(FsObject*)*FS_ARRAY_MIN_SIZE);
	memset(m_obs,0,sizeof(FsObject*)*FS_ARRAY_MIN_SIZE);
	m_size=0;
}
FsArray* FsArray::create()
{
	FsArray* ret=new FsArray();
	return ret;
}


FsArray::FsArray(ulong size)
{
	if(size<FS_ARRAY_MIN_SIZE)
	{
		size=FS_ARRAY_MIN_SIZE;
	}
	m_cap=size;
	m_obs=(FsObject**)malloc(sizeof(FsObject*)*size);
	memset(m_obs,0,sizeof(FsObject*)*size);
	m_size=size;

}
FsArray::~FsArray()
{
	for(ulong i=0;i<m_size;i++)
	{
		if(m_obs[i])
		{
			m_obs[i]->decRef();
			m_obs[i]=NULL;
		}
	}
	free(m_obs);
}

void FsArray::enlarge(ulong new_size)
{
	if(new_size<m_cap)
	{
		return ;
	}

	ulong minsize=FS_ARRAY_MIN_SIZE;
	while(minsize<new_size) minsize<<=1;

	FsObject** new_obs=(FsObject**)malloc(sizeof(FsObject*)*minsize);
	memset(new_obs,0,sizeof(FsObject*)*minsize);

	for(ulong i=0;i<m_size;i++)
	{
		new_obs[i]=m_obs[i];
	}
	free(m_obs);
	m_obs=new_obs;
	m_cap=minsize;
}

int FsArray::itemPos(FsObject* ob)
{
	for(ulong i=0;i<m_size;i++)
	{
		if(m_obs[i]==ob)
		{
			return i;
		}
	}
	return -1;
}
void FsArray::push(FsObject* item)
{
	if(m_size>=m_cap)
	{
		ulong new_size=m_cap*2;
		enlarge(new_size);
	}
	if(item) item->addRef();
	m_obs[m_size++]=item;
}
void FsArray::resize(ulong new_size)
{
	ulong i;

	if(m_size>=new_size)
	{
		for(i=new_size-1;i<m_size;++i)
		{
			if(m_obs[i]!=NULL)
			{
				m_obs[i]->decRef();
				m_obs[i]=NULL;
			}
		}
		m_size=new_size;
		return;
	}
	enlarge(new_size);
	for(i=m_size;i<new_size;i++)
	{
		m_obs[i]=NULL;
	}
	m_size=new_size;
}
void FsArray::pop()
{
	FS_TRACE_ERROR_ON(m_size<=0,"No Item To Drop");
	if(m_obs[m_size-1])
	{
		m_obs[m_size-1]->decRef();
		m_obs[m_size-1]=NULL;
	}
	m_size--;
}

bool FsArray::set(ulong index,FsObject* item)
{
	if(index>=m_size)
	{
		FS_TRACE_WARN("Access Out Of Range");
		return false;
	}
	if(item) item->addRef();
	if(m_obs[index]) m_obs[index]->decRef();
	m_obs[index]=item;
	return true;
}

FsObject* FsArray::get(ulong index)
{
	if(index>=m_size)
	{
		FS_TRACE_WARN("Access Out Of Range");
		return NULL;
	}
	return m_obs[index];
}
FsObject* FsArray::top()
{
	if(m_size==0)
	{
		FS_TRACE_WARN("Access Out Of Range");
		return NULL;
	}
	return m_obs[m_size-1];
}

bool FsArray::insert(ulong index,FsObject* item)
{
	if(index>m_size)
	{
		FS_TRACE_WARN("Insert Out Of Range");
		return false;
	}
	/* no space here */
	if(m_size==m_cap)
	{
		ulong new_size=m_cap*2;
		enlarge(new_size);
	}

	ulong i;
	for(i=m_size;i>index;i--)
	{
		m_obs[i]=m_obs[i-1];
	}
	if(item) item->addRef();
	m_obs[index]=item;
	m_size++;
	return true;
}
bool FsArray::remove(ulong index)
{
	if(index>=m_size)
	{
		FS_TRACE_WARN("Remove Out Of Range");
		return false;
	}

	if(m_obs[index]) m_obs[index]->decRef();

	for(ulong i=index;i<m_size-1;i++)
	{
		m_obs[i]=m_obs[i+1];
	}
	m_size--;
	return true;
}
bool FsArray::remove(FsObject* ob)
{
	int pos=itemPos(ob);
	if(pos==-1)
	{
		FS_TRACE_WARN("Item Is Not In Array");
		return false;
	}
	return remove(pos);
	
}
void FsArray::clear()
{
	for(ulong i=0;i<m_size;i++)
	{
		m_obs[i]->decRef();
	}
	m_size=0;
}


FsDict* FsArray::getDict(ulong index) 
{
	FsObject* ob=this->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsDict::checkType(ob))
	{
		return (FsDict*) ob;
	}
	else 
	{
		return NULL;
	}
}

FsString* FsArray::getString(ulong index)
{
	FsObject* ob=this->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsString::checkType(ob))
	{
		return (FsString*) ob;
	}
	else 
	{
		return NULL;
	}
}



FsArray* FsArray::getArray(ulong index)
{
	FsObject* ob=this->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsArray::checkType(ob))
	{
		return (FsArray*) ob;
	}
	else 
	{
		return NULL;
	}

}






NS_FS_END 

