#ifndef _FS_HTTP_REPONSE_H_
#define _FS_HTTP_REPONSE_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class HttpReponse :public FsObject 
{
	public:
		static HttpReponse* create();

	public:
		void setReponseCode(int code);
		int getReponseCode();

		void appendData(uint8_t* data,int len);
		void setData(uint8_t* data,int len);
		void getData(uint8_t** data,int* len);

		void appendError(uint8_t* data,int len);
		void setErrorBuf(uint8_t* buf,int len);
		void getErrorBuf(uint8_t** buf,int* len);

	public:
		virtual const char* className();

	protected:
		HttpReponse();
		virtual ~HttpReponse();

	private:
		int m_code;
		std::vector<uint8_t> m_data;
		std::vector<uint8_t> m_error;
};


NS_FS_END


#endif /*_FS_HTTP_REPONSE_H_*/

