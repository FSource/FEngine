/*************************************************************************/
/*  FsFile.h                                                             */
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


#ifndef _FAERY_IO_FSFILE_H_
#define _FAERY_IO_FSFILE_H_

#include <string>

#include "FsMacros.h"
#include "FsObject.h"
#include "FsEnums.h"


NS_FS_BEGIN

class FsFile:public FsObject
{
	public:
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
		virtual long seek(long offset,E_FileSeek where)=0;
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

