
#include "FsMacros.h"
#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsPathUtil.h"
#include "support/util/FsScriptUtil.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"

NS_FS_BEGIN

void FsMain_Entry(int argc,char** argv)
{
    FsFaeris_LoadConfig((const char*) NULL);

	FsDict* dict=NULL;

	FsFile* file=NULL;


	file=VFS::createFile("ios.fgame");
    
    
    if(file==NULL)
    {
        FS_TRACE_INFO("Can't Find ios.fgame");
        return;
    }
    
    
    
	dict=ScriptUtil::parseScript(file);
	file->decRef();

	if(!dict)
	{
	
		FS_TRACE_WARN("file(ios.fgame) is bad format");
		return ;
	}

	FsDict* script=ScriptUtil::getDict(dict,"script");
	if(!script)
	{
		dict->decRef();
		FS_TRACE_WARN("can't get script in ios.fgame");
	}


	FsString* entry=ScriptUtil::getString(script,"entry");
	if(!entry)
	{
		FS_TRACE_WARN("Can't Find Script Entry");
		script->decRef();
		dict->decRef();
		return ;
	}
    

	LuaEngine* engine=LuaEngine::create();
	FS_NO_REF_DESTROY(engine);
	Global::setScriptEngine(engine);
	engine->executeFile(entry->cstr());

}



NS_FS_END

