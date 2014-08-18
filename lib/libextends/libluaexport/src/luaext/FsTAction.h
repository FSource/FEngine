#ifndef _FS_T_ACTION_H_
#define _FS_T_ACTION_H_

#include "FsMacros.h"

#include "stage/action/FsAction.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"


NS_FS_BEGIN

template <typename T_F>

class TAction:public T_F 
{
	public:
		virtual bool update(ActionTarget* target,float dt,float* out)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onUpdate",3,2,"ffn",this,target,dt))
			{
				return T_F::update(target,dt,out);
			}
			bool ret=se->toBoolean(-2);
			*out=se->toNumber(-1);
			se->pop();
			se->pop();
			return ret;
		}

		virtual bool run(ActionTarget* target,float dt,float* out)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onRun",3,2,"ffn",this,target,dt))
			{
				return T_F::run(target,dt,out);
			}
			bool ret=se->toBoolean(-2);
			*out=se->toNumber(-1);
			se->pop();
			se->pop();
			return ret;
		}

		virtual void begin()
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onBegin",1,0,"f",this))
			{
				return T_F::begin();
			}
		}

		virtual void finish()
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onFinish",1,0,"f",this))
			{
				return T_F::finish();
			}
		}

		virtual bool restart()
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onRestart",1,1,"f",this))
			{
				return T_F::restart();
			}

			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;

		}

	public:
		virtual bool onUpdate(ActionTarget* target,float dt,float* out)
		{
			return T_F::update(target,dt,out);
		}

		virtual bool onRun(ActionTarget* target,float dt,float* out)
		{
			return T_F::run(target,dt,out);
		}

		virtual void onBegin()
		{
			return T_F::begin();
		}

		virtual void onFinish()
		{
			return T_F::finish();
		}

		virtual bool onRestart()
		{
			return T_F::restart();
		}
};


NS_FS_END



#endif /*_FS_T_ACTION_H_*/

