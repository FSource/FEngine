#ifndef _FS_DYNAMIC_VIEW_H_
#define _FS_DYNAMIC_VIEW_H_

#include "FsMacros.h"
#include "FsUiWidget.h"

NS_FS_BEGIN


class FsDict;

class DynamicView:public UiWidget
{
	public:
		enum 
		{
			ALIGN_TOP,
			ALIGN_CENTER,
			ALIGN_BOTTOM,
			ALIGN_LEFT,
			ALIGN_RIGHT,
		};

	protected:
		class ViewInfo:public FsObject 
		{
			public:
				static ViewInfo* create(const char* name,UiWidget* widget,int alignh,int alignv)
				{
					FsString* fname=FsString::create(name);
					ViewInfo* ret=new ViewInfo(fname,alignh,alignv,widget);
					return ret;
				}

			public:
				int m_alignh;
				int m_alignv;
				UiWidget* m_widget;
				FsString* m_name;

			protected:
				ViewInfo(FsString* name,int alignh,int alignv,UiWidget* widget)
				{

					m_alignh=alignh;
					m_alignv=alignv;
					m_widget=widget;
					m_name=name;
					FS_SAFE_ADD_REF(m_widget);
					FS_SAFE_ADD_REF(m_name);
				}

				virtual ~ViewInfo()
				{
					FS_SAFE_DEC_REF(m_widget);
					FS_SAFE_DEC_REF(m_name);
				}

				const char* className()
				{
					return "DynamicView::ViewInfo";
				}
		};


	public:
		static DynamicView* create(float width,float height);

	public:
		void setMargin(float l,float r,float t,float b);
		void getMargin(float* l,float* r,float* t,float* b) const;

		void setMarginLeft(float v);
		float getMarginLeft() const;

		void setMarginRight(float r);
		float getMarginRight() const;

		void setMarginTop(float t);
		float getMarginTop() const;

		void setMarginBottom(float b);
		float getMarginBottom() const;


	public:
		void addView(const char* name,UiWidget* view);
		void addView(const char* name,UiWidget* view,int alignh,int alignv);

		void removeView(const char* name);
		void removeView(UiWidget* view);

		UiWidget* getCurrentView();
		const char* getCurrentViewName();

		void setCurrentView(const char* name);
		void setCurrentView(UiWidget* view);

		void setViewAlign(UiWidget* view,int alignh,int alignv);
		void setCurrentViewAlign(int alignh,int alignv);



	public:
		virtual const char* className();

		virtual void sizeChanged(float w,float h);
		virtual void anchorChanged(float x,float y);
		virtual void childSizeChanged(UiWidget* widget,float w,float h);
		virtual void childAnchorChanged(UiWidget* widget,float x,float y);

		virtual void layout();
		virtual void removeWidget(UiWidget* widget);



	public:
		virtual void currentViewChanged(UiWidget* old_view,UiWidget* new_view);

	protected:
		DynamicView(float width,float height);
		virtual ~DynamicView();


		ViewInfo* getViewInfo(const char* name);
		ViewInfo* getViewInfo(UiWidget* view);

		void removeViewInfo(ViewInfo* viewinfo);
		void addViewInfo(ViewInfo* info);

		void setCurrentViewInfo(ViewInfo* viewinfo);

		void adjustCurrentView();




	protected:

		FsDict* m_views;
		FS_FEATURE_WEAK_REF(ViewInfo*) m_currentView;

		float m_marginLeft,m_marginRight,m_marginTop,m_marginBottom;

};

NS_FS_END



#endif /*_FS_DYNAMIC_VIEW_H_*/

