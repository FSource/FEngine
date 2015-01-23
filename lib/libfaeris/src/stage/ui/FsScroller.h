/*************************************************************************/
/*  FsScroller.h                                                         */
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


#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_

#include "FsMacros.h"
#include "FsObject.h"


#define FS_SCROLL_DEFAULT_DURATION 0.25f

NS_FS_BEGIN


class EaseExpr;
class Scroller:public FsObject 
{
	public:
		enum
		{
			SCROLL,
			FLING,
			BOUNCE_BACK,
		};

	public:
		static Scroller* create();

	public:

		void startScroll(float start,float min,float max,float delta,float duration=FS_SCROLL_DEFAULT_DURATION);
		void fling(float start,float min,float max,float velocity,float accel,float range);
		void bounceBack(float start,float min,float max,float range);

		bool isFinished();
		void abortAnimation();
		void finishAnimation();

		float getCurPos();

		int getScrollMode();


	public:
		virtual const char* className();
		virtual bool update(float dt);


	protected:
		Scroller();
		virtual ~Scroller();


		void updateFling(float dt);
		void updateScroll(float dt);
		void updateBounceBack(float dt);




	private:
		int m_mode;

		bool m_finish;


		/* common */
		float m_duration;
		float m_timePassed;

		float m_curPos;
		float m_maxPos;
		float m_minPos;

		/* scroll mode*/
		float m_delta,m_start,m_final;
		EaseExpr* m_scrollEasing;


		/* fling mode */
		float m_startVelocity;
		float m_curVelocity;

		float m_accel;

		bool m_flingDecrease;
		float m_flingEdgeRange;



		EaseExpr* m_flingEasing;

		/* bounceBack mode */
		EaseExpr* m_bounceExpr;

};



NS_FS_END





#endif /*_FS_SCROLLER_H_*/

