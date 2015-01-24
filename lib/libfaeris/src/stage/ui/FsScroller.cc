/*************************************************************************/
/*  FsScroller.cc                                                        */
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


#include "FsMacros.h"
#include "FsScroller.h"

#include "math/easing/FsEaseExpr.h"
#include "math/easing/FsExponentialEase.h"
#include "math/easing/FsCubicEase.h"
#include "math/easing/FsLinearEase.h"


#include "math/FsMathUtil.h"


NS_FS_BEGIN 


const char* Scroller::className()
{
	return "Scroller";
}

Scroller* Scroller::create()
{
	Scroller* ret=new Scroller;
	return ret;
}

Scroller::Scroller()
{
	m_mode=SCROLL;
	m_finish=true;

	m_duration=0.0f;
	m_timePassed=0.0f;
	
	m_curPos=0.0f;
	m_maxPos=0.0f;
	m_minPos=0.0f;

	m_delta=0.0f;
	m_start=0.0f;
	m_final=0.0f;
	m_scrollEasing=NULL;


	m_startVelocity=0.0f;
	m_curVelocity=0.0f;

	m_accel=0.0f;
	m_flingDecrease=false;
	m_flingEdgeRange=0.0f;

	m_flingEasing=NULL;

	m_bounceExpr=CubicEase::create();
	m_bounceExpr->setMode(FS_EASE_OUT);

}

Scroller::~Scroller()
{
	FS_SAFE_DEC_REF(m_scrollEasing);
	FS_SAFE_DEC_REF(m_flingEasing);
	FS_SAFE_DEC_REF(m_bounceExpr);
}


void Scroller::startScroll(float start,float min,float max,float detail,float duration)
{
	m_finish=false;

	m_mode=SCROLL;
	m_delta=detail;

	m_start=start;
	m_final=start+detail;

	m_maxPos=max;
	m_minPos=min;

	m_curPos=start;

	m_duration=duration;
	m_timePassed=0.0f;

}


void Scroller::fling(float start,float min,float max,float velocity,float accel,float range)
{
	if(velocity==0||accel==0)
	{
		return;
	}


	m_mode=FLING;

	m_timePassed=0;
	m_duration=Math::abs(velocity/accel);


	m_finish=false;
	m_flingDecrease=false;

	m_start=start;
	m_curPos=m_start;

	m_maxPos=max;
	m_minPos=min;

	m_startVelocity=velocity;
	m_curVelocity=m_startVelocity;
	
	m_accel=accel;

	m_flingEdgeRange=range;
}



void Scroller::bounceBack(float start,float min,float max,float range)
{
	if(start<min)
	{
		m_start=start;
		m_curPos=m_start;
		m_final=min;
		m_delta=min-start;
	}
	else if(start>max)
	{
		m_start=start;
		m_curPos=m_start;
		m_final=max;
		m_delta=max-start;
	}
	else
	{
		return;
	}

	m_mode=BOUNCE_BACK;
	m_finish=false;
	float p=Math::abs(m_delta)/(range==0.0f?1.0f:range);

	if(p>1.0f)
	{
		p=1.0f;
	}

	m_duration=p*1.5f;
	m_timePassed=0.0f;
}


bool Scroller::isFinished()
{
	return m_finish;
}

void Scroller::abortAnimation()
{
	m_finish=true;
}

void Scroller::finishAnimation()
{
	if(!m_finish)
	{
		if(m_mode==SCROLL)
		{
			m_curPos=m_final;
		}
		m_finish=true;
	}
}

float Scroller::getCurPos()
{
	return m_curPos;
}





bool Scroller::update(float dt)
{
	if(m_finish)
	{
		return true;
	}

	switch(m_mode)
	{
		case SCROLL:
			updateScroll(dt);
			break;

		case FLING:
			updateFling(dt);
			break;

		case BOUNCE_BACK:
			updateBounceBack(dt);
			break;
	}
	return false;
}

void Scroller::updateFling(float dt)
{

	m_timePassed=m_timePassed+dt;

	if(m_timePassed>m_duration)
	{
		m_timePassed=m_duration;
		m_finish=true;
	}

	float percent=m_timePassed/m_duration;

	float old_velocity=m_curVelocity;

	m_curVelocity=m_startVelocity*(1-percent);


	if(old_velocity*m_curVelocity<0)
	{
		m_finish=true;
		m_curVelocity=0.0f;
	}

	float distance=(m_curVelocity+old_velocity)/2*dt;
	m_curPos+=distance;


	if((m_curPos<m_minPos||m_curPos>m_maxPos)&&!m_flingDecrease)
	{
		float need_time=Math::abs(2.0f/4.0f*m_flingEdgeRange/m_curVelocity);


		m_duration=m_duration-m_timePassed;

		if(m_duration>need_time)
		{
			m_duration=need_time;
		}


		if(m_duration>0.3f)
		{
			m_duration=0.3f;
		}
		m_timePassed=0.0f;
		m_startVelocity=m_curVelocity;
		m_flingDecrease=true;
	}

}

void Scroller::updateScroll(float dt)
{
	m_timePassed+=dt;

	if(m_timePassed>m_duration)
	{
		m_timePassed=m_duration;
		m_finish=true;
	}
	float percent=m_timePassed/m_duration;

	m_curPos=m_start+m_delta*percent;
}

void Scroller::updateBounceBack(float dt)
{

	m_timePassed+=dt;

	if(m_timePassed>m_duration)
	{
		m_timePassed=m_duration;
		m_finish=true;
	}


	float percent=m_timePassed/m_duration;
	m_curPos=m_start+m_delta*m_bounceExpr->getValue(percent);

}



int Scroller::getScrollMode()
{
	return m_mode;
}










NS_FS_END 

