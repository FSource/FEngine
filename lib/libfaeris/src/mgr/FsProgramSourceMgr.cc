#include "FsProgramSourceMgr.h"
#include "graphics/shader/FsProgramSource.h"

NS_FS_BEGIN

static Resource* S_ProgramSource_Create(FsFile* file)
{
	ProgramSource* ret=ProgramSource::create(file);
	return ret;
}


const char* ProgramSourceMgr::className()
{
	return "ProgramSourceMgr";
}

ProgramSourceMgr* ProgramSourceMgr::create()

{
	ProgramSourceMgr* ret=new ProgramSourceMgr;
	return ret;
}

ProgramSourceMgr::ProgramSourceMgr()
	:ResourceMgr(S_ProgramSource_Create)
{
}


ProgramSourceMgr::~ProgramSourceMgr()
{

}


Resource* ProgramSourceMgr::load(const char* name)
{
	return ResourceMgr::load(name);
}


void ProgramSourceMgr::loadPreDefineShader()
{

}




/*

struct ST_PreDefineShader
{
	const char* key;
	const char* vert;
	const char* frag;
};



static const char* FS_PRE_SHADER_V4F_VERT=
#include "graphics/shader/Fs_V4F.vert"

static const char* FS_PRE_SHADER_V4F_FRAG=
#include "graphics/shader/Fs_V4F.frag"

static const char* FS_PRE_SHADER_V4F_C4F_VERT=
#include "graphics/shader/Fs_V4F_C4F.vert"

static const char* FS_PRE_SHADER_V4F_C4F_FRAG=
#include "graphics/shader/Fs_V4F_C4F.frag"



static const char*  FS_PRE_SHADER_V4F_T2F_VERT=
#include "graphics/shader/Fs_V4F_T2F.vert"

static const char* FS_PRE_SHADER_V4F_T2F_FRAG=
#include "graphics/shader/Fs_V4F_T2F.frag"


static const char* FS_PRE_SHADER_V4F_T2F_A1F_VERT=
#include "graphics/shader/Fs_V4F_T2F_A1F.vert"

static const char* FS_PRE_SHADER_V4F_T2F_A1F_FRAG=
#include "graphics/shader/Fs_V4F_T2F_A1F.frag"


static const char* FS_PRE_SHADER_V4F_T2F_C4F_VERT=
#include "graphics/shader/Fs_V4F_T2F_C4F.vert"

static const char* FS_PRE_SHADER_V4F_T2F_C4F_FRAG=
#include "graphics/shader/Fs_V4F_T2F_C4F.frag"



void ProgramSourceMgr::loadPreDefineShader()
{
	ST_PreDefineShader shader[FS_MAX_PRE_SHADER_NU]=
	{
		{
			FS_PRE_SHADER_V4F,
			FS_PRE_SHADER_V4F_VERT,
			FS_PRE_SHADER_V4F_FRAG,
		},
		{
			FS_PRE_SHADER_V4F_C4F,
			FS_PRE_SHADER_V4F_C4F_VERT,
			FS_PRE_SHADER_V4F_C4F_FRAG,
		},
		{
			FS_PRE_SHADER_V4F_T2F,
			FS_PRE_SHADER_V4F_T2F_VERT,
			FS_PRE_SHADER_V4F_T2F_FRAG,
		},
		{
			FS_PRE_SHADER_V4F_T2F_A1F,
			FS_PRE_SHADER_V4F_T2F_A1F_VERT,
			FS_PRE_SHADER_V4F_T2F_A1F_FRAG,
		},
		{
			FS_PRE_SHADER_V4F_T2F_C4F,
			FS_PRE_SHADER_V4F_T2F_C4F_VERT,
			FS_PRE_SHADER_V4F_T2F_C4F_FRAG,
		},

	};

	for(int i=0;i<FS_MAX_PRE_SHADER_NU;i++)
	{
		ProgramSource* prog=ProgramSource::create(shader[i].vert,shader[i].frag);
		if(!prog)
		{
			FS_TRACE_WARN("Can't Load PreDefine Shader(%s)",shader[i].key);
			continue;
		}

		FsString* key=FsString::create(shader[i].key);
		addCache(key,prog);
		key->autoDestroy();
	}

}

*/

NS_FS_END
