#include "mgr/FsTextureMgr.h"
#include "graphics/FsTexture2D.h"
#include "support/image/FsImageDecoder.h"

NS_FS_BEGIN

static Resource* textureCreateFunc(FsFile* file)
{
	Image2D* image=FsUtil_ImageReader(file,Image2D::IMAGE_UNKWON);
	if(image==NULL)
	{
		return NULL;
	}

	Texture2D* tex=Texture2D::create(image);
	image->decRef();
	return tex;
}

TextureMgr* TextureMgr::create()
{
	return new TextureMgr();
}


const char* TextureMgr::className()
{
	return FS_TEXTURE_MGR_CLASS_NAME;
}


TextureMgr::TextureMgr()
	:ResourceMgr(textureCreateFunc)
{
}
TextureMgr::~TextureMgr()
{

}

Resource* TextureMgr::load(const char* name)
{
	Texture2D* ret=(Texture2D*)ResourceMgr::load(name);
	if(ret)
	{
		ret->setResourceUrl(name);
	}
	return ret;
}

Texture2D* TextureMgr::loadTexture(const char* name)
{
	return (Texture2D*) load(name);

}




NS_FS_END  












