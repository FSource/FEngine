/*************************************************************************/
/*  FsDialog.h                                                           */
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


#ifndef _FS_DIALOG_H_
#define _FS_DIALOG_H_

#include  "FsMacros.h"
#include  "FsUiWidget.h"
#include  "graphics/FsColor.h"

NS_FS_BEGIN 


class Dialog:public UiWidget 
{
	public:
		FS_CLASS_DECLARE(Dialog);

	public:
		static Dialog* create();
		static Dialog* create(float width,float height);

	public:
		bool hit2D(float x,float y) FS_OVERRIDE;
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	public:
		void setDarkOutsideColor(const Color4f& c);
		Color4f getDarkOutsideColor();

		void setDarkOutsideEnabled(bool enabled);
		bool getDarkOutsideEnabled();

		void setDetachOnTouchOutside(bool value);
		bool getDetachOnTouchOutside();

	public:
		virtual void touchOutside(float,float);
		std::function<void(Dialog*,float,float)> onTouchOutside;

	protected:
		Dialog();
		~Dialog();
		void drawOutside(RenderDevice* rd,bool update_matrix);

	private:
		bool m_detachOutside;
		bool m_darkOutsideEnabled;
		Material2D* m_outsideMaterial;
};





NS_FS_END 


#endif /*_FS_DIALOG_H_*/


