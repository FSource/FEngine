/*************************************************************************/
/*  DmLightScene.h                                                       */
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
#ifndef _DM_LIGHT_SCENE_H_
#define _DM_LIGHT_SCENE_H_ 

#include <vector>

#include "demo3D.h"

NS_FS_BEGIN

class DmLightScene:public Scene
{
	public:
		static DmLightScene* create();

	public:



	protected:

		bool init();
		void initBackLayer();
		void initLayer2D();
		void initButtons();
		void goBack();

		void initLayer3D();


		void init3DObject();
		void initAmbientLight();
		void initPointLight();
		void initDirectionLight();
		void initHemiSphereLight();
		void initCamera();
		void initSpotLight();



		DmLightScene();

	private:
		Layer2D* m_layer2D;
		Layer3D* m_layer3D;

		AmbientLight* m_ambientLight;
		std::vector<PointLight*> m_pointLight;
		DirectionalLight* m_dirLight;
		HemiSphereLight* m_hemiSphereLight;
		SpotLight* m_spotLight;


		Camera* m_camera;




};

NS_FS_END

#endif
