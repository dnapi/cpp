#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter{
	public:
		static void convert(std::string);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		static void print(char, int, float, double);
		static bool isChar(const std::string&);
		static void toChar(const std::string&);
};

#endif
