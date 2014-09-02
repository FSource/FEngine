
#include "FsScrollView.h"

NS_FS_BEGIN

const char* ScrollView::className()
{
	return "ScrollView";
}



ScrollView::ScrollView(float width,float height)
{
	m_contentWidget=NULL;
	setSize(width,height);

}

ScrollView::~ScrollView()
{
	if(m_contentWidget)
	{
		m_contentWidget->setParentWidget(NULL);

	}

}




ScrollView* ScrollView::create(float width,float height)
{
	ScrollView* ret=new ScrollView(width,height);
	return ret; 
}


void ScrollView::setContentWidget(UiWidget* widget)
{
	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("Widget Already Add To This Widget");
		return;
	}

	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("Widget Already Add to Other Widget");
		return;
	}

	if(m_contentWidget)
	{
		m_contentWidget->setParentWidget(NULL);
		remove(m_contentWidget);
		m_contentWidget=NULL;
		m_contentHeight=0;
		m_contentWidth=0;
	}


	if(widget)
	{
		FS_SAFE_ADD_REF(widget);
		m_contentWidget=widget;
		addChild(widget);

		widget->setParentWidget(this);
		m_contentWidth=widget->getWidth();
		m_contentHeight=widget->getHeight();
	}

	adjustScrollArea();

	setScrollPercent(0,0);
}

UiWidget* ScrollView::getContentWidget()
{
	return m_contentWidget;
}


void ScrollView::scrollChange(float x,float y)
{
	if(!m_contentWidget)
	{
		return ;
	}

	Vector2 anchor=m_contentWidget->getAnchor();
	Vector2 size=m_contentWidget->getSize();


	float h,w;


	switch(m_alignv)
	{
		case ALIGN_TOP:
			
			h=(1.0f-anchor.y)*size.y;
			m_contentWidget->setPositionY(y-h);
			break;

		case ALIGN_CENTER:
			h=(0.5f-anchor.y)*size.y;
			m_contentWidget->setPositionY(y-h);
			break;

		case ALIGN_BOTTOM:
			h=-anchor.y*size.y;
			m_contentWidget->setPositionY(y-h);
			break;
		default:
			FS_TRACE_WARN("Unkown Align For Vetical");
	}

	switch(m_alignh)
	{
		case ALIGN_LEFT:
			w=(-anchor.x)*size.x;
			m_contentWidget->setPositionX(x-w);
			break;

		case ALIGN_CENTER:
			w=(0.5f-anchor.x)*size.x;
			m_contentWidget->setPositionX(x-w);
			break;

		case ALIGN_RIGHT:
			w=(1.0f-anchor.x)*size.x;
			m_contentWidget->setPositionX(x-w);
			break;

		default:
			FS_TRACE_WARN("Unkown Align For Horizontal");
	}

	//FS_TRACE_WARN("%f,%f",x,y);

}








NS_FS_END









