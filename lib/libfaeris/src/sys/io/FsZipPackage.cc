/*************************************************************************/
/*  FsZipPackage.cc                                                      */
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


#include <stdlib.h>
#include <string.h>

#include "sys/io/FsFile.h"
#include "sys/io/FsZipPackage.h"
#include "support/data/FsZipReader.h"

NS_FS_BEGIN

ZipPackage* ZipPackage::create(FsFile* file)
{
	ZipPackage* ret=new ZipPackage;
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* ZipPackage::takeBlock(const char* filename)
{
	return m_reader->takeFile(filename);
}


const char* ZipPackage::className()
{
	return FS_ZIP_PACKAGE_CLASS_NAME;
}


bool ZipPackage::init(FsFile* file)
{
	ZipReader* reader=ZipReader::create(file);
	if(reader==NULL)
	{
		return false;
	}
	else 
	{
		m_reader=reader;
		return true;
	}

}

ZipPackage::ZipPackage()
{
	m_reader=NULL;
}


ZipPackage::~ZipPackage()
{
	if(m_reader)
	{
		m_reader->decRef();
		m_reader=NULL;
	}
}


NS_FS_END







































