#ifndef _FS_ITRANSFORM_H_
#define _FS_ITRANSFORM_H_
#include "FsMacros.h"
#include "math/FsVector3.h"
#include "math/FsMatrix4.h"
#include "FsObject.h"

NS_FS_BEGIN

class ITransform :public FsObject
{
	public:

		virtual void setPosition(const Vector3& v)=0;
		virtual Vector3 getPosition()=0;


		virtual void setRotate(const Vector3& r)=0;
		virtual Vector3 getRotate()=0;

		virtual void setScale(const Vector3& v)=0;
		virtual Vector3 getScale()=0;

		virtual bool updateTransformMatrix()=0;
		virtual  Matrix4* getTransformMatrix()=0;

};


NS_FS_END

#endif /*_FS_ITRANSFORM_H_*/



