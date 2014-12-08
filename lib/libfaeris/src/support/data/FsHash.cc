#include "support/data/FsHash.h"

NS_FS_BEGIN

ulong FsHash_JCode(const char* str)
{
	ulong hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}

NS_FS_END

