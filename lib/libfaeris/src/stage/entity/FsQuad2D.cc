#include "stage/entity/FsQuad2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRender.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "FsGlobal.h"
#include "mgr/FsTextureMgr.h"

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

void Quad2D::setColor(Color c)
{
	m_color=c;
}
Color Quad2D::getColor()
{
	return m_color;
}

void Quad2D::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float Quad2D::getOpacity()
{
	return m_opacity;
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


Texture2D* Quad2D::getTexture()
{
	FS_SAFE_ADD_REF(m_texture);
	return m_texture;
}


void Quad2D::setTextureCoord(const Rect2D& coord)
{
	m_textureCoord=coord;
}

Rect2D Quad2D::getTextureCoord()
{
	return m_textureCoord;
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
	m_width=width;
	m_height=height;
}
void Quad2D::setWidth(float width)
{
	m_width=width;
}
void Quad2D::setHeight(float height)
{
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
	m_anchorX=x;
}
void Quad2D::setAnchorY(float y)
{
	m_anchorY=y;
}

void Quad2D::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
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







void Quad2D::draw(Render* render,bool updateMatrix)
{
	if(m_texture==NULL)
	{
		return;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);

	render->setMaterial(m_material);

	render->setActiveTexture(1);
	render->disableAllAttrArray();
	render->bindTexture(m_texture,0);

	float x=-m_width*m_anchorX;
	float y=-m_height*m_anchorY;



	float vv[8]=
	{
		x,		  y,
		x+m_width,y,
		x+m_width,y+m_height,
		x,        y+m_height,
	};

	float vc[8]=
	{
		m_textureCoord.x, 					   m_textureCoord.y+m_textureCoord.height,	  /* a */
		m_textureCoord.x+m_textureCoord.width, m_textureCoord.y+m_textureCoord.height,	  /* b */
		m_textureCoord.x+m_textureCoord.width, m_textureCoord.y,	  /* c */
		m_textureCoord.x, 					   m_textureCoord.y,	  /* d */
	};

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	int pos_loc=m_material->getV4FLocation();
	int tex_loc=m_material->getT2FLocation();
	render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,vv);
	render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,vc);
	render->drawFace3(faces,2);

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
	m_color=Color::WHITE;
	m_opacity=1.0f;
	m_texture=NULL;
	m_material=NULL;
	m_textureCoord.set(0,0,1,1);
	m_width=0;
	m_height=0;
	m_anchorX=0.5;
	m_anchorY=0.5;

}

Quad2D::~Quad2D()
{
	destruct();
}

bool Quad2D::init()
{
	m_texture=NULL;
	m_material=Mat_V4F_T2F::shareMaterial();
	FS_SAFE_ADD_REF(m_material);
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
	m_material=Mat_V4F_T2F::shareMaterial();
	FS_SAFE_ADD_REF(m_material);
	return true;
}



void Quad2D::destruct()
{
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_material);
}



NS_FS_END 












