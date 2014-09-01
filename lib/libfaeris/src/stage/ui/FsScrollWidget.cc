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

void ScrollWidget::setMarginTop(float v)
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

/*
void ScrollWidget::setContentWidget(UiWidget* widget)
{
	if(m_contentWidget)
	{
		m_contentWidget->setParent(NULL);
		remove(widget);
		m_contentWidget=NULL;
		m_contentHeight=0;
		m_contentWidth=0;
	}
	if(widget)
	{
		FS_SAFE_ADD_REF(widget);
		m_contentWidget=widget;
		addChild(widget);
		m_contentWidget->setParent(this);

		m_contentWidth=widget->getWidth();
		m_contentHeight=widget->getHeight();

	}
	adjustScrollArea();
}
*/


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


void ScrollWidget::scrollBy(float x,float y)
{
	scrollTo(m_scrollX+x,m_scrollerY+y);
	scrollChange(m_scrollerX,m_scrollY);
}

void ScrollWidget::scrollTo(float x,float y)
{
	m_scrollerX->abortAnimation();
	m_scrollerY->abortAnimation();

	m_scrollX=x;
	m_scrollY=y;

	scrollChange(m_scrollX,m_scrollY);
}

void ScrollWidget::setScrollPercent(float x,float y)
{

	float sx= m_scrollMinX+(m_scrollMaxX-m_scrollMinX)*x;
	float sy= m_scrollMinY+(m_scrollMaxY-m_scrollMinY)*y;

	scrollTo(sx,sy);
}

void ScrollWidget::setScrollPercentX(float x)
{
	float sx= m_scrollMinX+(m_scrollMaxX-m_scrollMinX)*x;
	scrollTo(sx,m_scrollY);
}

void ScrollWidget::setScrollPercentY(float  y)
{
	float sy= m_scrollMinY+(m_scrollMaxY-m_scrollMinY)*y;
	scrollTo(m_scrollX,sy);
}

void ScrollWidget::getScrollPercent(float* x,float* y)
{
	*x=m_scrollX;
	*y=m_scrollY;
}


float ScrollWidget::getScrollPercentX()
{
	return (m_scrollX-m_scrollMinX)/(m_scrollMaxX-m_scrollMinX)
}


float ScrollWidget::getScrollPercentY()
{
	return (m_scrollY-m_scrollMinY)/(m_scrollMaxY-m_scrollMinY);

}


void ScrollWidget::update(float dt)
{
	UiWidget::update(dt);
	updateScroll();
}




void ScrollWidget::touchBegin(float x,float y)
{
	m_cancelDrag=false;
	m_isDraged=!m_scroller->isFinished();

	if(m_isDraged)
	{
		beginDrag();
	}

	if(!m_scroller->isFinished())
	{
		m_scroller->abortAnimation();
	}

	m_lastMotionPosX=x;
	m_lastMotionPosY=y;

	m_velocityTracker->beginTrack(x,y);

}


void ScrollWidget::touchMove(float x,float y)
{
	float detal_x=x-m_lastMotionPosX;
	float detal_y=y-m_lastMotionPosY;

	if(!m_isDraged)
	{
		if(m_scrollMode==SCROLL_HORIZONTAL)
		{
			if(Math::abs(detal_x) > m_touchTap)
			{
				m_isDraged=true;
				if(detal_x>0)
				{
					detal_x=detal_x-m_touchTap;
				}
				else 
				{
					detal_x=detal_x+m_touchTap;
				}
			}
		}
		else (m_scrollMode==SCROLL_VERTICAL)
		{
			if(Math::abs(detal_y) > m_touchTap)
			{
				m_isDraged=true;
			}
		}
		else 
		{
			if(Math::sqrt(detal_x*detal_x+detal_y*detal_y)> m_touchTap)
			{
				m_isDraged=true;
				if(detal_y>0)
				{
					detal_y=detal_y-m_touchTap;
				}
				else 
				{
					detal_y=detal_y+m_touchTap;
				}

				if(detal_x>0)
				{
					detal_x=detal_x-m_touchTap;
				}
				else 
				{
					detal_x=detal_x+m_touchTap;
				}
			}
		}
	}

	if(m_isDraged)
	{
		if(m_scrollMode==SCROLL_HORIZONTAL||m_scrollMode==SCROLL_ALL)
		{
			startScrollX(m_scrollX,m_scrollMinX,m_scrollMaxX,detal_x);
		}

		if(m_scrollMode==SCROLL_VERTICAL || m_scrollMode=SCROLL_ALL)
		{
			startScrollY(m_scrollY,m_scrollMinY,m_scrollMaxY,detal_y);
		}

		m_lastMotionPosX=x;
		m_lastMotionPosY=y;
	}

	m_velocityTracker->addTrack(x,y);
}


void ScrollWidget::touchEnd(float x,float y)
{
	m_isDraged=false;
	m_velocityTracker->endTrack(x,y);
}


void ScrollWidget::startScrollX(float cur,float min,float max,float detal)
{
	if(cur<min&&detal<0)
	{
		float percent=(min-cur)/getWidth();
		if(percent>1)
		{
			percent=1;
		
		}
		detal=detal*(1-percent);
	}

	if(cur>max&&detal>0)
	{
		float percent=(cur-max)/getWidth();
		if(percent>1)
		{
			percent=1;
		}
		detal=detal*(1-percent);
	}

	m_scrollerX->startScroll(cur,min,max,detal);
}

void ScrollWidget::startScrollY(float cur,float min,float max,float detal)
{
	if(cur<min&&detal<0)
	{
		float percent=(min-cur)/getHeight();
		if(percent>1)
		{
			percent=1;
		
		}
		detal=detal*(1-percent);
	}

	if(cur>max&&detal>0)
	{
		float percent=(cur-max)/getHeight();
		if(percent>1)
		{
			percent=1;
		}
		detal=detal*(1-percent);
	}

	m_scrollerY->startScroll(cur,min,max,detal);
}



void ScrollWidget::updateScroll(float dt)
{
	edgeCheckHandle();

	bool need_readjust=false;
	if(m_mode==SCROLL_HORIZONTAL||m_mode==SCROLL_ALL)
	{
		if(!m_scrollerX->update(dt))
		{
			need_readjust=true;
		}
		m_scrollX=m_scrollerX->getCurPos();
	}


	if(m_mode==SCROLL_VERTICAL || m_mode == SCROLL_ALL)
	{

		if( !m_scrollerY->update(dt))
		{
			need_readjust=true;
		}
		m_scrollY=m_scrollerY->getCurPos();

	}

	if(need_readjust)
	{
		scrollChange(m_scrollX,m_scrollerY);
	}
}

void ScrollWidget::adjustScrollArea()
{

	m_edgeLeft=-m_anchor.x*m_size.x;
	m_edgeRight=(1-m_anchor.x)*m_size.x;

	m_edgeTop=-m_anchor.y*m_size.y;
	m_edgeBottom=(1-m_anchor.y)*m_size.y;



	m_edgeBLeft=el+m_marginLeft;
	m_edgeBRight=er-m_marginRight;

	m_edgeBTop=rt-m_marginTop;
	m_edgeBBottom=rb+m_marginBottom;

	if(m_edgeBRight<m_edgeBLeft)
	{
		float t=(m_edgeBLeft+m_edgeRight)/2;
		m_edgeBLeft=t;
		m_edgeBRight=t;
	}

	if(m_edgeBTop<m_edgeBBottom)
	{
		float t=(m_edgeBTop+m_edgeBBottom)/2;
		m_edgeBTop=t;
		m_edgeBBottom=t;
	}


	if(m_alignh==ALIGN_LEFT)
	{
		m_scrollMaxX=m_edgeBLeft;
		m_scrollMinX=m_edgeBRight-m_contentWidth;

		if(m_scrollMinX>m_scrollMaxX)
		{
			m_scrollMinX=m_scrollMaxX;
		}
	}

	if(m_alignh==ALIGN_CENTER)
	{
		float middle=(m_edgeBLeft+m_edgeBRight)/2;
		float diff=m_contentWidth/2-(m_edgeBRight-m_edgeBLeft)/2;
		if(diff<0)
		{
			diff=0;
		}

		m_scrollMinX=middle-diff;
		m_scrollMaxX=middle+diff;
	}


	if(m_alignh==ALIGN_RIGHT)
	{
		m_scrollMinX=m_edgeBRight;
		m_scrollMaxX=m_edgeBLeft+m_contentWidth;

		if(m_scrollMaxX<m_scrollMinX)
		{
			m_scrollMinX=m_scrollMaxX;

		}
	}


	if(m_alignv==ALIGN_TOP)
	{
		m_scrollMinY=m_edgeBTop;
		m_scrollMaxY=m_edgeBBottom+m_contentHeight;
		if(m_scrollMaxY<m_scrollMinY)
		{
			m_scrollMaxY=m_scrollMinY;
		}
	}

	if(m_alignv==ALIGN_CENTER)
	{
		float middle=(m_edgeBTop+m_edgeBBottom)/2;
		float diff=m_contentHeight/2-(m_edgeBTop-m_edgeBBottom)/2;
		if(diff<0)
		{
			diff=0;
		}
		m_scrollMinY=middle-diff;
		m_scrollMaxY=middle+diff;
	}

	if(m_alignv==ALIGN_BOTTOM)
	{
		m_scrollMaxY=m_edgeBBottom;
		m_scrollMinY=m_edgeBTop-m_contentHeight;
		if(m_scrollMinY>m_scrollMaxY)
		{
			m_scrollMinY=m_scrollMaxY;
		}
	}


	scrollChange(m_scrollX,m_scrollY);

}

void ScrollWidget::childSizeChanged(float w,float h)
{
	m_contentWidth=w;
	m_contentHeight=h;
	adjustScrollArea();
}


void ScrollWidget::childAnchorChanged(float w,float h)
{
	scrollChange(m_scrollX,m_scrollY);
}




void ScrollWidget::setSize(float width,float height)
{

	UiWidget::setSize(width,height);
	adjustScrollArea();

}

void ScrollWidget::setAnchor(float x,float y)
{

	UiWidget::setAnchor(x,y);
	adjustScrollArea();

}

void ScrollWidget::scrollChange(float x,float y)
{
}




NS_FS_END 




