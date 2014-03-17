#ifndef _FAERIS_IMAGE_DECODER_H_
#define _FAERIS_IMAGE_DECODER_H_
#include "FsMacros.h"
#include "graphics/FsImage2D.h"

NS_FS_BEGIN

class FsFile;

Image2D::ImageType FsUtil_ImageTypeWithName(const char* name);
Image2D::ImageType FsUtil_ImageType(FsFile* file);



FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_ImageReader(const char* filename,Image2D::ImageType type);
FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_ImageReader(FsFile* file,Image2D::ImageType type);


NS_FS_END

#endif /*_FAERIS_PICTURE_DECODER_H_*/


