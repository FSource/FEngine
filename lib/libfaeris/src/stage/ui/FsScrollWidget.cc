

#include "FsMacros.h"

#include "FsClass.h"
#include "math/easing/FsEaseExpr.h"
#include "math/easing/FsExponentialEase.h"
#include "math/easing/FsCubicEase.h"
#include "math/easing/FsLinearEase.h"
#include "math/easing/FsCircleEase.h"
#include "math/easing/FsQuadEase.h"
#include "math/easing/FsQuintEase.h"

#include "math/FsMathUtil.h"

#include "FsScrollWidget.h"


#define FS_DEFAULT_TAP_TIME_TO_SCROLL 0.3f
#define FS_DEFAULT_TAP_DISTANCE_TO_SCROLL 10 


#define FS_DEFAULT_DECELERATION 200



NS_FS_BEGIN 

ScrollWidget::ScrollWidget()
	:m_scrollXEnabled(true),
	m_scrollYEnabled(true),
	m_directionLockedEnabled(true),
	m_directionLockThreshold(5),
	m_tapTimeToScroll(FS_DEFAULT_TAP_TIME_TO_SCROLL),
	m_tapDistanceToScroll(FS_DEFAULT_TAP_DISTANCE_TO_SCROLL),
	m_blockEventOnScroll(true),
	m_momentumEnabled(true),
	m_deceleration(FS_DEFAULT_DECELERATION),
	m_contentWidth(0.0f),
	m_contentHeight(0.0f),
	m_alignh(E_AlignH::CENTER),
	m_alignv(E_AlignV::CENTER),
	m_marginLeft(0.0f),
	m_marginRight(0.0f),
	m_marginTop(0.0f),
	m_marginBottom(0.0f),
	m_bounceEnabled(true),
	m_bounceTime(0.6f),
	m_minScrollX(0.0f),
	m_maxScrollX(0.0f),
	m_minScrollY(0.0f),
	m_maxScrollY(0.0f),
	m_positionX(0.0f),
	m_positionY(0.0f),
	m_startX(0.0f),
	m_startY(0.0f),
	m_startTime(0.0f),
	m_distX(0.0f),
	m_distY(0.0f),
	m_directionMoveMode(E_DirectionMoveMode::BOTH),
	m_edgeLeft(0.0f),
	m_edgeRight(0.0f),
	m_edgeTop(0.0f),
	m_edgeBottom(0.0f),
	m_edgeBLeft(0.0f),
	m_edgeBRight(0.0f),
	m_edgeBTop(0.0f),
	m_edgeBBottom(0.0f),
	m_isAnimating(false),
	m_isDrag(false),
	m_animatingFromX(0.0f),
	m_animatingToX(0.0f),
	m_animatingFromY(0.0f),
	m_animatingToY(0.0f),
	m_animatingTotalTime(0.0f),
	m_animatingElapseTime(0.0f),
	m_animatingEasingUse(NULL)
{
	m_bounceEasing=CircleEase::create();
	m_bounceEasing->setMode(FS_EASE_OUT);
	m_bounceEasing->addRef();

	m_animatingEasing=CircleEase::create();
	m_animatingEasing->setMode(FS_EASE_OUT);
	m_animatingEasing->addRef();

	m_animatingOutEdgeEasing=LinearEase::create();
	m_animatingOutEdgeEasing->setMode(FS_EASE_OUT);
	m_animatingOutEdgeEasing->addRef();

	onBeforeScrollStart=nullptr;
	onScrollCancel=nullptr;
	onScrollStart=nullptr;
	onScroll=nullptr;
	onScrollEnd=nullptr;
	onFlick=nullptr;


}

ScrollWidget::~ScrollWidget()
{
	FS_SAFE_DEC_REF(m_bounceEasing);
	FS_SAFE_DEC_REF(m_animatingEasing);
	FS_SAFE_DEC_REF(m_animatingOutEdgeEasing);
}






	


void ScrollWidget::update(float dt)
{
	updateScroll(dt);
	UiWidget::update(dt);
}





bool ScrollWidget::touchBegin(float x,float y)
{

	m_directionMoveMode=E_DirectionMoveMode::BOTH;
	m_startTime=m_timer.now()/1000.0f;

	m_startX=m_positionX;
	m_startY=m_positionY;

	if(m_isAnimating)
	{
		m_lastPosX=x;
		m_lastPosY=y;
		m_isAnimating=false;
		m_isDrag=true;
		return true;
	}
	m_isAnimating=false;
	m_isDrag=false;

	m_lastPosX=x;
	m_lastPosY=y;

	m_distX=0;
	m_distY=0;

	FS_OBJECT_LAMBDA_CALL(this,onBeforeScrollStart,beforeScrollStart);

	UiWidget::touchBegin(x,y);
	return true;
}

bool ScrollWidget::touchMove(float x,float y)
{

	float diffx=x-m_lastPosX;
	float diffy=y-m_lastPosY;
	if(!m_scrollXEnabled)
	{
		diffx=0.0f;
	}

	if(!m_scrollYEnabled)
	{
		diffy=0.0f;
	}


	m_lastPosX=x;
	m_lastPosY=y;

	m_distX+=diffx;
	m_distY+=diffy;

	float cur_time=m_timer.now()/1000.0f;


	float abs_distx=Math::abs(m_distX);
	float abs_disty=Math::abs(m_distY);

	if(!m_isDrag)
	{
		FS_TRACE_WARN("%f,%f,d=%f,%f",cur_time,m_startTime,abs_distx,abs_disty);
		if((cur_time-m_startTime)<m_tapTimeToScroll &&((abs_distx<m_tapDistanceToScroll)&& (abs_disty<m_tapDistanceToScroll)))
		{
			return true;
		}

		if(m_directionLockedEnabled)
		{
			if(abs_distx>abs_disty+m_directionLockThreshold)
			{
				m_directionMoveMode=E_DirectionMoveMode::HORIZONTAL;

			}
			else if(abs_disty>abs_distx+m_directionLockThreshold)
			{
				m_directionMoveMode=E_DirectionMoveMode::VERTICAL;
			}
			else 
			{
				m_directionMoveMode=E_DirectionMoveMode::BOTH;
			
			}
		}
		else 
		{
			m_directionMoveMode=E_DirectionMoveMode::BOTH;
		}

		m_isDrag=true;
		m_distX=0;
		m_distY=0;
		FS_OBJECT_LAMBDA_CALL(this,onScrollStart,scrollStart);

		if(m_blockEventOnScroll)
		{
			//UiWidget::touchCancel(x,y);
		}

		return true;
	}

	assert(m_isDrag==true);

	switch(m_directionMoveMode)
	{
		case E_DirectionMoveMode::HORIZONTAL:
			diffy=0;
			break;
		case E_DirectionMoveMode::VERTICAL:
			diffx=0;
			break;
		default:
			/* Do Nothing Here */
			break;
	}


	float new_x=m_positionX+diffx;
	float new_y=m_positionY+diffy;

	if(new_x<m_minScrollX || new_x>m_maxScrollX)
	{
		if(m_bounceEnabled)
		{
			new_x=m_positionX+diffx/3;
		}
		else 
		{
			new_x=Math::clampf(new_x,m_minScrollX,m_maxScrollX);
		}
	}

	if(new_y<m_minScrollY||new_y > m_maxScrollY)
	{
		if(m_bounceEnabled)
		{
			new_y=m_positionY+diffy/3;
		}
		else 
		{
			new_y=Math::clampf(new_x,m_minScrollY,m_maxScrollY);
		}
	}

	FS_OBJECT_LAMBDA_CALL(this,onScroll,scroll);

	scrollSet(new_x,new_y);

	if(cur_time-m_startTime>0.3f)
	{
		m_startTime=cur_time;
		m_startX=m_positionX;
		m_startY=m_positionY;
	}
	UiWidget::touchMove(x,y);
	return true;
}

bool ScrollWidget::touchEnd(float x,float y)
{
	float duration=m_timer.now()/1000.0f-m_startTime;

	float new_x=m_positionX;
	float new_y=m_positionY;

	float distance_x=new_x-m_startX;
	float distance_y=new_y-m_startY;

	if(doEdgeOut(m_bounceTime))
	{
		FS_TRACE_WARN("doEdgeOut");
		UiWidget::touchEnd(x,y);
		return true;
	}

	if(!m_isDrag)
	{
		m_isDrag=false;
		m_isAnimating=false;
		FS_OBJECT_LAMBDA_CALL(this,onScrollCancel,scrollCancel);

		FS_TRACE_WARN("undrag");
		UiWidget::touchEnd(x,y);
		return true;
	}

	if(!m_momentumEnabled)
	{
		m_isDrag=false;
		m_isAnimating=false;

		FS_OBJECT_LAMBDA_CALL(this,onScrollEnd,scrollEnd);

		UiWidget::touchEnd(x,y);
		return true;
	}


	float des_x,time_x;
	float des_y,time_y;


	float wrap_x=m_edgeRight-m_edgeLeft;
	float wrap_y=m_edgeBTop-m_edgeBBottom;


	if(m_directionMoveMode==E_DirectionMoveMode::BOTH)
	{
		calMomentum(m_positionX,m_startX,duration,m_minScrollX,m_maxScrollX,wrap_x,m_deceleration,&des_x,&time_x);
		calMomentum(m_positionY,m_startY,duration,m_minScrollY,m_maxScrollY,wrap_y,m_deceleration,&des_y,&time_y);
	}
	else if(m_directionMoveMode==E_DirectionMoveMode::HORIZONTAL)
	{
		calMomentum(m_positionX,m_startX,duration,m_minScrollX,m_maxScrollX,wrap_x,m_deceleration,&des_x,&time_x);
		des_y=m_positionY;
		time_y=0;
	}
	else if(m_directionMoveMode==E_DirectionMoveMode::VERTICAL)
	{
		calMomentum(m_positionY,m_startY,duration,m_minScrollY,m_maxScrollY,wrap_y,m_deceleration,&des_y,&time_y);
		des_x=m_positionX;
		time_x=0;
	}

	if(!m_bounceEnabled)
	{
		des_x=Math::clampf(des_x,m_minScrollX,m_maxScrollX);
		des_y=Math::clampf(des_y,m_minScrollY,m_maxScrollY);
	}


	float time=Math::maxf(time_x,time_y);
	if(des_x<m_minScrollX||des_x>m_maxScrollX||des_y<m_minScrollY||des_y>m_maxScrollY)
	{
		FS_TRACE_WARN("bounce out easing");
		scrollTo(des_x,des_y,time,m_animatingOutEdgeEasing);
	}
	else 
	{
		FS_TRACE_WARN("normal easing");
		scrollTo(des_x,des_y,time,m_animatingEasing);
	}

	UiWidget::touchEnd(x,y);
	return true;
}


void ScrollWidget::updateScroll(float dt)
{
	if(m_isAnimating)
	{
		m_animatingElapseTime=m_animatingElapseTime+dt;
		if(m_animatingElapseTime>m_animatingTotalTime)
		{
			m_isAnimating=false;
			scrollSet(m_animatingToX,m_animatingToY);
			if(!doEdgeOut(m_bounceTime))
			{
				FS_OBJECT_LAMBDA_CALL(this,onScrollEnd,scrollEnd);
			}
			return;
		}

		float percent=m_animatingElapseTime/m_animatingTotalTime;
		if(m_animatingEasingUse)
		{
			percent=m_animatingEasingUse->getValue(percent);
		}
		float new_x=(m_animatingToX-m_animatingFromX)*percent+m_animatingFromX;
		float new_y=(m_animatingToY-m_animatingFromY)*percent+m_animatingFromY;

		scrollSet(new_x,new_y);
	}
}

bool ScrollWidget::doEdgeOut(float time)
{
	float x=m_positionX;
	float y=m_positionY;

	if(x<m_minScrollX)
	{
		x=m_minScrollX;
	}
	else if(x>m_maxScrollX)
	{
		x=m_maxScrollX;
	}

	if(y<m_minScrollY)
	{
		y=m_minScrollY;
	}
	else if(y>m_maxScrollY)
	{
		y=m_maxScrollY;
	}

	if((x==m_positionX) && (y==m_positionY))
	{
		return false;
	}
	scrollTo(x,y,time,m_bounceEasing);
	return true;
}


void ScrollWidget::scrollSet(float x,float y)
{
	m_positionX=x;
	m_positionY=y;

	layoutContentWidget(m_positionX,m_positionY);
}

void ScrollWidget::scrollBy(float x,float y,float duration,EaseExpr* easing)
{
	scrollTo(m_positionX+x,m_positionY+y,duration,easing);
}

void ScrollWidget::scrollTo(float x,float y,float duration,EaseExpr* easing)
{
	m_isAnimating=true;

	m_animatingFromX=m_positionX;
	m_animatingFromY=m_positionY;

	m_animatingToX=x;
	m_animatingToY=y;

	m_animatingTotalTime=duration;
	m_animatingElapseTime=0;

	FS_SAFE_ASSIGN(m_animatingEasingUse,easing);
}

void ScrollWidget::stopScroll()
{
	if(!m_isAnimating)
	{
		return;
	}


	m_isAnimating=false;

	float x=Math::clampf(m_positionX,m_minScrollX,m_maxScrollX);
	float y=Math::clampf(m_positionY,m_minScrollX,m_maxScrollY);
	scrollSet(x,y);
}

void ScrollWidget::finishScroll()
{
	if(!m_isAnimating)
	{
		return;
	}

	m_isAnimating=false;
	float x=Math::clampf(m_animatingToX,m_minScrollX,m_maxScrollX);
	float y=Math::clampf(m_animatingToY,m_minScrollY,m_maxScrollY);
	scrollSet(x,y);
}

void ScrollWidget::calMomentum(float cur_pos,float start,
						float duration,
						float min,
						float max,
						float wrap_size,
						float deceleration,
						float* des,
						float *time
						)
{


	float distance=cur_pos-start;
	float speed=Math::abs(distance)/duration;
	FS_TRACE_WARN("distance=%f,speed=%f",distance,speed);

	if(deceleration<=0)
	{
		deceleration=FS_DEFAULT_DECELERATION;
	}

	float destination=cur_pos+(speed*speed)/(2*deceleration)*(distance<0?-1:1);
	duration=speed/deceleration;
	duration=Math::clampf(duration,0,5);

	destination=cur_pos+speed*duration/2*(distance<0?-1:1);

	if(destination<min)
	{
		destination= min-(wrap_size/4.0f);
		distance=Math::abs(destination-cur_pos);
		duration=distance/speed;
	}

	else if(destination>max)
	{
		destination=max+(wrap_size/4.0f);
		distance=Math::abs(destination-cur_pos);
		duration=distance/speed;
	}


	*des=destination;
	*time=duration;

}


void ScrollWidget::setSize(const Vector2&  size)
{
	UiWidget::setSize(size);
	adjustScrollArea();
}

void ScrollWidget::setAnchor(const Vector2& v)
{
	UiWidget::setAnchor(v);
	adjustScrollArea();
}


void ScrollWidget::childSizeChanged(UiWidget* widget)
{
	m_contentWidth=widget->getWidth();
	m_contentHeight=widget->getHeight();
	adjustScrollArea();
}


void ScrollWidget::childAnchorChanged(UiWidget* widget)
{
	layoutContentWidget(m_positionX,m_positionY);
}

void ScrollWidget::childTransformChanged(UiWidget* widget)
{
	layoutContentWidget(m_positionX,m_positionY);
}

void ScrollWidget::setContentAlign(E_AlignH h,E_AlignV v)
{
	m_alignv=v;
	m_alignh=h;
	adjustScrollArea();
}


void ScrollWidget::setContentSize(float width,float height)
{
	m_contentWidth=width;
	m_contentHeight=height;
	adjustScrollArea();
}


void ScrollWidget::setScrollPercent(float x,float y)
{
	x=Math::clampf(x,0.0f,1.0f);
	y=Math::clampf(y,0.0f,1.0f);

	float sx= m_maxScrollX+(m_minScrollX-m_maxScrollX)*x;
	float sy= m_minScrollY+(m_maxScrollY-m_minScrollY)*y;

	scrollSet(sx,sy);
}


void ScrollWidget::setScrollPercentX(float value)
{
	float x=Math::clampf(value,0.0f,1.0f);
	float sx= m_maxScrollX+(m_minScrollX-m_maxScrollX)*x;
	scrollSet(sx,m_positionY);
}

void ScrollWidget::setScrollPercentY(float value)
{
	float y=Math::clampf(value,0.0f,1.0f);
	float sy= m_minScrollY+(m_maxScrollY-m_minScrollY)*y;
	scrollSet(m_positionX,sy);
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


float ScrollWidget::getScrollPercentX()
{
	float width=m_minScrollX-m_maxScrollX;
	if(width==0.0f)
	{
		return 0;
	}
	float ret=(m_positionX-m_maxScrollX)/width;
	return Math::clampf(ret,-2,2);
}



float ScrollWidget::getScrollPercentY()
{
	float height= (m_maxScrollY-m_minScrollY);
	if(height==0.0f)
	{
		return 0;
	}
	float ret=(m_positionY-m_minScrollY)/height;
	return Math::clampf(ret,-2,2);

}


void ScrollWidget::setScrollXEnabled(bool value)
{
	m_scrollXEnabled=value;
}

void ScrollWidget::setScrollYEnabled(bool value)
{
	m_scrollYEnabled=value;
}

bool ScrollWidget::getScrollXEnabled()
{
	return m_scrollXEnabled;
}

bool ScrollWidget::getScrollYEnabled()
{
	return m_scrollYEnabled;
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


	switch(m_alignh)
	{

		case E_AlignH::LEFT:
			{
				m_maxScrollX=m_edgeBLeft;
				m_minScrollX=m_edgeBRight-m_contentWidth;

				if(m_minScrollX>m_maxScrollX)
				{
					m_minScrollX=m_maxScrollX;
				}
			}
			break;

		case E_AlignH::CENTER:
			{
				float middle=(m_edgeBLeft+m_edgeBRight)/2;
				float diff=m_contentWidth/2-(m_edgeBRight-m_edgeBLeft)/2;
				if(diff<0)
				{
					diff=0;
				}

				m_minScrollX=middle-diff;
				m_maxScrollX=middle+diff;
			}
			break;

		case E_AlignH::RIGHT:
			{
				m_minScrollX=m_edgeBRight;
				m_maxScrollX=m_edgeBLeft+m_contentWidth;

				if(m_maxScrollX<m_minScrollX)
				{
					m_maxScrollX=m_minScrollX;

				}
			}
			break;
	}

	switch(m_alignv)
	{
		case E_AlignV::TOP:
			{
				m_minScrollY=m_edgeBTop;
				m_maxScrollY=m_edgeBBottom+m_contentHeight;
				if(m_maxScrollY<m_minScrollY)
				{
					m_maxScrollY=m_minScrollY;
				}
			}
			break;

		case E_AlignV::CENTER:
			{
				float middle=(m_edgeBTop+m_edgeBBottom)/2;
				float diff=m_contentHeight/2-(m_edgeBTop-m_edgeBBottom)/2;
				if(diff<0)
				{
					diff=0;
				}
				m_minScrollY=middle-diff;
				m_maxScrollY=middle+diff;
			}
			break;

		case E_AlignV::BOTTOM:
			{
				m_maxScrollY=m_edgeBBottom;
				m_minScrollY=m_edgeBTop-m_contentHeight;
				if(m_minScrollY>m_maxScrollY)
				{
					m_minScrollY=m_maxScrollY;
				}
			}
			break;
	}

	layoutContentWidget(m_positionX,m_positionY);
}


void ScrollWidget::beforeScrollStart()
{

}

void ScrollWidget::scrollCancel()
{

}

void ScrollWidget::scrollStart()
{

}

void ScrollWidget::scroll()
{

}

void ScrollWidget::scrollEnd()
{

}

void ScrollWidget::flick()
{

}

void ScrollWidget::layoutContentWidget(float x,float y)
{
}






/** User For ScrollWidget FsClass Attr */


static FsClass::FsAttributeDeclare S_ScrollWidget_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};


FS_CLASS_IMPLEMENT_WITH_BASE(ScrollWidget,UiWidget,0,S_ScrollWidget_Main_Attr);




NS_FS_END 

