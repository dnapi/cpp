/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:32 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:00:34 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default contructor is called\n";
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor is called\n";
}

Cat::Cat(Cat const &other): Animal(other)
{
	std::cout << "Cat: Copy contructor is called\n";
	type = "Cat";
}

Cat & Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miiiiaaauu\n";
}
