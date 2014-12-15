#include "mgr/FsFontTTFMgr.h"
#include "graphics/FsFontTTF.h"

NS_FS_BEGIN
FontTTFMgr* FontTTFMgr::create()
{
	return  new FontTTFMgr;
}

FontTTF* FontTTFMgr::loadFontTTF(const char* name)
{
	return (FontTTF*)load(name);
}

const char* FontTTFMgr::className()
{
	return FS_FONT_TTF_DATA_MGR_CLASS_NAME;
}

FontTTFMgr::FontTTFMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc)FontTTF::create)
{
}

FontTTFMgr::~FontTTFMgr()
{
}

NS_FS_END



