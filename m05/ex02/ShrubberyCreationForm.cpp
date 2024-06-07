#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137) {
	std::cout << "ShrubberyCreationForm: Default Constructor called\n";
   _target = "default";	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm: Constructor call with target: " 
		<< _target << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called for target: " 
		<<_target << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	std::cout << "ShrubberyCreationForm: operator= call for name=" << getName() << "\n";
	(void)other;
//	if (this != &other)
//		_is_signed = other._is_signed;
	std::cout <<  "Note that coping of signature is not legal in Finland. The legislation that addresses forgery, including the forgery of signatures, is primarily found in the Penal Code (Rikoslaki). Specifically, Chapter 33 of the Penal Code. \n";
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	beExecuted(executor);
	ofile_name = _target + "_shrubbery";
	std::ofstream	ofs(ofile_name);
	if (!ofs) 
	{
	    std::cout << "Could not open the file for writing: " 
		<< ofile_name << std::endl;
	    return (1);
	}	
	std::string str = "\n"
"          _____ _                _     _                     \n "
"         / ____| |              | |   | |                    \n "
"        | (___ | |__  _ __ _   _| |__ | |__   ___ _ __ _   _ \n "
"         \___ \| '_ \| '__| | | | '_ \| '_ \ / _ \ '__| | | |\n "
"         ____) | | | | |  | |_| | |_) | |_) |  __/ |  | |_| |\n"
"        |_____/|_| |_|_|   \__,_|_.__/|_.__/ \___|_|   \__, |\n"
"                                                        __/ |\n"
"                                                       |___/ \n"
"	\n";
	ofs << str;
	ofs.close();
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
