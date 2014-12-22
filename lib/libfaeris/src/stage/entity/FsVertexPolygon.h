#ifndef _FS_VERTEX_POLYGON_H_
#define _FS_VERTEX_POLYGON_H_ 


#include <vector>
#include "FsMacros.h"
#include "FsEnums.h"

#include "stage/entity/FsEntity2D.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/FsColor.h"


#include "math/FsVector2.h"
#include "math/FsVector3.h"


NS_FS_BEGIN



class VertexPolygon :public Entity2D
{
	public:
		FS_CLASS_DECLARE(VertexPolygon);

	public:
		static VertexPolygon* create();

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

		void setMode(E_DrawMode mode);
		E_DrawMode getMode();



	public:
		virtual void draw(RenderDevice* r,bool update_matrix);

	protected:
		VertexPolygon();
		virtual ~VertexPolygon();
		bool init();
		void destruct();

	private:
		E_DrawMode m_mode;
		std::vector<Vector3> m_vertics;
};

NS_FS_END

#endif /*_FS_VERTEX_POLYGON_H_*/















