/*************************************************************************/
/*  xir_parser.h                                                         */
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


#ifndef _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#define _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#include <vector>

#include "FsMacros.h"
#include "sys/io/FsFile.h"
#include "xir_scanner.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsString.h"
#include "support/util/FsScriptUtil.h"



class XirParser
{
	public:
		static Faeris::FsDict* create(Faeris::FsFile* file);
};

class YYParserParm
{
	public:
		XirScanner* m_lex;
		Faeris::FsDict* m_root;
		bool m_delimiter;
		Faeris::FsArray* m_pending_obs;
	public:
		YYParserParm(XirScanner* lex)
		{
			m_lex=lex;
			m_root=NULL;
			m_delimiter=false;
			m_pending_obs=new Faeris::FsArray;
		}
		void releasePendingNode()
		{
			m_pending_obs->decRef();
		}
		Faeris::FsString* newStringObject()
		{
			char* esc_str=Faeris::ScriptUtil::escapeStringToOrign(m_lex->curString());
			Faeris::FsString* ob=NULL;
			if(esc_str==NULL)
			{
				ob=new Faeris::FsString(m_lex->curString());
			}
			else 
			{
				ob=new Faeris::FsString(esc_str);
				delete[] esc_str;
			}
			m_pending_obs->push(ob);
			return ob;
		}
		Faeris::FsDict* newDictObject()
		{
			Faeris::FsDict* ob=new Faeris::FsDict();
			m_pending_obs->push(ob);
			return ob;
		}

		Faeris::FsArray* newArrayObject()
		{
			Faeris::FsArray* ob=new Faeris::FsArray;
			m_pending_obs->push(ob);
			return ob;
		}

		void setRoot(Faeris::FsDict* root)
		{
			FS_SAFE_ASSIGN(m_root,root);
		}

		Faeris::FsDict* getRoot()
		{
			return m_root;
		}

		~YYParserParm()
		{
			if(m_root) m_root->decRef();
			releasePendingNode();
		}
};
#define YACC_SHIFT_BASE  258

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm

int yylex(void* lvap,void* parm);
int yyparse(void* parm);
void xir_parse_err(const char* ,void* YYPARSE_PARAM);

#define yyerror(msg)  xir_parse_err(msg,YYPARSE_PARAM)

#endif 

