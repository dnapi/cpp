/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:27 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 15:05:15 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap a("Gooddy");
	a = ClapTrap("Foo");
	a.attack("Baddy");
	a.takeDamage(3);
	a.beRepaired(4);
	a.beRepaired(4);

	ClapTrap b(a);
	ClapTrap c;
	c = b;


	ScavTrap st("Robot");
	st.attack("a door");
	st.takeDamage(42);
	st.beRepaired(10);
	st.guardGate();

	FragTrap ft0("Chupacabra");
	FragTrap ft;
	ft = ft0;
	ft.attack("Robot");
	ft.takeDamage(42);
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n\n\n ----- Diamond era -----\n";
	DiamondTrap dt;
	std::cout << " ----- Diamond 1 -----\n";
	DiamondTrap dt1("Vinni");
	std::cout << " ----- Diamond 2 -----\n";
	DiamondTrap dt2(dt1);
	dt2.attack("somebody");
	std::cout << " ----- Diamond 3 -----\n";
	DiamondTrap dt3("Trap");
	dt3.whoAmI();
	std::cout << " ----- Diamond 4 -----\n";
	DiamondTrap dt4;
	dt4 = dt3;
	std::cout << " ----- end of Diamond era -----\n\n";
	
	return (0);
}	
