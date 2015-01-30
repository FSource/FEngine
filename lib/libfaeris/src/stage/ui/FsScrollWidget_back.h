/*************************************************************************/
/*  FsScrollWidget.h                                                     */
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


#ifndef _FS_SCROLL_WIDGET_H_
#define _FS_SCROLL_WIDGET_H_

#include "FsMacros.h"
#include "FsUiWidget.h"

NS_FS_BEGIN

class VelocityTracker;
class Scroller;

class ScrollWidget:public UiWidget
{
	public:
		FS_CLASS_DECLARE(ScrollWidget);

	public:
		/* inherit Entity */
		void update(float dt) FS_OVERRIDE;

		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;


		/* inherit UiWidget */
		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widge) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;


		using UiWidget::setSize;
		void setSize(const Vector2& size) FS_OVERRIDE;

		using UiWidget::setAnchor;
		void setAnchor(const Vector2& size) FS_OVERRIDE;


	public:
		virtual void scrollChange(float x,float y);
		virtual void beginDrag();
		virtual void endDrag();



		void setEdgeBounceEnabled(bool enabled);
		bool getEdgeBounceEnabled();


	public:
		void setContentAlign(E_AlignH h,E_AlignV v);


	public: /* scroll support */
		void scrollBy(float x,float y);
		void scrollTo(float x,float y);

		void setScrollPercent(float x,float y);
		void setScrollPercentX(float x);
		void setScrollPercentY(float y);

		void getScrollPercent(float* x,float* y);
		float getScrollPercentX();
		float getScrollPercentY();

		void layout();

	protected:

		ScrollWidget();
		virtual ~ScrollWidget();

		void adjustScrollArea();

		void startScrollX(float cur,float min,float max,float delta);
		void startScrollY(float cur,float min,float max,float delta);

		void updateScroll(float dt);
		void edgeCheckHandle();

		void setContentSize(float width,float height);




	protected:
		float m_scrollX,m_scrollY;



		/* attr cache */
		float m_edgeLeft,m_edgeRight,m_edgeTop,m_edgeBottom;
		float m_edgeBLeft,m_edgeBRight,m_edgeBTop,m_edgeBBottom;


		/* drag info */

		bool m_cancelDrag,m_isDraged;
		float m_lastMotionPosX, m_lastMotionPosY; 


		bool m_press;
		int m_scrollState;

		Scroller* m_scrollerX;
		Scroller* m_scrollerY;

		E_ScrollDirection m_scrollMode;

		E_AlignH m_alignh;
		E_AlignV m_alignv;

		VelocityTracker* m_velocityTracker;

		bool m_edgeBounceEnabled;

};

NS_FS_END

#endif /*_FS_SCROLL_WIDGET_H_*/


