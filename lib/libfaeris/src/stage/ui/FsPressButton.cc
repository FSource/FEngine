/*************************************************************************/
/*  FsPressButton.cc                                                     */
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


#include "stage/ui/FsPressButton.h"

#include "math/easing/FsLinearEase.h"
#include "FsClass.h"


NS_FS_BEGIN


PressButton* PressButton::create()
{
	PressButton* ret=new PressButton();
	return ret;
}


PressButton* PressButton::createWithColorStyle(const char* filename,const Color4f& normal,const Color4f& press)
{
	PressButton* ret=new PressButton();
	ret->initWithColorStyle(filename,normal,press);
	return ret;
}

PressButton* PressButton::createWithColorStyle(Texture2D* tex,const Color4f& normal,const Color4f& press)
{
	PressButton* ret=new PressButton();
	ret->initWithColorStyle(tex,normal,press);
	return ret;

}




PressButton* PressButton::createWithDarkStyle(const char* filename,const Color4f& dark)
{
	PressButton* ret=new PressButton();
	ret->initWithDarkStyle(filename,dark);
	return ret;
}

PressButton* PressButton::createWithDarkStyle(Texture2D* tex,const Color4f& dark)
{
	PressButton* ret=new PressButton();
	ret->initWithDarkStyle(tex,dark);
	return ret;
}




PressButton* PressButton::createWithScaleStyle(const char*  filename,const Vector3& scale)
{
	PressButton* ret=new PressButton();
	ret->initWithScaleStyle(filename,scale);
	return ret;
}


PressButton* PressButton::createWithScaleStyle(Texture2D* tex,const Vector3& scale)
{
	PressButton* ret=new PressButton();
	ret->initWithScaleStyle(tex,scale);
	return ret;
}



PressButton::PressButton()
	:StateButton(STATE_NU)
{
	m_moveIn=false;
	m_disabled=false;

	onPressDown=nullptr;
	onPressMoveIn=nullptr;
	onPressMoveOut=nullptr;
	onPressUp=nullptr;
	onCancel=nullptr;
	onClick=nullptr;

}


PressButton::~PressButton()
{
}


void PressButton::initWithDarkStyle(const char* filename,const Color4f& dark)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't Load Texture(%s) For PressButton",filename);
	initWithDarkStyle(texture,dark);
}


void PressButton::initWithDarkStyle(Texture2D* texture,const Color4f& dark)
{

	setTexture(texture);

	setTweenFlags(E_ButtonTweenFlag::COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setColor(STATE_PRESS,dark);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
}


void PressButton::initWithScaleStyle(const char* filename,const Vector3& scale)
{

	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't loadTexture(%s) For PressButton",filename);
	initWithScaleStyle(texture,scale);

}


void PressButton::initWithScaleStyle(Texture2D* texture,const Vector3& scale)
{
	setTexture(texture);

	setTweenFlags(E_ButtonTweenFlag::SCALE|E_ButtonTweenFlag::COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setScale(STATE_PRESS,scale);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
}

void PressButton::initWithColorStyle(const char* filename,const Color4f&  normal,const Color4f& press)
{
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	FS_TRACE_WARN_ON(texture==NULL,"Can't Load Texture(%s) For PressButton",filename);
	initWithColorStyle(texture,normal,press);
}

void PressButton::initWithColorStyle(Texture2D* tex,const Color4f& normal,const Color4f& press)
{
	setTexture(tex);

	setTweenFlags(E_ButtonTweenFlag::COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setColor(STATE_NORMAL,normal);
	setColor(STATE_PRESS,press);
	setColor(STATE_DISABLE,Color4f(0.2f,0.2f,0.2f));
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



/* touch handle */
bool PressButton::touchBegin(float x,float y)
{
	if(m_disabled)
	{
		return false;
	}


	m_moveIn=true;
	FS_OBJECT_LAMBDA_CALL(this,onPressDown,pressDown,x,y);
	return  true;
}


bool PressButton::touchMove(float x,float y)
{
	bool hit=FS_OBJECT_LAMBDA_CALL(this,onHit2D,hit2D,x,y);
	if(hit)
	{
		if(!m_moveIn)
		{
			m_moveIn=true;
			FS_OBJECT_LAMBDA_CALL(this,onPressMoveIn,pressMoveIn,x,y);
		}
	}
	else 
	{
		if(m_moveIn)
		{
			m_moveIn=false;
			FS_OBJECT_LAMBDA_CALL(this,onPressMoveOut,pressMoveOut,x,y);
		}
	}
	return true;
}

bool PressButton::touchEnd(float x,float y)
{
	bool hit=FS_OBJECT_LAMBDA_CALL(this,onHit2D,hit2D,x,y);
	if(hit)
	{
		FS_OBJECT_LAMBDA_CALL(this,onPressUp,pressUp,x,y);
		FS_OBJECT_LAMBDA_CALL(this,onClick,click);
	}
	else 
	{
		FS_OBJECT_LAMBDA_CALL(this,onPressUp,pressUp,x,y);
		FS_OBJECT_LAMBDA_CALL(this,onCancel,cancel);
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





bool PressButton::hit2D(float x,float y)
{
	if(m_disabled) 
	{
		return false;
	}
	return StateButton::hit2D(x,y);
}



/*** Used For PressButton FsClass Attribute */

static PressButton* PressButton_NewInstance(FsDict* attr)
{
	PressButton* ret=PressButton::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}

	return ret;
}


static void PressButton_setNormalAttribute(PressButton* pb,FsDict* attr)
{

	FsStateButton_SetState(pb,PressButton::STATE_NORMAL,attr);
}

static FsDict* PressButton_getNormalAttribute(PressButton* pb)
{

	return FsStateButton_getState(pb,PressButton::STATE_NORMAL);
}

static void PressButton_setPressAttribute(PressButton* pb,FsDict* attr)
{
	FsStateButton_SetState(pb,PressButton::STATE_PRESS,attr);
}

static FsDict* PressButton_getPressAttribute(PressButton* pb)
{

	return FsStateButton_getState(pb,PressButton::STATE_PRESS);
}


static void PressButton_setDisableAttribute(PressButton* pb,FsDict* attr)
{
	FsStateButton_SetState(pb,PressButton::STATE_DISABLE,attr);
}

static FsDict* PressButton_getDisableAttribute(PressButton* pb)
{

	return FsStateButton_getState(pb,PressButton::STATE_DISABLE);
}





/* normal state */
static void PressButton_setNormalAttributeTextureUrl(PressButton* pb,const char* url)
{
	pb->setTextureUrl(PressButton::STATE_NORMAL,url);
}

static const char* PressButton_getNormalAttributeTextureUrl(PressButton* pb)
{
	return pb->getTextureUrl(PressButton::STATE_NORMAL);
}

static void PressButton_setNormalAttributeColor(PressButton* pb,const Color4f& value)
{
	pb->setColor(PressButton::STATE_NORMAL,value);
}

static Color4f* PressButton_getNormalAttributeColor(PressButton* pb)
{
	static Color4f ret;
	ret= pb->getColor(PressButton::STATE_NORMAL);
	return &ret;
}

static void PressButton_setNormalAttributeScale(PressButton* pb,const Vector3& value)
{
	pb->setScale(PressButton::STATE_NORMAL,value);
}

static Vector3f* PressButton_getNormalAttributeScale(PressButton* pb)
{
	static Vector3f ret;
	ret=pb->getScale(PressButton::STATE_NORMAL);
	return &ret;
}



/* normal state */
static void PressButton_setPressAttributeTextureUrl(PressButton* pb,const char* url)
{
	pb->setTextureUrl(PressButton::STATE_PRESS,url);
}

static const char* PressButton_getPressAttributeTextureUrl(PressButton* pb)
{
	return pb->getTextureUrl(PressButton::STATE_PRESS);
}

static void PressButton_setPressAttributeColor(PressButton* pb,const Color4f& value)
{
	pb->setColor(PressButton::STATE_PRESS,value);
}

static Color4f* PressButton_getPressAttributeColor(PressButton* pb)
{
	static Color4f ret;
	ret= pb->getColor(PressButton::STATE_PRESS);
	return &ret;
}

static void PressButton_setPressAttributeScale(PressButton* pb,const Vector3& value)
{
	pb->setScale(PressButton::STATE_PRESS,value);
}

static Vector3f* PressButton_getPressAttributeScale(PressButton* pb)
{
	static Vector3f ret;
	ret= pb->getScale(PressButton::STATE_PRESS);
	return &ret;
}


/* normal state */
static void PressButton_setDisableAttributeTextureUrl(PressButton* pb,const char* url)
{
	pb->setTextureUrl(PressButton::STATE_DISABLE,url);
}

static const char*  PressButton_getDisableAttributeTextureUrl(PressButton* pb)
{
	return pb->getTextureUrl(PressButton::STATE_DISABLE);
}

static void PressButton_setDisableAttributeColor(PressButton* pb,const Color4f& value)
{
	pb->setColor(PressButton::STATE_DISABLE,value);
}
  
static Color4f* PressButton_getDisableAttributeColor(PressButton* pb)
{
	static Color4f ret;
	ret= pb->getColor(PressButton::STATE_DISABLE);
	return &ret;
}

static void PressButton_setDisableAttributeScale(PressButton* pb,const Vector3& value)
{
	pb->setScale(PressButton::STATE_DISABLE,value);
}

static Vector3f* PressButton_getDisableAttributeScale(PressButton* pb)
{
	static Vector3f ret;
	ret= pb->getScale(PressButton::STATE_DISABLE);
	return &ret;
}


static FsClass::FsAttributeDeclare S_PressButton_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("normalState",E_FsType::FT_DICT,NULL,PressButton_setNormalAttribute,PressButton_getNormalAttribute),
	FS_CLASS_ATTR_DECLARE("pressState",E_FsType::FT_DICT,NULL,PressButton_setPressAttribute,PressButton_getPressAttribute),
	FS_CLASS_ATTR_DECLARE("disableState",E_FsType::FT_DICT,NULL,PressButton_setDisableAttribute,PressButton_getDisableAttribute),

	FS_CLASS_ATTR_DECLARE("normalState.textureUrl",E_FsType::FT_CHARS,NULL,PressButton_setNormalAttributeTextureUrl,PressButton_getNormalAttributeTextureUrl),
	FS_CLASS_ATTR_DECLARE("normalState.color",E_FsType::FT_COLOR_4,NULL,PressButton_setNormalAttributeColor,PressButton_getNormalAttributeColor),
	FS_CLASS_ATTR_DECLARE("normalState.scale",E_FsType::FT_F_3,NULL,PressButton_setNormalAttributeScale,PressButton_getNormalAttributeScale),

	FS_CLASS_ATTR_DECLARE("pressState.textureUrl",E_FsType::FT_CHARS,NULL,PressButton_setPressAttributeTextureUrl,PressButton_getPressAttributeTextureUrl),
	FS_CLASS_ATTR_DECLARE("pressState.color",E_FsType::FT_COLOR_4,NULL,PressButton_setPressAttributeColor,PressButton_getPressAttributeColor),
	FS_CLASS_ATTR_DECLARE("pressState.scale",E_FsType::FT_F_3,NULL,PressButton_setPressAttributeScale,PressButton_getPressAttributeScale),

	FS_CLASS_ATTR_DECLARE("disableState.textureUrl",E_FsType::FT_CHARS,NULL,PressButton_setDisableAttributeTextureUrl,PressButton_getDisableAttributeTextureUrl),
	FS_CLASS_ATTR_DECLARE("disableState.color",E_FsType::FT_COLOR_4,NULL,PressButton_setDisableAttributeColor,PressButton_getDisableAttributeColor),
	FS_CLASS_ATTR_DECLARE("disableState.scale",E_FsType::FT_F_3,NULL,PressButton_setDisableAttributeScale,PressButton_getDisableAttributeScale),
	

	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(PressButton,StateButton,PressButton_NewInstance,S_PressButton_Main_Attr);



NS_FS_END





