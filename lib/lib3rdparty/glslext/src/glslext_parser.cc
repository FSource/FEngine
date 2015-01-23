/*************************************************************************/
/*  glslext_parser.cc                                                    */
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


#include "glslext_defines.h"
#include "glslext_parser.h"
#include "glslext_grammer.h"
#include "glslext_scanner.h"


int Glslext_error(GlslextParser* param,const char* msg)
{
	printf("error: %s at line<%d><%s>\n",msg,
			Glslext_get_lineno(param->m_scanner),
			Glslext_get_text(param->m_scanner)
			);
	return 0;
}

GlslextParser* GlslextParser::create(void* file,ReadFunc func)
{
	GlslextParser* ret=new GlslextParser();

	if(!ret->init(file,func))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}

GlslextParser::GlslextParser()
{
	m_scanner=NULL;
	m_file=NULL;
	m_readFunc=0;
	m_vertexSrc=NULL;
	m_fragmentSrc=NULL;
}

GlslextParser::~GlslextParser()
{
	if(m_scanner)
	{
		Glslext_lex_destroy(m_scanner);
	}

	if(m_vertexSrc)
	{
		delete m_vertexSrc;
	}

	if(m_fragmentSrc)
	{
		delete m_fragmentSrc;
	}

	int size=m_uniformMap.size();
	for(int i=0;i<size;i++)
	{
		delete m_uniformMap[i];
	}

	m_uniformMap.clear();

	size=m_attributeMap.size();
	for(int i=0;i<size;i++)
	{
		delete m_attributeMap[i];
	}
	m_attributeMap.clear();


	size=m_feature.size();
	for(int i=0;i<size;i++)
	{
		delete m_feature[i];
	}
	m_feature.clear();

}


bool GlslextParser::init(void* file,ReadFunc func)
{
	m_file=file;
	m_readFunc=func;

	Glslext_lex_init(&m_scanner);
	Glslext_set_extra(this,m_scanner);


	return true;

}

GlslextParser* GlslextParser_Parse(void* file,GlslextParser::ReadFunc func)
{
	GlslextParser* parser=GlslextParser::create(file,func);
	if(Glslext_parse(parser)==0)
	{
		return parser;
	}

	delete parser;
	return NULL;

}




