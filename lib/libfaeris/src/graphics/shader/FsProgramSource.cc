#include "FsEnums.h"
#include "FsProgramSource.h"
#include "sys/io/FsVFS.h"
#include "FsUniformMap.h"
#include "FsStreamMap.h"
#include "glslext_parser.h"
#include "support/util/FsDict.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsProgramFeatureDesc.h"



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
	m_supportFlags=0;
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

struct ProgramSource_FeatureStrToType 
{
	ProgramSource_FeatureStrToType(const char* name,uint32_t flags)
	{
		m_name=name;
		m_flags=flags;
	}

	const char* m_name;
	uint32_t m_flags;

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
	S_UNIFORM_ELE("M.EMISSIVE",E_UniformRef::M_EMISSIVE),
	S_UNIFORM_ELE("M.AMBIENT",E_UniformRef::M_AMBIENT),
	S_UNIFORM_ELE("M.DIFFUSE",E_UniformRef::M_DIFFUSE),
	S_UNIFORM_ELE("M.SPECULAR",E_UniformRef::M_SPECULAR),
	S_UNIFORM_ELE("M.SHINESS",E_UniformRef::M_SHINESS),
	S_UNIFORM_ELE("M.AMBIENT_MAP",E_UniformRef::M_AMBIENT_MAP),
	S_UNIFORM_ELE("M.DIFFUSE_MAP",E_UniformRef::M_DIFFUSE_MAP),
	S_UNIFORM_ELE("M.SPECULAR_MAP",E_UniformRef::M_SPECULAR_MAP),
	S_UNIFORM_ELE("M.BUMP_MAP",E_UniformRef::M_BUMP_MAP),
	S_UNIFORM_ELE("M.NORMAL_MAP",E_UniformRef::M_NORMAL_MAP),

	S_UNIFORM_ELE("L.AMBIENT_LIGHT_COLOR",E_UniformRef::L_AMBIENT_LIGHT_COLOR),
	S_UNIFORM_ELE("L.DIRECTIONAL_LIGHT_COLOR",E_UniformRef::L_DIRECTIONAL_LIGHT_COLOR),
	S_UNIFORM_ELE("L.DIRECTIONAL_LIGHT_DIRECTION",E_UniformRef::L_DIRECTIONAL_LIGHT_DIRECTION),
	S_UNIFORM_ELE("L.POINT_LIGHT_COLOR",E_UniformRef::L_POINT_LIGHT_COLOR),
	S_UNIFORM_ELE("L.POINT_LIGHT_POSITION",E_UniformRef::L_POINT_LIGHT_POSITION),
	S_UNIFORM_ELE("L.POINT_LIGHT_DISTANCE",E_UniformRef::L_POINT_LIGHT_DISTANCE),
	S_UNIFORM_ELE("L.SPOT_LIGHT_COLOR",E_UniformRef::L_SPOT_LIGHT_COLOR),
	S_UNIFORM_ELE("L.SPOT_LIGHT_POSITION",E_UniformRef::L_SPOT_LIGHT_POSITION),
	S_UNIFORM_ELE("L.SPOT_LIGHT_DIRECTION",E_UniformRef::L_SPOT_LIGHT_DIRECTION),
	S_UNIFORM_ELE("L.SPOT_LIGHT_COSANGLE",E_UniformRef::L_SPOT_LIGHT_COSANGLE),
	S_UNIFORM_ELE("L.SPOT_LIGHT_EXPONENT",E_UniformRef::L_SPOT_LIGHT_EXPONENT),
	S_UNIFORM_ELE("L.SPOT_LIGHT_DISTANCE",E_UniformRef::L_SPOT_LIGHT_DISTANCE),
	S_UNIFORM_ELE("L.HEMI_SPHERE_LIGHT_SKY_COLOR",E_UniformRef::L_HEMI_SPHERE_LIGHT_SKY_COLOR),
	S_UNIFORM_ELE("L.HEMI_SPHERE_LIGHT_GROUND_COLOR",E_UniformRef::L_HEMI_SPHERE_LIGHT_GROUND_COLOR),
	S_UNIFORM_ELE("L.HEMI_SPHERE_LIGHT_DIRECTION",E_UniformRef::L_HEMI_SPHERE_LIGHT_DIRECTION),


	S_UNIFORM_ELE(NULL,E_UniformRef::UNKOWN)

};

#define S_FEATURE_ELE(name,type) ProgramSource_FeatureStrToType(name,type)


static ProgramSource_FeatureStrToType   S_feature_to_type[]=
{
	S_FEATURE_ELE("light",(E_ProgramFeatureSupport::SPOT_LIGHT|E_ProgramFeatureSupport::DIRECTIONAL_LIGHT|E_ProgramFeatureSupport::POINT_LIGHT|E_ProgramFeatureSupport::HEMI_SPHERE_LIGHT|E_ProgramFeatureSupport::AMBIENT_LIGHT)),
	S_FEATURE_ELE("spotLight",E_ProgramFeatureSupport::SPOT_LIGHT),
	S_FEATURE_ELE("directionalLight",E_ProgramFeatureSupport::DIRECTIONAL_LIGHT),
	S_FEATURE_ELE("pointLight",E_ProgramFeatureSupport::POINT_LIGHT),
	S_FEATURE_ELE("hemiSphereLight",E_ProgramFeatureSupport::HEMI_SPHERE_LIGHT),
	S_FEATURE_ELE("ambientLight",E_ProgramFeatureSupport::AMBIENT_LIGHT),
	S_FEATURE_ELE("colorMap",E_ProgramFeatureSupport::COLOR_MAP),
	S_FEATURE_ELE("diffuseMap",E_ProgramFeatureSupport::DIFFUSE_MAP),
	S_FEATURE_ELE("specularMap",E_ProgramFeatureSupport::SPECULAR_MAP),
	S_FEATURE_ELE("bumpMap",E_ProgramFeatureSupport::BUMP_MAP),
	S_FEATURE_ELE("normalMap",E_ProgramFeatureSupport::NORMAL_MAP),
	S_FEATURE_ELE(NULL,E_ProgramFeatureSupport::NONE)
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
				else if(u->m_value->at(0)=='R')
				{
					addUniformMap(UniformMap::create(u->m_name->c_str(),E_UniformType::UT_REF_RD,p->m_type));
				}
				else if(u->m_value->at(0)=='L')
				{
					addUniformMap(UniformMap::create(u->m_name->c_str(),E_UniformType::UT_REF_LIGHT,p->m_type));
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

	int feature_nu=parser->getFeatureNu();
	for(int i=0;i<feature_nu;i++)
	{
		GlslextFeature* f=parser->getFeature(i);
		ProgramSource_FeatureStrToType* p=S_feature_to_type;

		while(p->m_name!=NULL)
		{
			if(f->m_name->compare(p->m_name)==0)
			{
				if(f->m_value->compare("false")==0)
				{
					m_supportFlags&=~p->m_flags;
				}
				else if(f->m_value->compare("true")==0)
				{
					m_supportFlags|=p->m_flags;
				}
				else 
				{
					FS_TRACE_WARN("Unkown Value(%s) For Feature(%s)",f->m_value->c_str(),f->m_name->c_str());
				}
				break;
			}
			p++;
		}
		if(p->m_name==NULL)
		{
			FS_TRACE_WARN("Unkwon Feature (%s) Ingored",f->m_name->c_str());
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
		uint32_t support_flags=desc->getSupportFlags();
		desc->setSupportFlags(support_flags&m_supportFlags);

		/* first look from cache */
		Program* prog=(Program*)m_programCache->lookup(desc);
		desc->setSupportFlags(support_flags);
		if(prog) 
		{
			return prog;
		}

		/* create new program */
		prog=Program::create(this,desc);

		if(prog)
		{
			m_programCache->insert(prog->getFeatureDesc(),prog);
		}
		return prog;
	}
}






NS_FS_END











