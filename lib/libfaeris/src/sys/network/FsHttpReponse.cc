#include "FsHttpReponse.h"

NS_FS_BEGIN


const char* HttpReponse::className()
{
	return "HttpReponse";
}


HttpReponse* HttpReponse::create()
{
	return new HttpReponse;
}

HttpReponse::HttpReponse()
{
}
HttpReponse::~HttpReponse()
{
}

void HttpReponse::setReponseCode(int code)
{
	m_code=code;
}

int HttpReponse::getReponseCode()
{
	return m_code;
}


void HttpReponse::appendData(uint8_t* data,int len)
{
	m_data.insert(m_data.end(),data,data+len);
}

void HttpReponse::setData(uint8_t* data,int len)
{
	m_data.clear();
	m_data.insert(m_data.end(),data,data+len);
}

void HttpReponse::getData(uint8_t** data,int* len)
{
	*len=m_data.size();
	if(m_data.size()==0)
	{
		*data=NULL;
	}
	else
	{
		*data=&m_data[0];
	}
}


void HttpReponse::appendError(uint8_t* buf,int len)
{
	m_error.insert(m_error.end(),buf,buf+len);
}


void HttpReponse::setErrorBuf(uint8_t* buf,int len)
{
	m_error.clear();
	m_error.insert(m_error.end(),buf,buf+len);
}

void HttpReponse::getErrorBuf(uint8_t** buf,int* len)
{

	static uint8_t empty_str[]="";
	*len=m_error.size();

	if(m_error.size()==0)
	{
		*buf=empty_str;
	}
	else
	{
		*buf=&m_error[0];
	}

}









NS_FS_END





















