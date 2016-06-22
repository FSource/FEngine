#ifndef _FS_ANIMATION_EVENT_H_
#define _FS_ANIMATION_EVENT_H_ 
NS_FS_BEGIN

class FsAnimationEvent 
{
	public:
		int getEventType();
};

template<class TValue,class TEventType> 
class FsTAnimationEvent 
{

};
NS_FS_END 
#endif /*_FS_ANIMATION_EVENT_H_*/
