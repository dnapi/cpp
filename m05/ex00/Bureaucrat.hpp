/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:14:43 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:14:45 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(std::string, const int&);
		Bureaucrat& operator=(const Bureaucrat&);
		const std::string getName();
		int getGrade();
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
		void	applyNewGrade(int new_grade);
	private:
		const std::string	_name;
		int	_grade;
};
		

std::ostream& operator<<(std::ostream&, Bureaucrat&);
