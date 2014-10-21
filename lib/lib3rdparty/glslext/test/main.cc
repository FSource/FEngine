#include "glslext_parser.h"
#include "glslext_grammer.h"

int read_func(void* file,void* buf,int readlength)
{
	return fread(buf,1,readlength,(FILE*)file);
}



int main(int argc, char** argv)
{
	if(argc < 2 ) 
	{
		printf("useage %s <filename>\n" ,argv[0]);
		return 0;
	}

	FILE* file=fopen(argv[1],"r");


	GlslextParser* parser=GlslextParser::create(file,read_func);

	if(Glslext_parse(parser)==0)
	{
		printf("parser successful\n");
		printf("===VertexShader===\n%s\n",parser->getVertexSrc()->c_str());
		printf("===FragmentShader===\n%s\n",parser->getFramgentSrc()->c_str());

		printf("===Uniform Map===\n");
		for(int i=0;i<parser->m_uniformMap.size();i++)
		{
			GlslextTypeMap* iter=parser->m_uniformMap[i];
			printf("<%s,%s, ",iter->m_type->c_str(),iter->m_name->c_str());
			if(iter->m_valueType==GlslextTypeMap::E_STRING)
			{
				printf("%s",iter->m_stringValue->c_str());
			}
			else 
			{
				int v_size=iter->m_vecValue->size();
				printf("(");
				for(int j=0;j<v_size;j++)
				{
					float v=iter->m_vecValue->at(j);
					printf("%f,",v);

				}
				printf(")");
			}
			printf(">\n");

		}
		printf("\n\n===Attribute Map===\n");

		for(int i=0;i<parser->m_attributeMap.size();i++)
		{
			GlslextTypeMap* iter=parser->m_attributeMap[i];
			printf("<%s,%s, ",iter->m_type->c_str(),iter->m_name->c_str());
			if(iter->m_valueType==GlslextTypeMap::E_STRING)
			{
				printf("%s",iter->m_stringValue->c_str());
			}
			else 
			{
				int v_size=iter->m_vecValue->size();
				printf("(");
				for(int j=0;j<v_size;j++)
				{
					float v=iter->m_vecValue->at(j);
					printf("%f,",v);

				}
				printf(")");
			}
			printf(">\n");

		}


	}
	else 
	{
		printf("parser failed\n");
	}

	return 0;


}



