#include "DemoChooseLayer.h"
#include "demo3D.h"
#include "DemoItem.h"
#include "LayoutDemo/DmLayoutScene.h"
//#include "processBarDemo/DmProcessBarDemo.h"

#include "Common/DmBackLayer.h"
#include "ActionDemo/DmActionScene.h"
#include "FilterDemo/DmFilterScene.h"





NS_FS_BEGIN

DemoChooseLayer::DemoChooseLayer()
{
	this->init();
}

DemoChooseLayer* DemoChooseLayer::create()
{
	DemoChooseLayer* layer = new DemoChooseLayer;
	return layer;
}

bool DemoChooseLayer::init()
{
	setViewArea(0, 0, GAME_WIDTH, GAME_HEIGHT);
	setTouchEnabled(true);
	setDispatchTouchEnabled(true);
	setSortMode(Layer2D::SORT_ORDER_Z);

	initItems();
	initValue();

	Quad2D *back = Quad2D::create(Color(228, 228, 228), GAME_WIDTH, GAME_HEIGHT);
	back->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
	add(back);

	LabelTTF * label = LabelTTF::create("font/arial.ttf", 28, "Engine Demo Page 1/2");
	label->setPosition(GAME_WIDTH/2, GAME_HEIGHT - 35);
	label->setColor(Color(255, 0, 204));
	add(label);

	initDemoPage();
	return true;
}

void DemoChooseLayer::initItems()
{
	//DemoItem* di= new DemoItem("xxxxx",[](DemoChooseLayer* l){});

	m_demoItems.push_back(new DemoItem(
				"LayoutDemo", []()->Scene* 
				{
				DmLayoutScene* scene=DmLayoutScene::create();
				return scene;
				}));


	m_demoItems.push_back(new DemoItem(
				"ActionDemo",[]()->Scene*
				{
				ActionScene* scene=ActionScene::create();
				return scene;
				}));
	m_demoItems.push_back(new DemoItem("FilterDemo",[]()->Scene*
	{
			DmFilterScene* scene=DmFilterScene::create();
			return scene;
	}));


}



void DemoChooseLayer::initValue()
{
	float size = (float)m_demoItems.size();
	m_curPageNumber = 1;

	m_pageW = 966;
	m_pageH = 450;

	m_wBorder = 115;
	m_hBorder = 65;

	m_itemW = 177;
	m_itemH = 104;

	m_rowNumber = 3;
	m_colNumber = 4;
	m_pageNumber =(int)ceil(size/(m_rowNumber*m_colNumber));

}

void DemoChooseLayer::initDemoPage()
{

	PageView* pView = PageView::create(m_pageW, m_pageH);
	pView->setBgColor(Color4f(0.2f,0.2f,0.2f,0.5f));
	pView->setBgEnabled(true);

	pView->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
	add(pView);

	float startX = -m_pageW/2 + m_wBorder;
	float startY = m_pageH/2 - m_hBorder;
	float stepX = (m_pageW - 2*m_wBorder)/(m_colNumber - 1);
	float stepY = (m_pageH - 2*m_hBorder)/(m_rowNumber - 1);
	int size = m_demoItems.size() - (m_pageNumber - 1)*(m_colNumber*m_rowNumber);

	for(int m = 0; m< m_pageNumber; m++)
	{
		UiWidget* page = UiWidget::create(m_pageW, m_pageH);
		pView->addPage(page);			

		//page->setAnchor(0,0.2);

		for(int i = 0; i< m_rowNumber; i++)
		{
			for(int j = 0; j< m_colNumber; j++)
			{
				int index = i*m_colNumber + j;

				if (!((m == m_pageNumber - 1)&& index >= size)){
					float x = startX + j*stepX;
					float y = startY - i*stepY;
					//FS_TRACE_WARN("DemoStartLayer::init====(%f)", x);	
					//FS_TRACE_WARN("DemoStartLayer::init====(%f)", y);	

					PressButton* button = PressButton::createWithScaleStyle("images/button_bg.png", Vector3(0.9f, 0.9f, 1.0f)); 
					button->setPosition(x, y);
					button->setSize(m_itemW, m_itemH);
					button->setColor(PressButton::STATE_NORMAL, Color(34, 200, 178));
					button->setColor(PressButton::STATE_PRESS, Color(34, 200, 178));
					page->addChild(button);

					LabelTTF * text = LabelTTF::create("font/wawati.ttc", 22, m_demoItems[index]->m_name);
					text->setColor(Color(0, 0, 0));
					button->addChild(text);

					auto fn = [this, index](PressButton* ob)
					{
						Scene* se=m_demoItems[index]->m_func();
						se->push(DmBackLayer::create());
						Global::director()->push();
						Global::director()->run(se);
					};
					button->onClick=fn;
				}
			}
		}
	}
	pView->setCurrentPageIndex(0);
}


NS_FS_END
