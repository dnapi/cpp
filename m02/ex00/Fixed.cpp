/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:07:29 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:07:34 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_value = 0;
};

Fixed::~Fixed()
{
	_value = 0;
	std::cout << "Destructor called\n";
};

Fixed::Fixed(Fixed const &number)
{
	std::cout << "Copy constructor called\n";
	_value = number.getRawBits();
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_value);
}

Fixed	&Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &number)
		_value = number.getRawBits();
	return (*this);
}
