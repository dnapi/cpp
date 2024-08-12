/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:43:44 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:43:46 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

enum Type {emptyType, charType, intType,  floatType,  doubleType, unknownType}; 

class ScalarConverter{
	public:
		static void convert(std::string);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);

		static Type getType(std::string);
		static void castFrom(Type, std::string&, char&, int&, float&, double&);
		static void setPseudoValues(std::string&, char&, int&, float&, double&);
		static bool isPseudo(std::string&);
		static void print(std::string&, char, int, float, double);
};

#endif
