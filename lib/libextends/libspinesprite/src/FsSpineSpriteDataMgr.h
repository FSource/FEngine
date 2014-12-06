#ifndef _FS_SPINE_SPRITE_DATA_MGR_H_
#define _FS_SPINE_SPRITE_DATA_MGR_H_ 
#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"
#include "FsSpineSpriteData.h"

NS_FS_BEGIN

class SpineSpriteDataMgr: public ResourceMgr 
{
	public:
		static SpineSpriteDataMgr* sharedMgr();
		static void purgeMgr();

	public:
		SpineSpriteData* loadSpineSpriteData(const char* filename);

	public:
		virtual const char* className();

	protected:
		SpineSpriteDataMgr();
		virtual ~SpineSpriteDataMgr();

};



NS_FS_END
#endif /*_FS_SPINE_SPRITE_DATA_MGR_H_*/


