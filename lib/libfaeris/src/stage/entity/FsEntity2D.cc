/*************************************************************************/
/*  FsEntity2D.cc                                                        */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "FsEntity2D.h"
#include "FsGlobal.h"
#include "FsClass.h"

NS_FS_BEGIN

Entity2D* Entity2D::create()
{
	Entity2D* ret=new Entity2D;
	return ret;
}


Entity2D::Entity2D()
{
	m_material=Material2D::create();
	FS_SAFE_ADD_REF(m_material);

	m_touchFocus=NULL;
	m_touchEnabled=0;
	m_touchesEnabled=0;
	m_dispatchTouchEnabled=0;
	m_dispatchTouchesEnabled=0;
	m_blockTouchEnabled=0;
	m_blockTouchesEnabled=0;

	m_size.set(0,0);
	m_anchor.set(0.5,0.5);

	onTouchBegin=nullptr;
	onTouchMove=nullptr;
	onTouchEnd=nullptr;
	onHit2D=nullptr;
}


Entity2D::~Entity2D()
{
	FS_SAFE_DEC_REF(m_material);
}


void Entity2D::setMaterial(Material2D* mat)
{
	FS_SAFE_ASSIGN(m_material,mat);
}

Material2D* Entity2D::getMaterial()
{
	return m_material;
}

void Entity2D::setColor(const Color4f& c)
{
	if(m_material) m_material->setColor(c);
}

Color4f Entity2D::getColor()
{
	if(m_material) return m_material->getColor();
	return Color4f();
}


void Entity2D::setOpacity(float opacity)
{
	if(m_material) m_material->setOpacity(opacity);
}


float Entity2D::getOpacity()
{
	if(m_material) return m_material->getOpacity();
	return 1.0f;
}

void Entity2D::setBlend(E_BlendEquation eq,E_BlendFactor src,E_BlendFactor dst)
{
	if(m_material)  m_material->setBlend(eq,src,dst); 
}

void Entity2D::setBlend(E_BlendFactor src,E_BlendFactor dst)
{
	if(m_material)
	{
		m_material->setBlend(src,dst);
	}
}

void Entity2D::setBlendSrc(E_BlendFactor src)
{
	if(m_material) 
	{
		m_material->setBlendSrc(src);
	}
}

E_BlendFactor Entity2D::getBlendSrc()
{
	if(m_material)
	{
		m_material->getBlendSrc();
	}
	return E_BlendFactor::SRC_ALPHA;
}


void Entity2D::setBlendDst(E_BlendFactor dst)
{
	if(m_material)
	{
		m_material->setBlendDst(dst);
	}
}


E_BlendFactor Entity2D::getBlendDst()
{
	if(m_material)
	{
		return m_material->getBlendDst();
	}
	return E_BlendFactor::ONE_MINUS_SRC_ALPHA;
}



void Entity2D::setBlendEquation(E_BlendEquation eq)
{
	if(m_material)
	{
		return m_material->setBlendEquation(eq);
	}
}

E_BlendEquation Entity2D::getBlendEquation()
{
	if(m_material)
	{
		return m_material->getBlendEquation();
	}
	return E_BlendEquation::ADD;
}


void Entity2D::setProgramSource(ProgramSource* ps)
{
	if(m_material) m_material->setProgramSource(ps);
}

void Entity2D::setProgramSource(const char* filename)
{
	ProgramSource* ps=NULL;

	if(filename!=NULL)
	{
		ps=(ProgramSource*)Global::programSourceMgr()->load(filename);
	}

	if(m_material)
	{
		m_material->setProgramSource(ps);
	}
}




ProgramSource* Entity2D::getProgramSource()
{
	if(m_material) return m_material->getProgramSource();

	return NULL;
}



Program* Entity2D::getProgram(ProgramFeatureDesc* desc)
{
	if(m_material) return m_material->getProgram(desc);

	return NULL;
}


/* touch */
void Entity2D::setTouchEnabled(bool enabled)
{
	m_touchEnabled=enabled;
}

bool Entity2D::getTouchEnabled()
{
	return m_touchEnabled;
}

void Entity2D::setBlockTouchEnabled(bool enabled)
{
	m_blockTouchEnabled=enabled;
}

bool Entity2D::getBlockTouchEnabled()
{
	return m_blockTouchEnabled;
}

void Entity2D::setBlockTouchesEnabled(bool enabled)
{
	m_blockTouchesEnabled=enabled;
}

bool Entity2D::getBlockTouchesEnabled()
{
	return m_blockTouchesEnabled;
}





bool Entity2D::touchBegin(float x,float y)
{
	m_touchFocus=NULL;

	if(m_dispatchTouchEnabled)
	{
		if(m_zorderDirty)
		{
			sortChildren();
			m_zorderDirty=false;
		}
		m_chirdren->lock();
		int child_nu=m_chirdren->size();
		for(int i=child_nu-1;i>=0;i--)
		{
			Entity2D* e=(Entity2D*)m_chirdren->get(i);
			if(e->getVisible()&&e->getTouchEnabled()&&e->getParent()==this&&FS_OBJECT_LAMBDA_CALL(e,onHit2D,hit2D,x,y))
			{
				/* NOTE: entity will detach when called touchBegin */
				bool ret=FS_OBJECT_LAMBDA_CALL(e,onTouchBegin,touchBegin,x,y);
				if(ret)
				{
					if(e->getParent()==this)
					{
						m_touchFocus=e;
					}
					break;
				}
			}
		}
		m_chirdren->unlock();
		m_chirdren->flush();
	}
	return m_touchFocus!=NULL;
}


bool Entity2D::touchMove(float x,float y)
{

	bool ret=false;
	m_chirdren->lock();
	if(m_touchFocus)
	{
		ret=FS_OBJECT_LAMBDA_CALL(m_touchFocus,onTouchMove,touchMove,x,y);
	}
	m_chirdren->unlock();
	m_chirdren->flush();

	return ret;
}

bool Entity2D::touchEnd(float x,float y)
{
	bool ret=false;
	m_chirdren->lock();
	if(m_touchFocus)
	{
		ret=FS_OBJECT_LAMBDA_CALL(m_touchFocus,onTouchEnd,touchEnd,x,y);
		m_touchFocus=NULL;
	}
	m_chirdren->unlock();
	m_chirdren->flush();
	return ret;
}


void Entity2D::setTouchesEnabled(bool enabled)
{
	m_touchesEnabled=enabled;
}
bool Entity2D::getTouchesEnabled()
{
	return m_touchesEnabled;
}


void Entity2D::setDispatchTouchEnabled(bool enabled)
{
	m_dispatchTouchEnabled=enabled;
}

bool Entity2D::getDispatchTouchEnabled()
{
	return m_dispatchTouchEnabled;
}

void Entity2D::setDispatchTouchesEnabled(bool enabled)
{
	m_dispatchTouchesEnabled=enabled;
}

bool Entity2D::getDispatchTouchesEnabled()
{
	return m_dispatchTouchesEnabled;
}




void Entity2D::addChild(Entity* en) 
{
	if(en==NULL)
	{
		FS_TRACE_WARN("Can't Add Null Child");
		return;
	}

	Entity2D* e2d=dynamic_cast<Entity2D*>(en);
	if(!e2d)
	{
		FS_TRACE_WARN("Entity2D Can Only Add Entity2D Child");
		return;
	}
	Entity::addChild(en);
}

void Entity2D::removeChild(Entity* n)
{
	Entity::removeChild(n);
	if(m_touchFocus == n)
	{
		m_touchFocus=NULL;
	}
}

void Entity2D::clearChild()
{
	m_touchFocus=NULL;
	Entity::clearChild();
}



void Entity2D::setSize(float x,float y)
{
	setSize(Vector2f(x,y));
}

void Entity2D::getSize(float* x,float* y)
{
	Vector2f v=getSize();
	*x=v.x;
	*y=v.y;
}


void Entity2D::setSize(const Vector2f& v)
{
	m_size=v;
}

Vector2 Entity2D::getSize()
{
	return m_size;
}



void Entity2D::setWidth(float v)
{
	Vector2 s=getSize();
	s.x=v;
	setSize(s);
}


float Entity2D::getWidth()
{
	return getSize().x;
}


void Entity2D::setHeight(float v)
{
	Vector2 s=getSize();
	s.y=v;
	setSize(s);
}

float Entity2D::getHeight()
{
	return getSize().y;
}



void Entity2D::setAnchor(float x,float y)
{
	setAnchor(Vector2(x,y));
}

void Entity2D::getAnchor(float* x,float* y)
{
	Vector2 v=getAnchor();
	*x=v.x;
	*y=v.y;
}



void Entity2D::setAnchor(const Vector2& v)
{
	m_anchor=v;
}

Vector2 Entity2D::getAnchor()
{
	return m_anchor;
}


void Entity2D::setAnchorX(float v)
{
	Vector2 s=getAnchor();
	s.x=v;
	setAnchor(s);
}

float Entity2D::getAnchorX()
{
	return getAnchor().x;
}



void Entity2D::setAnchorY(float v)
{
	Vector2 s=getAnchor();
	s.y=v;
	setAnchor(s);
}


float Entity2D::getAnchorY()
{
	return getAnchor().y;
}

void Entity2D::getBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;

	*minx=left;
	*maxx=right;
	*miny=bottom;
	*maxy=top;
}




void Entity2D::getTRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top,bottom,left,right;
	getRSBoundSize2D(&left,&right,&bottom,&top);

	Vector3 t=getPositionInWorld();
	*minx=left+t.x;
	*maxx=right+t.x;

	*miny=bottom+t.y;
	*maxy=top+t.y;
}


void Entity2D::getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy)
{
	float top=(1.0f-m_anchor.y)*m_size.y;
	float  bottom=-m_anchor.y*m_size.y;

	float left=-m_anchor.x*m_size.x;
	float right=(1.0f-m_anchor.x)*m_size.x;
	Vector3 s=getScale();
	Vector3 r=getRotate();


	if(Math::floatEqual(s.x,1.0f) 
			&&Math::floatEqual(s.y,1.0f)
			&&Math::floatEqual(r.x,0.0f)
			&&Math::floatEqual(r.y,0.0f)
			&&Math::floatEqual(r.z,0.0f))
	{
		*minx=left;
		*maxx=right;
		*miny=bottom;
		*maxy=top;
		return;
	}


	Matrix4 mat;
	mat.makeCompose(Vector3(0,0,0),r,E_EulerOrientType::XYZ,s);

	/* D-----C 
	 * |     |
	 * A-----B
	 */

	Vector3 vv[4]={
		Vector3(left,bottom,0),
		Vector3(right,bottom,0),
		Vector3(right,top,0),
		Vector3(left,top,0),
	};

	for(int i=0;i<4;i++)
	{
		vv[i]=mat.mulVector3(vv[i]);
	}

	float t_minx=vv[0].x;
	float t_maxx=vv[0].x;

	float t_miny=vv[0].y;
	float t_maxy=vv[0].y;

	for(int i=1;i<4;i++)
	{
		if(t_minx>vv[i].x) t_minx=vv[i].x;
		if(t_maxx<vv[i].x) t_maxx=vv[i].x;

		if(t_miny>vv[i].y) t_miny=vv[i].y;
		if(t_maxy<vv[i].y) t_maxy=vv[i].y;
	}

	*minx=t_minx;
	*maxx=t_maxx;
	*miny=t_miny;
	*maxy=t_maxy;
}

bool Entity2D::hit2D(float x,float y)
{
	updateWorldMatrix();
	Vector3 v=worldToLocal(Vector3(x,y,0));

	float diffx=v.x+m_anchor.x*m_size.x;
	float diffy=v.y+m_anchor.y*m_size.y;

	if(diffx>=0 && diffx <m_size.x)
	{
		if(diffy>=0 && diffy <m_size.y)
		{
			return true;
		}
	}
	return false;
}


/*** Use For Entity Entity2D  FsClass Attribute */
static Entity2D* Entity2D_NewInstance(FsDict* attr)
{
	Entity2D* ret=Entity2D::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}

	return ret;
}


/* touch */
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setTouchEnabled,getTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setTouchesEnabled,getTouchesEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setDispatchTouchEnabled,getDispatchTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setDispatchTouchesEnabled,getDispatchTouchesEnabled,bool);

/* material */
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setColor,getColor,Color4f);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setOpacity,getOpacity,float);
FS_CLASS_ATTR_SET_CHARS_FUNCTION(Entity2D,setProgramSource);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(Entity2D,setBlendEquation,getBlendEquation,BlendEquation);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(Entity2D,setBlendSrc,getBlendSrc,BlendFactor);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(Entity2D,setBlendDst,getBlendDst,BlendFactor);

/* size and anchor */

FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setSize,getSize,Vector2);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setWidth,getWidth,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setHeight,getHeight,float);

FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setAnchor,getAnchor,Vector2);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setAnchorX,getAnchorX,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity2D,setAnchorY,getAnchorY,float);

static FsClass::FsAttributeDeclare S_Entity2D_Anchor_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",E_FsType::FT_F_1,NULL,Entity2D_setAnchorX,Entity2D_getAnchorX),
	FS_CLASS_ATTR_DECLARE("y",E_FsType::FT_F_1,NULL,Entity2D_setAnchorY,Entity2D_getAnchorY),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_Entity2D_Size_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("w",E_FsType::FT_F_1,NULL,Entity2D_setWidth,Entity2D_getWidth),
	FS_CLASS_ATTR_DECLARE("h",E_FsType::FT_F_1,NULL,Entity2D_setHeight,Entity2D_getHeight),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};



static FsClass::FsAttributeDeclare S_Entity2D_Main_Attr[]={

	FS_CLASS_ATTR_DECLARE("color",E_FsType::FT_COLOR_4,NULL,Entity2D_setColor,Entity2D_getColor),
	FS_CLASS_ATTR_DECLARE("opacity",E_FsType::FT_F_1,NULL,Entity2D_setOpacity,Entity2D_getOpacity),
	FS_CLASS_ATTR_DECLARE("shader",E_FsType::FT_CHARS,NULL,Entity2D_setProgramSource,0),
	FS_CLASS_ATTR_DECLARE("blendEquation",E_FsType::FT_CHARS,NULL,Entity2D_setBlendEquation,Entity2D_getBlendEquation),
	FS_CLASS_ATTR_DECLARE("blendSrc",E_FsType::FT_CHARS,NULL,Entity2D_setBlendSrc,Entity2D_getBlendSrc),
	FS_CLASS_ATTR_DECLARE("blendDst",E_FsType::FT_CHARS,NULL,Entity2D_setBlendDst,Entity2D_getBlendDst),

	FS_CLASS_ATTR_DECLARE("anchor",E_FsType::FT_F_2,S_Entity2D_Anchor_SubAttr,Entity2D_setAnchor,Entity2D_getAnchor),
	FS_CLASS_ATTR_DECLARE("size",E_FsType::FT_F_2,S_Entity2D_Size_SubAttr,Entity2D_setSize,Entity2D_getSize),

	FS_CLASS_ATTR_DECLARE("touchEnabled",E_FsType::FT_B_1,NULL,Entity2D_setTouchEnabled,Entity2D_getTouchEnabled),
	FS_CLASS_ATTR_DECLARE("touchesEnabled",E_FsType::FT_B_1,NULL,Entity2D_setTouchesEnabled,Entity2D_getTouchesEnabled),
	FS_CLASS_ATTR_DECLARE("touchDispatchEnabled",E_FsType::FT_B_1,NULL,Entity2D_setDispatchTouchEnabled,Entity2D_getDispatchTouchEnabled),
	FS_CLASS_ATTR_DECLARE("touchesDispatchEnabled",E_FsType::FT_B_1,NULL,Entity2D_setDispatchTouchesEnabled,Entity2D_getDispatchTouchesEnabled),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Entity2D,Entity,Entity2D_NewInstance,S_Entity2D_Main_Attr);

NS_FS_END 


