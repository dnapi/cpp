/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:11 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:12 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed()
{
//	std::cout << "Default constructor called\n";
	_value = 0;
};

Fixed::~Fixed()
{
	_value = 0;
//	std::cout << "Destructor called\n";
};

Fixed::Fixed(Fixed const &number)
{
//	std::cout << "Copy constructor called\n";
	_value = number.getRawBits();
}

Fixed::Fixed(const int &number)
{
//	std::cout << "Int constructor called\n";
	_value = number << _fract_bits;
}

Fixed::Fixed(const float &number)
{
//	std::cout << "Float constructor called\n";
	_value = roundf(number * (1 << _fract_bits));
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called\n";
	return (_value);
}

Fixed	&Fixed::operator=(const Fixed &number)
{
//	std::cout << "Copy assignment operator called\n";
	if (this != &number)
		_value = number.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	(void)number;
	os << number.toFloat();
	return (os);
}

// binary math operations

Fixed	Fixed::operator*(const Fixed & number)
{
	return (Fixed(this->toFloat() * number.toFloat()));
}

Fixed	Fixed::operator/(const Fixed & number)
{
	return (Fixed(this->toFloat() / number.toFloat()));
}


Fixed	Fixed::operator+(const Fixed & number)
{
	return (Fixed(this->toFloat() + number.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & number)
{
	return (Fixed(this->toFloat() - number.toFloat()));
}

// logic functions
bool	Fixed::operator<(const Fixed & number) const
{
	return (_value < number._value);
}

bool	Fixed::operator>(const Fixed & number) const
{
	return (_value > number._value);
}

bool	Fixed::operator<=(const Fixed & number) const
{
	return (_value <= number._value);
}

bool	Fixed::operator>=(const Fixed & number) const
{
	return (_value >= number._value);
}

bool	Fixed::operator==(const Fixed & number) const
{
	return (_value == number._value);
}

bool	Fixed::operator!=(const Fixed & number) const
{
	return (_value != number._value);
}

// decrement and increment
Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result = Fixed(*this);
	++*this;
	return (result);
}


Fixed Fixed::operator--(int)
{
	Fixed result = Fixed(*this);
	--*this;
	return (result);
}

// Helper functions

float	Fixed::toFloat(void) const
{
	float factor = (1 << _fract_bits);
	float number = this->getRawBits() / factor;
	return (number);
}

int	Fixed::toInt(void) const
{
	int	number = this->getRawBits() >> _fract_bits;
	return (number);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}


/*
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}
*/
