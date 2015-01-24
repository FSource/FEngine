/*************************************************************************/
/*  FsHttpRequest.cc                                                     */
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


#include <string.h>

#include "FsHttpRequest.h"
#include "FsHttpReponse.h"
#include "FsGlobal.h"
#include "scheduler/FsTask.h"
#include "scheduler/FsScheduler.h"

NS_FS_BEGIN

class HttpSyncTask:public Task 
{
	public:
		static HttpSyncTask* create(HttpRequest* request,HttpReponse* reponse)
		{
			return new HttpSyncTask(request,reponse);
		}
	
	public:
		virtual void run()
		{
			m_request->onSyncReponse(m_reponse);
		}
	protected:
		HttpSyncTask(HttpRequest* request,HttpReponse* reponse)
		{
			m_request=request;
			m_reponse=reponse;
			m_request->addRef();
			m_reponse->addRef();
		}
		~HttpSyncTask()
		{
			m_request->decRef();
			m_reponse->decRef();
		}

	private:
		HttpRequest* m_request;
		HttpReponse* m_reponse;
};

const char* HttpRequest::className()
{
	return "HttpRequest";
}

HttpRequest* HttpRequest::create()
{
	return new HttpRequest();
}



void HttpRequest::setUrl(const char* url)
{
	m_url=url;
}

const char* HttpRequest::getUrl()
{
	return m_url.c_str();
}

void HttpRequest::setMethod(int method)
{
	m_method=method;
}

int HttpRequest::getMethod()
{
	return m_method;
}


void HttpRequest::setVersion(int version)
{
	m_version=version;
}

int HttpRequest::getVersion()
{
	return m_version;
}

void HttpRequest::addHeader(const char* header)
{
	m_headers.insert(header);
}

void HttpRequest::removeHeader(const char* header)
{
	m_headers.erase(header);
}

void HttpRequest::clearHeader()
{
	m_headers.clear();
}

int HttpRequest::getHeaderNu()
{
	return m_headers.size();
}


void HttpRequest::setData(const uint8_t* data,int data_len)
{
	m_data.clear();
	m_data.insert(m_data.end(),data,data+data_len);
}

void HttpRequest::getData(uint8_t** data,int* data_len)
{
	*data_len=m_data.size();
	if(*data_len==0)
	{
		*data=NULL;
	}
	else 
	{
		*data=&m_data[0];
	}

}

void HttpRequest::setData(const char* data)
{
	int len=strlen(data);
	setData((uint8_t*)data,len);
}




HttpRequest::HeaderSetIterator HttpRequest::headerBegin()
{
	return m_headers.begin();
}

HttpRequest::HeaderSetIterator HttpRequest::headerEnd()
{
	return m_headers.end();
}


void HttpRequest::onReponse(HttpReponse* data)
{
	HttpSyncTask* task=HttpSyncTask::create(this,data);
	Scheduler* schedule=Global::scheduler();
	if(schedule)
	{
		schedule->runASyncTask(task);
	}
}

void HttpRequest::onSyncReponse(HttpReponse* data)
{

}

HttpRequest::HttpRequest()
{
	m_method=METHOD_GET;
	m_version=VERSION_1_1;
}

HttpRequest::~HttpRequest()
{

}


NS_FS_END 
