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
VertexShader 	return tVERTEX_SHADER;
FragmentShader	return tFRAGMENT_SHADER;
Feature			return tFeature;
AttributeMap 	return tATTRIBUTE_MAP ;
UniformMap 		return tUNIFORM_MAP ;


"("				return tL_RB;
")"				return tR_RB;
"["				return tL_SB;
"]"				return tR_SB;
"{"				return tL_CB;
"}"				return tR_CB;

"$"				return tDOLLAR;
":"				return tCOLON;


"="				return tASSIGN;				
	

\n[ \t\n]* 	return tNEW_LINE;


"/*".*"*/"		/*eating comments*/
"//".*\n		/*eating comments*/
[ \t]+			/*eating whitespace*/


[1-9][0-9]*[uU]?|0[xX][0-9a-fA-F]+[uU]?|0[0-7]*[uU]?	PARSE_TEXT_TO_YACC; return tINTEGER;

[_a-zA-Z0-9.]+					PARSE_TEXT_TO_YACC; return tWORD;
[~`!@#%\^&*-+_|\\'";<>,/?\-]+=?	 PARSE_TEXT_TO_YACC; return tWORD;

%%




