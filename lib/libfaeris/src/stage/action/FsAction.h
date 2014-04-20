#ifndef _FS_ACTION_H_
#define _FS_ACTION_H_

#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN

class ActionTarget;

class Action:public FsObject 
{
	public:
		Action(){}
		virtual ~Action();

	public:

		/* Note: if Return Value Is zero, Action Not Done
		 * 		 if Return Greater Than Zero, Action Done, And finish Func Will Called
		 */

		virtual float run(ActionTarget* target,float dt)=0;

		/* When Action Done, finish will Called  */ 
		virtual void finish();

		const char* className();
};



NS_FS_END






#endif /*_FS_ACTION_H_*/



