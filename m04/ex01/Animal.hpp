#pragma once

#include <iostream>

class Animal
{
	public:
		Animal();
//		Animal(const std::string);
		Animal(const Animal&);
		virtual	~Animal();
		Animal &operator=(const Animal&);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};
