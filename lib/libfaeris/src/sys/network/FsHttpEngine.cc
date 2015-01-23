/*************************************************************************/
/*  FsHttpEngine.cc                                                      */
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
#include "FsHttpEngine.h"
#include "FsHttpRequest.h"
#include "FsHttpReponse.h"

#include "sys/thread/FsThread.h"
#include "sys/thread/FsMutex.h"
#include "sys/thread/FsConditionVariable.h"



static const char* FS_REQUEST_UNKOWN_ERROR ="Unkown Error Happend";


NS_FS_BEGIN

const char* HttpEngine::className()
{
	return FS_HTTP_ENGINE_CLASS_NAME;
}

HttpEngine* HttpEngine::create()
{
	HttpEngine* ret=new HttpEngine;
	//FS_TRACE_WARN("begin start http engine");
	ret->start();
	//FS_TRACE_WARN("end start http engine");
	return ret;
}


void HttpEngine::send(HttpRequest* request)
{
	m_reqMutex->lock();
	m_requests->push(request);
	m_reqMutex->unlock();

	m_reqSem->signal();
}

void HttpEngine::clear()
{
	m_reqMutex->lock();
	m_requests->clear();
	m_reqMutex->unlock();
}

void HttpEngine::stop()
{
	m_stop=true;
	m_reqSem->signal();
}


void HttpEngine::run()
{
	while(true)
	{
		FS_TRACE_WARN("HttpEngine Loop");
		if(m_stop)
		{
			break;
		}

		m_reqMutex->lock();

		if(m_requests->size()==0)
		{
			//FS_TRACE_WARN("Begin To Sleep");
			int ret=m_reqSem->wait(m_reqMutex);
			if(ret<0)
			{
				FS_TRACE_WARN("Wait Error");
				m_reqMutex->unlock();
			}
			else 
			{
				m_reqMutex->unlock();
			}
			continue;
		}
		else 
		{
			HttpRequest* request=(HttpRequest*)m_requests->get(0); 
			request->addRef();

			m_requests->remove((ulong)0);
			m_reqMutex->unlock();

			HttpReponse* reponse=NULL;
			switch(request->getMethod())
			{
				case HttpRequest::METHOD_GET:
					reponse=FsHttp_HandleGet(request,m_maxConnectTime,m_maxReadTime);
					break;
				case HttpRequest::METHOD_POST:
					reponse=FsHttp_HandlePost(request,m_maxConnectTime,m_maxReadTime);
					break;
				default:
					FS_TRACE_WARN("Unkown Or UnSupport Method Type");
			}
			if(reponse==NULL)
			{
				reponse=HttpReponse::create();
				reponse->setErrorBuf((uint8_t*)FS_REQUEST_UNKOWN_ERROR,strlen(FS_REQUEST_UNKOWN_ERROR));
				reponse->setReponseCode(0);
			}

			request->onReponse(reponse);

			request->decRef();
			reponse->autoDestroy();
		}

	}
}

HttpEngine::HttpEngine()
{
	init();
}

bool HttpEngine::init()
{
	m_requests=FsArray::create();
	FS_NO_REF_DESTROY(m_requests);

	m_reqSem=new ConditionVariable();
	m_reqMutex=new Mutex();
	m_stop=false;
	m_maxConnectTime=30;
	m_maxReadTime=60;
	return true;
}


void HttpEngine::destruct()
{
	stop(); /* signal thread to  stop */
	join(); /* wait thread to exit */

	FS_SAFE_DESTROY(m_requests);
	FS_SAFE_DELETE(m_reqSem);
	FS_SAFE_DELETE(m_reqMutex);
}


HttpEngine::~HttpEngine()
{
	destruct();
}

NS_FS_END 



#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_ANDROID)  || FS_PLATFORM_OS(FS_OS_OSX) 
	#include "platform/FsCurlHttp.cc"
#else 
	#error "Unsupport Platform For FsHttpEngine" 
#endif














