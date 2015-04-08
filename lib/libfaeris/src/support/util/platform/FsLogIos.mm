#include <stdarg.h>
#include <Foundation/NSObjCRuntime.h>

#include "FsMacros.h"
#include "FsConfig.h"
#include "support/util/FsLog.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsLog.h"


NS_FS_BEGIN

static void FsLog_FormatLogBuffer(char* buf,ulong size,
                                  const char* fmt,va_list ap)
{
    uint msg_len=vsnprintf(buf,size-1,fmt,ap);
    buf[msg_len]='\0';
}

static void FsLog_FormatLogTagBuffer(char* buf,ulong size,
                                     const char* tag,const char* fmt,
                                     va_list ap)
{
    uint fmtbyte=snprintf(buf,size-1,"%s:",tag);
    uint msg_len=vsnprintf(buf+fmtbyte,size-1-fmtbyte,fmt,ap);
    buf[fmtbyte+msg_len]='\0';
    
}
void FsUtil_TagLog(const char* tag,const char* fmt,...)
{


	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	NSLog(@"%s:%s",tag,buf);
}

void FsUtil_Log(const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	NSLog(@"%s",buf);
}

NS_FS_END 
