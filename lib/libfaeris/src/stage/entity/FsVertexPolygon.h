#ifndef _FS_VERTEX_POLYGON_H_
#define _FS_VERTEX_POLYGON_H_ 


#include <vector>
#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/FsColor.h"

#include "math/FsVector2.h"
#include "math/FsVector3.h"


#include "graphics/material/FsColorMaterial.h"
#include "graphics/FsProgram.h"
NS_FS_BEGIN

class ColorMaterial;
class Program;


class VertexPolygon :public Entity
{
	public:
		static VertexPolygon* create();

	public:
		enum 
		{
			POINTS=RenderDevice::POINTS,
			LINES=RenderDevice::LINES,
			LINE_STRIP=RenderDevice::LINE_STRIP,
			LINE_LOOP=RenderDevice::LINE_LOOP,
			TRIANGLES=RenderDevice::TRIANGLES,
			TRIANGLE_FAN=RenderDevice::TRIANGLE_FAN,
			TRIANGLE_STRIP=RenderDevice::TRIANGLE_STRIP,
		};

	public:

		/* material */
		void setColor(Color4f c){m_material->setColor(c);}
		Color4f getColor(){return m_material->getColor();}

		void setOpacity(float opacity){m_material->setOpacity(opacity);}
		float getOpacity(){return m_material->getOpacity();}

		void setBlend(int eq,int src,int dst){m_material->setBlend(eq,src,dst);}
		void setBlend(int src,int dst){m_material->setBlend(src,dst);}

		void setPointSize(float size){m_material->setPointSize(size);}
		float getPointSize(){return m_material->getPointSize();}

		ColorMaterial* getMaterial(){return m_material;}
		void setMaterial(ColorMaterial* mat){FS_SAFE_ASSIGN(m_material,mat);}

		Program* getShader(){return m_program;}
		void setShader(Program* shader){FS_SAFE_ASSIGN(m_program,shader);}

	public:
		void setVertex(uint index,Vector3 v);
		void setVertex(uint index,Vector2 v);
		void setVertex(uint index,float x,float y,float z=0);


		Vector3 getVertex(uint index);

		void append(Vector3 v);
		void append(Vector2 v);
		void append(float x,float y,float z=0);

		void removeVertex(uint index);

		void insertVertex(uint index,Vector3 v );
		void insertVertex(uint index,Vector2 v );
		void insertVertex(uint index,float x,float y,float z=0);



		void resize(int nu);
		int getVertexNu();

		void setMode(int mode);
		int getMode();



	public:
		virtual const char* className();
		virtual void draw(RenderDevice* r,bool update_matrix);

	protected:
		VertexPolygon();
		virtual ~VertexPolygon();
		bool init();
		void destruct();

	private:
		int m_mode;
		std::vector<Vector3> m_vertics;
		ColorMaterial* m_material;
		Program* m_program;
};

NS_FS_END

#endif /*_FS_VERTEX_POLYGON_H_*/















