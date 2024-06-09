/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:09:32 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/09 11:09:35 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm&);
		AForm(std::string, int, int);
		AForm& operator=(const AForm&);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		std::string getTarget() const;
		void setTarget(std::string);
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
		void beSigned(Bureaucrat&);
		void beExecuted(const Bureaucrat&) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual AForm* clone() const = 0;
		void checkGrade(int);
	protected:
		std::string _target;
	private:
		const std::string	_name;
		bool			_is_signed;
		const int		_grade_to_sign;
		const int		_grade_to_exec;
};
		

std::ostream& operator<<(std::ostream&, AForm&);
