/*************************************************************************/
/*  FsSprite2DDataMgr.cc                                                 */
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


#include "mgr/FsSprite2DDataMgr.h"
#include "stage/entity/FsSprite2DData.h"


NS_FS_BEGIN 

Sprite2DDataMgr* Sprite2DDataMgr::create()
{
	return new Sprite2DDataMgr();
}

Sprite2DData* Sprite2DDataMgr::loadSprite2DData(const char* name)
{
	return (Sprite2DData*) load(name);
}


const char* Sprite2DDataMgr::className()
{
	return FS_SPRITE_2D_DATA_MGR_CLASS_NAME;
}


Sprite2DDataMgr::Sprite2DDataMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc) Sprite2DData::create)
{
}


Sprite2DDataMgr::~Sprite2DDataMgr()
{
}

NS_FS_END 



