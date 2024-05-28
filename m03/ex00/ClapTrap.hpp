#pragma once

#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string);
		ClapTrap(ClapTrap &);
		ClapTrap &operator=(ClapTrap &);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	_name;
		unsigned int _hit;
		unsigned int _energy;
		unsigned int _damage;
};
