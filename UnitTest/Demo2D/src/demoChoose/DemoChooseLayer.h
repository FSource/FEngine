#ifndef _DEMO_CHOOSE_LAYER_H
#define _DEMO_CHOOSE_LAYER_H
#include <vector>

#include "demo3D.h"


NS_FS_BEGIN 
class DemoItem;
class DemoChooseLayer:public Layer2D
{
	public:
		static DemoChooseLayer* create();
		virtual bool init();

		void initItems();
		
		void initValue();
		void initDemoPage();


	protected:
		DemoChooseLayer();
	public:
		int m_pageNumber;
		int m_curPageNumber;

		int m_rowNumber;//一页的行数
		int m_colNumber;//一页的列数

		float m_pageW;
		float m_pageH;

		float m_wBorder;
		float m_hBorder;

		float m_itemW;
		float m_itemH;


		std::vector<DemoItem*> m_demoItems;
};

NS_FS_END

#endif
