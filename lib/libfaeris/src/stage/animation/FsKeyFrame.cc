#include "FsKeyFrame.h"
#include "math/easing/FsEaseExpr.h"

NS_FS_BEGIN 
KeyFrame::KeyFrame(float time,EaseExpr* ease_expr)
{
	m_time=time;
	m_easeExpr=ease_expr;
	FS_SAFE_ADD_REF(m_easeExpr);
}

KeyFrame::~KeyFrame()
{
	FS_SAFE_DEC_REF(m_easeExpr);
}


float KeyFrame::getTime() const
{
	return m_time;
}

void KeyFrame::setEaseExpr(EaseExpr* ease)
{
	FS_SAFE_ASSIGN(m_easeExpr,ease);
}

EaseExpr* KeyFrame::getEaseExpr()
{
	return m_easeExpr;
}



/* VariantKeyFrame */

VariantKeyFrame* VariantKeyFrame::create(float time,const FsVariant& value,EaseExpr* ease_expr)
{
	return new VariantKeyFrame(time,value,ease_expr);
}

void VariantKeyFrame::setValue(const FsVariant& value)
{
	m_value=value;
}

const FsVariant& VariantKeyFrame::getValue()  const
{
	return m_value;
}


VariantKeyFrame::VariantKeyFrame(float time,const FsVariant& value,EaseExpr* ease_expr)
	:KeyFrame(time,ease_expr) 
{ 
	m_value=value;
}



/** Pose KeyFrame */

PoseKeyFrame* PoseKeyFrame::create(float time,int anim_index,float anim_time,EaseExpr* ease_expr)
{
	return new PoseKeyFrame(time,anim_index,anim_time,ease_expr);
}

void PoseKeyFrame::setAnimIndex(int anim_index)
{
	m_animIndex=anim_index;
}

int PoseKeyFrame::getAnimIndex() const
{
	return m_animIndex;
}


void PoseKeyFrame::setAnimTime(float time)
{
	m_time=time;
}

float PoseKeyFrame::getAnimTime() const
{
	return m_animTime;
}


PoseKeyFrame::PoseKeyFrame(float time,int anim_index,float anim_time,EaseExpr* ease_expr)
	:KeyFrame(time,ease_expr)
{
	m_animIndex=anim_index;
	m_animTime=anim_time;
}




NS_FS_END 

