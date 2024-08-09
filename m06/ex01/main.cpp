#include <iostream>
#include "Serializer.hpp"

int main(void){
	Data d(42);

	uintptr_t ptr = Serializer::serialize(&d);
	Data* d_ptr =Serializer::deserialize(ptr);
	std::cout << "data=" << d_ptr->data << "\n";
	return (0);
}