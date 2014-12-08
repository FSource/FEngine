#include "FsObject.h"
#include "FsClass.h"

#include "FsGlobal.h"
#include "extends/FsScriptEngine.h"



NS_FS_BEGIN 



FS_CLASS_IMPLEMENT(FsObject,0,NULL)


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

void _FsScriptExtends_Finalize(FsObject*);

void FsObject::finalize()
{
	/* NOTE: lua: implement in file FsScriptEngine.cc */
	_FsScriptExtends_Finalize(this);
}
#else 
void FsObject::finalize()
{
}
#endif 


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



NS_FS_END 




