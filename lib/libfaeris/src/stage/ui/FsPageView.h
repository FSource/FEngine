#ifndef _FS_PAGE_VIEW_H_
#define _FS_PAGE_VIEW_H_

#include "FsMacros.h"
#include "FsUiWidget.h"


NS_FS_BEGIN

class PageView:public UiWidget 
{
	public:
		static PageView* create(float width,float height);

	public:
		void addPage(UiWidget* widget);
		void addPage(int index,UiWidget* widget);
		void removePage(UiWidget* widget);
		void removePage(UiWidget* index);
		void clearPage();


		int getPageNu();
		UiWidget* getPage(int index);
		int getPageIndex(UiWidget* widget);

		int getCurrentPageIndex();
		UiWidget* getCurrentPage();


};




NS_FS_END 

#endif /*_FS_PAGE_VIEW_H_*/


