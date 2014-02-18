#include "stage/entity/FsEntity.h"
#include "graphics/FsRender.h"
#include "stage/layer/FsLayer.h"

NS_FS_BEGIN

uint32_t Entity::ms_olderCount=0;

const char* Entity::className()
{
	return FS_ENTITY_CLASS_NAME;
}

Entity* Entity::create()
{
	Entity* ret=new Entity;
	return ret;
}
Entity::Entity()
{
	init();
}


Entity::~Entity()
{
	destruct();
}


void Entity::update(float dt)
{
	updateAction(dt);
}

void Entity::updates(float dt)
{
	if(getVisible()) this->update(dt);
	int child_nu=m_chirdren->size();

	m_chirdren->lock();
	for(int i=0;i<child_nu;i++)
	{
		Entity* e=(Entity*)m_chirdren->get(i);
		if(e->getParent()==this) /* e not remove from entity */
		{
			if(e->getVisibles()) e->updates(dt);
		}
	}
	m_chirdren->unlock();
	m_chirdren->flush();
}


void Entity::draw(Render* r,bool updateMatrix)
{

}

void Entity::draws(Render* r,bool updateMatrix)
{
	if(m_zorderDirty)
	{
		sortChildren();
		m_zorderDirty=0;
	}

	int child_nu=m_chirdren->size();
	int i=0;
	for(;i<child_nu;i++)
	{
		Entity* e=(Entity*) m_chirdren->get(i);
		if(e->getZorder()<0) 
		{
			if(e->getVisibles()) e->draws(r,updateMatrix);
		}
		else 
		{
			break;
		}
	}

	if(getVisible()) this->draw(r,updateMatrix);

	for(;i<child_nu;i++)
	{
		Entity* e=(Entity* )m_chirdren->get(i);
		if(e->getVisibles()) e->draws(r,updateMatrix);
	}
}




void Entity::init()
{

	m_translate.set(0,0,0);
	m_rotate.set(0,0,0);
	m_scale.set(1,1,1);

	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
	m_hasBoundSphere=0;
	m_hasBoundBox=0;
	m_visible=1;
	m_visibles=1;
	m_zorderDirty=1;
	m_touchEnabled=0;
	m_touchesEnabled=0;
	m_dispatchTouchEnabled=0;
	m_dispatchTouchesEnabled=0;

	m_zorlder=0.0f;

	m_parent=NULL;
	m_layer=NULL;
	m_touchFocus=NULL;

	m_chirdren=FsSlowArray::create();
	FS_NO_REF_DESTROY(m_chirdren);
}

void Entity::destruct()
{
	assert(m_parent==NULL);
	assert(m_layer==NULL);
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* entity=(Entity*) m_chirdren->get(i);
		entity->setParent(NULL);
	}
	FS_DESTROY(m_chirdren);
	m_touchFocus=NULL;
}


bool Entity::updateLocalMatrix()
{
	if(m_localMatrixDirty)
	{
		m_localMatrix.makeCompose(m_translate,m_rotate,FS_EULER_XYZ,m_scale);
		m_localMatrixDirty=0;
		return true;
	}
	return false;
}

bool Entity::updateWorldMatrix()
{
	updateLocalMatrix();
	if(!m_parent)
	{
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_localMatrix;
			m_worldMatrixDirty=0;
			return true;
		}
	}
	else 
	{
		bool dirty=m_parent->updateWorldMatrix();
		if(m_worldMatrixDirty||dirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(m_localMatrix);
			m_worldMatrixDirty=0;
			return true;
		}
	}
	return false;
}

void Entity::updateAllWorldMatrix()
{
	bool dirty=updateWorldMatrix();

	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* node=(Entity*)m_chirdren->get(i);
		node->updateChildWorldMatrix(dirty);
	}
}

void Entity::updateChildWorldMatrix(bool force)
{
	updateLocalMatrix();
	bool dirty=force||m_worldMatrixDirty;

	if(dirty)
	{
		m_worldMatrix=m_parent->m_worldMatrix;
		m_worldMatrix.mul(m_localMatrix);
		m_worldMatrixDirty=0;
	}

	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* node=(Entity*)m_chirdren->get(i);
		node->updateChildWorldMatrix(dirty);
	}
}


Vector3 Entity::localToWorld(const Vector3& v)
{
	updateWorldMatrix();
	return m_worldMatrix.mulVector3(v);
}

Vector3 Entity::worldToLocal(const Vector3& v)
{
	updateWorldMatrix();

	Matrix4 inverse;
	m_worldMatrix.getInverse(&inverse);

	return inverse.mulVector3(v);
}


bool Entity::hit2D(float x,float y)
{
	return false;
}

void Entity::addChild(Entity* n)
{
	FS_TRACE_WARN_ON(n==NULL,"Entity Is NULL");
	if(n->m_parent==this)
	{
		FS_TRACE_WARN("Child Already Add To This Entity");
		return;
	}

	if(n->m_parent)  
	{
		n->m_parent->remove(n);
	}
	else
	{
		if(n->m_layer)
		{
			n->m_layer->remove(n);
		}
	}

	assert(n->m_parent==NULL);
	assert(n->m_layer==NULL);

	if(m_layer)
	{
		n->setLayer(m_layer);
	}

	m_chirdren->push(n);
	n->setParent(this);

	m_zorderDirty=1;
	n->m_addOlder=Entity::ms_olderCount++;
}




FsArray* Entity::takeAllChild()
{
	FsArray* ret=FsArray::create();
	getAllChild(ret);
	return ret;
}
int Entity::childNu()
{
	return m_chirdren->size();
}

void Entity::getAllChild(FsArray* ret)
{
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* ob=(Entity*)m_chirdren->get(i);
		ret->push(ob);
		ob->getAllChild(ret);
	}
}

void Entity::setChildVisible(bool visiable, bool rec)
{
	int child_nu=m_chirdren->size();

	for(int i=0;i<child_nu;i++)
	{
		Entity* ob=(Entity*)m_chirdren->get(i);
		ob->setVisible(visiable);
		if(rec)
		{
			ob->setChildVisible(visiable,true);
		}
	}
}




void Entity::remove(Entity* n)
{
	if(n->m_parent!=this)
	{
		FS_TRACE_WARN("Entity Is Not A Chirld Of This");
		return;
	}
	n->setLayer(NULL);
	n->setParent(NULL);
	if( m_touchFocus== n)
	{
		m_touchFocus=NULL;
	}
	m_chirdren->remove(n);

}

void Entity::clearChild()
{
	m_touchFocus=NULL;
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* e=(Entity*)m_chirdren->get(i);
		e->setParent(NULL);
		e->setLayer(NULL);
	}
	m_chirdren->clear();
}

Layer* Entity::getLayer()
{
	return m_layer;
}

void Entity::setLayer(Layer* layer)
{
	m_layer=layer;
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* e=(Entity*)m_chirdren->get(i);
		e->setLayer(layer);
	}
}

Entity* Entity::getParent()
{
	return m_parent;
}

void Entity::setParent(Entity* parent)
{
	m_parent=parent;
}

Scene* Entity::getScene()
{
	if(m_layer)
	{
		return m_layer->getScene();
	}
	return NULL;
}

float Entity::getZorder()
{
	return m_zorlder;
}

void Entity::setZorder(float z)
{
	if(m_zorlder==z)
	{
		return;
	}
	m_zorlder=z;
	if(m_parent)
	{
		m_parent->m_zorderDirty=1;
	}
}

void Entity::sortChildren()
{
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu-1;i++)
	{
		Entity* ei=(Entity*)m_chirdren->get(i);
		for(int j=i+1;j<child_nu;j++)
		{
			Entity* ej=(Entity*)m_chirdren->get(j);
			if((ei->m_zorlder>ej->m_zorlder)||
					((ei->m_zorlder==ej->m_zorlder)&& (ei->m_addOlder>ej->m_addOlder)))
			{
				Entity* tmp=ei; ei=ej; ej=tmp;

			   	ei->addRef();
				ej->addRef();

				m_chirdren->set(i,ei);
				m_chirdren->set(j,ej);

				ei->decRef();
				ej->decRef();
			}
		}
	}
}

void Entity::detach()
{
	if(m_parent)
	{
		m_parent->remove(this);
	}
	else if(m_layer)
	{
		m_layer->remove(this);
	}
	else 
	{
		FS_TRACE_WARN("Entity Is Already Detached");
	}
}




Matrix4* Entity::getWorldMatrix()
{
	updateWorldMatrix();
	return &m_worldMatrix;

}
Matrix4* Entity::getLocalMatrix()
{
	updateLocalMatrix();
	return &m_localMatrix;
}



/* touch */
void Entity::setTouchEnabled(bool enabled)
{
	m_touchEnabled=enabled;
}
bool Entity::getTouchEnabled()
{
	return m_touchEnabled;
}

bool Entity::touchBegin(float x,float y)
{
	m_touchFocus=NULL;

	if(m_dispatchTouchEnabled)
	{
		if(m_zorderDirty)
		{
			sortChildren();
			m_zorderDirty=false;
		}
		m_chirdren->lock();
		int child_nu=m_chirdren->size();
		for(int i=child_nu-1;i>=0;i--)
		{
			Entity* e=(Entity*)m_chirdren->get(i);
			if(e->getVisible()&&e->getTouchEnabled()&&e->getParent()==this&&e->hit2D(x,y))
			{
				/* NOTE: entity will detach when called touchBegin */
				bool ret=e->touchBegin(x,y);
				if(ret&&e->getParent()==this)
				{
					m_touchFocus=e;
					break;
				}
			}
		}
		m_chirdren->unlock();
		m_chirdren->flush();
	}
	return m_touchFocus!=NULL;
}
bool Entity::touchMove(float x,float y)
{
	if(m_touchFocus)
	{
		return m_touchFocus->touchMove(x,y);
	}

	return false;
}

bool Entity::touchEnd(float x,float y)
{
	if(m_touchFocus)
	{
		bool ret=m_touchFocus->touchEnd(x,y);
		m_touchFocus=NULL;
		return ret;
	}
	return false;
}






void Entity::setTouchesEnabled(bool enabled)
{
	m_touchesEnabled=enabled;
}
bool Entity::getTouchesEnabled()
{
	return m_touchesEnabled;
}


void Entity::setDispatchTouchEnabled(bool enabled)
{
	m_dispatchTouchEnabled=enabled;
}

bool Entity::getDispatchTouchEnabled()
{
	return m_dispatchTouchEnabled;
}

void Entity::setDispatchTouchesEnabled(bool enabled)
{
	m_dispatchTouchesEnabled=enabled;
}

bool Entity::getDispatchTouchesEnabled()
{
	return m_dispatchTouchesEnabled;
}




NS_FS_END



















