#include "FsCallBackExt.h"

NS_FS_BEGIN

/*   -------------------- Entity  ------------------------*/
static void FsLEntity_onUpdate(Entity* en,float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onUpdate",2,0,"fn",en,dt))
	{
		en->update(dt);
	}
}

static void FsLEntity_onDraw(Entity* en,RenderDevice* r,bool updateMatrix)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onDraw",2,0,"ff",en,r))
	{
		en->draw(r,updateMatrix);
	}
}

void FsLEntity_CallBackAssign(Entity* en)
{
	en->onUpdate=FsLEntity_onUpdate;
	en->onDraw=FsLEntity_onDraw;
}




/* ------------------------ Entity2D -------------------------------*/

static bool FsLEntity2D_onTouchBegin(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchBegin",3,1,"fnn",en,x,y))
	{
		return en->touchBegin(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}
static bool FsLEntity2D_onTouchMove(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchMove",3,1,"fnn",en,x,y))
	{
		return en->touchMove(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLEntity2D_onTouchEnd(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onTouchEnd",3,1,"fnn",en,x,y))
	{
		return  en->touchEnd(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

static bool FsLEntity2D_onHit2D(Entity2D* en,float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(en->m_scriptData,"onHit2D",3,1,"fnn",en,x,y))
	{
		return  en->hit2D(x,y);
	}
	bool ret=se->toBoolean(-1);
	se->pop();
	return ret;
}

void FsLEntity2D_CallBackAssign(Entity2D* en)
{
	en->onTouchBegin=FsLEntity2D_onTouchBegin;
	en->onTouchMove=FsLEntity2D_onTouchMove;
	en->onTouchEnd=FsLEntity2D_onTouchEnd;
}




NS_FS_END 
