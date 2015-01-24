/*************************************************************************/
/*  DemoChooseLayer.h                                                    */
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
#ifndef _DEMO_CHOOSE_LAYER_H
#define _DEMO_CHOOSE_LAYER_H
#include <vector>

#include "demo3D.h"


NS_FS_BEGIN 
class DemoItem;
class DemoChooseLayer:public Layer2D
{
	public:
		static DemoChooseLayer* create();
		virtual bool init();

		void initItems();
		
		void initValue();
		void initDemoPage();


	protected:
		DemoChooseLayer();
	public:
		int m_pageNumber;
		int m_curPageNumber;

		int m_rowNumber;//一页的行数
		int m_colNumber;//一页的列数

		float m_pageW;
		float m_pageH;

		float m_wBorder;
		float m_hBorder;

		float m_itemW;
		float m_itemH;


		std::vector<DemoItem*> m_demoItems;
};

NS_FS_END

#endif
