#include "FsMacros.h"
#include "FsScroller.h"

NS_FS_BEGIN 




bool Scroller::update(float dt)
{
	if(m_finished)
	{
		return true;
	}

	m_timePassed+=dt;
	if(m_timePassed< m_duration )
	{
		float x=m_timePassed/m_duration;
		if(m_easing==NULL)
		{
			x=viscousFluid(x);
		}
		else
		{
			x=m_easing->getValue(x);
		}

		m_curX=m_startX+m_deltaX*x;
		m_curY=m_startY+m_deltaY*x;
	}
	else 
	{
		m_curX=m_finalX;
		m_curY=m_finalY;
		m_finished=true;
	}
	return false;
}

void Scroller::startScroll(float start_x,float start_y,float dx,float dy)
{
	startScroll(start_x,start_y,dx,dy,FS_SCROLL_DEFAULT_DURATION);
}

void Scroller::startScroll(float start_x,float start_y,float dx,float dy,float duration)
{
	m_finished=false;
	m_duration=duration;
	m_timePassed=0.0f;
	m_startX=start_x;
	m_startY=start_y;

	m_finalX=m_finalX+dx;
	m_finalY=m_finalY+dy;

	m_deltaX=dx;
	m_deltaY=dy;

}






NS_FS_END 

