#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
		Form();
		~Form();
		Form(const Form&);
		Form(std::string, int, int);
		Form& operator=(const Form&);
		std::string getName();
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExec();
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		void beSigned(Bureaucrat&);
	private:
		const std::string	_name;
		bool			_is_signed;
		const int		_grade_to_sign;
		const int		_grade_to_exec;
		void checkGrade(int);
};
		

std::ostream& operator<<(std::ostream&, Form&);
