#include <algorithm>
#include "stage/layer/FsLayer.h"
#include "stage/entity/FsEntity.h"
#include "stage/FsScene.h"
#include "support/util/FsDict.h"
#include "support/util/FsSlowDict.h"
#include "mgr/FsObjectMgr.h"

NS_FS_BEGIN
static bool FsFuncEntity_SortZolder(Entity* left,Entity* right)
{
	if( left->getZorder()<right->getZorder())
	{
		return true;
	}
	else if(left->getZorder()>right->getZorder())
	{
		return false;
	}
	else 
	{
		return left->getAddOlder()<right->getAddOlder();
	}
}

const char* Layer::className()
{
	return FS_LAYER_CLASS_NAME;
}

int Layer::getEntityNu()
{
	return m_entity->size();
}

void Layer::add(Entity* entity)
{
	FS_TRACE_WARN_ON(entity==NULL,"Entity Is NULL");
	if(entity->getLayer()==this)
	{
		FS_TRACE_WARN("object all ready add to this layer");
		return ;
	}

	if(entity->getParent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by another layer");
		return ;
	}

	m_entity->insert(entity,entity);
	entity->setAddOlder(m_addOlder++);
	entity->setLayer(this);
}


void Layer::remove(Entity* entity)
{
	if(entity->getLayer()!=this)
	{
		FS_TRACE_WARN("Object is not Own by this layer");
		return ;
	}

	if(entity->getParent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by this layer,can't remove");
	}
	entity->setLayer(NULL);
	m_entity->remove(entity);
	if(m_touchFocus==entity)
	{
		m_touchFocus=NULL;
	}
}



Layer::Layer()
{
	init();
}

Layer::~Layer()
{
	destruct();
}

void Layer::update(float dt)
{
	updateAction(dt);
	updateEntity(dt);
}

void Layer::updateEntity(float dt)
{
	m_entity->lock();
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		if(entity->getLayer()==this) 
		{
			if(entity->getVisibles()) entity->updates(dt);
		}
		iter->next();
	}
	delete iter;

	m_entity->unlock();
	m_entity->flush();

}


void Layer::draw(Render* render)
{
	updateAllWorldMatrix();
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		if(entity->getVisibles()) entity->draws(render,false);
		iter->next();
	}
	delete iter;

}

void Layer::clearEntity()
{
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->setLayer(NULL);
		iter->next();
	}
	m_entity->clear();
	delete iter;
	m_touchFocus=NULL;
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


bool Layer::touchBegin(float x,float y)
{
	m_touchFocus=NULL;
	m_entity->lock();
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	if(m_dispatchTouchEnabled)
	{
		std::vector<Entity*> entitys;
		getTouchEnabledEntity(&entitys);
		sortEntity(&entitys);
		int entity_nu=entitys.size();
		for(int i=entity_nu-1;i>=0;i--)
		{
			Entity* e=entitys[i];
			if(e->getLayer()==this&&e->hit2D(tv.x,tv.y))
			{
				/* NOTE: entity will detach when called touchBegin */
				bool ret=e->touchBegin(tv.x,tv.y);
				/* check entity accept event and not detach */
				if(ret&&e->getLayer()==this)
				{
					m_touchFocus=e;
					break;  
				}
			}
		}
	}
	m_entity->unlock();
	m_entity->flush();
	return m_touchFocus!=NULL;
}
bool Layer::touchMove(float x,float y)
{
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	if(m_touchFocus) 
	{
		return m_touchFocus->touchMove(tv.x,tv.y);
	}
	return false;
}
bool Layer::touchEnd(float x,float y)
{
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	if(m_touchFocus) 
	{
		bool ret=m_touchFocus->touchEnd(tv.x,tv.y);
		m_touchFocus=NULL;
		return ret;
	}

	return false;
}


/* touches event */
bool Layer::touchesBegin(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer::touchesPointerDown(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer::touchesMove(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer::touchesPointerUp(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer::touchesEnd(TouchEvent* event)
{
	return m_touchesEnabled;
}




void Layer::init()
{
	m_addOlder=0;

	m_entity=FsSlowDict::create();
	FS_NO_REF_DESTROY(m_entity);


	m_visible=true;

	m_touchEnabled=false;
	m_touchesEnabled=false;

	m_dispatchTouchEnabled=false;
	m_dispatchTouchesEnabled=false;



	m_scissorEnabled=false;
	m_scissorArea.set(0,0,1,1);
	m_scene=NULL;

	m_touchFocus=NULL;

}

void Layer::destruct()
{
	clearEntity();
	FS_DESTROY(m_entity);
}

void Layer::updateAllWorldMatrix()
{
	FsDict::Iterator* iter= m_entity->takeIterator();

	while(!iter->done())
	{
		Entity* entity=(Entity*) iter->getValue();
		entity->updateAllWorldMatrix();
		iter->next();
	}
	delete iter;
}

void Layer::getTouchEnabledEntity(std::vector<Entity*>* e)
{
	FsDict::Iterator* iter= m_entity->takeIterator();

	while(!iter->done())
	{
		Entity* entity=(Entity*) iter->getValue();
		if(entity->getTouchEnabled()&&entity->getVisible())
		{
			e->push_back(entity);
		}
		iter->next();
	}
	delete iter;

}

void Layer::sortEntity(std::vector<Entity*>* entitys)
{
	std::sort(entitys->begin(),entitys->end(),FsFuncEntity_SortZolder);
}

Vector3 Layer::toLayerCoord(const Vector3& v)
{
	return v;
}











NS_FS_END

