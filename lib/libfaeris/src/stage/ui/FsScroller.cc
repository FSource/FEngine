#include "FsMacros.h"
#include "FsScroller.h"

NS_FS_BEGIN 




bool Scroller::update(float dt)
{

}


void Scroller::startScroll(float start,float min,float max,float detail,float duration)
{
	m_mode=SCROLL;


	m_delta=detail;

	m_start=start;
	m_final=start+detail;

	m_cur=m_start;

	m_min=min;
	m_max=max;


	m_duration=duration;

	m_timePassed=0;


}

void Scroller::fling(float start,float min,float max,float velocity,float accel)
{
	m_start=start;
	m_curPos=m_start;

	m_maxPos=max;
	m_minPos=min;

	m_startVelocity=velocity;
	m_curVelocity=m_startVelocity;
	
	m_accel=accel;
	m_eageVelocityAccum=0;
}


void Scroller::updateFling(float dt)
{
	m_timePassed+=m_timePassed;

	if(m_timePassed>m_duration)
	{
		m_timePassed=m_duration;
		m_finish=true;
	}

	float percent=m_timePassed/m_duration;

	float old_velocity=m_curVelocity;
	m_curVelocity=m_startVelocity*percent+m_eageVelocityAccum;

	if(old_velocity*m_curVelocity<0)
	{
		m_final=true;
		m_curVelocity=0.0f;
	}

	float distance=(m_curVelocity+old_velocity)/2*dt;
	m_curPos+=distance;

	if(m_curPos<m_minPos||m_curPos>m_maxPos)
	{
		m_eageVelocityAccum+=m_accel*dt;
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









NS_FS_END 

