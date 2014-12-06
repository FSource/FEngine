#ifndef _FS_HTTP_ENGING_H_
#define _FS_HTTP_ENGING_H_ 
#include "FsMacros.h"
#include "FsObject.h"
#include "sys/thread/FsThread.h"
#include "sys/thread/FsMutex.h"
#include "sys/thread/FsSemaphore.h"
#include "support/util/FsArray.h"

NS_FS_BEGIN
class HttpRequest;
class HttpReponse;

HttpReponse* FsHttp_HandlePost(HttpRequest* request,int max_connect_time,int max_read_time);
HttpReponse* FsHttp_HandleGet(HttpRequest* request,int max_connect_time,int max_read_time);



class HttpEngine:public FsObject,public Thread
{
	public:
		static HttpEngine* create();


	public:
		void send(HttpRequest* request);
		void clear();
		void stop();

	public:
		virtual void run();

	public:
		/* override FsObject */
		virtual const char* className();


	protected:
		HttpEngine();
		virtual ~HttpEngine();
		bool init();
		void destruct();


	private:
		FsArray* m_requests;
		Semaphore* m_reqSem;
		Mutex* m_reqMutex;

		int m_stop;
		int m_maxConnectTime;
		int m_maxReadTime;
};

NS_FS_END 

#endif /* _FS_HTTP_ENGING_H_ */

