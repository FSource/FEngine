/*************************************************************************/
/*  FsVelocityTracker.cc                                                 */
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


