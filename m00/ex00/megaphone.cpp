/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:34:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 12:29:23 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string toUpperCase(const std::string &str)
{
    std::string result = str;
    //for (char &c : result) {
	for (size_t i = 0; i < str.size(); i++)
	{
		result[i] = std::toupper(result[i]);
    }
    return (result);
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
	while (++i <= argc)
		std::cout << toUpperCase(argv[i - 1]);
    std::cout << std::endl;
    return (0);
}
