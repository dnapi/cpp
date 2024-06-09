/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:10:15 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/09 11:23:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request", 72, 45) {
	std::cout << "RobotomyRequestForm: Default Constructor called\n";
   _target = "default";	
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: Destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("robotomy request", 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm: Constructor call with target: " 
		<< _target << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other)
{
	_target = other._target;
	std::cout << "RobotomyRequestForm: Copy constructor called for target: " 
		<<_target << "\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	std::cout << "RobotomyRequestForm: operator= call for name=" << getName() << "\n";
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

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
	beExecuted(executor);
	std::cout << "Making some grilling noices\n";
	for (int i = 0; i < 20; ++i){
		std::cout << '\a';
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if (i % 5 == 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if (i % 7 == 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	srand(time(NULL));
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized (50\% chance)" << std::endl;
	else
		std::cout << "Robotomization of " << getTarget() << " failed (50\% chance)" << std::endl;

}

AForm* RobotomyRequestForm::clone() const{
        AForm* p = new RobotomyRequestForm(*this);
        return p;
}

/*
 std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& form){
	os << " ---------  RobotomyRequestForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}
*/
