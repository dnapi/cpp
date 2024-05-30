/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:19 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:52:20 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " is created" << std::endl;
	_hit = 100;
	_energy = 100;
	 _damage = 30;
}

FragTrap::FragTrap() : ClapTrap("unknown-scav") 
{
	std::cout << "FragTrap " << _name << " is created" << std::endl;
	_hit = 100;
	_energy = 100;
	 _damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Default FragTrap destructor is called\n";
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor is called\n";
}

FragTrap &FragTrap::operator=(FragTrap & other)
{
	std::cout << "FragTrap's assignment  is called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}
 

void FragTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "FragTrap " <<  _name << " is dead\n";
	else if (_energy == 0)
		std::cout << "FragTrap " << _name << " has no energy to attack\n";
	else
	{
		_energy--;
		std::cout << "FragTrap " << _name
			<< " attacks " << target
			<< " causing " << _damage << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ": give me a high five, anyone?!\n";
}
