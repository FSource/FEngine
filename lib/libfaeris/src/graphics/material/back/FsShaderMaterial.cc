#include <algorithm>
#include "graphics/material/FsMaterial.h"

NS_FS_BEGIN


ShaderSource* ShaderSource::create()
{
	return new ShaderSource();
}


ShaderSource::ShaderSource()
{

}


ShaderSource::~ShaderSource()
{
	int size=m_defaultUniformMaps.size();

	for(int i=0;i<size;i++)
	{
		delete m_defaultUniformMaps[i];
	}
	m_defaultUniformMaps.clear();

	size=m_defaultStreamMaps.size();

	for(int i=0;i<size;i++)
	{
		delete m_defaultStreamMaps[i];
	}
	m_defaultStreamMaps.clear();
}


static bool FsMaterialUniform_Sort(UniformValue* l,UniformValue* r)
{
	if(l->m_name<r->m_name)
	{
		return true;
	}

	return false;
}

ShaderMaterial::~ShaderMaterial()
{
	/* delete uniforms */
	int size=m_uniforms.size();
	for(int i=0;i<size;i++)
	{
		delete m_uniforms[i];
	}
	m_uniforms.clear();


	/* delete stream map */
	size=m_streamMaps.size();
	for (int i=0;i<size;i++)
	{
		delete m_streamMaps[i];
	}
	m_streamMaps.clear();
}

void ShaderMaterial::sortUniformByName()
{
	std::sort(m_uniforms->begin(),m_uniforms->end(),FsMaterialUniform_Sort);
}


NS_FS_END 





