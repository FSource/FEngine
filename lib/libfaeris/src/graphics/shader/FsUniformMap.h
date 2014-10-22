#ifndef _FS_UNIFORM_MAP_H_
#define _FS_UNIFORM_MAP_H_
#include <string>

#include "FsMacros.h"


NS_FS_BEGIN

class UniformMap:public UniformValue
{
	public:
		UniformMap(const char* name,E_UniformType type,E_UniformRef v)
			:m_name(name),
			m_type(type),
			m_location(-2)
		{
			m_refValue=v;
		}

		UniformMap(const char* name,E_UniformType type,int index)
			:m_name(name),
			m_type(type),
			m_location(-2)
		{
			m_extIndex=index;
		}
	public:
		virtual void* getData(){return &m_refValue;}

	public:
		UniformMap* clone ()
		{
			if(m_type==E_UniformType::UT_REF_RD || m_type==E_UniformType::UT_REF_MAT )
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


	public:
		union {
			E_UniformRef m_refValue;
			int m_extIndex;
		};
		int m_location;
};


NS_FS_END






#endif /*_FS_UNIFORM_MAP_H_*/





