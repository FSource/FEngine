#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "util/FsDict.h"
#include "util/FsString.h"

#define DEFALULT_SIZE 10000

using namespace Faeris;

FsObject* all_keys[DEFALULT_SIZE*2];
FsObject* all_value[DEFALULT_SIZE*2];

void FsDict_Map(FsDict* h,FsObject* key,FsObject* value)
{
	h->insert(key,value);
}
FsObject* FsDict_Lookup(FsDict* h,FsObject* key)
{
	return h->lookup(key);
}
bool FsDict_Del(FsDict* h,FsObject* key)
{
	return h->remove(key);
}

int test_map_no_exist()
{
	FsDict* h=new FsDict();
	int i=0;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		FsObject* key=all_keys[i];
		FsObject* value=all_value[i];
		FsDict_Map(h,(FsObject*)key,(FsObject*)value);
	}
	h->decRef();
	return 1;
}

int test_find_exist_value()
{
	FsDict* h=new FsDict();
	FsObject* key;
	FsObject* value;
	FsObject* value1;
	int i=0;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i];
		assert(key);
		FsDict_Map(h,key,value);

		value1=FsDict_Lookup(h,key);
		if(value1==NULL)
		{
			h->decRef();
			return 0;
		}
		if(value1!=value)
		{
			h->decRef();
			return 0;
		}
		value->decRef();
	}
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=FsDict_Lookup(h,key);
		if(value==NULL)
		{
			h->decRef();
			return 0;
		}
		if((value!=all_value[i]))
		{
			h->decRef();
			return 0;
		}
		value->decRef();
	}
	h->decRef();
	return 1;
}
int test_find_no_exist_value()
{
	int i=0;
	FsDict* h=new FsDict();
	FsObject* key;
	FsObject* value;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i];
		assert(key);
		FsDict_Map(h,key,value);

	}
	for(i=DEFALULT_SIZE;i<DEFALULT_SIZE*2;i++)
	{
		key=all_keys[i];
		value=FsDict_Lookup(h,key);
		if(value!=NULL)
		{
			h->decRef();
			return 0;
		}
	}
	h->decRef();
	return 1;
}

int test_insert_exist_value()
{
	int i=0;
	FsDict* h=new FsDict();
	FsObject* key;
	FsObject* value;
	FsObject* value1;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i];
		FsDict_Map(h,key,value);
	}
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i+1];

		FsDict_Map(h,key,value);

		value1=FsDict_Lookup(h,key);

		if(value==NULL)
		{
			h->decRef();
			return 0;
		}
		if(value!=value1)
		{
			h->decRef();
			return 0;
		}
		value1->decRef();
	}
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];

		value=FsDict_Lookup(h,key);

		if(value==NULL)
		{
			h->decRef();
			return 0;
		}
		if(value!=all_value[i+1])
		{
			h->decRef();
			return 0;
		}
		value->decRef();
	}
	h->decRef();
	return 1;
}

int test_del_exist_item()
{
	int i=0;
	int ret;
	FsDict* h=new FsDict();
	FsObject* key;
	FsObject* value;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i];
		FsDict_Map(h,key,value);
	}

	for(i=0;i<DEFALULT_SIZE;i+=3)
	{
		key=all_keys[i];
		value=FsDict_Lookup(h,key);
		if((value==NULL))
		{
			h->decRef();
			return 0;
		}
		if(value!=all_value[i])
		{
			h->decRef();
			return 0;
		}
		value->decRef();

		ret=FsDict_Del(h,key);
		if(ret==false)
		{
			h->decRef();
			return 0;
		}

		value=FsDict_Lookup(h,key);
		if((value!=NULL))
		{
			h->decRef();
			return 0;
		}
	}
	for(i=0;i<DEFALULT_SIZE;i+=3)
	{
		key=all_keys[i];
		value=FsDict_Lookup(h,key);
		if(value!=NULL)
		{
			h->decRef();
			return 0;
		}
	}
	h->decRef();
	return 1;
}


int test_del_no_exist_item()
{

	int i=0;
	int ret=0;
	FsDict* h=new FsDict();
	FsObject* key;
	FsObject* value;
	for(i=0;i<DEFALULT_SIZE;i++)
	{
		key=all_keys[i];
		value=all_value[i];
		FsDict_Map(h,key,value);
		if(h->size()!=i+1)
		{
			h->decRef();
			return 0;
		}
	}


	for(i=0;i<DEFALULT_SIZE;i+=3)
	{
		key=all_keys[i];
		value=all_value[i];
		ret=FsDict_Del(h,key);
		if(ret==false)
		{
			printf("i=%d,key=%s\n",i,((FsString*)key)->cstr());
			h->decRef();
			return 0;
		}
	}
	for(i=0;i<DEFALULT_SIZE;i+=3)
	{
		key=all_keys[i];
		value=all_value[i];
		ret=FsDict_Del(h,key);
		if(ret==true)
		{
			h->decRef();
			return 0;
		}
	}

	h->decRef();
	return  1;
}


#define TEST_TIMES 1

#define Func_Test(func) \
	do{ \
		printf("Unit_Test(%s)---",#func); \
		int i=0; \
		int ret; \
		while(i++<TEST_TIMES) \
		{ \
			ret=func(); \
			if(!ret) \
			{  \
				break; \
			} \
		} \
		if(ret) \
		{  \
			printf("(Ok)"); \
			g_corret++; \
		} \
		else \
		{  \
			printf("(Falied)");  \
			g_error++; \
		} \
		printf("\n"); \
	} while(0) 


int g_corret=0;
int g_error=0;


int main(int argc,char** argv)
{

	int i=0;
	char buffer[100];


	for(;i<DEFALULT_SIZE*2;i++)
	{
		sprintf(buffer,"%d",i);
		all_keys[i]=(FsObject*)new FsString(buffer);
		sprintf(buffer,"%d",i*10);
		all_value[i]=(FsObject*)new FsString(buffer);
	}

	Func_Test(test_map_no_exist);
	Func_Test(test_find_exist_value);
	Func_Test(test_find_no_exist_value);
	Func_Test(test_insert_exist_value);
	Func_Test(test_del_exist_item);
	Func_Test(test_del_no_exist_item);
	for(i=0;i<DEFALULT_SIZE*2;i++)
	{
		all_keys[i]->decRef();
		all_value[i]->decRef();
	}

	printf("Result: Ok(%d),Falied(%d)\n",g_corret,g_error);
	return 0;
}

