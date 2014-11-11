#ifndef __LIB_OBJ_MODEL_H_
#define __LIB_OBJ_MODEL_H_
#include "LibObjCallBacks.h"

class LibObjTexCoord 
{
	public:
		LibObjTexCoord(float _u,float _v)
		{
			u=_u; v=_v;
		}

		LibObjTexCoord()
		{
			u=0; v=0;
		}

	public:
		float u;
		float v;
} ;


class LibObjVector3
{
	public:
		static float docProduct(const LibObjVector3& l,const LibObjVector3& r);
		LibObjVector3 crossProduct(const LibObjVector3& l,const LibObjVector3& r);

	public:
		LibObjVector3(float _x,float _y,float _z)
		{ 
			x=_x; y=_y; z=_z; 
		}

		LibObjVector3()
		{
			x=0; y=0; z=0; 
		}

	public:
		void normalize();


	public:
		float x;
		float y;
		float z;
};






typedef int (*LibObj_ReadIoFunc)(void* file,void* buf,int length);

class LibObjMeshContext
{
	public:
		void* m_scanner;
		void* m_file;
		LibObj_ReadIoFunc m_readio;
		void* m_userdata;
		LibObjMeshCallbacks* m_callbacks;
};


class LibObjMtlContext 
{
	public:
		void* m_scanner;
		void* m_file;
		LibObj_ReadIoFunc m_readio;
		void* m_userdata;
		LibObjMtlCallbacks* m_callbacks;
};




int LibObj_ParseMesh(void* file,LibObj_ReadIoFunc io_func,
		void* userdata,LibObjMeshCallbacks* ucb);

int LibObj_ParseMaterial(void* file,LibObj_ReadIoFunc io_func,
		void* userdata,LibObjMtlCallbacks* ucb);


#endif /* __LIB_OBJ_MODEL_H_*/




