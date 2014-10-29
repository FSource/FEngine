#include "FsStateButton.h"

#include "graphics/shader/FsProgram.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgram.h"

#include "mgr/FsProgramSourceMgr.h"

#include "mgr/FsTextureMgr.h"

#include "FsGlobal.h"




#define FS_CHECK_STATE_VALID(st) \
	FS_TRACE_ERROR_ON(st<0 || st >=m_stateNu,"Invalid State")



NS_FS_BEGIN

const char* StateButton::className()
{
	return FS_STATE_BUTTON_CLASS_NAME;
}


StateButton::StateButton(int state_nu)
{
	init(state_nu);
}

StateButton::~StateButton()
{
	destruct();
}


bool StateButton::init(int state_nu)
{
	if( state_nu < 1)
	{
		state_nu=1;
	}

	m_stateNu=state_nu;

	m_states=new StateAttr[state_nu];
	m_tweenInfo=new TweenInfo*[state_nu];

	for( int i=0;i<state_nu;i++)
	{
		m_tweenInfo[i]=new TweenInfo[state_nu];
	}
	m_tweenFlags=0;

	m_tweenFromState=new StateAttr;
	m_tweenToState=&m_states[0];

	m_curTween=NULL;
	m_tweenTime=0;
	m_curState=0;
	m_stateDirty=true;

	m_size.set(0.0f,0.0f);
	m_anchor.set(0.5f,0.5f);

	m_texture=NULL;

	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F);

	}
	setProgramSource(S_programSource);

	setTouchEnabled(true);
	return true;
}

void StateButton::destruct()
{
	FS_SAFE_DELETES(m_states);

	for (int i=0;i<m_stateNu;i++)
	{
		FS_SAFE_DELETES(m_tweenInfo[i]);
	}
	FS_SAFE_DELETES(m_tweenInfo);
	FS_SAFE_DELETE(m_tweenFromState);

	m_tweenFromState=NULL;

	FS_SAFE_DEC_REF(m_texture);

}


/* State Attribute */

/* color */
void StateButton::setColor(const Color4f& value)
{
	m_material->setColor(value);
}

void StateButton::setColor(int st,const Color4f& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_color=value;

	markStateDirty();

}

Color4f StateButton::getColor() const 
{
	return m_material->getColor();
}

Color4f StateButton::getColor(int st) const 
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_color;
}

/* opacity */

void StateButton::setOpacity(float value)
{
	m_material->setOpacity(value);
}

float StateButton::getOpacity()const 
{
	return m_material->getOpacity();
}


void StateButton::setOpacity(int st,float value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_opacity=value;
	markStateDirty();

}

float StateButton::getOpacity(int st) const 
{
	return m_states[st].m_opacity;
}

/* texture */

void StateButton::setTexture(const char* filename)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);
	setTexture(tex);
}

void StateButton::setTexture(const char* filename,float width,float height)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);
	setTexture(tex,width,height);
}


void StateButton::setTexture(const char* filename,const Vector2& size)
{
	setTexture(filename,size.x,size.y);
}

void StateButton::setTexture(Texture2D* tex)
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

void StateButton::setTexture(Texture2D* tex,float width,float height)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	m_size.set(width,height);
}

void StateButton::setTexture(Texture2D* tex,const Vector2& size)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	m_size=size;
}

Texture2D* StateButton::getTexture()const 
{
	return m_texture;
}



void StateButton::setTexture(int st,const char* filename)
{
	FS_CHECK_STATE_VALID(st);
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);
	setTexture(st,tex);
}

void StateButton::setTexture(int st,const char* filename,float width,float height)
{
	FS_CHECK_STATE_VALID(st);
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);
	setTexture(st,tex,width,height);
}

void StateButton::setTexture(int st,const char* filename,const Vector2& size)
{
	setTexture(st,filename,size.x,size.y);
}


void StateButton::setTexture(int st,Texture2D* tex)
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

void StateButton::setTexture(int st,Texture2D* tex,float width,float height)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_texture,tex);
	m_states[st].m_size.set(width,height);
	markStateDirty();

}
void StateButton::setTexture(int st,Texture2D* tex,const Vector2& size)
{
	setTexture(st,tex,size.x,size.y);

}

Texture2D* StateButton::getTexture(int st) const
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_texture;
}	


/* size */ 

void StateButton::setSize(const Vector2& size)
{
	m_size=size;
}

void StateButton::setSize(float x,float y)
{
	m_size.set(x,y);
}

Vector2 StateButton::getSize() const
{
	return m_size;
}

void StateButton::setSize(int st,float x,float y)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_size.set(x,y);
	markStateDirty();
}
void StateButton::setSize(int st,const Vector2& size)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_size=size;
	markStateDirty();
}

Vector2 StateButton::getSize(int st) const
{
	return m_states[st].m_size;
}



/* anchor */

void StateButton::setAnchor(float x,float y)
{
	m_anchor.set(x,y);
}

void StateButton::setAnchor(const Vector2& size)
{
	m_anchor=size;
}

Vector2 StateButton::getAnchor() const 
{
	return m_anchor;
}

void StateButton::setAnchor(int st,float x,float y)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_anchor.set(x,y);
	markStateDirty();
}

void StateButton::setAnchor(int st,const Vector2& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_anchor=value;
	markStateDirty();
}

Vector2 StateButton::getAnchor(int st) const 
{
	return m_states[st].m_anchor;
}


/* rotate */

void StateButton::setRotate(int st,float x,float y,float z)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_rotate.set(x,y,z);
	markStateDirty();
}

void StateButton::setRotate(int st,const Vector3& value)
{

	FS_CHECK_STATE_VALID(st);
	m_states[st].m_rotate=value;
	markStateDirty();
}

Vector3 StateButton::getRotate(int st) const 
{
	return m_states[st].m_rotate;
}


/* scale */
void StateButton::setScale(int st,float x,float y,float z)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_scale.set(x,y,z);
	markStateDirty();
}

void StateButton::setScale(int st,const Vector3& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_scale=value;
	markStateDirty();
}

Vector3 StateButton::getScale(int st) const 
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_scale;
}


void StateButton::setChild(int st,FsArray* child)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_children,child);
	markStateDirty();
}

FsArray* StateButton::getChild(int st) const
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_children;
}

void StateButton::setTweenInfo(int from,int to,EaseExpr* easing,float time)
{
	if(from== -1)
	{

		for(int i=0;i<m_stateNu;i++)
		{
			setTweenInfo(i,to,easing,time);
		}

	}
	else if(to== -1)
	{
		for (int i=0;i<m_stateNu;i++)
		{
			setTweenInfo(from,i,easing,time);
		}
	}
	else 
	{
		FS_CHECK_STATE_VALID(from);
		FS_CHECK_STATE_VALID(to);
		FS_SAFE_ASSIGN(m_tweenInfo[from][to].m_easing,easing);
		m_tweenInfo[from][to].m_time=time;
	}

}


void StateButton::setTweenFlags(uint32_t flags)
{
	m_tweenFlags=flags;
	markStateDirty();
}

void StateButton::clearTweenFlags()
{
	m_tweenFlags=0;
	markStateDirty();
}

void StateButton::addTweenFlags(uint32_t flags)
{
	m_tweenFlags|=flags;
	markStateDirty();
}

void StateButton::removeTweenFlags(uint32_t flags)
{
	m_tweenFlags &= ~flags;
	markStateDirty();
}


void StateButton::setState(int st)
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
		m_tweenFromState->m_rotate=Entity::getRotate();
		m_tweenFromState->m_scale=Entity::getScale();

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



void StateButton::updateTween(float dt)
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


void StateButton::setAttributeWithState(StateAttr* st)
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


void StateButton::setAttributeWithState(StateAttr* from,StateAttr* to,EaseExpr* easing,float percent)
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

void StateButton::markStateDirty()
{
	m_stateDirty=true;
}



void StateButton::update(float dt)
{
	Entity::update(dt);
	updateTween(dt);
}


void StateButton::draw(RenderDevice* rd,bool update_matrix)
{
	Program* prog=getProgram(NULL);
	if(!m_texture||!prog)
	{
		return;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}

	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);

	m_material->configRenderDevice(rd);

	rd->bindTexture(m_texture,0);


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


	rd->disableAllAttrArray();

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);

	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,vv);
	}
	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,vc);
	}

	rd->drawFace3(faces,2);

}


bool StateButton::hit2D(float x,float y)
{

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

