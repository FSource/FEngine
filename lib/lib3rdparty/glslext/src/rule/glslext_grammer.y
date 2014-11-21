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

%token tL_RB 
%token tR_RB
%token tDOLLAR
%token tCOLON


%token tL_SB 
%token tR_SB

%token tL_CB 
%token tR_CB


%token tATTRIBUTE 
%token tUNIFROM 

%token <istring> tU_TYPE 
%token <istring> tFLOAT 
%token <istring> tINTEGER

%token tNEW_LINE

%token tCOMMA
%token tASSIGN

%token <istring> tOPERATOR
%token <istring> tWORD 

%token <istring> tPRECISION

%token tSEMICOLON
%token <istring> tOP_EQUAL


%type <istring> word
%type <istring> program_body
%type <istring> words


%define api.pure 
%parse-param{GlslextParser* param}
%lex-param{void* param_scanner}

%define api.prefix {Glslext_}


%start shader_source_start


%%



shader_source_start: new_lines vertex_shader new_lines fragment_shader  new_lines;
shader_source_start: new_lines feature_define new_lines vertex_shader new_lines fragment_shader  new_lines;


feature_define: tFeature  new_lines tL_CB new_lines features tR_CB ;

features : | features feature ;

feature : tWORD  tCOLON tWORD   new_lines
{
	param->addFeature($1,$3);
}
;


vertex_shader:tVERTEX_SHADER new_lines tL_CB program_body tR_CB
	{
		param->setVertexSrc($4);
	}
;

fragment_shader:tFRAGMENT_SHADER new_lines tL_CB program_body tR_CB
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
	| tFLOAT
	{
		$$=$1;
	}
	| tINTEGER
	{
		$$=$1;
	}
	|tWORD 
	{
		$$=$1;
	}
	|tU_TYPE 
	{
		$$=$1;
	}
	|tPRECISION  
	{
		$$=$1;
	}
	| tSEMICOLON 
	{
		$$=new std::string(";");
	}
	|tASSIGN
	{
		$$=new std::string("=");
	}
	|tOPERATOR
	{
		$$=$1;
	}
	|tCOMMA
	{
		$$=new std::string(",");
	}
	|tCOLON 
	{
		$$=new std::string(":");
	}


;

word: tUNIFROM tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tL_SB tINTEGER tR_SB tR_RB tSEMICOLON
	{
		std::string* ret=new std::string("uniform ");

		/* type */
		ret->append(*($2));

		/* variable */
		ret->append(" ");
		ret->append(*($3));
		
		/* add uniform map */
		param->addUniformMap($3,$2,$7,atoi($9->c_str()));
		delete $9;

		ret->append(" ;");
		$$=ret;
	}
;

word: tUNIFROM tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tR_RB tSEMICOLON
	{
		std::string* ret=new std::string("uniform ");

		/* type */
		ret->append(*($2));

		/* variable */
		ret->append(" ");
		ret->append(*($3));
		
		/* add unifom map */
		param->addUniformMap($3,$2,$7);

		ret->append(" ;");
		$$=ret;
	}
;

word: tUNIFROM tPRECISION tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tL_SB tINTEGER tR_SB tR_RB tSEMICOLON 
{
	std::string* ret=new std::string("uniform ");

	/* precision*/
	ret->append(*($2));
	delete $2;

	/* type */
	ret->append(" ");
	ret->append(*($3));
		

	/* variable */
	ret->append(" ");
	ret->append(*($4));
		
	/* add uniform map */
	param->addUniformMap($4,$3,$8,atoi($10->c_str()));
	delete $10;

	ret->append(" ;");
	$$=ret;
}
;

word: tUNIFROM tPRECISION tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tR_RB tSEMICOLON 
{
	std::string* ret=new std::string("uniform ");

	/* precision*/
	ret->append(*($2));
	delete $2;

	/* type */
	ret->append(" ");
	ret->append(*($3));
		

	/* variable */
	ret->append(" ");
	ret->append(*($4));
		
	/* add uniform map */
	param->addUniformMap($4,$3,$8);

	ret->append(" ;");
	$$=ret;
}
;



word: tATTRIBUTE tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tR_RB tSEMICOLON 
{
	std::string* ret=new std::string("attribute ");

	/* type */
	ret->append(*($2));

	/* variable */
	ret->append(" ");
	ret->append(*($3));
		
	/* add uniform map */
	param->addAttributeMap($3,$2,$7);

	ret->append(" ;");
	$$=ret;
}
;


word: tATTRIBUTE tPRECISION tU_TYPE tWORD tASSIGN tDOLLAR tL_RB tWORD tR_RB tSEMICOLON 
{
	std::string* ret=new std::string("attribute ");

	/* precision*/
	ret->append(*($2));
	delete $2;

	/* type */
	ret->append(" ");
	ret->append(*($3));
		

	/* variable */
	ret->append(" ");
	ret->append(*($4));

	/* add attribute map */
	param->addAttributeMap($4,$3,$8);

	ret->append(" ;");
	$$=ret;

}
;

word:tUNIFROM tU_TYPE tWORD tSEMICOLON 
{
	std::string* ret=new std::string("uniform ");

	/* type */
	ret->append(*($2));
	delete $2;

	/* variable */
	ret->append(" ");
	ret->append(*($3));
	delete $3;
		
	/* semicolon */
	ret->append(" ;");
	$$=ret;
}
;

word:tUNIFROM tPRECISION tU_TYPE tWORD tSEMICOLON 
{
	std::string* ret=new std::string("uniform ");

	/* precision*/
	ret->append(*($2));
	delete $2;

	/* type */
	ret->append(" ");
	ret->append(*($3));
	delete $3;
		

	/* variable */
	ret->append(" ");
	ret->append(*($4));
	delete $4;
		
	ret->append(" ;");
	$$=ret;

};


word:tATTRIBUTE tU_TYPE tWORD tSEMICOLON 
{
	std::string* ret=new std::string("attribute ");

	/* type */
	ret->append(*($2));
	delete $2;

	/* variable */
	ret->append(" ");
	ret->append(*($3));
	delete $3;
		

	ret->append(" ;");

	$$=ret;
};


word:tATTRIBUTE tPRECISION tU_TYPE tWORD tSEMICOLON 
{
	std::string* ret=new std::string("attribute ");

	/* precision*/
	ret->append(*($2));
	delete $2;

	/* type */
	ret->append(" ");
	ret->append(*($3));
	delete $3;
		

	/* variable */
	ret->append(" ");
	ret->append(*($4));
	delete $4;
		

	ret->append(" ;");
	$$=ret;
}


new_lines: | new_lines tNEW_LINE ;



























