/*************************************************************************/
/*  FsLabelTTF.h                                                         */
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


#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"
#include "graphics/FsFontTTF.h"

NS_FS_BEGIN

class Image2D;
class Texture2D;

class Material2D;
class Program;

class FontTTF;

class LabelTTF:public Entity2D
{
	public:
		FS_CLASS_DECLARE(LabelTTF);

	public:
		static LabelTTF* create();
		static LabelTTF* create(const char* font,int size);
		static LabelTTF* create(const char* font,int size,const char* text);

	public:
		void setString(const char* string);
		const char* getString();

		void setFontName(const char* font);
		const char* getFontName();

		void setFontSize(int size);
		int getFontSize();


		void setTextAlign(E_TextAlign align);
		E_TextAlign getTextAlign();


		void setBoundWidth(float width);
		void setBoundHeight(float height);

		void setBoundSize(float width,float height);
		void setBoundSize(const Vector2& v);

		void getBoundSize(float* width,float* height);
		Vector2 getBoundSize();
		float getBoundWidth();
		float getBoundHeight();


		float getTextWidth();
		float getTextHeight();
		void getTextSize(float* width,float* height);

		void setLineGap(float line_gap);
		float getLineGap();



	public:
		/* inherit Entity */
		void draw(RenderDevice* render,bool updateMatrix) FS_OVERRIDE;
		bool hit2D(float x,float y) FS_OVERRIDE;

		using Entity2D::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;



	protected:
		bool init();
		bool init(const char* font,int size);
		bool init(const char* font,int size,const char* text);

		void destruct();

		LabelTTF();
		virtual ~LabelTTF();

		void typoText();
		void realignText();
		void clearTextLine();


	private:
		bool m_dirty;
		std::string m_text;
		uint16_t* m_utf16text;

		std::string m_fontName;
		int m_fontSize;

		E_TextAlign m_textAlign;
		
		float m_boundWidth,m_boundHeight;


		float m_lineGap;


		FontTTF* m_font;

		/* compute result */
		float m_textWidth,m_textHeight;
		TypoPage<TypoText> m_typoPage;


};

NS_FS_END

#endif /*_FS_LABLE_TTF_H_*/



