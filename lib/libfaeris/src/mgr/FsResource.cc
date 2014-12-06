#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"

NS_FS_BEGIN
Resource::Resource()
{
	m_mgr=NULL;
	m_resourceName=NULL;
}


void Resource::setMgr(ResourceMgr* mgr)
{
	m_mgr=mgr;
}

void Resource::setResourceName(FsString* name)
{
	FS_SAFE_ASSIGN(m_resourceName,name);

}
FsString* Resource::getResourceName()
{
	return m_resourceName;
}

Resource::~Resource() 
{
	assert(m_mgr==NULL);
	FS_SAFE_DEC_REF(m_resourceName);
}

NS_FS_END

