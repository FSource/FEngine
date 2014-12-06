#include "FsFelisScriptMgr.h"

#include "support/util/FsScriptUtil.h"

NS_FS_BEGIN


FelisScriptMgr::FelisResource* FelisScriptMgr::FelisResource::create(FsFile* file)
{
	FelisResource* ret=new FelisResource();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FelisScriptMgr::FelisResource::FelisResource()
{
	m_dict=NULL;
}

FelisScriptMgr::FelisResource::~FelisResource()
{
	FS_SAFE_DEC_REF(m_dict);
}

bool FelisScriptMgr::FelisResource::init(FsFile* file)
{
	FsDict* dict=ScriptUtil::parseScript(file);

	if(dict==NULL)
	{
		return false;
	}

	FS_SAFE_ASSIGN(m_dict,dict);
	return true;
}


/*  FelisScriptMgr */

FelisScriptMgr* FelisScriptMgr::create()
{
	FelisScriptMgr* ret=new FelisScriptMgr;
	return ret;
}





Resource* FelisScriptMgr::load(const char* name)
{
	return ResourceMgr::load(name);
}

FsDict* FelisScriptMgr::loadDict(const char* name)
{
	FelisResource* felis=(FelisResource*)load(name);
	if(felis==NULL)
	{
		return NULL;

	}

	return felis->getDict();
}



FelisScriptMgr::FelisScriptMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc)FelisResource::create)
{

}


NS_FS_END 

