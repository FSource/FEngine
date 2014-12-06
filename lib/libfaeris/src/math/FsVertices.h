#ifndef _FS_VERTICES_H_
#define _FS_VERTICES_H_

#include "FsMacros.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "graphics/FsColor.h"


NS_FS_BEGIN


class Fs_V2F_T2F
{
	
	public:
		Fs_V2F_T2F(){}
		Fs_V2F_T2F(const Vector2& v,const TexCoord2& t)
		{
			v2=v;
			t2=t;
		}
	
	public:

		Vector2 v2;
		TexCoord2 t2;
};


class Fs_V3F_T2F
{
	public:
		Fs_V3F_T2F();
		Fs_V3F_T2F(const Vector3& v,const TexCoord2& t)
		{
			v3=v;
			t2=t;
		}

	public:
		Vector3 v3;
		TexCoord2 t2;
};

class Fs_V2F_T2F_C4F
{
	public:
		Fs_V2F_T2F_C4F(){}
		Fs_V2F_T2F_C4F(const Vector2& v,const TexCoord2& t,const Color4f& c)
		{
			v2=v;
			t2=t;
			c4=c;
		}

	public:
		Vector2 v2;
		TexCoord2 t2;
		Color4f c4;
};


NS_FS_END 



#endif /*_FS_VERTICES_H_*/









