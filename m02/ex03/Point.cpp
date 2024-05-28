//#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){}

Point::~Point(){}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)){}
	
Point::Point(const Point &p): x(p.x), y(p.y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}


Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
