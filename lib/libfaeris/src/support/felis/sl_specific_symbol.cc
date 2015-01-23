/*************************************************************************/
/*  sl_specific_symbol.cc                                                */
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


#include "xir_token.h"
#include "sl_state.h"
#include "xir_state.h"

static unsigned char begin_input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,5,0,4,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,9,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,7,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
enum  Specific_Input_type
{
	SI_OTHER=0,
	SI_NEWLINE,
	SI_COMMA,
	SI_COLON,
	SI_AMPERSAND,
	SI_DOLLAR,
	SI_L_RB,
	SI_R_RB,
	SI_L_SB,
	SI_R_SB,
};

static XirState* Specific_Symbol_Begin_Targets[]=
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
};

XirState Specific_Symbol_Begin=
{
	"Specific_Symbol_Begin",
	begin_input_map,
	0,
	XT_UNKOWN,
	Specific_Symbol_Begin_Targets,
};


static unsigned char zeor_input_map[]=
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static XirState* Error_Targets[]= { &Err_State};



#define SPECIFIC_SYMBOL_STATE(name,token) \
	XirState name = { #name,zeor_input_map,1,token,Error_Targets} 


SPECIFIC_SYMBOL_STATE(Specific_Symbol_Newline,XT_NEWLINE);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_Comma,XT_COMMA);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_Colon,XT_COLON);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_Ampersand,XT_AMPERSAND);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_Dollar,XT_DOLLAR);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_L_RB,XT_L_RB);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_R_RB,XT_R_RB);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_L_SB,XT_L_SB);
SPECIFIC_SYMBOL_STATE(Specific_Symbol_R_SB,XT_R_SB);























