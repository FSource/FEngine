#ifndef _FS_UNIFORM_VALUE_H_
#define _FS_UNIFORM_VALUE_H_

#include "FsMacros.h"
#include "FsEnums.h"
#include "FsObject.h"

#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"

#include "graphics/FsColor.h"
#include "graphics/FsTexture2D.h"




NS_FS_BEGIN

class UniformValue :public FsObject
{
	public:
		virtual void* getData()=0;

	public:


		int getCount() 
		{
			return m_count;
		}


		void setName(const char* name)
		{
			m_name=name;
		}

		const char* getName()
		{
			return m_name.c_str();
		}

		void setType(E_UniformType type)
		{
			m_type=type;
		}

		E_UniformType getType()
		{
			return m_type;
		}

	protected:
		UniformValue()
			:m_count(1),
			m_type(E_UniformType::UT_UNKOWN)
		{
		}
		UniformValue(const char* name,E_UniformType type)
			:m_count(1),
			m_name(name),
			m_type(type)

		{}

	protected:
		int m_count;
		std::string m_name;
		E_UniformType m_type;

};



template <typename T,E_UniformType U_T,const char* CL_NAME> 
class TUniformValue:public UniformValue
{
	public:
		static TUniformValue<T,U_T,CL_NAME>* create(const char* name,const T& v)
		{
			return new TUniformValue<T,U_T,CL_NAME>(name,v);
		}

	public:
		void set(const T& d){m_data=d;}
		T get(){return m_data;}

	public:
		void* getData() FS_OVERRIDE
		{
			return &m_data;
		}
		const char* className() FS_OVERRIDE
		{
			return CL_NAME;
		}

	protected:
		TUniformValue(const char* name,const T& v)
			:m_data(v)
		{ 
			m_name=name;
			m_type=U_T;
		}

	protected:
		T m_data;
};

class UniformValueSample2D: public UniformValue 
{

	public:
		static UniformValueSample2D* create(const char* name,Texture2D* tex)
		{
			return new UniformValueSample2D(name,tex);
		}

	public:

		void set(Texture2D* tex)
		{
			FS_SAFE_ASSIGN(m_data,tex);
		}

		Texture2D* get()
		{
			return m_data;
		}


	public:
		void* getData() FS_OVERRIDE 
		{
		   	return m_data; 
		}

		const char* className()
		{
			return  "UniformValueSample2D";
		}


	protected:
		UniformValueSample2D(const char* name,Texture2D* tex)
		{
			m_name=name;
			m_type=E_UniformType::UT_S_2D;
			m_data=tex;
			FS_SAFE_ADD_REF(m_data);
		}

		virtual ~UniformValueSample2D()
		{
			FS_SAFE_DEC_REF(m_data);
		}

	protected:
		Texture2D* m_data;
};


class UniformRefRD:public UniformValue 
{

	public:
		static UniformRefRD* create(const char* name,E_UniformRef ref)
		{
			return new UniformRefRD(name,ref);
		}

	public:

		void set(E_UniformRef value)
		{
			m_data=value;
		}

		E_UniformRef get()
		{
			return m_data;
		}

	public:
		void* getData() FS_OVERRIDE 
		{ 
			return &m_data; 
		}

		const char* className() FS_OVERRIDE
		{
			return "UniformRefRD";
		}


	protected:
		UniformRefRD(const char* name,E_UniformRef ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_RD;
			m_data=ref;
		}

	protected:
		E_UniformRef m_data;
};


class UniformRefMtl:public UniformValue 
{
	public:
		static UniformRefMtl* create(const char* name,E_UniformRef ref)
		{
			return new UniformRefMtl(name,ref);
		}

	public:
		void set (E_UniformRef value) { m_data=value; }
		E_UniformRef get() { return m_data; }

	public:
		void* getData() FS_OVERRIDE
		{
			return &m_data;
		}

		const char* className() FS_OVERRIDE
		{
			return "UniformRefMtl";
		}

	protected:
		UniformRefMtl(const char* name,E_UniformRef ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_MTL;
			m_data=ref;
		}

	protected:
		E_UniformRef m_data;
};



class UniformRefMtlExt:public UniformValue 
{
	public:
		static UniformRefMtlExt* create(const char* name,int ref)
		{
			return new UniformRefMtlExt(name,ref);
		}

	public:
		void set(int value) { m_data=value; }
		int get() { return m_data; }

	public:
		void* getData() FS_OVERRIDE 
		{
			return &m_data;
		}

		const char* className() FS_OVERRIDE
		{
			return "UniformRefMtlExt";
		}

	protected:
		UniformRefMtlExt(const char* name,int ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_MTL_EXT;
			m_data=ref;
		}

	protected:
		int m_data;
};


extern const char UniformValue1f_ClassName[];
extern const char UniformValue2f_ClassName[];
extern const char UniformValue3f_ClassName[];
extern const char UniformValue4f_ClassName[];

extern const char UniformValue1i_ClassName[];
extern const char UniformValue2i_ClassName[];
extern const char UniformValue3i_ClassName[];
extern const char UniformValue4i_ClassName[];

extern const char UniformValue1ui_ClassName[];
extern const char UniformValue2ui_ClassName[];
extern const char UniformValue3ui_ClassName[];
extern const char UniformValue4ui_ClassName[];

extern const char UniformValueC3f_ClassName[];
extern const char UniformValueC4f_ClassName[];
extern const char UniformValueMatrix4f_ClassName[];


typedef TUniformValue<float,E_UniformType::UT_F_1,UniformValue1f_ClassName>    UniformValue1f;
typedef TUniformValue<float,E_UniformType::UT_F_2,UniformValue2f_ClassName>    UniformValue2f;
typedef TUniformValue<float,E_UniformType::UT_F_3,UniformValue3f_ClassName>    UniformValue3f;
typedef TUniformValue<float,E_UniformType::UT_F_4,UniformValue4f_ClassName>    UniformValue4f;

typedef TUniformValue<int32_t,E_UniformType::UT_I_1,UniformValue1i_ClassName>  UniformValue1i;
typedef TUniformValue<int32_t,E_UniformType::UT_I_2,UniformValue2i_ClassName>  UniformValue2i;
typedef TUniformValue<int32_t,E_UniformType::UT_I_3,UniformValue3i_ClassName>  UniformValue3i;
typedef TUniformValue<int32_t,E_UniformType::UT_I_4,UniformValue4i_ClassName>  UniformValue4i;

typedef TUniformValue<uint32_t,E_UniformType::UT_UI_1,UniformValue1ui_ClassName>  UniformValue1ui;
typedef TUniformValue<uint32_t,E_UniformType::UT_UI_2,UniformValue1ui_ClassName>  UniformValue2ui;
typedef TUniformValue<uint32_t,E_UniformType::UT_UI_3,UniformValue1ui_ClassName>  UniformValue3ui;
typedef TUniformValue<uint32_t,E_UniformType::UT_UI_4,UniformValue1ui_ClassName>  UniformValue4ui;

typedef TUniformValue<Color3f,E_UniformType::UT_F_3,UniformValueC3f_ClassName> UniformValueC3f;
typedef TUniformValue<Color4f,E_UniformType::UT_F_4,UniformValueC4f_ClassName> UniformValueC4f;

typedef TUniformValue<Matrix4,E_UniformType::UT_M_4,UniformValueMatrix4f_ClassName> UniformMat4f;

NS_FS_END

#endif /*_FS_UNIFORM_VALUE_H_*/


