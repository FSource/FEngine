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


}


bool GlslextParser::init(void* file,ReadFunc func)
{
	m_file=file;
	m_readFunc=func;

	Glslext_lex_init(&m_scanner);
	Glslext_set_extra(this,m_scanner);


	return true;

}




