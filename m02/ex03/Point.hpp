#pragma once

#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		~Point();
		
		Point &operator=(const Point &other);
		const Fixed &getX(void);
		const Fixed &getY(void);
	
	private:
		const Fixed x;
		const Fixed y;
};
