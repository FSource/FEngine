#ifndef _FS_SPRITE_2D_DATA_MGR_H_
#define _FS_SPRITE_2D_DATA_MGR_H_
#include "FsMacros.h"
#include "FsResourceMgr.h"

NS_FS_BEGIN
class Sprite2DData;

class Sprite2DDataMgr:public ResourceMgr
{
	public:
		static Sprite2DDataMgr* create();

	public:
		Sprite2DData* loadSprite2DData(const char* name);

	public:
		virtual const char* className();

	protected:
		Sprite2DDataMgr();
		virtual ~Sprite2DDataMgr();
};



NS_FS_END


#endif /*_FS_SPRITE_2D_DATA_MGR_H_*/

