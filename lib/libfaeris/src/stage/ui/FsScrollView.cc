/*************************************************************************/
/*  FsScrollView.cc                                                      */
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


#include "FsClass.h"
#include "FsScrollView.h"
#include "FsGlobal.h"

NS_FS_BEGIN

ScrollView* ScrollView::create(float width,float height)
{
	ScrollView* ret=new ScrollView(width,height);
	return ret; 
}

ScrollView* ScrollView::create()
{
	ScrollView* ret=new ScrollView();
	return ret; 
}



ScrollView::ScrollView(float width,float height)
{
	m_contentWidget=NULL;

	setSize(Vector2f(width,height));
	setScissorEnabled(true);
}

ScrollView::ScrollView()
{
	m_contentWidget=NULL;
}




ScrollView::~ScrollView()
{

}




void ScrollView::setContentWidget(UiWidget* widget)
{
	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("Widget Already Add To ScrollView");
		return;
	}

	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("Widget Already Add to Other Widget");
		return;
	}

	if(m_contentWidget)
	{
		ScrollWidget::removeChild(m_contentWidget);
		m_contentWidget=NULL;
		setContentSize(0,0);
	}


	if(widget)
	{
		FS_SAFE_ADD_REF(widget);
		m_contentWidget=widget;
		ScrollWidget::addChild(widget);

		float minx,maxx,miny,maxy;
		widget->getRSBoundSize2D(&minx,&maxx,&miny,&maxy);

		setContentSize(maxx-minx,maxy-miny);
	}
	setScrollPercent(0,0);
}

UiWidget* ScrollView::getContentWidget()
{
	return m_contentWidget;
}


void ScrollView::layoutContentWidget(float x,float y)
{
	if(!m_contentWidget)
	{
		return ;
	}

	float minx,maxx,miny,maxy;

	m_contentWidget->getRSBoundSize2D(&minx,&maxx,&miny,&maxy);


	float middlex=(minx+maxx)/2;
	float middley=(miny+maxy)/2;
	m_contentWidget->setSignalTSAEnabled(false);


	switch(m_alignv)
	{
		case E_AlignV::TOP:
			m_contentWidget->setPositionY(y-maxy);
			break;

		case E_AlignV::CENTER:
			m_contentWidget->setPositionY(y-middley);
			break;

		case E_AlignV::BOTTOM:
			m_contentWidget->setPositionY(y-miny);
			break;
		default:
			FS_TRACE_WARN("Unkown Align For Vetical");
	}

	switch(m_alignh)
	{
		case E_AlignH::LEFT:
			m_contentWidget->setPositionX(x-minx);
			break;

		case E_AlignH::CENTER:
			m_contentWidget->setPositionX(x-middlex);
			break;

		case E_AlignH::RIGHT:
			m_contentWidget->setPositionX(x-maxx);
			break;

		default:
			FS_TRACE_WARN("Unkown Align For Horizontal");
	}
	m_contentWidget->setSignalTSAEnabled(true);

	//FS_TRACE_WARN("%f,%f",x,y);

}

void ScrollView::addChild(Entity* en)
{
	FS_TRACE_WARN("Can't Add Child to ScrollView,Use Set ContentWidget");
}


void ScrollView::clearChild()
{
	setContentWidget(NULL);
}

void ScrollView::removeChild(Entity* en)
{
	if(en==m_contentWidget)
	{
		setContentWidget(NULL);
	}
	else 
	{
		FS_TRACE_WARN("Entity Is Not Manager By ScrollView");
	}
}

Entity* ScrollView::getChildByName(const char* name,bool reverse)
{
	return NULL;
}



/** Used For ScrollView ScrollView FsClass */

ScrollView* ScrollView_NewInstance(FsDict* attr)
{
	ScrollView* ret=ScrollView::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}

static void ScrollView_setContentWidget(ScrollView* sl,FsDict* dict)
{
	FsObject* ob=Global::classMgr()->newInstance(dict);
	if(ob)
	{
		UiWidget* ui_widget=dynamic_cast<UiWidget*>(ob);
		if(ui_widget)
		{
			sl->setContentWidget(ui_widget);
		}
		else 
		{
			FS_TRACE_WARN("Need UiWidget For ScrollView ContentWidget");
			ob->decRef();
		}
	}
}


static FsClass::FsAttributeDeclare S_ScrollView_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("contentWidget",E_FsType::FT_DICT,NULL,ScrollView_setContentWidget,0),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(ScrollView,ScrollWidget,ScrollView_NewInstance,S_ScrollView_Main_Attr);













NS_FS_END









