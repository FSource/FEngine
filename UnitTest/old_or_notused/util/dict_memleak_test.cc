#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#include "util/FsDict.h"
#include "util/FsString.h"

using namespace Faeris;

void test_create()
{
	FsDict* dict=new FsDict();
	dict->decRef();
}

void test_insert()
{
	FsDict* dict=new FsDict();
	FsString* key=new FsString("key");
	FsString* value=new FsString("value");
	dict->insert(key,value);
	key->decRef();
	value->decRef();

	dict->decRef();
}
void test_reinsert()
{
	FsDict* dict=new FsDict();
	FsString* key=new FsString("key");
	FsString* value1=new  FsString("value1");
	FsString* value2=new FsString("value2");

	dict->insert(key,value1);
	dict->insert(key,value1);
	dict->insert(key,value2);

	key->decRef();
	value1->decRef();
	value2->decRef();
	dict->decRef();
}
void test_remove()
{
	FsDict* dict=new FsDict();
	FsString* key=new FsString("key");
	FsString* value=new FsString("value");

	dict->insert(key,value);
	dict->remove(key);

	key->decRef();
	value->decRef();
	dict->decRef();
}

void test_lookup()
{
	FsDict* dict=new FsDict();
	FsString* key=new FsString("key");
	FsString* value=new FsString("value");

	FsObject* ret;

	dict->insert(key,value);
	ret=dict->lookup(key);

	ret->decRef();
	key->decRef();
	value->decRef();
	dict->decRef();
}


int main()
{
	test_create();
	test_insert();
	test_reinsert();
	test_remove();
	test_lookup();
	return 0;
}
