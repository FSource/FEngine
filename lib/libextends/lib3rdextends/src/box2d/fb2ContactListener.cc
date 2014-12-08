#include "fb2ContactListener.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"

NS_FS_BEGIN 


fb2ContactListener::fb2ContactListener()
{
	m_scriptData=-1;
}

fb2ContactListener::~fb2ContactListener()
{

}


void fb2ContactListener::BeginContact(b2Contact* contact)
{

	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onBeginContact",2,0,"u<fb2ContactListener>u<b2Contact>",this,contact);
}

void fb2ContactListener::EndContact(b2Contact* contact)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onEndContact",2,0,"u<fb2ContactListener>u<b2Contact>",this,contact);
}


void fb2ContactListener::PreSolve(b2Contact* contact,const b2Manifold* old_mf)
{

	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onPreSolve",3,0,"u<fb2ContactListener>u<b2Contact>u<b2Manifold>",this,contact,old_mf);

}

void fb2ContactListener::PostSolve(b2Contact* contact,const b2ContactImpulse* old_mf)
{

	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onPostSolve",3,0,"u<fb2ContactListener>u<b2Contact>u<b2ContactImpulse>",this,contact,old_mf);
}



















NS_FS_END 


