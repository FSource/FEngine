/*************************************************************************/
/*  FsHttpRequest.h                                                      */
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


#ifndef _FS_HTTP_REQUEST_H_
#define _FS_HTTP_REQUEST_H_
#include <set>
#include <string>
#include <vector>


#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class HttpReponse;
class  HttpRequest:public FsObject  
{
	public:
		typedef std::set<std::string>::iterator HeaderSetIterator;
	public:
		enum
		{
			VERSION_1_0,
			VERSION_1_1,
		};
		enum 
		{
			METHOD_GET,
			METHOD_POST,
		};

	public:
		static HttpRequest* create();


	public:
		void setUrl(const char* url);
		const char* getUrl();

		void setMethod(int method);
		int getMethod();

		void setVersion(int version);
		int getVersion();

		void addHeader(const char* header);
		void removeHeader(const char* header);
		void clearHeader();
		int getHeaderNu();

		void setData(const uint8_t* data,int data_len);
		void getData(uint8_t** data,int* data_len);
		void setData(const char* data);


		HeaderSetIterator headerBegin();
		HeaderSetIterator headerEnd();

	public:
		virtual void onReponse(HttpReponse* data);
		virtual void onSyncReponse(HttpReponse* data);

		virtual const char* className();

	protected:
		HttpRequest();
		virtual ~HttpRequest();

	private:
		int m_method;
		int m_version;
		std::string m_url;
		std::set<std::string> m_headers;
		std::vector<uint8_t> m_data;
};

NS_FS_END

#endif /*_FS_HTTP_REQUEST_H_*/

