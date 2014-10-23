#include "FsMacros.h"
#include "Box2D/Common/b2Draw.h"
#include "graphics/material/FsMaterial2D.h"
#include "graphics/shader/FsProgram.h"


NS_FS_BEGIN

class Mat_V4F;
class fb2Draw:public b2Draw 
{
	public:
		fb2Draw(float32 ratio);
    	virtual ~fb2Draw();

	public:
    	/// Draw a closed polygon provided in CCW order.
		virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) ;

		/// Draw a solid closed polygon provided in CCW order.
		virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) ;

		/// Draw a circle.
		virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) ;

		/// Draw a solid circle.
		virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) ;

		/// Draw a line segment.
		virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) ;

		/// Draw a transform. Choose your own length scale.
		/// @param xf a transform.
		virtual void DrawTransform(const b2Transform& xf) ;

	private:
		float32 m_ratio;
		Material2D* m_material;
		Program* m_program;
};



NS_FS_END
