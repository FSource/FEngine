#ifndef _FS_MOVE_TO_ACTION_H_
#define _FS_MOVE_TO_ACTION_H_

#include "stage/action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN

class MoveToAction:public Action 
{
	public: 
		static MoveToAction* create(float sx,float sy,float sz,float time)
		{
			return MoveToAction::create(Vector3(sx,sy,sz),time);
		}
		static MoveToAction* create(float sx,float sy,float time)
		{
			return MoveToAction::create(Vector3(sx,sy,0),time);
		}
		
		static MoveToAction* create(const Vector3& pos,float time);


	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		MoveToAction(const Vector3& pos,float time);

	private:
		float m_lifeTime;
		float m_elapse;
		Vector3 m_targetPos;
};



NS_FS_END

#endif /*_FS_MOVE_TO_ACTION_H_*/

