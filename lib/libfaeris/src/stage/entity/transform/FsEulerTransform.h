#ifndef _FS_EULER_TRANSFORM_H_
#define _FS_EULER_TRANSFORM_H_

#include "FsITransform.h"

NS_FS_BEGIN

class EulerTransform :public ITransform
{
	public:
		static EulerTransform* create();;

	public:
		void setPosition(const Vector3& v) FS_OVERRIDE;
		Vector3 getPosition() FS_OVERRIDE;


		void setRotate(const Vector3& r) FS_OVERRIDE;
		Vector3 getRotate() FS_OVERRIDE;

		void setScale(const Vector3& v) FS_OVERRIDE;
		Vector3 getScale() FS_OVERRIDE;

		bool updateTransformMatrix() FS_OVERRIDE; 
		Matrix4* getTransformMatrix() FS_OVERRIDE;

	public:
		const char* className() FS_OVERRIDE;

	protected:
		EulerTransform();
		virtual ~EulerTransform();

	protected:
		/* transform info */
		Vector3 m_translate;
		Vector3 m_rotate;
		Vector3 m_scale;


		bool m_transformMatrixDirty;
		Matrix4 m_transformMatrix;
};

NS_FS_END

#endif /*_FS_EULER_TRANSFORM_H_*/


