#ifndef _FS_SCROLLER_H_
#define _FS_SCROLLER_H_

#include "FsMacros.h"
#include "FsObject.h"

#define FS_SCROLL_DEFAULT_DURATION 0.25f;

class Scroller:public FsObject 
{
	public:
		static Scroller* create();

	public:
		void startScroll(float start_x,float start_y,float dx,float dy);
		void startScroll(float start_x,float start_y,float dx,float dy,float duration);

	public:
		virtual bool update(float dt);



	private:
		float m_startX,m_startY;
		float m_finalX,m_finalY;
		float m_deltaX,m_deltaY;


		float m_curX,m_curY;

		float m_minX,m_minY;
		float m_maxX,m_maxY;

		float m_duration;
		float m_timePassed;

		bool m_finished;


		EaseExpr* m_easing;


};






#endif /*_FS_SCROLLER_H_*/

