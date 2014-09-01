#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_

#include "FsMacros.h"
#include "FsObject.h"

#define FS_SCROLL_DEFAULT_DURATION 0.25f;

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

		void startScroll(float start,float min,float max,float delta,float duration);
		void fling(float start,float min,float max,float velocity,float accel);
		void bounceBack(float start,float min,float max);


		bool isFinish();
		void abortAnimation();
		void finishAnimation();

		float getCurPos();



	public:
		virtual bool update(float dt);

	private:
		float m_mode;


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
		float m_eageVelocityAccum;


		EaseExpr* m_flingEasing;
		/* bounceBack mode */

};






#endif /*_FS_SCROLLER_H_*/

