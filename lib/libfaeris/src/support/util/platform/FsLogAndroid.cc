#include <stdarg.h>
#include <android/log.h>

#include "FsMacros.h"
#include "FsConfig.h"
#include "support/util/FsLog.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN

void FsUtil_TagLog(const char* tag,const char* fmt,...)
{


	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	__android_log_print(ANDROID_LOG_DEBUG,tag,"%s",buf);
}

void FsUtil_Log(const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);
	__android_log_print(ANDROID_LOG_DEBUG,"INFO","%s",buf);
}

NS_FS_END 
