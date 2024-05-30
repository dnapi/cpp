#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		virtual	~Cat();
		Cat &operator=(const Cat&);
		void	makeSound() const;
};
