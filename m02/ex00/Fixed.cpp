#include <iostream>
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
};

~Fixed::Fixed(){};

Fixed::Fixed(Fixed const &number)
{
	std::cout << "Copy constructor called\n";
	_int = number->getRawBits();
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void)
{
	return (_value);
}

Fixed	&Fixed::operator=(const Fixed &number)
{
	if (this != &number)
		_value = number->_value;
	return (*this);
}
