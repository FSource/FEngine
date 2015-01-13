#ifndef _FS_SEEK_BAR_H_
#define _FS_SEEK_BAR_H_

#include <functional>
#include "FsMacros.h"
#include "FsProcessBar.h"

NS_FS_BEGIN

class SeekBar:public ProcessBar
{
	public:
		static SeekBar* create(const char* bg,const char* fg,const char* seek);
		static SeekBar* create(Texture2D* tex_bg,Texture2D* tex_fg,Texture2D* tex_seek);

	public:
		void setSeekTexture(const char* filename);
		void setSeekTexture(Texture2D* tex);

		Texture2D* getSeekTexture();
		void setSeekMargin(float ml,float mb);
		void setSeekMargin(const Vector2f& v);
		Vector2f getSeekMargin();

		void setSeekSize(float w,float h);
		void setSeekSize(const Vector2f& v);
		Vector2f getSeekSize();

	public:
		virtual void processChange(float value);
		std::function<void(SeekBar*,float)> onProcessChange;

	public:
		void touchBegin(float x,float y) FS_OVERRIDE;
		void touchMove(float x,float y)  FS_OVERRIDE;
		void touchEnd(float x,float y)   FS_OVERRIDE;

		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	protected:
		SeekBar();
		~SeekBar();


	protected:
		Texture2D* m_seekTexture;
		Vector2f m_seekSize;
		Vector2f m_seekMargin;

		Vector2f m_beginDragPos;
		

};



NS_FS_END 

#endif /*_FS_SEEK_BAR_H_*/



