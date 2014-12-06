#include "stage/ui/FsPressButton.h"

#include "math/easing/FsLinearEase.h"


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

	setTweenFlags(FLAG_COLOR);
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

	setTweenFlags(FLAG_SCALE|FLAG_COLOR);
	setTweenInfo(STATE_ALL,STATE_ALL,LinearEase::create(),0.1f);

	setScale(STATE_PRESS,scale);
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
	bool hit=hit2D(x,y);
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
	bool hit=hit2D(x,y);
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

















NS_FS_END












