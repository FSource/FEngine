#ifndef _FS_MOVE_BY_ACTION_H_
#define _FS_MOVE_BY_ACTION_H_

#include "FsMacros.h"
#include "stage/action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN

class MoveByAction:public Action
{
	public:
		static MoveByAction* create(float x,float y,float z,float time)
		{
			return MoveByAction::create(Vector3(x,y,z),time);
		}
		static MoveByAction* create(float x,float y,float time)
		{
			return MoveByAction::create(Vector3(x,y,0),time);
		}
		static MoveByAction* create(const Vector3& pos,float time);

	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		MoveByAction(const Vector3& pos,float time);

	private:
		float m_lifeTime;
		float m_elapse;
		Vector3 m_stepPos;
};



NS_FS_END

#endif /*_FS_MOVE_BY_ACTION_H_*/
