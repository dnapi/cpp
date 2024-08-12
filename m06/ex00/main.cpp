/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:43:34 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:43:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv){
	if (argc == 1 || argc > 2)
	{
		std::cout << "[ERROR] Please, provide one argument, and no more\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
