%{

#include <string>
#include <vector>

#include "glslext_defines.h"
#include "glslext_parser.h"
#include "glslext_grammer.h"
#include "glslext_scanner.h"

#define yylex Glslext_lex 
#define param_scanner param->m_scanner

/* TODO(When Parse Failed MemLeak Will Happend */

%}

%union{
	std::string* istring;
	std::vector<float>* ivec;
	float inumber;
}



%token tFeature

%token tVERTEX_SHADER

%token tFRAGMENT_SHADER
%token tUNIFORM_MAP 
%token tATTRIBUTE_MAP

%token tL_RB 
%token tR_RB


%token tL_SB 
%token tR_SB

%token tL_CB 
%token tR_CB

%token tDOLLAR
%token tCOLON

%token tASSIGN

%token <istring> tINTEGER

%token tNEW_LINE

%token <istring> tWORD 
%token <istring> tPRECISION



%type <istring> word
%type <istring> program_body
%type <istring> words


%define api.pure 
%parse-param{GlslextParser* param}
%lex-param{void* param_scanner}

%define api.prefix {Glslext_}


%start shader_source_start


%%



shader_source_start: new_lines shader_chunks new_lines 

shader_chunks :  shader_chunk | shader_chunks new_lines shader_chunk 

shader_chunk : feature_define | uniform_map_define | attribute_map_define | vertex_shader_define | fragment_shader_define ;



feature_define: tFeature  new_lines tL_CB new_lines features tR_CB ;

features : | features feature ;

feature : tWORD  tCOLON tWORD   new_lines
{
	param->addFeature($1,$3);
}
;

uniform_map_define : tUNIFORM_MAP new_lines tL_CB  new_lines uniform_maps tR_CB ;
uniform_maps : | uniform_maps uniform_map ;
uniform_map : tWORD tASSIGN  tDOLLAR tL_RB  tWORD tR_RB new_lines
	{
		param->addUniformMap($1,NULL,$5);
	};
uniform_map : tWORD tASSIGN  tDOLLAR tL_RB tWORD tL_SB tINTEGER tL_SB new_lines 
	{
		param->addUniformMap($1,NULL,$5,atoi($7->c_str()));
		delete $7;
	};



attribute_map_define  : tATTRIBUTE_MAP new_lines tL_CB new_lines attribute_maps tR_CB;
attribute_maps : | attribute_maps attribute_map ;
attribute_map: tWORD tASSIGN tDOLLAR tL_RB tWORD tR_RB new_lines
	{
		param->addAttributeMap($1,NULL,$5);
	};



vertex_shader_define:tVERTEX_SHADER new_lines tL_CB program_body tR_CB
	{
		param->setVertexSrc($4);
	}
;

fragment_shader_define :tFRAGMENT_SHADER new_lines tL_CB program_body tR_CB
	{
		param->setFragmentSrc($4);
		
	}
;


program_body: words
	{
		$$=$1;
	}
;


words: word
{
	$$=$1;
}
|words word 
{
	($1)->append(" ");
	($1)->append(*($2));
	$$=$1;
	delete $2;
};

word: tL_CB words tR_CB 
{
	std::string* tmp=new std::string("{ ");
	tmp->append(*$2);
	tmp->append("  }");
	$$=tmp;
};



word: tNEW_LINE 
	{
		$$=new std::string("\n");
	}
	|  tL_RB 
	{
		$$=new std::string("(");
	}
	|tR_RB 
	{
		$$=new std::string(")");
	}
	|tL_SB 
	{
		$$=new std::string("[");
	}
	|tR_SB 
	{
		$$=new std::string("]");
	}
	|tCOLON 
	{
		$$=new std::string(":");
	}
	| tINTEGER
	{
		$$=$1;
	}
	|tWORD 
	{
		$$=$1;
	}
	|tASSIGN
	{
		$$=new std::string("=");
	}
;



new_lines: | new_lines tNEW_LINE ;



























