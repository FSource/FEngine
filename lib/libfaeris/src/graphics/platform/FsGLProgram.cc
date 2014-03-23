#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#else 
	#include "GL/glew.h"
#endif 

#include "graphics/FsProgram.h"
#include "support/util/FsLog.h"

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
	Program* ret=NULL;


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
	m_vertSrc=std::string(vertex_src);
	m_fragSrc=std::string(fragment_src);

	for(int i=0;i<FS_PROGRAM_CACHE_ATTR_SUPPORT;i++)
	{
		m_cacheAttrLoc[i]=-1;
	}

	for(int i=0;i<FS_PROGRAM_CACHE_UNIFORM_SUPPORT;i++)
	{
		m_cacheUniformLoc[i]=-1;
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





int Program::getAttrLocation(const char* name)
{

	int loc=glGetAttribLocation(m_program,name);
	return loc;
}
int Program::getCacheAttrLocation(int index,const char* name)
{
	if(m_cacheAttrLoc[index]==-1)
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
	if(m_cacheUniformLoc[index]==-1)
	{
		m_cacheUniformLoc[index]=getUniformLocation(name);
	}
	return m_cacheUniformLoc[index];
}

void Program::reload()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
		m_program=0;
	}
	init(m_vertSrc.c_str(),m_fragSrc.c_str());
}


void Program::markInvalid()
{
	m_program=0;
}

Program::Program()
{
	m_program=0;
}

Program::~Program()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
	}
}

const char* Program::className()
{
	return FS_PROGRAM_CLASS_NAME;
}

NS_FS_END 

