#ifndef _FS_COLOR_QUAD_2D_H_
#define _FS_COLOR_QUAD_2D_H_

#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

/* points
 *   D ------ C
 *   |        |
 *   |        |
 *   A ------ B
 */

class ColorMaterial;
class Program;

class ColorQuad2D:public Entity
{
	public:
		enum 
		{
			VERTEX_A=0x1,
			VERTEX_B=0x2,
			VERTEX_C=0x4,
			VERTEX_D=0x8,
			VERTEX_ALL=VERTEX_A|VERTEX_B|VERTEX_C|VERTEX_D,
		};

	public:
		static ColorQuad2D* create();
		static ColorQuad2D* create(const Rect2D& rect,Color4f c);
		static ColorQuad2D* create(float width,float height,Color4f c);

	public:
		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(Render* render,bool updateMatrix=true);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className()const;


	public:

		/* material */
		void setColor(Color4f c){m_material->setColor(c);}
		Color4f getColor(){return m_material->getColor();}

		void setOpacity(float opacity){m_material->setOpacity(opacity);}
		float getOpacity(){return m_material->getOpacity();}

		void setBlend(int eq,int src,int dst){m_material->setBlend(eq,src,dst);}
		void setBlend(int src,int dst){m_material->setBlend(src,dst);}

		ColorMaterial* getMaterial(){return m_material;}
		void setMaterial(ColorMaterial* mat){FS_SAFE_ASSIGN(m_material,mat);}

		Program* getShader(){return m_program;}
		void setShader(Program* shader){FS_SAFE_ASSIGN(m_program,shader);}


	public:
		/* --- */

		void setVertexColor(Color4f,int vertex=VERTEX_ALL);


		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();


		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		void setSize(float w,float h);
		void getSize(float* w,float* h);


	protected:
		ColorQuad2D();
		~ColorQuad2D();
		void init(const Rect2D& rect,Color4f c);
		void init(float width,float height,Color4f c);
		void init();
		void destroy();

	private:
		Color4f m_colors[4];
		float m_anchorX,m_anchorY;
		float m_width,m_height;

		ColorMaterial* m_material;
		Program* m_program;
};

NS_FS_END

#endif /*_FS_COLOR_QUAD_2D_H_*/



