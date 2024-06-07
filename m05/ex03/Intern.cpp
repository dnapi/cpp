#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called\n";
}

Intern::~Intern() {
	std::cout << "Intern: Destructor called\n";
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called\n";
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: operator= called\n";
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Intern& brc) {
	os << "Intern:  I have no grade, no name, but superpower to make forms\n";
	return os;
}

AForm* Intern::makeForm(std::string form_name, std::string target){
	AForm *pnt;
	switch (form_name){
	case "shrubbery creation":
		pnt = new ShrubberyCreationForm(target);
		break ;
	case "robotomy request":
		pnt = new RobotomyRequestForm(target);
		break ;
	case "presidential pardon":
		pnt = new PresidentialPardonForm(target);
		break ;
	default:
		pnt = nullptr;
	}
	if (pnt)
		std::cout << "Intern creates " << form_name <<"\n";
	else 
		std::cout << "Intern: Error - form named " << form_name	<< " does not exist\n";
	return pnt;
}



