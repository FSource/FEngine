"Feature  \n\
{  \n\
  \n\
	light : true  \n\
	colorMap : true  \n\
	diffuseMap: true \n\
	specularMap: true \n\
}  \n\
  \n\
UniformMap  \n\
{  \n\
	u_wvp_mat=$(R.WORLD_VIEW_PROJECTION_MAT)  \n\
	u_wv_it_mat=$(R.WORLD_VIEW_INVERSE_TRANSPOSE_MAT)  \n\
	u_wv_mat=$(R.WORLD_VIEW_MAT)  \n\
	u_v_mat=$(R.VIEW_MAT)  \n\
  \n\
	u_emissive=$(M.EMISSIVE)  \n\
	u_ambient=$(M.AMBIENT)  \n\
	u_diffuse=$(M.DIFFUSE)  \n\
	u_specular=$(M.SPECULAR)  \n\
	u_shininess=$(M.SHININESS)  \n\
  \n\
	u_ambientLightColor=$(L.AMBIENT_LIGHT_COLOR)  \n\
  \n\
    u_pointLightColor = $(L.POINT_LIGHT_COLOR)  \n\
	u_pointLightPosition=$(L.POINT_LIGHT_POSITION)  \n\
	u_pointLightDistance=$(L.POINT_LIGHT_DISTANCE)  \n\
  \n\
	u_directionalLightColor 	=$(L.DIRECTIONAL_LIGHT_COLOR)  \n\
	u_directionalLightDirection =$(L.DIRECTIONAL_LIGHT_DIRECTION)  \n\
  \n\
	u_hemiSphereLightDirection  =$(L.HEMI_SPHERE_LIGHT_DIRECTION)  \n\
	u_hemiSphereLightSkyColor   =$(L.HEMI_SPHERE_LIGHT_SKY_COLOR)  \n\
	u_hemiSphereLightGroundColor=$(L.HEMI_SPHERE_LIGHT_GROUND_COLOR)  \n\
  \n\
  \n\
	u_spotLightColor		=$(L.SPOT_LIGHT_COLOR)  \n\
	u_spotLightPosition 	=$(L.SPOT_LIGHT_POSITION)  \n\
	u_spotLightDirection	=$(L.SPOT_LIGHT_DIRECTION)  \n\
	u_spotLightDistance		=$(L.SPOT_LIGHT_DISTANCE)  \n\
	u_spotLightCosAngle		=$(L.SPOT_LIGHT_COSANGLE)  \n\
	u_spotLightExponent		=$(L.SPOT_LIGHT_EXPONENT)  \n\
  \n\
	u_colorMap=$(M.COLOR_MAP)  \n\
	u_diffuseMap=$(M.DIFFUSE_MAP)  \n\
	u_specularMap=$(M.SPECULAR_MAP)  \n\
}  \n\
  \n\
AttributeMap  \n\
{  \n\
	a_position=$(VERTICES)  \n\
	a_normal=$(NORMALS)  \n\
	a_texCoord=$(UVS)  \n\
}  \n\
  \n\
  \n\
VertexShader  \n\
{  \n\
	uniform mat4 u_wvp_mat;  \n\
	uniform mat4 u_wv_mat;  \n\
	uniform mat4 u_wv_it_mat;  \n\
  \n\
	attribute vec4 a_position;  \n\
	attribute vec3 a_normal;  \n\
  \n\
#if defined(FS_COLOR_MAP) || defined(FS_DIFFUSE_MAP) || defined(FS_SPECULAR_MAP)    \n\
	attribute vec2 a_texCoord;  \n\
  \n\
#ifdef GL_ES  \n\
	varying  mediump vec2 v_texCoord;  \n\
#else   \n\
	varying vec2 v_texCoord;  \n\
#endif   \n\
  \n\
#endif   \n\
  \n\
	varying vec3 v_normal;  \n\
	varying vec3 v_position;  \n\
  \n\
	void main()  \n\
	{  \n\
		v_normal=normalize((u_wv_it_mat*vec4(a_normal,0.0)).xyz);  \n\
		v_position=(u_wv_mat*a_position).xyz;  \n\
  \n\
#if defined(FS_COLOR_MAP) ||defined(FS_DIFFUSE_MAP) || defined(FS_SPECULAR_MAP)    \n\
		v_texCoord=a_texCoord;  \n\
#endif   \n\
		gl_Position=u_wvp_mat*a_position;  \n\
	}  \n\
}  \n\
  \n\
  \n\
FragmentShader   \n\
{  \n\
  \n\
#ifdef GL_ES  \n\
	precision lowp float;	  \n\
#endif  \n\
  \n\
  \n\
#ifdef FS_AMBIENT_LIGHT_NU   \n\
	uniform vec3 u_ambientLightColor;  \n\
#endif   \n\
  \n\
#ifdef FS_DIRECTIONAL_LIGHT_NU   \n\
	uniform vec3 u_directionalLightColor[FS_DIRECTIONAL_LIGHT_NU];  \n\
	uniform vec3 u_directionalLightDirection[FS_DIRECTIONAL_LIGHT_NU];  \n\
#endif   \n\
  \n\
#ifdef FS_POINT_LIGHT_NU   \n\
	uniform  vec3  u_pointLightColor[FS_POINT_LIGHT_NU];  \n\
	uniform  vec3  u_pointLightPosition[FS_POINT_LIGHT_NU];  \n\
	uniform  float u_pointLightDistance[FS_POINT_LIGHT_NU];  \n\
#endif   \n\
  \n\
#ifdef FS_SPOT_LIGHT_NU   \n\
	uniform vec3  u_spotLightColor[FS_SPOT_LIGHT_NU];  \n\
	uniform vec3  u_spotLightPosition[FS_SPOT_LIGHT_NU];  \n\
	uniform vec3  u_spotLightDirection[FS_SPOT_LIGHT_NU];  \n\
	uniform float u_spotLightDistance[FS_SPOT_LIGHT_NU];  \n\
	uniform float u_spotLightCosAngle[FS_SPOT_LIGHT_NU];  \n\
	uniform float u_spotLightExponent[FS_SPOT_LIGHT_NU];  \n\
#endif   \n\
  \n\
#ifdef FS_HEMI_SPHERE_LIGHT_NU   \n\
	uniform vec3 u_hemiSphereLightSkyColor[FS_HEMI_SPHERE_LIGHT_NU];  \n\
	uniform vec3 u_hemiSphereLightGroundColor[FS_HEMI_SPHERE_LIGHT_NU];  \n\
	uniform vec3 u_hemiSphereLightDirection[FS_HEMI_SPHERE_LIGHT_NU];  \n\
#endif   \n\
  \n\
#ifdef FS_COLOR_MAP   \n\
	uniform sampler2D u_colorMap;  \n\
#endif   \n\
  \n\
#ifdef FS_DIFFUSE_MAP   \n\
	uniform sampler2D u_diffuseMap;  \n\
#endif   \n\
  \n\
#ifdef FS_SPECULAR_MAP  \n\
	uniform sampler2D u_specularMap;  \n\
#endif   \n\
	  \n\
	uniform vec3 u_emissive;  \n\
	uniform vec3 u_ambient;  \n\
	uniform vec3 u_diffuse;  \n\
	uniform vec3 u_specular;  \n\
	uniform float u_shininess;  \n\
  \n\
  \n\
	/* matrix */  \n\
	uniform mat4 u_v_mat;  \n\
  \n\
  \n\
#if defined(FS_COLOR_MAP) ||defined(FS_DIFFUSE_MAP) ||defined(FS_SPECULAR_MAP)    \n\
	varying  vec2 v_texCoord;  \n\
#endif   \n\
  \n\
	varying vec3 v_normal;  \n\
	varying vec3 v_position;  \n\
  \n\
  \n\
	void main()  \n\
	{  \n\
  \n\
		vec3 normal=normalize(v_normal);  \n\
		vec3 view_dir=normalize(v_position)*-1.0;  \n\
  \n\
#ifdef FS_AMBIENT_LIGHT_NU   \n\
		vec3 l_ambient=u_ambientLightColor;  \n\
#else   \n\
		vec3 l_ambient=vec3(0);  \n\
#endif   \n\
		vec3 l_diffuse=vec3(0);  \n\
		vec3 l_specular=vec3(0);  \n\
  \n\
  \n\
  \n\
  \n\
#ifdef FS_DIRECTIONAL_LIGHT_NU   \n\
		  \n\
		for(int i=0;i<FS_DIRECTIONAL_LIGHT_NU;i++)  \n\
		{  \n\
			vec3 ld_direction= normalize((u_v_mat* vec4(u_directionalLightDirection[i],0.0)).xyz);  \n\
  \n\
			float df_dot_value=dot(normal,ld_direction);  \n\
			if(df_dot_value<0.0)  \n\
			{  \n\
				df_dot_value=0.0;  \n\
			}  \n\
  \n\
			/* diffuse */  \n\
			l_diffuse+=df_dot_value*u_directionalLightColor[i];  \n\
  \n\
			/* specular */  \n\
			vec3 ld_half_vector=normalize(ld_direction+view_dir);  \n\
			float sp_dot_value=dot(normal,ld_half_vector);  \n\
  \n\
			if(sp_dot_value<0.0)  \n\
			{  \n\
				sp_dot_value=0.0;  \n\
			}  \n\
			float sp_value=pow(sp_dot_value,u_shininess);  \n\
			l_specular+=sp_value*u_directionalLightColor[i];  \n\
  \n\
		}  \n\
#endif   \n\
  \n\
#ifdef FS_POINT_LIGHT_NU   \n\
		for(int i=0;i<FS_POINT_LIGHT_NU;i++)  \n\
		{  \n\
			vec4 lp_point_pos=u_v_mat*vec4(u_pointLightPosition[i],1.0);  \n\
			vec3 lp_point_dir=lp_point_pos.xyz-v_position;  \n\
  \n\
			float lp_intensity=1.0-length(lp_point_dir)/u_pointLightDistance[i];  \n\
			if(lp_intensity<0.0)  \n\
			{  \n\
				lp_intensity=0.0;  \n\
			}  \n\
  \n\
			lp_point_dir=normalize(lp_point_dir);  \n\
  \n\
			/* diffuse */  \n\
			float lp_dot_value=dot(normal,lp_point_dir);  \n\
			if(lp_dot_value<0.0)  \n\
			{  \n\
				lp_dot_value=0.0;  \n\
			}  \n\
			l_diffuse+=lp_dot_value*lp_intensity*u_pointLightColor[i];  \n\
  \n\
			/* specular */  \n\
			vec3 lp_half_vector=normalize(lp_point_dir+view_dir);  \n\
			float lp_half_dot_value=dot(normal,lp_half_vector);  \n\
			if(lp_half_dot_value<0.0)  \n\
			{  \n\
				lp_half_dot_value=0.0;  \n\
			}  \n\
			float lp_value=pow(lp_half_dot_value,u_shininess);  \n\
			l_specular+=lp_value*u_pointLightColor[i]*lp_intensity;  \n\
		}  \n\
#endif   \n\
  \n\
#ifdef FS_HEMI_SPHERE_LIGHT_NU   \n\
		for(int i=0;i<FS_HEMI_SPHERE_LIGHT_NU;i++)  \n\
		{  \n\
			vec3 l_hemi_direction=normalize((u_v_mat*vec4(u_hemiSphereLightDirection[i],0.0)).xyz);  \n\
			float dot_value=dot(normal,l_hemi_direction);  \n\
			dot_value=0.5+0.5*dot_value;  \n\
			l_diffuse+=mix(u_hemiSphereLightGroundColor[i],u_hemiSphereLightSkyColor[i],dot_value);  \n\
		}  \n\
#endif   \n\
  \n\
#ifdef FS_SPOT_LIGHT_NU   \n\
		for(int i=0;i<FS_SPOT_LIGHT_NU;i++)  \n\
		{  \n\
			vec3 l_spot_center_dir=normalize((u_v_mat*vec4(u_spotLightDirection[i],0.0)).xyz);  \n\
			vec4 l_spot_pos = u_v_mat*vec4(u_spotLightPosition[i],1.0);  \n\
			vec3 l_spot_dir=  l_spot_pos.xyz-v_position;  \n\
			vec3 l_spot_n_dir= normalize(l_spot_dir);  \n\
			float spot_value=dot(l_spot_center_dir,l_spot_n_dir);  \n\
			if(spot_value>u_spotLightCosAngle[i])  \n\
			{  \n\
				spot_value=pow(spot_value,u_spotLightExponent[i]);  \n\
				float l_intensity=1.0-length(l_spot_dir)/u_spotLightDistance[i];  \n\
				if(l_intensity<0.0)  \n\
				{  \n\
					l_intensity=0.0;  \n\
				}  \n\
  \n\
				/* diffuse */  \n\
				float dot_value=dot(normal,l_spot_n_dir);  \n\
				if(dot_value<0.0)  \n\
				{  \n\
					dot_value=0.0;  \n\
				}  \n\
				l_diffuse+=dot_value*l_intensity*u_spotLightColor[i]*spot_value;  \n\
  \n\
				/* specular */  \n\
				vec3 ls_half_vector=normalize(l_spot_n_dir+view_dir);  \n\
				float ls_half_dot_value=dot(normal,ls_half_vector);  \n\
				if(ls_half_dot_value<0.0)  \n\
				{  \n\
					ls_half_dot_value=0.0;  \n\
				}  \n\
				float ls_value=pow(ls_half_dot_value,u_shininess);  \n\
				l_specular+=ls_value*u_spotLightColor[i]*l_intensity*spot_value;  \n\
			}  \n\
		}  \n\
#endif   \n\
  \n\
		/* output */  \n\
		gl_FragColor=vec4(u_emissive,1.0);  \n\
  \n\
  \n\
#ifdef FS_COLOR_MAP   \n\
		vec3 base_color=texture2D(u_colorMap,v_texCoord).rgb;  \n\
#else   \n\
		vec3 base_color=vec3(1);  \n\
#endif   \n\
		gl_FragColor.rgb+=base_color*l_ambient*u_ambient;  \n\
  \n\
#ifdef FS_DIFFUSE_MAP   \n\
		gl_FragColor.rgb+=l_diffuse*texture2D(u_diffuseMap,v_texCoord).rgb*u_diffuse;  \n\
#else   \n\
		gl_FragColor.rgb+=l_diffuse*base_color*u_diffuse;  \n\
#endif  \n\
  \n\
#ifdef FS_SPECULAR_MAP   \n\
		gl_FragColor.rgb+=l_specular*texture2D(u_specularMap,v_texCoord).rgb*u_specular;  \n\
#else   \n\
		gl_FragColor.rgb+=l_specular*base_color*u_specular;  \n\
#endif   \n\
  \n\
  \n\
	}  \n\
  \n\
}"  ; 
