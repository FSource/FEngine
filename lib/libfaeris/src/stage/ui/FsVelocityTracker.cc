#include "FsVelocityTracker.h"

NS_FS_BEGIN

const char* VelocityTracker::className()
{
	return "VelocityTracker";
}

VelocityTracker* VelocityTracker::create()
{
	return new VelocityTracker();
}


VelocityTracker::VelocityTracker()
{
	m_time.reset();

	m_curTrackIndex=0;
	m_velocityX=0;
	m_velocityY=0;

}


void VelocityTracker::beginTrack(float x,float y)
{
	m_curTrackIndex=0;
	m_time.reset();

	addTrack(x,y);

}


void VelocityTracker::addTrack(float x,float y)
{
	int r_index=m_curTrackIndex%FS_VELOCITY_TRACE_MAX_POINT_SUPPORT;

	m_trackInfo[r_index].m_x=x;
	m_trackInfo[r_index].m_y=y;
	m_trackInfo[r_index].m_time=m_time.now();
	m_curTrackIndex++;

	computeVelocity();

}

void VelocityTracker::endTrack(float x,float y)
{
	addTrack(x,y);
}

void VelocityTracker::computeVelocity()
{
	if(m_curTrackIndex<1)
	{
		m_velocityX=0;
		m_velocityY=0;
	}


	int start,end;

	if(m_curTrackIndex<=FS_VELOCITY_TRACE_MAX_POINT_SUPPORT)
	{
		start=0;
		end=m_curTrackIndex;
	}
	else 
	{
		end=m_curTrackIndex;
		start=m_curTrackIndex-FS_VELOCITY_TRACE_MAX_POINT_SUPPORT;
	}

	TrackInfo* trace_start=&m_trackInfo[start%FS_VELOCITY_TRACE_MAX_POINT_SUPPORT];

	float accum_x=0;
	float accum_y=0;


	for(int i=start+1;i<end;i++)
	{
		TrackInfo* trace_cur=&m_trackInfo[i%FS_VELOCITY_TRACE_MAX_POINT_SUPPORT];

		float duration=(trace_cur->m_time-trace_start->m_time)/1000.0f;

		if(duration==0.0f)
		{
			continue;
		}

		float distance_x=trace_cur->m_x-trace_start->m_x;
		float velocity=distance_x/duration;
		accum_x=(accum_x==0.0f)? velocity : (accum_x+velocity) * 0.5f;

		float distance_y=trace_cur->m_y-trace_start->m_y;
		velocity=distance_y/duration;
		accum_y=(accum_y==0.0f)? velocity: (accum_x+velocity)* 0.5f;

	}

	m_velocityX=accum_x;
	m_velocityY=accum_y;
}


float VelocityTracker::getVelocityX()
{
	return m_velocityX;
}

float VelocityTracker::getVelocityY()
{
	return m_velocityY;
}


NS_FS_END 


