#include <algorithm>
#include "FsClass.h"
#include "stage/layer/FsLayer2D.h"
#include "support/util/FsArray.h"
#include "support/util/FsSlowDict.h"
#include "support/util/FsDict.h"
#include "graphics/FsRenderDevice.h"
#include "stage/entity/FsEntity2D.h"

NS_FS_BEGIN

static bool FsFuncEntity_SortZolder(Entity2D* left,Entity2D* right)
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

static bool FsFuncEntity_SortY(Entity2D* left,Entity2D* right)
{
	return left->getPositionInWorld().y>right->getPositionInWorld().y;
}


Layer2D* Layer2D::create()
{
	Layer2D* ret=new Layer2D;
	return ret;
}


Matrix4 Layer2D::getProjectMatrix() 
{
	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			-1024,
			1024);
	return mat;
}

Rect2D Layer2D::getViewArea()const 
{
	return m_viewArea;
}

void Layer2D::toLayerCoord(float* x,float* y)
{
	*x=*x*m_viewArea.width+m_viewArea.x;
	*y=*y*m_viewArea.height+m_viewArea.y;
}

Vector3 Layer2D::toLayerCoord(const Vector3& v)
{
	float x=v.x;
	float y=v.y;
	toLayerCoord(&x,&y);
	return Vector3(x,y,0);
}

void Layer2D::setViewArea(float x,float y,float width,float height)
{
	m_viewArea.set(x,y,width,height);
}


void Layer2D::getViewArea(float* x,float* y,float* width,float* height)
{
	*x=m_viewArea.x;
	*y=m_viewArea.y;
	*width=m_viewArea.width;
	*height=m_viewArea.height;
}




void Layer2D::setViewArea(const Rect2D& area)
{
	m_viewArea=area;
}

void Layer2D::setSortMode(int mode)
{
	m_sortMode=mode;
}
int Layer2D::getSortMode()
{
	return m_sortMode;
}



/* eliminate */
void Layer2D::setEliminate(bool eliminate)
{
	m_eliminate=eliminate;
}

bool Layer2D::getEliminate()
{
	return m_eliminate;
}

void Layer2D::draw(RenderDevice* rd)
{

	if(m_scissorEnabled)
	{
		rd->setScissorEnabled(true);
		rd->setScissorArea(m_scissorArea.x,m_scissorArea.y,m_scissorArea.width,m_scissorArea.height);
	}
	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			-1024,
			1024);
	rd->setProjectionMatrix(&mat);
	rd->setViewMatrix(&Matrix4::IDENTITY);


	rd->loadWorldMatrixIdentity();

	/* update all child matrix4 */
	updateAllWorldMatrix();

	std::vector<Entity2D*> entitys;

	getEntityInView(&entitys);
	sortEntity(&entitys);

	int entity_nu=entitys.size();
	for(int i=0;i<entity_nu;i++)
	{
		Entity2D* ob=entitys[i];
		if(ob->getVisibles()) ob->draws(rd,false);
	}

	if(m_scissorEnabled)
	{
		rd->setScissorEnabled(false);
	}
}



void Layer2D::getEntityInView(std::vector<Entity2D*>* entitys)
{
	/* TODO(add real eliminate here) */
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		FsObject* ob=iter->getValue();
		entitys->push_back((Entity2D*)ob);
		iter->next();
	}
	delete iter;
}


void Layer2D::sortEntity(std::vector<Entity2D*>* entitys)
{
	switch(m_sortMode)
	{
		case SORT_NONE:
			break;
		case SORT_ORDER_Z:
			std::sort(entitys->begin(),entitys->end(),FsFuncEntity_SortZolder);
			break;
		case SORT_Y:
			std::sort(entitys->begin(),entitys->end(),FsFuncEntity_SortY);
			break;
		default:
			FS_TRACE_WARN("Unkown Sort Type");
	}
}


Layer2D::Layer2D()
{
	m_viewArea.set(0,0,1,1);
	m_sortMode=SORT_NONE;
	m_eliminate=false;
	m_entity=FsSlowDict::create();
	FS_NO_REF_DESTROY(m_entity);
	m_touchFocus=NULL;
}

Layer2D::~Layer2D()
{
	clearEntity();
	FS_DESTROY(m_entity);
}


void Layer2D::add(Entity2D* entity)
{
	FS_TRACE_WARN_ON(entity==NULL,"Entity Is NULL");
	if(entity->getLayer()==this)
	{
		FS_TRACE_WARN("object already add to this layer");
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


void Layer2D::remove(Entity2D* entity)
{
	if(entity->getLayer()!=this)
	{
		FS_TRACE_WARN("Object is not Own by this layer");
		return ;
	}

	if(entity->getParent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by this layer,can't remove");
		return;
	}
	entity->setLayer(NULL);
	m_entity->remove(entity);
	if(m_touchFocus==entity)
	{
		m_touchFocus=NULL;
	}
}

void Layer2D::clearEntity()
{
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity2D* entity=(Entity2D*)iter->getValue();
		entity->setLayer(NULL);
		iter->next();
	}
	m_entity->clear();
	delete iter;
	m_touchFocus=NULL;
}

int Layer2D::getEntityNu()
{
	return m_entity->size();
}

void Layer2D::update(float dt)
{
	updateAction(dt);
	updateEntity(dt);
}

void Layer2D::updateEntity(float dt)
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

bool Layer2D::touchBegin(float x,float y)
{
	m_touchFocus=NULL;
	m_entity->lock();
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	if(m_dispatchTouchEnabled)
	{
		std::vector<Entity2D*> entitys;
		getTouchEnabledEntity(&entitys);
		sortEntity(&entitys);
		int entity_nu=entitys.size();
		for(int i=entity_nu-1;i>=0;i--)
		{
			Entity2D* e=entitys[i];
			if(e->getLayer()==this&&e->hit2D(tv.x,tv.y))
			{
				/* NOTE: entity will detach when called touchBegin */
				bool ret=FS_OBJECT_LAMBDA_CALL(e,onTouchBegin,touchBegin,tv.x,tv.y);
				if(ret)
				{
					/* check entity accept event and not detach */
					if(e->getLayer()==this)
					{
						m_touchFocus=e;
					}
					break;  
				}
			}
		}
	}
	m_entity->unlock();
	m_entity->flush();
	return m_touchFocus!=NULL;
}
bool Layer2D::touchMove(float x,float y)
{
	m_entity->lock();
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	bool ret=false;
	if(m_touchFocus) 
	{
		ret=FS_OBJECT_LAMBDA_CALL(m_touchFocus,onTouchMove,touchMove,tv.x,tv.y);
	}
	m_entity->unlock();
	m_entity->flush();
	return ret;
}
bool Layer2D::touchEnd(float x,float y)
{
	m_entity->lock();
	Vector3 tv=toLayerCoord(Vector3(x,y,0));
	bool ret=false;
	if(m_touchFocus) 
	{
		Entity2D* en=m_touchFocus;
		m_touchFocus=NULL;
		ret=FS_OBJECT_LAMBDA_CALL(en,onTouchMove,touchEnd,tv.x,tv.y);
	}
	m_entity->unlock();
	m_entity->flush();
	return ret;
}


/* touches event */
bool Layer2D::touchesBegin(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer2D::touchesPointerDown(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer2D::touchesMove(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer2D::touchesPointerUp(TouchEvent* event)
{
	return m_touchesEnabled;
}

bool Layer2D::touchesEnd(TouchEvent* event)
{
	return m_touchesEnabled;
}


void Layer2D::updateAllWorldMatrix()
{
	FsDict::Iterator* iter= m_entity->takeIterator();

	while(!iter->done())
	{
		Entity2D* entity=(Entity2D*) iter->getValue();
		entity->updateAllWorldMatrix();
		iter->next();
	}
	delete iter;
}

void Layer2D::getTouchEnabledEntity(std::vector<Entity2D*>* e)
{
	FsDict::Iterator* iter= m_entity->takeIterator();

	while(!iter->done())
	{
		Entity2D* entity=(Entity2D*) iter->getValue();
		if(entity->getTouchEnabled()&&entity->getVisible())
		{
			e->push_back(entity);
		}
		iter->next();
	}
	delete iter;
}



/*** Used For Layer2D FsClass Attribute */

void Layer2D_setViewArea(Layer2D* l,FsDict* dict)
{
	Rect2D view_area=l->getViewArea();

	if(dict->lookupString("x"))
	{
		view_area.x=dict->lookupString("x")->toFloatValue();
	}

	if(dict->lookupString("y"))
	{
		view_area.y=dict->lookupString("y")->toFloatValue();
	}

	if(dict->lookupString("w"))
	{
		view_area.width=dict->lookupString("w")->toFloatValue();
	}

	if(dict->lookupString("h"))
	{
		view_area.height=dict->lookupString("h")->toFloatValue();
	}

	l->setViewArea(view_area);
}


static FsClass::FsAttributeDeclare S_Layer2D_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("viewArea",FsType::FT_DICT,NULL,Layer2D_setViewArea,0),

	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)

} ;

FS_CLASS_IMPLEMENT_WITH_BASE(Layer2D,Layer,0,S_Layer2D_Main_Attr);



NS_FS_END

















