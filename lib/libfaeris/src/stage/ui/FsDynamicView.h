#ifndef _FS_DYNAMIC_VIEW_H_
#define _FS_DYNAMIC_VIEW_H_

#include <functional>
#include "FsMacros.h"
#include "FsUiWidget.h"

NS_FS_BEGIN


class FsDict;

class DynamicView:public UiWidget
{
	protected:
		class ViewInfo:public FsObject 
		{
			public:
				static ViewInfo* create(const char* name,UiWidget* widget,E_AlignH alignh,E_AlignV alignv)
				{
					FsString* fname=FsString::create(name);
					ViewInfo* ret=new ViewInfo(fname,alignh,alignv,widget);
					return ret;
				}

			public:
				E_AlignH m_alignh;
				E_AlignV m_alignv;
				UiWidget* m_widget;
				FsString* m_name;

			protected:
				ViewInfo(FsString* name,E_AlignH alignh,E_AlignV alignv,UiWidget* widget)
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

		};


	public:
		static DynamicView* create();
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
		void addView(const char* name,UiWidget* view,E_AlignH alignh,E_AlignV alignv);

		void removeView(const char* name);
		void removeView(UiWidget* view);

		UiWidget* getCurrentView();
		const char* getCurrentViewName();

		void setCurrentView(const char* name);
		void setCurrentView(UiWidget* view);

		void setViewAlign(UiWidget* view,E_AlignH alignh,E_AlignV alignv);
		void setCurrentViewAlign(E_AlignH alignh,E_AlignV alignv);

		void clearView();


	public:

		using UiWidget::setSize;
		void setSize(const Vector2& v) FS_OVERRIDE;

		using UiWidget::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;

		void childSizeChanged(UiWidget* widget) FS_OVERRIDE;
		void childAnchorChanged(UiWidget* widget) FS_OVERRIDE;
		void childTransformChanged(UiWidget* widget) FS_OVERRIDE;

		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;



	public:
		virtual void currentViewChanged(UiWidget* old_view,UiWidget* new_view);

	public:
		std::function<void(DynamicView*,UiWidget* old_view,UiWidget* new_view)> onCurrentViewChanged;

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

