/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:08:00 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:02 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// constructors
		Fixed();
		Fixed(Fixed const &number);
		Fixed(const int	&number);
		Fixed(const float &number);

		//destructors
		~Fixed();

		//operators
		Fixed	&operator=(const Fixed &number);

		//setter
		void		setRawBits(int const raw);

		//getter
		int	getRawBits(void) const;
		
		// other member functions
		float	toFloat(void) const;
		int	toInt(void) const;


	private:
		int			_value;
		static const int	_fract_bits;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &number);

#endif
