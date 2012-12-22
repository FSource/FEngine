#include <GL/gl.h>
#include "graphics/FsRender.h"

FAERIS_NAMESPACE_BEGIN


Render::Render()
{
	glClearColor(0,0,0,1);
	glClearDepth(1);
	glClearStencil(0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	m_target=NULL;
	m_material=NULL;
}


void Render::pushMatrix()
{
	glPushMatrix();
}
void Render::popMatrix()
{
	glPopMatrix();
}
void Render::translate(const Vector3& v)
{
	glTranslatef(v.x,v.y,v.z);
}
void Render::scale(const Vector3& v)
{
	glScalef(v.x,v.y,v.z);
}
void Render::rotate(const Vector3& v,FsFloat angle)
{
	glRotatef(angle,v.x,v.y,v.z);
}
void Render::setViewport(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glViewport(x,y,width,height);
}

void Render::setClearColor(Color c)
{
	m_clearColor=c;
	glClearColor(c.r/255.0f,c.g/255.0f,c.b/255.0f,c.a/255.0f);
}


void Render::clear(FsBool color,FsBool depth,FsBool stencil)
{
	GLint flags=0;
	if(color) flags|=GL_COLOR_BUFFER_BIT;
	if(depth) flags|=GL_DEPTH_BUFFER_BIT;
	if(stencil) flags|=GL_STENCIL_BUFFER_BIT;
	glClear(flags);
}

void Render::setScissor(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glScissor(x,y,width,height);
}
void Render::enableScissorTest(FsBool enable)
{
	if(m_scissorEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_SCISSOR_TEST);
		}
		else
		{
			glDisable(GL_SCISSOR_TEST);
		}
		m_scissorEnable=enable;
	}
}
void Render::enableDepthTest(FsBool enable)
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
void Render::setDepthMask(FsBool enable)
{
	if(m_depthMask!=enable)
	{
		glDepthMask(enable);
		m_depthMask=enable;
	}
}

void Render::setLineWidth(FsFloat width)
{
	if(m_lineWidth!=width)
	{
		glLineWidth(width);
		m_lineWidth=width;
	}
}

void Render::enableFog(FsBool enable)
{
	if(m_fogEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_FOG);
		}
		else
		{
			glDisable(GL_FOG);
		}
		m_fogEnable=enable;
	}
}

void Render::setMaterial(Material* mat,bool force)
{
	if(!force)
	{
		if(mat==m_material) { return ; }
	}

	if(mat!=NULL)
	{
		mat->addRef();
	}

	if(m_material!=NULL)
	{
		m_material->unload(this);
		m_material->decRef();
	}
	if(mat) mat->load(this);
	m_material=mat;
}

void Render::setRenderTarget(RenderTarget* target)
{
	if(target) target->addRef();
	if(m_target)
	{
	   	m_target->loseCurrent(this);
		m_target->decRef();
	}

	if(target) { target->makeCurrent(this); }
	m_target=target;
}
void Render::swapBuffers()
{
	if(m_target) m_target->swapBuffers();
}



//void Render::enablePolygonOffset(FsBool){}
//oid Render::setPolygonOffset(FsFloat factor,FsFloat units);


FAERIS_NAMESPACE_END

