#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


//class Bureaucrait;

class PresidentialPardonForm: public AForm{
	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		void execute(Bureaucrat const& executor) const override;
		AForm* clone() const override;
	private:
		std::string _target;
};
		
//std::ostream& operator<<(std::ostream&, PresidentialPardonForm&);
