/*************************************************************************/
/*  sl_state.h                                                           */
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


#ifndef _FEARY_XIR_SL_STATE_H_
#define _FEARY_XIR_SL_STATE_H_

#include  "xir_state.h"

extern XirState Err_State;
extern XirState Xir_Top;
/* Dobule Quote String */
extern XirState Double_Quote_Str_Begin;
extern XirState Double_Quote_Str_Body;
extern XirState Double_Quote_Str_Esc;
extern XirState Double_Quote_Str_End;


/* Single Quote String */
extern XirState Single_Quote_Str_Begin;
extern XirState Single_Quote_Str_Body;
extern XirState Single_Quote_Str_End;

/* Simple String */
extern XirState Simple_Str_Begin;
extern XirState Simple_Str_Body;
extern XirState Simple_Str_Space;

/* White space */
extern XirState WS_Begin;
extern XirState WS_Body;

/* Comment */
extern XirState Comment_Begin;
extern XirState Comment_Body;
extern XirState Comment_End;

/* Specific Symbol */
extern XirState Specific_Symbol_Begin;
extern XirState Specific_Symbol_Newline; 
extern XirState Specific_Symbol_Comma; 
extern XirState Specific_Symbol_Colon;
extern XirState Specific_Symbol_Ampersand;
extern XirState Specific_Symbol_Dollar;
extern XirState Specific_Symbol_L_RB;
extern XirState Specific_Symbol_R_RB;
extern XirState Specific_Symbol_L_SB;
extern XirState Specific_Symbol_R_SB;

#endif 

