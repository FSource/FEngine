/*************************************************************************/
/*  FsVelocityTracker.h                                                  */
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


#ifndef _FS_VELOCITY_TRACKER_H_
#define _FS_VELOCITY_TRACKER_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "sys/FsTimer.h"

#define FS_VELOCITY_TRACE_MAX_POINT_SUPPORT 10
NS_FS_BEGIN

class VelocityTracker:public FsObject 
{
	protected:
		class TrackInfo
		{
			public:
				TrackInfo()
					:m_time(0.0f),
					m_x(0.0f),m_y(0.0f)
				{}

			public:
				float m_time;
				float m_x;
				float m_y;
		};

	public:
		static VelocityTracker* create();

	public:
		virtual const char* className();


	public:
		void beginTrack(float x,float y);
		void addTrack(float x,float y);
		void endTrack(float x,float y);

		float getVelocityX();
		float getVelocityY();

	protected:
		VelocityTracker();

		void computeVelocity();


	private:
		Timer m_time;
		TrackInfo m_trackInfo[FS_VELOCITY_TRACE_MAX_POINT_SUPPORT];
		int m_curTrackIndex;

		float m_velocityX;
		float m_velocityY;



};

NS_FS_END


#endif /*_FS_VELOCITY_TRACKER_H_*/

