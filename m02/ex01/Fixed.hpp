#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

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
		std::ostream	&operator<<(std::ostream &os, const Fixed &number);

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

#endif
