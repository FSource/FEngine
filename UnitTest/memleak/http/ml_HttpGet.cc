#include "sys/network/FsHttpEngine.h"
#include "sys/network/FsHttpRequest.h"
#include "sys/network/FsHttpReponse.h"

#include <stdio.h>
#include <unistd.h>

#include <string.h>
#include <stdlib.h>

NS_FS_USE

class MyUrlRequest:public HttpRequest 
{
	public:
		MyUrlRequest(const char* url)
		{
			setUrl(url);
		}
	public:
		virtual void onReponse(HttpReponse* reponse)
		{
			if(reponse->getReponseCode()!=200)
			{
				uint8_t* error_buf=NULL;
				int buf_len=0;
				reponse->getErrorBuf(&error_buf,&buf_len);

				char* dst_buf=strndup((char*)error_buf,buf_len);
				printf("Request Error %d (%s)\n",reponse->getReponseCode(),dst_buf);
				free(dst_buf);
			}
			else 
			{
				uint8_t* buf=NULL;
				int buf_len=0;
				reponse->getData(&buf,&buf_len);
				char* dst_buf=strndup((char*)buf,buf_len);
				printf("Request Success(%s)\n",dst_buf);
				free(dst_buf);
			}
		}
};



int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("useage: %s <url>\n",argv[0]);
		return -1;
	}

	HttpEngine* http=HttpEngine::create();

	MyUrlRequest* request=new MyUrlRequest(argv[1]);

	http->send(request);

	sleep(5);

	http->decRef();
}


