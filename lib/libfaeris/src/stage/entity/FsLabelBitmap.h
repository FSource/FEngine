#ifndef _FS_LABEL_BITMAP_H_
#define _FS_LABEL_BITMAP_H_

#include <string>
#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"

NS_FS_BEGIN


class FontBitmap;

class LabelBitmap:public Entity2D 
{
	public:
		FS_CLASS_DECLARE(LabelBitmap);

	public:
		static LabelBitmap* create();
		static LabelBitmap* create(const char* font,float size);
		static LabelBitmap* create(const char* font,const char* text);
		static LabelBitmap* create(const char* font,float size,const char* text);


	public:
		void setString(const char* str);
		const char* getString();

		void setFontName(const char* font);
		const char* getFomtName();

		void setFontSize(float size);
		float getFontSize();

		void setTextAlign(E_TextAlign align);
		E_TextAlign getTextAlign();

		void setBoundWidth(float width);
		void setBoundHeight(float height);

		void setBoundSize(float width,float height);
		void setBoundSize(const Vector2& v);
		Vector2 getBoundSize();

		float getBoundWidth();
		float getBoundHeight();

		float getTextWidth();
		float getTextHeight();

		void getTextSize(float* width,float* height);
		void setLineGap(float line_gap);
		float getLineGap();


	public:
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;
		void hit2D(float x,float y) FS_OVERRIDE;

		using  Entity2D::setAnchor;
		void setAnchor(const Vector2& v) FS_OVERRIDE;


	protected:
		bool init();
		bool init(const char* font,float size);
		bool init(const char* font,float size,const char* text);

		void destruct();

		LabelBitmap();
		virtual ~LabelBitmap();

		void typoText();
		void realignText();
		void clearTextLine();

	private:
		bool m_dirty;
		std::string m_text;
		uint16_t* m_utf16text;

		std::string m_fontName;
		float m_fontSize;
		E_TextAlign m_textAlign;

		float m_boundWidth,m_boundHeight;
		float m_lineGap;

		FontBitmap* m_font;

		/* compute result */

		float m_textWidth,m_textHeight;
		TypoPage<TypoText> m_typoPage;
};


NS_FS_END 



#endif /*_FS_LABEL_BITMAP_H_*/


