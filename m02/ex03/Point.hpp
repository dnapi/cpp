/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:52 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:53 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		~Point();
		
		Point &operator=(const Point &other);

		Fixed getX(void) const;
		Fixed getY(void) const;
	
	private:
		const Fixed x;
		const Fixed y;
};
