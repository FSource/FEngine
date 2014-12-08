#include <stdlib.h>
#include <string.h>

#include "support/util/FsDict.h"
#include "support/util/FsString.h"

#define FS_DICT_MIN_SIZE 8
#define FS_DICT_DEFAULT_PERTURB_SHIFT 5
NS_FS_BEGIN


static const char* s_FsDict_Name=FS_DICT_CLASS_NAME;
static int s_dummy_int=0; /* only for get an unique address value */
FsObject* s_dict_dummy_entry=(FsObject*)&s_dummy_int;

bool FsDict::checkType(FsObject* ob)
{
	return ob->className()==s_FsDict_Name;
}

const char* FsDict::className()
{
	return s_FsDict_Name;
}

FsDict* FsDict::create()
{
	FsDict* ret=new FsDict();
	return ret;
}
FsDict::FsDict()
{
	m_fill=0;
	m_used=0;
	m_mask=FS_DICT_MIN_SIZE-1;
	m_table=(DictEntry*)malloc(sizeof(DictEntry)*FS_DICT_MIN_SIZE);
	memset(m_table,0,sizeof(DictEntry)*FS_DICT_MIN_SIZE);
}
bool FsDict::validEntry(FsDict::DictEntry* entry)
{
	return entry->m_key!=NULL&&entry->m_key!=s_dict_dummy_entry;
}

FsDict::DictEntry* FsDict::lookupEntry(FsObject* key,long code)
{
	ulong mask=m_mask;
	ulong i=code&mask;
	ulong perturb;

	DictEntry* table=m_table;
	DictEntry* p=table+i;
	DictEntry* freeslot=NULL;
	int cmp;
	if(p->m_key==NULL)
	{
		return p;
	}
	if(p->m_key==s_dict_dummy_entry)
	{
		freeslot=p;
	}
	else if(p->m_code==code)
	{
		cmp=key->equal(p->m_key);
		if(cmp)
		{
			return p;
		}
	}
	for(perturb=code;;perturb>>=FS_DICT_DEFAULT_PERTURB_SHIFT)
	{
		i=(i<<2)+i+1+perturb;
		p=table+(i&mask);

		if(p->m_key==NULL) 
		{
			return freeslot==NULL?p:freeslot;
		}

		if(p->m_key==s_dict_dummy_entry)
		{
			if(freeslot==NULL) freeslot=p;
		}
		else if(p->m_code==code)
		{
			FS_ASSERT(p->m_key);
			cmp=key->equal(p->m_key);
			if(cmp)
			{
				return p;
			}
		}
	}
}
void FsDict::simpleInsert(FsObject* key,long code,FsObject* value)
{
	ulong mask=m_mask;
	ulong i=code&mask;
	ulong perturb=code;

	DictEntry* table=m_table;
	DictEntry* p=table+i;

	while(p->m_key!=NULL)
	{
		i=(i<<2)+i+1+perturb;
		perturb>>=FS_DICT_DEFAULT_PERTURB_SHIFT;
		p=table+(i&mask);
	}
	FS_ASSERT(p->m_value==NULL);
	p->m_key=key;
	p->m_value=value;
	p->m_code=code;
	m_fill++;
	m_used++;
}

void FsDict::resize(long minisize)
{
	DictEntry* old_table=0;
	DictEntry* new_table=0;
	DictEntry* p=0;
	long new_size=FS_DICT_MIN_SIZE;
	long i;

	while(new_size<minisize&&new_size>0) new_size<<=1;
	FS_TRACE_ERROR_ON(new_size<0,"Can't Alloc Memory For Resize Hash Object");

	new_table=(DictEntry*)malloc(sizeof(DictEntry)*new_size);
	memset(new_table,0,sizeof(DictEntry)*new_size);

	old_table=m_table;
	m_table=new_table;
	m_mask=new_size-1;
	m_used=0;

	i=m_fill;
	m_fill=0;

	for(p=old_table;i>0;p++)
	{
		if(p->m_key!=NULL)
		{
			i--;
			if(p->m_key!=s_dict_dummy_entry)
			{

				simpleInsert(p->m_key,p->m_code,p->m_value);
			}
		}
	}
	free(old_table);
}
bool FsDict::remove(FsObject* key)
{
	long code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->className());
		return false;
	}
	DictEntry* p=lookupEntry(key,code);

	if(p->m_key==NULL||p->m_key==s_dict_dummy_entry)
	{
		FS_TRACE_WARN(" %s Key Not Map ",key->className());
		return false;
	}
	p->m_key->decRef();
	p->m_key=s_dict_dummy_entry;

	p->m_value->decRef();
	p->m_value=NULL;
	m_used--;
	return true;
}




FsObject* FsDict::lookup(FsObject* key)
{
	long code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->className());
		return NULL ;
	}
	DictEntry* p=lookupEntry(key,code);
	if(p->m_key==NULL||p->m_key==s_dict_dummy_entry)
	{
		return NULL;
	}
	FS_ASSERT(p->m_value);
	return p->m_value;
}
FsObject* FsDict::lookup(const char* key)
{
	FsObject* ob=FsString::create(key);
	FsObject* ret=lookup(ob);
	ob->decRef();
	return ret;
}


bool FsDict::insert(FsObject* key,FsObject* value)
{
	long code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->className());
		return false;
	}
	long used=m_used;
	DictEntry* p=lookupEntry(key,code);

	key->addRef();
	value->addRef();
	/* key not map before */
	if(p->m_key==NULL)
	{
		m_fill++;
		m_used++;
	}
	else if(p->m_key==s_dict_dummy_entry) /* key is dummy */
	{
		m_used++;
		p->m_key=NULL;
	}
	else  /* key aready map */
	{
		p->m_value->decRef();
		p->m_value=NULL;
	}

	if(p->m_key==NULL)
	{
		p->m_key=key;
	}
	else 
	{
		key->decRef();
	}

	p->m_value=value;
	p->m_code=code;

	/* check space, make sure 1/3 free slot */
	if(used<m_used && (ulong)m_fill*3>m_mask*2)
	{
		resize((m_used>50000?2:4)*m_used);
	}
	return true;
}

void FsDict::clear()
{
	for(unsigned int i=0;i<=m_mask;i++)
	{
		DictEntry* e=m_table+i;
		if(validEntry(e))
		{
			e->m_key->decRef();
			e->m_value->decRef();
		}
		e->m_value=NULL;
		e->m_key=NULL;
	}
	m_used=0;
	m_fill=0;
}

FsDict::Iterator* FsDict::takeIterator()
{
	Iterator* ret=new Iterator(this);
	return ret;
}



FsDict::~FsDict()
{
	DictEntry* p;
	long i=m_fill;
	for(p=m_table;i>0;p++)
	{
		if(p->m_key!=NULL)
		{
			i--;
			if(p->m_key!=s_dict_dummy_entry)
			{
				p->m_key->decRef();
				p->m_value->decRef();
			}
		}
	}
	free(m_table);
}








NS_FS_END 

