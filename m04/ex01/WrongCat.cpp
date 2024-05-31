#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat: Default contructor is called\n";
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor is called\n";
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other)
{
	std::cout << "WrongCat: Copy contructor is called\n";
	type = "WrongCat";
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miiiiaaauu\n";
}
