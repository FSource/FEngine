/*************************************************************************/
/*  FsTexture2D.cc                                                       */
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


#include "graphics/FsTexture2D.h"
#include "support/util/FsDict.h"
#include "FsClass.h"


#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE)
	#include "platform/FsGLTexture2D.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 




NS_FS_BEGIN

static void Texture2D_setWrap(Texture2D* tex,FsDict* dict)
{
	E_TextureWrap wrap_t=tex->getWrapT();
	E_TextureWrap wrap_s=tex->getWrapS();

	FsString* s_wrap_t=dict->lookupString("t");
	if(s_wrap_t)
	{
		wrap_t=FsEnum_StrToTextureWrap(s_wrap_t->cstr());
	}

	FsString* s_wrap_s=dict->lookupString("s");
	if(s_wrap_s)
	{
		wrap_s=FsEnum_StrToTextureWrap(s_wrap_s->cstr());
	}

	tex->setWrap(wrap_s,wrap_t);
}

static void  Texture2D_setFilter(Texture2D* tex,FsDict* dict)
{
	E_TextureFilter filter_min=tex->getFilterMin();
	E_TextureFilter filter_mag=tex->getFilterMag();
	E_TextureFilter filter_mipmap=tex->getFilterMipmap();

	FsString*  s_filter_min=dict->lookupString("min");
	if(s_filter_min)
	{
		filter_min=FsEnum_StrToTextureFilter(s_filter_min->cstr());
	}

	FsString* s_filter_mag=dict->lookupString("mag");
	if(s_filter_mag)
	{
		filter_mag=FsEnum_StrToTextureFilter("mag");
	}

	FsString* s_filter_mipmap=dict->lookupString("mipmap");
	if(s_filter_mipmap)
	{
		filter_mipmap=FsEnum_StrToTextureFilter(s_filter_mipmap->cstr());
	}
	tex->setFilter(filter_mag,filter_min,filter_mipmap);
}



FS_CLASS_ATTR_SET_GET_FUNCTION(Texture2D,setMipmapEnabled,getMipmapEnalbed,bool);


static FsClass::FsAttributeDeclare S_Texture_MainAttr[]={
	FS_CLASS_ATTR_DECLARE("wrap",FsType::FT_DICT,NULL,Texture2D_setWrap,0),
	FS_CLASS_ATTR_DECLARE("filter",FsType::FT_DICT,NULL,Texture2D_setFilter,0),
	FS_CLASS_ATTR_DECLARE("mipmapEnabled",FsType::FT_B_1,NULL,Texture2D_setMipmapEnabled,Texture2D_getMipmapEnalbed),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Texture2D,FsObject,0,S_Texture_MainAttr);

NS_FS_END 


