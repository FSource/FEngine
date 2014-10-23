#ifndef _FS_QUAD_2D_H_
#define _FS_QUAD_2D_H_ 

#include <vector>
#include "FsMacros.h"
#include "FsEnums.h"
#include "stage/entity/FsEntity.h"
#include "stage/entity/FsIMaterial2DEntity.h"
#include "math/FsRect2D.h"
#include "graphics/FsColor.h"
#include "math/FsVector2.h"
#include "math/FsVector4.h"
#include "math/FsVertices.h"

#include "graphics/material/FsMaterial2D.h"
#include "graphics/shader/FsProgram.h"

NS_FS_BEGIN
class Texture2D;

class Material2D;
class Program;

class Quad2D:public Entity,public IMaterial2DEntity
{
	public:
		enum 
		{
			MODE_COLOR,
			MODE_TEXTURE
		};

	public:
		static Quad2D* create(const Color4f& c,float width,float height);
		static Quad2D* create(const Color4f& c,const Rect2D& rect);

		static Quad2D* create();
		static Quad2D* create(const char* tex);
		static Quad2D* create(const char* tex,const Rect2D& rect);
		static Quad2D* create(const char* tex,float width,float height);


	public:

		/* texture */
		void setTexture(const char* tex);
		void setResourceUrl(const char* name);
		void setTexture(Texture2D* tex);
		Texture2D* getTexture();


		/* Rect2D */
		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();


		void setWidth(float width);
		void setHeight(float height);
		void setSize(float width,float height);
		float getWidth();
		float getHeight();
		void getSize(float* width,float* height);

		void setAnchorX(float x);
		void setAnchorY(float y);
		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		float getAnchorX();
		float getAnchorY();

	public:
		void setRegionRect(float x,float y,float w,float h);
		void setRegionRect(const Rect2D& rect);

		void setRegionCircle(float x,float y,float radius,int precision);
		void setRegionCircle(const Vector2& center,float radius,int precision);
		void setRegionCircle(float x,float y,float radius,
				float start_angle,float end_angle,
				int precision);
		void setRegionCircle(const Vector2& center,float radius,
				float start_angle,float end_angle,
				int precision);


		void setRegionEllipse(float x,float y,float a,float b,int precision);
		void setRegionEllipse(const Vector2& center,float a,float b,int precision);

		void setRegionEllipse(float x,float y,float a,float b,
				float start_angle,float end_angle,
				int precision);
		void setRegionEllipse(const Vector2& center,float a,float b,
				float start_angle,float end_angle,
				int precision);


		/* When Texture Size Change, You Should ReCall setRegionScale9 to Correct Region*/
		void setRegionScale9(float edge);
		void setRegionScale9(const Vector4& edge);
		void setRegionScale9(float l,float r,float b,float t);




	public:
		/* inherit Entity */
		virtual void draw(RenderDevice* rd,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();


	protected:
		Quad2D();
		~Quad2D();
		bool init();
		bool init(const char* tex);
		bool init(Texture2D* tex);
		bool init(const Color4f& c);


		void destruct();

		void calFinishVertics();
		void drawTextureMode(RenderDevice*);
		void drawColorMode(RenderDevice*);

		void setRenderMode(int value){m_renderMode=value;}
		int getRenderMode(){return m_renderMode;}

	private:
		float m_width,m_height;
		float m_anchorX,m_anchorY;

		Texture2D* m_texture;

		std::vector<Fs_V2F_T2F> m_rawVertices;
		std::vector<Fs_V2F_T2F> m_finishVertices;

		std::vector<Face3> m_faces;

		bool m_vertiesDirty;
		E_DrawMode m_vertiesMode;

		int m_renderMode;
};

NS_FS_END 



#endif /*_FS_QUAD_2D_H_*/

