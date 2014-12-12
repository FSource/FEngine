#ifndef _FS_PRESS_BUTTON_H_
#define _FS_PRESS_BUTTON_H_

#include <functional>
#include "FsMacros.h"


#include "stage/ui/FsStateButton.h"



NS_FS_BEGIN

class Program;
class Material2D;
class Texture2D;

class PressButton:public StateButton
{
	public:
		enum{
			STATE_ALL=-1,
			STATE_NORMAL=0,
			STATE_PRESS=1,
			STATE_DISABLE=2,
			STATE_NU=3,
			STATE_UNKOWN=4,
		};



	public:
		static PressButton* create();
		static PressButton* createWithDarkStyle(const char* filename,const Color4f& dark);
		static PressButton* createWithDarkStyle(Texture2D* tex,const Color4f& dark);

		static PressButton* createWithColorStyle(const char* filename,const Color4f& normal,const Color4f& press);
		static PressButton* createWithColorStyle(Texture2D* tex,const Color4f& normal,const Color4f& press);

		static PressButton* createWithScaleStyle(const char* filename,const Vector3& scale);
		static PressButton* createWithScaleStyle(Texture2D* tex,const Vector3& scale);


	public:
		/* inherit Entity*/
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();


	public:
		virtual void pressDown(float x,float y);
		virtual void pressMoveIn(float x,float y);
		virtual void pressMoveOut(float x,float y);
		virtual void pressUp(float x,float y);

		virtual void cancel();
		virtual void click();


	public:

		std::function<void(PressButton*,float,float)> onPressDown;
		std::function<void(PressButton*,float,float)> onPressMoveIn;
		std::function<void(PressButton*,float,float)> onPressMoveOut;
		std::function<void (PressButton*,float,float)> onPressUp;
		std::function<void(PressButton*)> onCancel;
		std::function<void(PressButton*)> onClick;

	public:  
		void setDisabled(bool value);
		bool getDisabled() const;

	protected:
		PressButton();
		virtual ~PressButton();


		void initWithDarkStyle(const char* filename,const Color4f& dark);
		void initWithDarkStyle(Texture2D* texture,const Color4f& dark);

		void initWithColorStyle(const char* filename,const Color4f& normal,const Color4f& press);
		void initWithColorStyle(Texture2D* texture,const Color4f& normal,const Color4f& press);

		void initWithScaleStyle(const char* filename,const Vector3& scale);
		void initWithScaleStyle(Texture2D* texture,const Vector3& scale);


	protected:
		/* bool focus */
		bool m_moveIn;
		bool m_disabled;

};


NS_FS_END

#endif /*_FS_PRESS_BUTTON_H_*/

















