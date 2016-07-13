/*************************************************************************/
/*  FsObject.cc                                                          */
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


#include "FsObject.h"
#include "FsClass.h"

#include "FsGlobal.h"
#include "extends/FsScriptEngine.h"



NS_FS_BEGIN 





int FsObject::m_objectNu=0;

FsObject::~FsObject()
{
	FS_OBJECT_LAMBDA_CALL(this,onFinalize,finalize);

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	dropScriptData();
#endif 


	FsObject::m_objectNu--;
}




long FsObject::getHashCode() 
{
	return (long)this;
}

bool FsObject::equal(FsObject* ob)
{
	return this==ob;
}



#if FS_CONFIG(FS_SCRIPT_SUPPORT)
void FsObject::dropScriptData()
{
	if(m_scriptData!=-1)
	{
		ScriptEngine* se=Global::scriptEngine();
		if(se!=NULL)
		{
			se->releaseData(m_scriptData);
		}
		m_scriptData=-1;
	}
}
#endif 

void FsObject::finalize()
{
}

void FsObject::setAttribute(const char* name,const FsVariant& v)
{
	FsClass* fsl=this->objectClass();
	fsl->callSet(this,name,v);
}

FsVariant FsObject::getAttribute(const char* name)
{
	FsClass* fsl=this->objectClass();
	return fsl->callGet(this,name);
}

void FsObject::setAttributes(FsDict* dict)
{
	FsClass* fsl=this->objectClass();
	fsl->callSets(this,dict);
}

void FsObject::setObjectName(const char* name)
{
	int length=strlen(name);
	if(m_objectName)
	{
		delete[] m_objectName;
		m_objectName=NULL;
	}
	m_objectName= new char[length+1];
	memcpy(m_objectName,name,length+1);

}
const char* FsObject::getObjectName()
{
	if(m_objectName==NULL)
	{
		return "";
	}
	return m_objectName;
}


/* Attribute Used For FsObject */
FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(FsObject,setObjectName,getObjectName);
FS_CLASS_ATTR_GET_CHARS_FUNCTION(FsObject,className);


static FsClass::FsAttributeDeclare S_Object_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("className",E_FsType::FT_CHARS,NULL,0,FsObject_className),
	FS_CLASS_ATTR_DECLARE("objectName",E_FsType::FT_CHARS,NULL,FsObject_setObjectName,FsObject_getObjectName),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT(FsObject,NULL,S_Object_Main_Attr);

NS_FS_END 




