/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:06:13 by string            #+#    #+#             */
/*   Updated: 2024/06/09 11:09:53 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called\n";
	_drafts[0] = new ShrubberyCreationForm();
	_drafts[1] = new RobotomyRequestForm();
	_drafts[2] = new PresidentialPardonForm();
	_drafts[3] = nullptr;
}

Intern::~Intern() {
	std::cout << "Intern: Destructor called\n";
	for (int i = 0; i < 4;++i){
		delete _drafts[i];
	}
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called\n";
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: operator= called\n";
	(void)other;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Intern& brc) {
	os << "Intern:  I have no grade, no name, but superpower to make forms\n";
	(void)brc;
	return os;
}

/*
The makeForm() function should use some kind of array of pointers to member
functions to handle the creation of Forms.
If it's using an unclean method, like if/elseif/elseif/else branchings, or
some other ugly stuff like this, please count this as wrong.
*/

AForm* Intern::makeForm(std::string form_name, std::string target){
	int i = -1;
	while (++i < 3 && _drafts[i]->getName() != form_name)
		;
	AForm* pnt  = nullptr;
	if (_drafts[i])
	{
		pnt = _drafts[i]->clone();
		pnt->setTarget(target);
		std::cout << "Intern creates " << form_name <<"\n";
	}
	else 
		std::cout << "Intern: Error form" << form_name	<< " does not exist\n";
	return pnt;
}



