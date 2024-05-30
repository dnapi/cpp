#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " is created" << std::endl;
	_hit = 100;
	_energy = 50;
	 _damage = 20;
}

ScavTrap::ScavTrap() : ClapTrap("defaultname") 
{
	std::cout << "ScavTrap " << _name << " is created" << std::endl;
	_hit = 100;
	_energy = 50;
	 _damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor is called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default ScavTrap destructor is called\n";
}


ScavTrap &ScavTrap::operator=(ScavTrap & other)
{
	std::cout << "ScavTrap's assignment  is called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}
 

void ScavTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "ScavTrap " <<  _name << " is dead\n";
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " has no energy to attack\n";
	else
	{
		_energy--;
		std::cout << "ScavTrap " << _name
			<< " attacks " << target
			<< " causing " << _damage << " points of damage!\n";
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
