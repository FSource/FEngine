#include "string.h"
#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#else 
	#include "GL/glew.h"
#endif 

#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsProgramSource.h"
#include "support/util/FsLog.h"
#include "graphics/shader/FsUniformMap.h"
#include "graphics/shader/FsStreamMap.h"

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
		int loc=glGetUniformLocation(m_program,map->m_name.c_str());
		if(loc>=0)
		{
			UniformMap* u=map->clone();
			u->m_location=loc;
			m_uniformMaps.push_back(map);
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
			m_streamMaps.push_back(s);
		}
	}
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
	m_streamMaps.push_back(map);
	m_seqStreamMaps[static_cast<int>(map->m_refType)]=map;
}





Program::Program()
{
	m_program=0;
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

}

Program::~Program()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
	}

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
}


const char* Program::className()
{
	return "Program";
}

NS_FS_END 

