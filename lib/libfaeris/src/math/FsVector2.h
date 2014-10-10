#ifndef  FY_MATH_VECTOR2_H_
#define  FY_MATH_VECTOR2_H_ 

#include "FsMacros.h"
#include "FsMath.h"

NS_FS_BEGIN
template<typename T>
class TVector2
{
	public:
		union
		{
			struct 
			{
				T x;
				T y;
			};
			T v[2];
		};
	public:
		TVector2(T fx,T fy);
		TVector2();

		TVector2<T> add(const TVector2<T>& v)const;
		TVector2<T> sub(const TVector2<T>& v)const;
		TVector2<T> scale(T k) const ;

		T dot(const TVector2<T>& v)const;

		TVector2<T> normal()const;
		void normalize();

		TVector2<T> proj(const TVector2<T>& v)const;

		T angle(const TVector2<T>& v)const;

		T length() const;
		T length2() const;

		bool equal(const TVector2<T>& v)const ;
		void set(T _x,T _y);

		TVector2<T> lerp(const TVector2<T>& v,T t);

		/* operator */
		TVector2<T> operator + (const TVector2<T>& v)const;
		TVector2<T> operator - (const TVector2<T>& v)const;
		TVector2<T> operator / (T v) const ;
		TVector2<T> operator * (T v) const ;

		TVector2<T>& operator +=(const TVector2<T>& v);
};

#include "FsVector2.inl"

typedef TVector2<float> Vector2f;
typedef TVector2<float> Vector2;

typedef TVector2<uint16_t> Vector2ui;
typedef TVector2<int16_t> Vector2i;



NS_FS_END
#endif 







