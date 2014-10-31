

template<typename T>
inline TVertexBuffer<T>* TVertexBuffer<T>::create()
{
	return new TVertexBuffer<T>;
}

template<typename T>
inline TVertexBuffer<T>* TVertexBuffer<T>::create(int size)
{
	TVertexBuffer<T>* ret=new TVertexBuffer<T>;
	ret->setItemNu(size);
	return ret;
}

template<typename T>
inline TVertexBuffer<T>::TVertexBuffer(){}

template<typename T>
inline TVertexBuffer<T>::~TVertexBuffer(){}











