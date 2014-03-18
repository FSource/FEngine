#include "FsHttpEngine.h"
#include "FsHttpRequest.h"
#include "FsHttpReponse.h"





#define FS_REQUEST_UNKOWN_ERROR "Unkown Error Happend"


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

	m_reqSem->post();
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
	m_reqSem->post();
}


void HttpEngine::run()
{
	while(true)
	{
		int ret=m_reqSem->wait();

		if(m_stop)
		{
			break;
		}

		if(ret==-1)  /* time  out */
		{
			continue;
		}


		m_reqMutex->lock();
		if(m_requests->size()==0)
		{
			m_reqMutex->unlock();
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
				reponse->setErrorBuf((uint8_t*)FS_REQUEST_UNKOWN_ERROR,sizeof(FS_REQUEST_UNKOWN_ERROR));
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

	m_reqSem=new Semaphore(0);
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



#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "platform/FsCurlHttp.cc"
#else 
	#error "Unsupport Platform For FsHttpEngine" 
#endif














