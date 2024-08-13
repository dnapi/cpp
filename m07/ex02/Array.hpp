#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array{
	public:
		Array();
		Array(unsigned int);
		~Array();
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&) &;
		const T& operator[](int) const;
		T& operator[](int);
		unsigned int size() const;
	private:
		T*	_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
