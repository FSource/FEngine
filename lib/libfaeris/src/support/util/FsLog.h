#ifndef FS_UTIL_LOG_H_
#define FS_UTIL_LOG_H_
#include "FsMacros.h"

NS_FS_BEGIN 

class FsFile;
class FsLog
{
	public:
		void tagLog(const char* tag,const char* fmt,...);
		void log(const char* fmt,...);

		virtual ~FsLog(){}
	protected:
		virtual void logMsg(const char* log)=0;

};

class FileLog:public FsLog 
{
	public:
		static FileLog* getStdoutFileLog();
		static FileLog* ms_stdoutFileLog;
		static FileLog* create(const char* filename);
	public:
		virtual ~FileLog();
	protected:
		virtual void logMsg(const char* log);
	private:
		FileLog(FsFile* file);
	private:
		FsFile* m_file;
};


void FsUtil_TagLog(const char* tag,const char* msg,...);
void FsUtil_Log(const char* fmt,...);


NS_FS_END

#endif  /*FS_UTIL_LOG_H_*/

