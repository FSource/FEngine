#ifndef _FS_SCENE_NODE_INL_
#define _FS_SCENE_NODE_INL_


inline void Entity::getPosition(float* x,float* y,float* z)
{
	Vector3 t=m_transform->getPosition();
	*x=t.x;
	*y=t.y;
	*z=t.z;
}

inline float Entity::getPositionX()
{
	return m_transform->getPosition().x;
}
inline float Entity::getPositionY()
{
	return m_transform->getPosition().y;
}

inline float Entity::getPositionZ()
{
	return m_transform->getPosition().z;
}


inline Vector3 Entity::getScale()
{
	return m_transform->getScale();
}

inline float Entity::getScaleX()
{
	return m_transform->getScale().x;
}
inline float Entity::getScaleY()
{
	return m_transform->getScale().y;
}

inline float Entity::getScaleZ()
{
	return m_transform->getScale().z;
}



inline float Entity::getRotateX()
{
	return m_transform->getRotate().x;
}

inline float Entity::getRotateY()
{
	return m_transform->getRotate().y;
}

inline float Entity::getRotateZ()
{
	return m_transform->getRotate().z;
}






inline void Entity::rotate(float rx,float ry,float rz)
{
	Vector3 r=m_transform->getRotate();
	r.x+=rx;
	r.y+=ry;
	r.z+=rz;
	setRotate(r);
}
inline void Entity::rotateX(float v)
{

	Vector3 r=m_transform->getRotate();
	r.x+=v;
	setRotate(r);

}
inline void Entity::rotateY(float v)
{
	Vector3 r=m_transform->getRotate();
	r.y+=v;
	setRotate(r);
}

inline void Entity::rotateZ(float v)
{
	Vector3 r=m_transform->getRotate();
	r.z+=v;
	setRotate(r);
}


inline void Entity::scale(float sx,float sy,float sz)
{
	Vector3 s=m_transform->getScale();
	s.x*=sx;
	s.y*=sy;
	s.z*=sz;
	setScale(s);
}

inline void Entity::scaleX(float v)
{
	Vector3 s=m_transform->getScale();
	s.x*=v;
	setScale(s);
}

inline void Entity::scaleY(float v)
{
	Vector3 s=m_transform->getScale();
	s.y*=v;
	setScale(s);
}

inline void Entity::scaleZ(float v)
{
	Vector3 s=m_transform->getScale();
	s.z*=v;
	setScale(s);
}


inline void Entity::move(float tx,float ty,float tz)
{

	Vector3 t=m_transform->getPosition();
	t.x+=tx;
	t.y+=ty;
	t.z+=tz;

	setPosition(t);
}

inline void Entity::moveX(float v)
{
	Vector3 t=m_transform->getPosition();
	t.x+=v;

	setPosition(t);
}

inline void Entity::moveY(float v)
{
	Vector3 t=m_transform->getPosition();
	t.y+=v;

	setPosition(t);
}

inline void Entity::moveZ(float v)
{
	Vector3 t=m_transform->getPosition();
	t.z+=v;

	setPosition(t);
}


inline void Entity::setRotate(float rx,float ry,float rz)
{
	setRotate(Vector3(rx,ry,rz));
}

inline void Entity::setRotateX(float v)
{

	Vector3 r=m_transform->getRotate();
	r.x=v;
	setRotate(r);
}
inline void Entity::setRotateY(float v)
{
	Vector3 r=m_transform->getRotate();
	r.y=v;
	setRotate(r);
}
inline void Entity::setRotateZ(float v)
{
	Vector3 r=m_transform->getRotate();
	r.z=v;

	setRotate(r);
}

inline void Entity::setScale(float sx,float sy,float sz)
{
	setScale(Vector3(sx,sy,sz));
}
inline void Entity::setScaleX(float v)
{
	Vector3 s=m_transform->getScale();
	s.x=v;
	setScale(s);
}

inline void Entity::setScaleY(float v)
{
	Vector3 s=m_transform->getScale();
	s.y=v;
	setScale(s);
}

inline void Entity::setScaleZ(float v)
{
	Vector3 s=m_transform->getScale();
	s.z=v;
	setScale(s);
}






inline void Entity::setPosition(float tx,float ty,float tz)
{
	setPosition(Vector3(tx,ty,tz));
}
inline void Entity::setPositionX(float v)
{
	Vector3 t=m_transform->getPosition();
	t.x=v;
	setPosition(t);
}

inline void Entity::setPositionY(float v)
{
	Vector3 t=m_transform->getPosition();
	t.y=v;
	setPosition(t);
}

inline void Entity::setPositionZ(float v)
{
	Vector3 t=m_transform->getPosition();
	t.z=v;
	setPosition(t);
}



/* world transform */

inline Vector3  Entity::getPositionInWorld()
{
	if(m_parent==NULL)
	{
		return m_transform->getPosition();
	}
	else 
	{
		updateWorldMatrix();
		return Vector3(m_worldMatrix.m03,m_worldMatrix.m13,m_worldMatrix.m23);
	}
}

inline void Entity::getPositionInWorld(float* x,float* y,float* z)
{
	Vector3 ret=getPositionInWorld();
	*x=ret.x;
	*y=ret.y;
	*z=ret.z;
}


#endif /*_FS_SCENE_NODE_INL_*/

















