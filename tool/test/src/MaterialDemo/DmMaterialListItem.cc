/*************************************************************************/
/*  DmMaterialListItem.cc                                                */
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
#include "DmMaterialListItem.h"

#define MD_MOVE_TIME_MAX 10

NS_FS_BEGIN

DmMaterialListItem* DmMaterialListItem::create(const char* name,const char* cname,const char* mtl)
{
	DmMaterialListItem* ret=new DmMaterialListItem(name,cname,mtl);
	return ret;
}

DmMaterialListItem::DmMaterialListItem(const char* name,const char* cname,const char* mtl)
{
	Color4f dark_color("#ccccccff");
	setBgEnabled(true);
	m_focus=false;
	m_name=name;

	if(cname!=NULL)
	{
		m_cname=cname;
	}

	m_material=mtl;
	setFocus(false);
	setSize(200,40);

	LabelTTF* name_text=LabelTTF::create("font/arial.ttf",18,name);
	addChild(name_text);
	name_text->setColor(dark_color);
	m_moveTime=0;
	onClick=nullptr;

	setTouchEnabled(true);
}

bool DmMaterialListItem::touchBegin(float x,float y)
{
	m_moveTime=0;
	setBgColor(Color4f("#9f00a7ff"));

	return true;
}
bool DmMaterialListItem::touchMove(float x,float y)
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

bool DmMaterialListItem::touchEnd(float x,float y)
{
	if(m_moveTime <=MD_MOVE_TIME_MAX)
	{
		if(onClick)
		{
			onClick(this);
		}
	}
	return true;
}



void DmMaterialListItem::setFocus(bool value)
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



NS_FS_END


