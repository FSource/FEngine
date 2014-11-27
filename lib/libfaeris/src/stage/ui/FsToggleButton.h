#ifndef _FS_TOGGLE_BUTTON_H_
#define _FS_TOGGLE_BUTTON_H_

#include <functional>
#include "FsMacros.h"
#include "FsStateButton.h"

NS_FS_BEGIN 

class ToggleButton:public StateButton 
{
	public:
		enum 
		{
			STATE_ALL=-1,
			STATE_ON=0,
			STATE_OFF=1,
			STATE_DISABLE=2,
			STATE_NU=3,
		};

	public:
		static ToggleButton* create();
		static ToggleButton* createWithColorStyle(const char* filename,
											const Color4f& on,
											const Color4f& off);

		static ToggleButton* createWithColorStyle(Texture2D* tex,
												const Color4f& on,
												const Color4f& off);

		static ToggleButton* createWithTextureStyle(const char* fileon,const char* fileoff);
		static ToggleButton* createWithTextureStyle(Texture2D* on,Texture2D* off);

	public:
		/* inherit Entity*/
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);
		virtual bool hit2D(float x,float y);


		/* inherit FsObject */
		virtual const char* className();

	public:
		virtual void toggleChanged(bool value);

	public:
		std::function<void(ToggleButton*,bool)> onToggleChanged;


	public:
		void setDisabled(bool value);
		bool getDisabled() const;

		void setToggle(bool value,bool callback=false);
		bool getToggle() const;


	protected:
		ToggleButton();
		~ToggleButton();

		void initWithDarkStyle(const char* filename,const Color4f& dark);
		void initWithDarkStyle(Texture2D* tex,const Color4f& dark);


		void initWithColorStyle(const char* filename,const Color4f& on,const Color4f& off);
		void initWithColorStyle(Texture2D* tex,const Color4f& on,const Color4f& off);


		void initWithTextureStyle(const char* fileon,const char* fileoff);
		void initWithTextureStyle(Texture2D* on,Texture2D* off);

	protected:
		bool m_toggleState;
		bool m_disabled;

};



NS_FS_END 

#endif /*_FS_TOGGLE_BUTTON_H_*/


