/*************************************************************************/
/*  FsVertexBuffer.h                                                     */
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


#ifndef _FS_VERTEX_BUFFER_H_
#define _FS_VERTEX_BUFFER_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"

NS_FS_BEGIN

class RenderDevice;

class VertexBuffer:public FsObject
{
	public:
		enum {
			TARGET_ARRAY,
			TARGET_ELEMENT,
		};

		enum {
			USAGE_STATIC,
			USAGE_DYNAMIC,
			USAGE_STREAM,
		};

	public:
		const char* className();

	public:
		void setDirty(bool value){m_dirty=value;}
		bool getDirty(){return m_dirty;}

		void setCacheInGpu(int target,int usage){
			m_target=target;
			m_usage=usage;
			m_dirty=true;
			m_cacheInGpu=true;
		}

		void cancelCacheInGpu(){ m_cacheInGpu=false;}

		bool getCacheInGpu(){return m_cacheInGpu;}

	public:
		virtual void* getBufferData()=0;
		virtual int getItemNu()=0;
		virtual void setItemNu(int nu)=0;
		virtual int getItemSize()=0;

	protected:
		VertexBuffer();
		virtual ~VertexBuffer();

		void updateBufferInGpu();


	protected:
		bool m_cacheInGpu;

		int m_target;
		int m_usage;
		int m_gpuVBO;

		bool m_dirty;

		friend RenderDevice;
};



template <typename T>
class TVertexBuffer:public VertexBuffer
{

	public:
		static TVertexBuffer<T>* create();
		static TVertexBuffer<T>* create(int size);

	public:
		/* override VertexBuffer */
		virtual void* getBufferData(){ return &m_buffer[0]; }
		virtual int getItemNu(){return m_buffer.size();}
		virtual void setItemNu(int size){ m_buffer.resize(size);m_dirty=true;}
		virtual int getItemSize(){return sizeof(T);}

	public:
		T& get(int index) { return m_buffer[index]; }
		void set(int index,const T& v){ m_buffer[index]=v;m_dirty=true;}
		void setQuick(int index,const T& v){ m_buffer[index]=v;}
		void append(const T& v){m_buffer.push_back(v);m_dirty=true;}
		void appendQuick(const T& v){m_buffer.push_back(v);}


	protected:
		TVertexBuffer();
		virtual ~TVertexBuffer();

	protected:
		std::vector<T> m_buffer;
};

#include "FsVertexBuffer.inl"


typedef TVertexBuffer<Vector4f> VertexBuffer4f;
typedef TVertexBuffer<Vector3f> VertexBuffer3f;
typedef TVertexBuffer<Vector2f> VertexBuffer2f;
typedef TVertexBuffer<float> VertexBufferf;

typedef TVertexBuffer<Vector4i>  VertexBuffer4i;
typedef TVertexBuffer<Vector3i>  VertexBuffer3i;
typedef TVertexBuffer<Vector2i>  VertexBuffer2i;
typedef TVertexBuffer<int32_t>   VertexBufferi;

typedef TVertexBuffer<Vector4ui>  VertexBuffer4ui;
typedef TVertexBuffer<Vector3ui>  VertexBuffer3ui;
typedef TVertexBuffer<Vector2ui>  VertexBuffer2ui;
typedef TVertexBuffer<uint32_t>   VertexBufferui;



NS_FS_END


#endif /*_FS_VERTEX_BUFFER_H_*/

