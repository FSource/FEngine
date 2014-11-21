#include "FsProgramSourceMgr.h"
#include "graphics/shader/FsProgramSource.h"
#include "sys/io/FsMemFile.h"

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



struct ST_PreDefineShader
{
	const char* key;
	const char* source;
};



static const char* FS_PRE_PROGRAM_SOURCE_V4F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F_T2F.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F_T2F_A1F.fshader"


static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F_SOURCE=
#include "graphics/shader/buildin//Fs_V4F_T2F_C4F.fshader"


static const char* FS_PRE_PROGRAM_SOURCE_PARTICLE_SOURCE=
#include "graphics/shader/buildin/Fs_Particle.fshader"

static const char*  FS_PRE_PROGRAM_SOURCE_COLOR_SOURCE=
#include "graphics/shader/buildin/Fs_Color.fshader"


static const  char* FS_PRE_PROGRAM_SOURCE_TEXTURE_SOURCE=
#include "graphics/shader/buildin/Fs_Texture.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_CONSTANT_SOURCE=
#include "graphics/shader/buildin/Fs_Constant.fshader"


void ProgramSourceMgr::loadPreDefineShader()
{
	ST_PreDefineShader shader[FS_MAX_PRE_PROGRAM_SOURCE_NU]=
	{
		{
			FS_PRE_PROGRAM_SOURCE_V4F,
			FS_PRE_PROGRAM_SOURCE_V4F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F_SOURCE
		},
		{
			FS_PRE_PROGRAM_SOURCE_PARTICLE,
			FS_PRE_PROGRAM_SOURCE_PARTICLE_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_COLOR,
			FS_PRE_PROGRAM_SOURCE_COLOR_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_TEXTURE,
			FS_PRE_PROGRAM_SOURCE_TEXTURE_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_CONSTANT,
			FS_PRE_PROGRAM_SOURCE_CONSTANT_SOURCE,
		},
	};

	for(int i=0;i<FS_MAX_PRE_PROGRAM_SOURCE_NU;i++)
	{
		int length=strlen(shader[i].source);
		FsFile* file=MemFile::create(shader[i].source,length);
		ProgramSource* ps=ProgramSource::create(file);
		file->autoDestroy();

		if(!ps)
		{
			FS_TRACE_WARN("Can't Load PreDefine Shader(%s)",shader[i].key);
			continue;
		}

		FsString* key=FsString::create(shader[i].key);

		addCache(key,ps);
		key->autoDestroy();
	}
}


NS_FS_END
