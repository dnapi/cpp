/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:59:26 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:59:46 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string);
		DiamondTrap(DiamondTrap&);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap&);
		
		using	ScavTrap::attack;
		void whoAmI(void);
	private:
		std::string _name;
};
