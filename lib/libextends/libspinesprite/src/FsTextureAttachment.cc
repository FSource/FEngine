#include <string>
#include "spine/spine.h"
#include "spine/extension.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"
#include "FsTextureAttachment.h"

NS_FS_BEGIN

static void _TextureAttachment_Deinit(Attachment* att)
{
	TextureAttachment* self=SUB_CAST(TextureAttachment,att);
	FS_SAFE_DEC_REF(self->texture);
	_Attachment_deinit(att);
}

TextureAttachment* TextureAttachment_Create(const char* filename)
{
	TextureAttachment* self=NEW(TextureAttachment);
	std::string rel_name=std::string(filename)+std::string(".png");

	Texture2D* texture=Global::textureMgr()->loadTexture(rel_name.c_str());
	if(texture==NULL)
	{
		FS_TRACE_WARN("Can't Load Texture(%s) For Spine Skeleton",filename);
	}
	self->texture=texture;

	_Attachment_init((Attachment*)self,filename,ATTACHMENT_REGION,_TextureAttachment_Deinit);
	return self;
}


NS_FS_END 


