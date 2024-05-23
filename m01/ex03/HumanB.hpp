#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void attack(void) const;
	private:
		std::string	name;
		Weapon		*weapon;
};
