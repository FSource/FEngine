#ifndef _FS_BOX3_H_
#define _FS_BOX3_H_

#include "FsMacros.h"
#include "math/FsVector3.h"



NS_FS_BEGIN 

class Box3D
{
	public:
		Box3D();
		Box3D(const Vector3f& _min,const Vector3f& _max);

	public:
		void set(const Vector3f& _min,const Vector3f& _max);
		void setFromCenterAndSize(const Vector3f& center,const Vector3f& size);
		Vector3f center();
		Vector3f size() { return max.sub(min); }
		bool contain(const Box3D& box);
		bool intersection(const Box3D&  box ) ;


		/*
		Box3D intersect( const Box3D& box ) 
		{
			Vector3f t_min=Math::max(min,box.min);
			Vector3f t_max=Math::min(max,box.max);

			return Box3D(t_min,t_max);

		}

		Box3D union( const Box3D& box ) 
		{
			Vector3f t_min=Math::min(min,box.min);
			Vector3f t_max=Math::max(max,box.max);
			return Box3D(t_min,t_max);
		}
		*/


	public:
		Vector3f min;
		Vector3f max;
};



NS_FS_END 


#endif /*_FS_BOX3_H_*/



