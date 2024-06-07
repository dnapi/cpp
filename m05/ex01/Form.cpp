/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:15:26 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:15:28 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("AbraCadabra"), _is_signed(false), _grade_to_sign(1), _grade_to_exec(1) {
	//std::cout << "Form: Default constructor call for " << *this << "\n";
	std::cout << "Form: Constructor call with name=" <<_name 
		<< " for grades " << _grade_to_sign << "&" << _grade_to_exec << "\n";
}

Form::~Form() {
	std::cout << "Form: Destructor call for name=" << _name << "\n";
}

Form::Form(std::string name, int sign, int exec):
	_name(name),
	_is_signed(false),
	_grade_to_sign(sign), 
	_grade_to_exec(exec)
{
	std::cout << "Form: Constructor call with name=" <<_name 
		<< " for grades " << sign << "&" << exec << "\n";
	checkGrade(sign);
	checkGrade(exec);
}

Form::Form(const Form& other):
	_name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec)
{
	std::cout << "Form: Copy constructor call with name=" <<_name << "\n";
}

Form& Form::operator=(const Form& other){
	std::cout << "Form: operator= call for name=" <<_name << "\n";
	if (this != &other)
		_is_signed = other._is_signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Form& form){
	os << " ---------  Form --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}

std::string Form::getName(){
	return _name;
}

bool Form::getIsSigned(){
	return _is_signed;
}

int Form::getGradeToSign(){
	return _grade_to_sign;
}

int Form::getGradeToExec(){
	return _grade_to_exec;
}

void Form::checkGrade(int new_grade){
	if (new_grade > 150)
		throw GradeTooLowException();
	else if (new_grade < 1)
		throw GradeTooHighException();
}

void Form::beSigned(Bureaucrat& bura){
	if (bura.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Form: Exception: Grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Form: Exception: Grade is too low";
}
