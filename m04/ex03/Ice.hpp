#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice&);
		Ice& operator=(const Ice& other);
		Ice* clone() const override;
};
