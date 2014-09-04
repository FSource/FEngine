#include <string.h>

#include "support/image/FsImageDecoder.h"
#include "support/image/FsImagePng.h"
#include "support/image/FsImageJpeg.h"

#include "graphics/FsImage2D.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN
Image2D::ImageType FsUtil_ImageTypeWithName(const char* name)
{
	uint str_len=strlen(name);
	if(str_len<=5)  /*  *.jpg, *.png, *.bmp *.tga */
	{
		return Image2D::IMAGE_UNKWON;
	}

	const char* ext=name+str_len-4;
	if(strcmp(ext,".jpg")==0)
	{
		return Image2D::IMAGE_JEPG;
	}
	else if(strcmp(ext,".png")==0)
	{
		return Image2D::IMAGE_PNG;
	}
	else if(strcmp(ext,".bmp")==0)
	{
		return Image2D::IMAGE_BMP;
	}
	else if(strcmp(ext,".tga")==0)
	{
		return Image2D::IMAGE_TGA;
	}

	if(str_len<=6)   /* *.jpeg */
	{
		return Image2D::IMAGE_UNKWON;
	}

	ext=name+str_len-5;
	if(strcmp(ext,".jpeg")==0)
	{
		return Image2D::IMAGE_JEPG;
	}

	return Image2D::IMAGE_UNKWON;
}

Image2D::ImageType FsUtil_ImageType(FsFile* file)
{
	if(FsUtil_CheckPng(file))
	{
		return Image2D::IMAGE_PNG;
	}
	if(FsUtil_CheckJpeg(file))
	{
		return Image2D::IMAGE_JEPG;
	}
	return Image2D::IMAGE_UNKWON;
}



Image2D* FsUtil_ImageReader(FsFile* file,Image2D::ImageType image_type)
{

	if(image_type==Image2D::IMAGE_UNKWON)
	{
		image_type=FsUtil_ImageType(file);
	}

	switch(image_type)
	{
		case Image2D::IMAGE_JEPG:
			return FsUtil_JpegReader(file);
		case Image2D::IMAGE_PNG:
			return FsUtil_PngReader(file);
		case Image2D::IMAGE_BMP:
			/*TODO add Bitmap Reader hear */
			//	return FsUtil_BmpReader(file);
			return NULL;
		default:
			FS_TRACE_WARN("Image Type Is Not Support");
			return NULL;
	}
	return NULL;
}

Image2D* FsUtil_ImageReader(const char* filename,Image2D::ImageType image_type)
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






