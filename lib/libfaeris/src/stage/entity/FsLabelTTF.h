#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"
#include "graphics/FsFontTTF.h"
#include "graphics/shader/FsProgram.h"

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















