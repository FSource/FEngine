#include "stage/entity/FsQuad2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRender.h"
#include "mgr/FsTextureMgr.h"

#include "FsGlobal.h"
#include "mgr/FsProgramMgr.h"

NS_FS_BEGIN


Quad2D* Quad2D::create(const char* tex)
{
	Quad2D* ret=new Quad2D;
	if(!ret->init(tex))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Quad2D* Quad2D::create(const char* tex,const Rect2D&  rect)
{
	Quad2D* ret=new Quad2D;
	if(!ret->init(tex))
	{
		delete ret;
		return NULL;
	}
	ret->setRect2D(rect);
	return ret;
}

Quad2D* Quad2D::create(const char* tex,float width,float height)
{
	return create(tex,Rect2D(-width/2.0f,-height/2.0f,width,height));
}




void Quad2D::setTexture(Texture2D* tex)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	if(m_texture)
	{
		m_width=(float)m_texture->getWidth();
		m_height=(float)m_texture->getHeight();
	}
	else 
	{
		m_width=0;
		m_height=0;
	}

}
void Quad2D::setTexture(const char* filename)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_SAFE_ASSIGN(m_texture,tex);
	if(m_texture)
	{
		m_width=(float)m_texture->getWidth();
		m_height=(float)m_texture->getHeight();
	}
	else 
	{
		m_width=0;
		m_height=0;
	}
}
void Quad2D::setResourceUrl(const char* name)
{
	setTexture(name);
}


Texture2D* Quad2D::getTexture()
{
	FS_SAFE_ADD_REF(m_texture);
	return m_texture;
}


void Quad2D::setRect2D(const Rect2D& rect)
{
	m_width=rect.width;
	m_height=rect.height;

	m_anchorX=-rect.x/m_width;
	m_anchorY=-rect.y/m_height;
}


Rect2D Quad2D::getRect2D()
{
	return Rect2D(-m_anchorX*m_width,-m_anchorY*m_height,m_width,m_height);
}


void Quad2D::setSize(float width,float height)
{
	if(m_width==width&&m_height==height)
	{
		return ;
	}

	m_width=width;
	m_height=height;
	m_vertiesDirty=true;
}

void Quad2D::setWidth(float width)
{
	if(m_width==width)
	{
		return;
	}

	m_width=width;
}
void Quad2D::setHeight(float height)
{
	if(m_height==height)
	{
		return;
	}

	m_height=height;
}


float Quad2D::getHeight()
{
	return m_height;
}

float Quad2D::getWidth()
{
	return m_width;
}


void Quad2D::getSize(float* w,float* h)
{
	*w=m_width;
	*h=m_height;
}

void Quad2D::setAnchorX(float x)
{
	if(m_anchorX==x)
	{
		return;
	}

	m_anchorX=x;
	m_vertiesDirty=true;
}
void Quad2D::setAnchorY(float y)
{
	if(m_anchorY==y)
	{
		return;
	}
	m_anchorY=y;
	m_vertiesDirty=true;
}

void Quad2D::setAnchor(float x,float y)
{
	if(m_anchorX==x&&m_anchorY==y)
	{
		return;
	}

	m_anchorX=x;
	m_anchorY=y;
	m_vertiesDirty=true;
}

void Quad2D::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}

float Quad2D::getAnchorX()
{
	return m_anchorX;
}

float Quad2D::getAnchorY()
{
	return m_anchorY;
}

void Quad2D::setRegionRect(float x,float y,float w,float h)
{
	float x2=x+w;
	float y2=y+h;
	
	m_rawVertices.resize(4);

	m_rawVertices[0].v2.x=x;
	m_rawVertices[0].v2.y=y;
	m_rawVertices[0].t2.tu=x;
	m_rawVertices[0].t2.tv=1-y;


	m_rawVertices[1].v2.x=x2;
	m_rawVertices[1].v2.y=y;
	m_rawVertices[1].t2.tu=x2;
	m_rawVertices[1].t2.tv=1-y;

	m_rawVertices[2].v2.x=x;
	m_rawVertices[2].v2.y=y2;
	m_rawVertices[2].t2.tu=x;
	m_rawVertices[2].t2.tv=1-y2;

	m_rawVertices[3].v2.x=x2;
	m_rawVertices[3].v2.y=y2;
	m_rawVertices[3].t2.tu=x2;
	m_rawVertices[3].t2.tv=1-y2;

	m_vertiesMode=Render::TRIANGLE_STRIP;

	m_vertiesDirty=true;

}

void Quad2D::setRegionRect(const Rect2D& rect)
{
	setRegionRect(rect.x,rect.y,rect.width,rect.height);
}


void Quad2D::setRegionCircle(const Vector2& center,float radius,int precision)
{
	setRegionCircle(center.x,center.y,radius,0,360,precision);
}

void Quad2D::setRegionCircle(float x,float y,float radius,int precision)
{
	setRegionCircle(x,y,radius,0,360,precision);
}
void Quad2D::setRegionCircle(const Vector2& center,float radius,float a_start,float a_end,int precision)
{
	setRegionCircle(center.x,center.y,radius,a_start,a_end,precision);
}


void Quad2D::setRegionCircle(float x,float y,float radius,float a_start,float a_end,int precision)
{
	setRegionEllipse(x,y,radius,radius,a_start,a_end,precision);

}

void Quad2D::setRegionEllipse(const Vector2& center,float a,float b,int precision)
{
	setRegionEllipse(center.x,center.y,a,b,0,360,precision);
}

void Quad2D::setRegionEllipse(float x,float y,float a,float b,int precision)
{
	setRegionEllipse(x,y,a,b,0,360,precision);
}

void Quad2D::setRegionEllipse(const Vector2& center,float a,float b,float a_start,float a_end,int precision)
{
	setRegionEllipse(center.x,center.y,a,b,a_start,a_end,precision);
}


void Quad2D::setRegionEllipse(float x,float y,float a ,float b,float a_start,float a_end,int precision)
{
	if(a_start>a_end)
	{
		float t=a_start;
		a_start=a_end;
		a_end=t;
	}

	if(precision < 8) 
	{
		precision=8;
	}

	m_rawVertices.resize(precision+2);

	float start_angle=a_start/180.0f*FS_PI;
	float end_angle=a_end/180.0f*FS_PI;
	float dtangle=(end_angle-start_angle)/precision;

	m_rawVertices[0].v2.x=x;
	m_rawVertices[0].v2.y=y;
	m_rawVertices[0].t2.tu=x;
	m_rawVertices[0].t2.tv=1-y;

	for(int i=1;i<precision+2;i++)
	{
		float tx=x+a*Math::cosr(dtangle*i+start_angle);
		float ty=y+b*Math::sinr(dtangle*i+start_angle);

		m_rawVertices[i].v2.x=tx;
		m_rawVertices[i].v2.y=ty;
		m_rawVertices[i].t2.tu=tx;
		m_rawVertices[i].t2.tv=1-ty;
	}	

	m_vertiesDirty=true;
	m_vertiesMode=Render::TRIANGLE_FAN;

}



void Quad2D::setRegionScale9(float edge)
{
	setRegionScale9(edge,edge,edge,edge);
}

void Quad2D::setRegionScale9(const Vector4& edge)
{
	setRegionScale9(edge.x,edge.y,edge.z,edge.w);
}


static inline void S_Scale9SetVertices(Fs_V2F_T2F* vertices,const Vector2& v1,const Vector2& v2,
													   const Vector2& t1,const Vector2& t2)
{
	vertices[0].v2.x=v1.x;
	vertices[0].v2.y=v1.y;
	vertices[0].t2.tu=t1.x;
	vertices[0].t2.tv=1-t1.y;


	vertices[1].v2.x=v2.x;
	vertices[1].v2.y=v1.y;
	vertices[1].t2.tu=t2.x;
	vertices[1].t2.tv=1-t1.y;

	vertices[2].v2.x=v2.x;
	vertices[2].v2.y=v2.y;
	vertices[2].t2.tu=t2.x;
	vertices[2].t2.tv=1-t2.y;


	vertices[3].v2.x=v1.x;
	vertices[3].v2.y=v2.y;
	vertices[3].t2.tu=t1.x;
	vertices[3].t2.tv=1-t2.y;



}



void Quad2D::setRegionScale9(float l,float r,float b,float t)
{
	if(m_texture==NULL)
	{
		FS_TRACE_WARN("Scale 9 Need Texture");
		return;
	}

	float tw=float(m_texture->getWidth());
	float th=float(m_texture->getHeight());


	float el=tw*l/m_width;
	float er=tw*r/m_width;

	if(el+er>1.0f)
	{
		float p=el/(el+er);
		el=p;
		er=1-p;
	}

	float eb=th*b/m_height;
	float et=th*t/m_height;
	if(eb+et>1.0f)
	{
		float p=eb/(eb+et);
		eb=p;
		et=1-p;
	}




	m_rawVertices.resize(16);

	Vector2 v1,v2,t1,t2;

	/* left bottom */
	v1.set(0,0);
	v2.set(el,eb);

	t1.set(0,0);
	t2.set(l,b);

	S_Scale9SetVertices(&m_rawVertices[0],v1,v2,t1,t2);


	/* right bottom */
	v1.set(1-er,0);
	v2.set(1,eb);
	t1.set(1-r,0);
	t2.set(1,b);
	S_Scale9SetVertices(&m_rawVertices[4],v1,v2,t1,t2);

	/* right top */
	v1.set(1-er,1-et);
	v2.set(1,1);
	t1.set(1-r,1-t);
	t2.set(1,1);
	S_Scale9SetVertices(&m_rawVertices[8],v1,v2,t1,t2);

	/* left top */
	v1.set(0,1-et);
	v2.set(el,1);

	t1.set(0,1-t);
	t2.set(l,1);
	S_Scale9SetVertices(&m_rawVertices[12],v1,v2,t1,t2);

	m_faces.resize(18);

	static Face3 faces[18]={
		Face3(0,1,3),
		Face3(3,1,2),

		Face3(1,4,2),
		Face3(2,4,7),

		Face3(4,5,7),
		Face3(7,5,6),

		Face3(7,6,8),
		Face3(8,6,9),

		Face3(8,9,11),
		Face3(11,9,10),

		Face3(13,8,14),
		Face3(14,8,11),

		Face3(12,13,15),
		Face3(15,13,14),

		Face3(3,2,12),
		Face3(12,2,13),

		Face3(2,7,13),
		Face3(13,7,8),
	};

	for (int i=0;i<18;i++)
	{
		m_faces[i]=faces[i];
	}

	m_vertiesDirty=true;
	m_vertiesMode=Render::TRIANGLE_INDEX;

}



void Quad2D::calFinishVertics()
{
	int size=m_rawVertices.size();
	m_finishVertices.resize(size);

	float x=-m_width*m_anchorX;
	float y=-m_height*m_anchorY;

	for(int i=0;i<size;i++)
	{
		m_finishVertices[i].v2.x=x+m_rawVertices[i].v2.x*m_width;
		m_finishVertices[i].v2.y=y+m_rawVertices[i].v2.y*m_height;
		m_finishVertices[i].t2=m_rawVertices[i].t2;
	}

}




void Quad2D::draw(Render* render,bool updateMatrix)
{
	if(m_texture==NULL||!m_program||!m_material)
	{
		return;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	render->setProgram(m_program);
	m_material->configRender(render);


	render->bindTexture(m_texture,0);
	render->disableAllAttrArray();


	int pos_loc=render->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);
	int tex_loc=render->getCacheAttrLocation(FS_ATTR_T2F_LOC,FS_ATTR_T2F_NAME);


	if(m_vertiesDirty)
	{
		calFinishVertics();
		m_vertiesDirty=false;
	}

	int size=m_finishVertices.size();


	render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,size,
										sizeof(Fs_V2F_T2F),
										&m_finishVertices[0].v2);

	render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,size,
										sizeof(Fs_V2F_T2F),
										&m_finishVertices[0].t2);

	if(m_vertiesMode==Render::TRIANGLE_INDEX)
	{
		render->drawFace3(&m_faces[0],m_faces.size());
		//render->drawFace3(&m_faces[0],2);
	}
	else 
	{
		render->drawArray(m_vertiesMode,0,size);
	}

	render->popMatrix();
}

bool Quad2D::hit2D(float x,float y)
{
	Vector3 t=worldToLocal(Vector3(x,y,0));
	float diffx=t.x+m_anchorX*m_width;
	float diffy=t.y+m_anchorY*m_height;


	if ((diffx>=0) && (diffx<m_width))
	{
		if((diffy>=0)&&(diffy<m_height))
		{
			return true;
		}
	}

	return false;
}


const char* Quad2D::className()
{
	return FS_QUAD2D_CLASS_NAME;
}





Quad2D::Quad2D()
{
	m_texture=NULL;
	m_material=NULL;
	m_width=0;
	m_height=0;
	m_anchorX=0.5;
	m_anchorY=0.5;
	m_vertiesDirty=true;
	m_vertiesMode=Render::TRIANGLE_INDEX;

	m_material=TextureMaterial::create();
	m_material->addRef();

	m_program=(Program*)Global::programMgr()->load(FS_PRE_SHADER_V4F_T2F);
	FS_SAFE_ADD_REF(m_program);

	setRegionRect(0,0,1,1);
}

Quad2D::~Quad2D()
{
	destruct();
}

bool Quad2D::init()
{
	m_texture=NULL;
	return true;
}




bool Quad2D::init(const char* file)
{
	FS_TRACE_WARN_ON(file==NULL,"texture path is NULL");
	Texture2D* tex=Global::textureMgr()->loadTexture(file);
	if(tex==NULL)
	{
		FS_TRACE_WARN("Can't Load Texture(%s)",file);
		return false;
	}
	bool ret=init(tex);
	return ret;
}


bool Quad2D::init(Texture2D* tex)
{
	m_width=(float)tex->getWidth();
	m_height=(float)tex->getHeight();
	FS_SAFE_ASSIGN(m_texture,tex);
	return true;
}



void Quad2D::destruct()
{
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_program);
}


NS_FS_END 












