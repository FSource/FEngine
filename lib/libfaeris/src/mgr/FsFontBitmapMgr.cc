#include "FsFontBitmapMgr.h"
#include "graphics/FsFontBitmap.h"

NS_FS_BEGIN

FontBitmapMgr* FontBitmapMgr::create()
{
	return new FontBitmapMgr();
}


FontBitmap* FontBitmapMgr::loadFontBitmap(const char* name)
{
	return (FontBitmap*) load(name);
}

const char* FontBitmapMgr::className()
{
	return "FontBitmapMgr";
}


FontBitmapMgr::FontBitmapMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc)FontBitmap::create)
{
}

FontBitmapMgr::~FontBitmapMgr()
{
}



NS_FS_END 





