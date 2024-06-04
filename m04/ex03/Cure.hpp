#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure& other);
		Cure* clone() const override;
		void use(ICharacter& target) override;
};
