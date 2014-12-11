#include "string.h"
#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#if FS_PLATFORM_OS(FS_OS_OSX)
	#include "GL/glew.h"
#else 
	#include "GL/glew.h"
#endif 

#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsProgramSource.h"
#include "support/util/FsLog.h"
#include "graphics/shader/FsUniformMap.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgramFeatureDesc.h"

#define FS_MAX_GL_SHADER_LOG_LENGTH 1024
#define FS_MAX_GL_PROGRAM_LOG_LENGTH 1024

NS_FS_BEGIN

GLint S_CreateShaderObject(const char* source,int length,GLint type)
{
	char log_info[FS_MAX_GL_SHADER_LOG_LENGTH];
	GLint compile_result,log_length;

	GLuint shader=0;
	shader=glCreateShader(type);

	const char* all_source[]={source};
	const int all_source_length[]={length};

	glShaderSource(shader,1,all_source,all_source_length);
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_result);

	if(compile_result==GL_FALSE)
	{
		glGetShaderInfoLog(shader,
				FS_MAX_GL_SHADER_LOG_LENGTH,
				&log_length,log_info);
		log_info[FS_MAX_GL_SHADER_LOG_LENGTH-1]='\0';
		FS_TRACE_WARN("Compile %s Shader(%s)",
				type==GL_VERTEX_SHADER?"Vertex":"Fragment",
				log_info);
		glDeleteShader(shader);
		return 0;
	}
	return shader;
}


Program* Program::create(const char* vertex_src, const char* fragment_src)
{
	Program* ret=new Program();
	if(!ret->init(vertex_src,fragment_src))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Program* Program::create(ProgramSource* source)
{
	Program* ret=new Program();
	if(!ret->init(source))
	{
		delete ret;
		return NULL;
	}

	return ret;
}

Program* Program::create(ProgramSource* source,ProgramFeatureDesc* desc)
{
	Program* ret=new Program();
	if(!ret->init(source,desc))
	{
		delete ret;
		return NULL;
	}
	return ret;

}


bool Program::canMatch(ProgramFeatureDesc* desc)
{
	if(!m_programSource||!m_featureDesc) 
	{
		return false;
	}
	
	uint32_t flag_mark=m_programSource->getSupportFlags();

	return ProgramFeatureDesc::equal(m_featureDesc,desc,flag_mark);

}






bool Program::init(const char* vertex_src,const char* fragment_src)
{
	if(vertex_src==NULL||fragment_src==NULL)
	{
		FS_TRACE_WARN("No Information About Vertex Shader Or Fragment Shader");
		return false;
	}

	uint v_size=strlen(vertex_src);
	uint f_size=strlen(fragment_src);

	GLuint program=0;
	GLuint vertex_shader=0;
	GLuint fragment_shader=0;

	char log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH];
	int log_length;
	GLint link_result;


	vertex_shader=S_CreateShaderObject(vertex_src,v_size,GL_VERTEX_SHADER);
	if(vertex_shader==0)
	{
		goto error;
	}


	fragment_shader=S_CreateShaderObject(fragment_src,f_size,GL_FRAGMENT_SHADER);
	if(fragment_shader==0)
	{
		goto error;
	}

	/* create program object */
	program=glCreateProgram();  /* success: non-zero */
	glAttachShader(program,vertex_shader);
	glAttachShader(program,fragment_shader);


	/* link program */
	glLinkProgram(program);

	/* check error */
	glGetProgramiv(program,GL_LINK_STATUS,&link_result);
	if(link_result==GL_FALSE)
	{
		glGetProgramInfoLog(program,FS_MAX_GL_PROGRAM_LOG_LENGTH,&log_length,log_info);
		log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH-1]='\0';
		FS_TRACE_WARN("Program Result(%s)",log_info);
		goto error;
	}

	/* delete  shader */
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	m_program=program;

	for(int i=0;i<FS_PROGRAM_CACHE_ATTR_SUPPORT;i++)
	{
		m_cacheAttrLoc[i]=-2;
	}

	for(int i=0;i<FS_PROGRAM_CACHE_UNIFORM_SUPPORT;i++)
	{
		m_cacheUniformLoc[i]=-2;
	}



	return true;


error:
	if(vertex_shader)
	{
		glDeleteShader(vertex_shader);
	}
	if(fragment_shader)
	{
		glDeleteShader(fragment_shader);
	}
	if(program)
	{
		glDeleteProgram(program);
	}
	return false;
}

bool Program::init(ProgramSource* source)
{

	bool ret=init(source->getVertexStr(),source->getFragmentStr());
	if(!ret)
	{
		return false;
	}
	
	int uniform_nu=source->getUniformMapNu();
	for(int i=0;i<uniform_nu;i++)
	{
		UniformMap* map=source->getUniformMap(i);
		int loc=glGetUniformLocation(m_program,map->getName());
		if(loc>=0)
		{
			UniformMap* u=map->clone();
			u->m_location=loc;
			addUniformMap(u);
		}
	}

	int stream_nu=source->getStreamMapNu();
	for(int i=0;i<stream_nu;i++)
	{
		StreamMap* map=source->getStreamMap(i);
		int loc=glGetAttribLocation(m_program,map->m_name.c_str());
		if(loc>=0)
		{
			StreamMap* s=map->clone();
			s->m_location=loc;
			addStreamMap(s);
		}
	}
	m_programSource=source;

	return true;
}

bool Program::init(ProgramSource* source,ProgramFeatureDesc* desc)
{

	uint32_t support_flags=desc->getSupportFlags()&source->getSupportFlags();


	std::string head_define;
	char buf[1024];

	if(support_flags&E_ProgramFeatureSupport::LIGHT)
	{
		if((support_flags&E_ProgramFeatureSupport::AMBIENT_LIGHT ) 
				&&  desc->m_ambientLightNu !=  0 )
		{
			head_define.append("#define FS_AMBIENT_LIGHT_NU 1 \n");
		}
				
		if((support_flags&E_ProgramFeatureSupport::DIRECTIONAL_LIGHT)
				&& desc->m_directionalLightNu != 0 )
		{
			sprintf(buf,"#define FS_DIRECTIONAL_LIGHT_NU %d \n",desc->m_directionalLightNu);
			head_define.append(buf);
		}

		if((support_flags&E_ProgramFeatureSupport::POINT_LIGHT)
				&& desc->m_pointLightNu !=0 )
		{
			sprintf(buf, "#define FS_POINT_LIGHT_NU %d \n",desc->m_pointLightNu);
			head_define.append(buf);
		}

		if((support_flags & E_ProgramFeatureSupport::SPOT_LIGHT )
				&& desc->m_spotLightNu !=0)
		{
			sprintf(buf, "#define FS_SPOT_LIGHT_NU %d \n",desc->m_spotLightNu);
			head_define.append(buf);
		}

		if((support_flags &  E_ProgramFeatureSupport::HEMI_SPHERE_LIGHT)
				&& desc->m_hemiSphereLightNu !=0)
		{
			sprintf(buf, "#define FS_HEMI_SPHERE_LIGHT_NU %d \n",desc->m_hemiSphereLightNu);
			head_define.append(buf);
		}
	}

	if(support_flags&E_ProgramFeatureSupport::TEXTURE_MAP)
	{
		if(support_flags & E_ProgramFeatureSupport::COLOR_MAP)
		{
			head_define.append("#define FS_COLOR_MAP \n");
		}

		if(support_flags & E_ProgramFeatureSupport::DIFFUSE_MAP)
		{
			head_define.append("#define FS_DIFFUSE_MAP \n");
		}

		if(support_flags & E_ProgramFeatureSupport::SPECULAR_MAP)
		{
			head_define.append("#define FS_SPECULAR_MAP \n");
		}

		if(support_flags & E_ProgramFeatureSupport::BUMP_MAP)
		{
			head_define.append("#define FS_BUMP_MAP \n");
		}

		if(support_flags & E_ProgramFeatureSupport::NORMAL_MAP) 
		{
			head_define.append("#define FS_NORMAL_MAP \n");
		}

	}

	if(support_flags & E_ProgramFeatureSupport:: SKELETON )
	{
		sprintf(buf, "#define FS_SKELETON_BONE_NU %d \n" ,desc->m_boneNu);
		head_define.append(buf);
	}

	std::string vertex_src = head_define + std::string(source->getVertexStr());
	std::string fragment_src= head_define + std::string(source->getFragmentStr());


	bool ret=init(vertex_src.c_str(),fragment_src.c_str());

	if(!ret)
	{
		return false;
	}

	
	int uniform_nu=source->getUniformMapNu();
	for(int i=0;i<uniform_nu;i++)
	{
		UniformMap* map=source->getUniformMap(i);
		int loc=glGetUniformLocation(m_program,map->getName());
		if(loc>=0)
		{
			UniformMap* u=map->clone();
			u->m_location=loc;
			addUniformMap(u);
		}
	}

	int stream_nu=source->getStreamMapNu();
	for(int i=0;i<stream_nu;i++)
	{
		StreamMap* map=source->getStreamMap(i);
		int loc=glGetAttribLocation(m_program,map->m_name.c_str());
		if(loc>=0)
		{
			StreamMap* s=map->clone();
			s->m_location=loc;
			addStreamMap(s);
		}
	}
	m_programSource=source;
	m_featureDesc=desc->clone();
	desc->setSupportFlags(support_flags);
	
	FS_SAFE_ADD_REF(m_featureDesc);

	return true;

}





int Program::getAttrLocation(const char* name)
{

	int loc=glGetAttribLocation(m_program,name);
	return loc;
}
int Program::getCacheAttrLocation(int index,const char* name)
{
	if(m_cacheAttrLoc[index]==-2)
	{
		m_cacheAttrLoc[index]=getAttrLocation(name);
	}

	return m_cacheAttrLoc[index];
}


int Program::getUniformLocation(const char* name)
{
	int loc=glGetUniformLocation(m_program,name);
	return loc;
}

int Program::getCacheUniformLocation(int index,const char* name)
{
	if(m_cacheUniformLoc[index]==-2)
	{
		m_cacheUniformLoc[index]=getUniformLocation(name);
	}
	return m_cacheUniformLoc[index];
}


void Program::addStreamMap(StreamMap* map)
{
	m_streamMaps->push(map);
	m_seqStreamMaps[static_cast<int>(map->m_refType)]=map;
}





Program::Program()
{
	m_program=0;

	m_programSource=NULL;
	m_featureDesc=NULL;

	for(int i=0;i<FS_PROGRAM_CACHE_ATTR_SUPPORT;i++)
	{
		m_cacheAttrLoc[i]=-2;
	}

	for(int i=0;i<FS_PROGRAM_CACHE_UNIFORM_SUPPORT;i++)
	{
		m_cacheUniformLoc[i]=-2;
	}

	for(int i=0;i<static_cast<int>(E_StreamType::MAX_NU);i++)
	{
		m_seqStreamMaps[i]=NULL;
	}

	m_uniformMaps=FsArray::create();
	FS_NO_REF_DESTROY(m_uniformMaps);

	m_streamMaps=FsArray::create();
	FS_NO_REF_DESTROY(m_streamMaps);




}

Program::~Program()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
	}


	FS_SAFE_DESTROY(m_uniformMaps);
	FS_SAFE_DESTROY(m_streamMaps);

	FS_SAFE_DEC_REF(m_featureDesc);
}


const char* Program::className()
{
	return "Program";
}

NS_FS_END 

