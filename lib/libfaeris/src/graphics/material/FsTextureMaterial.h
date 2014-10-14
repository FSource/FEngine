#ifndef _FS_TEXTURE_MATERIAL_H_
#define _FS_TEXTURE_MATERIAL_H_

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"

/* uniform:
 * 		sampler2D 	u_texture0,
 * 		sampler2D	u_texture1,
 * 			.
 * 			.
 * 			.
 * 		sampler2D	u_texturen
 */

NS_FS_BEGIN

class TextureMaterial:public Material 
{
	public:
		static TextureMaterial* create();


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

