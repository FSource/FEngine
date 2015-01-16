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
		void add(Entity2D* entity);
		void remove(Entity2D* entity);

		int getEntityNu();


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
