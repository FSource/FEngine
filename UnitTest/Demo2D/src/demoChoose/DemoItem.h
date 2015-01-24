#ifndef _DEMO_ITEM_H
#define _DEMO_ITEM_H


#include <functional>
#include "demo3D.h"

NS_FS_BEGIN

class DemoChooseLayer;
class Scene;
class DemoItem
{
	public:
		DemoItem()
		{
			m_name=NULL;
			m_func=nullptr;
		}
		DemoItem(const char* name, std::function<Scene*()> func)
		{
			m_name = name;
			m_func = func;
		}
	public:
		const char* m_name;
		std::function<Scene*()> m_func;
};


NS_FS_END
#endif
