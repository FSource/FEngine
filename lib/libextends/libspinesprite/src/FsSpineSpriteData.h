#ifndef _FS_SPINE_SPRITE_DATA_H_
#define _FS_SPINE_SPRITE_DATA_H_
#include "spine/spine.h"
#include "FsMacros.h"
#include "mgr/FsResource.h"



NS_FS_BEGIN
class FsFile;
class SpineSpriteData:public Resource
{
	public:
		static SpineSpriteData* create(FsFile* file);

	public:
		SkeletonData* getSkeletonData()
		{
			return m_data;
		}
	public:
		virtual const char* className();

	protected:
		SpineSpriteData();
		~SpineSpriteData();
		bool init(FsFile* file);
		void destroy();

	private:
		SkeletonData*  m_data;
};


NS_FS_END


#endif /*_FS_SPINE_SPRITE_DATA_H_*/

