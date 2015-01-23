/*************************************************************************/
/*  FsHttpReponse.h                                                      */
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

