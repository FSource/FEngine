#include "DmColorSlider.h"


NS_FS_BEGIN

DmColorSlider* DmColorSlider::create(const char* title,const Color3f& c)
{
	return new DmColorSlider(title,c);
}

DmColorSlider::DmColorSlider(const char* title,const Color3f& c)
{

	Color4f dark_color("#ccccccff");
	onColorChange=nullptr;
	setAnchor(0,0);
	setSize(300,110);
	setBgColor(Color4f(1.0f,1.0f,1.0f,0.20f));
	setBgEnabled(true);

	m_title=LabelTTF::create("font/arial.ttf",18,title);
	m_title->setPosition(7,98,0);
	m_title->setAnchor(0,0.5);
	m_title->setColor(dark_color);

	this->addChild(m_title);


	m_redText=LabelTTF::create("font/arial.ttf",13,"Red:");
	m_redText->setPosition(15,64);
	m_redText->setAnchor(0,0.5);
	m_redText->setColor(dark_color);
	this->addChild(m_redText);


	m_greenText=LabelTTF::create("font/arial.ttf",13,"Green:");
	m_greenText->setPosition(15,41);
	m_greenText->setAnchor(0,0.5);
	m_greenText->setColor(dark_color);
	this->addChild(m_greenText);

	m_blueText=LabelTTF::create("font/arial.ttf",13,"Blue:");
	m_blueText->setPosition(15,19);
	m_blueText->setAnchor(0,0.5);
	m_blueText->setColor(dark_color);
	this->addChild(m_blueText);


	m_redValue=LabelTTF::create("font/arial.ttf",13,"1.00");
	m_redValue->setPosition(255,64);
	m_redValue->setAnchor(0,0.5);
	m_redValue->setColor(dark_color);
	this->addChild(m_redValue);

	m_greenValue=LabelTTF::create("font/arial.ttf",13,"1.00");
	m_greenValue->setPosition(255,41);
	m_greenValue->setAnchor(0,0.5);
	m_greenValue->setColor(dark_color);
	this->addChild(m_greenValue);

	auto fn=[this](DmSlideBar*,float)
	{
		float red=m_slideRed->getPercent();
		float green=m_slideGreen->getPercent();
		float blue=m_slideBlue->getPercent();

		setColorTextValue(Color3f(red,green,blue));


		if(onColorChange)
		{
			onColorChange(this,Color3f(red,green,blue));
		}

	};


	m_blueValue=LabelTTF::create("font/arial.ttf",13,"1.00");
	m_blueValue->setPosition(255,19);
	m_blueValue->setAnchor(0,0.5);
	m_blueValue->setColor(dark_color);
	this->addChild(m_blueValue);


	Vector2 fg_size(10,13);

	m_slideRed=DmSlideBar::create(Vector2(174,7),Color4f::RED,fg_size,Color4f::WHITE);
	m_slideRed->setPosition(150,64);
	this->addChild(m_slideRed);
	m_slideRed->onPercentChange=fn;

	m_slideGreen=DmSlideBar::create(Vector2(174,7),Color4f::GREEN,fg_size,Color4f::WHITE);
	m_slideGreen->setPosition(150,41);
	this->addChild(m_slideGreen);
	m_slideGreen->onPercentChange=fn;

	m_slideBlue=DmSlideBar::create(Vector2(174,7),Color4f::BLUE,fg_size,Color4f::WHITE);
	m_slideBlue->setPosition(150,19);
	this->addChild(m_slideBlue);
	m_slideBlue->onPercentChange=fn;


	setColor(Color3f::WHITE);


}

void DmColorSlider::setColorTextValue(Color3f c)
{

	char buf[128];
	sprintf(buf,"%.2f",c.r);
	m_redValue->setString(buf);

	sprintf(buf,"%.2f",c.g);
	m_greenValue->setString(buf);

	sprintf(buf,"%.2f",c.b);
	m_blueValue->setString(buf);

}

void DmColorSlider::setColor(const Color3f& c,bool call_back)
{
	setColorTextValue(c);
	m_slideRed->setPercent(c.r);
	m_slideGreen->setPercent(c.g);
	m_slideBlue->setPercent(c.b);

	if(call_back&&onColorChange)
	{
		onColorChange(this,c);
	}

	//m_title->setColor(Color4f(c.r,c.g,c.b,1.0));
}


NS_FS_END





