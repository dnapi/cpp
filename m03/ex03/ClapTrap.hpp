#pragma once

#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string);
		ClapTrap(ClapTrap &);
		ClapTrap &operator=(const ClapTrap &);

		virtual	void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		unsigned int _hit;
		unsigned int _energy;
		unsigned int _damage;
};
