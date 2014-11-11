%{
#include <stdio.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMtlGrammer.h"
#include "LibObjMtlScanner.h"


#define MTL_CALL_BACK (param->m_callbacks)
#define MTL_USER_DATA (param->m_userdata)


#define param_scanner param->m_scanner



void libobjmtl_error(void* param,const char* s)
{
	fprintf(stderr,"parase mtl error:%s\n",s);
}



%}

%error-verbose

%parse-param{LibObjMtlContext* param}
%lex-param{LibObjMtlContext* param_scanner}

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

mtlfile: | mtlfile material emptylines ;

emptylines: | emptylines EOL ; 


material: NEWMTL_MARKER WORD EOL materialdef 
{
 	if(MTL_CALL_BACK->onAddMaterial)
	{
    	MTL_CALL_BACK->onAddMaterial($2->c_str(), MTL_USER_DATA);
	}
	delete $2;
} /* sometimes tools, like for example Blender are generating 
material names which looks like file path (for textures based on the file).
These names does not match the word, but the file paths. So to prevent
the error we also "allows" such material names.*/
| NEWMTL_MARKER FILEPATH EOL materialdef 
{
 	if(MTL_CALL_BACK->onAddMaterial)
	{
    	MTL_CALL_BACK->onAddMaterial($2->c_str(), MTL_USER_DATA);
	}
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
  	if(MTL_CALL_BACK->onSetAmbientColor)
	{
    	MTL_CALL_BACK->onSetAmbientColor($2, $3, $4, MTL_USER_DATA);
	}
};

diffuse: KD_MARKER value value value 
{
 	if(MTL_CALL_BACK->onSetDiffuseColor)
	{
    	MTL_CALL_BACK->onSetDiffuseColor($2, $3, $4, MTL_USER_DATA);
	}
};

specular: KS_MARKER value value value 
{
	if(MTL_CALL_BACK->onSetSpecularColor)
	{
		MTL_CALL_BACK->onSetSpecularColor($2, $3, $4, MTL_USER_DATA);
	}
};

alpha: D_MARKER value 
{
  	if(MTL_CALL_BACK->onSetAlpha)
	{
   		MTL_CALL_BACK->onSetAlpha($2,MTL_USER_DATA);
	}
};

ns: NS_MARKER value 
{
  	if(MTL_CALL_BACK->onSetSpecularExponent)
	{
    	MTL_CALL_BACK->onSetSpecularExponent($2,MTL_USER_DATA);
	}
};

ni: NI_MARKER value 
{ 
  	if(MTL_CALL_BACK->onSetOpticalDensity)
	{
    	MTL_CALL_BACK->onSetOpticalDensity($2,MTL_USER_DATA);
	}
};

illum: ILLUM_MARKER INTEGER 
{
  	if(MTL_CALL_BACK->onSetIllumModel)
	{
    	MTL_CALL_BACK->onSetIllumModel($2,MTL_USER_DATA);
	}
};

mapka: MAPKA_MARKER FILEPATH 
{
  	if(MTL_CALL_BACK->onSetAmbientTextureMap)
	{
    	MTL_CALL_BACK->onSetAmbientTextureMap($2->c_str(), MTL_USER_DATA);
	}
	delete $2;
};

mapkd: MAPKD_MARKER FILEPATH 
{
  	if(MTL_CALL_BACK->onSetDiffuseTextureMap)
	{
    	MTL_CALL_BACK->onSetDiffuseTextureMap($2->c_str(),MTL_USER_DATA);
	}
	delete $2;
};

mapks: MAPKS_MARKER FILEPATH 
{
	if(MTL_CALL_BACK->onSetSpecularTextureMap)
	{
		MTL_CALL_BACK->onSetSpecularTextureMap($2->c_str(),MTL_USER_DATA);
	}
	delete $2;
};

mapd: MAPD_MARKER FILEPATH 
{
	if(MTL_CALL_BACK->onSetAlphaTextureMap)
	{
		MTL_CALL_BACK->onSetAlphaTextureMap($2->c_str(),MTL_USER_DATA);
	}
	delete $2;
};

mapbump: MAPBUMP_MARKER FILEPATH 
{
	if(MTL_CALL_BACK->onSetBumpTextureMap)
	{
		MTL_CALL_BACK->onSetBumpTextureMap($2->c_str(),MTL_USER_DATA);
	}
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

