#ifndef _FS_BRIGHT_NESS_FILTER_H_
#define _FS_BRIGHT_NESS_FILTER_H_

#include "FsFilter.h"

NS_FS_BEGIN 

class BrightnessFilter:public Filter 
{
	public:
		static BrightnessFilter* create();
		static BrightnessFilter* create(float value);

	public:
		void setBrightness(float value);
		float getBrightness();
	
	protected:
		BrightnessFilter();


};



NS_FS_END 


#endif /*_FS_BRIGHT_NESS_FILTER_H_*/

