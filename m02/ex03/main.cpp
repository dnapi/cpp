/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:43 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:44 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

int	main(void)
{
	Point a{0.0,0.0};
	Point b{1.0,0.0};
	Point c{0.0,1.0};
	Point p1{0.1,0.1};
	Point p2{0.5,0.5};
	Point p3{0.5,0.6};
	
	std::cout << bsp(a,b,c,p1) << std::endl;
	std::cout << bsp(a,b,c,p2) << std::endl;
	std::cout << bsp(a,b,c,p3) << std::endl;
	std::cout << bsp(a,b,c,a) << std::endl;

	return 0;
}
