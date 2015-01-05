#ifndef _FS_FONT_BITMAP_MGR_H_
#define _FS_FONT_BITMAP_MGR_H_

#include "mgr/FsResourceMgr.h"


NS_FS_BEGIN

class FontBitmap;

class FontBitmapMgr:public ResourceMgr 
{
	public:
		static FontBitmapMgr* create();

	public:
		FontBitmap* loadFontBitmap(const char* name);

	public:
		virtual const char* className();

	protected:
		FontBitmapMgr();
		virtual ~FontBitmapMgr();


};



NS_FS_END 




#endif /*_FS_FONT_BITMAP_MGR_H_*/


