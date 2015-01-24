/*************************************************************************/
/*  FsCurlHttp.cc                                                        */
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
#include "curl/curl.h"


#include "FsMacros.h"
#include "sys/network/FsHttpReponse.h"
#include "sys/network/FsHttpRequest.h"

NS_FS_BEGIN 

static size_t FsCurl_WriteFunction(void* ptr,size_t size,size_t nmemb,void* stream)
{
	HttpReponse* reponse=(HttpReponse*) stream;
	size_t len=size*nmemb;
	reponse->appendData((uint8_t*)ptr,len);
	return len;
}



HttpReponse* FsHttp_HandlePost(HttpRequest* request,int max_connect_time,int max_read_time)
{
	CURLcode code;
	int32_t reponse_code=-1;

	uint8_t* data=NULL;
	int datalen=0;

	char error_buf[CURL_ERROR_SIZE]={0};

	struct curl_slist* headers=NULL;
	HttpRequest::HeaderSetIterator iter;

	HttpReponse* reponse=HttpReponse::create();

	CURL* curl=curl_easy_init();
	if(curl==NULL)
	{
		FS_TRACE_WARN("Can't Create Curl Handler");
		goto error;
	}



	/* configure header */
	curl_easy_setopt(curl,CURLOPT_ERRORBUFFER,error_buf);
	curl_easy_setopt(curl,CURLOPT_TIMEOUT,max_read_time);
	curl_easy_setopt(curl,CURLOPT_CONNECTTIMEOUT,max_connect_time);


	if(request->getHeaderNu()!=0)
	{
		for(iter=request->headerBegin();iter!=request->headerEnd();++iter)
		{
			headers=curl_slist_append(headers,(iter)->c_str());
		}
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
	}


	curl_easy_setopt(curl,CURLOPT_URL,request->getUrl());
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,FsCurl_WriteFunction);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,reponse);
	curl_easy_setopt(curl,CURLOPT_POST,1);

	request->getData(&data,&datalen);
	if(datalen!=0)
	{
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,data);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDSIZE,datalen);
	}

	code=curl_easy_perform(curl);
	if(code!=CURLE_OK)
	{
		FS_TRACE_WARN("curl_error:%s",curl_easy_strerror(code));
		goto error;
	}

	if(headers!=NULL)
	{
		curl_slist_free_all(headers);
		headers=NULL;
	}
	code=curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&reponse_code);
	if(code!=CURLE_OK)
	{
		FS_TRACE_WARN("curl_error:%s",curl_easy_strerror(code));
		goto error;
	}

	reponse->setReponseCode(reponse_code);
	reponse->setErrorBuf((uint8_t*)error_buf,strnlen(error_buf,CURL_ERROR_SIZE));

	curl_easy_cleanup(curl);

	return reponse;


error:
	if(reponse)
	{
		reponse->decRef();
	}
	if(curl)
	{
		curl_easy_cleanup(curl);
	}
	if(headers)
	{
		curl_slist_free_all(headers);
	}
	return NULL;
}


HttpReponse* FsHttp_HandleGet(HttpRequest* request,int max_read_time,int max_connect_time)
{

	CURLcode code;
	int32_t reponse_code=-1;
	uint8_t* data=NULL;
	int datalen=0;

	char error_buf[CURL_ERROR_SIZE]={0};
	struct curl_slist* headers=NULL;
	HttpRequest::HeaderSetIterator iter;

	HttpReponse* reponse=HttpReponse::create();

	CURL* curl=curl_easy_init();
	if(curl==NULL)
	{
		FS_TRACE_WARN("Can't Create Curl Handler");
		goto error;
	}


	/* configure header */
	curl_easy_setopt(curl,CURLOPT_ERRORBUFFER,error_buf);
	curl_easy_setopt(curl,CURLOPT_TIMEOUT,max_read_time);
	curl_easy_setopt(curl,CURLOPT_CONNECTTIMEOUT,max_connect_time);


	if(request->getHeaderNu()!=0)
	{
		for(iter=request->headerBegin();iter!=request->headerEnd();++iter)
		{
			headers=curl_slist_append(headers,(iter)->c_str());
		}
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
	}


	curl_easy_setopt(curl,CURLOPT_URL,request->getUrl());
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, request->getUrl());

	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,FsCurl_WriteFunction);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,reponse);

	request->getData(&data,&datalen);
	if(datalen!=0)
	{
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,data);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDSIZE,datalen);
	}

	code=curl_easy_perform(curl);
	if(code!=CURLE_OK)
	{
		FS_TRACE_WARN("curl_error:%s",curl_easy_strerror(code));
		goto error;
	}

	if(headers!=NULL)
	{
		curl_slist_free_all(headers);
		headers=NULL;
	}

	code=curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&reponse_code);
	if(code!=CURLE_OK)
	{
		FS_TRACE_WARN("curl_error:%s",curl_easy_strerror(code));
		goto error;
	}

	reponse->setReponseCode(reponse_code);
	reponse->setErrorBuf((uint8_t*)error_buf,strnlen(error_buf,CURL_ERROR_SIZE));

	curl_easy_cleanup(curl);

	return reponse;

error:
	if(reponse)
	{
		reponse->decRef();
	}
	if(curl)
	{
		curl_easy_cleanup(curl);
	}

	if(headers)
	{
		curl_slist_free_all(headers);
	}

	return NULL;


}


NS_FS_END 














