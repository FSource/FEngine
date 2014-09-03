#include "FsScrollWidget.h"
#include "FsScroller.h"
#include "FsVelocityTracker.h"

#define FS_SCROLL_WIDGET_TOUCH_TAP 5


NS_FS_BEGIN


ScrollWidget::ScrollWidget()
	:m_scrollX(0.0f),
	m_scrollY(0.0f),
	m_touchTap(FS_SCROLL_WIDGET_TOUCH_TAP),
	m_contentWidth(0.0f),
	m_contentHeight(0.0f),
	
	m_marginLeft(0.0f),
	m_marginRight(0.0f),
	m_marginTop(0.0f),
	m_marginBottom(0.0f),

	m_scrollMinX(0.0f),
	m_scrollMaxX(0.0f),
	m_scrollMinY(0.0f),
	m_scrollMaxY(0.0f),


	m_edgeLeft(0.0f),
	m_edgeRight(0.0f),
	m_edgeTop(0.0f),
	m_edgeBottom(0.0f),
	m_edgeBLeft(0.0f),
	m_edgeBRight(0.0f),
	m_edgeBTop(0.0f),
	m_edgeBBottom(0.0f),

	m_cancelDrag(true),
	m_isDraged(true),

	m_lastMotionPosX(0.0f),
	m_lastMotionPosY(0.0f),

	m_press(false),
	m_scrollState(0),
	m_scrollerX(NULL),
	m_scrollerY(NULL),

	m_scrollMode(SCROLL_VERTICAL),

	m_alignh(ALIGN_CENTER),
	m_alignv(ALIGN_TOP),

	m_velocityTracker(NULL),
	m_edgeBounceEnabled(true)
{

	m_scrollerX=Scroller::create();
	m_scrollerY=Scroller::create();
	m_velocityTracker=VelocityTracker::create();
}

ScrollWidget::~ScrollWidget()
{
	FS_SAFE_DESTROY(m_scrollerX);
	FS_SAFE_DESTROY(m_scrollerY);
	FS_SAFE_DESTROY(m_velocityTracker);

}




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

float ScrollWidget::getMarginBottom() const
{
	return m_marginBottom;
}

void ScrollWidget::getMargin(float* l,float* r,float* t,float* b)
{
	*l=m_marginLeft;
	*r=m_marginRight;
	*t=m_marginTop;
	*b=m_marginBottom;
}

void ScrollWidget::setScrollMode(int mode)
{
	m_scrollMode=mode;
	setScrollPercent(0.0f,0.0f);
	adjustScrollArea();
}

int ScrollWidget::getScrollMode()
{
	return m_scrollMode;
}

void ScrollWidget::setEdgeBounceEnabled(bool enabled)
{
	m_edgeBounceEnabled=enabled;
}

bool ScrollWidget::getEdgeBounceEnabled()
{
	return m_edgeBounceEnabled;
}





void ScrollWidget::setContentSize(float width,float height)
{
	m_contentWidth=width;
	m_contentHeight=height;
	adjustScrollArea();
}


void ScrollWidget::setContentAlign(int h,int v)
{
	m_alignv=v;
	m_alignh=h;
	adjustScrollArea();
}


void ScrollWidget::scrollBy(float x,float y)
{
	scrollTo(m_scrollX+x,m_scrollY+y);
	scrollChange(m_scrollX,m_scrollY);
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

	float sx= m_scrollMaxX+(m_scrollMinX-m_scrollMaxX)*x;
	float sy= m_scrollMinY+(m_scrollMaxY-m_scrollMinY)*y;

	scrollTo(sx,sy);
}

void ScrollWidget::setScrollPercentX(float x)
{
	float sx= m_scrollMaxX+(m_scrollMinX-m_scrollMaxX)*x;
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
	return (m_scrollX-m_scrollMaxX)/(m_scrollMinX-m_scrollMaxX);
}



float ScrollWidget::getScrollPercentY()
{
	return (m_scrollY-m_scrollMinY)/(m_scrollMaxY-m_scrollMinY);

}


void ScrollWidget::update(float dt)
{
	UiWidget::update(dt);
	updateScroll(dt);
}





bool ScrollWidget::touchBegin(float x,float y)
{
	UiWidget::touchBegin(x,y);

	m_cancelDrag=false;
	m_isDraged=!m_scrollerX->isFinished();

	if(m_isDraged)
	{
		beginDrag();
	}

	if(!m_scrollerX->isFinished())
	{
		m_scrollerX->abortAnimation();
	}

	m_lastMotionPosX=x;
	m_lastMotionPosY=y;

	m_velocityTracker->beginTrack(x,y);

	return true;
}

bool ScrollWidget::touchMove(float x,float y)
{
	UiWidget::touchMove(x,y);

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
		else if(m_scrollMode==SCROLL_VERTICAL)
		{
			if(Math::abs(detal_y) > m_touchTap)
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
			}
		}
		else 
		{
			if(Math::sqrt(detal_x*detal_x+detal_y*detal_y)> m_touchTap)
			{
				m_isDraged=true;

				if(Math::abs(detal_y)>m_touchTap)
				{
					if(detal_y>0)
					{
						detal_y=detal_y-m_touchTap;
					}
					else 
					{
						detal_y=detal_y+m_touchTap;
					}
				}
				else 
				{
					detal_y=0;
				}

				if(Math::abs(detal_y)>m_touchTap)
				{

					if(detal_x>0)
					{
						detal_x=detal_x-m_touchTap;
					}
					else 
					{
						detal_x=detal_x+m_touchTap;
					}
				}
				else 
				{
					detal_x=0;
				}
			}
		}
	}
	if(m_isDraged)
	{
		if(m_scrollMode==SCROLL_HORIZONTAL||m_scrollMode==SCROLL_ALL)
		{
			if(!m_scrollerX->isFinished())
			{
				m_scrollerX->finishAnimation();
				m_scrollX=m_scrollerX->getCurPos();
			}

			startScrollX(m_scrollX,m_scrollMinX,m_scrollMaxX,detal_x);
		}

		if(m_scrollMode==SCROLL_VERTICAL || m_scrollMode==SCROLL_ALL)
		{
			if(!m_scrollerY->isFinished())
			{
				m_scrollerY->finishAnimation();
				m_scrollY=m_scrollerY->getCurPos();
			}
			startScrollY(m_scrollY,m_scrollMinY,m_scrollMaxY,detal_y);
		}

		m_lastMotionPosX=x;
		m_lastMotionPosY=y;
	}

	m_velocityTracker->addTrack(x,y);
	return true;
}


bool  ScrollWidget::touchEnd(float x,float y)
{
	UiWidget::touchEnd(x,y);

	m_isDraged=false;
	m_velocityTracker->endTrack(x,y);
	float d_accel=200;

	if(m_scrollMode==SCROLL_HORIZONTAL||m_scrollMode==SCROLL_ALL)
	{
		if(m_scrollX>m_scrollMaxX||m_scrollX<m_scrollMinX)
		{
			m_scrollerX->abortAnimation();
			m_scrollerX->bounceBack(m_scrollX,m_scrollMinX,m_scrollMaxX,getWidth());
		}
		else 
		{
			float v=m_velocityTracker->getVelocityX();
			v=Math::clampf(v,-1000.0f,1000);

			float accel=-d_accel*Math::sign(v);
			//FS_TRACE_WARN("v=%f,accel=%f",v,accel);

			m_scrollerX->abortAnimation();
			m_scrollerX->fling(m_scrollX,m_scrollMinX,m_scrollMaxX,v,accel,getWidth());
		}

	}

	if(m_scrollMode==SCROLL_VERTICAL||m_scrollMode==SCROLL_ALL)
	{
		if(m_scrollY>m_scrollMaxY||m_scrollY<m_scrollMinY)
		{
			m_scrollerY->abortAnimation();
			m_scrollerY->bounceBack(m_scrollY,m_scrollMinY,m_scrollMaxY,getHeight());
		}
		else 
		{
			float v=m_velocityTracker->getVelocityY();
			v=Math::clampf(v,-1000.0f,1000);

			float accel=-d_accel*Math::sign(v);
			m_scrollerY->abortAnimation();
			m_scrollerY->fling(m_scrollY,m_scrollMinY,m_scrollMaxY,v,accel,getHeight());
			//FS_TRACE_WARN("v=%f,accel=%f",v,accel);
		}
	}

	return true;
}


void ScrollWidget::startScrollX(float cur,float min,float max,float detal)
{
	if(!m_edgeBounceEnabled)
	{
		float finish=cur+detal;
		if(cur<=min&&detal<0)
		{
			return;
		}
		else if(finish<=min)
		{
			detal=min-cur;
		}

		if(cur>=max&&detal>0)
		{
			return;
		}
		else if(finish>=max)
		{
			detal=max-cur;
		}
	}


	if(cur<min&&detal<0)
	{
		float percent=(min-cur)/(getWidth()/2);
		if(percent>1)
		{
			percent=1;

		}
		float rp=(1-percent);

		detal=detal*rp*rp*rp;
	}

	if(cur>max&&detal>0)
	{
		float percent=(cur-max)/(getWidth()/2);
		if(percent>1)
		{
			percent=1;
		}
		float rp=(1-percent);
		detal=detal*rp*rp*rp;
	}

	m_scrollerX->startScroll(cur,min,max,detal,0.1f);
}

void ScrollWidget::startScrollY(float cur,float min,float max,float detal)
{
	if(!m_edgeBounceEnabled)
	{
		float finish=cur+detal;
		if(cur<=min&&detal<0)
		{
			return;
		}
		else if(finish<=min)
		{
			detal=min-cur;
		}

		if(cur>=max&&detal>0)
		{
			return;
		}
		else if(finish>=max)
		{
			detal=max-cur;
		}
	}

	float new_detal=detal;
	if(cur<min&&detal<0)
	{
		float percent=(min-cur)/(getHeight()/2);
		if(percent>1)
		{
			percent=1;
		}
		float rp=(1-percent);
		new_detal=detal*rp*rp*rp;
	}

	if(cur>max&&detal>0)
	{
		float percent=(cur-max)/(getHeight()/2);
		if(percent>1)
		{
			percent=1;
		}

		float rp=(1-percent);
		new_detal=detal*rp*rp*rp;
	}
	m_scrollerY->startScroll(cur,min,max,new_detal,0.1f);
}



void ScrollWidget::updateScroll(float dt)
{
	edgeCheckHandle();

	bool need_readjust=false;
	if(m_scrollMode==SCROLL_HORIZONTAL||m_scrollMode==SCROLL_ALL)
	{

		if(!m_scrollerX->update(dt))
		{
			need_readjust=true;
			m_scrollX=m_scrollerX->getCurPos();

			if(m_scrollerX->getScrollMode()==Scroller::FLING&&!m_edgeBounceEnabled)
			{
				if(m_scrollX>m_scrollMaxX||m_scrollX<m_scrollMinX)
				{
					m_scrollX=Math::clampf(m_scrollX,m_scrollMinX,m_scrollMaxX);
					m_scrollerX->abortAnimation();
				}
			}
		}
	}


	if(m_scrollMode==SCROLL_VERTICAL || m_scrollMode == SCROLL_ALL)
	{

		if( !m_scrollerY->update(dt))
		{
			need_readjust=true;
			m_scrollY=m_scrollerY->getCurPos();

			if(m_scrollerY->getScrollMode()==Scroller::FLING&&!m_edgeBounceEnabled)
			{
				if(m_scrollY>m_scrollMaxY||m_scrollY<m_scrollMinY)
				{
					m_scrollY=Math::clampf(m_scrollY,m_scrollMinY,m_scrollMaxY);
					m_scrollerY->abortAnimation();
				}
			}

		}

	}


	if(need_readjust)
	{
		scrollChange(m_scrollX,m_scrollY);
	}
}



void ScrollWidget::edgeCheckHandle()
{
	if(m_isDraged)
	{
		return; 
	}


	if(m_scrollMode==SCROLL_HORIZONTAL)
	{
		if(!m_scrollerX->isFinished())
		{
			return;
		}

		if(m_scrollX>m_scrollMaxX||m_scrollX<m_scrollMinX)
		{
			m_scrollerX->bounceBack(m_scrollX,m_scrollMinX,m_scrollMaxX,getWidth());
		}
	}

	if(m_scrollMode==SCROLL_VERTICAL)
	{
		if(!m_scrollerY->isFinished())
		{
			return;
		}

		if(m_scrollY>m_scrollMaxY||m_scrollY<m_scrollMinY)
		{
			m_scrollerY->bounceBack(m_scrollY,m_scrollMinY,m_scrollMaxY,getHeight());
		}
	}

	if(m_scrollMode==SCROLL_ALL)
	{

		if(m_scrollerX->isFinished())
		{
			if(m_scrollX>m_scrollMaxX||m_scrollX<m_scrollMinX)
			{
				m_scrollerX->bounceBack(m_scrollX,m_scrollMinX,m_scrollMaxX,getWidth());
			}
		}


		if(m_scrollerY->isFinished())
		{
			if(m_scrollY>m_scrollMaxY||m_scrollY<m_scrollMinY)
			{
				m_scrollerY->bounceBack(m_scrollY,m_scrollMinY,m_scrollMaxY,getHeight());
			}
		}


	}

}


void ScrollWidget::adjustScrollArea()
{
	m_edgeLeft=-m_anchor.x*m_size.x;
	m_edgeRight=(1-m_anchor.x)*m_size.x;

	m_edgeTop=(1-m_anchor.y)*m_size.y;
	m_edgeBottom=-m_anchor.y*m_size.y;



	m_edgeBLeft=m_edgeLeft+m_marginLeft;
	m_edgeBRight=m_edgeRight-m_marginRight;

	m_edgeBTop=m_edgeTop-m_marginTop;
	m_edgeBBottom=m_edgeBottom+m_marginBottom;

	if(m_edgeBRight<m_edgeBLeft)
	{
		float t=(m_edgeBLeft+m_edgeBRight)/2;
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
			m_scrollMaxX=m_scrollMinX;

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


void ScrollWidget::relayout()
{
	adjustScrollArea();
}


void ScrollWidget::scrollChange(float x,float y)
{

}

void ScrollWidget::beginDrag()
{
}
void ScrollWidget::endDrag()
{
}






NS_FS_END 



