#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5) {
	std::cout << "PresidentialPardonForm: Default Constructor called\n";
   _target = "default";	
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm: Constructor call with target: " 
		<< _target << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other),
	_target(other._target)
{
	std::cout << "PresidentialPardonForm: Copy constructor called for target: " 
		<<_target << "\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	std::cout << "PresidentialPardonForm: operator= call for name=" << getName() << "\n";
	(void)other;
//	if (this != &other)
//		_is_signed = other._is_signed;
	std::cout
	    << "#################################################################################\n"
		<< "#  Note that coping of signature is not legal in Finland.                       #\n" 
		<< "#  The legislation that addresses forgery, including the forgery of signatures, #\n"
		<< "#  is primarily found in the Penal Code (Rikoslaki).                            #\n" 
		<< "#  Specifically, Chapter 33 of the Penal Code.                                  #\n"
	    << "#################################################################################\n";
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	beExecuted(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

/*
 std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& form){
	os << " ---------  PresidentialPardonForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}
*/
