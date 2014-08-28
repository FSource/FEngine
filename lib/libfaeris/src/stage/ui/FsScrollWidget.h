#ifndef _FS_SCROLL_WIDGET_H_
#define _FS_SCROLL_WIDGET_H_

#include "FsMacros.h"
#include "stage/entity/FsUiWidget.h"

NS_FS_BEGIN

class ScrollWidget:public UiWidget
{
	enum 
	{
		SCROLL_HORIZONTAL,
		SCROLL_VERTICAL,
		SCROLL_ALL,
	};

	public:
		/* inherit Entity */
		virtual  bool touchBegin(float x,float y);
		virtual  bool touchMove(float x,float y);
		virtual  bool touchEnd(float x,float y);

		/* inherit FsObject */
		const char* className();

	public:
		virtual void pressDown(x,y);
		virtual void pressMove(x,y);
		virtual bool PressUp();




	public:
		void setMargin(float l,float r,float t,float b);
		void getMargin(float* l,float* r,float* t,float* b);

		void setMarginLeft(float v);
		float getMarginLeft() const;

		void setMarginRight(float v);
		float getMarginRight() const;

		void setMarginTop(float v);
		float getMarginTop() const ;

		void setMarginBottom(float v);
		float getMarginBottom() const;

	public:
		void setContentSize(float width,float height);
		void setContentAlign(int w,int h);





	public: /* scroll support */
		void scrollBy(float x,float y);
		void scrollTo(float x,float y);

		void setScrollPercent(float x,float y);
		void setScrollPercentX(float x);
		void setScrollPercentY(float y);

		void getScrollPercent(float* x,float* y);
		float getScrollPercentX();
		float getScrollPercentY();


	public:
		void onScrollChange(float x,float y,float oldx,float oldy);

	protected:
		void adjustScrollArea();


	private:
		float m_scrollX,m_scrollY;

		float m_contentWidth,m_contentHeight;

		float m_marginLeft,m_marginRight,m_marginTop,m_marginBottom;
		float m_scrollMaxX,m_scrollMinX,m_scrollMaxY,m_scrollMinY;

		bool m_press;
		int m_scrollState;

		Scroller* m_scroller;

		int m_scrollMode;


};

NS_FS_END

#endif /*_FS_SCROLL_WIDGET_H_*/


