#ifndef _FS_QUAD_2D_H_
#define _FS_QUAD_2D_H_ 

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "math/FsRect2D.h"
#include "graphics/FsColor.h"

#include "graphics/material/FsTextureMaterial.h"
#include "graphics/FsProgram.h"
NS_FS_BEGIN
class Texture2D;

class TextureMaterial;
class Program;

class Quad2D:public Entity 
{
	public:
		static Quad2D* create();
		static Quad2D* create(const char* tex);
		static Quad2D* create(const char* tex,const Rect2D& rect);
		static Quad2D* create(const char* tex,float width,float height);

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

		/* texture */
		void setTexture(const char* tex);
		void setResourceUrl(const char* name);
		void setTexture(Texture2D* tex);
		Texture2D* getTexture();

		/* texture coord */
		void setTextureCoord(const Rect2D& coord);
		Rect2D getTextureCoord();


		/* Rect2D */
		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();


		void setWidth(float width);
		void setHeight(float height);
		void setSize(float width,float height);
		float getWidth();
		float getHeight();
		void getSize(float* width,float* height);
			
		void setAnchorX(float x);
		void setAnchorY(float y);
		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		float getAnchorX();
		float getAnchorY();

	public:
		/* inherit Entity */
		virtual void draw(Render* r,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();


	protected:
		Quad2D();
		~Quad2D();
		bool init();
		bool init(const char* tex);
		bool init(Texture2D* tex);
		void destruct();

	private:
		float m_width,m_height;
		float m_anchorX,m_anchorY;

		Rect2D m_textureCoord;
		Texture2D* m_texture;

		TextureMaterial* m_material;
		Program* m_program;
};

NS_FS_END 



#endif /*_FS_QUAD_2D_H_*/

