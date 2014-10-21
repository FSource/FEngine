#include "graphics/material/FsColorMaterial.h"
#include "graphics/FsRenderDevice.h"

NS_FS_BEGIN


const char* ColorMaterial::className()
{
	return FS_COLOR_MATERIAL_CLASS_NAME;
}


ColorMaterial* ColorMaterial::create()
{
	ColorMaterial* ret=new ColorMaterial;
	return ret;
}


void ColorMaterial::configRenderDevice(RenderDevice* r)
{
	Material::configRenderDevice(r);
	int u_point_size=r->getCacheUniformLocation(FS_UNIFORM_POINT_SIZE_LOC,FS_UNIFORM_POINT_SIZE_NAME);
	r->setUniform(u_point_size,RenderDevice::U_F_1,1,&m_pointSize);
}


ColorMaterial::ColorMaterial()
{
	m_pointSize=1.0f;
}

ColorMaterial::~ColorMaterial()
{
}




NS_FS_END



