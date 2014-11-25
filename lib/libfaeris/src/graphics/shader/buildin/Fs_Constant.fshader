"Feature    \n\
{    \n\
	ambientLight : true    \n\
	colorMap : true    \n\
}    \n\
    \n\
UniformMap     \n\
{    \n\
	u_mvp =$(R.WORLD_VIEW_PROJECTION_MAT)    \n\
	u_emissive=$(M.EMISSIVE)    \n\
	u_ambient=$(M.AMBIENT)    \n\
	u_colorMap=$(M.COLOR_MAP)    \n\
	u_ambientLightColor= $(L.AMBIENT_LIGHT_COLOR)    \n\
}    \n\
    \n\
AttributeMap     \n\
{    \n\
	a_position=$(VERTICES)     \n\
	a_texCoord=$(UVS)    \n\
}    \n\
    \n\
    \n\
    \n\
VertexShader    \n\
{    \n\
	uniform mat4 u_mvp;    \n\
    \n\
	attribute vec4 a_position;    \n\
    \n\
    \n\
#ifdef FS_COLOR_MAP    \n\
	attribute vec2 a_texCoord;    \n\
    \n\
#ifdef GL_ES    \n\
	varying mediump vec2 v_texCoord;    \n\
#else    \n\
	varying vec2 v_texCoord;    \n\
#endif    \n\
    \n\
#endif    \n\
    \n\
	void main()    \n\
	{																    \n\
		gl_Position=u_mvp*a_position;    \n\
    \n\
#ifdef FS_COLOR_MAP    \n\
		v_texCoord=a_texCoord;    \n\
#endif    \n\
    \n\
	}														    \n\
}    \n\
    \n\
    \n\
FragmentShader    \n\
{    \n\
    \n\
#ifdef GL_ES    \n\
	precision lowp float;	    \n\
#endif    \n\
    \n\
	uniform vec3  u_emissive;    \n\
	uniform vec3  u_ambient;    \n\
    \n\
#ifdef FS_COLOR_MAP    \n\
	uniform sampler2D u_colorMap;    \n\
	varying  vec2 v_texCoord;    \n\
#endif    \n\
    \n\
    \n\
#ifdef FS_AMBIENT_LIGHT_NU    \n\
	uniform vec3 u_ambientLightColor;    \n\
#endif    \n\
    \n\
	void main()			    \n\
	{						    \n\
    \n\
#ifdef FS_COLOR_MAP    \n\
		vec3 color_map=texture2D(u_colorMap,v_texCoord).rgb;    \n\
#else    \n\
		vec3 color_map=vec3(1.0);    \n\
#endif    \n\
		gl_FragColor=vec4(u_emissive*color_map,1.0);    \n\
    \n\
    \n\
#ifdef FS_AMBIENT_LIGHT_NU    \n\
		vec3 ambient_color=u_ambient*u_ambientLightColor*color_map;    \n\
#else    \n\
		vec3 ambient_color=vec3(0.0);    \n\
#endif    \n\
    \n\
		gl_FragColor.rgb+=ambient_color;    \n\
	}								    \n\
}" ; 
