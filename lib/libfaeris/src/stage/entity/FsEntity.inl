#ifndef _FS_SCENE_NODE_INL_
#define _FS_SCENE_NODE_INL_


inline void Entity::rotate(float rx,float ry,float rz)
{
	m_rotate.x+=rx;
	m_rotate.y+=ry;
	m_rotate.z+=rz;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;

}
inline void Entity::rotateX(float r)
{
	m_rotate.x+=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::rotateY(float r)
{
	m_rotate.y+=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::rotateZ(float r)
{
	m_rotate.z+=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}

inline void Entity::scale(float sx,float sy,float sz)
{
	m_scale.x*=sx;
	m_scale.y*=sy;
	m_scale.z*=sz;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::scaleX(float s)
{
	m_scale.x*=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::scaleY(float s)
{
	m_scale.y*=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::scaleZ(float s)
{
	m_scale.z*=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}

inline void Entity::move(float tx,float ty,float tz)
{
	m_translate.x+=tx;
	m_translate.y+=ty;
	m_translate.z+=tz;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;

}
inline void Entity::moveX(float t)
{
	m_translate.x+=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::moveY(float t)
{
	m_translate.y+=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::moveZ(float t)
{
	m_translate.z+=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setRotate(const Vector3& r)
{
	setRotate(r.x,r.y,r.z);
}

inline void Entity::setRotate(float rx,float ry,float rz)
{
	m_rotate.set(rx,ry,rz);
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setRotateX(float r)
{
	m_rotate.x=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setRotateY(float r)
{
	m_rotate.y=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setRotateZ(float r)
{
	m_rotate.z=r;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}

inline void Entity::setScale(const Vector3& scale)
{
	m_scale=scale;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setScale(float sx,float sy,float sz)
{
	m_scale.set(sx,sy,sz);
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setScaleX(float s)
{
	m_scale.x=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setScaleY(float s)
{
	m_scale.y=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setScaleZ(float s)
{
	m_scale.z=s;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}

inline void Entity::setPosition(const Vector3& pos)
{
	m_translate=pos;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setPosition(float tx,float ty,float tz)
{
	m_translate.set(tx,ty,tz);
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setPositionX(float t)
{
	m_translate.x=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setPositionY(float t)
{
	m_translate.y=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}
inline void Entity::setPositionZ(float t)
{
	m_translate.z=t;
	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
}


/* world transform */

inline Vector3  Entity::getPositionInWorld()
{
	if(m_parent==NULL)
	{
		return m_translate;
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

















