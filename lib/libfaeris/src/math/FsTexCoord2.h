#ifndef _FAERIS_TEX_COORD2_H_
#define _FAERIS_TEX_COORD2_H_
#include "FsMacros.h"

NS_FS_BEGIN

class TexCoord2
{
	public:
		union
		{
			struct
			{
				float tu;
				float tv;
			};
			float v[2];
		};
	public:
		void set(float t_u,float t_v)
		{
			tu=t_u;
			tv=t_v;
		}

	public:
		TexCoord2(float t_u,float t_v):tu(t_u),tv(t_v){}
		TexCoord2():tu(0),tv(0){}
};
NS_FS_END
#endif /*_FAERIS_TEX_COORD2_H_*/

