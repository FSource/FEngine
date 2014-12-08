#include "FsBox3D.h"

NS_FS_BEGIN


Box3D::Box3D()
{
	min.set(0,0,0);
	max.set(0,0,0);
}

Box3D::Box3D(const Vector3f& _min,const Vector3f& _max)
{
	min=_min;
	max=_max;
}

void Box3D::set(const Vector3f& _min,const Vector3f& _max)
{
	min=_min; max=_max;
}
void Box3D::setFromCenterAndSize( const Vector3f& center,const Vector3f& size)
{
	Vector3f half_size=size.scale(0.5);

	min=center.sub(half_size);
	max=center.add(half_size);
}


Vector3f Box3D::center()
{
	return min.add(max).scale(0.5);
}

bool Box3D::contain(const Box3D& box)
{

	if ( ( min.x <= box.min.x ) && ( box.max.x <= max.x ) &&
			( min.y <= box.min.y ) && ( box.max.y <= max.y ) &&
			( min.z <= box.min.z ) && ( box.max.z <=max.z ) ) 
	{

		return true;

	}

	return false;

}

bool Box3D::intersection(const Box3D& box)
{
	if ( box.max.x < min.x || box.min.x > max.x ||
			box.max.y < min.y || box.min.y > max.y ||
			box.max.z < min.z || box.min.z > max.z ) 
	{

		return false;

	}

	return true;
}

NS_FS_END 

