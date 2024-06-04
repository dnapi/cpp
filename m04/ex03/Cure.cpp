/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:58:41 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:58:42 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
	std::cout << "Cure: Default constructor is called\n";
	type = "cure";
}

Cure::~Cure(){
	std::cout  << "Cure: Destructor is called\n";
}

Cure::Cure(const Cure& other): AMateria(){
	(void)other;
	type = "cure";
	std::cout << "Cure: Copy constructor for type " 
		<< type << " is called\n";
}

Cure& Cure::operator=(const Cure& other){
	std::cout << "Cure: operator = for type " << type << " is called\n";
	(void)other;
	return (*this);
}

Cure* Cure::clone() const{
	std::cout << "Cure: clone for type " << type << " is called\n";
	Cure* i = new Cure();
	return i;
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " 
		<< target.getName() 
		<< "’s wounds *\n";
}

/*
std::string const & Cure::getType() const {
	std::cout << "Cure: getter for type " << type << " is called\n";
	return (type);
}
*/

/*
Cure::Cure(std::string const& type_arg): type(type_arg){
	std::cout << "Cure: constructor from string for type " 
		<< type << " is called\n";
}
*/
