#include "DmListItem.h"
#include "DmListView.h"

DmListView* DmListView::create(float width,float height)
{
	DmListView* ret=new DmListView();
	ret->setSize(width,height);
	return ret;
}


DmListView::DmListView()
	:ListView(1,1)
{
	m_focus=NULL;
	onSelected=nullptr;
}

void DmListView::setFocus(DmListItem* l,bool callback)
{
	if(m_focus==l)
	{
		return ;
	}

	if(m_focus)
	{
		m_focus->setFocus(false);
	}
	if(l)
	{
		l->setFocus(true);
	}
	m_focus=l;

	int index=getListItemIndex(l);
	if(onSelected&&callback)
	{
		onSelected(index);
	}

}



void DmListView::setSelected(int index,bool callback)
{
	DmListItem* item=(DmListItem*)getListItem(index);
	setFocus(item,false);
	if(callback&&onSelected)
	{
		onSelected(index);
	}
}
