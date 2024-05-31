#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default contructor is called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor is called\n";
	delete brain;
}

Cat::Cat(Cat const &other): Animal(other)
{
	std::cout << "Cat: Copy contructor is called\n";
	type = "Cat";
	brain = new Brain(*other.brain);
}

Cat & Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Operator = is called\n";
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miiiiaaauu\n";
}
