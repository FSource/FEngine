#ifndef _FS_UNIFORM_MAP_H_
#define _FS_UNIFORM_MAP_H_
#include <string>

#include "FsMacros.h"
#include "FsUniformValue.h"


NS_FS_BEGIN

class UniformMap:public UniformValue
{
	public:
		static UniformMap* create(const char* name,E_UniformType type,E_UniformRef v)
		{
			return new UniformMap(name,type,v);
		}

		static UniformMap* create(const char* name,E_UniformType type, int index)
		{
			return new UniformMap(name,type,index);
		}

	public:
		void* getData() FS_OVERRIDE 
		{
			return &m_refValue;
		}
		const char* className() FS_OVERRIDE 
		{
			return "UniformMap";
		}

	public:
		UniformMap* clone ()
		{
			if(m_type==E_UniformType::UT_REF_RD || m_type==E_UniformType::UT_REF_MTL )
			{
				UniformMap* ret=new UniformMap(m_name.c_str(),m_type,m_refValue);
				return ret;
			}
			else 
			{
				UniformMap* ret=new UniformMap(m_name.c_str(),m_type,m_extIndex);
				return ret;
			}
			return NULL;
		}

	protected:
		UniformMap(const char* name,E_UniformType type,E_UniformRef v)
			:UniformValue(name,type),
			m_location(-2)
		{
			m_refValue=v;
		}

		UniformMap(const char* name,E_UniformType type,int index)
			:UniformValue(name,type),
			m_location(-2)
		{
			m_extIndex=index;
		}


	public:
		union {
			E_UniformRef m_refValue;
			int m_extIndex;
		};
		int m_location;
};

NS_FS_END






#endif /*_FS_UNIFORM_MAP_H_*/





