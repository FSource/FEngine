"Feature   \n\
{   \n\
   \n\
	light : true   \n\
	colorMap : true   \n\
}   \n\
   \n\
UniformMap   \n\
{   \n\
	u_wvp_mat=$(R.WORLD_VIEW_PROJECTION_MAT)   \n\
	u_wv_it_mat=$(R.WORLD_VIEW_INVERSE_TRANSPOSE_MAT)   \n\
	u_wv_mat=$(R.WORLD_VIEW_MAT)   \n\
	u_v_mat=$(R.VIEW_MAT)   \n\
   \n\
	u_emissive=$(M.EMISSIVE)   \n\
	u_ambient=$(M.AMBIENT)   \n\
	u_diffuse=$(M.DIFFUSE)   \n\
   \n\
	u_ambientLightColor=$(L.AMBIENT_LIGHT_COLOR)   \n\
   \n\
    u_pointLightColor = $(L.POINT_LIGHT_COLOR)   \n\
	u_pointLightPosition=$(L.POINT_LIGHT_POSITION)   \n\
	u_pointLightDistance=$(L.POINT_LIGHT_DISTANCE)   \n\
   \n\
	u_colorMap=$(M.COLOR_MAP)   \n\
}   \n\
   \n\
AttributeMap   \n\
{   \n\
	a_position=$(VERTICES)   \n\
	a_normal=$(NORMALS)   \n\
	a_texCoord=$(UVS)   \n\
}   \n\
   \n\
   \n\
VertexShader   \n\
{   \n\
	uniform mat4 u_wvp_mat;   \n\
	uniform mat4 u_wv_it_mat;   \n\
	uniform mat4 u_wv_mat;   \n\
	uniform mat4 u_v_mat;   \n\
   \n\
	uniform vec3 u_emissive;   \n\
	uniform vec3 u_ambient;   \n\
	uniform vec3 u_diffuse;   \n\
   \n\
   \n\
#ifdef FS_AMBIENT_LIGHT_NU   \n\
	uniform vec3 u_ambientLightColor;   \n\
#endif   \n\
   \n\
   \n\
#ifdef  FS_POINT_LIGHT_NU   \n\
	uniform  vec3  u_pointLightColor[FS_POINT_LIGHT_NU];   \n\
	uniform  vec3  u_pointLightPosition[FS_POINT_LIGHT_NU];   \n\
	uniform  float u_pointLightDistance[FS_POINT_LIGHT_NU];   \n\
#endif   \n\
   \n\
   \n\
	attribute vec4 a_position;   \n\
	attribute vec3 a_normal;   \n\
   \n\
   \n\
   \n\
	varying vec3 v_light;   \n\
   \n\
#ifdef FS_COLOR_MAP   \n\
	attribute vec2 a_texCoord;   \n\
#ifdef GL_ES   \n\
	varying mediump vec2 v_texCoord;   \n\
#else   \n\
	varying vec2 v_texCoord;   \n\
#endif   \n\
#endif   \n\
   \n\
	void main()   \n\
	{																   \n\
		gl_Position=u_wvp_mat*a_position;   \n\
   \n\
		vec4 mv_position=u_wv_mat*a_position;   \n\
		vec3 mv_normal=(u_wv_it_mat*vec4(a_normal,0.0)).xyz;   \n\
		mv_normal=normalize(mv_normal);   \n\
   \n\
   \n\
		vec3 l_diffuse=vec3(0);   \n\
   \n\
   \n\
		/* handle point light */   \n\
#ifdef FS_POINT_LIGHT_NU   \n\
		for( int i=0;i<FS_POINT_LIGHT_NU;i++)   \n\
		{   \n\
			vec4 l_point_pos=u_v_mat*vec4(u_pointLightPosition[i],1.0);   \n\
			vec3 l_point_dir=l_point_pos.xyz-mv_position.xyz;   \n\
   \n\
			float l_intensity=1-length(l_point_dir)/u_pointLightDistance[i];   \n\
   \n\
			if(l_intensity<0.0)   \n\
			{   \n\
				l_intensity=0.0;   \n\
			}   \n\
   \n\
			l_point_dir=normalize(l_point_dir);   \n\
			float dot_value=dot(mv_normal,l_point_dir);   \n\
			if(dot_value<0.0)   \n\
			{   \n\
				dot_value=0.0;   \n\
			}   \n\
   \n\
			l_diffuse+=u_pointLightColor[i]*dot_value*l_intensity;   \n\
		}   \n\
   \n\
#endif   \n\
	   \n\
#ifdef FS_AMBIENT_LIGHT_NU 			   \n\
		v_light=u_ambientLightColor*u_ambient + l_diffuse*u_diffuse + u_emissive;   \n\
#else   \n\
		v_light=l_diffuse*u_diffuse+u_emissive;   \n\
#endif   \n\
   \n\
   \n\
#ifdef FS_COLOR_MAP   \n\
		v_texCoord=a_texCoord;   \n\
#endif   \n\
   \n\
	}														   \n\
}   \n\
   \n\
   \n\
FragmentShader   \n\
{   \n\
   \n\
#ifdef GL_ES   \n\
	precision lowp float;	   \n\
#endif   \n\
   \n\
#ifdef FS_COLOR_MAP   \n\
	uniform sampler2D u_colorMap;   \n\
	varying  vec2 v_texCoord;   \n\
#endif   \n\
   \n\
	varying vec3 v_light;   \n\
   \n\
   \n\
	void main()			   \n\
	{						   \n\
   \n\
#ifdef FS_COLOR_MAP   \n\
		vec3 color_map=texture2D(u_colorMap,v_texCoord).rgb;   \n\
#else   \n\
		vec3 color_map=vec3(1.0);   \n\
#endif   \n\
		gl_FragColor=vec4(v_light*color_map,1.0);   \n\
   \n\
	}								   \n\
}" ;  
