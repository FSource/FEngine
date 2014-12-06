#ifndef _FS_ZIP_PACKAGE_H_
#define _FS_ZIP_PACKAGE_H_

#include "FsMacros.h"
#include "io/FsPackage.h"

NS_FS_BEGIN
class ZipPackageInternal;
class ZipPackage:public Package 
{
	public:
		static ZipPackage* create(FsFile* file);

	public:
		/* inherite Package */
		virtual FsFile* getBlock(const char* filename);

		/* inherite FsObject */
		virtual const char* className();

	protected:
		bool init(FsFile* file);
		ZipPackage();
		virtual ~ZipPackage();

	public:
		ZipPackageInternal* m_imp;
		FsFile* m_stream;
};

NS_FS_END 


#endif /*_FS_ZIP_PACKAGE_H_*/

