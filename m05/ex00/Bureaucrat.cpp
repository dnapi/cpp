#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default-name"), _grade(1) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
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

int Bureaucrat::getGrade(){
	return _grade;
}

void Bureaucrat::increment(){
	--_grade;
}

void Bureaucrat::decrement(){
	++grade;
}

