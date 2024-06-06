#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("AbraCadabra", 145, 137) {
	std::cout << "ShrubberyCreationForm: Default Constructor called\n";
   _target = "Harry Potter";	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm: Constructor call with target" << _target << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called for target=" <<_target << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	std::cout << "ShrubberyCreationForm: operator= call for name=" <<_name << "\n";
	if (this != &other)
		_is_signed = other._is_signed;
	return (*this);
}

/*
 std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& form){
	os << " ---------  ShrubberyCreationForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}
*/
