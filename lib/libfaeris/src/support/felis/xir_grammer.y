%{
#include "xir_scanner.h"
#include "xir_parser.h"

#define CAST_PARAM  ((YYParserParm*) YYPARSE_PARAM)
#define YYSTYPE Faeris::FsObject* 
%}

%token tUNKOWN tERR
%token tSIM_STR tDOU_STR tSIN_STR 
%token tNEWLINE tCOMMA 
%token tCOLON tAMPERSAND tDOLLAR
%token tL_RB tR_RB tL_SB tR_SB

%pure_parser

%start xir_start
%%

xir_start:xir_body
	{
		$$=$1;
		CAST_PARAM->setRoot((Faeris::FsDict*)$1);
	}
;

xir_body: sim_str tCOLON primity delimiter
	{
		Faeris::FsDict* dict= CAST_PARAM->newDictObject();
		$$=dict;
		dict->insert($1,$3);
	}
;
xir_body:tNEWLINE
	{
		$$=CAST_PARAM->newDictObject();
	}
;

xir_body:xir_body sim_str tCOLON primity  delimiter
{
		$$=$1;
		Faeris::FsDict* dict=(Faeris::FsDict*)($1);
		dict->insert($2,$4);
}
;



primity:dict{$$=$1;}
	| array {$$=$1;}
	| string {$$=$1;}
;

string:sim_str
	{
		$$=$1;
	}
	| dou_str
	{
		$$=$1;
	}
	| sin_str
	{
		$$=$1;
	}
;

sim_str:tSIM_STR
	{
		$$=CAST_PARAM->newStringObject();
	}
;

dou_str:tDOU_STR
	{
		$$=CAST_PARAM->newStringObject();
	}
;

sin_str:tSIN_STR
	{
		$$=CAST_PARAM->newStringObject();
	}
;


delimiter:tNEWLINE | tCOMMA | tNEWLINE tCOMMA tNEWLINE | tCOMMA tNEWLINE;


/* for dict */
dict_begin:tL_RB
	{
		$$=CAST_PARAM->newDictObject();
	}
;
dict_begin: tL_RB  tNEWLINE
	{
		$$=CAST_PARAM->newDictObject();
	}
;
	

dict_body:dict_begin
	{
		$$=$1;
	}
;	
dict_body:dict_body sim_str tCOLON primity  delimiter
	{
		$$=$1;
		Faeris::FsDict* dict=(Faeris::FsDict*)($1);
		dict->insert($2,$4);
	}
;
dict:dict_body tR_RB 
	{
		$$=$1;
	}
	| dict_body sim_str tCOLON primity tR_RB
	{
		$$=$1;
		Faeris::FsDict* dict=(Faeris::FsDict*)($1);
		dict->insert($2,$4);
	}
;


/* for array */
array_begin:tL_SB 
	{
		$$=CAST_PARAM->newArrayObject();
	}
;
array_begin: tL_SB  tNEWLINE
	{
		$$=CAST_PARAM->newArrayObject();
	}
;

array_body:array_begin
	{
		$$=$1;
	}
;

array_body:array_body primity delimiter
	{
		$$=$1;
		((Faeris::FsArray*)($1))->push($2);
	}
;
array:array_body tR_SB
	{
		$$=$1;
	}
	|array_body primity tR_SB
	{
		((Faeris::FsArray*)($1))->push($2);
		$$=$1;
	}
;




