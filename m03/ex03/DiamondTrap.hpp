#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(FragTrap&);
		~FragTrap();

		FragTrap &operator=(FragTrap&);
		
		void attack(const std::string&);
		void highFivesGuys(void);
	private:
		std::string _name;
};
