/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:07:37 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/28 12:13:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		// constructors
		Fixed();
		Fixed(Fixed const &number);

		//destructors
		~Fixed();

		//operators
		Fixed	&operator=(const Fixed &number);

		//setter
		void	setRawBits(int const raw);

		//getter
		int		getRawBits(void) const;


	private:
		int			_value;
		static const int	_fract_bits;
};

#endif
