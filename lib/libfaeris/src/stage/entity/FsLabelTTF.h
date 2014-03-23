#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "graphics/FsTypoPage.h"
#include "graphics/FsFontTTF.h"

NS_FS_BEGIN
class Image2D;
class Texture2D;

class TextureMaterial;
class Program;

class FontTTF;

class LabelTTF:public Entity
{
	public:
		static LabelTTF* create();
		static LabelTTF* create(const char* font,int size);
		static LabelTTF* create(const char* font,int size,const char* text);


	public:

		/* material */
		void setColor(Color4f c){m_material->setColor(c);}
		Color4f getColor(){return m_material->getColor();}

		void setOpacity(float opacity){m_material->setOpacity(opacity);}
		float getOpacity(){return m_material->getOpacity();}

		void setBlend(int eq,int src,int dst){m_material->setBlend(eq,src,dst);}
		void setBlend(int src,int dst){m_material->setBlend(src,dst);}

		TextureMaterial* getMaterial(){return m_material;}
		void setMaterial(TextureMaterial* mat){FS_SAFE_ASSIGN(m_material,mat);}

		Program* getShader(){return m_program;}
		void setShader(Program* shader){FS_SAFE_ASSIGN(m_program,shader);}


	public:
		void setString(const char* string);
		const char* getString();

		void setFontName(const char* font);
		const char* getFontName();

		void setFontSize(int size);
		int getFontSize();


		void setTextAlign(int align);
		int getTextAlign();

		void setBoundSize(float width,float height);
		void getBoundSize(float* width,float* height);

		float getTextWidth();
		float getTextHeight();
		void getTextSize(float* width,float* height);

		void setLineGap(float line_gap);
		float getLineGap();

		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);


	public:
		/* inherit Entity */
		virtual void draw(Render* render,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();
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

		int m_textAlign;
		
		float m_boundWidth,m_boundHeight;

		float m_anchorX,m_anchorY;

		float m_lineGap;


		FontTTF* m_font;

		/* compute result */
		float m_textWidth,m_textHeight;
		TypoPage<TypoText> m_typoPage;


		/* material */
		TextureMaterial* m_material;
		Program* m_program;
};

NS_FS_END

#endif /*_FS_LABLE_TTF_H_*/















