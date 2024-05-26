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

Fixed::Fixed(int &number)
{
	_value = number << fract_bits;
}

Fixed::Fixed(float &number)
{
	_value = roundf(number * (1 << _fract_bits));
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

std::ostream &operator<<(std::ostream &os, Fixed &number)
{
	os << "Printing Fixed point number to be implimented.\n";
	return (os);
}

float	Fixed::toFloat(void) const
{
	float factor = (1 << _fract_bits);
	float number = this->getRawBits() / factor;
	return (number);
}

int	toInt(vois) const
{
	int	number = this->getRawBits() >> _fract_bits;
	return (number);

}
