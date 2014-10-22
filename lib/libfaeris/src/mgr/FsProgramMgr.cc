#include "FsProgramMgr.h"
#include "graphics/shader/FsProgram.h"

NS_FS_BEGIN


const char* ProgramMgr::className()
{
	return FS_PROGRAM_MGR_CLASS_NAME;
}

ProgramMgr* ProgramMgr::create()

{
	ProgramMgr* ret=new ProgramMgr;
	return ret;
}

ProgramMgr::ProgramMgr()
	:ResourceMgr(0)
{
}
ProgramMgr::~ProgramMgr()
{
}

Resource* ProgramMgr::load(const char* name)
{
	return ResourceMgr::load(name);
}



Program* ProgramMgr::load(const char* vert,const char* frag)
{


	FS_TRACE_WARN_ON(vert==NULL||frag==NULL,"Vert Or Frag Filename Can't Be NULL");

	FsString* key=FsString::create(vert);
	key->append(frag);

	Program* ret=(Program*)findFromCache(key);
	if(ret)
	{
		key->autoDestroy();
		return ret;
	}



	FsFile* vert_file=createFile(vert);
	FsFile* frag_file=createFile(frag);

	if(vert_file==NULL||frag_file==NULL)
	{
		FS_TRACE_WARN("Can't LoadFile VertFile(%s) or FragFile(%s)",vert,frag);
		FS_SAFE_DEC_REF(vert_file);
		FS_SAFE_DEC_REF(frag_file);
		return NULL;
	}


	int vert_data_len=vert_file->getLength();
	int frag_data_len=frag_file->getLength();

	char* vert_data_buf=new char[vert_data_len+1];
	vert_data_buf[vert_data_len]=0;

	char* frag_data_buf=new char[frag_data_len+1];
	frag_data_buf[frag_data_len]=0;


	vert_file->read(vert_data_buf,vert_data_len);
	frag_file->read(frag_data_buf,frag_data_len);


	ret=Program::create(vert_data_buf,frag_data_buf);

	if(ret)
	{
		addCache(key,ret);
	}

	key->autoDestroy();
	vert_file->autoDestroy();
	frag_file->autoDestroy();
	
	
	delete[] vert_data_buf;
	delete[] frag_data_buf;

	return ret;
}


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



void ProgramMgr::loadPreDefineShader()
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
		Program* prog=Program::create(shader[i].vert,shader[i].frag);
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


NS_FS_END