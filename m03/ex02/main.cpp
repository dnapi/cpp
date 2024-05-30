/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:25 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:52:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap a("Gooddy");
	a = ClapTrap("Foo");
	a.attack("Baddy");
	a.takeDamage(3);
	a.beRepaired(4);
	a.beRepaired(4);

	ScavTrap st("Robot");
	st.attack("a door");
	st.takeDamage(42);
	st.beRepaired(10);
	st.guardGate();

	FragTrap ft("Chupacabra");
	ft.attack("Robot");
	ft.takeDamage(42);
	ft.beRepaired(10);
	ft.highFivesGuys();
	
	return (0);
}	
