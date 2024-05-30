#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string);
		DiamondTrap(DiamondTrap&);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap&);
		
		using	ScavTrap::attack;
		void whoAmI(void);
	private:
		std::string _name;
};
