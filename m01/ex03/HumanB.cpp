#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(nullptr)
{
}

void	HumanB::attack(void) const
{
	if (!this->weapon)
		return ;
	std::cout << this->name 
		<< " attacks with their "
		<< (*this->weapon).getType()
		<< std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
