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

