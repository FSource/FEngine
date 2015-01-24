/*************************************************************************/
/*  xir_token.h                                                          */
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


#ifndef _FEARY_XIR_TOKEN_H_
#define _FEARY_XIR_TOKEN_H_

enum XirToken
{
	XT_UNKOWN=0,
	XT_ERROR,
	XT_SIM_STR,
	XT_DOU_STR,
	XT_SIN_STR,

	XT_NEWLINE,
	XT_COMMA,

	XT_COLON,
	XT_AMPERSAND,
	XT_DOLLAR,
	XT_L_RB,
	XT_R_RB,
	XT_L_SB,
	XT_R_SB,

	XT_WS,
	XT_COMMENT,
	XT_EOF,

	XT_TOKEN_NU,
};

const char* XirToken_Name(int token);
#endif  /*_FEARY_XIR_TOKEN_H_*/



