/*************************************************************************/
/*  FsTextureMgr.cc                                                      */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "mgr/FsTextureMgr.h"
#include "graphics/FsTexture2D.h"
#include "support/image/FsImageDecoder.h"

NS_FS_BEGIN

static Resource* textureCreateFunc(FsFile* file)
{
	Image2D* image=FsUtil_ImageReader(file,E_ImageType::UNKOWN);
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
	: ResourceMgr((ResourceMgr::ResourceCreateFunc) textureCreateFunc)
{
}
TextureMgr::~TextureMgr()
{

}

Resource* TextureMgr::load(const char* name)
{
	if(name==NULL)
	{
		return NULL;
	}

	Texture2D* ret=(Texture2D*)ResourceMgr::load(name);
	if(ret)
	{
		ret->setResourceUrl(name);
	}
	else 
	{
		FS_TRACE_WARN("Can't Load Resource Name(%s)",name);

	}
	return ret;
}

Texture2D* TextureMgr::loadTexture(const char* name)
{
	return (Texture2D*) load(name);

}

Texture2D* TextureMgr::loadTexture(FsDict* dict)
{
	FsString* url=dict->lookupString("url");
	if(!url)
	{
		FS_TRACE_WARN("No Url In Dict");
		return NULL;
	}

	Texture2D* tex=loadTexture(url->cstr());
	if(tex)
	{
		tex->setAttributes(dict);
	}
	return tex;
}


NS_FS_END  












