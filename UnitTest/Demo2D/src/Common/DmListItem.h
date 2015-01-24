#ifndef _DM_LIST_ITEM_H_
#define _DM_LIST_ITEM_H_ 

#include "demo3D.h"

NS_FS_USE 

class DmListItem:public UiWidget 
{
	public:
		static DmListItem* create(const char* name,float width,float height);

	public:
		void setFocus(bool value); 

	public:
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;

	protected:
		DmListItem(const char* name);

	private:
		bool m_focus;
		int m_moveTime;

};







#endif /*_DM_LIST_ITEM_H_*/



