/*************************************************************************/
/*  FsEntity.cc                                                          */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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
	updateAnimation(dt);
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
	m_visible=1;
	m_visibles=1;
	m_zorderDirty=1;

	m_zorlder=0.0f;

	m_parent=NULL;
	m_layer=NULL;

	m_chirdren=FsSlowArray::create();
	FS_NO_REF_DESTROY(m_chirdren);

	onUpdate=nullptr;
	onDraw=nullptr;
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
		n->m_parent->removeChild(n);
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

int Entity::getChildNu()
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




void Entity::removeChild(Entity* n)
{
	if(n->m_parent!=this)
	{
		FS_TRACE_WARN("Entity Is Not A Chirld Of This");
		return;
	}
	n->setLayer(NULL);
	n->setParent(NULL);
	m_chirdren->remove(n);

}

void Entity::clearChild()
{
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
		m_parent->removeChild(this);
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


void Entity::setRotate(const Vector3& r)
{
	m_transform->setRotate(r);
	m_worldMatrixDirty=1;
}

Vector3 Entity::getRotate()
{
	return m_transform->getRotate();
}

void Entity::setScale(const Vector3& scale)
{
	m_transform->setScale(scale);
	m_worldMatrixDirty=1;
}


void Entity::setPosition(const Vector3& pos)
{
	m_transform->setPosition(pos);
	m_worldMatrixDirty=1;
}

Vector3 Entity::getPosition()
{
	return m_transform->getPosition();
}

/***  Use For Entity FsClass Attribute  **/
static Entity* S_Entity_NewInstance(FsDict* attr)
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


static FsClass::FsAttributeDeclare S_Entity_Position_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",E_FsType::FT_F_1,NULL,Entity_setPositionX,Entity_getPositionX),
	FS_CLASS_ATTR_DECLARE("y",E_FsType::FT_F_1,NULL,Entity_setPositionY,Entity_getPositionY),
	FS_CLASS_ATTR_DECLARE("z",E_FsType::FT_F_1,NULL,Entity_setPositionZ,Entity_getPositionZ),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_Entity_Rotation_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",E_FsType::FT_F_1,NULL,Entity_setRotateX,Entity_getRotateX),
	FS_CLASS_ATTR_DECLARE("y",E_FsType::FT_F_1,NULL,Entity_setRotateY,Entity_getRotateY),
	FS_CLASS_ATTR_DECLARE("z",E_FsType::FT_F_1,NULL,Entity_setRotateZ,Entity_getRotateZ),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

static FsClass::FsAttributeDeclare S_Entity_Scale_SubAttr[]={
	FS_CLASS_ATTR_DECLARE("x",E_FsType::FT_F_1,NULL,Entity_setScaleX,Entity_getScaleX),
	FS_CLASS_ATTR_DECLARE("y",E_FsType::FT_F_1,NULL,Entity_setScaleY,Entity_getScaleY),
	FS_CLASS_ATTR_DECLARE("z",E_FsType::FT_F_1,NULL,Entity_setScaleZ,Entity_getScaleZ),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};


static FsClass::FsAttributeDeclare S_Entity_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("position",E_FsType::FT_F_3,S_Entity_Position_SubAttr,Entity_setPosition,Entity_getPosition),
	FS_CLASS_ATTR_DECLARE("positionX",E_FsType::FT_F_1,NULL,Entity_setPositionX,Entity_getPositionX),
	FS_CLASS_ATTR_DECLARE("positionY",E_FsType::FT_F_1,NULL,Entity_setPositionY,Entity_getPositionY),
	FS_CLASS_ATTR_DECLARE("positionZ",E_FsType::FT_F_1,NULL,Entity_setPositionZ,Entity_getPositionZ),

	FS_CLASS_ATTR_DECLARE("scale",E_FsType::FT_F_3,S_Entity_Scale_SubAttr,Entity_setScale,Entity_getScale),
	FS_CLASS_ATTR_DECLARE("scaleX",E_FsType::FT_F_1,NULL,Entity_setScaleX,Entity_getScaleX),
	FS_CLASS_ATTR_DECLARE("scaleY",E_FsType::FT_F_1,NULL,Entity_setScaleY,Entity_getScaleY),
	FS_CLASS_ATTR_DECLARE("scaleZ",E_FsType::FT_F_1,NULL,Entity_setScaleZ,Entity_getScaleZ),



	FS_CLASS_ATTR_DECLARE("rotate",E_FsType::FT_F_3,S_Entity_Rotation_SubAttr,Entity_setRotate,Entity_getRotate),
	FS_CLASS_ATTR_DECLARE("rotateX",E_FsType::FT_F_1,NULL,Entity_setRotateX,Entity_getRotateX),
	FS_CLASS_ATTR_DECLARE("rotateY",E_FsType::FT_F_1,NULL,Entity_setRotateY,Entity_getRotateY),
	FS_CLASS_ATTR_DECLARE("rotateZ",E_FsType::FT_F_1,NULL,Entity_setRotateZ,Entity_getRotateZ),


	FS_CLASS_ATTR_DECLARE("visible",E_FsType::FT_B_1,NULL,Entity_setVisible,Entity_getVisible),
	FS_CLASS_ATTR_DECLARE("visibles",E_FsType::FT_B_1,NULL,Entity_setVisibles,Entity_getVisibles),

	FS_CLASS_ATTR_DECLARE("children",E_FsType::FT_ARRAY,NULL,Entity_SetChildren,0),
	FS_CLASS_ATTR_DECLARE("zorder",E_FsType::FT_I_1,NULL,Entity_setZorder,Entity_getZorder),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Entity,Animator,S_Entity_NewInstance,S_Entity_Main_Attr);


NS_FS_END



















