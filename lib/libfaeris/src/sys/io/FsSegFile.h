/*************************************************************************/
/*  FsSegFile.h                                                          */
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


#ifndef _FS_SEG_FILE_H_
#define _FS_SEG_FILE_H_ 

#include "FsMacros.h"
#include "sys/io/FsFile.h"

NS_FS_BEGIN
class SegFile:public FsFile 
{
	public:
		static SegFile* create(FsFile* file,uint32_t offset,uint32_t length);

	public:
		/* override FsFile */
		virtual long read(void* buf,long length);
		virtual long write(const void* buf,long length);
		virtual long seek(long offset,E_FileSeek where);
		virtual int  close();
		virtual long tell();
		virtual long getLength();

	public: 
		/* override FsObject */
		virtual const char* className();

	protected:
		virtual ~SegFile();
		SegFile();
		void destruct();
		bool init(FsFile* file,uint32_t offset,uint32_t length);

	private:
		FsFile* m_stream;
		uint32_t m_offset;
		uint32_t m_length;
		uint32_t m_curpos;
};



NS_FS_END 



#endif /*_FS_SEG_FILE_H_*/

