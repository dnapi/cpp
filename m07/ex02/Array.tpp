#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _array(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int i):_size(i){
	if (i > 0)
		_array = new T[_size];
	else
		_array = nullptr;
}

template<typename T>
Array<T>::~Array(){
	delete[] _array;
}


template<typename T>
Array<T>::Array(const Array<T>& other):_size(other.size()){
	if (_size > 0){
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++){
			_array[i] = other[i];
		}
	}
	else 
		_array = nullptr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) & {
	if (this == *other)
		return *this;
	delete[] _array;
	_size = other.size();
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++){
			_array[i] = other[i];
		}
	}
	else 
		_array = nullptr;
	return *this;
}

template<typename T>
T& Array<T>::operator[](int i){
	if (i < 0)
		throw std::exception();
	if (_size <= static_cast<unsigned int>(i))
		throw std::exception();
	return _array[i];
}

template<typename T>
const T& Array<T>::operator[](int i) const{
	if (i < 0)
		throw std::exception();
	if (_size <= static_cast<unsigned int>(i))
		throw std::exception();
	return _array[i];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif