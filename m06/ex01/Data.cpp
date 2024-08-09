#include "Data.hpp"

Data::Data(){}

Data::Data(int d):data(d){}

Data::~Data(){}

Data::Data(const Data& other):data(other.data){}

Data& Data::operator=(const Data& other){
	if (this == &other)
		return *this;
	data = other.data;
	return *this;
}
