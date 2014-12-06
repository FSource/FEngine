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

		FsVariant(FsType t,const void* value);

		FsVariant(float v);
		FsVariant(const Vector2& v);
		FsVariant(const Vector3& v);
		FsVariant(const Vector4& v);

		FsVariant(int32_t v);
		FsVariant(const Vector2i& v);
		FsVariant(const Vector3i& v);
		FsVariant(const Vector4i& v);


		FsVariant(const Matrix4& v);

		FsVariant(FsObject* v);
		FsVariant(FsString* v);
		FsVariant(FsDict*  v);
		FsVariant(FsArray* v);

		FsVariant(const FsVariant& value);
		~FsVariant();


		FsVariant& operator= (const FsVariant& v);


	public:
		FsType getType() const;
		void* getValue() const;

		bool isValid() const;
		FsVariant getCast(FsType t) const;



	protected:
		void init(FsType t,const void* value);
		void destruct();




	private:
		FsType m_type;
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



			FsObject* m_object;

			FsString* m_string;
			FsDict* m_dict;
			FsArray* m_array;
			void* m_value;
		};
};

NS_FS_END 


#endif /*_FS_VARIANT_H_*/


