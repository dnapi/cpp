#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		virtual	~Dog();
		Dog &operator=(const Dog&);
		void	makeSound() const;
};
