#include "FsTextureAttachmentLoader.h"
#include "FsTextureAttachment.h"
#include "spine/spine.h"
#include "spine/extension.h"

NS_FS_BEGIN 
static Attachment* _TextureAttachmentLoader_NewAttachemnt(AttachmentLoader* self,Skin* skin,AttachmentType type, const char* name)
{
	switch(type)
	{
		case ATTACHMENT_REGION:
			{
				return (Attachment*)TextureAttachment_Create(name);
			}
		default:
			{
				FS_TRACE_WARN("Load Texture(%s) For Spine Skeleton Failed",name);
				_AttachmentLoader_setUnknownTypeError(self,type);
			}
			return 0;
	}
	return 0;
}





TextureAttachmentLoader* TextureAttachmentLoader_Create()
{
	TextureAttachmentLoader* self=NEW(TextureAttachmentLoader);
	_AttachmentLoader_init(SUPER(self),_AttachmentLoader_deinit,_TextureAttachmentLoader_NewAttachemnt);
	return self;
}

NS_FS_END 

