/*************************************************************************/
/*  FsFontBitmap.h                                                       */
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


#ifndef _FS_FONT_BITMAP_H_
#define _FS_FONT_BITMAP_H_

#include <map>
#include "FsMacros.h"
#include "mgr/FsResource.h"

#include "graphics/FsTypoPage.h"


NS_FS_BEGIN

class FsDict;
class FsArray;
class FsFile;
class Texture2D;
class FontBitmap;

class GlyphBitmap:public TypoGlyph
{
	public:
		static GlyphBitmap* create();


	public:
		void getBound(int* minx,int* miny,int* maxx,int* maxy) FS_OVERRIDE;
		int getAdvanceX() FS_OVERRIDE;
		int getAscend() FS_OVERRIDE;
		int getDescend() FS_OVERRIDE;
		int getHeight() FS_OVERRIDE;
		uint16_t getChar() FS_OVERRIDE;

	public:
		void setFont(FontBitmap* font);
		FontBitmap* getFont();


	protected:
		GlyphBitmap();

	public:
		uint16_t m_char;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_xoffset;
		int m_yoffset;
		int m_xadvance;
		int m_page;

		/* info cache */
		int m_minx;
		int m_miny;
		int m_maxx;
		int m_maxy;

		float m_ulb,m_vlb;
		float m_urb,m_vrb;
		float m_urt,m_vrt;
		float m_ult,m_vlt;

		FS_FEATURE_WEAK_REF(FontBitmap*) m_font;

		friend class FontBitmap;
};

class FontBitmap:public Resource
{
	public:
		class GlyphSet 
		{
			public:
				GlyphSet();
				~GlyphSet();
			public:
				void insert(int key,GlyphBitmap* g);
				GlyphBitmap* find(int key);

			private:
				std::map<int,GlyphBitmap*> m_values;
		};

	public:
		static FontBitmap* create(FsFile* file);

	public:
		GlyphBitmap* getGlyph(uint16_t char_index);


		Texture2D* getTexture(int index);

		int getHeight(){return m_height;}
		int getAscent(){return m_ascent;}
		int getDescent(){return m_descent;}

		int getTextureWidth(){return m_textureWidth;}
		int getTextureHeight(){return m_textureHeight;}

	public:
		/* override FsObject */
		virtual const char* className();

	protected:
		FontBitmap();
		virtual ~FontBitmap();

		bool init(FsFile* file);
		void destruct();

	private:
		GlyphSet* m_glyphs;

		int m_textureWidth;
		int m_textureHeight;

		int m_descent;
		int m_ascent;
		int m_height;

		FsArray* m_textures;
};



NS_FS_END 
#endif 



