#include "stage/action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN
class ScaleByAction:public Action 
{
	public:
		static ScaleByAction* create(float sx,float sy,float sz,float time);
		static ScaleByAction* create(float sx,float sy,float time)
		{
			return ScaleByAction::create(sx,sy,1,time);
		}

	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		ScaleByAction(float sx,float sy,float sz,float time);

	private:
		float m_elapse;
		float m_lifeTime;
		Vector3 m_stepScale;
};



NS_FS_END

