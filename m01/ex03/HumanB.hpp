/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:42:31 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 15:43:02 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
