/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:57:29 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:52 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria: Default constructor is called\n";
	type = "undef-type";
}

AMateria::~AMateria(){
	std::cout  << "AMateria: Destructor is called\n";
}

AMateria::AMateria(const AMateria& other): type(other.type){
	std::cout << "AMateria: Copy constructor for type " 
		<< type << " is called\n";
}

AMateria::AMateria(std::string const& type_arg): type(type_arg){
	std::cout << "AMateria: constructor from string for type " 
		<< type << " is called\n";
}

AMateria& AMateria::operator=(const AMateria& other){
	std::cout << "AMateria: operator = for type " << type << " is called\n";
	(void)other;
	return (*this);
}

std::string const & AMateria::getType() const {
//	std::cout << "AMateria: " << type << " is called\n";
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria: AMateria is used for character " 
		<< target.getName() << std::endl;
}
