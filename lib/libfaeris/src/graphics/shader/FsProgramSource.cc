#include "FsEnums.h"
#include "FsProgramSource.h"
#include "sys/io/FsVFS.h"
#include "FsUniformMap.h"
#include "FsStreamMap.h"
#include "glslext_parser.h"
#include "support/util/FsDict.h"
#include "graphics/shader/FsProgram.h"



NS_FS_BEGIN

ProgramSource* ProgramSource::create()
{
	return new ProgramSource();
}


ProgramSource* ProgramSource::create(const char* filename)
{
	ProgramSource* ret=new ProgramSource();
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}

	return ret;
}


ProgramSource* ProgramSource::create(FsFile* file)
{
	ProgramSource* ret=new ProgramSource();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}






const char* ProgramSource::className()
{
	return "ProgramSource";
}


ProgramSource::ProgramSource()
{
	m_defaultProgramCache=NULL;
	m_programCache=FsDict::create();
}


ProgramSource::~ProgramSource()
{
	int size=m_uniformMaps.size();
	for(int i=0;i<size;i++)
	{
		UniformMap* map=m_uniformMaps[i];
		delete map;
	}
	m_uniformMaps.clear();


	size=m_streamMaps.size();
	for(int i=0;i<size;i++)
	{
		StreamMap* map=m_streamMaps[i];
		delete map;
	}
	m_streamMaps.clear();


	FS_SAFE_DEC_REF(m_defaultProgramCache);
	FS_SAFE_DEC_REF(m_programCache);
}


bool ProgramSource::init(const char* filename)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For ProgramSource",filename);
		return false;
	}
	bool ret=init(file);
	file->autoDestroy();
	return ret;
}


static int S_ProgramSource_ReadIo(void* data,void* buf,int length)
{
	FsFile* file=(FsFile*) data;
	return file->read(buf,length);
}


struct ProgramSource_UniformStrToType
{

	ProgramSource_UniformStrToType(const char* name,E_UniformRef type)
	{
		m_name=name;
		m_type=type;
	}

	const char* m_name;
	E_UniformRef m_type;
};

struct ProgramSource_AttributeStrToType
{

	ProgramSource_AttributeStrToType(const char* name,E_StreamType type)
	{
		m_name=name;
		m_type=type;
	}

	const char* m_name;
	E_StreamType m_type;
};

#define S_STREAM_ELE(name,type) ProgramSource_AttributeStrToType(name,type)

static ProgramSource_AttributeStrToType S_attribute_to_type[]={
	S_STREAM_ELE("VERTICES",E_StreamType::VERTICES),
	S_STREAM_ELE("NORMALS",E_StreamType::NORMALS),
	S_STREAM_ELE("COLORS",E_StreamType::COLORS),
	S_STREAM_ELE("UVS",E_StreamType::UVS),
	S_STREAM_ELE("UV2S",E_StreamType::UV2S),
	S_STREAM_ELE("TANGENTS",E_StreamType::TANGENTS),
	S_STREAM_ELE("SKIN_INDICS",E_StreamType::SKIN_INDICS),
	S_STREAM_ELE("SKIN_WEIGHTS",E_StreamType::SKIN_WEIGHTS),
	S_STREAM_ELE("USER_DEFINE1",E_StreamType::USER_DEFINE1),
	S_STREAM_ELE("USER_DEFINE2",E_StreamType::USER_DEFINE2),
	S_STREAM_ELE("USER_DEFINE3",E_StreamType::USER_DEFINE3),
	S_STREAM_ELE("USER_DEFINE4",E_StreamType::USER_DEFINE4),
	S_STREAM_ELE(NULL,E_StreamType::UNKOWN),
};







#define S_UNIFORM_ELE(name,type)  ProgramSource_UniformStrToType(name,type)

static ProgramSource_UniformStrToType  S_uniform_to_type[]=
{

	S_UNIFORM_ELE("R.UNKOWN", E_UniformRef::UNKOWN),

	S_UNIFORM_ELE("R.WORLD_MAT",  E_UniformRef::R_WORLD_MAT),
	S_UNIFORM_ELE("R.WORLD_TRANSPOSE_MAT",  E_UniformRef::R_WORLD_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.WORLD_INVERSE_MAT",  E_UniformRef::R_WORLD_INVERSE_MAT),
	S_UNIFORM_ELE("R.WORLD_INVERSE_TRANSPOSE_MAT",  E_UniformRef::R_WORLD_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.VIEW_MAT",  E_UniformRef::R_VIEW_MAT),
	S_UNIFORM_ELE("R.VIEW_TRANSPOSE_MAT",  E_UniformRef::R_VIEW_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.VIEW_INVERSE_MAT",  E_UniformRef::R_VIEW_INVERSE_MAT),
	S_UNIFORM_ELE("R.VIEW_INVERSE_TRANSPOSE_MAT",  E_UniformRef::R_VIEW_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.PROJECTION_MAT",E_UniformRef::R_PROJECTION_MAT),
	S_UNIFORM_ELE("R.PROJECTION_TRANSPOSE_MAT",E_UniformRef::R_PROJECTION_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.PROJECTION_INVERSE_MAT",E_UniformRef::R_PROJECTION_INVERSE_MAT),
	S_UNIFORM_ELE("R.PROJECTION_INVERSE_TRANSPOSE_MAT",E_UniformRef::R_PROJECTION_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.WORLD_VIEW_MAT",E_UniformRef::R_WORLD_VIEW_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_TRANSPOSE_MAT",E_UniformRef::R_WORLD_VIEW_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_INVERSE_MAT",E_UniformRef::R_WORLD_VIEW_INVERSE_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_INVERSE_TRANSPOSE_MAT",E_UniformRef::R_WORLD_VIEW_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.VIEW_PROJECTION_MAT",E_UniformRef::R_VIEW_PROJECTION_MAT),
	S_UNIFORM_ELE("R.VIEW_PROJECTION_TRANSPOSE_MAT",E_UniformRef::R_VIEW_PROJECTION_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.VIEW_PROJECTION_INVERSE_MAT",E_UniformRef::R_VIEW_PROJECTION_INVERSE_MAT),
	S_UNIFORM_ELE("R.VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT",E_UniformRef::R_VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.WORLD_VIEW_PROJECTION_MAT",E_UniformRef::R_WORLD_VIEW_PROJECTION_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_PROJECTION_TRANSPOSE_MAT",E_UniformRef::R_WORLD_VIEW_PROJECTION_TRANSPOSE_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_PROJECTION_INVERSE_MAT",E_UniformRef::R_WORLD_VIEW_PROJECTION_INVERSE_MAT),
	S_UNIFORM_ELE("R.WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT",E_UniformRef::R_WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE_MAT),

	S_UNIFORM_ELE("R.TIME",E_UniformRef::R_TIME),
	S_UNIFORM_ELE("R.VIEWPORT_WIDTH",E_UniformRef::R_VIEWPORT_WIDTH),
	S_UNIFORM_ELE("R.VIEWPORT_WIDTH_INVERSE",E_UniformRef::R_VIEWPORT_WIDTH_INVERSE),
	S_UNIFORM_ELE("R.VIEWPORT_HEIGHT",E_UniformRef::R_VIEWPORT_HEIGHT),
	S_UNIFORM_ELE("R.VIEWPORT_HEIGHT_INVERSE",E_UniformRef::R_VIEWPORT_HEIGHT_INVERSE),

	S_UNIFORM_ELE("R.COLOR",E_UniformRef::R_COLOR),
	S_UNIFORM_ELE("R.OPACITY",E_UniformRef::R_OPACITY),

	S_UNIFORM_ELE("M.POINT_SIZE",E_UniformRef::M_POINT_SIZE),
	S_UNIFORM_ELE("M.COLOR",E_UniformRef::M_COLOR),
	S_UNIFORM_ELE("M.OPACITY",E_UniformRef::M_OPACITY),
	S_UNIFORM_ELE("M.COLOR_MAP",E_UniformRef::M_COLOR_MAP),


	S_UNIFORM_ELE(NULL,E_UniformRef::UNKOWN)

};


bool ProgramSource::init(FsFile* file)
{
	GlslextParser* parser=GlslextParser_Parse(file,S_ProgramSource_ReadIo);
	if(parser==NULL)
	{
		FS_TRACE_WARN("Can't Parser Shader Source File");
		return false;
	}

	m_vertexSrc=*parser->getVertexSrc();
	m_fragmentSrc=*parser->getFramgentSrc();

	int uniform_nu=parser->getUniformMapNu();
	for(int i=0;i<uniform_nu;i++)
	{
		GlslextTypeMap* u=parser->getUniformMap(i);
		ProgramSource_UniformStrToType* p=S_uniform_to_type;
		while(p->m_name!=NULL)
		{
			if(u->m_value->compare(p->m_name)==0)
			{
				if(u->m_value->at(0)=='M')
				{
					addUniformMap(UniformMap::create(u->m_name->c_str(),E_UniformType::UT_REF_MTL,p->m_type));
				}
				else 
				{
					addUniformMap(UniformMap::create(u->m_name->c_str(),E_UniformType::UT_REF_RD,p->m_type));
				}
				break;
			}
			p++;
		}
		if(p->m_name==NULL)
		{
			if(u->m_value->compare("M.EXT")==0)
			{
				addUniformMap(UniformMap::create(u->m_name->c_str(),E_UniformType::UT_REF_MTL_EXT,u->m_extIndex));
			}
			else 
			{
				FS_TRACE_WARN("Unkown Uniform Map Value(%s) Ingored",u->m_value->c_str());
			}
		}
	}

	int stream_nu=parser->getAttributeMapNu();

	for(int i=0;i<stream_nu;i++)
	{
		GlslextTypeMap* u=parser->getAttributeMap(i);
		ProgramSource_AttributeStrToType* p=S_attribute_to_type;
		while(p->m_name!=NULL)
		{
			if(u->m_value->compare(p->m_name)==0)
			{
				addStreamMap(StreamMap::create(u->m_name->c_str(),p->m_type));
				break;
			}
			p++;
		}
		if(p->m_name==NULL)
		{
			FS_TRACE_WARN("Unkown Stream Map Value(%s) Ingored",u->m_value->c_str());
		}
	}

	delete parser;
	return true;
}


Program* ProgramSource::getProgram(ProgramFeatureDesc* desc)
{
	if(desc==NULL)
	{
		if(!m_defaultProgramCache)
		{
			m_defaultProgramCache=Program::create(this);
			FS_SAFE_ADD_REF(m_defaultProgramCache);
		}
		return m_defaultProgramCache;
	}
	else 
	{
		/* ADD TO SUPPORT ProgramFeatureDesc to Create Program */
		return NULL;
	
	}
}






NS_FS_END



