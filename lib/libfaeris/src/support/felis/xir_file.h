/*************************************************************************/
/*  xir_file.h                                                           */
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


#ifndef _FAERY_XIR_SCRIPT_FILE_H_
#define _FAERY_XIR_SCRIPT_FILE_H_ 

#define FS_EOF (-1)
#include "sys/io/FsFile.h"

class XirFile
{
	public:
		XirFile(Faeris::FsFile* file);
		~XirFile();

	public:
		int nextChar();
		void mark()
		{
			m_mark=m_buf_pos;
		}
		void backToMark()
		{
			m_buf_pos=m_mark;
		}
		void forwardToMark()
		{
			m_begin=m_mark;
			m_buf_pos=m_mark;
		}

	protected:
		int loadData();

	private:
		Faeris::FsFile* m_file;
		char* m_buf;
		int m_buf_cap;
		int m_buf_size;
		int m_begin;
		int m_mark;
		int m_buf_pos;
};
#endif  /* _FAERY_XIR_SCRIPT_FILE_H_ */


