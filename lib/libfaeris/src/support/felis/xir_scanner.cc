#include<stdio.h>
#include<string>

#include "FsMacros.h"
#include "xir_scanner.h"
#include "xir_token.h"
#include "sl_state.h"


#define ASCII_NEWLINE 10

XirScanner::XirScanner(Faeris::FsFile* file,XirState* begin_state)
{
	m_file=new XirFile(file);
	m_begin_state=begin_state;
	m_cur_token=XT_UNKOWN;
	m_cur_line=1;
	m_eof=0;
}
XirScanner::~XirScanner()
{
	if(m_file)
	{
		delete m_file;
		m_file=NULL;
	}
}

int XirScanner::nextToken()
{
	XirFile* file=m_file;
	int line=m_cur_line;

	int finally_line=0;

	XirState* cur_state=m_begin_state;
	XirState* next_state=NULL;
	XirState* finnal_state=NULL;
	int finnal_token_size=0;

	int token_size=0;

	m_cur_string.clear();

	while(1)
	{
		int event=file->nextChar();

		//("event=%d",event);
		if(event==13) continue;  /* window use \n\r for newline, it is too boring here,i just ingore it  */
		if(event==(int) FS_EOF)
		{
			if(!m_eof)
			{
				event=ASCII_NEWLINE;
				m_eof=true;
			}
			else
			{
				if(token_size==0)
				{
				//	FS_TRACE_WARN("Toke EOF");
					m_cur_token=XT_EOF;
					break;
				}
				if(finnal_state==NULL)
				{
					file->mark();
					m_cur_token=XT_ERROR;
				}
				else
				{
					m_cur_token=finnal_state->token;
				}
				break;
			}
		}

		token_size++;
		m_cur_string.append(1,event);
		if(event==ASCII_NEWLINE)
		{
			line++;
		}

		next_state=cur_state->next(event);

		if(next_state==&Err_State)
		{
			if(finnal_state==NULL)
			{
				m_cur_token=XT_ERROR;
				file->mark();
			}
			else
			{
				m_cur_token=finnal_state->token;
			}
			break;
		}

		if(next_state->isFinnally())
		{
			finnal_state=next_state;
			file->mark();
			finnal_token_size=token_size;
			finally_line=line;
		}
		cur_state=next_state;
	}
	if(m_cur_token!=XT_ERROR&&m_cur_token!=XT_EOF)
	{
		m_cur_string.resize(finnal_token_size);
		m_cur_line=finally_line;
	}
	else
	{
		m_cur_line=line;
	}
	file->forwardToMark();
	return m_cur_token;
}


const char* XirScanner::curTokenName()
{
	return XirToken_Name(m_cur_token);
}

















