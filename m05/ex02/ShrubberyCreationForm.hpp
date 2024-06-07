/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:17:05 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:17:07 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	private:
		std::string _target;
};
		
//std::ostream& operator<<(std::ostream&, ShrubberyCreationForm&);
