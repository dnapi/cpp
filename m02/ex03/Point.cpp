#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){}

Point::~Point(){}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)){}
	
Point::Point(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}


const Fixed &Fixed::getX(void)
{
	return (this->x);
}

const Fixed &Fixed::getY(void)
{
	return (this->y);
}
