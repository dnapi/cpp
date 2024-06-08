#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


//class Bureaucrait;

class ShrubberyCreationForm: public AForm{
	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		void execute(Bureaucrat const& executor) const override;
		AForm* clone() const override;
	private:
		std::string _target;
};
		
//std::ostream& operator<<(std::ostream&, ShrubberyCreationForm&);
