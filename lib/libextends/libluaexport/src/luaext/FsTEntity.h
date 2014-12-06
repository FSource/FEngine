#ifndef _FS_T_ENTITY_H_
#define _FS_T_ENTITY_H_

#include "FsMacros.h"

#include "stage/entity/FsEntity.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

template <typename T_F>
class TEntity:public T_F 
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

		virtual void draw(RenderDevice* r,bool updateMatrix=true)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onDraw",2,0,"ff",this,r))
			{
				T_F::draw(r,updateMatrix);
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

		virtual bool hit2D(float x,float y)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onHit2D",3,1,"fnn",this,x,y))
			{
				return  T_F::hit2D(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}

	public:
		virtual void onUpdate(float dt)
		{
			T_F::update(dt);
		}
		virtual void onDraw(RenderDevice* r)
		{
			T_F::draw(r,true);
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
		bool onHit2D(float x,float y)
		{
			return T_F::hit2D(x,y);
		}
};

NS_FS_END


#endif /*_FS_T_ENTITY_H_*/

