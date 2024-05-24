/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:42:04 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:05 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon	&weapon);
		void attack(void) const;
	private:
		std::string	name;
		Weapon		&weapon;
};
