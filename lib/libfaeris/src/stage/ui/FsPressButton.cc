#include "stage/ui/FsPressButton.h"
#include "graphics/FsProgram.h"
#include "graphics/FsTexture2D.h"
#include "graphics/material/FsColorMaterial.h"
#include "graphics/FsRender.h"

#include "mgr/FsProgramMgr.h"
#include "mgr/FsTextureMgr.h"
#include "math/easing/FsLinearEase.h"
#include "FsGlobal.h"




#define FS_CHECK_STATE_VALID(st) \
	FS_TRACE_ERROR_ON(st<0 || st >=STATE_NU,"Invalid State")


NS_FS_BEGIN

const char* PressButton::className()
{
	return FS_PRESS_BUTTON_CLASS_NAME;
}

PressButton* PressButton::create()
{
	PressButton* ret=new PressButton();
	return ret;
}

PressButton* PressButton::createWithDarkStyle(const char* filename,const Color4f& dark)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't Load Texture(%s) For PressButton",filename);
	return createWithDarkStyle(texture,dark);
}

PressButton* PressButton::createWithDarkStyle(Texture2D* tex,const Color4f& dark)
{
	PressButton* ret=new PressButton();
	ret->initWithDarkStyle(tex,dark);
	return ret;
}




PressButton* PressButton::createWithScaleStyle(const char*  filename,const Vector3& scale)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't loadTexture(%s) For PressButton",filename);
	return createWithScaleStyle(texture,scale);
}


PressButton* PressButton::createWithScaleStyle(Texture2D* tex,const Vector3& scale)
{
	PressButton* ret=new PressButton();
	ret->initWithScaleStyle(tex,scale);
	return ret;
}



PressButton::PressButton()
{
	init();
}

PressButton::~PressButton()
{
	destruct();
}

bool PressButton::init()
{
	m_tweenFlags=0;

	m_tweenFromState=new PressButtonState;
	m_tweenToState=&m_states[STATE_NORMAL];


	m_curTween=NULL;
	m_tweenTime=0;

	m_curState=STATE_NORMAL;
	m_stateDirty=true;

	m_size.set(0.0f,0.0f);
	m_anchor.set(0.5f,0.5f);

	m_moveIn=false;
	m_disabled=false;

	m_material=ColorMaterial::create();
	m_material->addRef();

	m_program=(Program*)Global::programMgr()->load(FS_PRE_SHADER_V4F_T2F);
	FS_SAFE_ADD_REF(m_program);
	m_texture=NULL;

	return true;
}

void PressButton::destruct()
{
	FS_SAFE_DELETE(m_tweenFromState);
	m_tweenFromState=NULL;

	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_program);

}

void PressButton::initWithDarkStyle(Texture2D* texture,const Color4f& dark)
{

	setTexture(texture);

	setTweenFlags(FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.5f);

	setColor(STATE_PRESS,dark);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
}

void PressButton::initWithScaleStyle(Texture2D* texture,const Vector3& scale)
{
	setTexture(texture);

	setTweenFlags(FLAG_SCALE|FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.5f);

	setScale(STATE_PRESS,scale);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
	
}


/* State Attribute */

/* color */
void PressButton::setColor(const Color4f& value)
{
	m_material->setColor(value);
}

void PressButton::setColor(int st,const Color4f& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_color=value;

	markStateDirty();

}

Color4f PressButton::getColor() const 
{
	return m_material->getColor();
}

Color4f PressButton::getColor(int st) const 
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_color;
}

/* opacity */

void PressButton::setOpacity(float value)
{
	m_material->setOpacity(value);
}

float PressButton::getOpacity()const 
{
	return m_material->getOpacity();
}


void PressButton::setOpacity(int st,float value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_opacity=value;
	markStateDirty();

}

float PressButton::getOpacity(int st) const 
{
	return m_states[st].m_opacity;
}

/* texture */

void PressButton::setTexture(const char* filename)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For PressButton",filename);
	setTexture(tex);
}

void PressButton::setTexture(const char* filename,float width,float height)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For PressButton",filename);
	setTexture(tex,width,height);
}


void PressButton::setTexture(const char* filename,const Vector2& size)
{
	setTexture(filename,size.x,size.y);
}

void PressButton::setTexture(Texture2D* tex)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	if(m_texture)
	{
		m_size.x=(float)m_texture->getWidth();
		m_size.y=(float)m_texture->getHeight();
	}
	else
	{
		m_size.set(0,0);
	}
}

void PressButton::setTexture(Texture2D* tex,float width,float height)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	m_size.set(width,height);
}

void PressButton::setTexture(Texture2D* tex,const Vector2& size)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	m_size=size;
}

Texture2D* PressButton::getTexture()const 
{
	return m_texture;
}



void PressButton::setTexture(int st,const char* filename)
{
	FS_CHECK_STATE_VALID(st);
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For PressButton",filename);
	setTexture(st,tex);
}

void PressButton::setTexture(int st,const char* filename,float width,float height)
{
	FS_CHECK_STATE_VALID(st);
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For PressButton",filename);
	setTexture(st,tex,width,height);
}

void PressButton::setTexture(int st,const char* filename,const Vector2& size)
{
	setTexture(st,filename,size.x,size.y);
}


void PressButton::setTexture(int st,Texture2D* tex)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_texture,tex);

	if(m_states[st].m_texture)
	{
		m_states[st].m_size.set((float)tex->getWidth(),(float)tex->getHeight());
	}
	else
	{
		m_states[st].m_size.set(0,0);
	}

	markStateDirty();
}

void PressButton::setTexture(int st,Texture2D* tex,float width,float height)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_texture,tex);
	m_states[st].m_size.set(width,height);
	markStateDirty();

}
void PressButton::setTexture(int st,Texture2D* tex,const Vector2& size)
{
	setTexture(st,tex,size.x,size.y);

}

Texture2D* PressButton::getTexture(int st) const
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_texture;
}	


/* size */ 

void PressButton::setSize(const Vector2& size)
{
	m_size=size;
}

void PressButton::setSize(float x,float y)
{
	m_size.set(x,y);
}

Vector2 PressButton::getSize() const
{
	return m_size;
}

void PressButton::setSize(int st,float x,float y)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_size.set(x,y);
	markStateDirty();
}
void PressButton::setSize(int st,const Vector2& size)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_size=size;
	markStateDirty();
}

Vector2 PressButton::getSize(int st) const
{
	return m_states[st].m_size;
}



/* anchor */

void PressButton::setAnchor(float x,float y)
{
	m_anchor.set(x,y);
}

void PressButton::setAnchor(const Vector2& size)
{
	m_anchor=size;
}

Vector2 PressButton::getAnchor() const 
{
	return m_anchor;
}

void PressButton::setAnchor(int st,float x,float y)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_anchor.set(x,y);
	markStateDirty();
}

void PressButton::setAnchor(int st,const Vector2& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_anchor=value;
	markStateDirty();
}

Vector2 PressButton::getAnchor(int st) const 
{
	return m_states[st].m_anchor;
}


/* rotate */

void PressButton::setRotate(int st,float x,float y,float z)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_rotate.set(x,y,z);
	markStateDirty();
}

void PressButton::setRotate(int st,const Vector3& value)
{

	FS_CHECK_STATE_VALID(st);
	m_states[st].m_rotate=value;
	markStateDirty();
}

Vector3 PressButton::getRotate(int st) const 
{
	return m_states[st].m_rotate;
}


/* scale */
void PressButton::setScale(int st,float x,float y,float z)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_scale.set(x,y,z);
	markStateDirty();
}

void PressButton::setScale(int st,const Vector3& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_scale=value;
	markStateDirty();
}

Vector3 PressButton::getScale(int st) const 
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_scale;
}


void PressButton::setChild(int st,FsArray* child)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_children,child);
	markStateDirty();
}

FsArray* PressButton::getChild(int st) const
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_children;
}

void PressButton::setTweenInfo(int from,int to,EaseExpr* easing,float time)
{
	if(from== STATE_ALL)
	{
		setTweenInfo(STATE_NORMAL,to,easing,time);
		setTweenInfo(STATE_PRESS,to,easing,time);
		setTweenInfo(STATE_DISABLE,to,easing,time);
	}
	else if(to==STATE_ALL)
	{
		setTweenInfo(from,STATE_NORMAL,easing,time);
		setTweenInfo(from,STATE_PRESS,easing,time);
		setTweenInfo(from,STATE_DISABLE,easing,time);
	}
	else 
	{
		FS_CHECK_STATE_VALID(from);
		FS_CHECK_STATE_VALID(to);
		FS_SAFE_ASSIGN(m_tweenInfo[from][to].m_easing,easing);
		m_tweenInfo[from][to].m_time=time;
	}

}

void PressButton::setDisabled(bool value)
{
	if(m_disabled==value)
	{
		return;
	}

	m_disabled=value;
	
	if(m_disabled)
	{
		setState(STATE_DISABLE);
	}
	else 
	{
		setState(STATE_NORMAL);
	}

}

bool PressButton::getDisabled() const
{
	return m_disabled;
}



void PressButton::setTweenFlags(uint32_t flags)
{
	m_tweenFlags=flags;
	markStateDirty();
}

void PressButton::clearTweenFlags()
{
	m_tweenFlags=0;
	markStateDirty();
}

void PressButton::addTweenFlags(uint32_t flags)
{
	m_tweenFlags|=flags;
	markStateDirty();
}

void PressButton::removeTweenFlags(uint32_t flags)
{
	m_tweenFlags &= ~flags;
	markStateDirty();
}


/* touch handle */
bool PressButton::touchBegin(float x,float y)
{
	if(m_disabled)
	{
		return false;
	}


	m_moveIn=true;
	this->pressDown(x,y);

	return  true;
}


bool PressButton::touchMove(float x,float y)
{
	bool hit=hit2D(x,y);
	if(hit)
	{
		if(!m_moveIn)
		{
			m_moveIn=true;
			this->pressMoveIn(x,y);
		}
	}
	else 
	{
		if(m_moveIn)
		{
			m_moveIn=false;
			this->pressMoveOut(x,y);
		}
	}
	return true;
}

bool PressButton::touchEnd(float x,float y)
{
	bool hit=hit2D(x,y);
	if(hit)
	{
		this->pressUp(x,y);
		this->click();
	}
	else 
	{
		this->pressUp(x,y);
		this->cancel();
	}
	return true;
}

void PressButton::pressDown(float x,float y)
{
	if(!m_disabled)
	{
		setState(STATE_PRESS);
	}
}
void PressButton::pressMoveIn(float x,float y)
{
	if(!m_disabled)
	{
		setState(STATE_PRESS);
	}

}

void PressButton::pressMoveOut(float x,float y)
{
	if(!m_disabled)
	{
		setState(STATE_NORMAL);
	}
}

void PressButton::pressUp(float x,float y)
{
	if(!m_disabled)
	{
		setState(STATE_NORMAL);
	}
}

void PressButton::cancel()
{

}

void PressButton::click()
{
	/* Do Nothing Here 
	   SubClass Overrite it */
}


void PressButton::setState(int st)
{
	if(m_curState==st)
	{
		return;
	}

	m_curTween=&m_tweenInfo[m_curState][st];
	m_tweenTime=m_curTween->m_time;


	m_tweenToState=&m_states[st];


	if(m_curTween->m_easing==NULL||m_curTween->m_time==0)
	{
		setAttributeWithState(m_tweenToState);
		m_curTween=NULL;
		m_tweenTime=0;
	}
	else 
	{
		FS_SAFE_ASSIGN(m_tweenFromState->m_texture,m_texture);

		m_tweenFromState->m_color=m_material->getColor();
		m_tweenFromState->m_opacity=m_material->getOpacity();
		m_tweenFromState->m_size=m_size;
		m_tweenFromState->m_anchor=m_anchor;
		m_tweenFromState->m_rotate=m_rotate;
		m_tweenFromState->m_scale=m_scale;

		m_tweenFromState->m_children=NULL;
		if(m_tweenFlags&FLAG_TEXTURE)
		{
			FS_SAFE_ASSIGN(m_texture,m_tweenToState->m_texture);
		}

		if(m_tweenFlags&FLAG_CHILDREN)
		{
			clearChild();
			if(m_tweenToState->m_children)
			{
				int child_nu=m_tweenToState->m_children->size();
				for(int i=0;i<child_nu;i++)
				{
					Entity* e=(Entity*) m_tweenToState->m_children->get(i);
					addChild(e);
				}
			}
		}
	}
	m_curState=st;

}



void PressButton::updateTween(float dt)
{
	if(m_curTween)
	{
		m_tweenTime-=dt;
		if(m_tweenTime<0)
		{
			m_tweenTime=0;
			setAttributeWithState(m_tweenToState);
			m_curTween=NULL;
		}
		else 
		{
			float percent=1-m_tweenTime/m_curTween->m_time;
			setAttributeWithState(m_tweenFromState,m_tweenToState,m_curTween->m_easing,percent);
		}
		m_stateDirty=false;
	}
	else
	{
		if(m_stateDirty)
		{
			setAttributeWithState(m_tweenToState);
			m_stateDirty=false;
		}
	}
}


void PressButton::setAttributeWithState(PressButtonState* st)
{
	if(m_tweenFlags&FLAG_COLOR)
	{
		m_material->setColor(st->m_color);
	}
	if(m_tweenFlags&FLAG_OPACITY)
	{
		m_material->setOpacity(st->m_opacity);
	}

	if(m_tweenFlags&FLAG_SIZE)
	{
		m_size=st->m_size;
	}

	if(m_tweenFlags&FLAG_ANCHOR)
	{
		m_anchor=st->m_anchor;
	}

	if(m_tweenFlags&FLAG_ROTATE)
	{
		Entity::setRotate(st->m_rotate);
	}

	if(m_tweenFlags&FLAG_SCALE)
	{
		Entity::setScale(st->m_scale);
	}

	if(m_tweenFlags&FLAG_TEXTURE)
	{
		FS_SAFE_ASSIGN(m_texture,st->m_texture);
	}

	if(m_tweenFlags&FLAG_CHILDREN)
	{
		clearChild();
		if(st->m_children)
		{
			int child_nu=st->m_children->size();
			for(int i=0;i<child_nu;i++)
			{
				Entity* e=(Entity*) st->m_children->get(i);
				addChild(e);
			}
		}
	}
}


void PressButton::setAttributeWithState(PressButtonState* from,PressButtonState* to,EaseExpr* easing,float percent)
{
	float r_p=easing->getValue(percent);

	if(m_tweenFlags&FLAG_COLOR)
	{
		m_material->setColor(from->m_color.lerp(to->m_color,r_p));
	}

	if(m_tweenFlags&FLAG_OPACITY)
	{
		m_material->setOpacity(from->m_opacity+(to->m_opacity-from->m_opacity)*r_p);
	}

	if(m_tweenFlags&FLAG_SIZE)
	{
		m_size=from->m_size.lerp(to->m_size,r_p);
	}

	if(m_tweenFlags&FLAG_ANCHOR)
	{
		m_anchor=from->m_anchor.lerp(to->m_anchor,r_p);
	}

	if(m_tweenFlags&FLAG_ROTATE)
	{
		Entity::setRotate(from->m_rotate.lerp(to->m_rotate,r_p));
	}

	if(m_tweenFlags&FLAG_SCALE)
	{
		Entity::setScale(from->m_scale.lerp(to->m_scale,r_p));
	}
}

void PressButton::markStateDirty()
{
	m_stateDirty=true;
}



void PressButton::update(float dt)
{
	Entity::update(dt);
	updateTween(dt);
}


void PressButton::draw(Render* render,bool update_matrix)
{
	if(!m_texture||!m_program||!m_material)
	{
		return;
	}
	if(update_matrix)
	{
		updateWorldMatrix();
	}

	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	render->setProgram(m_program);
	m_material->configRender(render);

	render->bindTexture(m_texture,0);



	float x=-m_size.x*m_anchor.x;
	float y=-m_size.y*m_anchor.y;

	float vv[8]=
	{
		x,		  y,
		x+m_size.x,y,
		x+m_size.x,y+m_size.y,
		x,        y+m_size.y,
	};


	static float vc[8]=
	{
		0,1,
		1,1,
		1,0,
		0,0,
	};

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};


	render->disableAllAttrArray();

	int pos_loc=render->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);
	int tex_loc=render->getCacheAttrLocation(FS_ATTR_T2F_LOC,FS_ATTR_T2F_NAME);


	render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,vv);
	render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,vc);

	render->drawFace3(faces,2);

	render->popMatrix();


}


bool PressButton::hit2D(float x,float y)
{
	if(m_disabled) 
	{
		return false;
	}

	Vector3 t=worldToLocal(Vector3(x,y,0));
	float diffx=t.x+m_anchor.x*m_size.x;
	float diffy=t.y+m_anchor.y*m_size.y;


	if ((diffx>=0) && (diffx<m_size.x))
	{
		if((diffy>=0)&&(diffy<m_size.y))
		{
			return true;
		}
	}
	return false;
}





















NS_FS_END












