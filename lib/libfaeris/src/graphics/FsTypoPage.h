#ifndef _FS_TYPO_PAGE_H_
#define _FS_TYPO_PAGE_H_

#include "FsMacros.h"
#include "FsObject.h"



class TypoGlyph:public FsObject 
{
	public:
		virtual void getBound(int* minx,int* miny,int* maxx,int* maxy)=0;
		virtual int getAdvanceX()=0;
		virtual int getAscend()=0;
		virtual int getDescend()=0;
		virtual int getHeight()=0;

	public:
		TypoGlyph();
		virtual ~TypoGlyph();
};


template <typename T_Data>
class TypoText
{
	public:
		TypoText(TypoGlyph* g,const Vector2& pen)
		{
			m_glyph=g;
			float minx,miny,maxx,maxy;
			m_glyph->getBound(&minx,&miny,&maxx,&maxy);
			m_vertices[0].x=pen.x+minx;
			m_vertices[0].y=pen.y+miny;
			m_vertices[1].x=pen.x+maxx;
			m_vertices[1].y=pen.y+miny;
			m_vertices[2].x=pen.x+minx;
			m_vertices[2].y=pen.y+maxy;
			m_vertices[3].x=pen.x+maxx;
			m_vertices[3].y=pen.x+maxy;
		}

	public:
		void applyShift(float x,float y)
		{
			for(int i=0;i<4;i++)
			{
				m_vertices[i].x+=sx;
				m_vertices[i].y+=sy;
			}
		}

		float getMinx() { return m_vertices[0].x; }
		float getMiny() { return m_vertices[0].y; }
		float getMaxx() { return m_vertices[3].x; }
		float getMaxy() { return m_vertices[3].y; }

		void getAscend() {return m_glyph->getAscend();}
		void getDescend() {return m_glyph->getDescend();}

	public:
		Vector2[4] m_vertices;
		T_Data m_userData;
		TypoGlyph* m_glyph;
};

template <typename T_Data>
class TypoLine
{
	public:
		TypoLine()
		{
			m_minx=0;
			m_maxx=0;
			m_miny=0;
			m_maxy=0;
			m_ascend=0;
			m_descend=0;
		}

		~TypoLine()
		{
			clearText();
		}

	public:
		int getTextNu()
		{
			return m_texts.size();
		}
		TypoText* getText(int i)
		{
			return &m_texts[i];
		}
		TypoText* pushText(TypoGlyph* g,const Vector2& pen)
		{
			FS_SAFE_ADD_REF(g);
			m_texts.push_back(TypoText(g,pen));
			TypoText* ret=&m_texts.back();

			if(m_minx>ret->getMinx()) { m_minx=ret->getMinx();}
			if(m_miny>ret->getMiny()) { m_miny=ret->getMiny();}
			if(m_maxx<ret->getMaxx()) { m_maxx=ret->getMaxx();}
			if(m_maxy<ret->getMaxy()) { m_maxy=ret->getMaxy();}
			if(m_ascend<ret->getAscend()) {m_ascend=ret->getAscend();}
			if(m_ascend<ret->getDescend()) {m_ascend=ret->getDescend();}
			return ret;
		}

		void clearText()
		{
			int size=m_texts.size();
			for(int i=0;i<size;i++)
			{
				m_texts[i].m_glyph->decRef();;
			}
			m_texts.clear();
			m_minx=0;
			m_miny=0;
			m_maxx=0;
			m_maxy=0;
		}

		float getMinx(){return m_minx;}
		float getMiny(){return m_miny;}
		float getMaxx(){return m_maxx;}
		float getMaxy(){return m_maxy;}
		
		void applyShift(float x,float y);

		void setHeight(float height){m_height=height;}
		float getHeight()
		{
			if(m_height!=0)
			{
				return m_height;
			}
			else 
			{
				return m_ascend+m_descend;
			}
		}

	public:
		std::vector<TypoText<T_Data>> m_texts;
		float m_minx,m_miny,m_maxx,m_maxy;
		float m_ascend,m_descend;
		float m_height;

};


template <typename T_Data>
class TypoPage
{
	public:
		TypoPage(float page_width,float page_height,float line_height,float line_gap);
		~TypoPage();

	public:
		void typoBegin()
		{
			clearLines();
			FS_SAFE_DELETE(m_current);
			m_curHeight=0;
			m_curWidth=0;
			m_lastHeight=m_lineHeight;
			m_pen=Vector2(0,0);
			if(m_pageHeight!=0 && m_lineHeight> m_pageHeight)
			{
				m_done=true;
			}
		}

		TypoText<T_Data>* pushText(TypoGlyph* g)
		{
			bool new_line=false;

			if (m_current==NULL)
			{
				m_current=new TypoLine<T_Data*>;
			}

			if(g->getChar()=='\n')
			{
				pushCurLine();
			}

			do{
				if (m_current==NULL)
				{
					m_current=new TypoLine<T_Data*>;
				}
				int minx,miny,maxx,maxy;
				g->getBound(&minx,&miny,&maxx,&maxy);
				if(m_pen.x +minx <0) { m_pen.x=-minx; }
				float height=g->getAscend()+g->getDescend();
				if(!canExpandHeight(height))
				{
					m_done=true;
					delete m_current;
					return NULL;
				}

				if((m_width!=0)&&(m_pen.x+maxx>m_width))
				{
					if(m_current->getTextNu()==0)
					{
						m_done=true;
						return NULL;
					}

					pushCurLine();
					if(m_done)
					{
						return NULL;
					}
				}
				else 
				{
					TypoText<T_Data>* ret=m_current->pushText(g,m_pen);
					return ret;
				}
			}while(1);
		}

		void typoEnd()
		{
			if(m_lines.size()==0)
			{
				return;
			}
			TypoLine<T_Data>* first_line=m_lines[0];

			float shifty=first_line->getAscend();
			first_line->applyShift(0,-shifty);

			shifty+=first_line->getHeight()+m_lineGap;


			int size=m_lines.size();

			for(int i=1;i<size;i++)
			{
				TypoLine<T_Data>* line=m_lines[i];
				line->applyShift(0,-shifty);
				shifty+=line->getHeight();
			}
		}



		void clearText();
		float getMinx();
		float getMiny();
		float getMaxx();
		float getMaxy();
		float getBound(float* minx,float* miny,float* maxx,float* maxy);
		float applyShift(float x,float y);

		void setAlign(int h,int v);

	protected:
		void pushCurLine()
		{
			if(m_current->getTextNu()==0)
			{
				m_current->setHeight(m_lastHeight);
			}
			else 
			{
				m_lastHeight=m_current->getHeight();
			}
			m_lines.push_back(m_current);
			m_current=NULL;

			if(m_lines.size()==0)
			{
				m_curHeight=m_lastHeight;
			}
			else 
			{
				m_curHeight=m_lastHeight+m_lineGap;
			}
			if ((m_pageHeight!=0)&&(m_curHeight+m_lastHeight+m_lineGap>m_pageHeight))
			{
				m_done=true;
			}
			m_pen=Vector(0,0);
		}


	private:
		std::vector<TypoLine<T_Data>*> m_lines;
		TypoLine* m_current;
		float m_curWidth,m_curHeight;
		float m_pageWidth,m_pageHeight;
		bool m_done;
};



class 








#endif /*_FS_TYPO_PAGE_H_*/

