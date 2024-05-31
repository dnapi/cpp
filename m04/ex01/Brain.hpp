#pragma once
#include <iostream>

class Brain{
	public:
		Brain();
		~Brain();
		Brain(Brain&);
		Brain& operator=(Brain& other);
	private:
		std::string	ideas[100];
};
