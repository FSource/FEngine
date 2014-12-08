#ifndef _FS_FGZ_READER_H_
#define _FS_FGZ_READER_H_

#include "FsMacros.h"
#include "FsObject.h"


#define FS_FGZ_STORE 	0x0 
#define FS_FGZ_DEFLATE  0x10
#define FS_FGZ_LZMA   	0x20 


#define FS_FGZ_CRC32   0xFAE

#define FS_FGZ_MAGIC_NU       {0,'F','G','Z','I','P','1',0}
#define FS_FGZ_FILE_MAGIC_NU  {0,'F','G','F','I','L','E',0}


#define FS_DEFLATE_DEFAULT_LEVEL  6




NS_FS_BEGIN
class FsFile;
class FsDict;
class FgzReader:public FsObject 
{
	public:
		static FgzReader* create(FsFile* file);
		static bool CheckType(FsFile* file);

	public:
		FsFile* takeFile(const char* filename);

	public:
		virtual const char* className();


	public:
		FgzReader();
		virtual ~FgzReader();
		bool init(FsFile* file);
		void destruct();

	private:
		FsDict* m_files;
		FsFile* m_stream;
};


NS_FS_END 



#endif /*_FS_FGZ_READER_H_*/

