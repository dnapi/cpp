/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:09:17 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 16:09:18 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of argument." << std::endl;
		return (1);
	}
	Harl harl;
	int level = harl.levelToInt(argv[1]);
	switch(level)
	{
		case 0:
			harl.complainAll(0);
			break;
		case 1:
			harl.complainAll(1);
			break;
		case 2:
			harl.complainAll(2);
			break;
		case 3:
			harl.complainAll(3);
			break;
		default:
			harl.complainAll(-1);
	}
	return (0);
}
