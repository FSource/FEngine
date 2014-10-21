#ifndef _FS_PROGRAM_MGR_H_
#define _FS_PROGRAM_MGR_H_

#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN

#define FS_PRE_SHADER_V4F "__V4F__"
#define FS_PRE_SHADER_V4F_C4F "__V4F_C4F__"
#define FS_PRE_SHADER_V4F_T2F "__V4F_T2F__"
#define FS_PRE_SHADER_V4F_T2F_A1F "__V4F_T2F_A1F__"
#define FS_PRE_SHADER_V4F_T2F_C4F "__V4F_T2F_C4F__"

#define FS_MAX_PRE_SHADER_NU 5

class Program;
class ProgramMgr:public ResourceMgr 
{
	public:
		static ProgramMgr* create();

	public:
		void loadPreDefineShader();

	public:
		Resource* load(const char* name);

		Program* load(const char* vert,const char* frag);




	public:
		virtual const char* className();

	protected:
		ProgramMgr();
		~ProgramMgr();


};

NS_FS_END


#endif /*_FS_PROGRAM_MGR_H_*/



