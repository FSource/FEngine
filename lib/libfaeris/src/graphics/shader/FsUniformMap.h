/*************************************************************************/
/*  FsUniformMap.h                                                       */
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





