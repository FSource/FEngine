#ifndef _FS_MATERIAL3D_MGR_H_
#define _FS_MATERIAL3D_MGR_H_

#include"mgr/FsResourceMgr.h"

NS_FS_BEGIN
class Material3D;

class Material3DMgr:public ResourceMgr
{
	public:
		static Material3DMgr* create();

	public:
		Material3D* loadMaterial3D(const char* filename);

	public:
		virtual const char* className() FS_OVERRIDE;

	protected:
		Material3DMgr();
		virtual ~Material3DMgr();
};



NS_FS_END




#endif /*_FS_MATERIAL3D_MGR_H_*/

