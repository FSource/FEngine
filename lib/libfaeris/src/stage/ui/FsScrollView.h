#ifndef _FS_SCROLL_VIEW_H_
#define _FS_SCROLL_VIEW_H_

#include "FsMacros.h"
#include "FsScrollWidget.h"


NS_FS_BEGIN

class ScrollView:public ScrollWidget 
{
	public:
		FS_CLASS_DECLARE(ScrollView);

	public:
		static ScrollView* create();
		static ScrollView* create(float width,float height);

	public:
		void setContentWidget(UiWidget* widget);
		UiWidget* getContentWidget();

	public:
		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;

	public:
		virtual void scrollChange(float x,float y);

	protected:
		ScrollView();
		ScrollView(float width,float height);
		virtual ~ScrollView();



	private:
		UiWidget* m_contentWidget;

};


NS_FS_END



#endif /*_FS_SCROLL_VIEW_H_*/
