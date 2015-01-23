/*************************************************************************/
/*  DmMaterialListItem.h                                                 */
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
#ifndef _DM_MATERIAL_LIST_ITEM_H_
#define _DM_MATERIAL_LIST_ITEM_H_

#include "demo3D.h"

NS_FS_BEGIN

class DmMaterialListItem:public UiWidget 
{
	public:
		static DmMaterialListItem* create(const char* name,const char* cname,const char* mtl);

	public:
		void setFocus(bool value);

	public:
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;

		const char* getName(){return m_name.c_str();}
		const char* getMaterial(){return m_material.c_str();}
		const char* getCName(){ return m_cname.c_str();}

	public:
		std::function<void(DmMaterialListItem*)> onClick;

	protected:
		DmMaterialListItem(const char* name,const char* cname,const char* mtl);

	private:
		bool m_focus;
		std::string m_name;
		std::string m_material;
		std::string m_cname;
		int m_moveTime;
};


NS_FS_END 

#endif /*_DM_MATERIAL_LIST_ITEM_H_*/

