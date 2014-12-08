#include "stage/layer/FsColorLayer.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/material/FsMaterial2D.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"


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




void ColorLayer::draw(RenderDevice*  rd)
{
	Program* prog=m_material->getProgram(NULL);
	if(!prog)
	{
		return ;
	}

	if(m_scissorEnabled)
	{
		rd->setScissorEnabled(true);
		rd->setScissorArea(m_scissorArea.x,m_scissorArea.y,m_scissorArea.width,m_scissorArea.height);
	}

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



	Matrix4 mat;
	mat.makeOrthographic(0,1,0,1,-100,100);
	rd->setProjectionMatrix(&mat);
	rd->loadWorldMatrixIdentity();

	rd->setProgram(prog);
	m_material->configRenderDevice(rd);

	rd->disableAllAttrArray();

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);


	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,3,FS_FLOAT,4,0,vv);
	}


	rd->drawFace3(faces,2);

	if(m_scissorEnabled)
	{
		rd->setScissorEnabled(false);
	}

}

const char* ColorLayer::className()
{
	return FS_COLOR_LAYER_CLASS_NAME;
}

ColorLayer::ColorLayer()
{
	m_color=Color4f(1.0f,1.0f,1.0f,0.5f);
	m_material=Material2D::create();


	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
	}
	m_material->setProgramSource(S_programSource);
}

ColorLayer::~ColorLayer()
{
	FS_SAFE_DEC_REF(m_material);
}

NS_FS_END 


