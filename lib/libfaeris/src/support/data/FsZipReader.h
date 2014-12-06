#ifndef _FS_ZIP_READER_H_
#define _FS_ZIP_READER_H_ 

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsFile;
class ZipReader:public FsObject
{
	public:
		static ZipReader* create(FsFile* file);
		static bool CheckType(FsFile* file);

	public:
		FsFile* takeFile(const char* filename);


	public:
		/* override FsObject */
		virtual const char* className();

	protected:
		ZipReader();
		virtual ~ZipReader();
		bool init(FsFile* file,void* unzfile);
		void destruct();

	private:
		void* m_unzfile;
		FsFile* m_stream;
};

NS_FS_END


#endif /*&_FS_ZIP_READER_H_*/













