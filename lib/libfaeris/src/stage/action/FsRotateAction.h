#ifndef _FS_ROTATE_ACTION_H_
#define _FS_ROTATE_ACTION_H_

#include "FsCurve3Action.h"

class RotateAction::Curve3Action 
{
	public:
		RotateAction* createFromTo(const Vector3& from,const Vector3& to,float time);
		RotateAction* createBy(const Vector3& from,const Vector3& to,float time);
		RotateAction* create(Curve3* curve,float time);

	public:
		/* inherit FixTimeAction */
		virtual void step(ActionTarget* target,float percent); 

		/* inherit FsObject */
		virtual const char* className();

	public:
		RotateAction();

		void initWithFromTo(const Vector3& from,const Vector3& to,float time);
		void initWithBy(const Vector3& from,const Vector3& by,float time);
		void initWithCurve(Curve3* curve,float time);


};

#endif /*_FS_ROTATE_ACTION_H_*/



