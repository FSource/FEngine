#ifndef _FS_EASE_EXPR_H_
#define _FS_EASE_EXPR_H_

#include "FsObject.h"
#include "FsMacros.h"

NS_FS_BEGIN

enum 
{
	FS_EASE_IN=0,
	FS_EASE_OUT=1,
	FS_EASE_INOUT=2,
	FS_EASE_OUTIN=3,
};


class EaseExpr:public FsObject 
{
	public:
		float getValue(float t);
		void setMode(int mode);
		int getMode();

	public:
		virtual float getEaseIn(float t)=0;
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);


		/* inherit FsObject */
		const char* className();

	protected:
		EaseExpr(int mode=FS_EASE_IN);
		virtual ~EaseExpr();

	private:
		int m_easeMode;

};

NS_FS_END 
#endif /*_FS_EASE_EXPR_H_*/


