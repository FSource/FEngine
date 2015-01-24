/*************************************************************************/
/*  FsColor.cc                                                           */
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


#include "FsColor.h"
#include "support/util/FsScriptUtil.h"

NS_FS_BEGIN

Color Color::DEFAULT_COLOR=Color(255,255,255,255);
Color Color::RED=Color(255,0,0,255);
Color Color::BLUE=Color(0,0,255,255);
Color Color::GREEN=Color(0,255,0,255);
Color Color::WHITE=Color(255,255,255,255);
Color Color::BLACK=Color(0,0,0,255);




Color Color::operator+(Color right)
{
	int red=r+right.r;
	int green=g+right.g;
	int blue=b+right.b;
	int alpha=a+right.a;

	if(red>255) red=255;
	if(green>255) green=255;
	if(blue>255) blue=255;
	if(alpha>255) alpha=255;

	return Color(red,green,blue,alpha);
}

Color Color::operator-(Color right)
{
	int red=r-right.r;
	int green=g-right.g;
	int blue=b-right.b;
	int alpha=a-right.a;

	if(red<0) red=0;
	if(green<0) green=0;
	if(blue<0) blue=0;
	if(alpha<0) alpha=0;

	return Color(red,green,blue,alpha);
}

Color Color::operator*(float s)
{
	int red=(int)(r*s);
	int green=(int)(g*s);
	int blue=(int)(b*s);
	int alpha=(int)(a*s);

	if(red<0) red=0;
	if(red>255) red=255;

	if(green<0)  green=0;
	if(green>255) green=255;

	if(blue<0) blue=0;
	if(blue>255) blue=255;

	if(alpha<0) alpha=0;
	if(alpha>255) alpha=255;


	return Color(red,green,blue,alpha);
}


Color3f Color3f::RED=Color3f(1.0f,0.0f,0.0f);
Color3f Color3f::GREEN=Color3f(0.0f,1.0f,0.0f);
Color3f Color3f::BLUE=Color3f(0.0f,0.0f,1.0f);
Color3f Color3f::WHITE=Color3f(1.0f,1.0f,1.0f);
Color3f Color3f::BLACK=Color3f(0.0f,0.0f,0.0f);

Color3f::Color3f(const char* str)
	:r(1.0f),
	g(1.0f),
	b(1.0f)
{
	ScriptUtil::parseColor3f(str,&r,&g,&b);
}

Color3f Color3f::operator + (const Color3f& v)
{
	float red=r+v.r;
	float blue=b+v.b;
	float green=g+v.g;

	return Color3f(red,green,blue);
}

Color3f Color3f::operator - (const Color3f& v)
{
	float red=r-v.r;
	float blue=b-v.b;
	float green=g-v.g;
	return Color3f(red,green,blue);
}


Color3f Color3f::operator * (const Color3f& v)
{
	float red=r*v.r;
	float blue=b*v.b;
	float green=g*v.g;
	return Color3f(red,green,blue);
}

Color3f Color3f::operator * (float v)
{
	float red=r*v;
	float blue=b*v;
	float green=g*v;
	return Color3f(red,green,blue);
}


Color3f Color3f::operator / (const Color3f& v)
{
	float red=r/v.r;
	float blue=b/v.b;
	float green=g/v.g;
	return Color3f(red,green,blue);

}
Color3f Color3f::operator / (float v)
{
	float red=r/v;
	float blue=b/v;
	float green=g/v;
	return Color3f(red,green,blue);
}


Color4f Color4f::DEFAULT_COLOR=Color4f(1.0f,1.0f,1.0f,1.0f);
Color4f Color4f::RED=Color4f(1.0f,0.0f,0.0f,1.0f);
Color4f Color4f::GREEN=Color4f(0.0f,1.0f,0.0f,1.0f);
Color4f Color4f::BLUE=Color4f(0.0f,0.0f,1.0f,1.0f);
Color4f Color4f::WHITE=Color4f(1.0f,1.0f,1.0f,1.0f);
Color4f Color4f::BLACK=Color4f(0.0f,0.0f,0.0f,1.0f);

Color4f::Color4f(const char* c)
	:r(1.0f),
	g(1.0f),
	b(1.0f),
	a(1.0f)
{
	ScriptUtil::parseColor4f(c,&r,&g,&b,&a);
}

Color4f Color4f::lerp(const Color4f& value,float t)
{
	float red=r+(value.r-r)*t;
	float green=g+(value.g-g)*t;
	float blue=b+(value.b-b)*t;
	float alpha=a+(value.a-a)*t;

	return Color4f(red,green,blue,alpha);
}


Color4f Color4f::operator+(Color4f right)
{
	float red=r+right.r;
	float green=g+right.g;
	float blue=b+right.b;
	float alpha=a+right.a;

	return Color4f(red,green,blue,alpha);
}

Color4f Color4f::operator-(Color4f right)
{
	float red=r-right.r;
	float green=g-right.g;
	float blue=b-right.b;
	float alpha=a-right.a;

	return Color4f(red,green,blue,alpha);
}

Color4f Color4f::operator*(Color4f right)
{
	float red=r*right.r;
	float green=g*right.g;
	float blue=b*right.b;
	float alpha=a*right.a;

	return Color4f(red,green,blue,alpha);
}


Color4f Color4f::operator*(float s)
{
	float red=r*s;
	float green=g*s;
	float blue=b*s;
	float alpha=a*s;

	return Color4f(red,green,blue,alpha);
}






NS_FS_END

