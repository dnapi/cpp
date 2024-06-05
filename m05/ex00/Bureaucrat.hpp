#pragma once

#include <string>
#include <iostream>

class Bureaucrat{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		const std::string getName();
		int getGrade();
		void increment();
		void decrement();
	private:
		const std::string	_name;
		int	_grade;
};
		

std::ostream& operator<<(std::ostream&, Bureaucrat&);
