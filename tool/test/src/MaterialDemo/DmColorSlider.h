/*************************************************************************/
/*  DmColorSlider.h                                                      */
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
#ifndef _DM_COLOR_SLIDER_H_
#define _DM_COLOR_SLIDER_H_

#include "demo3D.h"

#include "DmSlideBar.h"

NS_FS_BEGIN

class DmColorSlider:public UiWidget 
{
	public:
		static DmColorSlider* create(const char* title,const Color3f& c);

	public:
		std::function<void(DmColorSlider*,Color3f)> onColorChange ;
		void setColor(const Color3f& c ,bool call_back=false);

	protected:
		DmColorSlider(const char* title,const Color3f& c);
		void setColorTextValue(Color3f c);

	protected:
		LabelTTF* m_title;

		LabelTTF* m_redValue;
		LabelTTF* m_greenValue;

		LabelTTF* m_blueValue;

		LabelTTF* m_redText;
		LabelTTF* m_blueText;
		LabelTTF* m_greenText;

		DmSlideBar* m_slideRed;
		DmSlideBar* m_slideBlue;
		DmSlideBar* m_slideGreen;
};

NS_FS_END

#endif /*_DM_COLOR_SLIDER_H_*/

