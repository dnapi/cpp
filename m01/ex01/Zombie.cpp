#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	std::cout << "a zombie is born" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is deleted" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
