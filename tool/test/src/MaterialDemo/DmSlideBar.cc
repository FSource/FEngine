/*************************************************************************/
/*  DmSlideBar.cc                                                        */
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
#include "DmSlideBar.h"

NS_FS_BEGIN

DmSlideBar* DmSlideBar::create(const Vector2& bg_size,const Color4f& bg_color,
								const Vector2& fg_size,const Color4f& fg_color) 
{
	DmSlideBar* ret=new DmSlideBar();
	ret->init(bg_size,bg_color,fg_size,fg_color);
	return ret;
}


DmSlideBar::DmSlideBar()
{
	m_slide=NULL;
	m_percent=0;
	onPercentChange=nullptr;

}


void DmSlideBar::init(const Vector2& bg_size,const Color4f& bg_color,
						const Vector2& fg_size,const Color4f& fg_color)
{
	setTouchEnabled(true);
	Quad2D::init(bg_color);
	setSize(bg_size.x,bg_size.y);
	m_slide=Quad2D::create(fg_color,fg_size.x,fg_size.y);
	addChild(m_slide);

	m_bgSize=bg_size;
	m_fgSize=fg_size;

	setPercent(0);
}

Vector2f DmSlideBar::getMoveRange() 
{
	float min_x= -m_bgSize.x/2+m_fgSize.x/2;
	float max_x= m_bgSize.x/2-m_fgSize.x/2;

	return Vector2f(min_x,max_x);
}

bool DmSlideBar::touchBegin(float x,float y)  
{
	m_lastTouchPosX=x;

	return true;
}

bool DmSlideBar::touchMove(float x,float y)
{
	float orgin_x=m_slide->getPositionX();
	float diff=x-m_lastTouchPosX;

	float now_x=orgin_x+diff;

	Vector2f range=getMoveRange();

	now_x=Math::clampf(now_x,range.x,range.y);

	float percent=(now_x-range.x)/(range.y-range.x);

	m_lastTouchPosX=x;
	setPercent(percent,true);
	return true;
}


bool DmSlideBar::touchEnd(float x,float y)
{

	return true;
}


void DmSlideBar::setPercent(float percent,bool call_back)
{
	Vector2f range=getMoveRange();

	float x=range.x+(range.y-range.x)*percent;

	m_percent=percent;
	m_slide->setPosition(x,0,0);

	if(call_back)
	{
		if(onPercentChange)
		{
			onPercentChange(this,percent);
		}
	}
}

float DmSlideBar::getPercent()
{
	return m_percent;
}

bool DmSlideBar::hit2D(float x,float y)
{
	return Quad2D::hit2D(x,y) || m_slide->hit2D(x,y);
}



NS_FS_END 


