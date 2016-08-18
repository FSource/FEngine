/*************************************************************************/
/*  FsStateButton.cc                                                     */
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


#include "FsStateButton.h"

#include "graphics/shader/FsProgram.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgram.h"

#include "mgr/FsProgramSourceMgr.h"
#include "math/easing/FsLinearEase.h"

#include "mgr/FsTextureMgr.h"

#include "FsGlobal.h"
#include "FsClass.h"




#define FS_CHECK_STATE_VALID(st) \
	FS_TRACE_ERROR_ON(st<0 || st >=m_stateNu,"Invalid State")



NS_FS_BEGIN


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

	m_textureUrl="";
	m_texture=NULL;

	setTexture(NULL);
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

void StateButton::setColor(int st,const Color4f& value)
{
	FS_CHECK_STATE_VALID(st);
	m_states[st].m_color=value;

	markStateDirty();

}


Color4f StateButton::getColor(int st) const 
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_color;
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
void StateButton::setTextureUrl(const char* filename)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);
	setTexture(tex);
	if(tex==NULL)
	{
		m_textureUrl=filename;
	}
}

const char* StateButton::getTextureUrl()
{
	return m_textureUrl.c_str();
}


void StateButton::setTexture(Texture2D* tex)
{
	FS_SAFE_ASSIGN(m_texture,tex);
	if(m_texture)
	{
		if(m_size.x==0)
		{
			m_size.x=(float)m_texture->getWidth();
		}

		if(m_size.y==0)
		{
			m_size.y=(float)m_texture->getHeight();
		}

		m_textureUrl=m_texture->getResourceUrl();
	}

	if(m_texture)
	{
		static ProgramSource* S_programSourceTex=NULL;

		/* Change Shader To Color Mode */
		if(S_programSourceTex==NULL)
		{
			S_programSourceTex=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F);
		}
		setProgramSource(S_programSourceTex);

	}
	else 
	{
		static ProgramSource* S_programSourceColor=NULL;
		if(S_programSourceColor==NULL)
		{
			S_programSourceColor=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
		}

		setProgramSource(S_programSourceColor);
	}





}



Texture2D* StateButton::getTexture()const 
{
	return m_texture;
}



void StateButton::setTextureUrl(int st,const char* filename)
{
	FS_CHECK_STATE_VALID(st);
	Texture2D* tex=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(tex==NULL,"Can't Load Texture(%s) For StateButton",filename);

	setTexture(st,tex);
	
	if(tex==NULL)
	{
		FS_CHECK_STATE_VALID(st);
		m_states[st].m_textureUrl=filename;
	}

}

const char* StateButton::getTextureUrl(int st)
{
		FS_CHECK_STATE_VALID(st);
		return m_states[st].m_textureUrl.c_str();
}


void StateButton::setTexture(int st,Texture2D* tex)
{
	FS_CHECK_STATE_VALID(st);
	FS_SAFE_ASSIGN(m_states[st].m_texture,tex);

	if(m_states[st].m_texture)
	{
		m_states[st].m_size.set((float)tex->getWidth(),(float)tex->getHeight());
	}

	markStateDirty();
}


Texture2D* StateButton::getTexture(int st) const
{
	FS_CHECK_STATE_VALID(st);
	return m_states[st].m_texture;
}	


/* size */ 

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

void StateButton::setLinearTween(float time)
{
	setTweenInfo(-1,-1,LinearEase::create(),time);
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


void StateButton::setTweenColorEnabled(bool value)
{
	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::COLOR;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::COLOR;
	}

}

bool StateButton::getTweenColorEnabled()
{
	return m_tweenFlags&E_ButtonTweenFlag::COLOR ;
}



void StateButton::setTweenOpacityEnabled(bool value)
{
	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::OPACITY;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::OPACITY;
	}
}

bool StateButton::getTweenOpacityEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::OPACITY)!=0;
}


void StateButton::setTweenTextureEnabled(bool value)
{

	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::TEXTURE;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::TEXTURE;
	}
}




bool StateButton::getTweenTextureEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::TEXTURE)!=0;
}



void StateButton::setTweenSizeEnabled(bool value)
{

	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::SIZE;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::SIZE;
	}
}

bool StateButton::getTweenSizeEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::SIZE)!=0;
}


void StateButton::setTweenAnchorEnabled(bool value)
{
	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::ANCHOR;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::ANCHOR;
	}
}

bool StateButton::getTweenAnchorEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::ANCHOR)!=0;
}


void StateButton::setTweenRotateEnabled(bool value)
{

	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::ROTATE;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::ROTATE;
	}
}

bool StateButton::getTweenRotateEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::ROTATE)!=0;
}

void StateButton::setTweenScaleEnabled(bool value)
{
	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::SCALE;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::SCALE;
	}

}

bool StateButton::getTweenScaleEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::SCALE)!=0;
}

void StateButton::setTweenChildrenEnabled(bool value)
{

	if(value)
	{
		m_tweenFlags|=E_ButtonTweenFlag::CHILDREN;
	}
	else 
	{
		m_tweenFlags &=~E_ButtonTweenFlag::CHILDREN;
	}
}

bool StateButton::getTweenChildrenEnabled()
{
	return (m_tweenFlags&E_ButtonTweenFlag::CHILDREN)!=0;
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

		if(m_tweenFlags&E_ButtonTweenFlag::TEXTURE)
		{
			setTexture(m_tweenToState->m_texture);
			//FS_SAFE_ASSIGN(m_texture,m_tweenToState->m_texture);
		}

		if(m_tweenFlags&E_ButtonTweenFlag::CHILDREN)
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


void StateButton::stopTween()
{
	if(m_curTween)
	{
		m_curTween=NULL;
		m_tweenTime=0;
		setAttributeWithState(m_tweenToState);
		m_stateDirty=false;
	}
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
	if(m_tweenFlags&E_ButtonTweenFlag::COLOR)
	{
		m_material->setColor(st->m_color);
	}
	if(m_tweenFlags&E_ButtonTweenFlag::OPACITY)
	{
		m_material->setOpacity(st->m_opacity);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::SIZE)
	{
		m_size=st->m_size;
	}

	if(m_tweenFlags&E_ButtonTweenFlag::ANCHOR)
	{
		m_anchor=st->m_anchor;
	}

	if(m_tweenFlags&E_ButtonTweenFlag::ROTATE)
	{
		Entity::setRotate(st->m_rotate);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::SCALE)
	{
		Entity::setScale(st->m_scale);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::TEXTURE)
	{
		setTexture(st->m_texture);
		//FS_SAFE_ASSIGN(m_texture,st->m_texture);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::CHILDREN)
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

	if(m_tweenFlags&E_ButtonTweenFlag::COLOR)
	{
		m_material->setColor(from->m_color.lerp(to->m_color,r_p));
	}

	if(m_tweenFlags&E_ButtonTweenFlag::OPACITY)
	{
		m_material->setOpacity(from->m_opacity+(to->m_opacity-from->m_opacity)*r_p);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::SIZE)
	{
		m_size=from->m_size.lerp(to->m_size,r_p);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::ANCHOR)
	{
		m_anchor=from->m_anchor.lerp(to->m_anchor,r_p);
	}

	if(m_tweenFlags&E_ButtonTweenFlag::ROTATE)
	{
		Entity::setRotate(from->m_rotate.lerp(to->m_rotate,r_p));
	}

	if(m_tweenFlags&E_ButtonTweenFlag::SCALE)
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
	Entity2D::update(dt);
	updateTween(dt);
}


void StateButton::draw(RenderDevice* rd,bool update_matrix)
{
	Program* prog=getProgram(NULL);
	if(!prog)
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

	if(m_texture)
	{
		rd->bindTexture(m_texture,0);
	}


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


/***  Used For StateButton FsClass Attribute */

static void StateButton_setTweenFlag(StateButton* sb,FsArray* tweens)
{
	int tween_nu=tweens->size();
	uint32_t flags=0;

	for(int i=0;i<tween_nu;i++)
	{
		FsString* s_t=tweens->getString(i);
		if(s_t)
		{
			E_ButtonTweenFlag f=FsEnum_StrToButtonTweenFlag(s_t->cstr());
			flags|=f;
		}
		else 
		{
			FS_TRACE_WARN("Unkown Tween State");
		}
	}
	sb->setTweenFlags(flags);
}

void FsStateButton_SetState(StateButton* sb,int state,FsDict* dict)
{
	FsVariant color=FsVariant(dict->lookup("color")).getCast(E_FsType::FT_COLOR_4);
	if(color.isValid())
	{
		sb->setColor(state,*((Color4f*)color.getValue()));
	}

	FsString* tex_url=dict->lookupString("textureUrl");
	if(tex_url)
	{
		sb->setTextureUrl(state,tex_url->cstr());
	}


	FsString* opacity=dict->lookupString("opacity");
	if(opacity)
	{
		sb->setOpacity(state,opacity->toFloatValue());
	}

	FsDict* size=dict->lookupDict("size");
	if(size)
	{
		float x=0,y=0;
		if(size->lookupString("w"))
		{
			x=size->lookupString("w")->toFloatValue();
		}
		if(size->lookupString("h"))
		{
			y=size->lookupString("h")->toFloatValue();
		}

		sb->setSize(state,x,y);
	}

	FsDict* anchor=dict->lookupDict("anchor");
	if(anchor)
	{
		float x=0.5,y=0.5;
		if(anchor->lookupString("x"))
		{
			x=anchor->lookupString("x")->toFloatValue();
		}
		if(anchor->lookupString("y"))
		{
			y=anchor->lookupString("y")->toFloatValue();
		}
		sb->setAnchor(state,x,y);
	}

	FsDict* rotate=dict->lookupDict("rotate");
	if(rotate)
	{
		float x=0,y=0,z=0;
		if(rotate->lookupString("x"))
		{
			x=rotate->lookupString("x")->toFloatValue();
		}
		if(rotate->lookupString("y"))
		{
			y=rotate->lookupString("y")->toFloatValue();
		}
		if(rotate->lookupString("z"))
		{
			z=rotate->lookupString("z")->toFloatValue();
		}
		sb->setRotate(state,x,y,z);
	}

	FsDict* scale=dict->lookupDict("scale");
	if(scale)
	{
		float x=1,y=1,z=1;
		if(scale->lookupString("x"))
		{
			x=scale->lookupString("x")->toFloatValue();
		}
		if(scale->lookupString("y"))
		{
			y=scale->lookupString("y")->toFloatValue();
		}
		if(rotate->lookupString("z"))
		{
			z=scale->lookupString("z")->toFloatValue();
		}
		sb->setScale(state,x,y,z);
	}

	FsArray* child=dict->lookupArray("children");
	if(child)
	{
		FsArray* e2ds=FsArray::create();
		int child_nu=child->size();
		for(int i=0;i<child_nu;i++)
		{
			FsDict* ds=child->getDict(i);
			if(ds)
			{
				FsObject* ob=Global::classMgr()->newInstance(ds);
				if(ob)
				{
					Entity2D* e2d=dynamic_cast<Entity2D*>(ob);
					if(e2d)
					{
						e2ds->push(e2d);
					}
					else 
					{
						FS_TRACE_WARN("Not SubClass Of Entity,Ingore Item(%d)",i);
						ob->destroy();
					}
				}
			}
			else 
			{
				FS_TRACE_WARN("Not Dict,Ingore Item(%d)",i);
			}
		}
		sb->setChild(state,e2ds);
		e2ds->autoDestroy();
	}
}






FS_CLASS_ATTR_SET_FUNCTION(StateButton,setLinearTween,float);

FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenColorEnabled,getTweenColorEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenOpacityEnabled,getTweenOpacityEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenTextureEnabled,getTweenTextureEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenSizeEnabled,getTweenSizeEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenAnchorEnabled,getTweenAnchorEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenRotateEnabled,getTweenRotateEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenScaleEnabled,getTweenScaleEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(StateButton,setTweenChildrenEnabled,getTweenChildrenEnabled,bool);

FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(StateButton,setTextureUrl,getTextureUrl);




static FsClass::FsAttributeDeclare S_StateButton_Main_Attr[]={

	FS_CLASS_ATTR_DECLARE("linearTweenTime",E_FsType::FT_F_1,NULL,StateButton_setLinearTween,0),
	FS_CLASS_ATTR_DECLARE("tweenFlags",E_FsType::FT_ARRAY,NULL,StateButton_setTweenFlag,0),

	FS_CLASS_ATTR_DECLARE("tweenColorEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenColorEnabled,StateButton_getTweenColorEnabled),
	FS_CLASS_ATTR_DECLARE("tweenOpacityEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenOpacityEnabled,StateButton_getTweenOpacityEnabled),
	FS_CLASS_ATTR_DECLARE("tweenTextureEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenTextureEnabled,StateButton_getTweenTextureEnabled),
	FS_CLASS_ATTR_DECLARE("tweenSizeEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenSizeEnabled,StateButton_getTweenSizeEnabled),
	FS_CLASS_ATTR_DECLARE("tweenAnchorEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenAnchorEnabled,StateButton_getTweenAnchorEnabled),
	FS_CLASS_ATTR_DECLARE("tweenRotateEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenRotateEnabled,StateButton_getTweenRotateEnabled),
	FS_CLASS_ATTR_DECLARE("tweenScaleEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenScaleEnabled,StateButton_getTweenScaleEnabled),
	FS_CLASS_ATTR_DECLARE("tweenChildrenEnabled",E_FsType::FT_B_1,NULL,StateButton_setTweenChildrenEnabled,StateButton_getTweenChildrenEnabled),
	FS_CLASS_ATTR_DECLARE("textureUrl",E_FsType::FT_CHARS,NULL,StateButton_setTextureUrl,StateButton_getTextureUrl),

	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};


FS_CLASS_IMPLEMENT_WITH_BASE(StateButton,Entity2D,0,S_StateButton_Main_Attr);


NS_FS_END 

