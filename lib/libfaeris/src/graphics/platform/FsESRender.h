#ifndef _FS_GL_ES_RENDER_H_
#define _FS_GL_ES_RENDER_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "graphics/FsColor.h"
#include "graphics/FsRenderTarget.h"

#include "math/FsMatrix4.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "math/FsRect2D.h"


NS_FS_BEGIN
class Material;
class FsString;
class Program;
class Texture2D;

class Render:public FsObject 
{
	public:
		enum 
		{
			/* front side */
			FRONT_CCW,
			FRONT_CW,

			/* cull face */
			FACE_CULL,

			/* blend equation */
			EQUATION_NONE,
			EQUATION_ADD,
			EQUATION_SUBTRACT,
			EQUATION_REVERSE_SUBTRACT,

			/* blend factor */
			FACTOR_ZERO,
			FACTOR_ONE,
			FACTOR_SRC_COLOR,
			FACTOR_ONE_MINUS_SRC_COLOR,
			FACTOR_DST_COLOR,
			FACTOR_ONE_MINUS_DST_COLOR,
			FACTOR_SRC_ALPHA,
			FACTOR_ONE_MINUS_SRC_ALPHA,
			FACTOR_DST_ALPHA,
			FACTOR_ONE_MINUS_DST_ALPHA,
			FACTOR_SRC_ALPHA_SATURATE,

			/* element */
			POINTS,
			LINES,
			LINE_STRIP,
			LINE_LOOP,
			TRIANGLES,
			TRIANGLE_STRIP,
			TRIANGLE_FAN,

			/* uniform */

			/* float vec2 vec3 vec4 */
			U_F_1=0,
			U_F_2,
			U_F_3,
			U_F_4,

			/* int ivec2 ivec3 ivec4 */
			U_I_1,
			U_I_2,
			U_I_3,
			U_I_4,

			/* unsigned int uvec2 uvec3 uvec4 */
			U_UI_1,
			U_UI_2,
			U_UI_3,
			U_UI_4,

			/* mat2 mat3 mat4 */
			U_M_2,
			U_M_3,
			U_M_4,

			/* sampler */
			U_S_1D,         /* sampler1D,sampler2D,sampler3D */
			U_S_2D,
			U_S_3D,
			U_S_CUBE,       /* samplerCube */
			U_S_1D_SHADOW,  /* sampler1DShadow, sampler2DShadow */
			U_S_2D_SHADOW,

			U_MAX_NU,
		};
	public:
		static Render* create();
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
		void swapBuffers();

		/* color */
		void setClearColor(Color4f c){m_clearColor=c;}
		Color4f getClearColor(){return  m_clearColor;}
		void clear(bool color=true,bool depth=false,bool stencil=false);

		void setColor(Color4f c){m_color=c;};
		Color4f getColor(){return m_color;}

		void setOpacity(float opacity){m_opacity=opacity;}
		float getOpacity(){return m_opacity;}



		/* transform */
		void setProjectionMatrix(const Matrix4* mat);
		void pushMatrix();
		void popMatrix();
		void loadIdentity();
		void mulMatrix(const  Matrix4* m);
		void setMatrix(const Matrix4* m);
		void translate(const Vector3& s);
		void scale(const Vector3& s);
		void rotate(const Vector3& v,float angle);

		Matrix4* getProjectionMatrix();
		Matrix4* getMatrix();
		Matrix4* getMVPMatrix();


		/* vertex pointer */
		void disableAllAttrArray();
		void enableAttrArray(int index);
		void disableAttrArray(int index);
		void setVertexAttrPointer(int index,int size,int type,
								  int count,int stride,void* pointer);
		void setAndEnableVertexAttrPointer(int index,int size,int type,
								  int count,int stride,void* pointer);


		void drawFace3(Face3* f,uint num);
		void drawArray(int mode,int start,uint size);


		/* set opengl state */
		void setViewport(int x,int y,int width,int height);
		void setScissorArea(float x,float y,float width,float height);
		void setScissorArea(const Rect2D& area);
		Rect2D getScissorArea();
		void setScissorEnabled(bool enable);
		bool getScissorEnabled();

		void setDepthTest(bool enable);

		/* blend */
		void setBlend(int eq,int fsrc,int fdst);

		/* Uniform  Add Attibute */
		void setUniform(int loc,int type,int count,void* value);

		int getUniformLocation(const char* name);
		int getAttrLocation(const char* name);
		int getCacheUniformLocation(int index,const char* name);
		int getCacheAttrLocation(int index,const char* name);



	protected:
		Render();
		~Render();
		void _setGLScissor(const Rect2D& scissor_area);

	private:
		RenderTarget* m_target;

		Program* m_program;

		/* cache GL State */
		Color4f m_clearColor;
		Color4f m_color;
		float m_opacity;


		bool m_scissorEnable;
		Rect2D m_scissorArea;
		bool m_depthTest;
		
		int m_viewportX,m_viewportY,m_viewportWidth,m_viewportHeight;

		/* blend */
		int m_blendEquation;
		int m_blendSrc;
		int m_blendDst;

		/* face */
		int m_frontFace;
		bool m_cullFace;

		/* texture */
		int m_activeTextureId;

		/* vertex attr array flags[] */
		bool* m_vertexAttrFlags;
		int m_vertexAttrEnableNu;
		int m_vertexAttrMaxNu;

		/* transform */
		int m_stackIndex;
		Matrix4 m_stack[FS_MAX_RENDER_STACK_NU];

		/* projection matrix */
		Matrix4 m_projMatrix;

		/* model view projection matrix */
		bool m_mvpDirty;
		Matrix4 m_mvpMatrix;
};





NS_FS_END


#endif /*_FS_GL_ES_RENDER_H_*/












