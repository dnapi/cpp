#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		virtual	~WrongCat();
		WrongCat &operator=(const WrongCat&);
		void	makeSound() const;
};
