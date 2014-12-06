#include "FsGlobal.h"
#include "luaext/FsLuaScene.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

LuaScene* LuaScene::create()
{
	LuaScene* ret=new LuaScene;
	return ret;
}

void LuaScene::enter()
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onEnter",1,0,"f",this))
	{
		Scene::enter();
	}
}
void LuaScene::exit()
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onExit",1,0,"f",this))
	{
		Scene::exit();
	}
}
void LuaScene::update(float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onUpdate",2,0,"fn",this,dt))
	{
		Scene::update(dt);
	}
}
void LuaScene::draw(RenderDevice* render)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();

	if(!se->callFunctionInTable(m_scriptData,"onDraw",2,0,"ff",this,render))
	{
		Scene::draw(render);
	}
}

void LuaScene::touchBegin(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchBegin",3,0,"fnn",this,x,y))
	{
		Scene::touchBegin(x,y);
	}
}

void LuaScene::touchMove(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchMove",3,0,"fnn",this,x,y))
	{
		Scene::touchMove(x,y);
	}
}


void LuaScene::touchEnd(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchEnd",3,0,"fnn",this,x,y))
	{
		Scene::touchEnd(x,y);
	}
}

void LuaScene::touchesBegin(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchesBegin",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event))
	{
		Scene::touchesBegin(event);
	}
}

void LuaScene::touchesPointerDown(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchesPointerDown",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event))
	{
		Scene::touchesPointerDown(event);
	}

}
void LuaScene::touchesMove(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchesMove",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event))
	{
		Scene::touchesMove(event);
	}
}
void LuaScene::touchesPointerUp(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchesPointerUp",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event))
	{
		Scene::touchesPointerUp(event);
	}

}
void LuaScene::touchesEnd(TouchEvent* event)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onTouchesEnd",3,0,"fiu<TouchEvent>",this,event->getPointsNu(),event))
	{
		Scene::touchesEnd(event);
	}
}

void LuaScene::keypadEvent(int type,int keycode)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onKeypadEvent",3,0,"fii",this,type,keycode))
	{
		Scene::keypadEvent(type,keycode);
	}
}

void LuaScene::inputTextEvent(const char* value,int length)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onInputText",2,0,"fs",this,value))
	{
		FS_TRACE_WARN("onInputText %s",value);
		Scene::inputTextEvent(value,length);
	}
}


const char*  LuaScene::className()
{
	return FS_LUA_SCENE_CLASS_NAME;

}

LuaScene::LuaScene()
{
}

LuaScene::~LuaScene()
{
}


NS_FS_END




