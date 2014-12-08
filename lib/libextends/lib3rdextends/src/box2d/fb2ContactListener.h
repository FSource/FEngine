#ifndef _F_B2_CONTACT_LISTENER_H_
#define _F_B2_CONTACT_LISTENER_H_

#include "FsMacros.h"
#include "Box2D/Box2D.h"
#include "FsObject.h"
NS_FS_BEGIN

class fb2ContactListener:public b2ContactListener
{
	public:

		fb2ContactListener();
		~fb2ContactListener();

	public:
		virtual void BeginContact(b2Contact* contact);
		virtual void EndContact(b2Contact* contact);
		virtual void PreSolve(b2Contact* contact, const b2Manifold* old_mf);
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

	public:
		int m_scriptData;

};

#endif /*_F_B2_CONTACT_LISTENER_H_*/
NS_FS_END



