#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		virtual	~Cat();
		Cat &operator=(const Cat&);
		void	makeSound() const;
	private:
		Brain* brain;
};
