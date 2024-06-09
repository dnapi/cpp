/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:10:29 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/09 11:24:27 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137) {
	std::cout << "ShrubberyCreationForm: Default Constructor called\n";
   _target = "default";	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("shrubbery creation", 145, 137)
	//,_target(target)
{
	_target = target;
	std::cout << "ShrubberyCreationForm: Constructor call with target: " 
		<< _target << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other)
//	,_target(other._target)
{
	_target = other._target;
	std::cout << "ShrubberyCreationForm: Copy constructor called for target: " 
		<< getTarget() << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	std::cout << "ShrubberyCreationForm: operator= call for name=" << getName() << "\n";
	//(void)other;
	_target = other._target;
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

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	beExecuted(executor);
	std::string ofile_name = _target + "_shrubbery";
	std::ofstream ofs(ofile_name, std::ofstream::app);
	ofs.exceptions(std::ofstream::failbit | std::ofstream::badbit);
/*	if (!ofs) 
	{
	    std::cout << "Could not open the file for writing: " 
		<< ofile_name << std::endl;
	    return ;
	}	
*/
	std::string str = 
    "        _-_\n"
    "     /~~   ~~\\\n"
    "  /~~         ~~\\\n"
    " {               }\n"
    "  \\  _-     -_  /\n"
    "    ~  \\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\n";
	ofs << str;
	ofs.close();
}

AForm* ShrubberyCreationForm::clone() const{
	AForm* p = new ShrubberyCreationForm(*this);
	return p;
}

/*
 std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& form){
	os << " ---------  ShrubberyCreationForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< "    target: " << form.getTarget() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}
*/