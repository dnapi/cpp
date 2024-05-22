#pragma once
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(str::string name, Weapon weapon);
		void attack(void) const;
	private:
		str::string	name;
		Weapon		weapon;
}
