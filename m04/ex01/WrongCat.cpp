/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:15 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:17 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat: Default contructor is called\n";
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor is called\n";
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other)
{
	std::cout << "WrongCat: Copy contructor is called\n";
	type = "WrongCat";
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat: Operator = is called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miiiiaaauu\n";
}
