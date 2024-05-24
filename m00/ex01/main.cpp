/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:56:40 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 12:31:58 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook pb;
	std::string str;

	while (1)
	{
		if (std::cin.eof()){
			std::cout << std::endl << "You have entered EOF. Program is terminated." << std::endl;
			break ;
		}
	    std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
    	if (!std::getline(std::cin, str))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (str == "ADD")
			pb.addEntry();
		else if (str == "SEARCH")
			pb.searchEntry();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Command: " << str << " is not supported." << std::endl;
	}
	return (0);
}
