#ifndef FY_MATH_VECTOR4_H_
#define FY_MATH_VECTOR4_H_
#include "FsMacros.h"
#include "FsMath.h"

NS_FS_BEGIN
template<typename T>
class TVector4
{
	public:
		union
		{
			struct 
			{
				T x;
				T y;
				T z;
				T w;
			};
			T v[4];
		};
	public:
		TVector4(T fx,T fy,T fz,T fw);
		TVector4(T fx,T fy,T fz);
		TVector4<T>();
		TVector4<T> add(const TVector4<T>& v)const ;
		TVector4<T> sub(const TVector4<T>& v)const;
		TVector4<T> scale(T k)const ;
		T dot(const TVector4<T>& v)const;

		TVector4<T> normal() const ;
		void normalize() ;
		T length() const;
		T length2() const;

		bool equal(const TVector4<T>& v) const;

		TVector4<T> lerp(const TVector4<T>& v,T t);


		TVector4<T> operator + (const TVector4<T>& v)const;
		TVector4<T> operator - (const TVector4<T>& v)const;
		TVector4<T> operator / (T v) const ;
		TVector4<T> operator * (T v) const ;

		TVector4<T>& operator +=(const TVector4<T>& v);
};

#include"FsVector4.inl"

typedef TVector4<float> Vector4f;
typedef TVector4<float> Vector4;

typedef TVector4<uint16_t> Vector4ui;
typedef TVector4<int16_t> Vector4i;

NS_FS_END
#endif



