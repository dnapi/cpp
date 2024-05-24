/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:42:09 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:10 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
