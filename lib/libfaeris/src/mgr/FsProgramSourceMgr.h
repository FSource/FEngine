#ifndef _FS_PROGRAM_SOURCE_MGR_H_
#define _FS_PROGRAM_SOURCE_MGR_H_

#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN


#define FS_PRE_PROGRAM_SOURCE_V4F "__V4F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_C4F "__V4F_C4F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F "__V4F_T2F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F "__V4F_T2F_A1F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F "__V4F_T2F_C4F__.fshader"

#define FS_MAX_PRE_PROGRAM_SOURCE_NU 5


class ProgramSource;
class ProgramSourceMgr:public ResourceMgr 
{
	public:
		static ProgramSourceMgr* create();

	public:
		void loadPreDefineShader();

	public:
		Resource* load(const char* name);



	public:
		virtual const char* className();

	protected:
		ProgramSourceMgr();
		~ProgramSourceMgr();


};

NS_FS_END


#endif /*_FS_PROGRAM_SOURCE_MGR_H_*/



