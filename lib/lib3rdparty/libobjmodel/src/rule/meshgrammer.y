%{
#include <stdio.h>
#include <string>

#include "LibObjModel.h"
#include "LibObjMeshGrammer.h"
#include "LibObjMeshScanner.h"


#define MESH_CALL_BACK (param->m_callbacks)
#define MESH_USER_DATA (param->m_userdata)


#define param_scanner param->m_scanner



void libobjmesh_error(void* param,const char* s)
{
	fprintf(stderr,"parase mesh error:%s\n",s);
}



%}

%error-verbose

%parse-param{LibObjMeshContext* param}
%lex-param{LibObjMeshContext* param_scanner}

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
	if(MESH_CALL_BACK->onVertex)
	{
		MESH_CALL_BACK->onVertex($2,$3,$4,1.0f,MESH_USER_DATA);
	}
} 
| VERTEX_MARKER value value value value 
{ 
	if(MESH_CALL_BACK->onVertex)
	{
		MESH_CALL_BACK->onVertex($2,$3,$4,$5,MESH_USER_DATA);
	}
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
	if(MESH_CALL_BACK->onStartObject)
	{
		MESH_CALL_BACK->onStartObject($2->c_str(),MESH_USER_DATA);
	}
	delete $2;
};


group: GROUP_MARKER groupnamelist ;

groupnamelist: groupname 
{
  	if(MESH_CALL_BACK->onStartGroup)
	{
   	 	MESH_CALL_BACK->onStartGroup(MESH_USER_DATA);
	}
	if(MESH_CALL_BACK->onGroupName)
	{
		MESH_CALL_BACK->onGroupName($1->c_str(),MESH_USER_DATA);
	}
	delete $1;
}
|groupnamelist groupname  
{ 
	if(MESH_CALL_BACK->onGroupName)
	{
		MESH_CALL_BACK->onGroupName($2->c_str(),MESH_USER_DATA);
	}
	delete $2;
};


groupname: std_string
{
	$$=$1;
};

texel: TEXEL_MARKER value value
{ 
	if(MESH_CALL_BACK->onTexel)
	{
		MESH_CALL_BACK->onTexel($2,$3,MESH_USER_DATA);
	}
};


normal: NORMAL_MARKER value value value 
{ 
	if(MESH_CALL_BACK->onNormal)
	{
		MESH_CALL_BACK->onNormal($2,$3,$4,MESH_USER_DATA);
	}
};

line: LINE_MARKER linedescrlist ;

linedescrlist: linedescrlist pair
| { 
	if(MESH_CALL_BACK->onStartLine)
	{
		MESH_CALL_BACK->onStartLine(MESH_USER_DATA);
	}
};

pair: INTEGER '/' INTEGER 
{ 
  	if(MESH_CALL_BACK->onAddToLine)
	{
   		 MESH_CALL_BACK->onAddToLine($1, $3,MESH_USER_DATA);
	}
}
| INTEGER 
{ 
  	if(MESH_CALL_BACK->onAddToLine)
	{
    	MESH_CALL_BACK->onAddToLine($1, 0, MESH_USER_DATA);
	}
};

face: FACE_MARKER vertexdescrlist ;

vertexdescrlist: vertexdescrlist tripple
| 
{ 
	if(MESH_CALL_BACK->onStartFace)
	{
    	MESH_CALL_BACK->onStartFace(MESH_USER_DATA);
	}
};

tripple: INTEGER '/' INTEGER '/' INTEGER 
{
  	if(MESH_CALL_BACK->onAddToFace)
	{
		MESH_CALL_BACK->onAddToFace($1,$3,$5,MESH_USER_DATA);
	}
} 
| INTEGER '/' '/' INTEGER 
{ 
	if(MESH_CALL_BACK->onAddToFace)
	{
    	MESH_CALL_BACK->onAddToFace($1, 0, $4, MESH_USER_DATA);
	}
}
| INTEGER '/' INTEGER 
{ 
	if(MESH_CALL_BACK->onAddToFace)
	{
    	MESH_CALL_BACK->onAddToFace($1, $3, 0, MESH_USER_DATA);
	}
}
| INTEGER 
{ 
	if(MESH_CALL_BACK->onAddToFace)
	{
		MESH_CALL_BACK->onAddToFace($1,0,0,MESH_USER_DATA);
	}
};

materiallib: MATERIALLIB_MARKER MTLFILEPATH 
{ 
	if(MESH_CALL_BACK->onRefMaterialLib)
	{
		MESH_CALL_BACK->onRefMaterialLib($2->c_str(),MESH_USER_DATA);
	}
	delete $2;
};

usematerial: USEMATERIAL_MARKER WORD 
{		   
	if(MESH_CALL_BACK->onRefMaterialLib)
	{
		MESH_CALL_BACK->onRefMaterialLib($2->c_str(),MESH_USER_DATA);
	}
	delete $2;
}
| USEMATERIAL_MARKER NULL_MARKER { 
	if(MESH_CALL_BACK->onRefMaterialLib)
	{
		MESH_CALL_BACK->onRefMaterialLib("",MESH_USER_DATA);
	}
};


smoothinggroup: SMOOTHINGGROUP_MARKER groupid ;

groupid: OFF_WORD 
{
  	if(MESH_CALL_BACK->onSmoothingGroup)
	{
    	MESH_CALL_BACK->onSmoothingGroup(0, MESH_USER_DATA);
	}
}
| INTEGER {
  	if(MESH_CALL_BACK->onSmoothingGroup)
	{
		MESH_CALL_BACK->onSmoothingGroup($1,MESH_USER_DATA);
	}
}

%%


