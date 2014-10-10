#ifndef FY_MATH_VECTORE3_H_
#define FY_MATH_VECTORE3_H_

#include "FsMath.h"

NS_FS_BEGIN

template <typename T> 
class TVector3
{
	public:
		union
		{
			struct
			{
				T x;
				T y;
				T z;
			};
			T v[3];
		};
	public:
		TVector3(T _x,T _y,T _z);
		TVector3();

		TVector3<T> add(const TVector3<T>& v) const ;
		TVector3<T> sub(const TVector3<T>& v) const ;
		TVector3<T> scale(T k) const ;
		T dot(const TVector3<T>& v) const ;
		TVector3<T> cross(const TVector3<T>& v)const;
		TVector3<T> normal() const ;
		void normalize() ;
		TVector3<T> proj(const TVector3<T>& v) const;
		T angle(const TVector3<T>& v) const;
		T length() const;
		T length2() const;
		bool equal(const TVector3<T>& v) const;
		void set(T _x,T _y,T _z);
		TVector3<T> lerp(const TVector3<T>& v,T t);



		/* operator */

		TVector3<T> operator+(const TVector3<T>& v)const;
		TVector3<T> operator-(const TVector3<T>& v)const;
		TVector3<T> operator/ (T v)const;
		TVector3<T> operator* (T v)const;
		TVector3<T>& operator +=(const TVector3<T>& v);


};

#include "FsVector3.inl"

typedef TVector3<float> Vector3f;
typedef TVector3<float> Vector3;

typedef TVector3<uint16_t> Vector3ui;
typedef TVector3<int16_t> Vector3i;


NS_FS_END
#endif 

