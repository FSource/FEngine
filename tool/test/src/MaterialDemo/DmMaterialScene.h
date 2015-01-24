/*************************************************************************/
/*  DmMaterialScene.h                                                    */
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
#ifndef _DM_MATERIAL_SCENE_H_
#define _DM_MATERIAL_SCENE_H_

#include <vector>
#include "demo3D.h"
#include "DmColorSlider.h"
#include "DmMaterialListItem.h"

NS_FS_BEGIN
class DmMaterialScene:public Scene 
{
	public:
		static DmMaterialScene* create();


	public:
		void setMaterial(const char* name,const char* cname,Material3D* mtl);


	protected:
		void init();

		void initLayer3D();
		void initObjects();
		void initCamera();
		void initLight();

		void initLayer2D();
		void initColorSlider();

		void initMaterials();

		DmMaterialScene();
		~DmMaterialScene();


		void setShininessValue(float value);
	protected:
		Layer3D* m_layer3D;
		Layer2D* m_layer2D;

		Sprite3D* m_monkey;
		Material3D* m_material;

		LabelTTF* m_materialName;

		DmColorSlider* m_ambientSlider;
		DmColorSlider* m_diffuseSlider;
		DmColorSlider* m_specularSlider;

		DmMaterialListItem* m_focusMaterialItem;

		DmSlideBar* m_shininessSilder;
		LabelTTF* m_shininessValue;
};



NS_FS_END 



#endif /*_DM_MATERIAL_SCENE_H_*/


