#ifndef __VECTORUTILS_H
#define __VECTORUTILS_H

#include <objreader/objbasetypedefs.h>

/**
 * Normalize a vector.
 * Scales a vector so that its length is 1.0.
 * @param c Vector to normalize.
 */
void NormalizeVector(Vector3D *c);

/** 
 * Compute the dot product of two vectors
 * @return dot product of u and v
 */
float DotProduct(Vector3D *u, Vector3D *v);

/**
 * Compute the cross product of two vectors u and v
 * @param n - to return the cross product in
 */
void CrossProduct(Vector3D *u, Vector3D *v, Vector3D *n);

#endif /* __VECTORUTILS_H */
