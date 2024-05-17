/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:34:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/17 10:57:22 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

// Function to convert a string to uppercase
std::string toUpperCase(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

int main(int arc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
	if (argc >= 2)
		std::string uppercased = toUpperCase(input);
	std::string input = "Hello, World!";
    std::cout << "Original: " << input << std::endl;
    std::cout << "Uppercased: " << uppercased << std::endl;
    return 0;
}
