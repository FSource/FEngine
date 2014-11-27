#include "FsToggleButton.h"

#include "math/easing/FsLinearEase.h"

NS_FS_BEGIN

const char* ToggleButton::className()
{
	return FS_TOGGLE_BUTTON_CLASS_NAME;
}


ToggleButton* ToggleButton::create()
{
	ToggleButton* ret=new ToggleButton();
	return ret;
}

ToggleButton* ToggleButton::createWithColorStyle(const char* filename,
												const Color4f& on,
												const Color4f& off)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithColorStyle(filename,on,off);
	return ret;
}

ToggleButton* ToggleButton::createWithColorStyle(Texture2D* tex,
												const Color4f& on,
												const Color4f& off)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithColorStyle(tex,on,off);
	return ret;
}

ToggleButton* ToggleButton::createWithTextureStyle(const char* fileon,const char* fileoff)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithTextureStyle(fileon,fileoff);
	return ret;
}

ToggleButton* ToggleButton::createWithTextureStyle(Texture2D* on,Texture2D* off)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithTextureStyle(on,off);
	return ret;
}

ToggleButton::ToggleButton()
	:StateButton(STATE_NU)
{

	m_toggleState=true;
	m_disabled=false;
	onToggleChanged=nullptr;
}

ToggleButton::~ToggleButton()
{

}

void ToggleButton::setDisabled(bool value)
{
	if(value)
	{
		setState(STATE_DISABLE);
	}
	else 
	{
		if(m_toggleState)
		{
			setState(STATE_ON);
		}
		else 
		{
			setState(STATE_OFF);
		}

	}
	m_disabled=value;
}

bool ToggleButton::getDisabled()const 
{
	return m_disabled;
}

void ToggleButton::setToggle(bool value,bool callback)
{
	if(m_disabled)
	{
		m_toggleState=value;
		return;
	}
	else 
	{
		m_toggleState=value;
		if(m_toggleState)
		{
			setState(STATE_ON);
		}
		else 
		{
			setState(STATE_OFF);
		}
		if (callback)
		{
			FS_OBJECT_LAMBDA_CALL(this,onToggleChanged,toggleChanged,m_toggleState);
		}
	}
}

bool ToggleButton::getToggle() const
{
	return m_disabled;
}


bool ToggleButton::touchBegin(float x,float y)
{
	m_toggleState=!m_toggleState;
	if(m_toggleState)
	{
		setState(STATE_ON);
	}
	else 
	{
		setState(STATE_OFF);
	}

	FS_OBJECT_LAMBDA_CALL(this,onToggleChanged,toggleChanged,m_toggleState);
	return true;
}


bool ToggleButton::touchMove(float x,float y)
{
	return true;
}

bool ToggleButton::touchEnd(float x,float y)
{
	return true;
}

bool ToggleButton::hit2D(float x,float y)
{
	if(m_disabled)
	{
		return false;
	}
	return StateButton::hit2D(x,y);
}

void ToggleButton::initWithColorStyle(const char* filename,const Color4f& on,const Color4f& off)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't loadTexture(%s) For ToggleButton",filename);
	initWithColorStyle(texture,on,off);
}

void ToggleButton::initWithDarkStyle(const char* filename,const Color4f& dark)
{
	initWithColorStyle(filename,Color4f::WHITE,dark);
}


void ToggleButton::initWithColorStyle(Texture2D* tex,const Color4f& on,const Color4f& off)
{
	setTexture(tex);

	setTweenFlags(FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setColor(STATE_ON,on);
	setColor(STATE_OFF,off);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.3f));
}

void ToggleButton::initWithDarkStyle(Texture2D* tex,const Color4f& dark)
{
	initWithColorStyle(tex,Color4f::WHITE,dark);
}


void ToggleButton::initWithTextureStyle(const char* fileon,const char* fileoff)
{
	Texture2D* tex_on=Global::textureMgr()->loadTexture(fileon);
	FS_TRACE_WARN_ON(tex_on==NULL,"Can't loadTexture(%s) For ToggleButton",fileon);

	Texture2D* tex_off=Global::textureMgr()->loadTexture(fileoff);
	FS_TRACE_WARN_ON(tex_off==NULL,"Can't loadTexture(%s) For ToggleButton",fileoff);

	initWithTextureStyle(tex_on,tex_off);

}

void ToggleButton::initWithTextureStyle(Texture2D* on,Texture2D* off)
{
	setTexture(on);
	setTweenFlags(FLAG_TEXTURE|FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setTexture(STATE_ON,on);
	setTexture(STATE_OFF,off);
	setTexture(STATE_DISABLE,on);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));

}


void ToggleButton::toggleChanged(bool value)
{
}






NS_FS_END 







