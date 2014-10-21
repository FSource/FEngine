#ifndef _FS_SHADER_SOURCE_PARSER_H_
#define _FS_SHADER_SOURCE_PARSER_H_

#include <string>
#include <vector>
#include <stdio.h>


class GlslextTypeMap
{
	public:
		enum 
		{
			E_STRING,
			E_VECTOR
		};
	public:
		GlslextTypeMap(std::string* name,std::string* type,std::string* value)
		{
			m_name=name;
			m_type=type;
			m_stringValue=value;
			m_valueType=E_STRING;
		}

		GlslextTypeMap(std::string* name,std::string* type,std::vector<float>* value)
		{
			m_name=name;
			m_type=type;
			m_vecValue=value;
			m_valueType=E_VECTOR;
		}

		~GlslextTypeMap()
		{
			if(m_name)
			{
				delete m_name;
			}
			if(m_type)
			{
				delete m_type;
			}

			if(m_valueType==E_STRING)
			{
				if(m_stringValue)
				{
					delete m_stringValue;
				}
			}
			else 
			{
				if(m_vecValue)
				{
					delete m_vecValue;
				}
			}
		}

	public:
		std::string* m_name;
		std::string* m_type;
		int m_valueType;

		union 
		{
			std::string* m_stringValue;
			std::vector<float>* m_vecValue;
		};
};


class GlslextParser 
{
	public:
		typedef int(*ReadFunc)(void* file,void* buf,int length);

	public:
		static GlslextParser* create(void* file,ReadFunc func);


	public:
		void setVertexSrc(std::string* value){m_vertexSrc=value;}
		std::string* getVertexSrc(){return m_vertexSrc;}

		void setFragmentSrc(std::string* value){m_fragmentSrc=value;}
		std::string* getFramgentSrc(){return m_fragmentSrc;}

		void addUniformMap(std::string* name,std::string* type,std::string* value)
		{
			m_uniformMap.push_back(new GlslextTypeMap(name,type,value));
		}
		void addUniformMap(std::string* name,std::string* type,std::vector<float>* value)
		{
			m_uniformMap.push_back(new GlslextTypeMap(name,type,value));
		}

		void addAttributeMap(std::string* name,std::string* type,std::string* value)
		{
			m_attributeMap.push_back(new GlslextTypeMap(name,type,value));
		}


	protected:
		GlslextParser();
		~GlslextParser();
		bool init(void* file,ReadFunc func);


	public:
		void* m_scanner;

		void* m_file;
		ReadFunc m_readFunc;

		std::string* m_vertexSrc;
		std::string* m_fragmentSrc;

		std::vector<GlslextTypeMap*> m_uniformMap;
		std::vector<GlslextTypeMap*> m_attributeMap;

};

int Glslext_error(GlslextParser* param,const char* msg);
int Glslext_parse (GlslextParser* param);

#endif /*_FS_SHADER_SOURCE_PARSER_H_*/



