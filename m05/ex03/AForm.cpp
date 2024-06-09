/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:54:33 by alex              #+#    #+#             */
/*   Updated: 2024/06/09 11:08:23 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	_target("None"),
	_name("AbraCadabra"),
	_is_signed(false),
	_grade_to_sign(1),
	_grade_to_exec(1) {
	std::cout << "AForm: Constructor call with name=" <<_name 
		<< " for grades " << _grade_to_sign << "&" << _grade_to_exec << "\n";
}

AForm::~AForm() {
	std::cout << "AForm: Destructor call for name=" << _name << "\n";
}

AForm::AForm(std::string name, int sign, int exec):
	_target("None"),
	_name(name),
	_is_signed(false),
	_grade_to_sign(sign), 
	_grade_to_exec(exec) {
	std::cout << "AForm: Constructor call with name=" <<_name 
		<< " for grades " << sign << "&" << exec << "\n";
	checkGrade(sign);
	checkGrade(exec);
}

AForm::AForm(const AForm& other):
	_target(other._target),
	_name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec)
{
	std::cout << "AForm: Copy constructor call with name=" <<_name << "\n";
}

AForm& AForm::operator=(const AForm& other){
	std::cout << "AForm: operator= call for name=" <<_name << "\n";
	if (this != &other)
	{
		_is_signed = other._is_signed;
		_target = other._target;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, AForm& form){
	os << " ---------  AForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< "    target: " << form.getTarget() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getGradeToSign() const {
	return _grade_to_sign;
}

int AForm::getGradeToExec() const {
	return _grade_to_exec;
}

std::string AForm::getTarget() const {
	return _target;
}

void AForm::setTarget(std::string target){
	_target = target;
}

void AForm::checkGrade(int new_grade){
	if (new_grade > 150)
		throw GradeTooLowException();
	else if (new_grade < 1)
		throw GradeTooHighException();
}

void AForm::beSigned(Bureaucrat& bura){
	if (bura.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

void AForm::beExecuted(const Bureaucrat& bura) const {
	if (bura.getGrade() > _grade_to_exec)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "AForm: Exception: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "AForm: Exception: Grade is too low";
}
