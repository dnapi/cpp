/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:02:17 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/30 14:02:20 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Gooddy");
	a.attack("Baddy");
	a.takeDamage(3);
	a.beRepaired(4);
	a.beRepaired(4);
	return (0);
}	
