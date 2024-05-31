#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default contructor is called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor is called\n";
	delete brain;
}

Dog::Dog(Dog const &other): Animal(other)
{
	std::cout << "Dog: Copy contructor is called\n";
	type = "Dog";
	brain = new Brain(*other.brain);
}

Dog & Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Operator = is called\n";
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Hi! I am Dog. My brain is at " << brain << std::endl;
}
