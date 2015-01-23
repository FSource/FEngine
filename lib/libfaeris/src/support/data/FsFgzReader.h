/*************************************************************************/
/*  FsFgzReader.h                                                        */
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


#ifndef _FS_FGZ_READER_H_
#define _FS_FGZ_READER_H_

#include "FsMacros.h"
#include "FsObject.h"


#define FS_FGZ_STORE 	0x0 
#define FS_FGZ_DEFLATE  0x10
#define FS_FGZ_LZMA   	0x20 


#define FS_FGZ_CRC32   0xFAE

#define FS_FGZ_MAGIC_NU       {0,'F','G','Z','I','P','1',0}
#define FS_FGZ_FILE_MAGIC_NU  {0,'F','G','F','I','L','E',0}


#define FS_DEFLATE_DEFAULT_LEVEL  6




NS_FS_BEGIN
class FsFile;
class FsDict;
class FgzReader:public FsObject 
{
	public:
		static FgzReader* create(FsFile* file);
		static bool CheckType(FsFile* file);

	public:
		FsFile* takeFile(const char* filename);

	public:
		virtual const char* className();


	public:
		FgzReader();
		virtual ~FgzReader();
		bool init(FsFile* file);
		void destruct();

	private:
		FsDict* m_files;
		FsFile* m_stream;
};


NS_FS_END 



#endif /*_FS_FGZ_READER_H_*/

