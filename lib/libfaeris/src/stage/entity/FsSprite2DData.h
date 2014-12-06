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











