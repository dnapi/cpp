#include "Array.hpp"

template<typename T>
Array<T>::Array():_size(0){ // _array(nullptr) 
	_array = new T[0];
}
Array<T>::Array() : _size(0), _array(nullptr) {}

template<typename T>
Array<T>::Array(unsigned int i):_size(i){
	_array = new T[_size];
}

template<typename T>
Array<T>::~Array(){
	delete[] _array;
}


template<typename T>
Array<T>::Array(const Array<T>& other):_size(other.size()){
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++){
		_array[i] = other[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if (this == *other)
		return this;
	delete[] _array;
	_size = other.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++){
		_array[i] = other[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](int i) const{
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
