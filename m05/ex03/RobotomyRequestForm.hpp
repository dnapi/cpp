/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:10:21 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/09 11:10:25 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
