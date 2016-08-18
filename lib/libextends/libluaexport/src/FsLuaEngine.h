/*************************************************************************/
/*  FsLuaEngine.h                                                        */
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
		virtual bool loadScript(FsObject* ob,const char* url);

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
