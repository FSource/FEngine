#ifndef _FS_LABLE_RTF_H_
#define _FS_LABLE_RTF_H_

#include <string>
#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"
#include "graphics/FsFontTTF.h"


NS_FS_BEGIN

class LabelRTF:public Entity2D 
{
	public:
		class LabelRTFState
		{
			public:
				FontTTF* m_font;
				int m_fontSize;
				Color4f m_color;
		};

		class TypoRTFText :public TypoText
		{
			public:
				Color4f m_color;
		};



	public:
		FS_CLASS_DECLARE(LabelRTF);

	public:
		static LabelRTF* create();
		static LabelRTF* create(const char* font,int size);
		static LabelRTF* create(const char* font,int size,const char* text);

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
		void getTextSize(float * width,float* height);

		void setLineGap(float line_gap);
		float getLineGap();

	private:
		bool m_dirty;

		std::string m_text;
		uint16_t* m_utf16text;

		std::string m_fontName;
		FontTTF* m_font;

		int m_fontSize;

		E_TextAlign m_textAlign;
		float m_boundWidth,m_boundHeight;
		float m_lineGap;

		TypoPage<TypoRTFText> m_typoPage;
};





NS_FS_END 



#endif  /*_FS_LABLE_RTF_H_*/



