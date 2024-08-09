#include "Serializer.hpp"

Serializer(){}

~Serializer(){}

Serializer(const Serializer&){}

Serializer& operator=(const Serializer& other){
	return *this;
}

uintptr_r serialize(Data* ptr){
	return reinterpret_cast<uintptr_r>(ptr);
}

Data* deserialize(uintptr_r raw){
	return reinterpret_cast<Data*>(raw);
}
#endif
