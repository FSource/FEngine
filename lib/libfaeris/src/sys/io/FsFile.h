#ifndef _FAERY_IO_FSFILE_H_
#define _FAERY_IO_FSFILE_H_

#include <string>

#include "FsMacros.h"
#include "FsObject.h"
NS_FS_BEGIN

class FsFile:public FsObject
{
	public:
		enum
		{
			FS_SEEK_SET,
			FS_SEEK_CUR,
			FS_SEEK_END,
		};
		enum
		{
			FS_IO_RDONLY=0x1,
			FS_IO_WRONLY=0x2,
			FS_IO_RDWR=0x4,
			FS_IO_APPEND=0x8,
			FS_IO_CREATE=0x16,
			FS_IO_TRUNC=0x32
		};
	public:
		virtual long read(void* buf,long length)=0;
		virtual long write(const void* buf,long length)=0;
		virtual long seek(long offset,int where)=0;
		virtual int  close()=0;
		virtual long tell()=0;
		virtual long getLength();
		virtual ~FsFile(){}
		virtual const char* className();

		virtual const char* getFileName();
		virtual void setFileName(const char* name);

	public:
		long writeStr(const char* fmt,...);

	protected:
		std::string m_filename;

};

NS_FS_END

#endif  /*_FAERY_IO_FSFILE_H_*/

