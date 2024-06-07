#pragma once

#include "AForm.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern(std::string, const int&);
		Intern& operator=(const Intern&);
		AForm* makeForm(std::string, std::string);
};
		

//std::ostream& operator<<(std::ostream&, Intern&);
