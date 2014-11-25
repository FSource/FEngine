#ifndef _FAERIS_COLOR_H_
#define _FAERIS_COLOR_H_
#include "FsMacros.h"
NS_FS_BEGIN
class Color 
{
	public:
		static Color DEFAULT_COLOR;
		static Color RED;
		static Color BLUE;
		static Color GREEN;
		static Color WHITE;
		static Color BLACK;
	public:
		union{
			struct{
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			};
			uint rgba;
		};
	public:
		Color(uint8_t red,uint8_t green,uint8_t blue,uint8_t alpha)
			:r(red),g(green),b(blue),a(alpha){}
		Color():r(0),g(0),b(0),a(255){}
		Color(uint8_t red,uint8_t green,uint8_t blue)
			:r(red),g(green),b(blue),a(255){}

		void set(uint8_t _r,uint8_t _g,uint8_t _b,uint8_t _a)
		{
			r=_r;
			g=_g;
			b=_b;
			a=_a;
		}
		Color operator+(Color right);
		Color operator-(Color right);
		Color operator*(float s);
		bool operator==(Color right){return rgba==right.rgba;}
		bool operator!=(Color right){return rgba!=right.rgba;}
};

class Color3f 
{
	public:
		static Color3f RED;
		static Color3f BLUE;
		static Color3f GREEN;
		static Color3f WHITE;
		static Color3f BLACK;
	public:
		Color3f(const Color& c)
		{
			r=float(c.r)/255.0f;
			g=float(c.g)/255.0f;
			b=float(c.b)/255.0f;
		}

		Color3f(float _r,float _g,float _b)
			:r(_r),
			g(_g),
			b(_b)
		{ }

		Color3f()
			:r(1.0f),
			g(1.0f),
			b(1.0f)
		{}

	public:
		Color3f operator + (const Color3f& v);
		Color3f operator - (const Color3f& v);

		Color3f operator * (const Color3f& v);
		Color3f operator * (float value);

		Color3f operator / (const Color3f& v);
		Color3f operator / (float value);

	public:
		void set(float _r,float _g,float _b)
		{
			r=_r;
			g=_g;
			b=_b;
		}
	public:
		union{
			struct{
				float r;
				float g;
				float b;
			};
			float v[3];
		};
};

class Color4f
{
	public:
		static Color4f DEFAULT_COLOR;
		static Color4f RED;
		static Color4f BLUE;
		static Color4f GREEN;
		static Color4f WHITE;
		static Color4f BLACK;

	public:
		Color4f(const Color& c)
		{
			r=float(c.r)/255.0f;
			g=float(c.g)/255.0f;
			b=float(c.b)/255.0f;
			a=float(c.a)/255.0f;
		}

		Color4f(float red,float green,float blue,float alpha)
			:r(red),g(green),b(blue),a(alpha)
		{}
		Color4f(float red,float green,float blue)
			:r(red),g(green),b(blue),a(1.0f)
		{ }

		Color4f()
			:r(1.0f),g(1.0f),b(1.0f),a(1.0f)
		{
		}

		void set(float _r,float _g,float _b,float _a)
		{
			r=_r;
			g=_g;
			b=_b;
			a=_a;
		}


		Color4f lerp(const Color4f& value,float t);


		Color4f operator+(Color4f right);
		Color4f operator-(Color4f right);
		Color4f operator*(float s);
		Color4f operator*(Color4f right);


	public:
		union{
			struct{
				float r;
				float g;
				float b;
				float a;
			};
			float v[4];
		};
};


NS_FS_END

#endif /*_FAERIS_COLOR_H_*/

