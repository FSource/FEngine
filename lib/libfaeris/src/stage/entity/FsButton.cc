#include "stage/entity/FsButton.h"

NS_FS_BEGIN

const char* Button::className()
{
	return FS_BUTTON_CLASS_NAME;
}

Button::Button()
{
	m_normalState=new ButtonState;
	m_pressState=new ButtonState;
	m_moveIn=false;
}

Button::~Button()
{
	delete m_normalState;
	delete m_pressState;
}

Button* Button::create()
{
	Button* ret=new Button();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}
Button* Button::create(const char* filename)
{
	Button* ret=new Button();
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Button* Button::create(const char* filename,float width,float height)
{
	Button* ret=new Button();
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}

	ret->setSize(width,height);
	return ret;
}

ButtonState* Button::getNormalState()
{
	return m_normalState;
}

ButtonState* Button::getPressState()
{
	return m_pressState;
}

bool Button::touchBegin(float x,float y)
{
	m_moveIn=true;
	this->pressDown(x,y);
	Quad2D::touchBegin(x,y);
	return true;
}
bool Button::touchMove(float x,float y)
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

	return Quad2D::touchMove(x,y);
}

bool Button::touchEnd(float x,float y)
{

	bool hit=hit2D(x,y);
	if(hit)
	{
		pressUp(x,y);
		this->click();

	}
	else 
	{
		pressCancel(x,y);
	}

	return Quad2D::touchEnd(x,y);
}

void Button::pressDown(float x,float y)
{
	setStatePress();
}

void Button::pressMoveIn(float x,float y)
{
	setStatePress();
}

void Button::pressMoveOut(float x,float y)
{
	setStateNormal();
}

void Button::pressUp(float x,float y)
{
	setStateNormal();
}

void Button::pressCancel(float x,float y)
{
}


void Button::click()
{
}


void Button::setStateNormal()
{
	setState(m_normalState);
}

void Button::setStatePress()
{
	setState(m_pressState);
}


void Button::setState(ButtonState* state)
{
	if(state->m_flags&FLAG_COLOR){setColor(state->m_color);}
	if(state->m_flags&FLAG_OPACITY){setOpacity(state->m_opacity);}
	if(state->m_flags&FLAG_TEXTURE){setTexture(state->m_texture);}
	if(state->m_flags&FLAG_SIZE){setSize(state->m_width,state->m_height);}
	if(state->m_flags&FLAG_ANCHOR){setAnchor(state->m_anchorX,state->m_anchorY);}
	if(state->m_flags&FLAG_TRANSLATE){setPosition(state->m_translate);}
	if(state->m_flags&FLAG_ROTATE){setRotate(state->m_rotate);}
	if(state->m_flags&FLAG_SCALE){setScale(state->m_scale);}
	if(state->m_flags&FLAG_ZORDER){setZorder(state->m_zorder);}
	if(state->m_flags&FLAG_CHILDREN)
	{
		clearChild();
		if(state->m_children)
		{
			int child_nu=state->m_children->size();
			for(int i=0;i<child_nu;i++)
			{
				Entity* e=(Entity*)state->m_children->get(i);
				addChild(e);
			}
		}
	}
}

NS_FS_END




