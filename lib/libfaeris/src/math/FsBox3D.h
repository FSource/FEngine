#ifndef _FS_BOX3_H_
#define _FS_BOX3_H_

#include "FsMacros.h"


NS_FS_BEGIN 

class Box3D
{

	public:
		Box3D(const Vector3f& min,const Vector3f& max)

	public:
		void set(const Vector3f& _min,const Vector3f& _max)
		{
			min=_min; max=_max;
		}

		void setFromCenterAndSize(const Vector3f& center,const Vector3f& size)
		{
			Vector3f half_size=size.scale(0.5);

			min=center.sub(half_size);
			max=center.add(half_size);
		}

		Vector3f center()
		{
			return min.add(max).scale(0.5);
		}

		Vector3f size()
		{
			return max.sub(min);
		}

		bool contain(const Box3D& box)
		{

			if ( ( min.x <= box.min.x ) && ( box.max.x <= max.x ) &&
				 ( min.y <= box.min.y ) && ( box.max.y <= max.y ) &&
				 ( min.z <= box.min.z ) && ( box.max.z <=max.z ) ) 
			{

				return true;

			}

			return false;

		}

		bool intersection(const Box3D&  box ) 
		{
			if ( box.max.x < min.x || box.min.x > max.x ||
				 box.max.y < min.y || box.min.y > max.y ||
			 	 box.max.z < min.z || box.min.z > max.z ) 
			{

				return false;

			}

			return true;
		}


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



