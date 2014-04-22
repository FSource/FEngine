#include "stage/action/FsAction.h"


NS_FS_BEGIN
class RotateZByAction:public Action 
{
	public:
		static RotateZByAction* create(float angle,float time);

	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		RotateZByAction(float angle,float time);

	private:
		float m_lifeTime;
		float m_elapse;
		float m_stepAngle;
};

NS_FS_END

