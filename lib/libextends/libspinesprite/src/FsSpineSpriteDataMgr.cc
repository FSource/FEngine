#include "FsSpineSpriteDataMgr.h"

NS_FS_BEGIN
static SpineSpriteDataMgr* _shareSpingMgr=NULL;


const char* SpineSpriteDataMgr::className()
{
	return "SpineSpriteDataMgr";
}

SpineSpriteDataMgr* SpineSpriteDataMgr::sharedMgr()
{
	if(_shareSpingMgr==NULL)
	{
		_shareSpingMgr=new SpineSpriteDataMgr;
	}
	return _shareSpingMgr;
}

void SpineSpriteDataMgr::purgeMgr()
{
	if(_shareSpingMgr)
	{
		delete _shareSpingMgr;
		_shareSpingMgr=NULL;
	}
}


SpineSpriteData* SpineSpriteDataMgr::loadSpineSpriteData(const char* filename)
{
	return (SpineSpriteData*)load(filename);
}


SpineSpriteDataMgr::SpineSpriteDataMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc)SpineSpriteData::create)
{
}

SpineSpriteDataMgr::~SpineSpriteDataMgr()
{
}







NS_FS_END 

