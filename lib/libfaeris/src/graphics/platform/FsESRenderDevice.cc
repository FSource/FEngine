#include <string.h>
#include <math.h>

#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "GL_Android/gles_2.0.h"
#else 
	#include "GL/glew.h"
#endif 

#include "graphics/material/FsMaterial.h"
#include "FsESRenderDevice.h"
#include "graphics/FsProgram.h"
#include "graphics/FsTexture2D.h"
#include "math/FsMatrix4.h"
#include "support/util/FsString.h"

NS_FS_BEGIN
static GLint FsType_ToGLEnum(int t)
{
	switch(t)
	{
		case FS_FLOAT:  return GL_FLOAT;
		case FS_INT:    return GL_INT;
		case FS_INT8:   return GL_BYTE;
		case FS_INT16:  return GL_SHORT;
		case FS_INT32:  return GL_INT;
		case FS_UINT8:  return GL_UNSIGNED_BYTE;
		case FS_UINT16: return GL_UNSIGNED_SHORT;
		case FS_UINT32: return GL_UNSIGNED_INT;
		default: assert(0);
	}
	return 0;
}


static GLint FsBlend_ToGLEnum(int value)
{
	switch(value)
	{
		case RenderDevice::EQUATION_ADD:      
			return GL_FUNC_ADD;

		case RenderDevice::EQUATION_SUBTRACT: 
			return GL_FUNC_SUBTRACT;

		case RenderDevice::EQUATION_REVERSE_SUBTRACT:
			return GL_FUNC_REVERSE_SUBTRACT;

		case RenderDevice::FACTOR_ZERO:       
			return GL_ZERO;
		case RenderDevice::FACTOR_ONE:        
			return GL_ONE;
		case RenderDevice::FACTOR_SRC_COLOR:  
			return GL_SRC_COLOR;
		case RenderDevice::FACTOR_ONE_MINUS_SRC_COLOR: 
			return GL_ONE_MINUS_SRC_COLOR;
		case RenderDevice::FACTOR_DST_COLOR:  
			return GL_DST_COLOR;
		case RenderDevice::FACTOR_ONE_MINUS_DST_COLOR: 
			return GL_ONE_MINUS_DST_COLOR;
		case RenderDevice::FACTOR_SRC_ALPHA:  
			return GL_SRC_ALPHA;
		case RenderDevice::FACTOR_ONE_MINUS_SRC_ALPHA: 
			return GL_ONE_MINUS_SRC_ALPHA;
		case RenderDevice::FACTOR_DST_ALPHA:  
			return GL_DST_ALPHA;
		case RenderDevice::FACTOR_ONE_MINUS_DST_ALPHA: 
			return GL_ONE_MINUS_DST_ALPHA;
		case RenderDevice::FACTOR_SRC_ALPHA_SATURATE:
			return GL_SRC_ALPHA_SATURATE;
		default: assert(0);
	}
	return 0;
}

static GLint FsPrimitive_ToGLEnum(int value)
{
	switch(value)
	{
		case RenderDevice::POINTS: return GL_POINTS;
		case RenderDevice::LINES:  return GL_LINES;
		case RenderDevice::LINE_STRIP: return GL_LINE_STRIP;
		case RenderDevice::LINE_LOOP:  return GL_LINE_LOOP;
		case RenderDevice::TRIANGLES:  return GL_TRIANGLES;
		case RenderDevice::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
		case RenderDevice::TRIANGLE_FAN: 	 return GL_TRIANGLE_FAN;
		default:assert(0);
	}
	return 0;
}


RenderDevice* RenderDevice::create()
{
	RenderDevice* ret=new RenderDevice;
	return ret;
}

const char* RenderDevice::className()
{
	return FS_RENDER_CLASS_NAME;
}

RenderDevice::RenderDevice()
{
	m_target=NULL;
	m_program=NULL;


	/* cache GL State */
	m_clearColor=Color4f(0.0f,0.0f,0.0f,1.0f);
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	m_color=Color4f::WHITE;
	m_opacity=1.0f;

	m_scissorEnable=false;
	m_depthTest=false;
	m_viewportX=0;
	m_viewportY=0;
	m_viewportWidth=0;
	m_viewportHeight=0;
	m_scissorArea.set(0,0,1,1);

	/* blend */
	m_blendEquation=EQUATION_ADD;
	m_blendSrc=FACTOR_SRC_ALPHA;
	m_blendDst=FACTOR_ONE_MINUS_SRC_ALPHA;
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	/* depth */
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_DEPTH_TEST);


	/* face */
	m_frontFace=FRONT_CCW;
	m_cullFace=false;
	glFrontFace(GL_CCW);
	glDisable(GL_CULL_FACE);



	/* texture */
	m_activeTextureId=0;
	glActiveTexture(GL_TEXTURE0);



	/* vertex array */
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,&m_vertexAttrMaxNu);
	m_vertexAttrFlags=new bool[m_vertexAttrMaxNu];
	memset(m_vertexAttrFlags,0,sizeof(bool)*m_vertexAttrMaxNu);
	m_vertexAttrEnableNu=0;


	/* transform */
	m_stackIndex=0;
	m_stack[0].makeIdentity();

	/* model view projection matrix */
	m_mvpDirty=true;

}

RenderDevice::~RenderDevice()
{
	if(m_target)
	{
		m_target->loseCurrent(this);
		m_target->decRef();
	}


	if(m_program)
	{
		m_program->decRef();
	}
	delete[] m_vertexAttrFlags;
}


void RenderDevice::setProgram(Program* prog)
{
	if(m_program==prog)
	{
		return;
	}

	FS_SAFE_ADD_REF(prog);

	if(m_program)
	{
		m_program->decRef();
		disableAllAttrArray();
	}

	if(prog)
	{
		GLint plat_prog=prog->getPlatformProgram();
		glUseProgram(plat_prog);
	}
	else 
	{
		glUseProgram(0);
	}
	m_program=prog;
}

void RenderDevice::bindTexture(Texture2D* tex,int slot)
{
	if(m_activeTextureId != slot )
	{
		glActiveTexture(GL_TEXTURE0+slot);
		m_activeTextureId=slot;
	}

	if(tex)
	{
		glBindTexture(GL_TEXTURE_2D,tex->getPlatformTexture());
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D,0);
	}
}

/* render target */
void RenderDevice::setRenderTarget(RenderTarget* target)
{
	FS_SAFE_ADD_REF(target);
	if(m_target)
	{
		m_target->loseCurrent(this);
		m_target->decRef();
	}
	if(target){ target->makeCurrent(this);}
	m_target=target;
}

void RenderDevice::swapBuffers()
{
	if(m_target) m_target->swapBuffers();
}


/* color */
void RenderDevice::clear(bool color,bool depth,bool stencil)
{
	

	glClearColor(m_clearColor.r,
			 	 m_clearColor.g,
				 m_clearColor.b,
				 m_clearColor.a);

	GLint flags=0;
	if(color) flags|=GL_COLOR_BUFFER_BIT;
	if(depth) flags|=GL_DEPTH_BUFFER_BIT;
	if(stencil) flags|=GL_STENCIL_BUFFER_BIT;
	glClear(flags);

}

/* transform */
void RenderDevice::setProjectionMatrix(const Matrix4* m)
{
	m_projMatrix=*m;
	m_mvpDirty=true;
}

void RenderDevice::pushMatrix()
{
	if(m_stackIndex>=FS_MAX_RENDER_STACK_NU)
	{
		FS_TRACE_ERROR("Stack Overflow");
		return;	
	}
	m_stack[m_stackIndex+1]=m_stack[m_stackIndex];
	m_stackIndex++;
}
void RenderDevice::popMatrix()
{
	if(m_stackIndex<=0)
	{
		FS_TRACE_ERROR("Stack Overflow");
		return;
	}
	m_stackIndex--;
	m_mvpDirty=true;
}
void RenderDevice::loadIdentity()
{
	m_stack[m_stackIndex].makeIdentity();
	m_mvpDirty=true;
}

void RenderDevice::mulMatrix(const Matrix4* m)
{
	m_stack[m_stackIndex].mul(*m);
	m_mvpDirty=true;
}

void RenderDevice::setMatrix(const Matrix4* m)
{
	m_stack[m_stackIndex]=*m;
	m_mvpDirty=true;
}
void RenderDevice::translate(const Vector3& s)
{
	m_stack[m_stackIndex].translate(s);
	m_mvpDirty=true;
}
void RenderDevice::scale(const Vector3& s)
{
	m_stack[m_stackIndex].scale(s);
	m_mvpDirty=true;
}
void RenderDevice::rotate(const Vector3& s,float angle)
{
	m_stack[m_stackIndex].rotateByAxis(s,angle);
	m_mvpDirty=true;
}

Matrix4* RenderDevice::getProjectionMatrix() 
{
	return &m_projMatrix;
}
Matrix4* RenderDevice::getMatrix()
{
	return m_stack+m_stackIndex;
}
Matrix4* RenderDevice::getMVPMatrix()
{
	if(m_mvpDirty)
	{
		m_mvpMatrix=m_projMatrix;
		m_mvpMatrix.mul(m_stack[m_stackIndex]);

		m_mvpDirty=false;
	}
	return &m_mvpMatrix;
}


void RenderDevice::disableAllAttrArray()
{
	if(m_vertexAttrEnableNu==0)
	{
		return ;
	}
	for(int i=0;i<m_vertexAttrMaxNu;i++)
	{
		if(m_vertexAttrFlags[i])
		{
			glDisableVertexAttribArray(i);
			m_vertexAttrEnableNu--;
			m_vertexAttrFlags[i]=false;
			if(m_vertexAttrEnableNu==0)
			{
				break;
			}
		}
	}
}

void RenderDevice::enableAttrArray(int index)
{
	if(!m_vertexAttrFlags[index])
	{
		m_vertexAttrFlags[index]=true;
		glEnableVertexAttribArray(index);
		m_vertexAttrEnableNu++;
	}
}
void RenderDevice::disableAttrArray(int index)
{
	if(m_vertexAttrFlags[index])
	{
		m_vertexAttrFlags[index]=false;
		glDisableVertexAttribArray(index);
		m_vertexAttrEnableNu--;
	}
}

void RenderDevice::setVertexAttrPointer(int index,int size,int type,
					int count,int stride,void* pointer)
{
	GLint type_gl=FsType_ToGLEnum(type);
	glVertexAttribPointer(index,size,type_gl,0,stride,pointer);
}
void RenderDevice::setAndEnableVertexAttrPointer(int index,int size,int type,
								  int count,int stride,void* pointer)
{
	enableAttrArray(index);
	GLint type_gl=FsType_ToGLEnum(type);
	glVertexAttribPointer(index,size,type_gl,0,stride,pointer);
}

void RenderDevice::drawFace3(Face3* f,uint num)
{
	glDrawElements(GL_TRIANGLES,num*3,GL_UNSIGNED_SHORT,f);

}

void RenderDevice::drawArray(int mode,int start,uint size)
{

	GLint mode_gl=FsPrimitive_ToGLEnum(mode);
	glDrawArrays(mode_gl,start,size);

}
	


/* set opengl state */
void RenderDevice::setViewport(int x,int y,int width,int height)
{
	m_viewportX=x;
	m_viewportY=y;
	m_viewportWidth=width;
	m_viewportHeight=height;
	glViewport(x,y,width,height);
}


void RenderDevice::setScissorArea(const Rect2D& area)
{
	m_scissorArea=area;
	if(m_scissorEnable)
	{
		_setGLScissor(m_scissorArea);
	}
}

void RenderDevice::setScissorArea(float x,float y,float width,float height)
{
	m_scissorArea.set(x,y,width,height);
	if(m_scissorEnable)
	{
		_setGLScissor(m_scissorArea);
	}
}

Rect2D RenderDevice::getScissorArea()
{
	return m_scissorArea;
}


bool RenderDevice::getScissorEnabled()
{
	return m_scissorEnable;
}





void RenderDevice::setScissorEnabled(bool enable)
{
	if(m_scissorEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_SCISSOR_TEST);
			_setGLScissor(m_scissorArea);
		}
		else
		{
			glDisable(GL_SCISSOR_TEST);
		}
		m_scissorEnable=enable;
	}
}

void RenderDevice::_setGLScissor(const Rect2D& scissor_area)
{
	int x= (int)floor(scissor_area.x*m_viewportWidth+m_viewportX+0.5f);
	int y= (int)floor(scissor_area.y*m_viewportHeight+m_viewportY+0.5f); 
	int width=(int)floor(scissor_area.width*m_viewportWidth+0.5f);
	int height=(int)floor(scissor_area.height*m_viewportHeight+0.5f);

	glScissor(x,y,width,height);
}

void RenderDevice::setDepthTest(bool enable)
{
	if(m_depthTest==enable)
	{
		if(enable)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
		m_depthTest=enable;
	}
}


void RenderDevice::setBlend(int eq,int fsrc,int fdst)
{
	if((eq==m_blendEquation) 
		&&(fsrc==m_blendSrc )
		&&(fdst==m_blendDst))
	{
		return ;
	}

	if(eq==EQUATION_NONE) 
	{
		glDisable(GL_BLEND);
	}
	else 
	{
		if(m_blendEquation==EQUATION_NONE)
		{
			glEnable(GL_BLEND);
		}
		glBlendEquation(FsBlend_ToGLEnum(eq));

		glBlendFunc(FsBlend_ToGLEnum(fsrc),
				FsBlend_ToGLEnum(fdst));
	}
	m_blendEquation=eq;
	m_blendSrc=fsrc;
	m_blendDst=fdst;
}

void RenderDevice::setUniform(int loc,int type,int count,void* value)
{                                                                          
	if(loc<0)
	{
		//FS_TRACE_WARN("Ivalid Uniform Loc");
		return ;
	}

	switch(type)
	{
		/* float vec */
		case U_F_1:
			glUniform1fv(loc,count,(GLfloat*) value);
			break;
		case U_F_2:
			glUniform2fv(loc,count,(GLfloat*) value);
			break;
		case U_F_3:
			glUniform3fv(loc,count,(GLfloat*) value);
			break;
		case U_F_4:
			glUniform4fv(loc,count,(GLfloat*) value);
			break;

		/* int vec */                                                      
		case U_I_1:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_I_2:
			glUniform2iv(loc,count,(GLint*) value);
			break;
		case U_I_3:
			glUniform3iv(loc,count,(GLint*) value);
			break;
		case U_I_4:
			glUniform4iv(loc,count,(GLint*) value);
			break;


		/* matrix vec */
		case U_M_2:
			glUniformMatrix2fv(loc,count,GL_FALSE,(GLfloat*) value);
			break;
		case U_M_3:
			glUniformMatrix3fv(loc,count,GL_FALSE,(GLfloat*) value);      
			break;
		case U_M_4:
			glUniformMatrix4fv(loc,count,GL_FALSE,(GLfloat*) value);
			break;

		/* sampler */
		case U_S_1D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_2D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_3D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_CUBE:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_1D_SHADOW:      
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_2D_SHADOW:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		default:
			FS_TRACE_WARN("Unkown Uniform Type");
	}
}


int RenderDevice::getUniformLocation(const char* name)
{
	if(!m_program)
	{
		return -1;
	}

	return m_program->getUniformLocation(name);
}

int RenderDevice::getAttrLocation(const char* name)
{
	if(!m_program)
	{
		return -1;
	}
	return m_program->getAttrLocation(name);
}


int RenderDevice::getCacheUniformLocation(int index,const char* name)
{
	if(!m_program)
	{
		return -1;
	}

	return m_program->getCacheUniformLocation(index,name);
}

int RenderDevice::getCacheAttrLocation(int index,const char* name)
{
	if(!m_program)
	{
		return -1;
	}
	return m_program->getCacheAttrLocation(index,name);
}


NS_FS_END



















