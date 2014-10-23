#ifndef _FAERY_FACE3_H_
#define _FAERY_FACE3_H_

#include "FsMacros.h"

NS_FS_BEGIN
class Face3 
{
	public:
		union
		{
			struct
			{
				uint16_t a;
				uint16_t b;
				uint16_t c;
			};
			uint16_t v[3];
		};
	public:
		void set(uint16_t _a,uint16_t _b,uint16_t _c)
		{
			a=_a;
			b=_b;
			c=_c;
		}

	public:
		Face3(uint16_t _a,uint16_t _b,uint16_t _c)
			:a(_a),b(_b),c(_c)
		{}
		Face3(){}
};
typedef Face3 Face3i;


NS_FS_END

#endif 

