/*************************************************************************/
/*  FsJson.cc                                                            */
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


#include "FsJson.h"
#include "support/util/FsDict.h"
#include "support/util/FsScriptUtil.h"
#include <float.h>
#include <math.h>
#include <limits.h>
#include <cJSON.h>

NS_FS_BEGIN


static FsObject* S_FsJson_DecodeObject(cJSON* item);
static FsDict* S_FsJson_DecodeDict(cJSON* item);
static FsString* S_FsJson_DecodeNull(cJSON* item);
static FsString* S_FsJson_DecodeFalse(cJSON* item);
static FsString* S_FsJson_DecodeTrue(cJSON* item);
static FsString* S_FsJson_DecodeString(cJSON* item);
static FsArray* S_FsJson_DecodeArray(cJSON* item);
static FsString* S_FsJson_DecodeNumber(cJSON* item);


FsDict* FsJson_Decode(const char* text)
{
	cJSON* json=cJSON_Parse(text);
	if(json==NULL)
	{
		return NULL;
	}

	if( json->type != cJSON_Object)
	{
		FS_TRACE_WARN("only support json root with dict");
		cJSON_Delete(json);
		return NULL;
	}

	FsDict* ret=S_FsJson_DecodeDict(json);

	cJSON_Delete(json);

	return ret;

}


static FsObject* S_FsJson_DecodeObject(cJSON* item)
{
	assert(item);
	switch(item->type)
	{
		case cJSON_NULL:	return S_FsJson_DecodeNull(item); break;
		case cJSON_False:	return S_FsJson_DecodeFalse(item); break;
		case cJSON_True:	return S_FsJson_DecodeTrue(item); break;
		case cJSON_Number:	return S_FsJson_DecodeNumber(item); break;
		case cJSON_String:	return S_FsJson_DecodeString(item); break;
		case cJSON_Array:	return S_FsJson_DecodeArray(item); break;
		case cJSON_Object:	return S_FsJson_DecodeDict(item); break;
	}
	assert(0);
	return NULL;
}


static FsDict* S_FsJson_DecodeDict(cJSON* item)
{
	FsDict* ret=FsDict::create();
	cJSON* child=item->child;

	while(child)
	{

		FsObject* value=S_FsJson_DecodeObject(child);
		const char* key=child->string;
		assert(key&&value);
		ret->insert(FsString::create(key),value);
		child=child->next;
	}
	return ret;
}

static FsArray* S_FsJson_DecodeArray(cJSON* item)
{
	FsArray* ret=FsArray::create();

	cJSON* child=item->child;

	while(child)
	{
		FsObject* value=S_FsJson_DecodeObject(child);
		assert(value);
		ret->push(value);
		child=child->next;
	}

	return ret;
}

static FsString* S_FsJson_DecodeTrue(cJSON* item)
{
	return FsString::create("true");
}

static FsString* S_FsJson_DecodeFalse(cJSON* item)
{
	return FsString::create("false");
}

static FsString* S_FsJson_DecodeNumber(cJSON* item)
{
	char buf[128];
	double d=item->valuedouble;

	if (fabs(((double)item->valueint)-d)<=DBL_EPSILON && d<=INT_MAX && d>=INT_MIN)
	{
		sprintf(buf,"%d",item->valueint);
	}
	else
	{
		if (fabs(floor(d)-d)<=DBL_EPSILON && fabs(d)<1.0e60)
		{
			sprintf(buf,"%.0f",d);
		}
		else if (fabs(d)<1.0e-6 || fabs(d)>1.0e9){		
			sprintf(buf,"%e",d);
		}
		else
		{
			sprintf(buf,"%f",d);
		}
	}
	return FsString::create(buf);
}


static FsString* S_FsJson_DecodeNull(cJSON* item)
{
	return FsString::create("null");
}


static FsString* S_FsJson_DecodeString(cJSON* item)
{
	return FsString::create(item->valuestring);
}

NS_FS_END 



