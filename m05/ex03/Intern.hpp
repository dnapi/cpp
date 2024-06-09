/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:09:54 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/09 11:09:56 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern(std::string, const int&);
		Intern& operator=(const Intern&);
		AForm* makeForm(std::string, std::string);
	private:
		AForm* _drafts[4];
};
		

//std::ostream& operator<<(std::ostream&, Intern&);
