#include "FsScrollWidget.h"


NS_FS_BEGIN

const char* ScrollWidget::className()
{
	return FS_SCROLL_WIDGET_CLASS_NAME;
}


void ScrollWidget::setMargin(float l,float r,float t,float b)
{
	m_marginLeft=l;
	m_marginRight=r;
	m_marginTop=t;
	m_marginBottom=b;

	adjustScrollArea();
}

void ScrollWidget::setMarginLeft(float v)
{
	m_marginLeft=v;
	adjustScrollArea();
}

void ScrollWidget::setMarginRight(float v)
{
	m_marginRight=v;
	adjustScrollArea();
}

void ScrollWidget:;setMarginTop(float v)
{
	m_marginTop=v;
}

void ScrollWidget::setMarginBottom(float v)
{
	m_marginBottom=v;
}

float ScrollWidget::getMarginLeft()const 
{
	return m_marginLeft;
}

float ScrollWidget::getMarginRight()const 
{
	return m_marginRight;
}

float ScrollWidget::getMarginTop()const 
{
	return m_marginTop;
}

float ScrollWidget::getMarginBottom()
{
	return m_marginBottom;
}

void ScrollWidget::setContentSize(float width,float height)
{
	m_contentWidth=width;
	m_contentHeight=height;
	adjustScrollArea();
}

void ScrollWidget::setContentAlign(int v,int h)
{
	m_contentVAlign=v;
	m_contentHAlign=h;
	adjustScrollArea();
}

void ScrollWidget::touchBegin(float x,float y)
{
	m_cancelDrag=false;

	m_isDraged=!m_scroller->isFinished();

	if(!m_scroller->isFinished())
	{
		m_scroller.abortAnimation();
	}

	m_lastMotionPosX=x;
	m_lastMotionPosY=y;

}


void ScrollWidget::touchMove(float x,float y)
{
	float detal_x=x-m_lastMotionPosX;
	float detal_y=y-m_lastMotionPosY;

	if(!m_isDraged)
	{
		if(m_scrollMode==SCROLL_HORIZONTAL)
		{

		}
		else (m_scrollMode==SCROLL_VERTICAL)
		{

		}
		else 
		{

		}
	}



}



void ScrollWidget::touchMoveX(float x)
{
	float detal_x=x-m_lastMotionPosX;



}



void ScrollWidget::touchEnd(float x,float y)
{

}































NS_FS_END 




