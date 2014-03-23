#ifndef _FS_TEXTURE_MGR_H_
#define _FS_TEXTURE_MGR_H_

#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN
class Texture2D;
class TextureMgr:public ResourceMgr 
{
	public:
		static TextureMgr* create();

	public:
		virtual Resource* load(const char* name);
		Texture2D* loadTexture(const char* name);

	public:
		/* inherit FsObject */
		virtual const char* className();

	protected:
		TextureMgr();
		virtual ~TextureMgr();

};


NS_FS_END


#endif /*_FS_TEXTURE_MGR_H_*/

