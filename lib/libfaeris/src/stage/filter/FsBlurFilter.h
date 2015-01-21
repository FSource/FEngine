#ifndef _FS_BLUR_FILTER_H_
#define _FS_BLUR_FILTER_H_

#include "FsFilter.h"

NS_FS_BEGIN 

class BlurFilter:public Filter 
{
	public:
		static BlurFilter* create();
		static BlurFilter* create(float radius);

	public:


};



NS_FS_END 


#endif /*_FS_BLUR_FILTER_H_*/


