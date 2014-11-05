%{
#include <vector>
#include <string>
#include <stdio.h>


#include "glslext_defines.h"
#include "glslext_parser.h"
#include "glslext_grammer.h"


#define YY_INPUT(buf,result,max_size) \
	GlslextParser* parser=(GlslextParser*) Glslext_get_extra(yyg); \
	result=parser->m_readFunc(parser->m_file,buf,max_size); \




#define PARSE_TEXT_TO_YACC  \
	yylval_param->istring = new std::string(Glslext_get_text(yyscanner))

%}

%option yylineno
%option reentrant
%option never-interactive
%option nounput
%option noyywrap 
%option prefix="Glslext_"



digit [0-9]

%%
VERTEX_BEGIN 	return tVERTEX_BEGIN;
VERTEX_END 		return tVERTEX_END;

FRAGMENT_BEGIN  return tFRAGMENT_BEGIN;
FRAGMENT_END 	return tFRAGMENT_END;

"("				return tL_RB;
")"				return tR_RB;
"$"				return tDOLLAR;
";"				return tSEMICOLON;
"["				return tL_SB;
"]"				return tR_SB;

attribute 		return tATTRIBUTE;
uniform 		return tUNIFROM;

"="				return tASSIGN;				
"," 			return tCOMMA;
	
\.|"!"|"~"|"^"|"?"|:|=|"{"|"}"  				PARSE_TEXT_TO_YACC; return tOPERATOR;
\*|\/|\%|\+|-|\<|>|&|\\							PARSE_TEXT_TO_YACC; return tOPERATOR;


\+\+|--|\<=|>=|==|!=|&&|\|\||"^^"|"<<"|">>"		PARSE_TEXT_TO_YACC; return tOPERATOR;
\*=|\/=|\+=|\%=|\<\<=|>>=|&=|"^="|\|=|-=    	PARSE_TEXT_TO_YACC; return tOPERATOR;


float|vec2|vec3|vec4							PARSE_TEXT_TO_YACC; return tU_TYPE;
int|ivec2|ivec3|ivec4 							PARSE_TEXT_TO_YACC; return tU_TYPE;
uint|uvec2|uvec3|uvec4 							PARSE_TEXT_TO_YACC; return tU_TYPE;
bool|bvec2|bvec3|bvec4 							PARSE_TEXT_TO_YACC; return tU_TYPE;
mat2|mat3|mat4									PARSE_TEXT_TO_YACC; return tU_TYPE;
sampler1D|sampler2D|sampler3D|samplerCube 		PARSE_TEXT_TO_YACC; return tU_TYPE;
sampler1DShadow|sampler2DShadow 				PARSE_TEXT_TO_YACC; return tU_TYPE;
 
highp|lowp|middlep		 						PARSE_TEXT_TO_YACC; return tPRECISION;


\n[ \t\n]* 	return tNEW_LINE;


"/*".*"*/"		/*eating comments*/
"//".*\n		/*eating comments*/
[ \t]+			/*eating whitespace*/


[1-9][0-9]*[uU]?|0[xX][0-9a-fA-F]+[uU]?|0[0-7]*[uU]?	PARSE_TEXT_TO_YACC; return tINTEGER;

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?[fF]?	PARSE_TEXT_TO_YACC; return tFLOAT;
\.[0-9]+([eE][+-]?[0-9]+)?[fF]?			PARSE_TEXT_TO_YACC; return tFLOAT;
[0-9]+\.([eE][+-]?[0-9]+)?[fF]?			PARSE_TEXT_TO_YACC; return tFLOAT;
[0-9]+[eE][+-]?[0-9]+[fF]?				PARSE_TEXT_TO_YACC; return tFLOAT;
[0-9]+[fF]								PARSE_TEXT_TO_YACC; return tFLOAT;

 
[_a-zA-Z0-9#.]+	 PARSE_TEXT_TO_YACC; return tWORD;


%%




