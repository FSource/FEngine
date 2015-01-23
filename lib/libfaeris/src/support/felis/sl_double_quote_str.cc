/*************************************************************************/
/*  sl_double_quote_str.cc                                               */
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

extern XirState Double_Quote_Str_Begin;
extern XirState Double_Quote_Str_Body;
extern XirState Double_Quote_Str_Esc;
extern XirState Double_Quote_Str_End;

static unsigned char input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
enum  Double_Str_Input_Type
{
	DS_ERR=0,
	DS_SLASH=1,
	DS_QUOTE=2,
};

static XirState* Double_Quote_Str_Begin_Targets[]=
{&Err_State,&Err_State,&Double_Quote_Str_Body};

XirState Double_Quote_Str_Begin=
{
	"Double_Quote_Str_Begin",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Begin_Targets,
};

static XirState* Double_Quote_Str_Body_Targets[]=
{&Double_Quote_Str_Body,&Double_Quote_Str_Esc,&Double_Quote_Str_End};

XirState Double_Quote_Str_Body=
{
	"Double_Quote_Str_Body",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Body_Targets,
};

static XirState* Double_Quote_Str_Esc_Targets[]=
{&Double_Quote_Str_Body,&Double_Quote_Str_Body,&Double_Quote_Str_Body};

XirState Double_Quote_Str_Esc=
{
	"Dobule_Quote_Str_Esc",
	input_map,
	0,
	XT_UNKOWN,
	Double_Quote_Str_Esc_Targets,
};

static XirState* Double_Quote_Str_End_Targets[]=
{ &Err_State,&Err_State,&Err_State};

XirState Double_Quote_Str_End=
{
	"Double_Quote_Str_End",
	input_map,
	1,
	XT_DOU_STR,
	Double_Quote_Str_End_Targets,
};
