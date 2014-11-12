%{

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMeshGrammer.h"

#define YYSTYPE LIBOBJMESH_STYPE

#define YY_INPUT(buf,result,max_size) \
{ \
	LibObjParserContext* parser=(LibObjParserContext*) libobjmesh_get_extra(yyg); \
	result = parser->m_readIo(parser->m_file,buf,max_size); \
}

%}

%option yylineno
%option reentrant 
%option never-interactive 
%option nounput
%option noyywrap
%option prefix="libobjmesh_"


word [a-zA-Z]+[a-zA-Z0-9\_\.\-]*
mtlfile [a-zA-Z\.\\/][:\\/\.a-z\_A-Z0-9\-]*\.mtl
null (\(null\)|null)

%%


[\n\r] { return EOL; }

#.*\n  ; /* skip comments */

[ \t]+ ; /* skip whitespace */

v  { return VERTEX_MARKER; }

o  { return OBJECT_MARKER; }

g  { return GROUP_MARKER; }

vt { return TEXEL_MARKER; }

vn { return NORMAL_MARKER; }

l  { return LINE_MARKER; }

f  { return FACE_MARKER; }

c  { return CAMERA_MARKER; }

mtllib  { return MATERIALLIB_MARKER; }

usemtl  { return USEMATERIAL_MARKER; }

s  { return SMOOTHINGGROUP_MARKER; }

[\-\+]?[0-9]*\.[0-9]+([eE][\-\+]?[0-9]+)? {
  yylval->ftype= (float)atof(yytext);
  return DECIMAL;
}

[\-\+]?[0-9][0-9]* {
  yylval->itype= atoi(yytext);
  return INTEGER;
}

[/\n] { return *yytext; }

off {
  return OFF_WORD;
}

{mtlfile} {
  yylval->ctype= new std::string(yytext);
  return MTLFILEPATH;
}

{null} {
  return NULL_MARKER;
}

{word} {
  yylval->ctype= new std::string(yytext);
  return WORD;
}

. return ERR;

%%


