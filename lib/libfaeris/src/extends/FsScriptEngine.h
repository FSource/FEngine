#ifndef _FS_SCRIPT_ENGINE_H_
#define _FS_SCRIPT_ENGINE_H_

#include "FsMacros.h"
#include "FsObject.h"
NS_FS_BEGIN

class ScriptEngine:public FsObject
{
	public:
		virtual int executeFile(const char* filename)=0;
		virtual int executeString(const char* string)=0;
		virtual void releaseData(int data)=0;
		virtual int collectGarbage()=0;
		virtual ~ScriptEngine();
};

NS_FS_END 


#endif /*_FS_SCRIPT_ENGINE_H_*/

