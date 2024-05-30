#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(ScavTrap&);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap&);
		
		void attack(const std::string&);
		void guardGate();
};