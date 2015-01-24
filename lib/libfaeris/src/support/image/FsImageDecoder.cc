/*************************************************************************/
/*  FsImageDecoder.cc                                                    */
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


#include <string.h>

#include "support/image/FsImageDecoder.h"
#include "support/image/FsImagePng.h"
#include "support/image/FsImageJpeg.h"
#include "support/image/FsImageTga.h"

#include "graphics/FsImage2D.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN
E_ImageType FsUtil_ImageTypeWithName(const char* name)
{
	uint str_len=strlen(name);
	if(str_len<5)  /*  *.jpg, *.png, *.bmp *.tga */
	{
		return E_ImageType::UNKOWN;
	}

	const char* ext=name+str_len-4;
	if(strcmp(ext,".jpg")==0)
	{
		return E_ImageType::JPEG;
	}
	else if(strcmp(ext,".png")==0)
	{
		return E_ImageType::PNG;
	}
	else if(strcmp(ext,".bmp")==0)
	{
		return E_ImageType::BMP;
	}
	else if(strcmp(ext,".tga")==0)
	{
		return E_ImageType::TGA;
	}

	if(str_len<6)   /* *.jpeg */
	{
		return E_ImageType::UNKOWN;
	}

	ext=name+str_len-5;
	if(strcmp(ext,".jpeg")==0)
	{
		return E_ImageType::JPEG;
	}

	return E_ImageType::UNKOWN;
}

E_ImageType FsUtil_ImageType(FsFile* file)
{
	if(FsUtil_CheckPng(file))
	{
		return E_ImageType::PNG;
	}

	if(FsUtil_CheckJpeg(file))
	{
		return E_ImageType::JPEG;
	}

	if(FsUtil_CheckTga(file))
	{
		return E_ImageType::TGA;
	}


	return E_ImageType::UNKOWN;
}



Image2D* FsUtil_ImageReader(FsFile* file,E_ImageType image_type)
{

	if(image_type==E_ImageType::UNKOWN)
	{
		image_type=FsUtil_ImageType(file);
	}

	switch(image_type)
	{
		case E_ImageType::JPEG:
			return FsUtil_JpegReader(file);

		case E_ImageType::PNG:
			return FsUtil_PngReader(file);

		case E_ImageType::BMP:
			/*TODO add Bitmap Reader hear */
			//	return FsUtil_BmpReader(file);
			return NULL;

		case E_ImageType::TGA:
			return FsUtil_TgaReader(file);

		default:
			FS_TRACE_WARN("Image Type Is Not Support");
			return NULL;
	}
	return NULL;

}

Image2D* FsUtil_ImageReader(const char* filename,E_ImageType image_type)
{

	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Create Image2D From File(%s)",filename);
		return NULL;
	}
	
	Image2D* ret=FsUtil_ImageReader(file,image_type);
	if(ret==NULL)
	{
		FS_TRACE_WARN("Can't Create Image2D From File(%s)",filename);
	}

	return ret;

}


NS_FS_END






