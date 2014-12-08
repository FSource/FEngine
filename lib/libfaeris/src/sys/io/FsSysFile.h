#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_

#include "FsMacros.h"
#include "FsFile.h"


#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX) ||FS_PLATFORM_OS(FS_OS_ANDROID) ||FS_PLATFORM_OS(FS_OS_OSX)
	#include<stdio.h>
	typedef FILE* SysFilePlateform ;
#else 
	#error "Error Platform For SysFile"
#endif 


NS_FS_BEGIN
class SysFile:public FsFile 
{
	public:
		static SysFile* create(const char* name,uint mode=FsFile::FS_IO_RDONLY);
		static SysFile* getStdout();
		static SysFile* getStderr();
		static SysFile* getStdin();

	private:
		static SysFile* ms_stdout;
		static SysFile* ms_stdin;
		static SysFile* ms_stderr;
	public:
		virtual long read(void* buf,long length);
		virtual long write(const void* buf,long length);
		virtual long seek(long offset,E_FileSeek where);
		virtual int close();
		virtual long tell();
		virtual ~SysFile();
		virtual const char* className();
	protected:
		SysFile(SysFilePlateform f){m_platfromFile=f;}
	private:
		SysFilePlateform m_platfromFile;
};
NS_FS_END

#endif  /*_FAERY_SYS_FILE_H_*/


