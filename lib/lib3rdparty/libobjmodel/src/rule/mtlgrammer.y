%{
#include <stdio.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMtlGrammer.h"
#include "LibObjMtlScanner.h"


#define MTL_DATA  ((LibObjMaterialLib*)(param->m_data))


#define param_scanner param->m_scanner



void libobjmtl_error(void* param,const char* msg)
{
	fprintf(stderr,"error: %s at line<%d><%s>\n ",
			msg,
			libobjmtl_get_lineno(((LibObjParserContext*)param)->m_scanner),
			libobjmtl_get_text(((LibObjParserContext*)param)->m_scanner));
}



%}

%error-verbose

%parse-param{LibObjParserContext* param}
%lex-param{LibObjParserContext* param_scanner}

%define api.pure
%define api.prefix{libobjmtl_}

%union
{
  int itype;    			/* integer */
  float ftype;    			/* float value */
  std::string* ctype;    	/* character string */
};

%token ERR
%token EOL
%token <ftype> DECIMAL
%token <itype> INTEGER
%token <ctype> WORD
%token <ctype> FILEPATH
%token NEWMTL_MARKER
%token KA_MARKER
%token KD_MARKER
%token KS_MARKER
%token D_MARKER
%token NS_MARKER
%token NI_MARKER
%token ILLUM_MARKER
%token MAPKA_MARKER
%token MAPKD_MARKER
%token MAPKS_MARKER
%token MAPD_MARKER
%token MAPBUMP_MARKER

%type <ftype> value

/* start of grammar */
%start mtlfile

%%

mtlfile: emptylines material 
	   | mtlfile material emptylines ;

emptylines: | emptylines EOL ; 


material: NEWMTL_MARKER WORD EOL materialdef 
{
	MTL_DATA->getCurMaterial()->m_name=*($2);
	MTL_DATA->commitMaterial();
	delete $2;
}
| NEWMTL_MARKER FILEPATH EOL materialdef 
{
	MTL_DATA->getCurMaterial()->m_name=*($2);
	MTL_DATA->commitMaterial();
	delete $2;
}
;

materialdef: parameters ;

parameters: | parameters parameter EOL ;

parameter:
ambient
| diffuse
| specular
| alpha
| ns
| ni
| illum
| mapka
| mapkd
| mapks
| mapd
| mapbump
;




ambient: KA_MARKER value value value 
{
	MTL_DATA->getCurMaterial()->m_ambient.set($2,$3,$4);
};

diffuse: KD_MARKER value value value 
{
	MTL_DATA->getCurMaterial()->m_diffuse.set($2,$3,$4);
};

specular: KS_MARKER value value value 
{
	MTL_DATA->getCurMaterial()->m_specular.set($2,$3,$4);
};

alpha: D_MARKER value 
{
	MTL_DATA->getCurMaterial()->m_opacity=$2;
};

ns: NS_MARKER value 
{
	MTL_DATA->getCurMaterial()->m_shiness=$2;
};

ni: NI_MARKER value 
{ 
	MTL_DATA->getCurMaterial()->m_ni=$2;
};

illum: ILLUM_MARKER INTEGER 
{
	MTL_DATA->getCurMaterial()->m_illuminationMode=$2;
};

mapka: MAPKA_MARKER FILEPATH 
{
	MTL_DATA->getCurMaterial()->m_ambientMap=*$2;
	delete $2;
};

mapkd: MAPKD_MARKER FILEPATH 
{
	MTL_DATA->getCurMaterial()->m_diffuseMap=*$2;
	delete $2;
};

mapks: MAPKS_MARKER FILEPATH 
{
	MTL_DATA->getCurMaterial()->m_specularMap=*$2;
	delete $2;
};

mapd: MAPD_MARKER FILEPATH 
{
	MTL_DATA->getCurMaterial()->m_alphaMap=*$2;
	delete $2;
};

mapbump: MAPBUMP_MARKER FILEPATH 
{
	MTL_DATA->getCurMaterial()->m_boumpMap=*$2;
	delete $2;

};

value: DECIMAL 
{ 
	$$ = $1;  
}
|INTEGER 
{ 
	$$ = (float)$1;
};

%%


LibObjMaterialLib* LibObj_ParseMtl(void* file,LibObj_ReadIoFunc io_func)
{
	LibObjMaterialLib* mtl=new LibObjMaterialLib;
	yyscan_t scanner=NULL;
	libobjmtl_lex_init(&scanner);

	LibObjParserContext* parser=new LibObjParserContext(scanner,mtl,file,io_func);
	
	libobjmtl_set_extra(parser,scanner);
	
	if(libobjmtl_parse(parser)!=0)
	{
		delete mtl;
		mtl=NULL;
	}
	libobjmtl_lex_destroy(scanner);
	delete parser;

	return mtl;
}



