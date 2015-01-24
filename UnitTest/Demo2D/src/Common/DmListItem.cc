#include "DmListItem.h"
#include "DmListView.h"

#define MD_MOVE_TIME_MAX 10

DmListItem* DmListItem::create(const char* name,float width,float height)
{
	DmListItem* ret=new DmListItem(name);
	ret->setSize(width,height);
	return ret;
}

DmListItem::DmListItem(const char* name)
{
	Color4f dark_color("#ccccccff");
	setBgEnabled(true);
	setBgColor(Color4f("#1c1111ff"));
	m_focus=false;

	if(name)
	{
		LabelTTF* name_text=LabelTTF::create("font/arial.ttf",18,name);
		addChild(name_text);
		name_text->setColor(dark_color);
	}

	m_moveTime=0;

	setTouchEnabled(true);
}

bool DmListItem::touchBegin(float x,float y)
{
	m_moveTime=0;
	setBgColor(Color4f("#9f00a7ff"));

	return true;
}


bool DmListItem::touchMove(float x,float y)
{
	m_moveTime++;
	if(m_moveTime > MD_MOVE_TIME_MAX)
	{
		if(m_focus)
		{
			setBgColor(Color4f("#b91d47ff"));
		}
		else 
		{
			setBgColor(Color4f("#1c1111ff"));
		}
	}
	return true;
}

bool DmListItem::touchEnd(float x,float y)
{
	if(m_focus)
	{
		setBgColor(Color4f("#b91d47ff"));
	}
	else 
	{
		setBgColor(Color4f("#1c1111ff"));
	}
	if(m_moveTime <=MD_MOVE_TIME_MAX)
	{
		DmListView* parent=dynamic_cast<DmListView*>(this->getParentWidget());
		if(parent)
		{
			parent->setFocus(this,true);
			return true;
		}
	}
	return true;
}



void DmListItem::setFocus(bool value)
{
	m_focus=value;

	if(value)
	{
		setBgColor(Color4f("#b91d47ff"));
	}
	else 
	{
		setBgColor(Color4f("#1c1111ff"));
	}

}

