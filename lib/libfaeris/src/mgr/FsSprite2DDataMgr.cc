#include "mgr/FsSprite2DDataMgr.h"
#include "stage/entity/FsSprite2DData.h"


NS_FS_BEGIN 

Sprite2DDataMgr* Sprite2DDataMgr::create()
{
	return new Sprite2DDataMgr();
}

Sprite2DData* Sprite2DDataMgr::loadSprite2DData(const char* name)
{
	return (Sprite2DData*) load(name);
}


const char* Sprite2DDataMgr::className()
{
	return FS_SPRITE_2D_DATA_MGR_CLASS_NAME;
}


Sprite2DDataMgr::Sprite2DDataMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc) Sprite2DData::create)
{
}


Sprite2DDataMgr::~Sprite2DDataMgr()
{
}

NS_FS_END 



