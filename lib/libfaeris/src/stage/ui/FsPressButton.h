#ifndef _FS_PRESS_BUTTON_H_
#define _FS_PRESS_BUTTON_H_

#include "FsMacros.h"

#include "stage/entity/FsEntity.h"
#include "support/util/FsArray.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"
#include "math/easing/FsEaseExpr.h"
#include "math/FsVector3.h"
#include "math/FsVector2.h"





NS_FS_BEGIN 

class PressButton;
class PressButtonState 
{


	public:
		PressButtonState()
		{
			m_color=Color4f::WHITE;
			m_opacity=1.0;
			m_texture=NULL;
			m_size.set(0,0);
			m_anchor.set(0.5,0.5);
			m_rotate.set(0,0,0);
			m_scale.set(1,1,1);
			m_children=NULL;
		}

		~PressButtonState()
		{
			FS_SAFE_DEC_REF(m_texture);
			FS_SAFE_DEC_REF(m_children);
		}

	private:
		Texture2D* m_texture;
		Color4f m_color;
		float m_opacity;
		Vector2 m_size;
		Vector2 m_anchor;
		Vector3 m_rotate;
		Vector3 m_scale;
		FsArray* m_children;
		friend class PressButton;
};


class Program;
class ColorMaterial;
class Texture2D;

class PressButton:public Entity
{
	public:
		enum 
		{
			FLAG_COLOR= 0x1UL,
			FLAG_OPACITY= 0x2UL,
			FLAG_TEXTURE= 0x4UL,
			FLAG_SIZE=0x8UL,
			FLAG_ANCHOR =0x10UL,
			FLAG_ROTATE=0x20UL,
			FLAG_SCALE=0x40UL,
			FLAG_CHILDREN=0x80UL,
			FLAG_ALL= 0xFFUL,
		};

		enum{
			STATE_UNKOWN=-1,
			STATE_NORMAL=0,
			STATE_PRESS=1,
			STATE_DISABLE=2,
			STATE_NU=3,
			STATE_ALL=4,
		};

		class TweenInfo{
			public:
				TweenInfo()
				{
					m_easing=NULL;
					m_time=0;
				}
				~TweenInfo()
				{
					FS_SAFE_DEC_REF(m_easing);
				}

			public:
				EaseExpr* m_easing;
				float m_time;
		};


	public:
		static PressButton* create();
		static PressButton* createWithDarkStyle(const char* filename,const Color4f& dark);
		static PressButton* createWithDarkStyle(Texture2D* tex,const Color4f& dark);
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

	public:  /* Attribut And State Attribute Setting */
		/* color */
		void setColor(const Color4f& value);
		void setColor(int state,const Color4f& value);
		Color4f getColor() const;
		Color4f getColor(int state) const ;



		/* opacity */
		void setOpacity(float value);
		float getOpacity() const;

		void setOpacity(int state,float value);
		float getOpacity(int state) const;


		/* texture */
		void setTexture(const char* filename);
		void setTexture(const char* filename,float width,float height);
		void setTexture(const char* filename,const Vector2& size);
		void setTexture(Texture2D* tex);
		void setTexture(Texture2D* tex,float width,float height);
		void setTexture(Texture2D* tex,const Vector2& size);
		Texture2D* getTexture() const;




		void setTexture(int state,const char* filename);
		void setTexture(int state,const char* filename,float width,float height);
		void setTexture(int state,const char* filename,const Vector2& size);
		void setTexture(int state,Texture2D* tex);
		void setTexture(int state,Texture2D* tex,float width,float height);
		void setTexture(int state,Texture2D* tex,const Vector2& size);
		Texture2D* getTexture(int state) const;


		/* size */
		void setSize(const Vector2& size);
		void setSize(float x,float y);
		Vector2 getSize()const ;


		void setSize(int state,float x,float y);
		void setSize(int state,const Vector2& size);
		Vector2 getSize(int state) const;


		/* anchor */
		void setAnchor(float x,float y);
		void setAnchor(const Vector2& size);
		Vector2 getAnchor()const ;

		void setAnchor(int state,float x,float y);
		void setAnchor(int state,const Vector2& size);
		Vector2 getAnchor(int state)const ;



		/* rotate */
		void setRotate(int state,float x,float y,float z);
		void setRotate(int state,const Vector3& value);
		Vector3 getRotate(int state)const ;


		/* scale */
		void setScale(int state,float x,float y,float z);
		void setScale(int state,const Vector3& value);
		Vector3 getScale(int state)const ;

		/* child */
		void setChild(int state,FsArray* child);
		FsArray* getChild(int state)const;

		void setDisabled(bool value);
		bool getDisabled() const;


	public: /* tween info */
		void setTweenInfo(int from,int to,EaseExpr* easing,float time);

		void setTweenFlags(uint32_t flags);
		void clearTweenFlags();

		void addTweenFlags(uint32_t flags);
		void removeTweenFlags(uint32_t flags);

	public:
		virtual void update(float dt);
		virtual void draw(Render* render,bool update_matrix);

	protected:
		PressButton();
		virtual ~PressButton();

		bool init();
		void destruct();

		void updateTween(float dt);
		void setState(int st);

		void setAttributeWithState(PressButtonState* st);
		void setAttributeWithState(PressButtonState* from,PressButtonState* to,EaseExpr* easing,float percent);

		void markStateDirty();

		void initWithDarkStyle(Texture2D* texture,const Color4f& dark);
		void initWithScaleStyle(Texture2D* texture,const Vector3& scale);


	protected:

		/* Button State */
		PressButtonState m_states[STATE_NU];

		/* Tween Info */
		TweenInfo m_tweenInfo[STATE_NU][STATE_NU];
		uint32_t m_tweenFlags;


		PressButtonState*  m_tweenFromState;
		PressButtonState*  m_tweenToState;
		TweenInfo* m_curTween;
		float m_tweenTime;


		int m_curState;
		bool m_stateDirty; 

		/* Button Attribute */
		Texture2D* m_texture;
		Vector2 m_size;    /* When Size < 0, It Will Used Texture2D Size */
		Vector2 m_anchor;

		/* bool focus */
		bool m_moveIn;
		bool m_disabled;

		/* render */
		ColorMaterial* m_material;
		Program* m_program;

};



NS_FS_END

#endif /*_FS_PRESS_BUTTON_H_*/

















