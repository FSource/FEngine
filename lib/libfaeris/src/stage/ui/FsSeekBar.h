/*************************************************************************/
/*  FsSeekBar.h                                                          */
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


#ifndef _FS_SEEK_BAR_H_
#define _FS_SEEK_BAR_H_

#include <functional>
#include "FsMacros.h"
#include "FsProcessBar.h"

NS_FS_BEGIN

class SeekBar:public ProcessBar
{
	public:
		static SeekBar* create(const char* bg,const char* fg,const char* seek);
		static SeekBar* create(Texture2D* tex_bg,Texture2D* tex_fg,Texture2D* tex_seek);

	public:
		void setSeekTexture(const char* filename);
		void setSeekTexture(Texture2D* tex);

		Texture2D* getSeekTexture();
		void setSeekMargin(float ml,float mb);
		void setSeekMargin(const Vector2f& v);
		Vector2f getSeekMargin();

		void setSeekSize(float w,float h);
		void setSeekSize(const Vector2f& v);
		Vector2f getSeekSize();

	public:
		virtual void processChange(float value);
		std::function<void(SeekBar*,float)> onProcessChange;

	public:
		void touchBegin(float x,float y) FS_OVERRIDE;
		void touchMove(float x,float y)  FS_OVERRIDE;
		void touchEnd(float x,float y)   FS_OVERRIDE;

		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	protected:
		SeekBar();
		~SeekBar();


	protected:
		Texture2D* m_seekTexture;
		Vector2f m_seekSize;
		Vector2f m_seekMargin;

		Vector2f m_beginDragPos;
		

};



NS_FS_END 

#endif /*_FS_SEEK_BAR_H_*/



