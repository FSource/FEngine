#include "FsSeekBar.h"

NS_FS_BEGIN


SeekBar* SeekBar::create(const char* bg,const char* fg,const char* seek)
{
	SeekBar* ret=new SeekBar;
	ret->initWithTexture(bg,fg,seek);
	return ret;
}

SeekBar* SeekBar::create(Texture2D* tex_bg,Texture2D* tex_fg,Texture2D* tex_seek)
{
	SeekBar* ret=new SeekBar;
	ret->initWithTexture(tex_bg,tex_fg,tex_seek);
	return ret;
}


void SeekBar::setSeekTexture(const char* filename)
{
	Texture2D* tex=NULL;
	if(filename)
	{
		tex=Global::textureMgr()->loadTexture(filename);
		FS_TRACE_WARN_ON(tex==NULL,"Can't Seek Texture(%s) For SeekBar",filename);
	}
	setSeekTexture(tex);
}

void SeekBar::setSeekTexture(Texture2D* tex)
{
	FS_TRACE_WARN_ON(m_seekTexture,tex);
}







NS_FS_END 

