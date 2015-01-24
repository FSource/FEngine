/*************************************************************************/
/*  DemoStartLayer.cc                                                    */
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
#include "DemoStartLayer.h"
#include "demoChoose/DemoChooseLayer.h"
#include "demo3D.h"

NS_FS_BEGIN 


DemoStartLayer::DemoStartLayer()
{
	this->init();
}

DemoStartLayer* DemoStartLayer::create()
{
	DemoStartLayer* ret = new DemoStartLayer;
	return  ret;
}

bool DemoStartLayer::init()
{
	setViewArea(0, 0, GAME_WIDTH, GAME_HEIGHT);
	setTouchEnabled(true);
	setDispatchTouchEnabled(true);
	setSortMode(Layer2D::SORT_ORDER_Z);
	
	Quad2D *back = Quad2D::create(Color(172, 218, 224), GAME_WIDTH, GAME_HEIGHT);
	back->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
	add(back);

	LabelTTF * label = LabelTTF::create("font/wawati.ttc", 60, "RealityEngine  Demo");
	label->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2 + 150);
	label->setColor(Color(255, 0, 204));
	add(label);



	PressButton* button = PressButton::createWithScaleStyle("images/button_bg.png", Vector3(0.9f, 0.9f, 1.0f)); 
	button->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2 - 100);
	button->setSize(120, 60);
	button->setColor(PressButton::STATE_NORMAL, Color(96, 219, 2));
	button->setColor(PressButton::STATE_PRESS, Color(196, 219, 2));
	add(button);

	LabelTTF * text = LabelTTF::create("font/wawati.ttc", 30, "play");
	text->setColor(Color(0, 0, 0));
	button->addChild(text);

	auto fn = [this, label](PressButton* ob)
	{
		this->showDemoChooseLayer();

	};
	button->onClick=fn;
	
	FS_TRACE_WARN("DemoStartLayer::init");	
	return true;
}

void DemoStartLayer::showDemoChooseLayer()
{
	FS_TRACE_WARN("showDemoChooseLayer");
	this->getScene()->push(DemoChooseLayer::create());
}



NS_FS_END
