#ifndef _FS_SCALE_ACTION_H_
#define _FS_SCALE_ACTION_H_ 

#include "FsCurve3Action.h"


NS_FS_BEGIN
class ScaleAction:public Curve3Action 
{
	public:
		static ScaleAction* createFromTo(const Vector3& from,const Vector3& to,float time);
		static ScaleAction* createBy(const Vector3& from,const Vector3& to,float time);
		static ScaleAction* create(Curve3* curve,float time);

	public:
		/* inherit FixTimeAction */
		virtual void step(ActionTarget* target,float percent);

		/* inherit FsObject */
		virtual const char* className();

	public:
		ScaleAction();

		void initWithFromTo(const Vector3& from,const Vector3& to,float time);
		void initWithBy(const Vector3& from,const Vector3& by,float time);
		void initWithCurve(Curve3* curve,float time);
};
NS_FS_END








#endif /*_FS_SCALE_ACTION_H_*/


