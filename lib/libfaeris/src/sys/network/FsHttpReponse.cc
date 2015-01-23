/*************************************************************************/
/*  FsHttpReponse.cc                                                     */
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


#include "FsHttpReponse.h"

NS_FS_BEGIN


const char* HttpReponse::className()
{
	return "HttpReponse";
}


HttpReponse* HttpReponse::create()
{
	return new HttpReponse;
}

HttpReponse::HttpReponse()
{
}
HttpReponse::~HttpReponse()
{
}

void HttpReponse::setReponseCode(int code)
{
	m_code=code;
}

int HttpReponse::getReponseCode()
{
	return m_code;
}


void HttpReponse::appendData(uint8_t* data,int len)
{
	m_data.insert(m_data.end(),data,data+len);
}

void HttpReponse::setData(uint8_t* data,int len)
{
	m_data.clear();
	m_data.insert(m_data.end(),data,data+len);
}

void HttpReponse::getData(uint8_t** data,int* len)
{
	*len=m_data.size();
	if(m_data.size()==0)
	{
		*data=NULL;
	}
	else
	{
		*data=&m_data[0];
	}
}


void HttpReponse::appendError(uint8_t* buf,int len)
{
	m_error.insert(m_error.end(),buf,buf+len);
}


void HttpReponse::setErrorBuf(uint8_t* buf,int len)
{
	m_error.clear();
	m_error.insert(m_error.end(),buf,buf+len);
}

void HttpReponse::getErrorBuf(uint8_t** buf,int* len)
{

	static uint8_t empty_str[]="";
	*len=m_error.size();

	if(m_error.size()==0)
	{
		*buf=empty_str;
	}
	else
	{
		*buf=&m_error[0];
	}

}









NS_FS_END





















