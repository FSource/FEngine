#ifndef _FS_TASK_H_
#define _FS_TASK_H_
#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class Task:public FsObject 
{
	public:
		virtual void run()=0;

	public:
		virtual const char* className();
};
NS_FS_END


#endif /*_FS_TASK_H_ */


