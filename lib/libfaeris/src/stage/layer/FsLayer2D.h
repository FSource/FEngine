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
class Entity;

class Layer2D:public Layer
{
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
		/* entity */
		virtual void add(Entity* entity);
		virtual void remove(Entity* entity);

		void clearEntity();
		int getEntityNu();


	public:
		/* inherit  Layer */
		virtual void update(float dt);
		virtual void draw(RenderDevice *r);
		virtual Matrix4 getProjectMatrix();
		virtual Vector3 toLayerCoord(const Vector3& v);

		void toLayerCoord(float* x,float* y);

		/* inherit FsObject */
		virtual const char* className();


		/* touch event */
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* touches event */
		virtual bool touchesBegin(TouchEvent* event);
		virtual bool touchesPointerDown(TouchEvent* event);
		virtual bool touchesMove(TouchEvent* event);
		virtual bool touchesPointerUp(TouchEvent* event);
		virtual bool touchesEnd(TouchEvent* event);

	protected:
		void getEntityInView(std::vector<Entity*>* entitys);
		void sortEntity(std::vector<Entity*>* entitys);
		void updateAllWorldMatrix();
		void updateEntity(float dt);
		void getTouchEnabledEntity(std::vector<Entity*>*);

		Layer2D();
		virtual ~Layer2D();

	protected:

		Rect2D m_viewArea;
		int m_sortMode;
		bool m_eliminate;

		FsSlowDict* m_entity;  /* direct add to layer */
		Entity* m_touchFocus;
		uint32_t m_addOlder;

};


NS_FS_END





#endif 
