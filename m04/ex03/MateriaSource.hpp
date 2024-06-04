#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria* _invent[4];
  	public:
	    MateriaSource();
	    ~MateriaSource();
    	MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
