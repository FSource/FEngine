#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#include "support/util/FsArray.h"
#include "support/util/FsString.h"

using namespace Faeris;
#define I_TO_GR(v) ((FsObject*)v)
typedef unsigned long FsUlong;


FsUlong FsArray_Size(FsArray* ay)
{
	return ay->size();
}
int FsArray_Set(FsArray* ay,FsUlong index,FsObject* item)
{
	return ay->set(index,item)?1:-1;
}
FsObject* FsArray_Get(FsArray* ay,FsUlong index)
{
	FsObject* ret=ay->get(index);
//	if(ret) ret->decRef();
	return ret;
}
int FsArray_Remove(FsArray* ay,FsUlong index)
{
	return ay->remove(index)?1:-1;
}
int FsArray_Push(FsArray* ay,FsObject* item)
{
	ay->push(item);
	return 1;
}

int FsArray_Insert(FsArray* ay,FsUlong index,FsObject* item)
{
	return ay->insert(index,item)?1:-1;
}
FsUlong FsString_GetValue(FsString* str)
{
	return atoi(str->cstr());
}


int test_set_and_get_item()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));

		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
	for(i=0;i<array_size;i++)
	{
		FsString* c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
error:
	array->decRef();
	return ret;
}

int test_get_no_exist_item()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	/* set array value*/
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	/*get no exist item*/
	for(i=array_size;i<array_size*2;i++)
	{
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i!=NULL)
		{
			c_i=NULL;
			ret=0;
			goto error;
		}
	}
error:
	array->decRef();
	return ret;
}
int test_push_back_item()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray();
	FsString* c_i=0;
	FsUlong i;
	int ret;
	/* push back item */
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Push(array,I_TO_GR(c_i));
		c_i=NULL;
		if(r<0)
		{
			ret=0;
			goto error;
		}
	}
	/* examine array_size*/
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}

	/* examine array items is correct set*/
	for(i=0;i<array_size;i++)
	{
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}
error:
	array->decRef();
	return 1;
}


/* insert front*/
int test_insert_front()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray();
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Insert(array,0,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}
		c_i=(FsString*)FsArray_Get(array,0);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}
	/* examine array size */
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
	/* examine array item */
	for(i=0;i<array_size;i++)
	{
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=array_size-1-i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}

error:
	array->decRef();
	return ret;
}

/* insert tail */
int test_insert_tail()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray();
	FsString* c_i=0;
	int ret=1;
	FsUlong i;

	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Insert(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}
	/* examine array size */
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
	/* examine array item */
	for(i=0;i<array_size;i++)
	{
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}


error:
	array->decRef();
	return ret;
}

int test_insert_middle()
{
	FsUlong array_size=1000;
	FsArray* array=new FsArray();
	FsString* c_i=0;
	int ret=1;
	FsUlong i;

	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int pos=i/2;
		int r=FsArray_Insert(array,pos,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}
		c_i=(FsString*)FsArray_Get(array,pos);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		if(FsString_GetValue(c_i)!=i)
		{
			c_i=0;
			ret=0;
			goto error;
		}
		c_i=0;
	}
	/* examine array size */
	if(FsArray_Size(array)!=array_size)
	{
		ret=0;
		goto error;
	}
	/* examine array item */
	for(i=0;i<array_size;i++)
	{
		c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		int val=FsString_GetValue(c_i);
		c_i=0;
		if(i<array_size/2)
		{
			if(val!=i*2+1)
			{
				ret=0;
				goto error;
			}
		}
		if(i>=array_size/2)
		{
			if(val!=(array_size-i-1)*2)
			{
				ret=0;
				goto error;
			}

		}


	}

error:
	array->decRef();
	return ret;
}


int test_remove_front()
{

	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	/* set array item from 0 to array_size-1 */
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	for(i=0;i<array_size/2;i++)
	{
		int r=FsArray_Remove(array,0);
		if(r<0)
		{
			ret=0;
			goto error;
		}
	}
	if(FsArray_Size(array)!=array_size/2)
	{
		ret=0;
		goto error;
	}

	for(i=0;i<array_size/2;i++)
	{
		FsString* c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		int val=FsString_GetValue(c_i);
		c_i=NULL;

		if(val!=array_size/2+i)
		{
			ret=0;
			goto error;
		}
	}
error:
	array->decRef();
	return ret;
}

int test_remove_tail()
{

	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	/* set array item from 0 to array_size-1 */
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	for(i=array_size-1;i>=array_size/2;i--)
	{
		int r=FsArray_Remove(array,i);
		if(r<0)
		{
			ret=0;
			goto error;
		}
	}
	if(FsArray_Size(array)!=array_size/2)
	{
		ret=0;
		goto error;
	}

	for(i=0;i<array_size/2;i++)
	{
		FsString* c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		int val=FsString_GetValue(c_i);
		c_i=NULL;

		if(val!=i)
		{
			ret=0;
			goto error;
		}
	}
error:
	array->decRef();
	return ret;
}
int test_remove_middle()
{

	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	/* set array item from 0 to array_size-1 */
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	for(i=0;i<array_size/2;i++)
	{
		int r=FsArray_Remove(array,array_size/4);
		if(r<0)
		{
			ret=0;
			goto error;
		}
	}
	if(FsArray_Size(array)!=array_size/2)
	{
		ret=0;
		goto error;
	}

	for(i=0;i<array_size/2;i++)
	{
		FsString* c_i=(FsString*)FsArray_Get(array,i);
		if(c_i==NULL)
		{
			ret=0;
			goto error;
		}
		int val=FsString_GetValue(c_i);
		c_i=NULL;

		if(i<array_size/4)
		{
			if(val!=i)
			{
				printf("val=%d ,real=%d \n",val,i);
				ret=0;
				goto error;
			}
		}
		else 
		{
			if(val!=array_size/2+i)
			{
				printf("val=%d ,real=%d \n",val,array_size/2+i);
				ret=0;
				goto error;
			}
		}
	}
error:
	array->decRef();
	return ret;
}


int test_remove_no_exist_item()
{

	FsUlong array_size=1000;
	FsArray* array=new FsArray(array_size);
	FsString* c_i=0;
	int ret=1;
	FsUlong i;
	for(i=0;i<array_size;i++)
	{
		c_i=new FsString(i);
		int r=FsArray_Set(array,i,I_TO_GR(c_i));
		c_i=0;
		if(r<0)
		{
			ret=0;
			goto error;
		}

	}
	for(i=array_size;i<array_size*2;i++)
	{
		int r=FsArray_Remove(array,i);
		if(r>=0)
		{
			ret=0;
			goto error;
		}
	}
error:
	array->decRef();
	return ret;
}


#define Func_Test(func) \
	do{ \
		printf("Unit_Test(%s)---",#func); \
		int ret=func(); \
		if(ret) { printf("(Ok)");g_corret++; } \
		else \
		{ printf("(Falied)"); g_error++;} \
		printf("\n"); \
	} while(0) 

static int g_corret=0;
static int g_error=0;
int main()
{

	Func_Test(test_set_and_get_item);
	Func_Test(test_get_no_exist_item);
	Func_Test(test_push_back_item);
	Func_Test(test_insert_front);
	Func_Test(test_insert_tail);
	Func_Test(test_insert_middle);
	Func_Test(test_remove_front);
		Func_Test(test_remove_tail);
		Func_Test(test_remove_middle);
		Func_Test(test_remove_no_exist_item);
	printf("Unit_Test Result:Corret=%d, Error=%d, Total=%d \n",g_corret,g_error,g_corret+g_error);
	return 0;
}
