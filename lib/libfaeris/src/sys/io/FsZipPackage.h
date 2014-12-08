#ifndef _FS_ZIP_PACKAGE_H_
#define _FS_ZIP_PACKAGE_H_

#include "FsMacros.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsFile.h"

NS_FS_BEGIN

class ZipReader;

class ZipPackage:public Package 
{
	public:
		static ZipPackage* create(FsFile* file);

	public:
		/* inherite Package */
		virtual FsFile* takeBlock(const char* filename);

		/* inherite FsObject */
		virtual const char* className();

	protected:
		bool init(FsFile* file);
		ZipPackage();
		virtual ~ZipPackage();

	public:
		ZipReader* m_reader;
};

NS_FS_END 


#endif /*_FS_ZIP_PACKAGE_H_*/

