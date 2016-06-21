#ifndef _FS_SEQ_ANIMATION_H_
#define _FS_SEQ_ANIMATION_H_ 

NS_FS_BEGIN 
class FsSeqAnimation:public FsAnimation 
{
	public:
		void update(Animator* at,float time,float dt) FS_OVERRIDE;
		float getTimeLength() FS_OVERRIDE;
	public:
		void addAnimation(FsAnimation* anim);
		void removeAnimation(FsAnimation* anim);
		int getAnimationNu();
		FsAnimation* getAnimation(int index);

	public:
		FsArray* m_animaitons;
		float m_totalTime;
};

NS_FS_END 

#endif /*_FS_SEQ_ANIMATION_H_*/
