#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(FragTrap&);
		~FragTrap();

		FragTrap &operator=(FragTrap&);
		
		void attack(const std::string&);
		void highFivesGuys(void);
};