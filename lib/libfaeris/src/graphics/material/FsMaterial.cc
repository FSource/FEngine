#include "graphics/material/FsMaterial.h"
#include "graphics/Material/FsRenderDevice.h"
NS_FS_BEGIN


const char* Material::className()
{
	return "Material";
}


Material::Material()
	:m_wireFrame(false),
	m_blendEquation(E_BlendEquation::ADD),
	m_blendSrc(E_BlendFactor::SRC_ALPHA),
	m_blendDst(E_BlendFactor::ONE_MINUS_SRC_ALPHA),
	m_depthTestEnabled(false),
	m_depthWriteEnabled(false),
	m_doubleSideEnabled(false),
{}


void Material::configRenderDevice(RenderDevice* rd,bool force)
{
	if(force)
	{
		rd->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
		rd->setDepthTestEnabled(m_depthTestEnabled);
		rd->setDepthWriteEnabled(m_depthWriteEnabled);
		rd->setDoubleSideEnabled(m_doubleSideEnabled);

		rd->setColor(m_color);
		rd->setOpacity(m_opacity);
	}
}

Material::~Material() 
{
}





NS_FS_END











