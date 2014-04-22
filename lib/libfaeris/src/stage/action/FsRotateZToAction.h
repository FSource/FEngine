#include "stage/action/FsAction.h"

NS_FS_BEGIN

class RotateZToAction:public Action 
{
	public:
		static RotateZToAction* create(float angle,float time);

	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		RotateZToAction(float angle,float time);

	private:
		float m_lifeTime;
		float m_elapse;
		float m_targetAngle;
};




NS_FS_END

