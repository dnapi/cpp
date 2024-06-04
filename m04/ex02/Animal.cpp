/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:33 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:34 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal: Default contructor is called\n";
}

Animal::~Animal()
{
	std::cout << "Animal: Default destructor is called\n";
}

Animal::Animal(Animal const &other): type(other.type)
{
	std::cout << "Animal: Copy contructor is called\n";
}

Animal & Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

/*
void Animal::makeSound() const
{
	std::cout << "C++17 Standard Animal sound\n";
}
*/
