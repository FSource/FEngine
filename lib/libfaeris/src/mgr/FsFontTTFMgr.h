#ifndef _FS_FONT_TTF_DATA_MGR_H_
#define _FS_FONT_TTF_DATA_MGR_H_

#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN
class FontTTF;
class FontTTFMgr:public ResourceMgr
{
	public:
		static FontTTFMgr* create();

	public:
		FontTTF* loadFontTTF(const char* name);

	public:
		virtual const char* className();

	protected:
		FontTTFMgr();
		virtual ~FontTTFMgr();

};


NS_FS_END


#endif /*_FS_FONT_TTF_DATA_MGR_H_*/

