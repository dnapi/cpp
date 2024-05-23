/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:34:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/23 09:48:44 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// Function to convert a string to uppercase
std::string toUpperCase(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

int main(int argc, char **argv) {
	int	i;
	std::string uppercased;


	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}
	i = 1;
//	shift = 0;
	while (++i <= argc)
		std::cout << toUpperCase(argv[i - 1]);
    std::cout << std::endl;
    return (0);
}
