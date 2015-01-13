#include "FsClass.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsRenderDevice.h"
#include "stage/layer/FsLayer.h"
#include "stage/entity/transform/FsEulerTransform.h"
#include "FsGlobal.h"

NS_FS_BEGIN

uint32_t Entity::ms_olderCount=0;

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
	if(getVisible()) FS_OBJECT_LAMBDA_CALL( this,onUpdate,update,dt);
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


void Entity::draw(RenderDevice* r,bool updateMatrix)
{

}

void Entity::draws(RenderDevice* r,bool updateMatrix)
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

	if(getVisible()) FS_OBJECT_LAMBDA_CALL(this,onDraw,draw,r,updateMatrix);

	for(;i<child_nu;i++)
	{
		Entity* e=(Entity* )m_chirdren->get(i);
		if(e->getVisibles()) e->draws(r,updateMatrix);
	}
}




void Entity::init()
{

	m_transform= EulerTransform::create();
	FS_SAFE_ADD_REF(m_transform);

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


	onUpdate=nullptr;
	onDraw=nullptr;
	onTouchBegin=nullptr;
	onTouchMove=nullptr;
	onTouchEnd=nullptr;
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
	delete m_transform;

}



bool Entity::updateWorldMatrix()
{
	if(!m_parent)
	{
		bool local_dirty=m_transform->updateTransformMatrix();
		if(m_worldMatrixDirty||local_dirty)
		{
			m_worldMatrix=*(m_transform->getTransformMatrix());
			m_worldMatrixDirty=0;
			setChildWorldMatrixDirty();
			return true;
		}
	}
	else 
	{
		bool dirty=m_parent->updateWorldMatrix();
		bool local_matrix=m_transform->updateTransformMatrix();

		if(m_worldMatrixDirty||local_matrix||dirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(*m_transform->getTransformMatrix());
			m_worldMatrixDirty=0;
			setChildWorldMatrixDirty();
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
	bool local_dirty=m_transform->updateTransformMatrix();
	bool dirty=force||m_worldMatrixDirty||local_dirty;

	if(dirty)
	{
		m_worldMatrix=m_parent->m_worldMatrix;
		m_worldMatrix.mul(*m_transform->getTransformMatrix());
		m_worldMatrixDirty=0;
	}

	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* node=(Entity*)m_chirdren->get(i);
		node->updateChildWorldMatrix(dirty);
	}
}

void Entity::setChildWorldMatrixDirty()
{
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* node=(Entity*)m_chirdren->get(i);
		node->m_worldMatrixDirty=1;
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

void Entity::setTransform(ITransform* tf)
{
	FS_SAFE_ASSIGN(m_transform,tf);
}


ITransform* Entity::getTransform()
{
	return m_transform;
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

	n->m_worldMatrixDirty=true;
	m_chirdren->push(n);
	n->setParent(this);

	m_zorderDirty=1;
	n->m_addOlder=Entity::ms_olderCount++;
}




FsArray* Entity::takeAllChild(bool visible)
{
	FsArray* ret=FsArray::create();
	getAllChild(ret,visible);
	return ret;
}
int Entity::childNu()
{
	return m_chirdren->size();
}

void Entity::getAllChild(FsArray* ret,bool visiable)
{
	if(visiable && !getVisibles())
	{
		return ;
	}

	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* ob=(Entity*)m_chirdren->get(i);
		if(visiable && ob->getVisibles() )
		{
			if(visiable && ob->getVisible())
			{
				ret->push(ob);
			}
			ob->getAllChild(ret,visiable);
		}
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
	if(m_transform->updateTransformMatrix())
	{
		m_worldMatrixDirty=true;
	}

	return m_transform->getTransformMatrix();
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
				bool ret=FS_OBJECT_LAMBDA_CALL(e,onTouchBegin,touchBegin,x,y);
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
		return FS_OBJECT_LAMBDA_CALL(m_touchFocus,onTouchMove,touchMove,x,y);
	}

	return false;
}

bool Entity::touchEnd(float x,float y)
{
	if(m_touchFocus)
	{
		Entity* focus=m_touchFocus;
		m_touchFocus=NULL;
		bool ret=FS_OBJECT_LAMBDA_CALL(focus,onTouchEnd,touchEnd,x,y);
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





/***  Use For Entity FsClass Attribute  **/
static Entity* Entity_NewInstance(FsDict* attr)
{
	Entity* ret=Entity::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}

static void Entity_SetChildren(Entity* en,FsArray* attr)
{
	en->clearChild();
	int child_nu=attr->size();

	for(int i=0;i<child_nu;i++)
	{
		FsDict* dict=attr->getDict(i);
		if(dict)
		{
			FsObject* ob=Global::classMgr()->newInstance(dict);
			if(ob)
			{
				Entity* child=dynamic_cast<Entity*>(ob);
				if(child)
				{
					en->addChild(child);
				}
				else 
				{
					FS_TRACE_WARN("Not SubClass Of Entity,Ingore Item(%d)",i);
					ob->destroy();
				}
			}
		}
		else 
		{
			FS_TRACE_WARN("Not Dict,Ingore Item(%d)",i);
		}
	}
}





/* attr position */
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setPosition,getPosition,Vector3);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setPositionX,getPositionX,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setPositionY,getPositionY,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setPositionZ,getPositionZ,float);

/* attr scale */
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setScale,getScale,Vector3);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setScaleX,getScaleX,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setScaleY,getScaleY,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setScaleZ,getScaleZ,float);

/* attr rotate */
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setRotate,getRotate,Vector3);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setRotateX,getRotateX,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setRotateY,getRotateY,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setRotateZ,getRotateZ,float);


FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setVisible,getVisible,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setVisibles,getVisibles,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setZorder,getZorder,float);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setTouchEnabled,getTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setTouchesEnabled,getTouchesEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setDispatchTouchEnabled,getDispatchTouchEnabled,bool);
FS_CLASS_ATTR_SET_GET_FUNCTION(Entity,setDispatchTouchesEnabled,getDispatchTouchesEnabled,bool);


static FsClass::FsAttributeDeclare S_Entity_Position_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",FsType::FT_F_1,NULL,Entity_setPositionX,Entity_getPositionX),
	FS_CLASS_ATTR_DECLARE("y",FsType::FT_F_1,NULL,Entity_setPositionY,Entity_getPositionY),
	FS_CLASS_ATTR_DECLARE("z",FsType::FT_F_1,NULL,Entity_setPositionZ,Entity_getPositionZ),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_Entity_Rotation_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",FsType::FT_F_1,NULL,Entity_setRotateX,Entity_getRotateX),
	FS_CLASS_ATTR_DECLARE("y",FsType::FT_F_1,NULL,Entity_setRotateY,Entity_getRotateY),
	FS_CLASS_ATTR_DECLARE("z",FsType::FT_F_1,NULL,Entity_setRotateZ,Entity_getRotateZ),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_Entity_Scale_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",FsType::FT_F_1,NULL,Entity_setScaleX,Entity_getScaleX),
	FS_CLASS_ATTR_DECLARE("y",FsType::FT_F_1,NULL,Entity_setScaleY,Entity_getScaleY),
	FS_CLASS_ATTR_DECLARE("z",FsType::FT_F_1,NULL,Entity_setScaleZ,Entity_getScaleZ),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};


static FsClass::FsAttributeDeclare S_Entity_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("position",FsType::FT_F_3,S_Entity_Position_SubAttr,Entity_setPosition,Entity_getPosition),
	FS_CLASS_ATTR_DECLARE("scale",FsType::FT_F_3,S_Entity_Scale_SubAttr,Entity_setScale,Entity_getScale),
	FS_CLASS_ATTR_DECLARE("rotate",FsType::FT_F_3,S_Entity_Rotation_SubAttr,Entity_setRotate,Entity_getRotate),
	FS_CLASS_ATTR_DECLARE("visible",FsType::FT_B_1,NULL,Entity_setVisible,Entity_getVisible),
	FS_CLASS_ATTR_DECLARE("visibles",FsType::FT_B_1,NULL,Entity_setVisibles,Entity_getVisibles),
	FS_CLASS_ATTR_DECLARE("touchEnabled",FsType::FT_B_1,NULL,Entity_setTouchEnabled,Entity_getTouchEnabled),
	FS_CLASS_ATTR_DECLARE("touchesEnabled",FsType::FT_B_1,NULL,Entity_setTouchesEnabled,Entity_getTouchesEnabled),
	FS_CLASS_ATTR_DECLARE("touchDispatchEnabled",FsType::FT_B_1,NULL,Entity_setDispatchTouchEnabled,Entity_getDispatchTouchEnabled),
	FS_CLASS_ATTR_DECLARE("touchesDispatchEnabled",FsType::FT_B_1,NULL,Entity_setDispatchTouchesEnabled,Entity_getDispatchTouchesEnabled),

	FS_CLASS_ATTR_DECLARE("children",FsType::FT_ARRAY,NULL,Entity_SetChildren,0),
	FS_CLASS_ATTR_DECLARE("zorder",FsType::FT_I_1,NULL,Entity_setZorder,Entity_getZorder),
	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)

};


FS_CLASS_IMPLEMENT_WITH_BASE(Entity,FsObject,Entity_NewInstance,S_Entity_Main_Attr);


NS_FS_END



















