#include "DmSlideBar.h"

NS_FS_BEGIN

DmSlideBar* DmSlideBar::create(const Vector2& bg_size,const Color4f& bg_color,
								const Vector2& fg_size,const Color4f& fg_color) 
{
	DmSlideBar* ret=new DmSlideBar();
	ret->init(bg_size,bg_color,fg_size,fg_color);
	return ret;
}


DmSlideBar::DmSlideBar()
{
	m_slide=NULL;
	m_percent=0;
	onPercentChange=nullptr;

}


void DmSlideBar::init(const Vector2& bg_size,const Color4f& bg_color,
						const Vector2& fg_size,const Color4f& fg_color)
{
	setTouchEnabled(true);
	Quad2D::init(bg_color);
	setSize(bg_size.x,bg_size.y);
	m_slide=Quad2D::create(fg_color,fg_size.x,fg_size.y);
	addChild(m_slide);

	m_bgSize=bg_size;
	m_fgSize=fg_size;

	setPercent(0);
}

Vector2f DmSlideBar::getMoveRange() 
{
	float min_x= -m_bgSize.x/2+m_fgSize.x/2;
	float max_x= m_bgSize.x/2-m_fgSize.x/2;

	return Vector2f(min_x,max_x);
}

bool DmSlideBar::touchBegin(float x,float y)  
{
	m_lastTouchPosX=x;

	return true;
}

bool DmSlideBar::touchMove(float x,float y)
{
	float orgin_x=m_slide->getPositionX();
	float diff=x-m_lastTouchPosX;

	float now_x=orgin_x+diff;

	Vector2f range=getMoveRange();

	now_x=Math::clampf(now_x,range.x,range.y);

	float percent=(now_x-range.x)/(range.y-range.x);

	m_lastTouchPosX=x;
	setPercent(percent,true);
	return true;
}


bool DmSlideBar::touchEnd(float x,float y)
{

	return true;
}


void DmSlideBar::setPercent(float percent,bool call_back)
{
	Vector2f range=getMoveRange();

	float x=range.x+(range.y-range.x)*percent;

	m_percent=percent;
	m_slide->setPosition(x,0,0);

	if(call_back)
	{
		if(onPercentChange)
		{
			onPercentChange(this,percent);
		}
	}
}

float DmSlideBar::getPercent()
{
	return m_percent;
}

bool DmSlideBar::hit2D(float x,float y)
{
	if(m_slide->hit2D(x,y))
	{
		return true;
	}

	float w=m_bgSize.x;
	float h=m_bgSize.y> m_fgSize.y? m_bgSize.y:m_fgSize.y;

	Vector3 v=worldToLocal(Vector3(x,y,0));
	if( Math::abs(v.x) <= w/2)
	{
		if(Math::abs(v.y) <= h/2)
		{
			return true;

		}
	}

	return false;

}



NS_FS_END 


