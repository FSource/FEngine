/*************************************************************************/
/*  FsEntity2D.h                                                         */
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

		/* block event */
		void setBlockTouchEnabled(bool enabled);
		bool getBlockTouchEnabled();
		void setBlockTouchesEnabled(bool enabled);
		bool getBlockTouchesEnabled();



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

		virtual void setSize(const Vector2f& v);
		virtual Vector2f getSize();

		virtual void setAnchor(const Vector2f& v);
		virtual Vector2f getAnchor();

		virtual bool hit2D(float x,float y);

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

		void getBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);
		void getTRSBoundSize2D(float* minx,float* maxx,float* miny,float* maxy);


	public:
		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;


	public:
		std::function<bool(Entity2D*,float,float)> onTouchBegin;
		std::function<bool(Entity2D*,float,float)> onTouchMove;
		std::function<bool(Entity2D*,float,float)> onTouchEnd;
		std::function<bool(Entity2D*,float,float)> onHit2D;

	protected:
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
				ulong m_blockTouchEnabled:1;
				ulong m_blockTouchesEnabled:1;
			};

			ulong m_touchFlags;
		};
		Entity2D* m_touchFocus;
};





NS_FS_END 

#endif /*_FS_ENTITY2D_H_*/


