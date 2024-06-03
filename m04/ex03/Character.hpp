#pragma once

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
  protected:
	AMateria* _invent[4];
	std::string	_name;
  public:
    Character();
    ~Character();
    Character(const Character&);
    Character(std::string name);
    Character& operator=(const Character& other);
    std::string const & getName() const;
    void equip(AMateria* m);
	  void unequip(int idx); 
	  void use(int idx, ICharacter& target);
};