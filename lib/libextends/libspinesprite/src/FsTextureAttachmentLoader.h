#ifndef _FS_TEXTURE_ATTACHMENT_LOADER_H_
#define _FS_TEXTURE_ATTACHMENT_LOADER_H_

#include "spine/spine.h"
#include "FsMacros.h"

NS_FS_BEGIN
typedef struct{
	AttachmentLoader super;                                 
} TextureAttachmentLoader;                                 

TextureAttachmentLoader* TextureAttachmentLoader_Create();


NS_FS_END 


#endif /*_FS_TEXTURE_ATTACHMENT_LOADER_H_*/


