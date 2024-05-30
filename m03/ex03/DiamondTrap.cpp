/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:58:44 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:59:11 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << "Default constructor DiamondTrap is called\n";
}

DiamondTrap::DiamondTrap(const std::string name) :
	ClapTrap(name + "_clap_name"),
	_name(name)
{
	_energy = 50;
	std::cout << "DiamondTrap " << _name << " is constructed\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &other) :
	ClapTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap " << _name << " is contructed by copy\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor DiamondTrap is called\n";
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	this->_name = other._name;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Hei! My name is " << _name 
		<< ", my ClapTrap name is" << ClapTrap::_name << std::endl;
	std::cout << "my hit points = " << this->_hit
		<< "\n   energy points = " << this->_energy
		<< "\n   attack damage = " << this->_damage
		<< std::endl;
}
