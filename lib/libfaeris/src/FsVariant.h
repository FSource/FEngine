/*************************************************************************/
/*  FsVariant.h                                                          */
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


#ifndef _FS_VARIANT_H_
#define _FS_VARIANT_H_

#include "FsMacros.h"
#include "FsEnums.h"

#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"
#include "graphics/FsColor.h"


NS_FS_BEGIN
class FsDict;
class FsArray;
class FsString;
class FsObject;
class FsVariant 
{

	public:
		FsVariant();

		FsVariant(E_FsType t,const void* value);

		FsVariant(float v);
		FsVariant(const Vector2& v);
		FsVariant(const Vector3& v);
		FsVariant(const Vector4& v);

		FsVariant(int32_t v);
		FsVariant(const Vector2i& v);
		FsVariant(const Vector3i& v);
		FsVariant(const Vector4i& v);

		FsVariant(const Color4f& v);
		FsVariant(const Color3f& v);

		FsVariant(const Matrix4& v);
		FsVariant(const char* v);

		FsVariant(FsObject* v);
		FsVariant(FsString* v);
		FsVariant(FsDict*  v);
		FsVariant(FsArray* v);
	

		FsVariant(const FsVariant& value);
		~FsVariant();


		FsVariant& operator= (const FsVariant& v);
		FsVariant operator* (float value) const;
		FsVariant operator+ (const FsVariant& value) const;


	public:
		E_FsType getType() const;
		void* getValue() const;

		bool isValid() const;
		FsVariant getCast(E_FsType t) const;



	protected:
		void init(E_FsType t,const void* value);
		void destruct();




	private:
		E_FsType m_type;
		union 
		{
			bool* m_b1;
			float* m_f1;
			Vector2* m_f2;
			Vector3* m_f3;
			Vector4* m_f4;

			int32_t* 	m_i1;
			Vector2i* m_i2;
			Vector3i* m_i3;
			Vector4i* m_i4;

			uint32_t*  m_ui1;
			Vector2ui* m_ui2;
			Vector3ui* m_ui3;
			Vector4ui* m_ui4;

			Color3f* m_c3;
			Color4f* m_c4;

			Matrix4* m_mat4;
			char* m_chars;



			FsObject* m_object;

			FsString* m_string;
			FsDict* m_dict;
			FsArray* m_array;
			void* m_value;
		};
};

NS_FS_END 


#endif /*_FS_VARIANT_H_*/


