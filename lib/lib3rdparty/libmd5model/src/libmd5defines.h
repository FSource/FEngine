#ifndef _LIB_MD5_DEFINES_H_
#define _LIB_MD5_DEFINES_H_

#include "libmd5model.h"

class Md5Parser 
{
	public:
		Md5Parser(void* scanner,void* data,void* file,LibMd5_ReadIo io)
		{
			m_scanner=scanner;
			m_data=data;
			m_file=file;
			m_io=io;
		}

	public:
		void* m_scanner;
		void* m_data;
		void* m_file;
		LibMd5_ReadIo m_io;
};









#endif /*_LIB_MD5_DEFINES_H_*/

