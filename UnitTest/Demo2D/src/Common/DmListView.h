#ifndef _DM_LIST_VIEW_H_
#define _DM_LIST_VIEW_H_

#include "demo3D.h"

class DmListItem;

class DmListView:public ListView 
{
	public:
		static DmListView* create(float width,float heigt);

	public:
		std::function<void(int)> onSelected;

	public:
		void setSelected(int index,bool callback);
		void setFocus(DmListItem* l,bool callback);

	protected:
		DmListView();

	private:
		DmListItem* m_focus;

};



#endif /*_DM_LIST_VIEW_H_*/


