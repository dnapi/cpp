#pragma once

#include <iostream>

class Animal
{
	public:
		virtual	~Animal();
		std::string getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string type;
		Animal();
		Animal(const Animal&);
		Animal &operator=(const Animal&);
};
