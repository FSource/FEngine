#ifndef _FS_TEXTURE_ATTACHMENT_H_
#define _FS_TEXTURE_ATTACHMENT_H_ 
#include "spine/spine.h"
#include "FsMacros.h"


NS_FS_BEGIN
class Texture2D;

typedef struct{
	RegionAttachment super;
	Texture2D* texture;
} TextureAttachment;

TextureAttachment* TextureAttachment_Create(const char* filename);


NS_FS_END 



#endif /*_FS_TEXTURE_ATTACHMENT_H_*/

