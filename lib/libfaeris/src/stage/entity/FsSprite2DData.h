/*************************************************************************/
/*  FsSprite2DData.h                                                     */
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


#ifndef _FS_SPRITE_2D_DATA_H_
#define _FS_SPRITE_2D_DATA_H_
#include <vector>

#include "FsMacros.h"
#include "mgr/FsResource.h"
#include "FsObject.h"
#include "math/FsRect2D.h"


NS_FS_BEGIN
class FsArray;
class FsDict;
class FsFile;
class Texture2D;

class Sprite2DQuad
{
	public:
		int texture;
		float vertex[2*4];
		float texcoord[2*4];
		float alpha[1*4];
};

class Sprite2DKeyFrame 
{
	public:
		/* quad */
		void addQuad(Sprite2DQuad* quad);
		Sprite2DQuad* getQuad(int i);
		int getQuadNu();

		/* bound box */
		void setBoundingBox(const Rect2D& rect);
		Rect2D getBoundingBox();
	public:
		Sprite2DKeyFrame();
		~Sprite2DKeyFrame();

	private:
		Rect2D m_boundingBox;
		std::vector<Sprite2DQuad*> m_quads;
};


class Sprite2DAnimation:public FsObject 
{
	public:
		static Sprite2DAnimation* create();
	public:
		/* key frame */
		void addKeyFrame(Sprite2DKeyFrame* frame);
		Sprite2DKeyFrame* getKeyFrame(int i);
		int getKeyFrameNu();

		/* fps */
		void setFps(int fps);
		int getFps();

		/* name */
		void setName(FsString* name);
		FsString* getName();

		/* inherite FsObject */
		virtual const char* className();

	protected:
		Sprite2DAnimation();
		~Sprite2DAnimation();
		
	private:
		std::vector<Sprite2DKeyFrame*> m_keys;
		int m_fps;
		FsString* m_name;
};

class Sprite2DData:public Resource 
{
	public:
		static Sprite2DData* create(FsFile* file);

	public:
		/* animation */
		void addAnimation(Sprite2DAnimation* animation);
		Sprite2DAnimation*  getAnimation(const char* name);
		int getAnimationNu();

		/* texture */
		FsArray* getTextures();
		Texture2D* getTexture(int i);
		

		/* inherite FsObject */
		virtual const char* className();

	protected:
		Sprite2DData();
		~Sprite2DData();
		bool init(FsFile* file);

		bool loadTextures(FsArray* array);
		bool loadAnimations(FsArray* dict);

		Sprite2DAnimation* createAnimation(FsDict* dict);
		Sprite2DKeyFrame* createKeyFrame(FsArray* frame);
	private:
		FsDict* m_animations;
		FsArray* m_textures;
		FsString* m_name;
};


NS_FS_END 




#endif /*_FS_SPRITE_2D_DATA_H_*/











