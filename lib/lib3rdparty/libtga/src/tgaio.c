/*
 *  tgaio.c
 *
 *  Copyright (C) 2001-2002, Matthias Brueckner
 *  Copyright (C) 2011, Alexander Azhevsky, Andrey Antsut
 *  
 *  This file is part of the TGA Extended library (libtga-ex).
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

#include "tgaio.h"


int tga_fgetc(TGA* tga)
{
	return  tga->fgetcFunc(tga) ;
}

size_t tga_fread(TGA* tga, void* buffer, size_t size, size_t count)
{
	return  tga->freadFunc(tga, buffer, size, count) ;
}

int tga_fputc(TGA* tga, int c)
{
	return  tga->fputcFunc(tga, c) ;
}

size_t tga_fwrite(TGA* tga, const void* buffer, size_t size, size_t count)
{
	return  tga->fwriteFunc(tga, buffer, size, count) ;
}

void tga_fseek(TGA* tga, long offset, int origin)
{
	tga->fseekFunc(tga, offset, origin) ;
}

long tga_ftell(TGA* tga)
{
	return tga->ftellFunc(tga) ;
}






