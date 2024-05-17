/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:34:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/17 12:19:18 by apimikov         ###   ########.fr       */
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
	int	shift;
	std::string uppercased;


	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}
	i = 1;
	shift = 0;
	while (++i <= argc)
	{
		shift = argv[i - 1][0] == ' ';
		uppercased = toUpperCase(argv[i - 1] + shift);
    	std::cout << uppercased;
		if (uppercased.back() != ' ')
			std::cout << " ";
	}
    std::cout << std::endl;
    return (0);
}
