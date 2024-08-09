#include "Data.hpp"

Data(){}

Data(int d):data(d){}

~Data(){}

Data(const Data& other):data(other.data){}

Data& operator=(const Data& other){
	if (this == &other)
		return *this;
	data = other.data;
	return *this;
}
