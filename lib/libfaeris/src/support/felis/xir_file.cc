/*************************************************************************/
/*  xir_file.cc                                                          */
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


#include <stdio.h>
#include <string.h>

#include "FsMacros.h"
#include "xir_file.h"
#define LEX_FILE_DEFAULT_SIZE 64


XirFile::XirFile(Faeris::FsFile* f)
{

	m_file=f;
	m_file->addRef();
	m_buf= new char[LEX_FILE_DEFAULT_SIZE];
	m_buf_cap=LEX_FILE_DEFAULT_SIZE;
	m_buf_size=0;
	m_begin=0;
	m_mark=0;
	m_buf_pos=0;
}
XirFile::~XirFile()
{
	if(m_buf)
	{
		delete[] m_buf;
		m_buf=0;
	}
	m_file->decRef();
}
int XirFile::nextChar()
{
	if(m_buf_pos>=m_buf_size)
	{
		if(loadData()==0)
		{
			return FS_EOF;
		}
	}
	return m_buf[m_buf_pos++];
}

int XirFile::loadData()
{
	//FS_TRACE_INFO("loadData");
	int readbyte;
	if(m_buf_size==0)
	{
		readbyte=m_file->read(m_buf,LEX_FILE_DEFAULT_SIZE);
		m_buf_size=readbyte;
		return readbyte;
	}

	int begin=m_begin;
	int mark=m_mark;
	int read_pos=m_buf_pos;

	int buf_used=m_buf_size-begin;
	int buf_free=m_buf_cap-buf_used;

	if(buf_free<LEX_FILE_DEFAULT_SIZE/2)
	{

		char* new_buf=new char[m_buf_cap*2];
		memcpy(new_buf,m_buf+begin,buf_used);
		delete[] m_buf;
		m_buf=new_buf;
		m_buf_cap=m_buf_cap*2;
	}
	else if(begin!=0)
	{
		int i;
		char* buf=m_buf;
		for(i=0;i<buf_used;i++)
		{
			buf[i]=buf[i+begin];
		}
	}

	m_begin=0;
	m_mark=mark-begin;
	m_buf_pos=read_pos-begin;

	readbyte=m_file->read(m_buf+buf_used,m_buf_cap-buf_used);
	m_buf_size=buf_used+readbyte;
	return readbyte;
}





















