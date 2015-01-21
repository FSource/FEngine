#ifndef _FS_OPACITY_FILTER_H_
#define _FS_OPACITY_FILTER_H_

#include "FsMacros.h"
#include "FsFilter.h"


NS_FS_BEGIN 

#define FS_OPACITY_FILTER_OPACITY_INDEX 3

class OpacityFilter: public Filter 
{
	public:
		static OpacityFilter* create();
		static OpacityFilter* create(float opacity);

	public:
		void setOpacity(float value);
		float getOpacity();

	protected:
		OpacityFilter();

};

NS_FS_END 

#endif /*_FS_OPACITY_FILTER_H_*/


