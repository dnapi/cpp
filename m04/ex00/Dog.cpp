/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:38 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:00:39 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default contructor is called\n";
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor is called\n";
}

Dog::Dog(Dog const &other): Animal(other)
{
	std::cout << "Dog: Copy contructor is called\n";
	type = "Dog";
}

Dog & Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Gaaavvvv\n";
}
