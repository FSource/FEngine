/*************************************************************************/
/*  FsStateButton.h                                                      */
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


#ifndef _FS_STATE_BUTTON_H_
#define _FS_STATE_BUTTON_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "support/util/FsArray.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"
#include "math/easing/FsEaseExpr.h"
#include "math/FsVector3.h"
#include "math/FsVector2.h"

NS_FS_BEGIN

class Program;
class Material2D;
class Texture2D;

class StateButton:public Entity2D
{
	public:
		FS_CLASS_DECLARE(StateButton);

	protected:
		class StateAttr 
		{
			public:
				StateAttr()
				{
					m_color=Color4f::WHITE;
					m_opacity=1.0;
					m_texture=NULL;
					m_textureUrl="";
					m_size.set(0,0);
					m_anchor.set(0.5,0.5);
					m_rotate.set(0,0,0);
					m_scale.set(1,1,1);
					m_children=NULL;
				};


				~StateAttr()
				{
					FS_SAFE_DEC_REF(m_texture);
					FS_SAFE_DEC_REF(m_children);
				}

			public:
				std::string m_textureUrl;
				Texture2D* m_texture;
				Color4f m_color;
				float m_opacity;
				Vector2 m_size;
				Vector2 m_anchor;
				Vector3 m_rotate;
				Vector3 m_scale;
				FsArray* m_children;
		};

		class TweenInfo{
			public:
				TweenInfo()
				{
					m_easing=NULL;
					m_time=0;
				}
				~TweenInfo()
				{
					FS_SAFE_DEC_REF(m_easing);
				}

			public:
				EaseExpr* m_easing;
				float m_time;
		};

	public:

		/* texture */
		void setTextureUrl(const char* filename);
		const char* getTextureUrl();

		void setTexture(Texture2D* tex);
		Texture2D* getTexture() const;


		/* State Attribute Setting */

		/* color */
		void setColor(int state,const Color4f& value);
		Color4f getColor(int state) const ;


		/* opacity */
		void setOpacity(int state,float value);
		float getOpacity(int state) const;


		/* texture */
		void setTextureUrl(int state,const char* filename);
		const char* getTextureUrl(int state);
		void setTexture(int state,Texture2D* tex);
		Texture2D* getTexture(int state) const;


		/* size */
		using Entity2D::setSize;
		using Entity2D::getSize;
		void setSize(int state,float x,float y);
		void setSize(int state,const Vector2& size);
		Vector2 getSize(int state) const;

		using Entity2D::setAnchor;
		using Entity2D::getAnchor;
		void setAnchor(int state,float x,float y);
		void setAnchor(int state,const Vector2& size);
		Vector2 getAnchor(int state)const ;



		/* rotate */
		using Entity2D::setRotate;
		using Entity2D::getRotate;
		void setRotate(int state,float x,float y,float z);
		void setRotate(int state,const Vector3& value);
		Vector3 getRotate(int state)const ;


		/* scale */
		using Entity2D::setScale;
		using Entity2D::getScale;
		void setScale(int state,float x,float y,float z);
		void setScale(int state,const Vector3& value);
		Vector3 getScale(int state)const ;

		/* child */
		void setChild(int state,FsArray* child);
		FsArray* getChild(int state)const;

	public:

		/* inherit Entity */
		void update(float dt) FS_OVERRIDE;
		void draw(RenderDevice* render,bool update_matrix) FS_OVERRIDE;


	public:

		void setTweenFlags(uint32_t flags);
		void clearTweenFlags();

		void setTweenColorEnabled(bool value);
		bool getTweenColorEnabled();

		void setTweenOpacityEnabled(bool value);
		bool getTweenOpacityEnabled();

		void setTweenTextureEnabled(bool value);
		bool getTweenTextureEnabled();

		void setTweenSizeEnabled(bool value);
		bool getTweenSizeEnabled();

		void setTweenAnchorEnabled(bool value);
		bool getTweenAnchorEnabled();

		void setTweenRotateEnabled(bool value);
		bool getTweenRotateEnabled();

		void setTweenScaleEnabled(bool value);
		bool getTweenScaleEnabled();

		void setTweenChildrenEnabled(bool value);
		bool getTweenChildrenEnabled();


		void addTweenFlags(uint32_t flags);
		void removeTweenFlags(uint32_t flags);

		void setTweenInfo(int from,int to,EaseExpr* easing,float time);
		void setLinearTween(float time);

		void setState(int st);
		void stopTween();



	protected:
		StateButton(int state_nu);
		virtual ~StateButton();

		bool init(int state_nu);
		void destruct();

		void updateTween(float dt);
		void markStateDirty();

		void setAttributeWithState(StateAttr* st);
		void setAttributeWithState(StateAttr* from,StateAttr* to,EaseExpr* easing,float percent);
		



	protected:
		int m_stateNu;
		StateAttr* m_states;
		TweenInfo** m_tweenInfo;

		uint32_t m_tweenFlags;
		StateAttr* m_tweenFromState;
		StateAttr* m_tweenToState;

		int m_curState;
		bool m_stateDirty; 

		TweenInfo* m_curTween;
		float m_tweenTime;

		/* Button Attribute */
		Texture2D* m_texture;
		std::string m_textureUrl;

};


void FsStateButton_SetState(StateButton* sb,int state,FsDict* dict);

NS_FS_END 

#endif /*_FS_STATE_BUTTON_H_*/



