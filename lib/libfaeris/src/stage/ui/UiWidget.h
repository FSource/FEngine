#include "FsMacros.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

class UiWidget:public Entity 
{
	public:
		static UiWidget* create(float width,float height);

	public:
		virtual const char* className();

		virtual bool hit2D(float x,float y);

	public:
		virtual void setSize(float width,float height);
		Vector2 getSize();

		float getWidth();
		float getHeight();

		void setScissor(bool clip);
		bool getScissor();


		virtual void setAnchor(float x,float y);
		float getAnchorX();
		float getAnchorY();
		Vector2 getAnchor();


	protected:
		UiWidget();
		virtual ~UiWidget();


		virtual void childSizeChanged(float w,float h);
		virtual void childAnchorChanged(float x,float y);

		void setParentWidget(UiWidget* widget);
		UiWidget* getParentWidget();

	protected:
		FS_FEATURE_WEAK_REF(UiWidget*) m_parentWidget;
		bool m_scissor;
		Vector2 m_size;
		Vector2 m_anchor;
};




NS_FS_END 



