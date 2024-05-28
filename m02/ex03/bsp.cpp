/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:23 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:24 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const &a, Point const &b, Point const &c)
{
	 Fixed area = ((a.getX() * (b.getY() - c.getY()))
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY()))) / Fixed(2);

	return (area > 0 ? area : area * -1);
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, a, b);
	Fixed area2 = area(point, b, c);
	Fixed area3 = area(point, c, a);
	bool isOnEdge = (area1 == 0 || area2 == 0 || area3 == 0);
	return (totalArea == area1 + area2 + area3 && !isOnEdge);
}
