#include <algorithm>
#include "stage/layer/FsLayer.h"
#include "stage/entity/FsEntity.h"
#include "stage/FsScene.h"
#include "support/util/FsDict.h"
#include "support/util/FsSlowDict.h"

NS_FS_BEGIN

const char* Layer::className()
{
	return FS_LAYER_CLASS_NAME;
}


Layer::Layer()
{
	init();
}

Layer::~Layer()
{
	destruct();
}



Scene* Layer::getScene()
{
	return m_scene;
}

void Layer::setScene(Scene* scene)
{
	m_scene=scene;
}




/* scissor */ 
void Layer::setScissorArea(float x,float y,float width,float height)
{
	m_scissorArea.set(x,y,width,height);
}
void Layer::getScissorArea(float* x,float* y,float* width,float* height)
{
	*x=m_scissorArea.x;
	*y=m_scissorArea.y;
	*width=m_scissorArea.width;
	*height=m_scissorArea.height;
}

void Layer::add(Entity* e)
{
	e->setLayer(this);
}

void Layer::remove(Entity* e) 
{
	e->setLayer(NULL);
}

void Layer::clearEntity()
{

}


void Layer::update(float dt)
{
}


bool Layer::touchBegin(float x,float y) { return m_touchEnabled; }
bool Layer::touchMove(float x,float y) { return m_touchEnabled; }
bool Layer::touchEnd(float x,float y) { return m_touchEnabled; }


/* touches event */
bool Layer::touchesBegin(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesPointerDown(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesMove(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesPointerUp(TouchEvent* event) { return m_touchesEnabled; }
bool Layer::touchesEnd(TouchEvent* event) { return m_touchesEnabled; }




void Layer::init()
{
	m_visible=true;

	m_touchEnabled=false;
	m_touchesEnabled=false;

	m_dispatchTouchEnabled=false;
	m_dispatchTouchesEnabled=false;



	m_scissorEnabled=false;
	m_scissorArea.set(0,0,1,1);
	m_scene=NULL;


}

void Layer::destruct() { }

Vector3 Layer::toLayerCoord(const Vector3& v) { return v; }











NS_FS_END

