#include <stdio.h>

#include "graphics/material/FsTextureMaterial.h"


NS_FS_BEGIN
const char* TextureMaterial::className()
{
	return FS_TEXTURE_MATERIAL_CLASS_NAME;
}


TextureMaterial* TextureMaterial::create()
{
	TextureMaterial* ret=new TextureMaterial;
	return ret;
}


void TextureMaterial::configRender(Render* r)
{
	Material::configRender(r);

	if(m_textureNu==1)
	{
		int texture=0;
		int u_loc=r->getCacheUniformLocation(FS_UNIFORM_TEXTURE0_LOC,FS_UNIFORM_TEXTURE0_NAME);
		r->setUniform(u_loc,Render::U_I_1,1,&texture);
	}
	else 
	{
		for(int i=0;i<m_textureNu;i++)
		{
			char buf[128];
			sprintf(buf,"u_texture%d",i);
			int texture=i;
			int u_loc=r->getCacheUniformLocation(FS_UNIFORM_TEXTURE0_LOC+i,buf);
			r->setUniform(u_loc,Render::U_I_1,1,&texture);
		}
	}
}
TextureMaterial::TextureMaterial()
{
	m_textureNu=1;
}
TextureMaterial::~TextureMaterial()
{
}


NS_FS_END





