/*************************************************************************/
/*  FsFgzPackage.cc                                                      */
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


#include "sys/io/FsFgzPackage.h"
#include "support/data/FsFgzReader.h"


NS_FS_BEGIN

const char* FgzPackage::className()
{
	return FS_FGZ_PACKAGE_CLASS_NAME;
}

FgzPackage* FgzPackage::create(FsFile* file)
{
	FgzPackage* ret=new FgzPackage;
	if(!ret->init(file))
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}

FsFile* FgzPackage::takeBlock(const char* filename)
{
	return m_reader->takeFile(filename);
}


bool FgzPackage::init(FsFile* file)
{
	FgzReader* reader=FgzReader::create(file);
	if(reader==NULL)
	{
		return false;
	}
	m_reader=reader;
	return true;

}


FgzPackage::FgzPackage()
{
	m_reader=NULL;
}

FgzPackage::~FgzPackage()
{
	if(m_reader)
	{
		m_reader->decRef();
		m_reader=NULL;
	}
}



NS_FS_END
