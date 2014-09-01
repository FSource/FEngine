#include "UiWidget.h"

NS_FS_BEGIN
const char* UiWidget::className()
{
	return FS_UI_WIDGET_CLASS_NAME;
}


UiWidget* UiWidget::create(float width,float height)
{
	return new UiWidget;
}



UiWidget::UiWidget()
{
	setTouchEnabled(true);
	setDispatchTouchEnabled(true);

	m_scissor=false;
	m_size.set(0.0f,0.0f);
	m_anchor.set(0.5f,0.5f);
	m_parentWidget=NULL;
}

UiWidget::~UiWidget()
{
	assert(m_parentWidget==NULL);
}

bool UiWidget::hit2D(float x,float y)
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

void UiWidget::setSize(float width,float height)
{
	m_size.x=width;
	m_size.y=height;

	if(m_parentWidget)
	{
		m_parentWidget->childSizeChanged(width,height);
	}
}

Vector2 UiWidget::getSize()
{
	return m_size;
}

float UiWidget::getWidth()
{
	return m_size.x;
}

float UiWidget::getHeight()
{
	return m_size.y;
}


void UiWidget::setScissor(bool enabled)
{
	m_scissor=enabled;
}

bool UiWidget::getScissor()
{
	return m_scissor;
}

void UiWidget::setAnchor(float x,float y)
{
	m_anchor.x=x;
	m_anchor.y=y;
	if(m_parentWidget)
	{
		m_parentWidget->childAnchorChanged(x,y);
	}
}

Vector2 UiWidget::getAnchor()
{
	return m_anchor;
}


float UiWidget::getAnchorX()
{
	return m_anchor.x;
}

float UiWidget::getAnchorY()
{
	return m_anchor.y;
}



void UiWidget::childSizeChanged(float w,float h)
{

}

void UiWidget::childAnchorChanged(float x,float y)
{

}

void UiWidget::setParentWidget(UiWidget* widget)
{
	m_parentWidget=widget;
}


UiWidget* UiWidget::getParentWidget()
{
	return m_parentWidget;
}

NS_FS_END


