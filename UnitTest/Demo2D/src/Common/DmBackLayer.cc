#include "DmBackLayer.h"
#include "mgr/FsFelisScriptMgr.h"

NS_FS_BEGIN

DmBackLayer* DmBackLayer::create()
{
	DmBackLayer* ret=new DmBackLayer();
	return ret;
}

DmBackLayer::DmBackLayer()
{
	this->setViewArea(0,0,GAME_WIDTH,GAME_HEIGHT);
	this->setTouchEnabled(true);
	this->setDispatchTouchEnabled(true);

	/*
	Quad2D* q=(Quad2D*)Quad2D::getClass()->newInstance("layout/quad_test.fls");
	this->add(q);
	*/

	initButtons();
	initFps();
}

void DmBackLayer::initButtons()
{
	PressButton* button = PressButton::createWithScaleStyle("images/button_bg.png", Vector3(0.9f, 0.9f, 1.0f)); 
	button->setPosition(100, GAME_HEIGHT - 40);
	button->setSize(120, 40);
	button->setColor(PressButton::STATE_NORMAL, Color(96, 219, 2));
	button->setColor(PressButton::STATE_PRESS, Color(196, 219, 2));
	this->add(button);

	LabelTTF * text = LabelTTF::create("font/arial.ttf", 20, "<<Go Back");
	//text->setColor(Color(0, 0, 0));
	button->addChild(text);

	auto fn = [this](PressButton*)
	{
		this->goBack();
	};
	button->onClick=fn;	
}




void DmBackLayer::goBack()
{
	Global::felisScriptMgr()->unloadAll(true);
	Global::director()->pop();
}


void DmBackLayer::update(float dt)
{
	Layer2D::update(dt);
	m_fpsNu+=1;
	m_time+=dt;

	if(m_time>1.0)
	{
		char buf[128];
		sprintf(buf,"FPS:%d",m_fpsNu);
		m_fpsLabel->setString(buf);
		m_time=0;
		m_fpsNu=0;
	}
}

void DmBackLayer::initFps()
{
	m_fpsLabel=nullptr;
	m_fpsNu=0;
	m_time=0;

	
	LabelTTF* fps=LabelTTF::create("font/arial.ttf",20,"fps");
	fps->setPosition(GAME_WIDTH-30,GAME_HEIGHT-30);
	fps->setColor(Color::RED);
	fps->setAnchor(1,0.5);
	this->add(fps);

	m_fpsLabel=fps;
}

NS_FS_END 


