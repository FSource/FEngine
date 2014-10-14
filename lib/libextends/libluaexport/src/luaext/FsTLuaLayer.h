#ifndef _FS_LUA_T_LAYER_H_
#define _FS_LUA_T_LAYER_H_

#include "stage/layer/FsLayer.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN
template<typename T_F>
class  TLuaLayer:public T_F 
{
	public:
		virtual void update(float dt)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onUpdate",2,0,"fn",this,dt))
			{
				T_F::update(dt);
			}
		}
		virtual void draw(RenderDevice* render)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();

			if(!se->callFunctionInTable(T_F::m_scriptData,"onDraw",2,0,"ff",this,render))
			{
				T_F::draw(render);
			}
		}

		virtual bool touchBegin(float x,float y)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchBegin",3,1,"fnn",this,x,y))
			{
				return T_F::touchBegin(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		virtual bool touchMove(float x,float y)
		{

			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchMove",3,1,"fnn",this,x,y))
			{
				return T_F::touchMove(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;

		}
		virtual bool touchEnd(float x,float y)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchEnd",3,1,"fnn",this,x,y))
			{
				return  T_F::touchEnd(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}

		virtual bool touchesBegin(TouchEvent* event)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchesBegin",3,1,"fiu<TouchEvent>",this,event->getPointsNu(),event))
			{
				return  T_F::touchesBegin(event);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}

		virtual bool touchesPointerDown(TouchEvent* event)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchesPointerDown",3,1,"fiu<TouchEvent>",this,event->getPointsNu(),event))
			{
				return  T_F::touchesPointerDown(event);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		virtual bool touchesMove(TouchEvent* event)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchesMove",3,1,"fiu<TouchEvent>",this,event->getPointsNu(),event))
			{
				return  T_F::touchesMove(event);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		virtual bool touchesPointerUp(TouchEvent* event)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchesPointerUp",3,1,"fiu<TouchEvent>",this,event->getPointsNu(),event))
			{
				return  T_F::touchesPointerUp(event);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		virtual bool touchesEnd(TouchEvent* event)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onTouchesEnd",3,1,"fiu<TouchEvent>",this,event->getPointsNu(),event))
			{
				return  T_F::touchesEnd(event);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}

	public:
		/* inherit T_F */
		void onUpdate(float dt)
		{
			T_F::update(dt);
		}
		bool onTouchBegin(float x,float y)
		{
			return T_F::touchBegin(x,y);
		}
		bool onTouchEnd(float x,float y)
		{
			return T_F::touchEnd(x,y);
		}
		bool onTouchMove(float x,float y)
		{
			return T_F::touchMove(x,y);
		}
		void onDraw(RenderDevice* r)
		{
			T_F::draw(r);
		}

		bool onTouchesBegin(TouchEvent* event)
		{
			return T_F::touchesBegin(event);
		}

		bool onTouchesPointerDown(TouchEvent* event)
		{
			return T_F::touchesPointerDown(event);
		}

		bool onTouchesMove(TouchEvent* event)
		{
			return T_F::touchesMove(event);
		}

		bool onTouchesPointerUp(TouchEvent* event)
		{
			return T_F::touchesPointerUp(event);
		}

		bool onTouchesEnd(TouchEvent* event)
		{
			return T_F::touchesEnd(event);
		}

};

NS_FS_END


#endif 
