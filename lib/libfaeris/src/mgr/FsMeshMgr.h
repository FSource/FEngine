#ifndef _FS_MESH_MGR_H_
#define _FS_MESH_MGR_H_

#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN
class Mesh;

class MeshMgr:public ResourceMgr 
{
	public:
		static MeshMgr* create();

	public:
		Mesh* loadMesh(const char* name);

	public:
		virtual const char* className();

	protected:
		MeshMgr();
		virtual ~MeshMgr();
};

NS_FS_END 





#endif /*_FS_MESH_MGR_H_*/


