/*************************************************************************/
/*  xir_scanner.h                                                        */
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


#ifndef _FAERY_XIR_SCRIPT_SCANNER_H_
#define _FAERY_XIR_SCRIPT_SCANNER_H_
#include <string>
#include "sys/io/FsVFS.h"
#include "xir_file.h"
#include "xir_state.h"
class XirScanner
{
	private:
		XirFile* m_file;
		int m_cur_token;
		int m_cur_line;
		std::string m_cur_string;
		XirState* m_begin_state;
		bool m_eof;
	public:
		XirScanner(Faeris::FsFile* file,XirState* begin_state);
		~XirScanner();
		int nextToken();
		int curToken(){return m_cur_token;}
		int curLine(){return m_cur_line;}
		const char* curString(){return m_cur_string.c_str();}
		const char* curTokenName();
};

#endif /*_FAERY_XIR_SCRIPT_SCANNER_H_*/

