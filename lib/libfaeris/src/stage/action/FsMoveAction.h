#ifndef _FS_MOVE_ACTION_H_
#define _FS_MOVE_ACTION_H_

#include "FsCurve3Action.h"

NS_FS_BEGIN

class MoveAction:public Curve3Action 
{
	public:
		/* from to */
		static MoveAction* createFromTo(const Vector3& from,const Vector3& to,float time);
		static MoveAction* createXYFromTo(float xfrom,float yfrom,float xto,float yto,float time);
		static MoveAction* createXFromTo(float from,float to,float time);
		static MoveAction* createYFromTo(float from,float to,float time);
		static MoveAction* createZFromTo(float from,float to,float time);


		static MoveAction* createBy(const Vector3& from,const Vector3& by,float time);
		static MoveAction* createXYBy(float xfrom,float yfrom,float xby,float yby,float time);
		static MoveAction* createXBy(float from,float by,float time);
		static MoveAction* createYBy(float from,float by,float time);
		static MoveAction* createZBy(float from,float by,float time);


		static MoveAction* create(Curve3* curve,float time);
	public:
		/* inherit FixTimeAction */
		virtual void step(ActionTarget* target,float percent);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		MoveAction();

		void initWithFromTo(const Vector3& from,const Vector3& to,float time);
		void initWithBy(const Vector3& from,const Vector3& by,float time);
		void initWithCurve(Curve3* curve,float time);
};





NS_FS_END



#endif /*_FS_MOVE_ACTION_H_*/

