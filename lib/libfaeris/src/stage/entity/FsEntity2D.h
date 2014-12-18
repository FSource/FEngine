#ifndef _FS_ENTITY_2D_H_
#define _FS_ENTITY_2D_H_

#include "FsMacros.h"
#include "FsEntity.h"
#include "graphics/material/FsMaterial2D.h"

NS_FS_BEGIN

class Entity2D:public Entity  
{
	public:
		FS_CLASS_DECLARE(Entity2D);

	public:
		static Entity2D* create();


	public:  /* Material Part */
		void setMaterial(Material2D* mat);
		Material2D* getMaterial() ;

		/* material */
		void setColor(const Color4f& c);
		Color4f getColor();

		void setOpacity(float opacity);
		float getOpacity();

		void setBlend(E_BlendEquation eq,E_BlendFactor src,E_BlendFactor dst);
		void setBlend(E_BlendFactor src,E_BlendFactor dst);

		void setBlendSrc(E_BlendFactor src);
		E_BlendFactor getBlendSrc();

		void setBlendDst(E_BlendFactor dst);
		E_BlendFactor getBlendDst();

		void setBlendEquation(E_BlendEquation eq);
		E_BlendEquation getBlendEquation();


		void setProgramSource(ProgramSource* ps);
		void setProgramSource(const char* filename);
		ProgramSource* getProgramSource();

	public:
		Program* getProgram(ProgramFeatureDesc* desc);


	public:
		/* single touch */
		void setTouchEnabled(bool enabled);
		bool getTouchEnabled();

		/* multi touches */
		void setTouchesEnabled(bool enabled);
		bool getTouchesEnabled();

		void setDispatchTouchEnabled(bool enabled);
		bool getDispatchTouchEnabled();

		void setDispatchTouchesEnabled(bool enabled);
		bool getDispatchTouchesEnabled();


	public:  /* touch part */
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);


		/* TODO:(implement) 
		bool touchesBegin(float x,float y,int id);
		bool touchesPointerDown(float x,float y,int id);
		bool touchesPointerMove(float x,float y,int id);
		bool touchesPointerUp(float x,float y,int id);
		bool touchesEnd(float x,float y,int id);
		*/

	public:
		virtual void setSize(const Vector2f& v);
		virtual Vector2f getSize();

		virtual void setAnchor(const Vector2f& v);
		virtual Vector2f getAnchor();

		virtual bool hit2D(const Vector2f& v);

	public:
		void setSize(float x,float y);
		void getSize(float* x,float* y);

		void setWidth(float v);
		float getWidth();

		void setHeight(float v);
		float getHeight();

		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		void setAnchorX(float v);
		float getAnchorX();

		void setAnchorY(float v);
		float getAnchorY();

		bool hit2D(float x,float y);


	public:
		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;


	public:
		std::function<bool(Entity2D*,float,float)> onTouchBegin;
		std::function<bool(Entity2D*,float,float)> onTouchMove;
		std::function<bool(Entity2D*,float,float)> onTouchEnd;

	public:
		Entity2D();
		virtual ~Entity2D();

	protected:
		Material2D* m_material;

		Vector2f m_size;
		Vector2f m_anchor;

		union 
		{
			struct{
				ulong m_touchEnabled:1;
				ulong m_touchesEnabled:1;
				ulong m_dispatchTouchEnabled:1;
				ulong m_dispatchTouchesEnabled:1;
			};
			ulong m_touchFlags;
		};
		Entity2D* m_touchFocus;
};





NS_FS_END 

#endif /*_FS_ENTITY2D_H_*/


