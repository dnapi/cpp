/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:01:36 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:01:38 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default contructor is called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor is called\n";
	delete brain;
}

Cat::Cat(Cat const &other): Animal(other)
{
	std::cout << "Cat: Copy contructor is called\n";
	type = "Cat";
	brain = new Brain(*other.brain);
}

Cat & Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Operator = is called\n";
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Hi! I am Cat. My brain is at " << brain << std::endl;
}
