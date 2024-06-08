#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


//class Bureaucrait;

class RobotomyRequestForm: public AForm{
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		void execute(Bureaucrat const& executor) const override;
		AForm* clone () const override;
	private:
		std::string _target;
};
		
//std::ostream& operator<<(std::ostream&, RobotomyRequestForm&);
