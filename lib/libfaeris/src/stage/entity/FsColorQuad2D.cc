#include "stage/entity/FsColorQuad2D.h"
#include "graphics/material/FsColorMaterial.h"
#include "graphics/FsRender.h"

#include "FsGlobal.h"
#include "FsProgramMgr.h"
#include "graphics/material/FsColorMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN

const char* ColorQuad2D::className()const 
{
	return FS_COLOR_QUAD2D_CLASS_NAME;
}


ColorQuad2D* ColorQuad2D::create(const Rect2D& rect,Color4f c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(rect,c);
	return quad;
}

ColorQuad2D* ColorQuad2D::create(float width,float height,Color4f c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(width,height,c);
	return quad;
}


void ColorQuad2D::update(float dt)
{
	Entity::update(dt);
}

void ColorQuad2D::draw(Render* render,bool updateMatrix)
{
	if(!m_material||!m_program)
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

	render->disableAllAttrArray();

	
	int pos_loc=render->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);
	int color_loc=render->getCacheAttrLocation(FS_ATTR_C4F_LOC,FS_ATTR_C4F_NAME);


	float x=-m_width*m_anchorX;
	float y=-m_height*m_anchorY;

	float vv[8]=
	{
		x,		  y,
		x+m_width,y,
		x+m_width,y+m_height,
		x,        y+m_height,
	};
	

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,m_colors);
	render->setAndEnableVertexAttrPointer(color_loc,4,FS_FLOAT,4,0,vc);

	render->drawFace3(faces,2);

	render->popMatrix();
}




bool ColorQuad2D::hit2D(float x,float y)
{
	updateWorldMatrix();

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


void ColorQuad2D::setColor(Color4f c)
{
	m_material->setColor(c);
}

Color4f ColorQuad2D::getColor()
{
	return m_material->getColor();
}




void ColorQuad2D::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
}

void ColorQuad2D::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}

void ColorQuad2D::setSize(float w,float h)
{
	m_width=w;
	m_height=h;
}

void ColorQuad2D::getSize(float* w,float* h)
{
	*w=m_width;
	*h=m_height;
}






void ColorQuad2D::setVertexColor(Color4f c,int vertex)
{
	if(vertex&VERTEX_A)
	{
		m_va=c;
	}
	if(vertex&VERTEX_B)
	{
		m_vb=c;
	}
	if(vertex&VERTEX_C)
	{
		m_vc=c;
	}
	if(vertex&VERTEX_D)
	{
		m_vd=c;
	}
}

void ColorQuad2D::setRect2D(const Rect2D& rect)
{
	m_width=rect.width;
	m_height=rect.height;
	m_anchorX=-rect.x/rect.width;
	m_anchorY=-rect.y/rect.height;
}


Rect2D ColorQuad2D::getRect2D()
{
	return Rect2D(-m_anchorX*m_width,-m_anchorY*m_height,m_width,m_height);
}


ColorQuad2D::ColorQuad2D()
{
	m_width=0;
	m_height=0;
	m_anchorX=0.5;
	m_anchorY=0.5;

	m_material=ColorMaterial::create();
	m_material->addRef();

	m_program=FsGlobal::programMgr->load(FS_PRE_SHADER_V4F_C4F);
	FS_SAFE_ADD_REF(m_program);
}

ColorQuad2D::~ColorQuad2D()
{
	destroy();
}

void ColorQuad2D::init(const Rect2D& rect,Color4f c)
{
	m_va=c;
	m_vb=c;
	m_vc=c;
	m_vd=c;

	setRect2D(rect);

}

void ColorQuad2D::init(float width,float height,Color4f c)
{
	m_va=c;
	m_vb=c;
	m_vc=c;
	m_vd=c;

	m_width=width;
	m_height=height;
	m_anchorX=0.5;
	m_anchorY=0.5;



}

void ColorQuad2D::init()
{

}
void ColorQuad2D::destroy()
{
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_program);
}


NS_FS_END









