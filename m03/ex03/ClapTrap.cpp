/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:57:55 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:58:22 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("defaultname"), _hit(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor is called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor is called\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << _name << " is created by constructor\n";
}

ClapTrap::ClapTrap(ClapTrap &other)
{	
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	std::cout << "ClapTrap copy constructor is called.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << " operator= is called\n";
	if (this == &other)
		return (*this);
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << _name << " is dead\n";
	else if (_energy == 0)
		std::cout << _name << " has no energy to attack\n";
	else
	{
		_energy--;
		std::cout << "ClapTrap " << _name
			<< " attacks " << target
			<< " causing " << _damage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << _name << " is already dead\n";
		return ;
	}
	unsigned int damage;
	if (_hit >= amount)
		damage = amount;
	else
		damage = _hit;
	_hit -= damage;
	std::cout << _name << " took " << damage << " points of damage!\n";
	if (_hit == 0)
		std::cout << _name << " is kille\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0)
		std::cout << _name << " has no energy to be repared.\n";
	else if (_hit == 0)
		std::cout << _name << " is already dead.\n";
	else
	{
		_energy--;
		_hit += amount;
		std::cout << _name << " is repared\n";
	}
}


