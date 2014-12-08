#ifndef _FS_IMAGE_JPEG_H_
#define _FS_IMAGE_JPEG_H_

#include "FsMacros.h"
#include "graphics/FsImage2D.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN

FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_JpegReader(const char* filename);
FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_JpegReader(FsFile* file);

int FsUtil_PngWriter(FsFile* file,Image2D* image);
bool FsUtil_CheckJpeg(FsFile* file);

NS_FS_END

#endif /*_FS_IMAGE_JPEG_H_*/
