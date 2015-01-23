/*************************************************************************/
/*  FsVertexPolygon.h                                                    */
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















