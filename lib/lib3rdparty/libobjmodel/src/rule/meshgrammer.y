%{
#include <stdio.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMeshGrammer.h"
#include "LibObjMeshScanner.h"


#define MESH_DATA ((LibObjMesh*)(param->m_data))


#define param_scanner param->m_scanner



void libobjmesh_error(void* param,const char* msg)
{

	fprintf(stderr,"error: %s at line<%d><%s>\n ",
			msg,
			libobjmesh_get_lineno(((LibObjParserContext*)param)->m_scanner),
			libobjmesh_get_text(((LibObjParserContext*)param)->m_scanner));
}



%}

%error-verbose

%parse-param{LibObjParserContext* param}
%lex-param{void* param_scanner}

%define api.pure
%define api.prefix{libobjmesh_}


%union
{
	int itype;    		/* integer */
	float ftype;    	/* float value */
	std::string* ctype;  /* ctype */
};



%token ERR
%token EOL
%token <ftype> DECIMAL
%token <itype> INTEGER
%token <ctype> WORD
%token MATERIALLIB_MARKER
%token <ctype> MTLFILEPATH
%token USEMATERIAL_MARKER
%token NULL_MARKER
%token VERTEX_MARKER
%token TEXEL_MARKER
%token NORMAL_MARKER
%token LINE_MARKER
%token FACE_MARKER
%token GROUP_MARKER
%token OBJECT_MARKER
%token SMOOTHINGGROUP_MARKER
%token CAMERA_MARKER
%token OFF_WORD

%type <ftype> value
%type <ctype> std_string
%type <ctype> groupname

/* start of grammar */
%start objfile

%%

objfile: objfile obj_line EOL
| objfile EOL
|
;

obj_line: vertex
| object
| group
| texel
| normal
| line
| face
| materiallib
| usematerial
| smoothinggroup
| camera
;

camera: CAMERA_MARKER value value value ;

vertex: VERTEX_MARKER value value value 
{
	MESH_DATA->addVertex($2,$3,$4);
} 
| VERTEX_MARKER value value value value 
{ 
	MESH_DATA->addVertex($2,$3,$4);
};

value: DECIMAL 
{ 
	$$ = $1;
}
| INTEGER 
{ 
	$$ = (float)$1;
};

std_string : WORD 
{
	$$=$1;
}
| INTEGER 
{
	char buf[128];
	sprintf(buf,"%d",$1);
	$$=new std::string(buf);
};


object: OBJECT_MARKER std_string
{
	delete $2;
};


group:GROUP_MARKER;

group: GROUP_MARKER groupnamelist ;

groupnamelist: groupname 
{
	delete $1;
}
|groupnamelist groupname  
{ 
	delete $2;
} ;


groupname: std_string
{
	$$=$1;
};

texel: TEXEL_MARKER value value
{ 
	MESH_DATA->addUv($2,$3);
};


normal: NORMAL_MARKER value value value 
{ 
	MESH_DATA->addNormal($2,$3,$4);
};

line: LINE_MARKER linedescrlist ;

linedescrlist: linedescrlist pair |   ;

pair: INTEGER '/' INTEGER | INTEGER ;


face: FACE_MARKER vertexdescrlist ;

vertexdescrlist: vertexdescrlist tripple
| 
{ 
	MESH_DATA->getCurSubMesh()->newFace();
	
};

tripple: INTEGER '/' INTEGER '/' INTEGER 
{
	MESH_DATA->getCurSubMesh()->addVertexIndex($1,$3,$5);
} 
| INTEGER '/' '/' INTEGER 
{ 
	MESH_DATA->getCurSubMesh()->addVertexIndex($1,0,$4);
}
| INTEGER '/' INTEGER 
{ 
	MESH_DATA->getCurSubMesh()->addVertexIndex($1,$3,0);
}
| INTEGER 
{ 
	MESH_DATA->getCurSubMesh()->addVertexIndex($1,0,0);
};

materiallib: MATERIALLIB_MARKER MTLFILEPATH 
{ 
	MESH_DATA->setMaterialLibName($2->c_str());
	delete $2;
};

usematerial: USEMATERIAL_MARKER WORD 
{		   
	MESH_DATA->commitSubMesh();
	MESH_DATA->getCurSubMesh()->setMaterialName($2->c_str());
	delete $2;
}
| USEMATERIAL_MARKER NULL_MARKER 
{

};


smoothinggroup: SMOOTHINGGROUP_MARKER groupid ;

groupid: OFF_WORD 
{
}
| INTEGER {
}

%%

LibObjMesh* LibObj_ParseMesh(void* file,LibObj_ReadIoFunc io_func)
{
	LibObjMesh* mesh=new LibObjMesh;
	yyscan_t scanner=NULL;
	libobjmesh_lex_init(&scanner);

	LibObjParserContext* parser=new LibObjParserContext(scanner,mesh,file,io_func);
	
	libobjmesh_set_extra(parser,scanner);
	
	if(libobjmesh_parse(parser)!=0)
	{
		delete mesh;
		mesh=NULL;
	}
	libobjmesh_lex_destroy(scanner);
	delete parser;

	return mesh;
}




