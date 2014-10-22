#ifndef _FS_GL_ES_RENDER_H_
#define _FS_GL_ES_RENDER_H_

#include "FsMacros.h"
#include "FsEnums.h"


#include "FsObject.h"
#include "graphics/FsColor.h"
#include "graphics/FsRenderTarget.h"

#include "math/FsMatrix4.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "math/FsRect2D.h"

#include "sys/FsTimer.h"


NS_FS_BEGIN


class Material;
class FsString;
class Program;
class Texture2D;
class UniformValue;


class RenderDevice:public FsObject 
{
	public:
		static RenderDevice* create();
		static int sizeofUniformType(int type);
		static int uniformTypeComponent(int type);

	public:
		virtual const char* className();

	public:
		void setProgram(Program* prog);

		/* texture */
		void bindTexture(Texture2D* tex,int slot);

		/* render target */
		void setRenderTarget(RenderTarget* target);
		RenderTarget* getRenderTarget();
		void swapBuffers();


		void clear(bool color=true,bool depth=false,bool stencil=false);


		/* color */
		void setClearColor(Color4f c){m_clearColor=c;}
		Color4f getClearColor(){return  m_clearColor;}


		void setColor(Color4f c){m_color=c;};
		Color4f getColor(){return m_color;}


		void setOpacity(float opacity){m_opacity=opacity;}
		float getOpacity(){return m_opacity;}


		/* set viewport */
		void setViewport(int x,int y,int width,int height);

		/* scissor area  */
		void setScissorArea(float x,float y,float width,float height);
		void setScissorArea(const Rect2D& area);
		Rect2D getScissorArea();

		void setScissorEnabled(bool enable);
		bool getScissorEnabled();


		/* depth */
		void setDepthTestEnabled(bool enable);
		bool getDepthTestEnabled(){return m_depthTest;}
		void setDepthWriteEnabled(bool enable);
		bool getDepthWrirteEnabled(){return m_depthWrite;}


		/* blend */
		void setBlend(E_BlendEquation eq,E_BlendFactor src,E_BlendFactor fdst);

		/* double side */
		void setDoubleSideEnabled(bool value);
		bool getDoubleSideEnabled(){return m_doubleSideEnabled;}


		/* projection matrix */
		void setProjectionMatrix(const Matrix4* mat);
		Matrix4* getProjectionMatrix();

		/* view matrix */
		void setViewMatrix(const Matrix4* mat);
		Matrix4* getViewMatrix();

		/* world matrix */
		void setWorldMatrix(const Matrix4* m);
		Matrix4* getWorldMatrix();

		void pushWorldMatrix();
		void popWorldMatrix();

		void loadWorldIdentity();
		void mulWorldMatrix(const  Matrix4* m);

		void translateWorldMatrix(const Vector3& s);
		void scaleWorldMatrix(const Vector3& s);
		void rotateWorldMatrix(const Vector3& v,float angle);

		Matrix4* getMatrix(E_UniformRef t);



		/* Attribute */
		int getAttrLocation(const char* name);
		int getCacheAttrLocation(int index,const char* name);

		void disableAllAttrArray();
		void enableAttrArray(int index);
		void disableAttrArray(int index);
		void setVertexAttrPointer(int index,int size,int type,
								  int count,int stride,void* pointer);
		void setAndEnableVertexAttrPointer(int index,int size,int type,
								  int count,int stride,void* pointer);



		/* Uniform */
		int getUniformLocation(const char* name);
		int getCacheUniformLocation(int index,const char* name);

		void setUniform(int loc,int type,int count,void* value);
		void setUniform(int loc,UniformValue* v);




		/* draw face */
		void drawFace3(Face3* f,uint num);
		void drawArray(E_DrawMode mode,int start,uint size);


	protected:
		RenderDevice();
		~RenderDevice();
		void _setGLScissor(const Rect2D& scissor_area);

	private:
		Timer m_timer;

		RenderTarget* m_target;
		Program* m_program;

		/* cache GL State */
		Color4f m_clearColor;

		Color4f m_color;

		float m_opacity;


		bool m_scissorEnable;
		Rect2D m_scissorArea;

		bool m_depthTest;
		bool m_depthWrite;
		
		int m_viewportX,m_viewportY,m_viewportWidth,m_viewportHeight;

		/* blend */
		E_BlendEquation m_blendEquation;
		E_BlendFactor m_blendSrc;
		E_BlendFactor m_blendDst;

		/* face */
		//int m_frontSided;
		bool m_doubleSideEnabled;

		/* texture */
		int m_activeTextureId;

		/* vertex attr array flags[] */
		bool* m_vertexAttrFlags;
		int m_vertexAttrEnableNu;
		int m_vertexAttrMaxNu;

		/* world matrix */
		int m_worldStackIndex;
		Matrix4 m_world[FS_MAX_RENDER_STACK_NU];

		/* projection matrix */
		Matrix4 m_projMatrix;
		Matrix4 m_viewMatrix;

		/* model view projection matrix */
		uint32_t m_matrixDirtyFlags;
		Matrix4 m_cacheMatrix[E_UniformRef::R_MAX_MATRIX_NU];

};






NS_FS_END


#endif /*_FS_GL_ES_RENDER_H_*/












