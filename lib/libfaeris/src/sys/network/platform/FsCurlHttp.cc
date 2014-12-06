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














