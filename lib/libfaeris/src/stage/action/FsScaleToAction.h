#include "stage/action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN
class ScaleToAction:public Action 
{
	public:
		static ScaleToAction* create(float sx,float sy,float sz,float time);
		static ScaleToAction* create(float sx,float sy,float time)
		{
			return ScaleToAction::create(sx,sy,1,time);
		}
	public:
		virtual bool run(ActionTarget* target,float dt);
		virtual const char* className();

	protected:
		ScaleToAction(float sx,float sy,float sz,float time);

	private:
		float m_elapse;
		float m_lifeTime;
		Vector3 m_targetScale;
};


NS_FS_END

