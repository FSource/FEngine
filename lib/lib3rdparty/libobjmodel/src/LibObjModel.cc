#include <math.h>
#include "LibObjModel.h" 

#define EPSILON (1e-8)


float LibObjVector3::docProduct(const LibObjVector3& l,const LibObjVector3& r)
{
	return l.x*r.x + 
		   l.y*r.y + 
		   l.z*r.z;
}



LibObjVector3  LibObjVector3::crossProduct(const LibObjVector3& u,const LibObjVector3& v)
{
	LibObjVector3 n;

	n.x = u.y*v.z - u.z*v.y;
	n.y = u.z*v.x - u.x*v.z;
	n.z = u.x*v.y - u.y*v.x;

	return n;

}


void LibObjVector3::normalize()
{
	float l, m;
	l=(float)sqrt(x*x + y*y + z*z);

	if (fabs(l) < EPSILON) {
		if ((x>=y) && (x>=z)) {
			x=1.0f;
			y=z=0.0f;
		}
		else
			if (y>=z) {
				y=1.0f;
				x=z=0.0f;
			}
			else {
				z=1.0f;
				x=y=0.0f;
			}
	}
	else {
		m=1.0f/l;
		x*=m;
		y*=m;
		z*=m;
	}
}




