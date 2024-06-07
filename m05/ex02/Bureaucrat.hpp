#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(std::string, const int&);
		Bureaucrat& operator=(const Bureaucrat&);
		const std::string getName();
		int getGrade() const;
		void increment();
		void decrement();
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		void signForm(AForm&);
		void executeForm(AForm const&);
	private:
		const std::string	_name;
		int	_grade;
		void applyNewGrade(int new_grade);
};
		

std::ostream& operator<<(std::ostream&, Bureaucrat&);
