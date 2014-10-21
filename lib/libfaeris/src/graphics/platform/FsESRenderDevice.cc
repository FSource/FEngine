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

#define S_FS_MARK_MATRIX_DIRTY(mask) \
	m_matrixDirtyFlags|=(mask)

#define S_FS_CLR_MATRIX_DIRTY(mask) \
	m_matrixDirtyFlags &=~(mask)

#define S_FS_IS_MATRIX_DIRTY(pos) \
	(m_matrixDirtyFlags & (1ul<<pos))


	




#define S_FS_PROJECTION_MATRIX_MASK \
	(1ul<<E_UnifomRef::PROJECTION) | \
	(1ul<<E_UnifomRef::PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::PROJECTION_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE) | \

#define S_FS_WORLD_MATRIX_MASK \
	(1ul<<E_UnifomRef::WORLD) | \
	(1ul<<E_UnifomRef::WORLD_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE) | \


#define S_FS_VIEW_MATRIX_MASK \
	(1ul<<E_UnifomRef::VIEW) | \
	(1ul<<E_UnifomRef::VIEW_TRANSPOSE) | \
	(1ul<<E_UnifomRef::VIEW_INVERSE) | \
	(1ul<<E_UnifomRef::VIEW_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::VIEW_PROJECTION_INVERSE_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_TRANSPOSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE) | \
	(1ul<<E_UnifomRef::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE) | \

	


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



static GLint FsBlendEquation_ToGLEnum(E_BlendEquation value)
{
	switch(value)
	{
		case E_BlendEquation::ADD:
			return GL_FUNC_ADD;

		case E_BlendEquation::SUBTRACT:
			return GL_FUNC_SUBTRACT;

		case E_BlendEquation::REVERSE_SUBTRACT:
			return GL_FUNC_REVERSE_SUBTRACT;

	}
	return 0;
}

static GLint FsBlendFactor_ToGLEnum(E_BlendFactor value)
{
	switch(value)
	{
		case E_BlendFactor::ZERO:
			return GL_ZERO;

		case E_BlendFactor::ONE:
			return GL_ONE;

		case E_BlendFactor::SRC_COLOR:  
			return GL_SRC_COLOR;

		case E_BlendFactor::ONE_MINUS_SRC_COLOR: 
			return GL_ONE_MINUS_SRC_COLOR;

		case E_BlendFactor::DST_COLOR:  
			return GL_DST_COLOR;

		case E_BlendFactor::ONE_MINUS_DST_COLOR: 
			return GL_ONE_MINUS_DST_COLOR;

		case E_BlendFactor::SRC_ALPHA:  
			return GL_SRC_ALPHA;

		case E_BlendFactor::ONE_MINUS_SRC_ALPHA: 
			return GL_ONE_MINUS_SRC_ALPHA;

		case E_BlendFactor::DST_ALPHA:  
			return GL_DST_ALPHA;

		case E_BlendFactor::ONE_MINUS_DST_ALPHA: 
			return GL_ONE_MINUS_DST_ALPHA;

		case E_BlendFactor::SRC_ALPHA_SATURATE:
			return GL_SRC_ALPHA_SATURATE;
		default: assert(0);
	}
	return 0;
}


static GLint FsPrimitive_ToGLEnum(E_DrawMode value)
{
	switch(value)
	{
		case E_DrawMode::POINTS: return GL_POINTS;
		case E_DrawMode::LINES:  return GL_LINES;
		case E_DrawMode::LINE_STRIP: return GL_LINE_STRIP;
		case E_DrawMode::LINE_LOOP:  return GL_LINE_LOOP;
		case E_DrawMode::TRIANGLES:  return GL_TRIANGLES;
		case E_DrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
		case E_DrawMode::TRIANGLE_FAN: 	 return GL_TRIANGLE_FAN;
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
	m_scissorArea.set(0,0,1,1);

	m_depthTest=false;
	m_depthWrite=false;

	m_viewportX=0;
	m_viewportY=0;
	m_viewportWidth=0;
	m_viewportHeight=0;

	/* depth */
	m_depthTest=false;
	m_depthWrit=false;
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(false);


	/* blend */
	m_blendEquation=E_BlendEquation::ADD;
	m_blendSrc=E_BlendFactor::SRC_ALPHA;
	m_blendDst=E_BlendFactor::ONE_MINUS_SRC_ALPHA;

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


	/* face */
	m_frontSided=FRONT_CCW;
	m_doubleSided=false;

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

	/* world matrix */
	m_worldStackIndex=0;
	m_world[0].makeIdentity();

	/* projection view matrix */
	m_projMatrix.makeIdentity();
	m_viewMatrix.makeIdentity();

	m_matrixDirtyFlags=~0ul;
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

RenderTarget* RenderDevice::getRenderTarget()
{
	return m_target;
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
	if(m_depthTest!=enable)
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
void RenderDevice::setDepthWriteEnabled(bool enable)
{
	if(m_depthWrite!=enable)
	{
		if(enable)
		{
			glDepthMask(true);
		}
		else 
		{
			glDepthMask(false);
		}
		m_depthWrite=enable;
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
		glBlendEquation(FsBlendEquation_ToGLEnum(eq));

		glBlendFunc(FsBlendFactor_ToGLEnum(fsrc),
				FsBlendFactor_ToGLEnum(fdst));
	}
	m_blendEquation=eq;
	m_blendSrc=fsrc;
	m_blendDst=fdst;
}

/* ----------------- MATRIX -------------------- */:w

/* transform */
void RenderDevice::setProjectionMatrix(const Matrix4* m)
{
	m_projMatrix=*m;
	S_FS_MARK_MATRIX_DIRTY(S_FS_PROJECTION_MATRIX_MASK);
}

Matrix4 * RenderDevice::getProjectionMatrix()
{
	return &m_projMatrix;
}

void RenderDevice::setViewMatrix(const Matrix4* m)
{
	m_viewMatrix=*m;
	S_FS_MARK_MATRIX_DIRTY(S_FS_VIEW_MATRIX_MASK);
}

Matrix4* RenderDevice::getViewMatrix()
{
	return m_viewMatrix;
}


void RenderDevice::setWorldMatrix(const Matrix4* m)
{
	m_world[m_worldStackIndex]=*m;
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

Matrix4* RenderDevice::getWorldMatrix()
{
	return &m_world[m_worldStackIndex];
}



void RenderDevice::pushWorldMatrix()
{
	if(m_worldStackIndex>=FS_MAX_RENDER_STACK_NU)
	{
		FS_TRACE_ERROR("Stack Overflow");
		return;	
	}
	m_world[m_worldStackIndex+1]=m_world[m_worldStackIndex];
	m_worldStackIndex++;
}

void RenderDevice::popWorldMatrix()
{
	if(m_worldStackIndex<=0)
	{
		FS_TRACE_ERROR("Stack Overflow");
		return;
	}
	m_worldStackIndex--;
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

void RenderDevice::loadWorldIdentity()
{
	m_world[m_worldStackIndex].makeIdentity();
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

void RenderDevice::mulWorldMatrix(const Matrix4* m)
{
	m_world[m_worldStackIndex].mul(*m);
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

void RenderDevice::translateWorldMatrix(const Vector3& s)
{
	m_world[m_worldStackIndex].translate(s);
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

void RenderDevice::scaleWorldMatrix(const Vector3& s)
{
	m_world[m_worldStackIndex].scale(s);
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}


void RenderDevice::rotateWorldMatrix(const Vector3& s,float angle)
{
	m_world[m_worldStackIndex].rotateByAxis(s,angle);
	S_FS_MARK_MATRIX_DIRTY(S_FS_WORLD_MATRIX_MASK);
}

Matrix4* RenderDevice::getMatrix(E_UniformType t)
{
	switch(t)
	{
		/* world matrix */
		case E_UniformType::WORLD:
			return &m_world[m_worldStackIndex];

		case E_UniformType::WORLD_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::WORLD_TRANSPOSE]=m_world[m_worldStackIndex];
				m_cacheMatrix[E_UniformType::WORLD_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_TRANSPOSE];

		case E_UniformType::WORLD_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_INVERSE]=m_world[m_worldStackIndex];
				m_cacheMatrix[E_UniformType::WORLD_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_INVERSE];

		case E_UniformType::WORLD_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_INVERSE_TRANSPOSE]=m_world[m_worldStackIndex];
				m_cacheMatrix[E_UniformType::WORLD_INVERSE_TRANSPOSE].inverse();
				m_cacheMatrix[E_UniformType::WORLD_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_INVERSE_TRANSPOSE];


		/* view matrix */
		case E_UniformType::VIEW:
			return &m_viewMatrix;

		case E_UniformType::VIEW_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::VIEW_TRANSPOSE]=m_viewMatrix;
				m_cacheMatrix[E_UniformType::VIEW_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_TRANSPOSE];

		case E_UniformType::VIEW_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::VIEW_INVERSE]=m_viewMatrix;
				m_cacheMatrix[E_UniformType::VIEW_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_INVERSE];

		case E_UniformType::VIEW_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::VIEW_INVERSE_TRANSPOSE]=*getMatrix(E_UniformType::VIEW_INVERSE);
				m_cacheMatrix[E_UniformType::VIEW_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_INVERSE_TRANSPOSE];

		/* projection matrix */
		case E_UniformType::PROJECTION:
			return &m_projMatrix;

		case E_UniformType::PROJECTION_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::PROJECTION_TRANSPOSE]=m_projMatrix;
				m_cacheMatrix[E_UniformType::PROJECTION_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::PROJECTION_TRANSPOSE];

		case E_UniformType::PROJECTION_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::PROJECTION_INVERSE]=m_projMatrix;
				m_cacheMatrix[E_UniformType::PROJECTION_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::PROJECTION_INVERSE];

		case E_UniformType::PROJECTION_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::PROJECTION_INVERSE_TRANSPOSE]=*getMatrix(E_UniformType::PROJECTION_INVERSE);
				m_cacheMatrix[E_UniformType::PROJECTION_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::PROJECTION_INVERSE_TRANSPOSE];

		/* world view */
		case E_UniformType::WORLD_VIEW:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW))
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW]=m_world[m_worldStackIndex];
				m_cacheMatrix[E_UniformType::WORLD_VIEW].mul(m_viewMatrix);
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW);
			}
			return m_cacheMatrix[E_UniformType::WORLD_VIEW];


		case E_UniformType::WORLD_VIEW_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_TRANSPOSE]=*getMatrix(E_UniformType::WORLD_VIEW);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_TRANSPOSE];

		case E_UniformType::WORLD_VIEW_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::PROJECTION_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE]=*getMatrix(E_UniformType::WORLD_VIEW);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE];

		case E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE]=*getMatrix(E_UniformType::WORLD_VIEW_INVERSE);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_INVERSE_TRANSPOSE];

		/* view  projection*/
		case E_UniformType::VIEW_PROJECTION:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION))
			{
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION]=m_viewMatrix;
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION]=mul(m_projMatrix);
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION);
			}
			return m_cacheMatrix[E_UniformType::VIEW_PROJECTION];


		case E_UniformType::VIEW_PROJECTION_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_TRANSPOSE]=*getMatrix(E_UniformType::VIEW_PROJECTION);
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_PROJECTION_TRANSPOSE];

		case E_UniformType::VIEW_PROJECTION_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE]=*getMatrix(E_UniformType::VIEW_PROJECTION);
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE];

		case E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE]=*getMatrix(E_UniformType::VIEW_PROJECTION_INVERSE);
				m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::VIEW_PROJECTION_INVERSE_TRANSPOSE];

		/* world view  projection*/
		case E_UniformType::WORLD_VIEW_PROJECTION:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION))
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION]=m_world[m_worldStackIndex];
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION]=mul(getMatrix(VIEW_PROJECTION));
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION);
			}
			return m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION];


		case E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE))
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE]=*getMatrix(E_UniformType::WORLD_VIEW_PROJECTION);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_TRANSPOSE];

		case E_UniformType::WORLD_VIEW_PROJECTION_INVERSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_INVERSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE]=*getMatrix(E_UniformType::WORLD_VIEW_PROJECTION);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE].inverse();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_INVERSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE];

		case E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE:
			if(S_FS_IS_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE)) 
			{
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE]=*getMatrix(E_UniformType::WORLD_VIEW_PROJECTION_INVERSE);
				m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE].transpose();
				S_FS_CLR_MATRIX_DIRTY(1ul<<E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE);
			}
			return &m_cacheMatrix[E_UniformType::WORLD_VIEW_PROJECTION_INVERSE_TRANSPOSE];
		default:
			FS_TRACE_WARN("Unkown Enum for Get Matrix");
			return NULL;
	}

	return NULL;
}





/* attribute */

int RenderDevice::getAttrLocation(const char* name)
{
	if(!m_program)
	{
		return -1;
	}
	return m_program->getAttrLocation(name);
}


int RenderDevice::getCacheAttrLocation(int index,const char* name)
{
	if(!m_program)
	{
		return -1;
	}
	return m_program->getCacheAttrLocation(index,name);
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


/* uniform */
int RenderDevice::getUniformLocation(const char* name)
{
	if(!m_program)
	{
		return -1;
	}

	return m_program->getUniformLocation(name);
}

int RenderDevice::getCacheUniformLocation(int index,const char* name)
{
	if(!m_program)
	{
		return -1;
	}

	return m_program->getCacheUniformLocation(index,name);
}


void RenderDevice::setUniform(E_UniformType loc,int type,int count,void* value)
{                                                                          
	if(loc<0)
	{
		//FS_TRACE_WARN("Ivalid Uniform Loc");
		return ;
	}

	switch(type)
	{
		/* float vec */
		case E_UniformType::UT_F_1:
			glUniform1fv(loc,count,(GLfloat*) value);
			break;
		case E_UniformType::UT_F_2:
			glUniform2fv(loc,count,(GLfloat*) value);
			break;
		case E_UniformType::UT_F_3:
			glUniform3fv(loc,count,(GLfloat*) value);
			break;
		case E_UniformType::UT_F_4:
			glUniform4fv(loc,count,(GLfloat*) value);
			break;

		/* int vec */                                                      
		case E_UniformType::UT_I_1:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_I_2:
			glUniform2iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_I_3:
			glUniform3iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_I_4:
			glUniform4iv(loc,count,(GLint*) value);
			break;

		/* uint */
		case E_UniformType::UT_UI_1:
			glUniform1uiv(loc,count,(GLuint*) value);
			break;
		case E_UniformType::UT_UI_2:
			glUniform2uiv(loc,count,(GLuint*) value);
			break;
		case E_UniformType::UT_UI_3:
			glUniform3uiv(loc,count,(GLuint*) value);
			break;
		case E_UniformType::UT_UI_4:
			glUniform4uiv(loc,count,(GLuint*) value);
			break;

		/* matrix vec */
		case E_UniformType::UT_M_2:
			glUniformMatrix2fv(loc,count,GL_FALSE,(GLfloat*) value);
			break;
		case E_UniformType::UT_M_3:
			glUniformMatrix3fv(loc,count,GL_FALSE,(GLfloat*) value);      
			break;
		case E_UniformType::UT_M_4:
			glUniformMatrix4fv(loc,count,GL_FALSE,(GLfloat*) value);
			break;

		/* sampler */
		case E_UniformType::UT_S_1D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_S_2D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_S_3D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_S_CUBE:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_S_1D_SHADOW:      
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case E_UniformType::UT_S_2D_SHADOW:
			glUniform1iv(loc,count,(GLint*) value);
			break;

		case E_UniformType::UT_REF:
			{
				int ref_nu=*(int*)data;
				if(ref_nu>0 && ref_nu<E_UnifomRef::MAX_MATRIX_NU)
				{
					glUniformMatrix4fv(loc,1,getMatrix(ref_nu));
				}
				else 
				{
					switch(ref_nu)
					{
						case E_UnifomRef::TIME:
							{
								float t=m_timer.now();
								glUniform1fv(loc,1,&t);
								break;
							}
						case E_UnifomRef::VIEWPORT_WIDTH:
							{
								float width=m_viewportWidth;
								glUniform1fv(loc,1,&width);
								break;
							}
						case E_UnifomRef::VIEWPORT_WIDTH_INVERSE:
							{
								float w=1.0f/m_viewportWidth;
								glUniform1fv(loc,1,&w);
								break;
							}
						case E_UnifomRef::VIEWPORT_HEIGHT:
							{
								float height=m_viewportHeight;
								glUniform1fv(loc,1,&height);
								break;
							}
						case E_UnifomRef::VIEWPORT_HEIGHT_INVERSE:
							{
								float h=1.0f/m_viewportHeight;
								glUniform1fv(loc,1,&h);
								break;
							}
						case E_UnifomRef::COLOR:
							{
								glUniform4fv(loc,1,&m_color);
								break;
							}
						case E_UnifomRef::OPACITY:
							{
								glUniform1fv(loc,1,&m_opacity);
								break;
							}
						default:
							FS_TRACE_WARN("Unkown Ref type(%d)",ref_nu);
					}
				}
			}

		default:
			FS_TRACE_WARN("Unkown Uniform Type");
	}
}


void RenderDevice::setUniform(int loc,int ref)
{
}


void RenderDevice::setUniform(int loc,UniformValue* v)
{
	void* data=v->getData();
	int type=v->getType();
	int count=v->getCount();

	setUniform(loc,type,count,data);
}





/* face */
void RenderDevice::drawFace3(Face3* f,uint num)
{
	glDrawElements(GL_TRIANGLES,num*3,GL_UNSIGNED_SHORT,f);

}

void RenderDevice::drawArray(E_DrawMode mode,int start,uint size)
{
	GLint mode_gl=FsPrimitive_ToGLEnum(mode);
	glDrawArrays(mode_gl,start,size);

}


NS_FS_END



















