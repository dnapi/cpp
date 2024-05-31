#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		virtual	~Dog();
		Dog &operator=(const Dog&);
		void	makeSound() const;
    private:
        Brain* brain;
};
