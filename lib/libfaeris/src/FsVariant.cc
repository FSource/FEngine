/*************************************************************************/
/*  FsVariant.cc                                                         */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "FsVariant.h"
#include "support/util/FsScriptUtil.h"

NS_FS_BEGIN

FsVariant::FsVariant()
{
	m_type=FsType::FT_IN_VALID;
	m_value=NULL;
}

FsVariant::FsVariant(FsType t, const void* value)
{
	init(t,value);
}

FsVariant::FsVariant(float v)
{
	init(FsType::FT_F_1,&v);
}

FsVariant::FsVariant(const Vector2& v)
{
	init(FsType::FT_F_2,&v);
}

FsVariant::FsVariant(const Vector3& v)
{
	init(FsType::FT_F_3,&v);
}
FsVariant::FsVariant(const Vector4& v)
{
	init(FsType::FT_F_4,&v);
}



FsVariant::FsVariant(int32_t v)
{
	init(FsType::FT_I_1,&v);
}

FsVariant::FsVariant(const Vector2i& v)
{
	init(FsType::FT_I_2,&v);
}

FsVariant::FsVariant(const Vector3i& v)
{
	init(FsType::FT_I_3,&v);
}

FsVariant::FsVariant(const Vector4i& v)
{
	init(FsType::FT_I_4,&v);
}



FsVariant::FsVariant(const Matrix4& v)
{
	init(FsType::FT_MAT4,&v);
}

FsVariant::FsVariant(FsObject* v)
{
	init(FsType::FT_OBJECT,v);
}

FsVariant::FsVariant(FsString* v)
{
	init(FsType::FT_STRING,v);
}

FsVariant::FsVariant(FsDict* v)
{
	init(FsType::FT_DICT,v);
}

FsVariant::FsVariant(FsArray* v)
{
	init(FsType::FT_ARRAY,v);
}

FsVariant::FsVariant(const char* str)
{
	init(FsType::FT_CHARS,str);
}

FsVariant::FsVariant(const FsVariant& value)
{
	init(value.m_type,value.m_value);
}



FsVariant::~FsVariant()
{
	destruct();
}



FsVariant& FsVariant::operator=(const FsVariant& v)
{
	destruct();
	init(v.m_type,m_value);
	return *this;
}

FsType FsVariant::getType()const
{
	return m_type;
}

void* FsVariant::getValue() const
{
	return m_value;
}

bool FsVariant::isValid() const
{
	return m_type!=FsType::FT_IN_VALID;
}

FsVariant FsVariant::getCast(FsType t) const
{
	if(m_type==t)
	{
		return *this;
	}

	switch(m_type)
	{
		case FsType::FT_B_1:
			{
				switch(t)
				{
					case FsType::FT_F_1:
						{
							float  v=float(*m_b1);
							return FsVariant(FsType::FT_F_1,&v);
						}
						break;

					case FsType::FT_I_1:
						{
							int v=int(*m_b1);
							return FsVariant(FsType::FT_I_1,&v);
						}
						break;
					default:
						break;

				}
			} 
			break;

		case FsType::FT_F_1:
			{
				switch(t)
				{
					case FsType::FT_B_1:
						{
							bool v=(bool)(*m_f1!=0.0f);
							return FsVariant(FsType::FT_B_1,&v);
						}
						break;

					case FsType::FT_I_1:
						{
							int v=int(*m_f1);
							return FsVariant(FsType::FT_I_1,&v);
						}
						break;
					default:
						break;

				}
			}
			break;

		case FsType::FT_I_1:
			{
				switch(t)
				{
					case FsType::FT_B_1:
						{
							bool v =(bool)(*m_i1!=0);
							return FsVariant(FsType::FT_B_1,&v);
						}
						break;

					case FsType::FT_F_1:
						{
							float v=float(*m_i1);
							return FsVariant(FsType::FT_F_1,&v);
						}
						break;
					default:
						break;
				}
			}
			break;

		case FsType::FT_F_2:
			{
				switch(t)
				{
					case FsType::FT_I_2:
						{
							Vector2i v((int)m_f2->x,(int)m_f2->y);
							return FsVariant(FsType::FT_I_2,&v);
						}
					default:
						break;
				}
			}
			break;

		case FsType::FT_I_2:
			{
				switch(t)
				{
					case FsType::FT_F_2:
						{
							Vector2f v((float)m_i2->x,(float)m_i2->y);
							return FsVariant(FsType::FT_F_2,&v);
						}
					default:
						break;
				}
			}
			break;

		case FsType::FT_F_3:
			{
				switch(t)
				{
					case FsType::FT_I_3:
						{
							Vector3i v((int)m_f3->x,(int)m_f3->y,(int)m_f3->z);
							return FsVariant(FsType::FT_I_3,&v);
						}
					default:
						break;
				}
			}
			break;

		case FsType::FT_I_3:
			{
				switch(t)
				{
					case FsType::FT_F_3:
						{
							Vector3f v((float)m_i3->x,(float)m_i3->y,(float)m_i3->z);
							return FsVariant(FsType::FT_F_3,&v);
						}
					default:
						break;
				}
			}
			break;



		case FsType::FT_F_4:
			{
				switch(t)
				{
					case FsType::FT_I_4:
						{
							Vector4i v((int)m_f4->x,(int)m_f4->y,(int)m_f4->z,(int)m_f4->w);
							return FsVariant(FsType::FT_I_4,&v);
						}
					default:
						break;
				}
			}
			break;

		case FsType::FT_I_4:
			{
				switch(t)
				{
					case FsType::FT_F_4:
						{
							Vector4f v((float)m_i4->x,(float)m_i4->y,(float)m_i4->z,(float)m_f4->w);
							return FsVariant(FsType::FT_F_4,&v);
						}
					default:
						break;
				}
			}
			break;

		case FsType::FT_STRING:
			{
				switch(t)
				{
					case FsType::FT_B_1:
						{
							bool v=ScriptUtil::parseBoolean(m_string);
							return FsVariant(FsType::FT_B_1,&v);
						}
						break;

					case FsType::FT_F_1:
						{
							float v=ScriptUtil::parseFloat(m_string);
							return FsVariant(FsType::FT_F_1,&v);
						}
						break;

					case FsType::FT_I_1:
						{
							int v=ScriptUtil::parseInteger(m_string);
							return FsVariant(FsType::FT_I_1,&v);
						}
						break;

					case FsType::FT_COLOR_3:
						{
							Color3f c;
							ScriptUtil::parseColor3f(m_string,&c.r,&c.g,&c.b);
							return FsVariant(FsType::FT_COLOR_3,&c);
						}
						break;

					case FsType::FT_COLOR_4:
						{
							Color4f c;
							ScriptUtil::parseColor4f(m_string,&c.r,&c.g,&c.b,&c.a);
							return FsVariant(FsType::FT_COLOR_4,&c);
						}
						break;

					case FsType::FT_CHARS:
						{
							return FsVariant(FsType::FT_CHARS,m_string->cstr());
						}
						break;
					default:
						break;
				}
			}
			break;

		case  FsType::FT_CHARS:
			{
				switch(t)
				{
					case FsType::FT_B_1:
						{
							bool v=ScriptUtil::parseBoolean(m_chars);
							return FsVariant(FsType::FT_B_1,&v);
						}
						break;

					case FsType::FT_F_1:
						{
							float v=ScriptUtil::parseFloat(m_chars);
							return FsVariant(FsType::FT_F_1,&v);
						}
						break;

					case FsType::FT_I_1:
						{
							int v=ScriptUtil::parseInteger(m_chars);
							return FsVariant(FsType::FT_I_1,&v);
						}
						break;

					case FsType::FT_COLOR_3:
						{
							Color3f c;
							ScriptUtil::parseColor3f(m_chars,&c.r,&c.g,&c.b);
							return FsVariant(FsType::FT_COLOR_3,&c);
						}
						break;

					case FsType::FT_COLOR_4:
						{
							Color4f c;
							ScriptUtil::parseColor4f(m_chars,&c.r,&c.g,&c.b,&c.a);
							return FsVariant(FsType::FT_COLOR_4,&c);
						}
						break;

					case FsType::FT_STRING:
						{
							return FsVariant(FsType::FT_STRING,FsString::create(m_chars));
						}
						break;
					default:
						break;

				}

			}
			break;


		case FsType::FT_ARRAY:
			{
				int array_nu=m_array->size();
				switch(t)
				{
					case FsType::FT_F_2:
						{
							Vector2 v;
							for(int i=0;i<array_nu&&i<2;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_F_2,&v);
						}
						break;

					case FsType::FT_F_3:
						{
							Vector3 v;
							for(int i=0;i<array_nu&&i<3;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_F_3,&v);
						}
						break;

					case FsType::FT_F_4:
						{
							Vector4 v;
							for(int i=0;i<array_nu&&i<4;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_F_4,&v);
						}
						break;


					case FsType::FT_I_2:
						{
							Vector2i v;
							for(int i=0;i<array_nu&&i<2;i++)
							{
								ScriptUtil::getInteger(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_I_2,&v);
						}
						break;
					case FsType::FT_I_3:
						{
							Vector3i v;
							for(int i=0;i<array_nu&&i<3;i++)
							{
								ScriptUtil::getInteger(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_I_3,&v);
						}
						break;

					case FsType::FT_I_4:
						{
							Vector4i v;
							for(int i=0;i<array_nu&&i<4;i++)
							{
								ScriptUtil::getInteger(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_I_4,&v);
						}
						break;


					case FsType::FT_COLOR_3:
						{
							Color3f v;
							for(int i=0;i<array_nu&&i<3;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}

							return FsVariant(FsType::FT_COLOR_3,&v);

						}
						break;

					case FsType::FT_COLOR_4:
						{
							Color4f v;
							for(int i=0;i<array_nu&&i<4;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}

							return FsVariant(FsType::FT_COLOR_4,&v);
						}
						break;

					case FsType::FT_MAT4:
						{
							Matrix4 v;
							for(int i=0;i<array_nu&&i<16;i++)
							{
								ScriptUtil::getFloat(m_array,i,&v.v[i]);
							}
							return FsVariant(FsType::FT_MAT4,&v);
						}
						break;
					default:
						break;
				}
			}
			break;
		default:
			break;
	}

	return FsVariant();
}





























void FsVariant::init(FsType t,const void* value)
{
	m_type=t;

	if(value==NULL)
	{
		m_type=FsType::FT_IN_VALID;
		m_value=NULL;
		return;
	}

	switch(t)
	{
		case FsType::FT_IN_VALID:
			m_value=NULL;
			break;

		case FsType::FT_B_1:
			m_b1=new bool();
			*m_b1=*(bool*)value;
			break;


		case FsType::FT_F_1:
			m_f1=new float();
			*m_f1=*(float*)value;
			break;

		case FsType::FT_F_2:
			m_f2=new Vector2();
			*m_f2=*(Vector2*)value;
			break;

		case FsType::FT_F_3:
			m_f3=new Vector3();
			*m_f3=*(Vector3*)value;
			break;

		case FsType::FT_F_4:
			m_f4=new Vector4();
			*m_f4=*(Vector4*)value;
			break;

		case FsType::FT_I_1:
			m_i1=new int32_t();
			*m_i1=*(int32_t*)value;
			break;

		case FsType::FT_I_2:
			m_i2=new Vector2i();
			*m_i2=*(Vector2i*)value;
			break;

		case FsType::FT_I_3:
			m_i3=new Vector3i();
			*m_i3=*(Vector3i*)value;
			break;

		case FsType::FT_I_4:
			m_i4=new Vector4i();
			*m_i4=*(Vector4i*)value;
			break;


		case FsType::FT_COLOR_3:
			m_c3=new Color3f();
			*m_c3=*(Color3f*)value;
			break;

		case FsType::FT_COLOR_4:
			m_c4=new Color4f();
			*m_c4=*(Color4f*)value;
			break;


		case FsType::FT_MAT4:
			m_mat4=new Matrix4();
			*m_mat4=*(Matrix4*)value;
			break;

		case FsType::FT_CHARS:
			{

				int size=strlen((const char*) value);
				m_chars=new char[size+1];
				strcpy(m_chars,(const char*)value);
				m_chars[size]='\0';
			}

			break;

		case FsType::FT_OBJECT:
		case FsType::FT_STRING:
		case FsType::FT_DICT:
		case FsType::FT_ARRAY:
			m_object=(FsObject*)value;
			m_object->addRef();
			if(FsString::checkType(m_object))
			{
				m_type=FsType::FT_STRING;
			}
			else if(FsDict::checkType(m_object))
			{
				m_type=FsType::FT_DICT;
			}
			else if(FsArray::checkType(m_object))
			{
				m_type=FsType::FT_ARRAY;
			}
			break;
		default:
			break;
	}
}


void FsVariant::destruct()
{
	switch(m_type)
	{
		case FsType::FT_B_1:
			delete m_b1;
			break;

		case FsType::FT_F_1:
			delete m_f1;
			break;

		case FsType::FT_F_2:
			delete m_f2;
			break;

		case FsType::FT_F_3:
			delete m_f3;
			break;

		case FsType::FT_F_4:
			delete m_f4;
			break;



		case FsType::FT_I_1:
			delete m_i1;
			break;

		case FsType::FT_I_2:
			delete m_i2;
			break;

		case FsType::FT_I_3:
			delete m_i3;
			break;

		case FsType::FT_I_4:
			delete m_i4;
			break;



		case FsType::FT_COLOR_3:
			delete m_c3;
			break;

		case FsType::FT_COLOR_4:
			delete m_c4;
			break;

		case FsType::FT_MAT4:
			delete m_mat4;
			break;

		case FsType::FT_CHARS:
			delete m_chars;
			break;

		case FsType::FT_OBJECT:
		case FsType::FT_ARRAY:
		case FsType::FT_DICT:
		case FsType::FT_STRING:
			m_object->decRef();
			break;
		default:
			break;
	}

}










NS_FS_END 




