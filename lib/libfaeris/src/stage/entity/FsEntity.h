#ifndef _FAERIS_ENTITY_H_
#define _FAERIS_ENTITY_H_
#include <functional>


#include "FsMacros.h"
#include "stage/FsActionTarget.h"
#include "math/FsVector3.h"
#include "math/FsMatrix4.h"
#include "transform/FsITransform.h"
#include "math/FsRect2D.h"
#include "support/util/FsString.h"
#include "support/util/FsSlowArray.h"

NS_FS_BEGIN
class RenderDevice;
class Layer;
class Scene;
class Entity :public ActionTarget
{
	public:
		Entity* create();

	public:
		/* inherit FsObject */
		virtual const char* className();


		virtual void update(float dt);
		virtual void draw(RenderDevice* r,bool updateMatrix=true);

		virtual void updates(float dt);
		virtual void draws(RenderDevice* r,bool updateMatrix=true);

		/* single touch */
		void setTouchEnabled(bool enabled);
		bool getTouchEnabled();

		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* multi touches */
		void setTouchesEnabled(bool enabled);
		bool getTouchesEnabled();

		/* TODO:(implement) 
		bool touchesBegin(float x,float y,int id);
		bool touchesPointerDown(float x,float y,int id);
		bool touchesPointerMove(float x,float y,int id);
		bool touchesPointerUp(float x,float y,int id);
		bool touchesEnd(float x,float y,int id);
		*/

		virtual void detach();

	public:
		std::function<void(Entity*,float)> onUpdate;
		std::function<void(Entity*,RenderDevice*,bool)> onDraw;

		std::function<bool(Entity*,float,float)> onTouchBegin;
		std::function<bool(Entity*,float,float)> onTouchMove;
		std::function<bool(Entity*,float,float)> onTouchEnd;


	public:

		Vector3 localToWorld(const Vector3& v);
		Vector3 worldToLocal(const Vector3& v);

		/* relation ship*/
		void addChild(Entity* n);
		void remove(Entity* n);
		void clearChild();


		FS_FEATURE_NEW_OBJECT(FsArray*) takeAllChild(bool visible);
		void getAllChild(FsArray* array,bool visible);
		int childNu();



		Matrix4* getWorldMatrix();
		Matrix4* getLocalMatrix();

		bool updateWorldMatrix();
		void updateAllWorldMatrix();
		void setChildWorldMatrixDirty();

	public: /* zorlder */
		float getZorder();
		void setZorder(float z);
		Layer* getLayer();

		/* please don't call setLayer directly */
		void setLayer(Layer* layer);
		
		Entity* getParent();
		Scene* getScene();


		/* used for layer to sort */
		uint32_t getAddOlder(){return m_addOlder;}
		void  setAddOlder(uint32_t older){ m_addOlder=older;}


	public: /* get transform info */
		Vector3 getPosition();
		void getPosition(float* x,float* y,float* z);
		float getPositionX();
		float getPositionY();
		float getPositionZ();

		/* scale information */
		Vector3 getScale();
		float getScaleX();
		float getScaleY();
		float getScaleZ();


		/* rotate information */
		Vector3 getRotate();
		float getRotateX();
		float getRotateY();
		float getRotateZ();

	public: /* transform */
		void rotate(float rx,float ry,float rz);
		void rotateX(float r);
		void rotateY(float r);
		void rotateZ(float r);

		void scale(float sx,float sy,float sz);
		void scaleX(float s);
		void scaleY(float s);
		void scaleZ(float s);

		void move(float tx,float ty,float tz);
		void moveX(float t);
		void moveY(float t);
		void moveZ(float t);

	public:/* set transform */
		void setRotate(const Vector3& r);
		void setRotate(float rx,float ry,float rz);
		void setRotateX(float r);
		void setRotateY(float r);
		void setRotateZ(float r);

		void setScale(const Vector3& s);
		void setScale(float sx,float sy,float sz);
		void setScaleX(float s);
		void setScaleY(float s);
		void setScaleZ(float s);

		void setPosition(float tx,float ty,float tz = 0.0f);
		void setPosition(const Vector3& pos);
		void setPositionX(float t);
		void setPositionY(float t);
		void setPositionZ(float t);

	public: /* world transform */
		void setPositionInWorld(float tx,float ty,float tz);
		void setPositionInWorld(const Vector3& v);

		Vector3 getPositionInWorld();
		void getPositionInWorld(float* x,float* y,float* z);

		void setTransform(ITransform* tf);
		ITransform* getTransform();


	public:
		void setVisible(bool visible){m_visible=visible;}
		bool getVisible(){return m_visible&&m_visibles;}

		void setVisibles(bool visible){m_visibles=visible;}
		bool getVisibles(){return m_visibles;}

		void setChildVisible(bool visiable,bool rec);

		/* for hiting */
		virtual bool hit2D(float x,float y);


	public:


		void setDispatchTouchEnabled(bool enabled);
		bool getDispatchTouchEnabled();
		void setDispatchTouchesEnabled(bool enabled);
		bool getDispatchTouchesEnabled();



	


	protected:
		Entity();
		virtual ~Entity();

		void init();
		void destruct();
		void updateChildWorldMatrix(bool force);
	
		void setParent(Entity* parent);


		void sortChildren();


	protected:  
		/* flags */
		union 
		{
			struct{
				ulong m_localMatrixDirty:1;
				ulong m_worldMatrixDirty:1;
				ulong m_hasBoundSphere:1;
				ulong m_hasBoundSphere2D:1;
				ulong m_hasBoundBox:1;
				ulong m_hasBoundBox2D:1;
				ulong m_visible:1;
				ulong m_visibles:1;
				ulong m_zorderDirty:1;
				ulong m_touchEnabled:1;
				ulong m_touchesEnabled:1;
				ulong m_dispatchTouchEnabled:1;
				ulong m_dispatchTouchesEnabled:1;
			};
			ulong m_flags;
		};


		/* matrix */
		Matrix4 m_worldMatrix;
		ITransform* m_transform;


		/* zorlder */
		float m_zorlder;
		uint32_t m_addOlder;


		/* relation ship*/
		Layer* m_layer;
		Entity* m_parent;
		FsSlowArray* m_chirdren;
		Entity* m_touchFocus;


		/* bound box */
		Rect2D m_boundBox2D;

		friend class Layer;

	/* class attribute */
	private:
		static uint32_t ms_olderCount;
};

#include "stage/entity/FsEntity.inl"
NS_FS_END

#endif 




