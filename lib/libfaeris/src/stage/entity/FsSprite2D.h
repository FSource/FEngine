/*************************************************************************/
/*  FsSprite2D.h                                                         */
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


#ifndef _FS_SPRITE_2D_H_
#define _FS_SPRITE_2D_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
#include "graphics/FsColor.h"
#include "graphics/material/FsMaterial2D.h"

NS_FS_BEGIN

class Sprite2DData;
class Texture2D;
class FsArray;
class FsDict;
class Sprite2DAnimation;
class AnimationCacheData;
class Material2D;
class Program;

class Sprite2D :public Entity2D
{
	public:

		static Sprite2D* create();
		static Sprite2D* create(const char* name);

	public:


		void setResourceUrl(const char* name);

		/* animation */
		void setAnimation(const char* name);
		const char* getAnimation();
		void updateAnimation(float dt);

		bool hasAnimation(const char* name);

		void playAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void startAnimation(E_AnimPlayMode mode=E_AnimPlayMode::LOOP);
		void stopAnimation();

		bool isAnimationPlaying();

		void setAnimationOffset(float x,float y);
		void getAnimationOffset(float* x,float* y);


		/* frame */
		void setCurFrame(int frame);
		int getCurFrame();
		int getTotalFrame();

		/* fps */
		int getFps();
		void setFps(int fps);

	public:

		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(RenderDevice* rd,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init();
		bool init(const char* name);
		void setAnimation(Sprite2DAnimation* anim);
		Sprite2D();
		~Sprite2D();

	private:

		int m_curFrame;
		float m_elapseTime;


		E_AnimPlayMode m_mode;
		int m_stop;

		int m_curFps;

		Sprite2DData* m_data;

		Sprite2DAnimation* m_curAnimation;
		AnimationCacheData* m_curAnimationCacheData; /* weak reference */
		FsArray* m_textures;
		FsDict* m_animationCacheData;

};



NS_FS_END


#endif /*_FS_SPRITE_2D_H_*/




