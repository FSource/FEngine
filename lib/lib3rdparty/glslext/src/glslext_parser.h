/*************************************************************************/
/*  glslext_parser.h                                                     */
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


#ifndef _FS_SHADER_SOURCE_PARSER_H_
#define _FS_SHADER_SOURCE_PARSER_H_

#include <string>
#include <vector>
#include <stdio.h>

class GlslextFeature 
{
	public:
		GlslextFeature(std::string* name,std::string* value)
		{
			m_name=name;
			m_value=value;
		}
		~GlslextFeature()
		{
			if(m_name) 
			{
				delete m_name;
			}
			if(m_value) 
			{
				delete m_value;
			}
		}
	public:
		std::string* m_name;
		std::string* m_value;

};


class GlslextTypeMap
{
	public:
		GlslextTypeMap(std::string* name,std::string* type,std::string* value)
		{
			m_name=name;
			m_type=type;
			m_value=value;
			m_extIndex=0;
		}

		GlslextTypeMap(std::string* name,std::string* type,std::string* value,int index)
		{
			m_name=name;
			m_type=type;
			m_value=value;
			m_extIndex=index;
		}

		~GlslextTypeMap()
		{
			if(m_name) { delete m_name; }
			if(m_type) { delete m_type; } 
			if(m_value) { delete m_value; }
	   	}

	public:
		std::string* m_name;
		std::string* m_type;
		std::string* m_value;
		int m_extIndex;
};


class GlslextParser 
{
	public:
		typedef int(*ReadFunc)(void* file,void* buf,int length);

	public:
		static GlslextParser* create(void* file,ReadFunc func);


	public:
		void setVertexSrc(std::string* value)
		{
			m_vertexSrc=value;
		}

		std::string* getVertexSrc()
		{
			return m_vertexSrc;
		}

		void setFragmentSrc(std::string* value)
		{
			m_fragmentSrc=value;
		}

		std::string* getFramgentSrc()
		{
			return m_fragmentSrc;
		}

		void addUniformMap(std::string* name,std::string* type,std::string* value)
		{
			m_uniformMap.push_back(new GlslextTypeMap(name,type,value));
		}
		void addUniformMap(std::string* name,std::string* type,std::string* value,int ext_index)
		{
			m_uniformMap.push_back(new GlslextTypeMap(name,type,value,ext_index));
		}

		int getUniformMapNu() 
		{
			return m_uniformMap.size();
		} 

		GlslextTypeMap* getUniformMap(int index)
		{
			return m_uniformMap[index];
		}



		void addAttributeMap(std::string* name,std::string* type,std::string* value)
		{
			m_attributeMap.push_back(new GlslextTypeMap(name,type,value));
		}

		int getAttributeMapNu()
		{
			return m_attributeMap.size();
		}

		GlslextTypeMap*  getAttributeMap(int index)
		{
			return m_attributeMap[index];
		}

		void addFeature(std::string* name,std::string* value)
		{
			m_feature.push_back(new GlslextFeature(name,value));
		}

		int getFeatureNu()
		{
			return m_feature.size();
		}

		GlslextFeature* getFeature(int index)
		{
			return m_feature[index];
		}


	public:
		GlslextParser();
		~GlslextParser();

	protected:
		bool init(void* file,ReadFunc func);


	public:
		void* m_scanner;

		void* m_file;
		ReadFunc m_readFunc;

		std::string* m_vertexSrc;
		std::string* m_fragmentSrc;

		std::vector<GlslextTypeMap*> m_uniformMap;
		std::vector<GlslextTypeMap*> m_attributeMap;
		std::vector<GlslextFeature*> m_feature;
};


GlslextParser* GlslextParser_Parse(void* file,GlslextParser::ReadFunc func);
int Glslext_error(GlslextParser* param,const char* msg);
int Glslext_parse (GlslextParser* param);

#endif /*_FS_SHADER_SOURCE_PARSER_H_*/



