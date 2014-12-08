#include "graphics/material/FsMaterial.h"
#include "graphics/FsRenderDevice.h"


NS_FS_BEGIN


const char* Material::className()
{
	return "Material";
}


Material::Material()
	:m_wireframe(false),
	m_blendEquation(E_BlendEquation::ADD),
	m_blendSrc(E_BlendFactor::SRC_ALPHA),
	m_blendDst(E_BlendFactor::ONE_MINUS_SRC_ALPHA),
	m_frontSide(E_FrontFace::CCW),
	m_doubleSideEnabled(true),
	m_depthTestEnabled(false),
	m_depthWriteEnabled(false)
{}


void Material::configRenderDevice(RenderDevice* rd)
{
	rd->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	rd->setDepthTestEnabled(m_depthTestEnabled);
	rd->setDepthWriteEnabled(m_depthWriteEnabled);
	rd->setDoubleSideEnabled(m_doubleSideEnabled);
	rd->setFrontSide(m_frontSide);
}



Material::~Material() 
{
}





NS_FS_END











