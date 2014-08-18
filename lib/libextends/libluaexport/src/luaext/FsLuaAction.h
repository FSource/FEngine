#ifndef _FS_LUA_ACTION_H_
#define _FS_LUA_ACTION_H_

#include "FsMacros.h"
#include "FsLuaMacros.h"
#include "FsObject.h"
#include "luaext/FsTAction.h"

#include "stage/action/FsAction.h"
#include "stage/action/FsCurve3Action.h"
#include "stage/action/FsFixTimeAction.h"
#include "stage/action/FsLoopAction.h"
#include "stage/action/FsMoveAction.h"
#include "stage/action/FsRotateAction.h"
#include "stage/action/FsScaleAction.h"
#include "stage/action/FsSeqAction.h"
#include "stage/action/FsPauseAction.h"

NS_FS_BEGIN

class LuaAction:public TAction<Action> 
{
	public:
		static LuaAction* create()
		{
			return new LuaAction;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_ACTION_CLASS_NAME;
		}

	protected:
		LuaAction(){}
		~LuaAction(){}
};

class LuaLoopAction:public TAction<LoopAction>
{
	public:
		static LuaLoopAction* create(Action* action,int loop_nu)
		{
			LuaLoopAction* ret=new LuaLoopAction();
			ret->init(action,loop_nu);

			return ret;
		}

		static LuaLoopAction* create(Action* action)
		{
			LuaLoopAction* ret=new LuaLoopAction();
			ret->init(action,-1);

			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_LOOP_ACTION_CLASS_NAME;
		}

};

class LuaPauseAction:public TAction<PauseAction>
{
	public:
		static LuaPauseAction* create(float time)
		{
			LuaPauseAction* ret=new LuaPauseAction();
			ret->initTotalTime(time);
			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_PAUSE_ACTION_CLASS_NAME;
		}
};



class LuaMoveAction:public TAction<MoveAction>
{
	public:
		static LuaMoveAction* createFromTo(const Vector3& from,const Vector3& to,float time)
		{
			LuaMoveAction* ret=new LuaMoveAction();
			ret->initWithFromTo(from,to,time);
			return ret;
		}
		static LuaMoveAction* createBy(const Vector3& from,const Vector3& by,float time)
		{
			LuaMoveAction* ret=new LuaMoveAction();
			ret->initWithBy(from,by,time);
			return ret;
		}
		static LuaMoveAction* create(Curve3* curve,float time)
		{
			LuaMoveAction* ret=new LuaMoveAction();
			ret->initWithCurve(curve,time);
			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_MOVE_ACTION_CLASS_NAME;
		}

};


class LuaRotateAction:public TAction<RotateAction> 
{
	public:
		static LuaRotateAction* createFromTo(const Vector3& from,const Vector3& to,float time)
		{
			LuaRotateAction* ret=new LuaRotateAction();
			ret->initWithFromTo(from,to,time);
			return ret;
		}

		static LuaRotateAction* createBy(const Vector3& from,const Vector3& to,float time)
		{
			LuaRotateAction* ret=new LuaRotateAction();
			ret->initWithBy(from,to,time);
			return ret;
		}

		static LuaRotateAction* create(Curve3* curve,float time)
		{
			LuaRotateAction* ret=new LuaRotateAction();
			ret->initWithCurve(curve,time);
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_ROTATE_ACTION_CLASS_NAME;
		}

};


class LuaScaleAction:public TAction<ScaleAction>
{
	public:
		static LuaScaleAction* createFromTo(const Vector3& from,const Vector3& to,float time)
		{
			LuaScaleAction* ret=new LuaScaleAction();
			ret->initWithFromTo(from,to,time);
			return ret;
		}

		static LuaScaleAction* createBy(const Vector3& from,const Vector3& by,float time)
		{
			LuaScaleAction* ret=new LuaScaleAction();
			ret->initWithBy(from,by,time);
			return ret;
		}

		static LuaScaleAction* create(Curve3* curve,float time)
		{
			LuaScaleAction* ret=new LuaScaleAction();
			ret->initWithCurve(curve,time);
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_SCALE_ACTION_CLASS_NAME;
		}
};

class LuaSeqAction:public TAction<SeqAction>
{
	public:
		static LuaSeqAction* create()
		{
			LuaSeqAction* ret=new LuaSeqAction();
			ret->init();
			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_SEQ_ACTION_CLASS_NAME;
		}
};






NS_FS_END










#endif /*_FS_LUA_ACTION_H_*/



