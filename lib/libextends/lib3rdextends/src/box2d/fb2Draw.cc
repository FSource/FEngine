#include "box2d/fb2Draw.h"
#include "FsGlobal.h"
#include "graphics/FsRenderDevice.h"

#include "math/FsVector2.h"
#include "math/FsMathUtil.h"

#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"

NS_FS_BEGIN

fb2Draw::fb2Draw(float ratio)
{
	m_ratio=ratio;
	m_material=Material2D::create();
	m_material->addRef();

	static ProgramSource* S_programSource=NULL;

	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
	}

	m_material->setProgramSource(S_programSource);

}


fb2Draw::~fb2Draw()
{
	FS_SAFE_DEC_REF(m_material);
}




void fb2Draw::DrawPolygon(const b2Vec2* old_vertices, int vertexCount,const b2Color& color)
{
	Vector2* vertices=new Vector2[vertexCount];

	for(int i=0;i<vertexCount;i++)
	{
		b2Vec2 tmp=old_vertices[i];
		tmp*=m_ratio;
		vertices[i].x=tmp.x;
		vertices[i].y=tmp.y;
	}


	RenderDevice* rd=Global::renderDevice();
	rd->pushWorldMatrix();
	rd->loadWorldMatrixIdentity();

	m_material->setColor(Color4f(color.r,color.g,color.b,1.0f));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	rd->setProgram(m_material->getProgram(NULL));

	m_material->configRenderDevice(rd);


	StreamMap* map_v=m_material->getProgram(NULL)->getStreamMap(E_StreamType::VERTICES);

	rd->disableAllAttrArray();

	int vertex_nu=vertexCount;

	rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertices);
	rd->drawArray(E_DrawMode::LINE_LOOP,0,vertex_nu);

	rd->popWorldMatrix();

	delete[] vertices;


}


void fb2Draw::DrawSolidPolygon(const b2Vec2* old_vertices,int32 vertexCount,const b2Color& color)
{
	Vector2* vertices=new Vector2[vertexCount];

	for(int i=0;i<vertexCount;i++)
	{
		b2Vec2 tmp=old_vertices[i];
		tmp*=m_ratio;
		vertices[i].x=tmp.x;
		vertices[i].y=tmp.y;
	}


	RenderDevice* r=Global::renderDevice();
	r->pushWorldMatrix();
	r->loadWorldMatrixIdentity();

	int vertex_nu=vertexCount;


	/* draw inner */
	m_material->setColor(Color4f(color.r*0.5f,color.g*0.5f,color.b*0.5f,0.5f));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	r->setProgram(m_material->getProgram(NULL));
	m_material->configRenderDevice(r);

	StreamMap* map_v=m_material->getProgram(NULL)->getStreamMap(E_StreamType::VERTICES);

	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertices);
	r->drawArray(E_DrawMode::TRIANGLE_FAN,0,vertexCount);


	/* draw outline */
	m_material->setColor(Color4f(color.r,color.g,color.b,1.0f));
	m_material->configRenderDevice(r);

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertices);
	r->drawArray(E_DrawMode::LINE_LOOP,0,vertex_nu);
	r->popWorldMatrix();

	delete[] vertices;

}

void fb2Draw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) 
{

	float32 k_segments=16.0f;
	int vertexCount=16;
	float32 k_increment=360.0f/k_segments;
	float32 theta=0.0f;

	Vector2 vertex[16];

	for(int32 i=0;i<k_segments;++i)
	{
		b2Vec2 v=center+radius*b2Vec2(Math::cosa(theta),Math::sina(theta));
		vertex[i].x=v.x*m_ratio;
		vertex[i].y=v.y*m_ratio;
		theta+= k_increment;
	}

	RenderDevice* r=Global::renderDevice();

	r->pushWorldMatrix();
	r->loadWorldMatrixIdentity();

	m_material->setColor(Color4f(color.r,color.g,color.b,1.0f));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);


	r->setProgram(m_material->getProgram(NULL));
	m_material->configRenderDevice(r);

	StreamMap* map_v=m_material->getProgram(NULL)->getStreamMap(E_StreamType::VERTICES);


	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertexCount,0,vertex);
	r->drawArray(E_DrawMode::LINE_LOOP,0,vertexCount);

	r->popWorldMatrix();	

}


void fb2Draw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) 
{
	float32 k_segments=16.0f;
	int vertexCount=16;
	float32 k_increment=360.0f/k_segments;
	float32 theta=0.0f;

	int vertex_nu=vertexCount;

	Vector2 vertex[16];

	for(int32 i=0;i<k_segments;++i)
	{
		b2Vec2 v=center+radius*b2Vec2(Math::cosa(theta),Math::sina(theta));
		vertex[i].x=v.x*m_ratio;
		vertex[i].y=v.y*m_ratio;
		theta+= k_increment;
	}

	RenderDevice* r=Global::renderDevice();
	r->pushWorldMatrix();
	r->loadWorldMatrixIdentity();

	m_material->setColor(Color4f(color.r*0.5f,color.g*0.5f,color.b*0.5f,0.5f));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	r->setProgram(m_material->getProgram(NULL));
	m_material->configRenderDevice(r);

	StreamMap* map_v=m_material->getProgram(NULL)->getStreamMap(E_StreamType::VERTICES);


	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(E_DrawMode::TRIANGLE_FAN,0,vertexCount);

	/* draw outline */
	m_material->setColor(Color4f(color.r,color.g,color.b,1.0f));
	m_material->configRenderDevice(r);

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(E_DrawMode::LINE_LOOP,0,vertex_nu);
	r->popWorldMatrix();

}

void fb2Draw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) 
{
	Vector2 vertex[2]={
		Vector2(p1.x*m_ratio,p1.y*m_ratio),
		Vector2(p2.x*m_ratio,p2.y*m_ratio),
	};

	int vertex_nu=2;

	RenderDevice* r=Global::renderDevice();
	r->pushWorldMatrix();
	r->loadWorldMatrixIdentity();

	

	m_material->setColor(Color4f(color.r,color.g,color.b,1.0f));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);


	r->setProgram(m_material->getProgram(NULL));
	m_material->configRenderDevice(r);
	StreamMap* map_v=m_material->getProgram(NULL)->getStreamMap(E_StreamType::VERTICES);

	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(E_DrawMode::LINE_LOOP,0,2);

	r->popWorldMatrix();

}

void fb2Draw::DrawTransform(const b2Transform& xf) 
{
	b2Vec2 p1=xf.p; 
	b2Vec2 p2;

	const float32 k_axisScale = 0.4f; 
	p2 = p1 + k_axisScale* xf.q.GetXAxis();
	DrawSegment(p1,p2,b2Color(1,0,0));

	p2=p1+k_axisScale* xf.q.GetYAxis();
	DrawSegment(p1,p2,b2Color(0,1,0));
}





NS_FS_END

