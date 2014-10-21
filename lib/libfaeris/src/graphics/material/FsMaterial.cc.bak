#include "graphics/material/FsMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
const char* Material::className()
{
	return FS_MATERIAL_CLASS_NAME;
}

Material::~Material(){}

void Material::configRenderDevice(RenderDevice* r)
{
	r->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	r->setDepthTest(m_depthTest);

	Matrix4* mat=r->getMVPMatrix();

	/* blend color */
	Color4f color=r->getColor()*m_color;
	float opacity=r->getOpacity()*m_opacity;


	int u_opacity=r->getCacheUniformLocation(FS_UNIFORM_OPACITY_LOC,FS_UNIFORM_OPACITY_NAME);
	int u_color=r->getCacheUniformLocation(FS_UNIFORM_COLOR_LOC,FS_UNIFORM_COLOR_NAME);
	int u_mvp=r->getCacheUniformLocation(FS_UNIFORM_MVP_LOC,FS_UNIFORM_MVP_NAME);

	r->setUniform(u_mvp,RenderDevice::U_M_4,1,mat);
	r->setUniform(u_color,RenderDevice::U_F_4,1,&color);
	r->setUniform(u_opacity,RenderDevice::U_F_1,1,&opacity);

}



NS_FS_END

