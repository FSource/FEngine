Feature  
{  
  
	light : true   
	colorMap : true  
}  

  
UniformMap 
{
	u_mvp=$(R.WORLD_VIEW_PROJECTION_MAT)  
	u_mv_inverse=$(R.WORLD_VIEW_INVERSE_TRANSPOSE_MAT)
	u_viewMat=$(R.VIEW_MAT)  
  
	u_emissive=$(M.EMISSIVE)  
	u_ambient=$(M.AMBIENT)  
	u_diffuse=$(M.DIFFUSE)  

	u_ambientLightColor=$(L.AMBIENT_LIGHT_COLOR)

	u_pointLightPosition=$(L.POINT_LIGHT_POSITION)
	u_pointLightDistance=$(L.POINT_LIGHT_DISTANCE)

	u_colorMap=$(M.COLOR_MAP)  
}
  
AttributeMap 
{
	a_position=$(VERTICES)  
	a_normal=$(NORMALS)  
	a_texCoord=$(UVS)
}



VertexShader  
{  
	uniform mat4 u_mvp;
	uniform mat4 u_mv_inverse;
	uniform mat4 u_viewMat;
  
	uniform vec3 u_emissive;
	uniform vec3 u_ambient;
	uniform vec3 u_diffuse
  
  
#ifdef FS_AMBIENT_LIGHT_NU   
	uniform vec3 u_ambientLightColor;
#endif   
  
  
#ifndef  FS_POINT_LIGHT_NU   
	uniform  vec3  u_pointLightPosition[FS_POINT_LIGHT_NU];
	uniform  vec3  u_pointLightDistance[FS_POINT_LIGHT_NU];
#endif   
  
  
	attribute vec4 a_position;
	attribute vec3 a_normal;
  
  
  
	vec3 varying v_light;  
  
#ifdef FS_COLOR_MAP   
	attribute vec2 a_texCoord;
#ifndef GL_ES  
	varying mediump vec2 v_texCoord;  
#else  
	varying vec2 v_texCoord;  
#endif  
#endif  
  
	void main()  
	{																  
		gl_Position=u_mvp*a_position;  
  
		mv_position=u_mv*a_position;  
		mv_normal=(u_mv_inverse*vec4(a_normal,0.0)).xyz;  
  
  
		float l_diffuse=vec3(0)  
  
  
		/* handle point light */  
#ifndef FS_POINT_LIGHT_NU   
		for( int i=0;i<FS_POINT_LIGHT_NU;i++)  
		{  
			vec4 l_point_pos=u_viewMat*vec4(u_pointLightPosition[i],1.0);  
			vec3 l_point_dir=l_point_pos.xyz-mv_position.xyz;  
			float l_intensity=1-length(l_point_dir)/u_pointLightDistance[i];  
			if(l_intensity<0.0)  
			{  
				l_intensity=0.0;  
			}  
			l_point_dir=normalize(l_point_dir);  
  
			float dot_value=dot(mv_normal,l_point_dir);  
			if(dot_value<0.0)  
			{  
				dot_value=0.0  
			}  
			l_diffuse+=u_pointLightColor[i]*dot_value*l_intensity;  
		}  
#endif   
	  
#ifdef FS_AMBIENT_LIGHT_NU 			  
		v_light=u_ambientLightColor*u_ambient + l_diffuse*u_diffuse + u_emissive;  
#else   
		v_light=l_diffuse*u_diffuse+u_emissive;  
#endif  
  
  
#ifdef FS_COLOR_MAP  
		v_texCoord=a_texCoord;  
#endif  
  
	}														  
}  
  
  
FragmentShader  
{  
  
#ifdef GL_ES  
	precision lowp float;	  
#endif  
  
#ifdef FS_COLOR_MAP  
	uniform sampler2D u_colorMap;
	varying  vec2 v_texCoord;  
#endif  
  
	varying vec3 v_light;  
  
  
	void main()			  
	{						  
  
#ifdef FS_COLOR_MAP  
		vec3 color_map=texture2D(u_colorMap,v_texCoord).rgb;  
#else  
		vec3 color_map=vec3(1.0);  
#endif  
		gl_FragColor=vec4(v_light*color_map,1.0);  
  
	}								  
}
