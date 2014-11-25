%{

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMtlGrammer.h"

#define YYSTYPE LIBOBJMTL_STYPE
#define YY_INPUT(buf,result,max_size) \
{ \
	LibObjParserContext* parser=(LibObjParserContext*) libobjmtl_get_extra(yyg); \
	result = parser->m_readIo(parser->m_file,buf,max_size); \
}


%}


%option yylineno
%option reentrant 
%option never-interactive 
%option nounput
%option noyywrap
%option prefix="libobjmtl_"

word [a-zA-Z]+[a-zA-Z0-9\_\.\-]*
filepath [a-zA-Z\.\\/][:\\/\.a-z\_A-Z0-9]*\.(jpg|JPG|bmp|BMP|png|PNG)


%%


[\n\r] { return EOL; }

#.*\n  ; /* skip comments */

[ \t]+ ; /* skip whitespace */
newmtl  { return NEWMTL_MARKER; }
Ka      { return KA_MARKER; }
Kd      { return KD_MARKER; }
Ks      { return KS_MARKER; }
d		{ return D_MARKER; }
Tr 		{ return D_MARKER; }
Ns      { return NS_MARKER; }
Ni      { return NI_MARKER; }
illum   { return ILLUM_MARKER; }
map_Ka  { return MAPKA_MARKER; }
map_Kd  { return MAPKD_MARKER; }
map_Ks  { return MAPKS_MARKER; }
map_d   { return MAPD_MARKER; }
[(map bump)(bump)] { return MAPBUMP_MARKER; }

[\-\+]?[0-9]*\.[0-9]+([eE][\-\+]?[0-9]+)? {
  yylval->ftype= (float)atof(yytext);
  return DECIMAL;
}

[\-\+]?[0-9][0-9]* {
  yylval->itype= atoi(yytext);
  return INTEGER;
}

[/\n] { return *yytext; }

{filepath} {
  yylval->ctype= new std::string(yytext);
  return FILEPATH;
}

{word} {
  yylval->ctype= new std::string(yytext);
  return WORD;
}

. return ERR;

%%

