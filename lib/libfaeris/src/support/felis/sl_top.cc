/*************************************************************************/
/*  sl_top.cc                                                            */
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


#include "sl_state.h"
#include "xir_token.h"
enum Xir_Top_Input_Type
{
	XP_OTHER=0,
	XP_NEWLINE,
	XP_COMMA,
	XP_COLON,
	XP_AMPERSAND,
	XP_DOLLAR,
	XP_L_RB,
	XP_R_RB,
	XP_L_SB,
	XP_R_SB,
	XP_COMMENT,
	XP_WS,
	XP_LETTER,
	XP_SIN_QUOTE,
	XP_DOU_QUOTE,
};

static XirState* Xir_Top_Targets[]=
{
	&Err_State,
	&Specific_Symbol_Newline,
	&Specific_Symbol_Comma,
	&Specific_Symbol_Colon,
	&Specific_Symbol_Ampersand,
	&Specific_Symbol_Dollar,
	&Specific_Symbol_L_RB,
	&Specific_Symbol_R_RB,
	&Specific_Symbol_L_SB,
	&Specific_Symbol_R_SB,
	&Comment_Body,
	&WS_Body,
	&Simple_Str_Body,
	&Single_Quote_Str_Body,
	&Double_Quote_Str_Body,
};

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	11,0,14,10,5,0,4,13,0,0,0,12,2,12,12,0,12,12,12,12,12,12,12,12,12,12,3,0,0,0,0,0,
	0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,8,0,9,0,12,
	0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,6,0,7,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

XirState Xir_Top=
{
	"Xir_Top",
	input_map,
	0,
	XT_UNKOWN,
	Xir_Top_Targets,
};


XirState Err_State=
{
	"Err_State",
	input_map,
	0,
	XT_UNKOWN,
	0,
};















