#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default contructor is called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Default destructor is called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other): type(other.type)
{
	std::cout << "WrongAnimal: Copy contructor is called\n";
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "C++17 Standard WrongAnimal sound\n";
}
