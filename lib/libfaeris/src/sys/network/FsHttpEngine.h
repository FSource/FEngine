/*************************************************************************/
/*  FsHttpEngine.h                                                       */
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


#ifndef _FS_HTTP_ENGING_H_
#define _FS_HTTP_ENGING_H_ 
#include "FsMacros.h"
#include "FsObject.h"
#include "support/util/FsArray.h"
#include "sys/thread/FsThread.h"

NS_FS_BEGIN
class HttpRequest;
class HttpReponse;
class Thread;
class Mutex;
class ConditionVariable;

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
		ConditionVariable* m_reqSem;
		Mutex* m_reqMutex;


		int m_stop;
		int m_maxConnectTime;
		int m_maxReadTime;
};

NS_FS_END 

#endif /* _FS_HTTP_ENGING_H_ */

