/*************************************************************************/
/*  FsKeyCode.h                                                          */
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


#ifndef _FS_KEY_CODE_H_
#define _FS_KEY_CODE_H_
#include "FsMacros.h"

NS_FS_BEGIN

enum  E_KeyCode
{
	KEY_UNKOWN=0x0,
	KEY_BACKSPACE=0x08,
	KEY_TAB=0x09,
	KEY_RETURN=0x0D,

	KEY_SHIFT=0x10,
	KEY_CONTROL=0x11,

	KEY_MENU=0x12,  /* key menu and key back also used on android */
	KEY_BACK=0x1B,

	KEY_ESCAPE=0x1B,
	KEY_SPACE=0x20,

	/* arrow key */
	KEY_LEFT=0x25,
	KEY_UP=0x26,
	KEY_RIGHT=0x27,
	KEY_DOWN=0x28,

	KEY_DELETE=0x2E,

	/* number 0 ~ 9 same as ascii */
	KEY_0=0x30,
	KEY_1=0x31,
	KEY_2=0x32,
	KEY_3=0x33,
	KEY_4=0x34,
	KEY_5=0x35,
	KEY_6=0x36,
	KEY_7=0x37,
	KEY_8=0x38,
	KEY_9=0x39,


	/* letter A ~ Z same as ascii */
	KEY_A=0x41,
	KEY_B=0x42,
	KEY_C=0x43,
	KEY_D=0x44,
	KEY_E=0x45,
	KEY_F=0x46,
	KEY_G=0x47,
	KEY_H=0x48,
	KEY_I=0x49,
	KEY_J=0x4A,
	KEY_K=0x4B,
	KEY_L=0x4C,
	KEY_M=0x4D,
	KEY_N=0x4E,
	KEY_O=0x4F,
	KEY_P=0x50,
	KEY_Q=0x51,
	KEY_R=0x52,
	KEY_S=0x53,
	KEY_T=0x54,
	KEY_U=0x55,
	KEY_V=0x56,
	KEY_W=0x57,
	KEY_X=0x58,
	KEY_Y=0x59,
	KEY_Z=0x5A,

	/* Numberic keypad */
	KEY_NUMPAD0=0x60,
	KEY_NUMPAD1=0x61,
	KEY_NUMPAD2=0x62,
	KEY_NUMPAD3=0x63,
	KEY_NUMPAD4=0x64,
	KEY_NUMPAD5=0x65,
	KEY_NUMPAD6=0x66,
	KEY_NUMPAD7=0x67,
	KEY_NUMPAD8=0x68,
	KEY_NUMPAD9=0x69,
	KEY_MULTIPLY=0x6A,


	KEY_ADD	=0x6B,
	KEY_SEPARATOR=0x6C,
	KEY_SUBTRACT=0x6D,
	KEY_DECIMAL=0x6E,
	KEY_DIVIDE=0x6F,

};


NS_FS_END

#endif /*_FS_KEY_CODE_H_*/
