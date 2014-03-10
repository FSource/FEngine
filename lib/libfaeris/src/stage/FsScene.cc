#include "stage/FsScene.h"
#include "stage/layer/FsLayer.h"
#include "support/util/FsSlowArray.h"
#include "mgr/FsObjectMgr.h"
#include "graphics/material/FsMat_V4F_C4F.h"



NS_FS_BEGIN

Scene* Scene::create()
{
	Scene* ret=new Scene;
	return ret;
}

/* layer operation */
void Scene::push(Layer* layer)
{
	if(layer->getScene())
	{
		FS_TRACE_WARN("layer is already owned by scene");
		return ;
	}
	m_layers->push(layer);

	layer->setScene(this);
}

void Scene::pop()
{
	int size=m_layers->size();
	if(size==0)
	{
		FS_TRACE_WARN("No Layer to pop");
		return;
	}
	Layer* ret=(Layer*)m_layers->get(size-1);
	if( ret==m_touchFocusLayer )
	{
		m_touchFocusLayer=NULL;
	}

	ret->setScene(NULL);
	m_layers->pop();
}

void Scene::insert(int pos,Layer* layer)
{
	if(layer->getScene())
	{
		FS_TRACE_WARN("layer is already owned by scene");
		return ;
	}
	m_layers->insert(pos,layer);
	layer->setScene(this);
}
void Scene::replace(int pos,Layer* layer)
{
	Layer*  ret=(Layer*)m_layers->get(pos);
	if(ret==NULL)
	{
		FS_TRACE_WARN("Index(%d) Layer Out Of Range",pos);
		return; 
	}

	if(ret==m_touchFocusLayer)
	{
		m_touchFocusLayer=NULL;
	}

	ret->setScene(NULL);
	m_layers->set(pos,layer);
}

void Scene::remove(Layer* layer)
{
	if(layer->getScene()!=this)
	{
		FS_TRACE_WARN("Layer is not owned by scene");
		return;
	}

	if(layer==m_touchFocusLayer)
	{
		m_touchFocusLayer=NULL;
	}

	layer->setScene(NULL);
	m_layers->remove(layer);
}

Layer* Scene::top()
{
	return (Layer*)m_layers->top();
}

int Scene::layerNu()
{
	return m_layers->size();
}

Layer* Scene::getLayer(int index)
{
	return (Layer*)m_layers->get(index);
}

int Scene::getLayerIndex(Layer* layer)
{
	int layer_nu=m_layers->size();
	Layer* cur=NULL;

	for(int i=0;i<layer_nu;i++)
	{
		cur=(Layer*)m_layers->get(i);
		if(cur==layer)
		{
			return i;
		}
	}
	return -1;
}

void Scene::clear()
{
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		layer->setScene(NULL);
	}
	m_layers->clear();
	m_touchFocusLayer=NULL;
}

void Scene::setTouchEnabled(bool enabled)
{
	m_touchEnabled=enabled;
}

bool Scene::getTouchEnabled()
{
	return m_touchEnabled;
}


void Scene::setTouchesEnabled(bool enabled)
{
	m_touchesEnabled=enabled;
}

bool Scene::getTouchesEnabled()
{
	return m_touchesEnabled;
}





void Scene::setEnabledFade(bool fade)
{
	m_fadeEnabled=fade;
}

void Scene::setFadeColor(Color c)
{
	m_fadeColor=c;
}


/* event */

void Scene::enter()
{
	/* do nothing */
}
void Scene::exit()
{
	/* do nothing */
}
void Scene::update(float dt)
{
	updateAction(dt);
	updateLayers(dt);
}


void Scene::updateLayers(float dt)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->getVisible())
		{
			layer->update(dt);
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::draw(Render* render)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=0;i<layer_nu;i++)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->getVisible())
		{
			layer->draw(render);
		}
	}
	m_layers->unlock();
	m_layers->flush();


	if(m_fadeEnabled)
	{

		Mat_V4F_C4F* material=Mat_V4F_C4F::shareMaterial();
		material->setOpacity(1.0);

		Matrix4 mat;
		mat.makeOrthographic(0,1,0,1,-100,100);
		render->setProjectionMatrix(&mat);

		render->setMaterial(material);

		render->setActiveTexture(0);
		render->disableAllAttrArray();

		int pos_loc=material->getV4FLocation();
		int color_loc=material->getC4FLocation();

		static Vector3 vv[4]=
		{
			Vector3(0,0,0),
			Vector3(1,0,0),
			Vector3(1,1,0),
			Vector3(0,1,0),
		};
		float vc[16]=
		{
			m_fadeColor.r/255.0f,m_fadeColor.g/255.0f,m_fadeColor.b/255.0f,m_fadeColor.a/255.0f,
			m_fadeColor.r/255.0f,m_fadeColor.g/255.0f,m_fadeColor.b/255.0f,m_fadeColor.a/255.0f,
			m_fadeColor.r/255.0f,m_fadeColor.g/255.0f,m_fadeColor.b/255.0f,m_fadeColor.a/255.0f,
			m_fadeColor.r/255.0f,m_fadeColor.g/255.0f,m_fadeColor.b/255.0f,m_fadeColor.a/255.0f,
		};

		Face3 faces[2]=
		{
			Face3(0,1,2),
			Face3(2,3,0),
		};

		render->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,4,0,vv);
		render->setAndEnableVertexAttrPointer(color_loc,4,FS_FLOAT,4,0,vc);

		render->drawFace3(faces,2);
	}

}
void Scene::touchBegin(float x,float y)
{
	m_touchFocusLayer=NULL;
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if((layer->getScene()==this)&&layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchBegin(x,y);
		}
		if(handle&&layer->getScene()==this)
		{
			m_touchFocusLayer=layer;
			break;
		}
	}

	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchMove(float x,float y)
{
	if(m_touchFocusLayer&&m_touchFocusLayer->touchEnabled()&&m_touchFocusLayer->getVisible())
	{
		m_touchFocusLayer->touchMove(x,y);
	}

}

void Scene::touchEnd(float x,float y)
{
	if(m_touchFocusLayer&&m_touchFocusLayer->touchEnabled()&&m_touchFocusLayer->getVisible())
	{
		m_touchFocusLayer->touchEnd(x,y);
	}
	m_touchFocusLayer=NULL;
}

void Scene::touchesBegin(TouchEvent* event)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchesBegin(event);
		}
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchesPointerDown(TouchEvent* event)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchesPointerDown(event);
		}
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::touchesMove(TouchEvent* event)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchesMove(event);
		}
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchesPointerUp(TouchEvent* event)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchesPointerUp(event);
		}
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchesEnd(TouchEvent* event)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->getVisible())
		{
			handle=layer->touchesEnd(event);
		}
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}



void Scene::keypadEvent(int type,int keycode)
{
}

void Scene::inputTextEvent(const char* text,int length)
{
}




const char* Scene::className()
{
	return FS_SCENE_CLASS_NAME;
}

Scene::Scene()
{
	init();
}
Scene::~Scene()
{
	destruct();
}

void Scene::init()
{
	m_layers=FsSlowArray::create();
	FS_NO_REF_DESTROY(m_layers);

	m_fadeColor=Color(255,255,255,0);
	m_fadeEnabled=true;
	m_touchFocusLayer=NULL;

	m_touchEnabled=true;
	m_touchesEnabled=true;

}




void Scene::destruct()
{
	FS_DESTROY(m_layers);
}


NS_FS_END





