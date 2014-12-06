#include <math.h>
#include <stdlib.h>

#include "FsMath.h"

NS_FS_BEGIN

void Math::srand(ulong s)
{
	::srand(s);
}

int Math::random()
{
	return ::rand();
}
int Math::random(int begin,int end)
{
	return begin+::rand()%(end-begin);
}
float Math::random(float begin,float end)
{

	float value=(float)rand()/float(RAND_MAX);
	assert(value>=0.0f&&value<=1.0f);
	return begin+(end-begin)*value;
}



NS_FS_END


