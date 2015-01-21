#ifndef _FS_GRAY_FILTER_H_
#define _FS_GRAY_FILTER_H_

#include "FsMacros.h"
#include "FsFilter.h"

NS_FS_BEGIN
class GrayFilter:public Filter 
{
	public:
		static GrayFilter* create();

	protected:
		GrayFilter();



};


NS_FS_END 




#endif /*_FS_GRAY_FILTER_H_*/


