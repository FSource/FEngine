/*************************************************************************/
/*  FsLayer2D.h                                                          */
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


#ifndef _FS_LAYER_2D_
#define _FS_LAYER_2D_

#include <vector>

#include "FsMacros.h"
#include "stage/layer/FsLayer.h"
#include "math/FsMatrix4.h"
#include "math/FsVector2.h"
#include "math/FsRect2D.h"


NS_FS_BEGIN
class FsArray;
class Entity2D;

class Layer2D:public Layer
{
	public:
		FS_CLASS_DECLARE(Layer2D);

	public:
		enum 
		{
			SORT_NONE,
			SORT_ORDER_Z,
			SORT_Y,
		};
	public:
		static Layer2D* create();

	public:
		void setViewArea(const Rect2D& area);

		void setViewAreaX(float x);
		float getViewAreaX();

		void setViewAreaY(float y);
		float getViewAreaY();

		void setViewAreaWidth(float w);
		float getViewAreaWidth();

		void setViewAreaHeight(float h);
		float getViewAreaHeight();

		Rect2D getViewArea() const;

		void setViewArea(float x,float y,float width,float height);
		void getViewArea(float* x,float* y,float* width,float* height);

		void setSortMode(int mode);
		int getSortMode();

		/* eliminate */
		void setEliminate(bool eliminate);
		bool getEliminate();

	public:

		void add(Entity* entity) FS_OVERRIDE;
		void remove(Entity* entity) FS_OVERRIDE;
		void clearEntity() FS_OVERRIDE;


		/* entity */
		void addEntity2D(Entity2D* entity);
		void removeEntity2D(Entity2D* entity);

		int getEntityNu();

		void traverseEntity(std::function<void(Entity2D*)> fn);


	public:
		void update(float dt) FS_OVERRIDE;
		void draw(RenderDevice *r) FS_OVERRIDE;
		Matrix4 getProjectMatrix() FS_OVERRIDE;
		Vector3 toLayerCoord(const Vector3& v) FS_OVERRIDE;

		void toLayerCoord(float* x,float* y);



		/* touch event */
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;

		/* touches event */
		bool touchesBegin(TouchEvent* event) FS_OVERRIDE;
		bool touchesPointerDown(TouchEvent* event) FS_OVERRIDE;
		bool touchesMove(TouchEvent* event) FS_OVERRIDE;
		bool touchesPointerUp(TouchEvent* event) FS_OVERRIDE;
		bool touchesEnd(TouchEvent* event) FS_OVERRIDE;

	protected:
		void getEntityInView(std::vector<Entity2D*>* entitys);
		void sortEntity(std::vector<Entity2D*>* entitys);
		void updateAllWorldMatrix();
		void updateEntity(float dt);
		void getTouchEnabledEntity(std::vector<Entity2D*>*);

		Layer2D();
		virtual ~Layer2D();

	protected:

		Rect2D m_viewArea;
		int m_sortMode;
		bool m_eliminate;

		FsSlowDict* m_entity;  /* direct add to layer */
		Entity2D* m_touchFocus;
		uint32_t m_addOlder;

};


NS_FS_END





#endif 
