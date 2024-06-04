/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:17 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:18 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
	std::cout << "Ice: Default constructor is called\n";
	type = "ice";
}

Ice::~Ice(){
	std::cout  << "Ice: Destructor is called\n";
}

Ice::Ice(const Ice& other): AMateria(){
	(void)other;
	type = "ice";
	std::cout << "Ice: Copy constructor for type " 
		<< type << " is called\n";
}

Ice& Ice::operator=(const Ice& other){
	std::cout << "Ice: operator = for type " << type << " is called\n";
	(void)other;
	return (*this);
}

Ice* Ice::clone() const{
	std::cout << "Ice: clone for type " << type << " is called\n";
	Ice* i = new Ice();
	return i;
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " 
		<< target.getName() << " *\n";
}