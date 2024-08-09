#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include "Data.hpp"

class Serializer{
	public:
		static uintptr_r serialize(Data* ptr);
		static Data* deserialize(uintptr_r raw);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
};
#endif
