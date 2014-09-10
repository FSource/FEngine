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

ToggleButton* ToggleButton::createWithDarkStyle(const char* filename,const Color4f& dark)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithDarkStyle(filename,dark);
	return ret;
}

ToggleButton* ToggleButton::createWithDarkStyle(Texture2D* tex,const Color4f& dark)
{
	ToggleButton* ret=new ToggleButton();
	ret->initWithDarkStyle(tex,dark);
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

	m_toggleState=STATE_ON;
	m_disabled=false;

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
		toggleChanged(m_toggleState);
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

	toggleChanged(m_toggleState);
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

void ToggleButton::initWithDarkStyle(const char* filename,const Color4f& dark)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't loadTexture(%s) For ToggleButton",filename);
	initWithDarkStyle(texture,dark);
}

void ToggleButton::initWithDarkStyle(Texture2D* tex,const Color4f& dark)
{
	setTexture(tex);

	setTweenFlags(FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setColor(STATE_OFF,dark);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.3f));

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
	setTexture(STATE_ON,off);
	setTexture(STATE_DISABLE,on);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));

}


void ToggleButton::toggleChanged(bool value)
{
}






NS_FS_END 







