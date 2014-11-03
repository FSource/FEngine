#ifndef _FAERIS_IMAGE_DECODER_H_
#define _FAERIS_IMAGE_DECODER_H_
#include "FsMacros.h"
#include "graphics/FsImage2D.h"

NS_FS_BEGIN

class FsFile;

E_ImageType FsUtil_ImageTypeWithName(const char* name);
E_ImageType FsUtil_ImageType(FsFile* file);



FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_ImageReader(const char* filename,E_ImageType type);
FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_ImageReader(FsFile* file,E_ImageType type);


NS_FS_END

#endif /*_FAERIS_PICTURE_DECODER_H_*/


