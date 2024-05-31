#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		virtual	~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};
