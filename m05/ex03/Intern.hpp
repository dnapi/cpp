#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern(std::string, const int&);
		Intern& operator=(const Intern&);
		AForm* makeForm(std::string, std::string);
	private:
		AForm* _drafts[4];
};
		

//std::ostream& operator<<(std::ostream&, Intern&);
