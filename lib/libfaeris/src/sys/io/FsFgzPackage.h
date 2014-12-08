#ifndef _FS_FGZ_PACKAGE_H_
#define _FS_FGZ_PACKAGE_H_

#include "FsMacros.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsFile.h"

NS_FS_BEGIN
class FgzReader;
class FgzPackage:public Package
{
	public:
		static FgzPackage* create(FsFile* file);

	public:
		/* override Package */
		virtual FsFile* takeBlock(const char* filename);

		/* override FsObject */
		virtual const char* className();

	protected:
		bool init(FsFile* file);
		FgzPackage();
		virtual ~FgzPackage();
	public:
		FgzReader* m_reader;
};



NS_FS_END



#endif /*_FS_FGZ_PACKAGE_H_*/

