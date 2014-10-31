/*
 *  tga.c
 *
 *  Copyright (C) 2001-2002  Matthias Brueckner <matbrc@gmx.de>
 *  This file is part of the TGA library (libtga).
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "tga.h"


TGA*
TGAOpen(void* file,
	TGA_IoRead read_io,
	TGA_IoWrite write_io,
	TGA_IoSeek seek_io,
	TGA_IoTell tell_io
	)
{

 	TGA *tga;

	tga = (TGA*)malloc(sizeof(TGA));
	if (!tga) {
		TGA_ERROR(tga, TGA_OOM);
		return NULL;
	}
	
	tga->off = 0;
	tga->file= file;
	tga->readio=read_io;
	tga->writeio=write_io;
	tga->seekio=seek_io;
	tga->tellio=tell_io;

	tga->last = TGA_OK;
	return tga;
}

size_t
TGAWrite(TGA 	     *tga, 
	 const void *buf, 
	 size_t       size, 
	 size_t       n)
{
	size_t wrote = tga->writeio(tga->file,buf, size*n);
	tga->off = tga->tellio(tga->file);
	return wrote/size;
}

int TGAPut(TGA* tga,
	   char v)
{
	return TGAWrite(tga,&v,1,1);
}

int TGAGet(TGA* tga)
{
	char v;
	TGARead(tga,&v,1,1);
	return v;
}

size_t
TGARead(TGA    *tga, 
	void  *buf,
	size_t 	size, 
	size_t 	n)
{
	size_t read = tga->readio(tga->file,buf, size*n);

	tga->off = tga->tellio(tga->file);
	return read/size;
}




const char*
TGAStrError(tuint8 code)
{
	if (code >= TGA_ERRORS) code = TGA_ERROR;
	return tga_error_strings[code];
}


tlong
__TGASeek(TGA  *tga, 
	  tlong off, 
	  int   whence)
{
	tga->seekio(tga->file,off,whence);
	tga->off = tga->tellio(tga->file);
	return tga->off;
}


void
__TGAbgr2rgb(tbyte  *data, 
	     size_t  size, 
	     size_t  bytes)
{
	size_t i;
	tbyte tmp;
	
	for (i = 0; i < size; i += bytes) {
		tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}
}
