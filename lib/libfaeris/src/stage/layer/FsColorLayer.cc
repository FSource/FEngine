#include "stage/layer/FsColorLayer.h"
#include "graphics/FsRender.h"
#include "graphics/material/FsColorMaterial.h"
#include "FsGlobal.h"
#include "mgr/FsProgramMgr.h"
#include "graphics/FsProgram.h"


NS_FS_BEGIN
ColorLayer* ColorLayer::create()
{
	ColorLayer* ret=new ColorLayer;
	return ret;
}

ColorLayer* ColorLayer::create(Color4f c)
{
	ColorLayer* ret=new ColorLayer;
	ret->setColor(c);
	return ret;
}

void ColorLayer::setColor(Color4f c)
{
	m_material->setColor(c);
}

Color4f ColorLayer::getColor()
{
	return m_material->getColor();
}

Matrix4 ColorLayer::getProjectMatrix()
{
	return Matrix4();
}




void ColorLayer::draw(Render*  r)
{
	if(m_scissorEnabled)
	{
		r->setScissorEnabled(true);
		r->setScissorArea(m_scissorArea.x,m_scissorArea.y,m_scissorArea.width,m_scissorArea.height);
	}


	Matrix4 mat;
	mat.makeOrthographic(0,1,0,1,-100,100);
	r->setProjectionMatrix(&mat);

	r->setProgram(m_program);

	m_material->configRender(r);

	r->disableAllAttrArray();

	int pos_loc=r->getCacheAttrLocation(FS_ATTR_V4F_LOC,FS_ATTR_V4F_NAME);


	static Vector3 vv[4]=
	{
		Vector3(0,0,0),
		Vector3(1,0,0),
		Vector3(1,1,0),
		Vector3(0,1,0),
	};

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};


	r->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,4,0,vv);

	r->drawFace3(faces,2);

	if(m_scissorEnabled)
	{
		r->setScissorEnabled(false);
	}

}

const char* ColorLayer::className()
{
	return FS_COLOR_LAYER_CLASS_NAME;
}

ColorLayer::ColorLayer()
{
	m_color=Color4f(1.0f,1.0f,1.0f,0.5f);
	m_material=ColorMaterial::create();
	m_material->addRef();

	m_program=(Program*)Global::programMgr()->load(FS_PRE_SHADER_V4F);
	FS_SAFE_ADD_REF(m_program);
}

ColorLayer::~ColorLayer()
{
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_program);
}

NS_FS_END 


