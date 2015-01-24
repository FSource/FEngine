/*************************************************************************/
/*  DmBackLayer.cc                                                       */
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
#include "DmBackLayer.h"

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


