/*************************************************************************/
/*  FsFelisScriptMgr.cc                                                  */
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

