#ifndef _FS_LUA_ENGINE_H_
#define _FS_LUA_ENGINE_H_

#include "extends/FsScriptEngine.h"



struct lua_State;
typedef int (*CFunction)(struct lua_State*);

NS_FS_BEGIN


void _FsScriptExtends_Finalize(FsObject* ob);

class TouchEvent;
class LuaEngine:public ScriptEngine
{	
	public:
		static LuaEngine* create();
	public:

		/* push value */
		void pushInteger(int value);
		void pushNumber(double value);
		void pushString(const char* str);
		void pushFsObject(FsObject* ob);
		void pushUserType(void* value,const char* type);
		void pushCFunction(CFunction func);
		void pushBoolean(bool value);

		/* pop value */
		void pop();

		/* cast value */
		int toInteger(int index);
		float toNumber(int index);
		bool toBoolean(int index);
		const char* toString(int index);



		void setGlobalCFunction(const char* name,CFunction func);
		void setGlobalUserType(const char* name,void* data,const char* type);


		/* fmt -----
		 * f: FsObject  
		 * i: Integer 
		 * s: String
		 * n: Number  
		 * b: bool 
		 * u<usertype>: usertype
	 	 */

		bool callFunctionInTable(int lua_table,const char* func_name,int argnu,int retnu,const char* fmt,...);

		/* no args */
		bool callFunctionInTable(int lua_table,const char* func_name,int retnu);
		bool callFunction(int lua_function,const char* name,const char* fmt,...);
		bool callFunctionInName(const char* luaFunc, const char* argt, ...) const;

		/* lua function*/
		void removeLuaFunction(int refid);
		void pushLuaFunction(int refid);

		/* lua table */
		void pushLuaTable(int refid);
		void removeLuaTable(int refid);

		/* call function */
		bool call(int argnu,int retnu);

		void cleanStack();

		struct lua_State* getLuaState(){return m_state;}

	public:
		/* inherit ScriptEngine */
		virtual int executeFile(const char* file);
		virtual int executeString(const char* str);
		virtual void releaseData(int data);
		virtual int collectGarbage();
		/* inherit FsObject */
		virtual const char* className();

	protected:
		LuaEngine();
		~LuaEngine();

	private:
		struct lua_State* m_state;

};
NS_FS_END
#endif /*_FS_LUA_ENGINE_H_*/
