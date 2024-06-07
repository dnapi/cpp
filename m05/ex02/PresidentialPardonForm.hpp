/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:16:52 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:16:54 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	private:
		std::string _target;
};
		
//std::ostream& operator<<(std::ostream&, PresidentialPardonForm&);
