/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:59 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
