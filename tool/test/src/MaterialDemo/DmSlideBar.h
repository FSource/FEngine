/*************************************************************************/
/*  DmSlideBar.h                                                         */
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
#ifndef _DM_SLIDE_BAR_H_
#define _DM_SLIDE_BAR_H_

#include "demo3D.h"

NS_FS_BEGIN

class DmSlideBar:public Quad2D
{
	public:
		static DmSlideBar* create(const Vector2& bg_size, const Color4f& bg_color,
									const Vector2& fg_size,const Color4f& fg_color
										);

	public:
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		bool hit2D(float x,float y) FS_OVERRIDE;

	public:
		void setPercent(float percent,bool call_back=false);
		float getPercent();

	public:
		std::function<void(DmSlideBar*,float)> onPercentChange;


	protected:
		DmSlideBar();
		void init(const Vector2& bg_size, const Color4f& bg_color,
				const Vector2& fg_size,const Color4f& fg_color
				);

		Vector2f getMoveRange();

	private:
		Quad2D* m_slide;

		Vector2f m_bgSize;
		Vector2f m_fgSize;

		float m_percent;



		float m_lastTouchPosX;

};


NS_FS_END 


#endif /* _DM_SLIDE_BAR_H_ */

