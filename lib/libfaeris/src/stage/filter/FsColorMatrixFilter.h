#ifndef _FS_COLOR_MATRIX_FILTER_H_
#define _FS_COLOR_MATRIX_FILTER_H_

#include "FsFilter.h"
#include "math/FsMatrix4.h"
#include "graphics/shader/FsUniformValue.h"

NS_FS_BEGIN

class UniformValue;

class ColorMatrixFilter:public Filter 
{
	public:
		static ColorMatrixFilter* create();

	public:
		void setColorMatrix(const Matrix4& mat);
		const Matrix4& getColorMatrix();
		void setColorOffset(const Vector4f& offset);
		const Vector4f& getColorOffset();

		void setSaturation(float value);
		void setBrightness(float b);
		void setContrast(float c);
		void setInvert();
		

		void setSepia();




	protected:
		ColorMatrixFilter();
		~ColorMatrixFilter();

	protected:
		UniformMat4f* m_colorMatrix;
		UniformValue4f* m_colorOffset;
};


NS_FS_END 


#endif /*_FS_COLOR_MATRIX_FILTER_H_*/

