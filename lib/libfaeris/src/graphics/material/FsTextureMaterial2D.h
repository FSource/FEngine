#ifndef _FS_TEXTURE_MATERIAL_2D_H_
#define _FS_TEXTURE_MATERIAL_2D_H_

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"


NS_FS_BEGIN

class TextureMaterial2D:public Material 
{
	public:
		static TextureMaterial2D* create();


	public:
		void setTextureNu(int value){m_textureNu=value;}
		int getTextureNu() { return m_textureNu;}

	public:
		virtual void configRenderDevice(RenderDevice* r);
		const char* className();

	protected:
		TextureMaterial();
		virtual ~TextureMaterial();

	private:
		int m_textureNu;
};


NS_FS_END




#endif /*_FS_TEXTURE_MATERIAL_H_*/

