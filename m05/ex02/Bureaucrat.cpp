/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:16:39 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:16:41 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Chupacabra"), _grade(1) {
	std::cout << "Bureaucrat: Default constructor call for " << *this << "\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor call for " << *this << "\n";
}

Bureaucrat::Bureaucrat(std::string name, const int& i): _name(name){
	std::cout << "Bureaucrat: Constructor call with name=" <<_name 
		<<" and grade=" << i << "\n";
	applyNewGrade(i);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){
	std::cout << "Bureaucrat: Copy constructor call for " << *this << "\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	std::cout << "Bureaucrat: Operator= call for " << *this << "\n";
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& brc){
	os << brc.getName() 
		<< ", bureaucrat grade " << brc.getGrade();
	return os;
}

const std::string Bureaucrat::getName(){
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::applyNewGrade(int new_grade){
	std::cout << "Bureaucrat: applyNewGrade called to check grade\n";
	if (new_grade > 150)
		throw GradeTooLowException();
	else if (new_grade < 1)
		throw GradeTooHighException();
	else
		_grade = new_grade;
}

void Bureaucrat::increment(){
	std::cout << "Bureaucrat: increment call for " << *this << "\n";
	applyNewGrade(_grade - 1);
}


void Bureaucrat::decrement(){
	std::cout << "Bureaucrat: decrement call for " << *this << "\n";
	applyNewGrade(_grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Bureaucrat: Exception: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Bureaucrat: Exception: Grade is too low";
}

void Bureaucrat::signForm(AForm& form){
	if (!form.getIsSigned()){
		try{
			form.beSigned(*this);
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
		catch(AForm::GradeTooLowException& e){
			std::cout << _name << " couldn’t sign " << form.getName() 
				<< " because" << " Grade too low" << std::endl;
		}
	}
	else {
		std::cout << _name << " couldn’t sign " << form.getName() << 
			" because" << " AForm allready signed" << std::endl;
	}
	return;
}


void Bureaucrat::executeForm(AForm const& form){
	if (form.getIsSigned()) {
		try{
			form.execute(*this);
			std::cout << _name << " executed " << form.getName() << std::endl;
			return;
		}
		catch(AForm::GradeTooLowException& e) {
			std::cout << _name << " couldn’t execute " << form.getName() 
				<< " because Grade too low" << std::endl;
			return;
		}
		catch (const std::ios_base::failure& e) {
			std::cout << _name << " couldn’t executed " << form.getName() << 
			" because it is not available at this moment" << std::endl;
        	return;
		}
	}
	else {
		std::cout << _name << " couldn’t executed" << form.getName() << 
			" because it is not signed" << std::endl;
	}
	return;
}
