/*************************************************************************/
/*  FsToggleButton.cc                                                    */
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


#include "FsClass.h"
#include "FsToggleButton.h"

#include "math/easing/FsLinearEase.h"

NS_FS_BEGIN



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

	setTweenFlags(E_ButtonTweenFlag::COLOR);
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
	setTweenFlags(E_ButtonTweenFlag::TEXTURE|E_ButtonTweenFlag::COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setTexture(STATE_ON,on);
	setTexture(STATE_OFF,off);
	setTexture(STATE_DISABLE,on);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
}


void ToggleButton::toggleChanged(bool value)
{
}


/*** Used For ToggleButton FsClass Attribute */

static ToggleButton* ToggleButton_NewInstance(FsDict* attr)
{
	ToggleButton* ret=ToggleButton::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}


static void ToggleButton_setOnAttribute(ToggleButton* pb,FsDict* attr)
{
	FsStateButton_SetState(pb,ToggleButton::STATE_ON,attr);
}

static void ToggleButton_setOffAttribute(ToggleButton* pb,FsDict* attr)
{
	FsStateButton_SetState(pb,ToggleButton::STATE_OFF,attr);
}

static void ToggleButton_setDisableAttribute(ToggleButton* pb,FsDict* attr)
{
	FsStateButton_SetState(pb,ToggleButton::STATE_DISABLE,attr);
}


static FsClass::FsAttributeDeclare S_ToggleButton_Main_Attr[]={

	FS_CLASS_ATTR_DECLARE("onState",E_FsType::FT_DICT,NULL,ToggleButton_setOnAttribute,0),
	FS_CLASS_ATTR_DECLARE("offState",E_FsType::FT_DICT,NULL,ToggleButton_setOffAttribute,0),
	FS_CLASS_ATTR_DECLARE("disableState",E_FsType::FT_DICT,NULL,ToggleButton_setDisableAttribute,0),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0),
};

FS_CLASS_IMPLEMENT_WITH_BASE(ToggleButton,StateButton,ToggleButton_NewInstance,S_ToggleButton_Main_Attr);

NS_FS_END 


