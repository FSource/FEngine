#ifndef _FS_LABEL_BITMAP_H_
#define _FS_LABEL_BITMAP_H_


#include <string>
#include <set>
#include <vector>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "math/FsVertices.h"
#include "math/FsFace3.h"

#include "graphics/material/FsMaterial2D.h"
#include "graphics/shader/FsProgram.h"
#include "stage/entity/FsIMaterial2DEntity.h"


NS_FS_BEGIN
class FontBitmap;
class Texture2D;
class Material2D;
class Program;

class LabelBitmap:public Entity ,public IMaterial2DEntity
{
	public:
		enum{ 
			ALIGN_V_TOP,
			ALIGN_V_CENTER,
			ALIGN_V_BOTTOM,
			ALIGN_V_USER_DEFINE,

			ALIGN_H_LEFT,
			ALIGN_H_RIGHT,
			ALIGN_H_CENTER,
			ALIGN_H_USER_DEFINE,
		};
		enum{
			TEXT_ALIGN_LEFT,
			TEXT_ALIGN_CENTER,
			TEXT_ALIGN_RIGHT,
		};

	public:
		static LabelBitmap* create(const char* text,FontBitmap* font);
		static LabelBitmap* create(FontBitmap* font);



	public:
		int setString(const char* utf8_str);
		int setString(const char* utf8_str,int start);
		int setString(const char* utf8_str,int start,int num);

		const char* getString();


		void setAlign(int alignh,int alignv);
		void setAlignOffset(float x,float y);

		void getAlign(int* alignh,int* alignv);
		void getAlignOffset(float* x,float* y);


		float getWidth();
		float getHeight();

		/* NOTE: setTextAlign and setBounds will not take effect 
		 * immediately,it will change at next setString called 
		 */
		void setTextAlign(int mode);
		void setBounds(float x,float y);

		int getTextAlign();
		void getBounds(float* x,float* y);

	public:
		/* override Entity */
		virtual void draw(RenderDevice* r,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* override FsObject */
		virtual const char* className();



	protected:
		LabelBitmap();
		virtual ~LabelBitmap();
		bool init(FontBitmap* font);
		void destruct();

		int setString(uint16_t* utf16_str,int len);

		void calRelOffset();
		void clear();
		void generateIndices();


	private:
		int m_alignh,m_alignv;
		float m_offsetx,m_offsety;
		int m_textAlign;

		float m_boundx,m_boundy;

		FontBitmap* m_font;
		Texture2D* m_texture;

		/* user setting */
		uint8_t* m_utf8str;


		/* auto generate */
		float m_width,m_height;
		float m_relOffsetx,m_relOffsety;

		std::vector<Fs_V2F_T2F> m_vertices;
		std::vector<Face3> m_indics;

};


NS_FS_END 


#endif /*_FS_LABEL_BITMAP_H_*/




























