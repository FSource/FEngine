#ifndef _FS_ACTION_H_
#define _FS_ACTION_H_

#include "FsMacros.h"
#include "FsObject.h"



NS_FS_BEGIN

class ActionTarget;
class Scene;

class Action:public FsObject
{
	public:
		Action(){}
		virtual ~Action(){}

	public:
		virtual bool run(ActionTarget* target,float dt)=0;
		const char* className();
};

NS_FS_END 

#endif /*_FS_ACTION_H_*/

