/*************************************************************************/
/*  FsLog.h                                                              */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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

