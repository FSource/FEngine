#ifndef _FS_SHADER_MATERIAL_H_
#define _FS_SHADER_MATERIAL_H_

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"

NS_FS_BEGIN

class UniformValue;

class StreamValue
{
	public:
		StreamValue(const char* name)
			:m_name(name),
			m_ref(E_StreamType::UNKOWN)
		{ }
	public:
		std::string m_name;
		E_StreamType m_ref;
};


class ShaderSource:public Resource
{
	public:
		static ShaderSource* create();

	protected:
		ShaderSource();
		virtual ~ShaderSource();

	public:
		std::string m_vert;
		std::string m_frag;
		std::vector<UniformValue*> m_defaultUniformMaps;
		std::vector<StreamValue*> m_defaultStreamMaps;
};


class ShaderMaterial:public Material 
{

	public:
		/* uniform value */
		UniformValue* getUniform(int i){return m_uniforms[i];}
		int getUniformNu(){return m_uniforms.size();}

		/* stream map */
		int getStreamMapNu(){return m_streamMaps.size();}
		StreamValue* getStreamMap(int index){return m_streamMaps[index];}

	protected:
		void addUniform(UniformValue* v);
		void sortUniformByName();


	protected:
		std::vector<UniformValue*> m_uniforms;
		std::vector<StreamValue*> m_streamMaps;

		ShaderSource* m_shaderSourceData;

};





NS_FS_END 


#endif /*_FS_SHADER_MATERIAL_H_*/


