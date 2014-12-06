#include "FsMacros.h"
#include "support/util/FsLog.h"
#include "FsConfig.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"
#include <stdarg.h>

NS_FS_BEGIN
static FsLog* s_global_log=NULL;


static void init_global_log()
{
	if(s_global_log==NULL)
	{
#if FS_CONFIG(FS_LOG_FILE)
		s_global_log=FileLog::Create(FS_CONFIG(LOG_FILE_NAME));
#elif FS_CONFIG(FS_LOG_STDIO)
		s_global_log=FileLog::getStdoutFileLog();
#else
		s_global_log=FileLog::getStdoutFileLog();
#endif
	}
}


void FsUtil_TagLog(const char* tag,const char* fmt,...)
{
	init_global_log();

	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	s_global_log->log("%s",buf);
}

void FsUtil_Log(const char* fmt,...)
{
	init_global_log();
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	s_global_log->log("%s",buf);
}

NS_FS_END 

