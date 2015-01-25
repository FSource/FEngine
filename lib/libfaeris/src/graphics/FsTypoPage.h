/*************************************************************************/
/*  FsTypoPage.h                                                         */
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


#ifndef _FS_TYPO_PAGE_H_
#define _FS_TYPO_PAGE_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"
#include "math/FsVector2.h"
#include "FsEnums.h"

NS_FS_BEGIN

class TypoGlyph:public FsObject 
{
	public:
		virtual uint16_t getChar()=0;
		virtual void getBound(int* minx,int* miny,int* maxx,int* maxy)=0;
		virtual int getAdvanceX()=0;
		virtual int getAscend()=0;
		virtual int getDescend()=0;
		virtual int getHeight()=0;

	public:
		TypoGlyph(){}
		virtual ~TypoGlyph(){}
};



class TypoText
{
	public:
		TypoText(TypoGlyph* g,const Vector2& pen,float scale)
		{
			m_glyph=g;
			g->addRef();
			int iminx,iminy,imaxx,imaxy;
			m_glyph->getBound(&iminx,&iminy,&imaxx,&imaxy);

			float minx=iminx*scale;
			float miny=iminy*scale;
			float maxx=imaxx*scale;
			float maxy=imaxy*scale;

			m_vertices[0].x=pen.x+minx;
			m_vertices[0].y=pen.y+miny;

			m_vertices[1].x=pen.x+maxx;
			m_vertices[1].y=pen.y+miny;

			m_vertices[2].x=pen.x+minx;
			m_vertices[2].y=pen.y+maxy;

			m_vertices[3].x=pen.x+maxx;
			m_vertices[3].y=pen.y+maxy;

			m_scale=scale;
		}
		virtual ~TypoText()
		{
			FS_SAFE_DEC_REF(m_glyph);
		}


	public:
		void applyShift(float x,float y)
		{
			for(int i=0;i<4;i++)
			{
				m_vertices[i].x+=x;
				m_vertices[i].y+=y;
			}
		}

		float getMinx() { return m_vertices[0].x; }
		float getMiny() { return m_vertices[0].y; }
		float getMaxx() { return m_vertices[3].x; }
		float getMaxy() { return m_vertices[3].y; }

		float getAscend() {return (float)m_glyph->getAscend()*m_scale;}
		float getDescend() {return (float)m_glyph->getDescend()*m_scale;}


	public:
		Vector2 m_vertices[4];
		TypoGlyph* m_glyph;
		float m_scale;
};


template <typename T_TypoText>
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
			m_height=0;
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
			return m_texts[i];
		}

		TypoText* pushText(TypoGlyph* g,const Vector2& pen,float scale)
		{
			T_TypoText* text=new T_TypoText(g,pen,scale);
			m_texts.push_back(text);

			if(m_minx>text->getMinx()) { m_minx=text->getMinx();}
			if(m_miny>text->getMiny()) { m_miny=text->getMiny();}
			if(m_maxx<text->getMaxx()) { m_maxx=text->getMaxx();}
			if(m_maxy<text->getMaxy()) { m_maxy=text->getMaxy();}
			if(m_ascend<text->getAscend()) {m_ascend=text->getAscend();}
			if(m_descend>text->getDescend()) {m_descend=text->getDescend();}
			return text;
		}

		void clearText()
		{
			int size=m_texts.size();
			for(int i=0;i<size;i++)
			{
				delete m_texts[i];
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
		float getAscend(){return m_ascend;}
		float getDescend(){return m_descend;}
		
		void applyShift(float x,float y)
		{
			int size=m_texts.size();
			for(int i=0;i<size;i++)
			{
				m_texts[i]->applyShift(x,y);
			}
		}

		float getWidth()
		{
			return getMaxx()-getMinx();
		}

		void setHeight(float height)
		{
			m_height=height;
		}
		float getHeight()
		{
			if(m_height!=0)
			{
				return m_height;
			}
			else 
			{
				return m_ascend-m_descend+1;
			}
		}

	public:
		std::vector<T_TypoText*> m_texts;
		float m_minx,m_miny,m_maxx,m_maxy;
		float m_ascend,m_descend;
		float m_height;

};


template <typename T_TypoText>
class TypoPage
{
	public:
		TypoPage()
		{
			m_current=NULL;
			m_curWidth=0;
			m_curHeight=0;
			m_pageWidth=0;
			m_pageHeight=0;
			m_relWidth=0;
			m_relHeight=0;
			m_lastHeight=0;
			m_lineGap=0;
			m_done=false;
			m_pen.set(0,0);
		}
		~TypoPage()
		{
			clearText();
		}

	public:
		void typoBegin(float page_width,float page_height,float line_height,float line_gap)
		{
			clearText();

			m_pageWidth=page_width;
			m_pageHeight=page_height;


			m_relWidth=0;
			m_relHeight=0;

			m_curHeight=0;
			m_curWidth=0;

			m_lastHeight=line_height;

			m_lineGap=line_gap;

			m_pen=Vector2(0,0);
			m_done=false;

			m_anchorX=0.5;
			m_anchorY=0.5;

			if(m_pageHeight!=0 && line_height> m_pageHeight)
			{
				m_done=true;
			}
		}

		T_TypoText* pushText(TypoGlyph* g,float scale)
		{

			if (m_current==NULL)
			{
				m_current=new TypoLine<T_TypoText>;
			}

			if(g->getChar()=='\n')
			{
				pushCurLine();
				return NULL;
			}

			do{
				if (m_current==NULL)
				{
					m_current=new TypoLine<T_TypoText>;
				}
				int iminx,iminy,imaxx,imaxy;
				g->getBound(&iminx,&iminy,&imaxx,&imaxy);
				float minx=iminx*scale;
				//float miny=iminy*scale;
				float maxx=imaxx*scale;
				//float maxy=imaxy*scale;

				if( m_current->getTextNu()== 0)
				{
					m_pen.x=-float(minx);
				}

				float height=float(g->getHeight())*scale;
				if(!canExpandHeight(height))
				{
					m_done=true;
					delete m_current;
					return NULL;
				}

				if((m_pageWidth!=0)&&(m_pen.x+maxx>m_pageWidth))
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
				
					T_TypoText* ret=m_current->pushText(g,m_pen,scale);
					m_pen.x+=g->getAdvanceX()*scale;

					return ret;
				}
			}while(1);
		}

		void typoEnd()
		{

			if((!m_done)&&m_current)
			{
				pushCurLine();
			}
			if(m_lines.size()==0)
			{
				return;
			}



			TypoLine<T_TypoText>* first_line=m_lines[0];
			float ascend=first_line->getAscend();
			first_line->applyShift(0,-ascend);

			float width=first_line->getWidth();
			float height=first_line->getHeight();

			float shifty=first_line->getHeight()+m_lineGap;

			int size=m_lines.size();

			for(int i=1;i<size;i++)
			{
				TypoLine<T_TypoText>* line=m_lines[i];
				ascend=line->getAscend();
				line->applyShift(0,-shifty-ascend);
				shifty+=line->getHeight()+m_lineGap;
				if(width<line->getWidth()){width=line->getWidth();}
				height+=line->getHeight()+m_lineGap;
			}

			m_relWidth=width;
			m_relHeight=height;


			float old_anchor_x=m_anchorX;
			float old_anchor_y=m_anchorY;

			m_anchorX=0;
			m_anchorY=1;

			setAnchor(old_anchor_x,old_anchor_y);
		}

		bool done()
		{
			return m_done;
		}

		void clearText()
		{
			int size=m_lines.size();
			for(int i=0;i<size;i++)
			{
				delete m_lines[i];
			}
			m_lines.clear();
			if(m_current)
			{
				delete m_current;
				m_current=NULL;
			}
		}

		float getTextWidth()
		{
			return m_relWidth;
		}

		float getTextHeight()
		{
			return m_relHeight;
		}

		void setAnchor(float x,float y)
		{
			float diffx=(m_anchorX-x)*m_relWidth;
			float diffy=(m_anchorY-y)*m_relHeight;
			applyShift(diffx,diffy);
			m_anchorX=x;
			m_anchorY=y;
		}


		void applyShift(float x,float y)
		{
			int size=m_lines.size();
			for(int i=0;i<size;i++)
			{
				m_lines[i]->applyShift(x,y);
			}
		}

		void setTextAlign(E_TextAlign align)
		{


			int line_nu=m_lines.size();

			for(int i=0;i<line_nu;i++)
			{
				TypoLine<T_TypoText>* line=m_lines[i];

				float minx=line->getMinx();
				float maxx=line->getMaxx();
				float line_width=maxx-minx;
				float x_shift=0;
				switch(align)
				{
					case E_TextAlign::LEFT:
						x_shift=-minx;
						break;
					case E_TextAlign::CENTER:
						x_shift=(m_relWidth-line_width)/2-minx;
						break;
					case E_TextAlign::RIGHT:
						x_shift=m_relWidth-maxx;
						break;
				}
				line->applyShift(x_shift,0);

			}
		}


		int getTypoLineNu()
		{
			return m_lines.size();
		}

		TypoLine<T_TypoText>* getTypoLine(int index)
		{
			return m_lines[index];
		}

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
				m_curHeight+=m_lastHeight+m_lineGap;
			}
			if ((m_pageHeight!=0)&&(m_curHeight+m_lastHeight+m_lineGap>m_pageHeight))
			{
				m_done=true;
			}
			m_pen=Vector2(0,0);
		}

		bool canExpandHeight(float height)
		{
			if(m_pageHeight==0)
			{
				return true;
			}

			if(m_lines.size()==0)
			{
				return height<=m_pageHeight;
			}

			return (m_curHeight+height+m_lineGap)<=m_pageHeight;
		}


	private:
		std::vector<TypoLine<T_TypoText>*> m_lines;
		TypoLine<T_TypoText>* m_current;
		float m_curWidth,m_curHeight;
		float m_pageWidth,m_pageHeight;
		float m_relWidth,m_relHeight;
		float m_lastHeight;
		float m_lineGap;
		float m_anchorX,m_anchorY;
		bool m_done;

		Vector2 m_pen;
};



NS_FS_END





#endif /*_FS_TYPO_PAGE_H_*/
