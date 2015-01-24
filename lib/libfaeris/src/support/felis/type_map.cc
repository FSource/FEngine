/*************************************************************************/
/*  type_map.cc                                                          */
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


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define ASSIC_NUM 256
char id_array[ASSIC_NUM];
void print_array(char* array)
{
	int i;
	for(i=0;i<ASSIC_NUM;i++)
	{
		if(i%32==0&&i!=0)
		{
			printf("\n");
		}
		if(i!=ASSIC_NUM-1)
		{
			printf("%d,",array[i]);
		}
		else
		{
			printf("%d\n",array[i]);

		}
	}
}

enum Sim_Str_Input_Type
{
	SS_ERR=0,
	SS_NORMAL,
	SS_WS,	
};

enum  Double_Str_Input_Type
{
	DS_ERR=0,
	DS_SLASH=1,
	DS_QUOTE=2,
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
void id_array_create()
{
	memset(id_array,0,sizeof(id_array));

	id_array[' ']=SS_WS;
	id_array['\t']=SS_WS;

	id_array['_']=SS_NORMAL;
	id_array['.']=SS_NORMAL;
	id_array['+']=SS_NORMAL;
	id_array['-']=SS_NORMAL;


	char c;
	for(c='0';c<='9';c++)
	{
		id_array[c]=SS_NORMAL;
	}
	for(c='a';c<='z';c++)
	{
		id_array[c]=SS_NORMAL;
	}
	for(c='A';c<='Z';c++)
	{
		id_array[c]=SS_NORMAL;
	}

}

void id_array_xtop()
{
	memset(id_array,0,sizeof(id_array));
	id_array['\n']=XP_NEWLINE;
	id_array[',']=XP_COMMA;
	id_array[':']=XP_COLON;
	id_array['&']=XP_AMPERSAND;
	id_array['$']=XP_DOLLAR;
	id_array['[']=XP_L_SB;
	id_array[']']=XP_R_SB;
	id_array['{']=XP_L_RB;
	id_array['}']=XP_R_RB;
	id_array['#']=XP_COMMENT;
	id_array[' ']=XP_WS;
	id_array['\t']=XP_WS;
	id_array['\'']=XP_SIN_QUOTE;
	id_array['\"']=XP_DOU_QUOTE;

	char c;
	for(c='0';c<='9';c++)
	{
		id_array[c]=XP_LETTER;
	}
	for(c='a';c<='z';c++)
	{
		id_array[c]=XP_LETTER;
	}
	for(c='A';c<='Z';c++)
	{
		id_array[c]=XP_LETTER;
	}
	id_array['_']=XP_LETTER;
	id_array['.']=XP_LETTER;
	id_array['+']=XP_LETTER;
	id_array['-']=XP_LETTER;
}






int main()
{
	id_array_xtop();
	print_array(id_array);
	return 0;
}
