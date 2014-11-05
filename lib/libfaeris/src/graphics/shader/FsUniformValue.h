#ifndef _FS_UNIFORM_VALUE_H_
#define _FS_UNIFORM_VALUE_H_

#include "FsMacros.h"
#include "FsEnums.h"

#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"

#include "graphics/FsColor.h"
#include "graphics/FsTexture2D.h"




NS_FS_BEGIN

class UniformValue 
{
	public:

		E_UniformType getType(){return m_type;}
		int getCount() {return m_count;}
		virtual void* getData()=0;

	public:
		UniformValue()
			:m_type(E_UniformType::UT_UNKOWN),
			m_count(1)
		{
		}
		UniformValue(const char* name,E_UniformType type)
			:m_name(name),
			m_type(type),
			m_count(1)

		{}



	public:
		int m_count;
		std::string m_name;
		E_UniformType m_type;

};


template <typename T> int TUniformValue_GetType() { T temp;return static_cast<int>(E_UniformType::UT_UNKOWN);}

template<> inline int TUniformValue_GetType<float>()    {return static_cast<int>(E_UniformType::UT_F_1);}
template<> inline int TUniformValue_GetType<Vector2f>() {return static_cast<int>(E_UniformType::UT_F_2);}
template<> inline int TUniformValue_GetType<Vector3f>() {return static_cast<int>(E_UniformType::UT_F_3);}
template<> inline int TUniformValue_GetType<Vector4f>() {return static_cast<int>(E_UniformType::UT_F_4);}

template<> inline int TUniformValue_GetType<int16_t>()  {return static_cast<int>(E_UniformType::UT_I_1);}
template<> inline int TUniformValue_GetType<Vector2i>() {return static_cast<int>(E_UniformType::UT_I_2);}
template<> inline int TUniformValue_GetType<Vector3i>() {return static_cast<int>(E_UniformType::UT_I_3);}
template<> inline int TUniformValue_GetType<Vector4i>() {return static_cast<int>(E_UniformType::UT_I_4);}

template<> inline int TUniformValue_GetType<uint16_t>() {return static_cast<int>(E_UniformType::UT_UI_1);}
template<> inline int TUniformValue_GetType<Vector2ui>() {return static_cast<int>(E_UniformType::UT_UI_2);}
template<> inline int TUniformValue_GetType<Vector3ui>() {return static_cast<int>(E_UniformType::UT_UI_3);}
template<> inline int TUniformValue_GetType<Vector4ui>() {return static_cast<int>(E_UniformType::UT_UI_4);}


template<> inline int TUniformValue_GetType<Color3f>() {return static_cast<int>(E_UniformType::UT_F_3);}
template<> inline int TUniformValue_GetType<Color4f>() {return static_cast<int>(E_UniformType::UT_F_4);}

template<> inline int TUniformValue_GetType<Matrix4>() {return static_cast<int>(E_UniformType::UT_M_4);}




template <typename T> 
class TUniformValue:public UniformValue
{
	public:
		TUniformValue(const char* name,const T& v)
			:m_data(v)
		{ 
			m_name=name;
			m_type=TUniformValue_GetType<T>();
		}

	public:
		virtual void* getData()
		{
			return &m_data;
		}
	public:
		T m_data;
};

class UniformValueSample2D: public UniformValue 
{
	public:
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

		virtual void* getData() { return m_data; }

	public:
		Texture2D* m_data;
};

class UniformRefRD:public UniformValue 
{
	public:
		UniformRefRD(const char* name,int ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_RD;
			m_data=ref;
		}

		virtual void* getData() { return &m_data; }

	public:
		int m_data;
		int m_location;
};


class UniformRefMat:public UniformValue 
{
	public:
		UniformRefMat(const char* name,int ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_MAT;
			m_data=ref;
		}
		virtual void* getData() {return &m_data;}

	public:
		int m_data;
};



class UniformRefMatExt:public UniformValue 
{
	public:
		UniformRefMatExt(const char* name,int ref)
		{
			m_name=name;
			m_type=E_UniformType::UT_REF_MAT_EXT;
			m_data=ref;
		}
		virtual void* getData(){return &m_data;}
	public:
		int m_data;
};






typedef TUniformValue<float>    UniformValuef;
typedef TUniformValue<Vector2f> UniformValue2f;
typedef TUniformValue<Vector3f> UniformValue3f;
typedef TUniformValue<Vector4f> UniformValue4f;

typedef TUniformValue<int32_t>  UniformValuei;
typedef TUniformValue<Vector2i> UniformValue2i;
typedef TUniformValue<Vector3i> UniformValue3i;
typedef TUniformValue<Vector4i> UniformValue4i;

typedef TUniformValue<int32_t>  UniformValueui;
typedef TUniformValue<Vector2ui> UniformValue2ui;
typedef TUniformValue<Vector3ui> UniformValue3ui;
typedef TUniformValue<Vector4ui> UniformValue4ui;


typedef TUniformValue<Color3f> UniformValueC3f;
typedef TUniformValue<Color4f> UniformValueC4f;

typedef TUniformValue<Matrix4> UniformMat4f;

NS_FS_END

#endif /*_FS_UNIFORM_VALUE_H_*/


