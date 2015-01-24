/*************************************************************************/
/*  FsProcessBar.h                                                       */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#ifndef _FS_PROCESS_BAR_H_
#define _FS_PROCESS_BAR_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
//#include "FsUiWidget.h"


NS_FS_BEGIN 

class ProcessBar:public Entity2D
{
	public:
		FS_CLASS_DECLARE(ProcessBar);

	public:
		static ProcessBar* create();
		static ProcessBar* create(const char* bg,const char* fg);
		static ProcessBar* create(Texture2D* bg,Texture2D* fg);

	public:
		void setPercent(float value);
		float getPercent();

		void setDirection(E_AxisDirection dr);
		E_AxisDirection getDirection();

	public:
		void setBackgroundTexture(const char* filename);
		void setBackgroundTexture(Texture2D* tex);
		Texture2D* getBackgroundTexture();

		void setForegroundTexture(const char* filename);
		void setForegroundTexture(Texture2D* tex);
		Texture2D* getForegroundTexture();

		void setReverseDirection(bool value);
		bool getReverseDirection();


	public:
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	protected:
		ProcessBar();
		~ProcessBar();

		void initWithTexture(const char* bg,const char* fg);
		void initWithTexture(Texture2D* bg,Texture2D* fg);

	protected:
		Texture2D* m_backgroundTexture;
		Texture2D* m_foregroundTexture;
		float m_percent;
		E_AxisDirection m_direction;
		bool m_reverseDirection;

};


NS_FS_END 


#endif /*_FS_PROCESS_BAR_H_*/



