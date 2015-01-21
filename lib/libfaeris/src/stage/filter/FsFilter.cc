#include "FsFilter.h"

#include "graphics/FsRenderDevice.h"
#include "graphics/FsFrameBuffer.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/material/FsMaterial2D.h"

#include "math/FsTexCoord2.h"


NS_FS_BEGIN

void Filter::begin(RenderDevice* rd,float left,float right,float bottom,float top)
{

	m_oldRenderTarget=rd->getRenderTarget();
	FS_SAFE_ADD_REF(m_oldRenderTarget);

	int width=(int)Math::ceil(right-left);
	int height=(int)Math::ceil(top-bottom);

	m_oldProjMat=*rd->getProjectionMatrix();


	if(m_width!=width||m_height!=height)
	{
		m_width=width;
		m_height=height;
		if(m_frameBuffer)
		{
			m_frameBuffer->setSize((int)Math::ceil(m_width*m_precision),(int)Math::ceil(m_height*m_precision));
		}
	}

	if(m_frameBuffer==NULL)
	{
		m_frameBuffer=FrameBuffer::create((int)Math::ceil(m_width*m_precision),(int)Math::ceil(m_height*m_precision));
		FS_NO_REF_DESTROY(m_frameBuffer);
	}

	rd->setRenderTarget(m_frameBuffer);
	Color4f old_clear_color=rd->getClearColor();
	rd->setClearColor(Color4f(0.0f,0,0,0.0f));
	rd->clear();

	Matrix4 proj_mat;

	proj_mat.makeOrthographic(left,right,bottom,top,-1000,1000);

	rd->setProjectionMatrix(&proj_mat);

	rd->setClearColor(old_clear_color);
}

void Filter::end(RenderDevice* rd)
{
	if(m_oldRenderTarget)
	{
		rd->setProjectionMatrix(&m_oldProjMat);
		rd->setRenderTarget(m_oldRenderTarget);
		FS_SAFE_DEC_REF(m_oldRenderTarget);
		m_oldRenderTarget=NULL;
	}
}



void Filter::apply(RenderDevice* rd,float left,float right,float bottom,float top)
{
	Program* prog=m_material->getProgram(NULL);
	rd->setProgram(prog);
	rd->setWorldMatrix(&Matrix4::IDENTITY);

	configRender(rd);


	Vector2f vertices[4]={
		Vector2f(left,bottom),
		Vector2f(right,bottom),
		Vector2f(left,top),
		Vector2f(right,top)
	};

	static TexCoord2 texcoord[4]={
		TexCoord2(0.0f,0.0f),
		TexCoord2(1.0f,0.0f),
		TexCoord2(0.0f,1.0f),
		TexCoord2(1.0f,1.0f)
	};


	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);


	Texture2D* tex=m_frameBuffer->getColorTexture();
	rd->bindTexture(tex,0);



	rd->disableAllAttrArray();

	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,vertices);
	}

	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,texcoord);
	}

	rd->drawArray(E_DrawMode::TRIANGLE_STRIP,0,4);


}

void Filter::configRender(RenderDevice* rd)
{
	m_material->configRenderDevice(rd);
}




Filter::Filter()
{
	m_width=0;
	m_height=0;
	m_frameBuffer=NULL;
	m_precision=1.0;

	m_oldRenderTarget=NULL;
	m_material=Material2D::create();
	FS_NO_REF_DESTROY(m_material);

}

Filter::~Filter()
{
	if(m_frameBuffer)
	{
		FS_SAFE_DESTROY(m_frameBuffer);
	}
	FS_SAFE_DESTROY(m_material);
}








NS_FS_END 

